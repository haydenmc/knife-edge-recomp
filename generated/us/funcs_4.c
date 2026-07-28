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

RECOMP_FUNC void func_800CEAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAE0: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x800CEAE4: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800CEAE8: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x800CEAEC: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x800CEAF0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEAF4: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800CEAF8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800CEAFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800CEB00: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800CEB04: sw          $t1, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r9;
    // 0x800CEB08: sh          $a2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r6;
    // 0x800CEB0C: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x800CEB10: lbu         $t3, 0x5($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X5);
    // 0x800CEB14: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x800CEB18: lw          $t4, 0x80($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X80);
    // 0x800CEB1C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800CEB20: sll         $t2, $v0, 8
    ctx->r10 = S32(ctx->r2 << 8);
    // 0x800CEB24: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x800CEB28: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800CEB2C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800CEB30: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x800CEB34: sw          $t5, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r13;
    // 0x800CEB38: sh          $a2, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r6;
    // 0x800CEB3C: jr          $ra
    // 0x800CEB40: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    return;
    // 0x800CEB40: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
;}
RECOMP_FUNC void func_800CEB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB44: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEB48: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEB4C: jr          $ra
    // 0x800CEB50: sb          $t6, 0xC2($a0)
    MEM_B(0XC2, ctx->r4) = ctx->r14;
    return;
    // 0x800CEB50: sb          $t6, 0xC2($a0)
    MEM_B(0XC2, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CEB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEB5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CEB60: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEB64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CEB68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CEB6C: jal         0x800D0DFC
    // 0x800CEB70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D0DFC(rdram, ctx);
        goto after_0;
    // 0x800CEB70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CEB74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800CEB78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEB7C: sb          $v0, 0xB1($a2)
    MEM_B(0XB1, ctx->r6) = ctx->r2;
    // 0x800CEB80: lb          $t6, 0xB1($a2)
    ctx->r14 = MEM_B(ctx->r6, 0XB1);
    // 0x800CEB84: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEB88: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEB8C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800CEB90: sb          $t8, 0xB1($a2)
    MEM_B(0XB1, ctx->r6) = ctx->r24;
    // 0x800CEB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEB98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEB9C: jr          $ra
    // 0x800CEBA0: nop

    return;
    // 0x800CEBA0: nop

;}
RECOMP_FUNC void func_800CEBA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEBA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEBA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEBAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CEBB0: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEBB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CEBB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CEBBC: jal         0x800D0DFC
    // 0x800CEBC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D0DFC(rdram, ctx);
        goto after_0;
    // 0x800CEBC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CEBC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEBC8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800CEBCC: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800CEBD0: sb          $v0, 0xB4($a2)
    MEM_B(0XB4, ctx->r6) = ctx->r2;
    // 0x800CEBD4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEBD8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEBDC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800CEBE0: sb          $t8, 0xB4($a2)
    MEM_B(0XB4, ctx->r6) = ctx->r24;
    // 0x800CEBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEBEC: jr          $ra
    // 0x800CEBF0: nop

    return;
    // 0x800CEBF0: nop

;}
RECOMP_FUNC void func_800CEBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEBF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEBF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEBFC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CEC00: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEC04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CEC08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CEC0C: jal         0x800D0DFC
    // 0x800CEC10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D0DFC(rdram, ctx);
        goto after_0;
    // 0x800CEC10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CEC14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEC18: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800CEC1C: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800CEC20: sb          $v0, 0xB5($a2)
    MEM_B(0XB5, ctx->r6) = ctx->r2;
    // 0x800CEC24: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEC28: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEC2C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800CEC30: sb          $t8, 0xB5($a2)
    MEM_B(0XB5, ctx->r6) = ctx->r24;
    // 0x800CEC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEC38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEC3C: jr          $ra
    // 0x800CEC40: nop

    return;
    // 0x800CEC40: nop

;}
RECOMP_FUNC void func_800CEC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEC44: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEC48: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEC4C: jr          $ra
    // 0x800CEC50: sb          $t6, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r14;
    return;
    // 0x800CEC50: sb          $t6, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CEC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEC54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CEC58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CEC5C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CEC60: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CEC64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CEC68: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEC6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CEC70: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x800CEC74: bne         $at, $zero, L_800CEC90
    if (ctx->r1 != 0) {
        // 0x800CEC78: addiu       $s2, $a1, 0x1
        ctx->r18 = ADD32(ctx->r5, 0X1);
            goto L_800CEC90;
    }
    // 0x800CEC78: addiu       $s2, $a1, 0x1
    ctx->r18 = ADD32(ctx->r5, 0X1);
    // 0x800CEC7C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800CEC80: andi        $t7, $s1, 0x7F
    ctx->r15 = ctx->r17 & 0X7F;
    // 0x800CEC84: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800CEC88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800CEC8C: addu        $s1, $t6, $t8
    ctx->r17 = ADD32(ctx->r14, ctx->r24);
L_800CEC90:
    // 0x800CEC90: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800CEC94: lbu         $a1, 0xB4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XB4);
    // 0x800CEC98: lbu         $a2, 0xB5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XB5);
    // 0x800CEC9C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800CECA0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800CECA4: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    // 0x800CECA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CECAC: jal         0x800CF2B0
    // 0x800CECB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800CF2B0(rdram, ctx);
        goto after_0;
    // 0x800CECB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800CECB4: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x800CECB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CECBC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800CECC0: bne         $v0, $zero, L_800CECD0
    if (ctx->r2 != 0) {
        // 0x800CECC4: sw          $t1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r9;
            goto L_800CECD0;
    }
    // 0x800CECC4: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x800CECC8: b           L_800CED24
    // 0x800CECCC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800CED24;
    // 0x800CECCC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CECD0:
    // 0x800CECD0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CECD4: lw          $a1, -0x630C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X630C);
    // 0x800CECD8: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CECDC: blez        $a1, L_800CED20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800CECE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800CED20;
    }
    // 0x800CECE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CECE4:
    // 0x800CECE4: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x800CECE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CECEC: bne         $v0, $t2, L_800CED18
    if (ctx->r2 != ctx->r10) {
        // 0x800CECF0: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800CED18;
    }
    // 0x800CECF0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CECF4: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x800CECF8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CECFC: sw          $t3, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r11;
    // 0x800CED00: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x800CED04: nop

    // 0x800CED08: sw          $t4, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r12;
    // 0x800CED0C: lw          $a1, -0x630C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X630C);
    // 0x800CED10: nop

    // 0x800CED14: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800CED18:
    // 0x800CED18: bne         $at, $zero, L_800CECE4
    if (ctx->r1 != 0) {
        // 0x800CED1C: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CECE4;
    }
    // 0x800CED1C: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CED20:
    // 0x800CED20: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CED24:
    // 0x800CED24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CED28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CED2C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CED30: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CED34: jr          $ra
    // 0x800CED38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CED38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800CED3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CED3C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CED40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CED44: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CED48: bgez        $t6, L_800CED60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800CED4C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800CED60;
    }
    // 0x800CED4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CED50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CED54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CED58: nop

    // 0x800CED5C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800CED60:
    // 0x800CED60: lui         $at, 0x3F90
    ctx->r1 = S32(0X3F90 << 16);
    // 0x800CED64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CED68: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800CED6C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800CED70: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800CED74: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CED78: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CED7C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800CED80: swc1        $f4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f4.u32l;
    // 0x800CED84: jr          $ra
    // 0x800CED88: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800CED88: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800CED8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CED8C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CED90: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CED94: jr          $ra
    // 0x800CED98: sb          $t6, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r14;
    return;
    // 0x800CED98: sb          $t6, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CED9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CED9C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CEDA0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800CEDA4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800CEDA8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800CEDAC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800CEDB0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800CEDB4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CEDB8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CEDBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CEDC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CEDC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CEDC8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CEDCC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEDD0: sw          $t6, -0x62DC($at)
    MEM_W(-0X62DC, ctx->r1) = ctx->r14;
    // 0x800CEDD4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800CEDD8: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800CEDDC: addiu       $s6, $s6, -0x630C
    ctx->r22 = ADD32(ctx->r22, -0X630C);
    // 0x800CEDE0: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x800CEDE4: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x800CEDE8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEDEC: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800CEDF0: sw          $t8, -0x6300($at)
    MEM_W(-0X6300, ctx->r1) = ctx->r24;
    // 0x800CEDF4: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x800CEDF8: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x800CEDFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEE00: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800CEE04: bne         $t0, $zero, L_800CEE20
    if (ctx->r8 != 0) {
        // 0x800CEE08: sw          $t9, -0x62FC($at)
        MEM_W(-0X62FC, ctx->r1) = ctx->r25;
            goto L_800CEE20;
    }
    // 0x800CEE08: sw          $t9, -0x62FC($at)
    MEM_W(-0X62FC, ctx->r1) = ctx->r25;
    // 0x800CEE0C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CEE10: addiu       $v0, $v0, -0x62F8
    ctx->r2 = ADD32(ctx->r2, -0X62F8);
    // 0x800CEE14: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x800CEE18: b           L_800CEE30
    // 0x800CEE1C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800CEE30;
    // 0x800CEE1C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800CEE20:
    // 0x800CEE20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CEE24: addiu       $v0, $v0, -0x62F8
    ctx->r2 = ADD32(ctx->r2, -0X62F8);
    // 0x800CEE28: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800CEE2C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800CEE30:
    // 0x800CEE30: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800CEE34: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x800CEE38: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x800CEE3C: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x800CEE40: addiu       $s0, $zero, 0x1C
    ctx->r16 = ADD32(0, 0X1C);
    // 0x800CEE44: bne         $t3, $zero, L_800CEE50
    if (ctx->r11 != 0) {
        // 0x800CEE48: nop
    
            goto L_800CEE50;
    }
    // 0x800CEE48: nop

    // 0x800CEE4C: break       7
    do_break(2148331084);
L_800CEE50:
    // 0x800CEE50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CEE54: bne         $t3, $at, L_800CEE68
    if (ctx->r11 != ctx->r1) {
        // 0x800CEE58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CEE68;
    }
    // 0x800CEE58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CEE5C: bne         $t4, $at, L_800CEE68
    if (ctx->r12 != ctx->r1) {
        // 0x800CEE60: nop
    
            goto L_800CEE68;
    }
    // 0x800CEE60: nop

    // 0x800CEE64: break       6
    do_break(2148331108);
L_800CEE68:
    // 0x800CEE68: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEE6C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CEE70: addiu       $a2, $a2, -0x66E8
    ctx->r6 = ADD32(ctx->r6, -0X66E8);
    // 0x800CEE74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CEE78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEE7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800CEE80: mflo        $t5
    ctx->r13 = lo;
    // 0x800CEE84: sw          $t5, -0x62F4($at)
    MEM_W(-0X62F4, ctx->r1) = ctx->r13;
    // 0x800CEE88: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800CEE8C: nop

    // 0x800CEE90: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CEE94: mflo        $t7
    ctx->r15 = lo;
    // 0x800CEE98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CEE9C: jal         0x800D8AE0
    // 0x800CEEA0: nop

    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_0;
    // 0x800CEEA0: nop

    after_0:
    // 0x800CEEA4: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800CEEA8: addiu       $s1, $zero, 0x120
    ctx->r17 = ADD32(0, 0X120);
    // 0x800CEEAC: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CEEB0: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800CEEB4: addiu       $fp, $fp, -0x6308
    ctx->r30 = ADD32(ctx->r30, -0X6308);
    // 0x800CEEB8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CEEBC: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x800CEEC0: addiu       $a2, $a2, -0x66E8
    ctx->r6 = ADD32(ctx->r6, -0X66E8);
    // 0x800CEEC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CEEC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800CEED0: mflo        $t9
    ctx->r25 = lo;
    // 0x800CEED4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800CEED8: jal         0x800D8AE0
    // 0x800CEEDC: nop

    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800CEEDC: nop

    after_1:
    // 0x800CEEE0: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800CEEE4: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800CEEE8: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CEEEC: addiu       $s3, $s3, -0x6304
    ctx->r19 = ADD32(ctx->r19, -0X6304);
    // 0x800CEEF0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800CEEF4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800CEEF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEEFC: mflo        $a2
    ctx->r6 = lo;
    // 0x800CEF00: jal         0x800D120C
    // 0x800CEF04: nop

    func_800D120C(rdram, ctx);
        goto after_2;
    // 0x800CEF04: nop

    after_2:
    // 0x800CEF08: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800CEF0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800CEF10: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CEF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEF18: mflo        $a2
    ctx->r6 = lo;
    // 0x800CEF1C: jal         0x800D120C
    // 0x800CEF20: nop

    func_800D120C(rdram, ctx);
        goto after_3;
    // 0x800CEF20: nop

    after_3:
    // 0x800CEF24: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800CEF28: jal         0x800CF02C
    // 0x800CEF2C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800CF02C(rdram, ctx);
        goto after_4;
    // 0x800CEF2C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_4:
    // 0x800CEF30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CEF34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEF38: sw          $t2, -0x62EC($at)
    MEM_W(-0X62EC, ctx->r1) = ctx->r10;
    // 0x800CEF3C: lui         $t4, 0x1234
    ctx->r12 = S32(0X1234 << 16);
    // 0x800CEF40: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CEF44: ori         $t4, $t4, 0x5678
    ctx->r12 = ctx->r12 | 0X5678;
    // 0x800CEF48: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CEF4C: addiu       $a1, $a1, -0x6320
    ctx->r5 = ADD32(ctx->r5, -0X6320);
    // 0x800CEF50: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800CEF54: sw          $t4, -0x62E8($at)
    MEM_W(-0X62E8, ctx->r1) = ctx->r12;
    // 0x800CEF58: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800CEF5C: addiu       $s5, $s5, -0x66D8
    ctx->r21 = ADD32(ctx->r21, -0X66D8);
    // 0x800CEF60: addiu       $t3, $t3, -0x684
    ctx->r11 = ADD32(ctx->r11, -0X684);
    // 0x800CEF64: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800CEF68: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CEF6C: sw          $a1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r5;
    // 0x800CEF70: jal         0x800D97E0
    // 0x800CEF74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    alSynAddPlayer_recomp(rdram, ctx);
        goto after_5;
    // 0x800CEF74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x800CEF78: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x800CEF7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800CEF80: blez        $t5, L_800CEFE8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800CEF84: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800CEFE8;
    }
    // 0x800CEF84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CEF88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CEF8C: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_800CEF90:
    // 0x800CEF90: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800CEF94: nop

    // 0x800CEF98: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800CEF9C: sb          $zero, 0xC1($t7)
    MEM_B(0XC1, ctx->r15) = 0;
    // 0x800CEFA0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800CEFA4: jal         0x800D0F38
    // 0x800CEFA8: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    func_800D0F38(rdram, ctx);
        goto after_6;
    // 0x800CEFA8: addu        $a0, $s0, $t8
    ctx->r4 = ADD32(ctx->r16, ctx->r24);
    after_6:
    // 0x800CEFAC: sb          $zero, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = 0;
    // 0x800CEFB0: lw          $t9, 0xC($s7)
    ctx->r25 = MEM_W(ctx->r23, 0XC);
    // 0x800CEFB4: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x800CEFB8: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x800CEFBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800CEFC0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800CEFC4: sh          $t9, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r25;
    // 0x800CEFC8: jal         0x800D9918
    // 0x800CEFCC: addu        $a1, $s2, $t0
    ctx->r5 = ADD32(ctx->r18, ctx->r8);
    alSynAllocVoice_recomp(rdram, ctx);
        goto after_7;
    // 0x800CEFCC: addu        $a1, $s2, $t0
    ctx->r5 = ADD32(ctx->r18, ctx->r8);
    after_7:
    // 0x800CEFD0: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800CEFD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CEFD8: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CEFDC: addiu       $s0, $s0, 0x120
    ctx->r16 = ADD32(ctx->r16, 0X120);
    // 0x800CEFE0: bne         $at, $zero, L_800CEF90
    if (ctx->r1 != 0) {
        // 0x800CEFE4: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_800CEF90;
    }
    // 0x800CEFE4: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_800CEFE8:
    // 0x800CEFE8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CEFEC: addiu       $v1, $v1, -0x66E8
    ctx->r3 = ADD32(ctx->r3, -0X66E8);
    // 0x800CEFF0: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x800CEFF4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800CEFF8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800CEFFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CF000: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CF004: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CF008: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800CF00C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800CF010: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800CF014: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800CF018: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800CF01C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800CF020: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CF024: jr          $ra
    // 0x800CF028: subu        $v0, $t2, $t4
    ctx->r2 = SUB32(ctx->r10, ctx->r12);
    return;
    // 0x800CF028: subu        $v0, $t2, $t4
    ctx->r2 = SUB32(ctx->r10, ctx->r12);
;}
RECOMP_FUNC void func_800CF02C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF02C: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800CF030: beq         $t6, $zero, L_800CF040
    if (ctx->r14 == 0) {
        // 0x800CF034: andi        $t7, $a0, 0x2
        ctx->r15 = ctx->r4 & 0X2;
            goto L_800CF040;
    }
    // 0x800CF034: andi        $t7, $a0, 0x2
    ctx->r15 = ctx->r4 & 0X2;
    // 0x800CF038: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF03C: sh          $a1, -0x62F0($at)
    MEM_H(-0X62F0, ctx->r1) = ctx->r5;
L_800CF040:
    // 0x800CF040: beq         $t7, $zero, L_800CF04C
    if (ctx->r15 == 0) {
        // 0x800CF044: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_800CF04C;
    }
    // 0x800CF044: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF048: sh          $a1, -0x62EE($at)
    MEM_H(-0X62EE, ctx->r1) = ctx->r5;
L_800CF04C:
    // 0x800CF04C: jr          $ra
    // 0x800CF050: nop

    return;
    // 0x800CF050: nop

;}
RECOMP_FUNC void func_800CF054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF054: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CF058: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CF05C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800CF060: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800CF064: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CF068: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800CF06C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CF070: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CF074: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CF078: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CF07C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800CF080: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    // 0x800CF084: sltiu       $at, $t6, 0x400
    ctx->r1 = ctx->r14 < 0X400 ? 1 : 0;
    // 0x800CF088: beq         $at, $zero, L_800CF0D0
    if (ctx->r1 == 0) {
        // 0x800CF08C: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800CF0D0;
    }
    // 0x800CF08C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CF090: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CF094: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF098: jal         0x800D1244
    // 0x800CF09C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800D1244(rdram, ctx);
        goto after_0;
    // 0x800CF09C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x800CF0A0: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x800CF0A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF0A8: jal         0x800D1244
    // 0x800CF0AC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800D1244(rdram, ctx);
        goto after_1;
    // 0x800CF0AC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_1:
    // 0x800CF0B0: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x800CF0B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF0B8: jal         0x800D1244
    // 0x800CF0BC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800D1244(rdram, ctx);
        goto after_2;
    // 0x800CF0BC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800CF0C0: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800CF0C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF0C8: jal         0x800D1244
    // 0x800CF0CC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800D1244(rdram, ctx);
        goto after_3;
    // 0x800CF0CC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
L_800CF0D0:
    // 0x800CF0D0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF0D4: addiu       $v1, $v1, -0x62EC
    ctx->r3 = ADD32(ctx->r3, -0X62EC);
    // 0x800CF0D8: lw          $s7, 0x0($v1)
    ctx->r23 = MEM_W(ctx->r3, 0X0);
    // 0x800CF0DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CF0E0: addiu       $t7, $s7, 0x1
    ctx->r15 = ADD32(ctx->r23, 0X1);
    // 0x800CF0E4: blez        $s6, L_800CF19C
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800CF0E8: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800CF19C;
    }
    // 0x800CF0E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CF0EC: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800CF0F0: addiu       $s5, $s5, -0x6304
    ctx->r21 = ADD32(ctx->r21, -0X6304);
    // 0x800CF0F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800CF0F8: addiu       $s4, $zero, 0x120
    ctx->r20 = ADD32(0, 0X120);
L_800CF0FC:
    // 0x800CF0FC: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x800CF100: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF104: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800CF108: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800CF10C: nop

    // 0x800CF110: beq         $t0, $zero, L_800CF190
    if (ctx->r8 == 0) {
        // 0x800CF114: nop
    
            goto L_800CF190;
    }
    // 0x800CF114: nop

    // 0x800CF118: jal         0x800D1070
    // 0x800CF11C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800D1070(rdram, ctx);
        goto after_4;
    // 0x800CF11C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800CF120: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CF124: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x800CF128: mflo        $t1
    ctx->r9 = lo;
    // 0x800CF12C: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800CF130: jal         0x800D0F38
    // 0x800CF134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0F38(rdram, ctx);
        goto after_5;
    // 0x800CF134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800CF138: sw          $s2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r18;
    // 0x800CF13C: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x800CF140: nop

    // 0x800CF144: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800CF148: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800CF14C: nop

    // 0x800CF150: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    // 0x800CF154: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800CF158: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x800CF15C: nop

    // 0x800CF160: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800CF164: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800CF168: nop

    // 0x800CF16C: sw          $v0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r2;
    // 0x800CF170: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800CF174: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x800CF178: nop

    // 0x800CF17C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800CF180: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800CF184: sw          $s7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r23;
    // 0x800CF188: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x800CF18C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800CF190:
    // 0x800CF190: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800CF194: bne         $s3, $s6, L_800CF0FC
    if (ctx->r19 != ctx->r22) {
        // 0x800CF198: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800CF0FC;
    }
    // 0x800CF198: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800CF19C:
    // 0x800CF19C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CF1A0: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800CF1A4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800CF1A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CF1AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CF1B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF1B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CF1B8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800CF1BC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800CF1C0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800CF1C4: jr          $ra
    // 0x800CF1C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CF1C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800CF1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF1CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CF1D0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800CF1D4: lw          $t6, -0x62FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X62FC);
    // 0x800CF1D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CF1DC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800CF1E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CF1E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CF1E8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF1EC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800CF1F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800CF1F4: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF1F8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800CF1FC: lw          $s0, -0x6304($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X6304);
    // 0x800CF200: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CF204: blez        $a2, L_800CF274
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF208: addiu       $a1, $t0, 0x1
        ctx->r5 = ADD32(ctx->r8, 0X1);
            goto L_800CF274;
    }
    // 0x800CF208: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
L_800CF20C:
    // 0x800CF20C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800CF210: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CF214: bne         $t1, $zero, L_800CF23C
    if (ctx->r9 != 0) {
        // 0x800CF218: nop
    
            goto L_800CF23C;
    }
    // 0x800CF218: nop

    // 0x800CF21C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800CF220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CF224: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800CF228: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800CF22C: jal         0x800D12F4
    // 0x800CF230: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D12F4(rdram, ctx);
        goto after_0;
    // 0x800CF230: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x800CF234: b           L_800CF2A4
    // 0x800CF238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CF2A4;
    // 0x800CF238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF23C:
    // 0x800CF23C: lhu         $t2, 0x9E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X9E);
    // 0x800CF240: nop

    // 0x800CF244: beq         $t2, $zero, L_800CF26C
    if (ctx->r10 == 0) {
        // 0x800CF248: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF26C;
    }
    // 0x800CF248: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF24C: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800CF250: nop

    // 0x800CF254: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CF258: beq         $at, $zero, L_800CF26C
    if (ctx->r1 == 0) {
        // 0x800CF25C: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF26C;
    }
    // 0x800CF25C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF260: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CF264: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CF268: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF26C:
    // 0x800CF26C: bne         $at, $zero, L_800CF20C
    if (ctx->r1 != 0) {
        // 0x800CF270: addiu       $s0, $s0, 0x120
        ctx->r16 = ADD32(ctx->r16, 0X120);
            goto L_800CF20C;
    }
    // 0x800CF270: addiu       $s0, $s0, 0x120
    ctx->r16 = ADD32(ctx->r16, 0X120);
L_800CF274:
    // 0x800CF274: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CF278: beq         $at, $zero, L_800CF2A0
    if (ctx->r1 == 0) {
        // 0x800CF27C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF2A0;
    }
    // 0x800CF27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CF284: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800CF288: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800CF28C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800CF290: jal         0x800D12F4
    // 0x800CF294: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D12F4(rdram, ctx);
        goto after_1;
    // 0x800CF294: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x800CF298: b           L_800CF2A4
    // 0x800CF29C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CF2A4;
    // 0x800CF29C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF2A0:
    // 0x800CF2A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF2A4:
    // 0x800CF2A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CF2A8: jr          $ra
    // 0x800CF2AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CF2AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800CF2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF2B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CF2B4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800CF2B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CF2BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CF2C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CF2C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CF2C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CF2CC: bne         $t6, $at, L_800CF2F0
    if (ctx->r14 != ctx->r1) {
        // 0x800CF2D0: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_800CF2F0;
    }
    // 0x800CF2D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CF2D4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800CF2D8: lw          $t7, -0x62FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X62FC);
    // 0x800CF2DC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800CF2E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800CF2E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800CF2E8: nop

    // 0x800CF2EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800CF2F0:
    // 0x800CF2F0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800CF2F4: beq         $a3, $zero, L_800CF344
    if (ctx->r7 == 0) {
        // 0x800CF2F8: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800CF344;
    }
    // 0x800CF2F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CF2FC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF300: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF304: lw          $a0, -0x6304($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6304);
    // 0x800CF308: blez        $a2, L_800CF344
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF30C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF344;
    }
    // 0x800CF30C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF310:
    // 0x800CF310: lhu         $t1, 0x9E($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X9E);
    // 0x800CF314: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF318: bne         $s0, $t1, L_800CF33C
    if (ctx->r16 != ctx->r9) {
        // 0x800CF31C: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF33C;
    }
    // 0x800CF31C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF320: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800CF324: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CF328: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CF32C: jal         0x800D12F4
    // 0x800CF330: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D12F4(rdram, ctx);
        goto after_0;
    // 0x800CF330: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x800CF334: b           L_800CF3F4
    // 0x800CF338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CF3F4;
    // 0x800CF338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF33C:
    // 0x800CF33C: bne         $at, $zero, L_800CF310
    if (ctx->r1 != 0) {
        // 0x800CF340: addiu       $a0, $a0, 0x120
        ctx->r4 = ADD32(ctx->r4, 0X120);
            goto L_800CF310;
    }
    // 0x800CF340: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
L_800CF344:
    // 0x800CF344: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF348: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF34C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CF350: lw          $a0, -0x6304($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6304);
    // 0x800CF354: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    // 0x800CF358: blez        $a2, L_800CF3C4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF35C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF3C4;
    }
    // 0x800CF35C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF360:
    // 0x800CF360: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800CF364: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF368: bne         $t2, $zero, L_800CF38C
    if (ctx->r10 != 0) {
        // 0x800CF36C: nop
    
            goto L_800CF38C;
    }
    // 0x800CF36C: nop

    // 0x800CF370: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800CF374: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CF378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CF37C: jal         0x800D12F4
    // 0x800CF380: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D12F4(rdram, ctx);
        goto after_1;
    // 0x800CF380: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x800CF384: b           L_800CF3F4
    // 0x800CF388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CF3F4;
    // 0x800CF388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF38C:
    // 0x800CF38C: lhu         $t3, 0x9E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X9E);
    // 0x800CF390: nop

    // 0x800CF394: beq         $t3, $zero, L_800CF3BC
    if (ctx->r11 == 0) {
        // 0x800CF398: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF3BC;
    }
    // 0x800CF398: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF39C: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x800CF3A0: nop

    // 0x800CF3A4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CF3A8: beq         $at, $zero, L_800CF3BC
    if (ctx->r1 == 0) {
        // 0x800CF3AC: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF3BC;
    }
    // 0x800CF3AC: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF3B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800CF3B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CF3B8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF3BC:
    // 0x800CF3BC: bne         $at, $zero, L_800CF360
    if (ctx->r1 != 0) {
        // 0x800CF3C0: addiu       $a0, $a0, 0x120
        ctx->r4 = ADD32(ctx->r4, 0X120);
            goto L_800CF360;
    }
    // 0x800CF3C0: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
L_800CF3C4:
    // 0x800CF3C4: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CF3C8: beq         $at, $zero, L_800CF3F0
    if (ctx->r1 == 0) {
        // 0x800CF3CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF3F0;
    }
    // 0x800CF3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF3D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CF3D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800CF3D8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800CF3DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CF3E0: jal         0x800D12F4
    // 0x800CF3E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D12F4(rdram, ctx);
        goto after_2;
    // 0x800CF3E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x800CF3E8: b           L_800CF3F4
    // 0x800CF3EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CF3F4;
    // 0x800CF3EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF3F0:
    // 0x800CF3F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CF3F4:
    // 0x800CF3F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CF3F8: jr          $ra
    // 0x800CF3FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CF3FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800CF400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF400: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CF404: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800CF408: beq         $a1, $zero, L_800CF418
    if (ctx->r5 == 0) {
        // 0x800CF40C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_800CF418;
    }
    // 0x800CF40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CF410: b           L_800CF41C
    // 0x800CF414: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800CF41C;
    // 0x800CF414: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CF418:
    // 0x800CF418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CF41C:
    // 0x800CF41C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF420: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF424: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CF428: lw          $a0, -0x6304($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6304);
    // 0x800CF42C: blez        $a2, L_800CF47C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF430: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CF47C;
    }
    // 0x800CF430: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CF434:
    // 0x800CF434: lhu         $a3, 0x9E($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X9E);
    // 0x800CF438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CF43C: beq         $a3, $zero, L_800CF44C
    if (ctx->r7 == 0) {
        // 0x800CF440: andi        $t6, $s0, 0x1
        ctx->r14 = ctx->r16 & 0X1;
            goto L_800CF44C;
    }
    // 0x800CF440: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x800CF444: bne         $t6, $zero, L_800CF45C
    if (ctx->r14 != 0) {
        // 0x800CF448: nop
    
            goto L_800CF45C;
    }
    // 0x800CF448: nop

L_800CF44C:
    // 0x800CF44C: bne         $a3, $zero, L_800CF470
    if (ctx->r7 != 0) {
        // 0x800CF450: andi        $t7, $s0, 0x2
        ctx->r15 = ctx->r16 & 0X2;
            goto L_800CF470;
    }
    // 0x800CF450: andi        $t7, $s0, 0x2
    ctx->r15 = ctx->r16 & 0X2;
    // 0x800CF454: beq         $t7, $zero, L_800CF474
    if (ctx->r15 == 0) {
        // 0x800CF458: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF474;
    }
    // 0x800CF458: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF45C:
    // 0x800CF45C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x800CF460: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800CF464: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF468: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF46C: nop

L_800CF470:
    // 0x800CF470: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF474:
    // 0x800CF474: bne         $at, $zero, L_800CF434
    if (ctx->r1 != 0) {
        // 0x800CF478: addiu       $a0, $a0, 0x120
        ctx->r4 = ADD32(ctx->r4, 0X120);
            goto L_800CF434;
    }
    // 0x800CF478: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
L_800CF47C:
    // 0x800CF47C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800CF480: jr          $ra
    // 0x800CF484: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CF484: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CF488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF488: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF48C: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF490: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF494: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF498: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CF49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF4A0: blez        $a2, L_800CF4EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF4A4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CF4EC;
    }
    // 0x800CF4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800CF4A8:
    // 0x800CF4A8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800CF4AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF4B0: beq         $t6, $zero, L_800CF4E4
    if (ctx->r14 == 0) {
        // 0x800CF4B4: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF4E4;
    }
    // 0x800CF4B4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF4B8: lhu         $a0, 0x9E($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X9E);
    // 0x800CF4BC: andi        $t7, $a3, 0x1
    ctx->r15 = ctx->r7 & 0X1;
    // 0x800CF4C0: beq         $a0, $zero, L_800CF4D0
    if (ctx->r4 == 0) {
        // 0x800CF4C4: nop
    
            goto L_800CF4D0;
    }
    // 0x800CF4C4: nop

    // 0x800CF4C8: bne         $t7, $zero, L_800CF4E0
    if (ctx->r15 != 0) {
        // 0x800CF4CC: nop
    
            goto L_800CF4E0;
    }
    // 0x800CF4CC: nop

L_800CF4D0:
    // 0x800CF4D0: bne         $a0, $zero, L_800CF4E4
    if (ctx->r4 != 0) {
        // 0x800CF4D4: andi        $t8, $a3, 0x2
        ctx->r24 = ctx->r7 & 0X2;
            goto L_800CF4E4;
    }
    // 0x800CF4D4: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x800CF4D8: beq         $t8, $zero, L_800CF4E4
    if (ctx->r24 == 0) {
        // 0x800CF4DC: nop
    
            goto L_800CF4E4;
    }
    // 0x800CF4DC: nop

L_800CF4E0:
    // 0x800CF4E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800CF4E4:
    // 0x800CF4E4: bne         $at, $zero, L_800CF4A8
    if (ctx->r1 != 0) {
        // 0x800CF4E8: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF4A8;
    }
    // 0x800CF4E8: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF4EC:
    // 0x800CF4EC: jr          $ra
    // 0x800CF4F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CF4F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CF4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF4F4: bne         $a0, $zero, L_800CF504
    if (ctx->r4 != 0) {
        // 0x800CF4F8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CF504;
    }
    // 0x800CF4F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CF4FC: jr          $ra
    // 0x800CF500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF504:
    // 0x800CF504: beq         $a1, $zero, L_800CF514
    if (ctx->r5 == 0) {
        // 0x800CF508: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_800CF514;
    }
    // 0x800CF508: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF50C: b           L_800CF518
    // 0x800CF510: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800CF518;
    // 0x800CF510: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CF514:
    // 0x800CF514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CF518:
    // 0x800CF518: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800CF51C: lw          $t0, -0x630C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X630C);
    // 0x800CF520: lw          $a2, -0x6304($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6304);
    // 0x800CF524: blez        $t0, L_800CF55C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800CF528: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800CF55C;
    }
    // 0x800CF528: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800CF52C:
    // 0x800CF52C: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x800CF530: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CF534: bne         $a0, $t6, L_800CF554
    if (ctx->r4 != ctx->r14) {
        // 0x800CF538: slt         $at, $v1, $t0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800CF554;
    }
    // 0x800CF538: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CF53C: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x800CF540: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x800CF544: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800CF548: lw          $t0, -0x630C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X630C);
    // 0x800CF54C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800CF550: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
L_800CF554:
    // 0x800CF554: bne         $at, $zero, L_800CF52C
    if (ctx->r1 != 0) {
        // 0x800CF558: addiu       $a2, $a2, 0x120
        ctx->r6 = ADD32(ctx->r6, 0X120);
            goto L_800CF52C;
    }
    // 0x800CF558: addiu       $a2, $a2, 0x120
    ctx->r6 = ADD32(ctx->r6, 0X120);
L_800CF55C:
    // 0x800CF55C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800CF560: jr          $ra
    // 0x800CF564: nop

    return;
    // 0x800CF564: nop

;}
RECOMP_FUNC void func_800CF568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF568: bne         $a0, $zero, L_800CF578
    if (ctx->r4 != 0) {
        // 0x800CF56C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF578;
    }
    // 0x800CF56C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF570: jr          $ra
    // 0x800CF574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF578:
    // 0x800CF578: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF57C: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF580: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF584: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF588: blez        $a2, L_800CF5AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF58C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CF5AC;
    }
    // 0x800CF58C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800CF590:
    // 0x800CF590: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF594: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF598: bne         $a0, $t6, L_800CF5A4
    if (ctx->r4 != ctx->r14) {
        // 0x800CF59C: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF5A4;
    }
    // 0x800CF59C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF5A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800CF5A4:
    // 0x800CF5A4: bne         $at, $zero, L_800CF590
    if (ctx->r1 != 0) {
        // 0x800CF5A8: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF590;
    }
    // 0x800CF5A8: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF5AC:
    // 0x800CF5AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CF5B0: jr          $ra
    // 0x800CF5B4: nop

    return;
    // 0x800CF5B4: nop

;}
RECOMP_FUNC void func_800CF5B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF5B8: bne         $a0, $zero, L_800CF5C8
    if (ctx->r4 != 0) {
        // 0x800CF5BC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CF5C8;
    }
    // 0x800CF5BC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CF5C0: jr          $ra
    // 0x800CF5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF5C8:
    // 0x800CF5C8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF5CC: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF5D0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF5D4: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF5DC: blez        $a2, L_800CF610
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF5E0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CF610;
    }
    // 0x800CF5E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800CF5E4:
    // 0x800CF5E4: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF5E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF5EC: bne         $a0, $t6, L_800CF608
    if (ctx->r4 != ctx->r14) {
        // 0x800CF5F0: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF608;
    }
    // 0x800CF5F0: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF5F4: sh          $a3, 0x96($v1)
    MEM_H(0X96, ctx->r3) = ctx->r7;
    // 0x800CF5F8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF5FC: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF600: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CF604: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF608:
    // 0x800CF608: bne         $at, $zero, L_800CF5E4
    if (ctx->r1 != 0) {
        // 0x800CF60C: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF5E4;
    }
    // 0x800CF60C: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF610:
    // 0x800CF610: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CF614: jr          $ra
    // 0x800CF618: nop

    return;
    // 0x800CF618: nop

;}
RECOMP_FUNC void func_800CF61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF61C: bne         $a0, $zero, L_800CF62C
    if (ctx->r4 != 0) {
        // 0x800CF620: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CF62C;
    }
    // 0x800CF620: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CF624: jr          $ra
    // 0x800CF628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF62C:
    // 0x800CF62C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF630: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF634: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF638: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF63C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF640: blez        $a2, L_800CF67C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF644: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CF67C;
    }
    // 0x800CF644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CF648: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800CF64C:
    // 0x800CF64C: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF650: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF654: bne         $a0, $t6, L_800CF674
    if (ctx->r4 != ctx->r14) {
        // 0x800CF658: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF674;
    }
    // 0x800CF658: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF65C: sh          $a3, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r7;
    // 0x800CF660: sb          $t0, 0xB6($v1)
    MEM_B(0XB6, ctx->r3) = ctx->r8;
    // 0x800CF664: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF668: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF66C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CF670: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF674:
    // 0x800CF674: bne         $at, $zero, L_800CF64C
    if (ctx->r1 != 0) {
        // 0x800CF678: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF64C;
    }
    // 0x800CF678: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF67C:
    // 0x800CF67C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CF680: jr          $ra
    // 0x800CF684: nop

    return;
    // 0x800CF684: nop

;}
RECOMP_FUNC void func_800CF688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF688: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CF68C: bne         $a0, $zero, L_800CF69C
    if (ctx->r4 != 0) {
        // 0x800CF690: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF69C;
    }
    // 0x800CF690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF694: jr          $ra
    // 0x800CF698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF69C:
    // 0x800CF69C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF6A0: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF6A4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF6A8: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF6AC: blez        $a2, L_800CF6EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CF6B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800CF6EC;
    }
    // 0x800CF6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800CF6B4:
    // 0x800CF6B4: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF6B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF6BC: bne         $a0, $t6, L_800CF6E4
    if (ctx->r4 != ctx->r14) {
        // 0x800CF6C0: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800CF6E4;
    }
    // 0x800CF6C0: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CF6C4: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x800CF6C8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CF6CC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800CF6D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CF6D4: swc1        $f6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f6.u32l;
    // 0x800CF6D8: lw          $a2, -0x630C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X630C);
    // 0x800CF6DC: nop

    // 0x800CF6E0: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_800CF6E4:
    // 0x800CF6E4: bne         $at, $zero, L_800CF6B4
    if (ctx->r1 != 0) {
        // 0x800CF6E8: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF6B4;
    }
    // 0x800CF6E8: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF6EC:
    // 0x800CF6EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CF6F0: jr          $ra
    // 0x800CF6F4: nop

    return;
    // 0x800CF6F4: nop

;}
RECOMP_FUNC void func_800CF6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF6F8: bne         $a0, $zero, L_800CF708
    if (ctx->r4 != 0) {
        // 0x800CF6FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF708;
    }
    // 0x800CF6FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF700: jr          $ra
    // 0x800CF704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF708:
    // 0x800CF708: bgtz        $a1, L_800CF718
    if (SIGNED(ctx->r5) > 0) {
        // 0x800CF70C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800CF718;
    }
    // 0x800CF70C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF710: b           L_800CF728
    // 0x800CF714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800CF728;
    // 0x800CF714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800CF718:
    // 0x800CF718: slti        $at, $a1, 0x101
    ctx->r1 = SIGNED(ctx->r5) < 0X101 ? 1 : 0;
    // 0x800CF71C: bne         $at, $zero, L_800CF728
    if (ctx->r1 != 0) {
        // 0x800CF720: nop
    
            goto L_800CF728;
    }
    // 0x800CF720: nop

    // 0x800CF724: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
L_800CF728:
    // 0x800CF728: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CF72C: lw          $a3, -0x630C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X630C);
    // 0x800CF730: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF734: blez        $a3, L_800CF780
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800CF738: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CF780;
    }
    // 0x800CF738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CF73C:
    // 0x800CF73C: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF740: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF744: bne         $a0, $t6, L_800CF778
    if (ctx->r4 != ctx->r14) {
        // 0x800CF748: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800CF778;
    }
    // 0x800CF748: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800CF74C: lhu         $t7, 0xA0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XA0);
    // 0x800CF750: sh          $a1, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r5;
    // 0x800CF754: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CF758: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CF75C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800CF760: mflo        $t8
    ctx->r24 = lo;
    // 0x800CF764: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x800CF768: sh          $t9, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r25;
    // 0x800CF76C: lw          $a3, -0x630C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X630C);
    // 0x800CF770: nop

    // 0x800CF774: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
L_800CF778:
    // 0x800CF778: bne         $at, $zero, L_800CF73C
    if (ctx->r1 != 0) {
        // 0x800CF77C: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF73C;
    }
    // 0x800CF77C: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF780:
    // 0x800CF780: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800CF784: jr          $ra
    // 0x800CF788: nop

    return;
    // 0x800CF788: nop

;}
RECOMP_FUNC void func_800CF78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF78C: bne         $a0, $zero, L_800CF79C
    if (ctx->r4 != 0) {
        // 0x800CF790: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF79C;
    }
    // 0x800CF790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF794: jr          $ra
    // 0x800CF798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF79C:
    // 0x800CF79C: bgez        $a1, L_800CF7AC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800CF7A0: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800CF7AC;
    }
    // 0x800CF7A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF7A4: b           L_800CF7BC
    // 0x800CF7A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800CF7BC;
    // 0x800CF7A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800CF7AC:
    // 0x800CF7AC: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800CF7B0: bne         $at, $zero, L_800CF7BC
    if (ctx->r1 != 0) {
        // 0x800CF7B4: nop
    
            goto L_800CF7BC;
    }
    // 0x800CF7B4: nop

    // 0x800CF7B8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_800CF7BC:
    // 0x800CF7BC: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CF7C0: lw          $a3, -0x630C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X630C);
    // 0x800CF7C4: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF7C8: blez        $a3, L_800CF804
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800CF7CC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CF804;
    }
    // 0x800CF7CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CF7D0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800CF7D4:
    // 0x800CF7D4: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF7D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF7DC: bne         $a0, $t6, L_800CF7FC
    if (ctx->r4 != ctx->r14) {
        // 0x800CF7E0: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800CF7FC;
    }
    // 0x800CF7E0: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800CF7E4: sb          $a1, 0xC3($v1)
    MEM_B(0XC3, ctx->r3) = ctx->r5;
    // 0x800CF7E8: sb          $t0, 0xC4($v1)
    MEM_B(0XC4, ctx->r3) = ctx->r8;
    // 0x800CF7EC: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CF7F0: lw          $a3, -0x630C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X630C);
    // 0x800CF7F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800CF7F8: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
L_800CF7FC:
    // 0x800CF7FC: bne         $at, $zero, L_800CF7D4
    if (ctx->r1 != 0) {
        // 0x800CF800: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF7D4;
    }
    // 0x800CF800: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF804:
    // 0x800CF804: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800CF808: jr          $ra
    // 0x800CF80C: nop

    return;
    // 0x800CF80C: nop

;}
RECOMP_FUNC void func_800CF810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF818: jal         0x800D0BE4
    // 0x800CF81C: nop

    func_800D0BE4(rdram, ctx);
        goto after_0;
    // 0x800CF81C: nop

    after_0:
    // 0x800CF820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF828: jr          $ra
    // 0x800CF82C: nop

    return;
    // 0x800CF82C: nop

;}
RECOMP_FUNC void func_800CF830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF834: beq         $a0, $zero, L_800CF854
    if (ctx->r4 == 0) {
        // 0x800CF838: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CF854;
    }
    // 0x800CF838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF83C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800CF840: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF844: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x800CF848: bgez        $t7, L_800CF854
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CF84C: nop
    
            goto L_800CF854;
    }
    // 0x800CF84C: nop

    // 0x800CF850: sw          $a0, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r4;
L_800CF854:
    // 0x800CF854: jal         0x800CF054
    // 0x800CF858: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CF054(rdram, ctx);
        goto after_0;
    // 0x800CF858: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800CF85C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800CF860: lw          $t8, -0x62E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X62E0);
    // 0x800CF864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF868: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF86C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF870: jr          $ra
    // 0x800CF874: sw          $t8, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r24;
    return;
    // 0x800CF874: sw          $t8, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_800CF878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF87C: beq         $a0, $zero, L_800CF89C
    if (ctx->r4 == 0) {
        // 0x800CF880: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CF89C;
    }
    // 0x800CF880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF884: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800CF888: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF88C: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x800CF890: bgez        $t7, L_800CF89C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CF894: nop
    
            goto L_800CF89C;
    }
    // 0x800CF894: nop

    // 0x800CF898: sw          $a0, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r4;
L_800CF89C:
    // 0x800CF89C: jal         0x800CF1CC
    // 0x800CF8A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CF1CC(rdram, ctx);
        goto after_0;
    // 0x800CF8A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800CF8A4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800CF8A8: lw          $t8, -0x62E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X62E0);
    // 0x800CF8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF8B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF8B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF8B8: jr          $ra
    // 0x800CF8BC: sw          $t8, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r24;
    return;
    // 0x800CF8BC: sw          $t8, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_800CF8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF8C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF8C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CF8C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CF8CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CF8D0: beq         $a0, $zero, L_800CF8F0
    if (ctx->r4 == 0) {
        // 0x800CF8D4: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800CF8F0;
    }
    // 0x800CF8D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CF8D8: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800CF8DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF8E0: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x800CF8E4: bgez        $t7, L_800CF8F4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CF8E8: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_800CF8F4;
    }
    // 0x800CF8E8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800CF8EC: sw          $a0, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r4;
L_800CF8F0:
    // 0x800CF8F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_800CF8F4:
    // 0x800CF8F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800CF8F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800CF8FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CF900: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800CF904: jal         0x800CF2B0
    // 0x800CF908: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800CF2B0(rdram, ctx);
        goto after_0;
    // 0x800CF908: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x800CF90C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800CF910: lw          $t9, -0x62E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X62E0);
    // 0x800CF914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF918: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CF91C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF920: jr          $ra
    // 0x800CF924: sw          $t9, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r25;
    return;
    // 0x800CF924: sw          $t9, -0x62E4($at)
    MEM_W(-0X62E4, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_800CF928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF928: bne         $a0, $zero, L_800CF938
    if (ctx->r4 != 0) {
        // 0x800CF92C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800CF938;
    }
    // 0x800CF92C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CF930: jr          $ra
    // 0x800CF934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CF934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF938:
    // 0x800CF938: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CF93C: lw          $a1, -0x630C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X630C);
    // 0x800CF940: lw          $v1, -0x6304($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6304);
    // 0x800CF944: blez        $a1, L_800CF970
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800CF948: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CF970;
    }
    // 0x800CF948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF94C:
    // 0x800CF94C: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x800CF950: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CF954: bne         $a0, $t6, L_800CF968
    if (ctx->r4 != ctx->r14) {
        // 0x800CF958: slt         $at, $v0, $a1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800CF968;
    }
    // 0x800CF958: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CF95C: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
    // 0x800CF960: jr          $ra
    // 0x800CF964: nop

    return;
    // 0x800CF964: nop

L_800CF968:
    // 0x800CF968: bne         $at, $zero, L_800CF94C
    if (ctx->r1 != 0) {
        // 0x800CF96C: addiu       $v1, $v1, 0x120
        ctx->r3 = ADD32(ctx->r3, 0X120);
            goto L_800CF94C;
    }
    // 0x800CF96C: addiu       $v1, $v1, 0x120
    ctx->r3 = ADD32(ctx->r3, 0X120);
L_800CF970:
    // 0x800CF970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF974: jr          $ra
    // 0x800CF978: nop

    return;
    // 0x800CF978: nop

;}
RECOMP_FUNC void func_800CF97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF97C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CF980: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CF984: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CF988: lw          $v0, -0x630C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X630C);
    // 0x800CF98C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800CF990: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CF994: lw          $s0, -0x6304($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X6304);
    // 0x800CF998: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CF99C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CF9A0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800CF9A4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800CF9A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CF9AC: blez        $v0, L_800CFC0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CF9B0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800CFC0C;
    }
    // 0x800CF9B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800CF9B4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800CF9B8:
    // 0x800CF9B8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800CF9BC: nop

    // 0x800CF9C0: beq         $t6, $zero, L_800CFBFC
    if (ctx->r14 == 0) {
        // 0x800CF9C4: nop
    
            goto L_800CFBFC;
    }
    // 0x800CF9C4: nop

    // 0x800CF9C8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800CF9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CF9D0: beq         $t7, $zero, L_800CF9E0
    if (ctx->r15 == 0) {
        // 0x800CF9D4: nop
    
            goto L_800CF9E0;
    }
    // 0x800CF9D4: nop

    // 0x800CF9D8: jal         0x800D0034
    // 0x800CF9DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0034(rdram, ctx);
        goto after_0;
    // 0x800CF9DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
L_800CF9E0:
    // 0x800CF9E0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800CF9E4: lhu         $t9, 0x94($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X94);
    // 0x800CF9E8: lhu         $t1, 0x92($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X92);
    // 0x800CF9EC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800CF9F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800CF9F4: beq         $t1, $at, L_800CFA6C
    if (ctx->r9 == ctx->r1) {
        // 0x800CF9F8: sw          $t0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r8;
            goto L_800CFA6C;
    }
    // 0x800CF9F8: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x800CF9FC: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x800CFA00: nop

    // 0x800CFA04: sltu        $at, $t2, $t0
    ctx->r1 = ctx->r10 < ctx->r8 ? 1 : 0;
    // 0x800CFA08: beq         $at, $zero, L_800CFA50
    if (ctx->r1 == 0) {
        // 0x800CFA0C: nop
    
            goto L_800CFA50;
    }
    // 0x800CFA0C: nop

    // 0x800CFA10: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800CFA14: nop

    // 0x800CFA18: beq         $t4, $zero, L_800CFA50
    if (ctx->r12 == 0) {
        // 0x800CFA1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CFA50;
    }
    // 0x800CFA1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800CFA20:
    // 0x800CFA20: jal         0x800CFC34
    // 0x800CFA24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CFC34(rdram, ctx);
        goto after_1;
    // 0x800CFA24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800CFA28: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x800CFA2C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800CFA30: nop

    // 0x800CFA34: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800CFA38: beq         $at, $zero, L_800CFA50
    if (ctx->r1 == 0) {
        // 0x800CFA3C: nop
    
            goto L_800CFA50;
    }
    // 0x800CFA3C: nop

    // 0x800CFA40: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800CFA44: nop

    // 0x800CFA48: bne         $t7, $zero, L_800CFA20
    if (ctx->r15 != 0) {
        // 0x800CFA4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CFA20;
    }
    // 0x800CFA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800CFA50:
    // 0x800CFA50: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800CFA54: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CFA58: bne         $t8, $zero, L_800CFA6C
    if (ctx->r24 != 0) {
        // 0x800CFA5C: nop
    
            goto L_800CFA6C;
    }
    // 0x800CFA5C: nop

    // 0x800CFA60: lw          $v0, -0x630C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X630C);
    // 0x800CFA64: b           L_800CFC00
    // 0x800CFA68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800CFC00;
    // 0x800CFA68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CFA6C:
    // 0x800CFA6C: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800CFA70: nop

    // 0x800CFA74: beq         $t9, $zero, L_800CFA9C
    if (ctx->r25 == 0) {
        // 0x800CFA78: nop
    
            goto L_800CFA9C;
    }
    // 0x800CFA78: nop

    // 0x800CFA7C: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x800CFA80: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800CFA84: nop

    // 0x800CFA88: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800CFA8C: beq         $at, $zero, L_800CFA9C
    if (ctx->r1 == 0) {
        // 0x800CFA90: nop
    
            goto L_800CFA9C;
    }
    // 0x800CFA90: nop

    // 0x800CFA94: jal         0x800D0854
    // 0x800CFA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0854(rdram, ctx);
        goto after_2;
    // 0x800CFA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_800CFA9C:
    // 0x800CFA9C: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x800CFAA0: nop

    // 0x800CFAA4: beq         $t2, $zero, L_800CFACC
    if (ctx->r10 == 0) {
        // 0x800CFAA8: nop
    
            goto L_800CFACC;
    }
    // 0x800CFAA8: nop

    // 0x800CFAAC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x800CFAB0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x800CFAB4: nop

    // 0x800CFAB8: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x800CFABC: beq         $at, $zero, L_800CFACC
    if (ctx->r1 == 0) {
        // 0x800CFAC0: nop
    
            goto L_800CFACC;
    }
    // 0x800CFAC0: nop

    // 0x800CFAC4: jal         0x800D0914
    // 0x800CFAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0914(rdram, ctx);
        goto after_3;
    // 0x800CFAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800CFACC:
    // 0x800CFACC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800CFAD0: nop

    // 0x800CFAD4: beq         $s2, $v0, L_800CFB24
    if (ctx->r18 == ctx->r2) {
        // 0x800CFAD8: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800CFB24;
    }
    // 0x800CFAD8: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800CFADC: bne         $s2, $t5, L_800CFB24
    if (ctx->r18 != ctx->r13) {
        // 0x800CFAE0: sw          $t5, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r13;
            goto L_800CFB24;
    }
    // 0x800CFAE0: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
    // 0x800CFAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CFAE8: jal         0x800CE320
    // 0x800CFAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE320(rdram, ctx);
        goto after_4;
    // 0x800CFAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800CFAF0: lbu         $t7, 0xC1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC1);
    // 0x800CFAF4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800CFAF8: beq         $t7, $zero, L_800CFB24
    if (ctx->r15 == 0) {
        // 0x800CFAFC: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800CFB24;
    }
    // 0x800CFAFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CFB00: sb          $zero, 0xC1($s0)
    MEM_B(0XC1, ctx->r16) = 0;
    // 0x800CFB04: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x800CFB08: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800CFB0C: lw          $t9, -0x6308($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6308);
    // 0x800CFB10: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800CFB14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800CFB18: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800CFB1C: jal         0x800D9A60
    // 0x800CFB20: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    alSynStopVoice_recomp(rdram, ctx);
        goto after_5;
    // 0x800CFB20: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
L_800CFB24:
    // 0x800CFB24: lbu         $t0, 0xC1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XC1);
    // 0x800CFB28: nop

    // 0x800CFB2C: beq         $t0, $zero, L_800CFBDC
    if (ctx->r8 == 0) {
        // 0x800CFB30: nop
    
            goto L_800CFBDC;
    }
    // 0x800CFB30: nop

    // 0x800CFB34: lbu         $t1, 0xBB($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XBB);
    // 0x800CFB38: nop

    // 0x800CFB3C: beq         $t1, $zero, L_800CFB4C
    if (ctx->r9 == 0) {
        // 0x800CFB40: nop
    
            goto L_800CFB4C;
    }
    // 0x800CFB40: nop

    // 0x800CFB44: jal         0x800D0430
    // 0x800CFB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0430(rdram, ctx);
        goto after_6;
    // 0x800CFB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800CFB4C:
    // 0x800CFB4C: lbu         $t2, 0xCC($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XCC);
    // 0x800CFB50: nop

    // 0x800CFB54: beq         $t2, $zero, L_800CFB7C
    if (ctx->r10 == 0) {
        // 0x800CFB58: nop
    
            goto L_800CFB7C;
    }
    // 0x800CFB58: nop

    // 0x800CFB5C: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
    // 0x800CFB60: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x800CFB64: nop

    // 0x800CFB68: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x800CFB6C: beq         $at, $zero, L_800CFB7C
    if (ctx->r1 == 0) {
        // 0x800CFB70: nop
    
            goto L_800CFB7C;
    }
    // 0x800CFB70: nop

    // 0x800CFB74: jal         0x800D0698
    // 0x800CFB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0698(rdram, ctx);
        goto after_7;
    // 0x800CFB78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_800CFB7C:
    // 0x800CFB7C: lbu         $t5, 0xCD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XCD);
    // 0x800CFB80: lwc1        $f20, 0x2C($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800CFB84: beq         $t5, $zero, L_800CFB98
    if (ctx->r13 == 0) {
        // 0x800CFB88: nop
    
            goto L_800CFB98;
    }
    // 0x800CFB88: nop

    // 0x800CFB8C: jal         0x800D07B0
    // 0x800CFB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D07B0(rdram, ctx);
        goto after_8;
    // 0x800CFB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800CFB94: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800CFB98:
    // 0x800CFB98: lbu         $t6, 0xC6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC6);
    // 0x800CFB9C: nop

    // 0x800CFBA0: beq         $t6, $zero, L_800CFBB4
    if (ctx->r14 == 0) {
        // 0x800CFBA4: nop
    
            goto L_800CFBB4;
    }
    // 0x800CFBA4: nop

    // 0x800CFBA8: jal         0x800D0754
    // 0x800CFBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D0754(rdram, ctx);
        goto after_9;
    // 0x800CFBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800CFBB0: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800CFBB4:
    // 0x800CFBB4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800CFBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CFBBC: bne         $t7, $zero, L_800CFBDC
    if (ctx->r15 != 0) {
        // 0x800CFBC0: nop
    
            goto L_800CFBDC;
    }
    // 0x800CFBC0: nop

    // 0x800CFBC4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800CFBC8: jal         0x800D0268
    // 0x800CFBCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0268(rdram, ctx);
        goto after_10;
    // 0x800CFBCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x800CFBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CFBD4: jal         0x800D00D0
    // 0x800CFBD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D00D0(rdram, ctx);
        goto after_11;
    // 0x800CFBD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
L_800CFBDC:
    // 0x800CFBDC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800CFBE0: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x800CFBE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CFBE8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CFBEC: srl         $t1, $t0, 8
    ctx->r9 = S32(U32(ctx->r8) >> 8);
    // 0x800CFBF0: sh          $t1, 0xA2($s0)
    MEM_H(0XA2, ctx->r16) = ctx->r9;
    // 0x800CFBF4: lw          $v0, -0x630C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X630C);
    // 0x800CFBF8: nop

L_800CFBFC:
    // 0x800CFBFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CFC00:
    // 0x800CFC00: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CFC04: bne         $at, $zero, L_800CF9B8
    if (ctx->r1 != 0) {
        // 0x800CFC08: addiu       $s0, $s0, 0x120
        ctx->r16 = ADD32(ctx->r16, 0X120);
            goto L_800CF9B8;
    }
    // 0x800CFC08: addiu       $s0, $s0, 0x120
    ctx->r16 = ADD32(ctx->r16, 0X120);
L_800CFC0C:
    // 0x800CFC0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFC10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CFC14: lw          $v0, -0x62F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X62F4);
    // 0x800CFC18: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800CFC1C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CFC20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CFC24: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CFC28: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CFC2C: jr          $ra
    // 0x800CFC30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CFC30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800CFC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFC34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CFC38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CFC3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CFC40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CFC44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800CFC48: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800CFC4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CFC50: beq         $s0, $zero, L_800CFCA4
    if (ctx->r16 == 0) {
        // 0x800CFC54: nop
    
            goto L_800CFCA4;
    }
    // 0x800CFC54: nop

    // 0x800CFC58: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800CFC5C: nop

    // 0x800CFC60: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800CFC64: bne         $at, $zero, L_800CFCA4
    if (ctx->r1 != 0) {
        // 0x800CFC68: andi        $t6, $v1, 0x7F
        ctx->r14 = ctx->r3 & 0X7F;
            goto L_800CFCA4;
    }
    // 0x800CFC68: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
L_800CFC6C:
    // 0x800CFC6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CFC70: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CFC74: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800CFC78: lw          $t9, -0x4670($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4670);
    // 0x800CFC7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CFC80: jalr        $t9
    // 0x800CFC84: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CFC84: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x800CFC88: beq         $v0, $zero, L_800CFCA4
    if (ctx->r2 == 0) {
        // 0x800CFC8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CFCA4;
    }
    // 0x800CFC8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CFC90: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFC94: nop

    // 0x800CFC98: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800CFC9C: beq         $at, $zero, L_800CFC6C
    if (ctx->r1 == 0) {
        // 0x800CFCA0: andi        $t6, $v1, 0x7F
        ctx->r14 = ctx->r3 & 0X7F;
            goto L_800CFC6C;
    }
    // 0x800CFCA0: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
L_800CFCA4:
    // 0x800CFCA4: beq         $s0, $zero, L_800CFFC8
    if (ctx->r16 == 0) {
        // 0x800CFCA8: sw          $s0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r16;
            goto L_800CFFC8;
    }
    // 0x800CFCA8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800CFCAC: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x800CFCB0: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x800CFCB4: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
    // 0x800CFCB8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x800CFCBC: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x800CFCC0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800CFCC4: lbu         $t1, 0xCA($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XCA);
    // 0x800CFCC8: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800CFCCC: beq         $t1, $zero, L_800CFCE4
    if (ctx->r9 == 0) {
        // 0x800CFCD0: nop
    
            goto L_800CFCE4;
    }
    // 0x800CFCD0: nop

    // 0x800CFCD4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800CFCD8: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800CFCDC: b           L_800CFCF0
    // 0x800CFCE0: sb          $t2, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r10;
        goto L_800CFCF0;
    // 0x800CFCE0: sb          $t2, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r10;
L_800CFCE4:
    // 0x800CFCE4: lbu         $t4, 0xCB($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XCB);
    // 0x800CFCE8: nop

    // 0x800CFCEC: sb          $t4, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r12;
L_800CFCF0:
    // 0x800CFCF0: lhu         $v0, 0xA4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA4);
    // 0x800CFCF4: nop

    // 0x800CFCF8: beq         $v0, $zero, L_800CFD64
    if (ctx->r2 == 0) {
        // 0x800CFCFC: nop
    
            goto L_800CFD64;
    }
    // 0x800CFCFC: nop

    // 0x800CFD00: lbu         $t5, 0xAF($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XAF);
    // 0x800CFD04: nop

    // 0x800CFD08: bne         $t5, $zero, L_800CFD18
    if (ctx->r13 != 0) {
        // 0x800CFD0C: nop
    
            goto L_800CFD18;
    }
    // 0x800CFD0C: nop

    // 0x800CFD10: b           L_800CFDAC
    // 0x800CFD14: sh          $v0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r2;
        goto L_800CFDAC;
    // 0x800CFD14: sh          $v0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r2;
L_800CFD18:
    // 0x800CFD18: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800CFD1C: sb          $zero, 0xAF($s1)
    MEM_B(0XAF, ctx->r17) = 0;
    // 0x800CFD20: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFD24: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800CFD28: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800CFD2C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800CFD30: beq         $at, $zero, L_800CFD40
    if (ctx->r1 == 0) {
        // 0x800CFD34: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800CFD40;
    }
    // 0x800CFD34: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CFD38: b           L_800CFDAC
    // 0x800CFD3C: sh          $a0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r4;
        goto L_800CFDAC;
    // 0x800CFD3C: sh          $a0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r4;
L_800CFD40:
    // 0x800CFD40: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800CFD44: andi        $t9, $v1, 0x7F
    ctx->r25 = ctx->r3 & 0X7F;
    // 0x800CFD48: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFD4C: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800CFD50: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800CFD54: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800CFD58: sh          $t0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r8;
    // 0x800CFD5C: b           L_800CFDAC
    // 0x800CFD60: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_800CFDAC;
    // 0x800CFD60: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_800CFD64:
    // 0x800CFD64: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800CFD68: nop

    // 0x800CFD6C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFD70: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800CFD74: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800CFD78: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800CFD7C: beq         $at, $zero, L_800CFD8C
    if (ctx->r1 == 0) {
        // 0x800CFD80: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800CFD8C;
    }
    // 0x800CFD80: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CFD84: b           L_800CFDAC
    // 0x800CFD88: sh          $a0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r4;
        goto L_800CFDAC;
    // 0x800CFD88: sh          $a0, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r4;
L_800CFD8C:
    // 0x800CFD8C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800CFD90: andi        $t4, $v1, 0x7F
    ctx->r12 = ctx->r3 & 0X7F;
    // 0x800CFD94: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFD98: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800CFD9C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800CFDA0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800CFDA4: sh          $t6, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r14;
    // 0x800CFDA8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800CFDAC:
    // 0x800CFDAC: lhu         $t7, 0x92($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X92);
    // 0x800CFDB0: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x800CFDB4: lbu         $t1, 0xC7($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC7);
    // 0x800CFDB8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800CFDBC: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x800CFDC0: sw          $t0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r8;
    // 0x800CFDC4: sh          $zero, 0xA2($s1)
    MEM_H(0XA2, ctx->r17) = 0;
    // 0x800CFDC8: sb          $zero, 0xC9($s1)
    MEM_B(0XC9, ctx->r17) = 0;
    // 0x800CFDCC: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    // 0x800CFDD0: sb          $t1, 0xC8($s1)
    MEM_B(0XC8, ctx->r17) = ctx->r9;
    // 0x800CFDD4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFDD8: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x800CFDDC: beq         $t2, $at, L_800CFF98
    if (ctx->r10 == ctx->r1) {
        // 0x800CFDE0: nop
    
            goto L_800CFF98;
    }
    // 0x800CFDE0: nop

    // 0x800CFDE4: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x800CFDE8: sll         $s0, $t2, 2
    ctx->r16 = S32(ctx->r10 << 2);
    // 0x800CFDEC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800CFDF0: lw          $v1, 0x7C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X7C);
    // 0x800CFDF4: nop

    // 0x800CFDF8: beq         $v1, $zero, L_800CFE58
    if (ctx->r3 == 0) {
        // 0x800CFDFC: addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
            goto L_800CFE58;
    }
    // 0x800CFDFC: addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // 0x800CFE00: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFE04: lw          $t8, 0x70($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X70);
    // 0x800CFE08: sh          $t3, 0xA6($s1)
    MEM_H(0XA6, ctx->r17) = ctx->r11;
    // 0x800CFE0C: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x800CFE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CFE14: bgez        $t5, L_800CFE24
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800CFE18: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800CFE24;
    }
    // 0x800CFE18: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800CFE1C: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800CFE20: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800CFE24:
    // 0x800CFE24: sb          $t6, 0xB5($s1)
    MEM_B(0XB5, ctx->r17) = ctx->r14;
    // 0x800CFE28: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800CFE2C: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x800CFE30: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800CFE34: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800CFE38: jal         0x800CE3B0
    // 0x800CFE3C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    func_800CE3B0(rdram, ctx);
        goto after_1;
    // 0x800CFE3C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_1:
    // 0x800CFE40: lw          $t1, 0x7C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X7C);
    // 0x800CFE44: nop

    // 0x800CFE48: addu        $t4, $t1, $s0
    ctx->r12 = ADD32(ctx->r9, ctx->r16);
    // 0x800CFE4C: lbu         $t2, 0x3($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X3);
    // 0x800CFE50: nop

    // 0x800CFE54: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_800CFE58:
    // 0x800CFE58: lbu         $t3, 0xCE($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XCE);
    // 0x800CFE5C: nop

    // 0x800CFE60: bne         $t3, $zero, L_800CFE70
    if (ctx->r11 != 0) {
        // 0x800CFE64: nop
    
            goto L_800CFE70;
    }
    // 0x800CFE64: nop

    // 0x800CFE68: jal         0x800D03C0
    // 0x800CFE6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D03C0(rdram, ctx);
        goto after_2;
    // 0x800CFE6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800CFE70:
    // 0x800CFE70: lbu         $t5, 0xCC($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XCC);
    // 0x800CFE74: nop

    // 0x800CFE78: beq         $t5, $zero, L_800CFE88
    if (ctx->r13 == 0) {
        // 0x800CFE7C: nop
    
            goto L_800CFE88;
    }
    // 0x800CFE7C: nop

    // 0x800CFE80: jal         0x800D067C
    // 0x800CFE84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D067C(rdram, ctx);
        goto after_3;
    // 0x800CFE84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_800CFE88:
    // 0x800CFE88: lbu         $t6, 0xCF($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XCF);
    // 0x800CFE8C: lhu         $s0, 0xA6($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0XA6);
    // 0x800CFE90: bne         $t6, $zero, L_800CFF10
    if (ctx->r14 != 0) {
        // 0x800CFE94: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_800CFF10;
    }
    // 0x800CFE94: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800CFE98: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CFE9C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800CFEA0: lw          $t8, 0x2C($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X2C);
    // 0x800CFEA4: lbu         $t1, 0xC1($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC1);
    // 0x800CFEA8: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x800CFEAC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800CFEB0: beq         $t1, $zero, L_800CFF00
    if (ctx->r9 == 0) {
        // 0x800CFEB4: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_800CFF00;
    }
    // 0x800CFEB4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800CFEB8: lhu         $t4, 0x98($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X98);
    // 0x800CFEBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CFEC0: beq         $t4, $zero, L_800CFF00
    if (ctx->r12 == 0) {
        // 0x800CFEC4: addiu       $a0, $a0, -0x66D8
        ctx->r4 = ADD32(ctx->r4, -0X66D8);
            goto L_800CFF00;
    }
    // 0x800CFEC4: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800CFEC8: sh          $zero, 0x98($s1)
    MEM_H(0X98, ctx->r17) = 0;
    // 0x800CFECC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800CFED0: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x800CFED4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800CFED8: lw          $t5, -0x6308($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6308);
    // 0x800CFEDC: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CFEE0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800CFEE4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800CFEE8: lw          $a3, -0x62F4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X62F4);
    // 0x800CFEEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CFEF0: jal         0x800D9AE0
    // 0x800CFEF4: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    alSynSetVol_recomp(rdram, ctx);
        goto after_4;
    // 0x800CFEF4: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    after_4:
    // 0x800CFEF8: b           L_800CFF10
    // 0x800CFEFC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_800CFF10;
    // 0x800CFEFC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_800CFF00:
    // 0x800CFF00: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800CFF04: jal         0x800D0034
    // 0x800CFF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0034(rdram, ctx);
        goto after_5;
    // 0x800CFF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800CFF0C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_800CFF10:
    // 0x800CFF10: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CFF14: lw          $t9, 0x28($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X28);
    // 0x800CFF18: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800CFF1C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800CFF20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CFF24: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800CFF28: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800CFF2C: lbu         $v1, 0xC2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XC2);
    // 0x800CFF30: lbu         $t1, 0xC4($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC4);
    // 0x800CFF34: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CFF38: beq         $t1, $v1, L_800D0020
    if (ctx->r9 == ctx->r3) {
        // 0x800CFF3C: swc1        $f16, 0x28($s1)
        MEM_W(0X28, ctx->r17) = ctx->f16.u32l;
            goto L_800D0020;
    }
    // 0x800CFF3C: swc1        $f16, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f16.u32l;
    // 0x800CFF40: lbu         $a2, 0xC3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XC3);
    // 0x800CFF44: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x800CFF48: subu        $t2, $t4, $a2
    ctx->r10 = SUB32(ctx->r12, ctx->r6);
    // 0x800CFF4C: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CFF50: sb          $v1, 0xC4($s1)
    MEM_B(0XC4, ctx->r17) = ctx->r3;
    // 0x800CFF54: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800CFF58: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800CFF5C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x800CFF60: lw          $t7, -0x6308($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6308);
    // 0x800CFF64: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x800CFF68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800CFF6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CFF70: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800CFF74: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    // 0x800CFF78: mflo        $t3
    ctx->r11 = lo;
    // 0x800CFF7C: sra         $t5, $t3, 7
    ctx->r13 = S32(SIGNED(ctx->r11) >> 7);
    // 0x800CFF80: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x800CFF84: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800CFF88: jal         0x800D9B80
    // 0x800CFF8C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    alSynSetFXMix_recomp(rdram, ctx);
        goto after_6;
    // 0x800CFF8C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_6:
    // 0x800CFF90: b           L_800D0024
    // 0x800CFF94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0024;
    // 0x800CFF94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CFF98:
    // 0x800CFF98: lbu         $t0, 0xBB($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XBB);
    // 0x800CFF9C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800CFFA0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800CFFA4: beq         $at, $zero, L_800D0020
    if (ctx->r1 == 0) {
        // 0x800CFFA8: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800D0020;
    }
    // 0x800CFFA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CFFAC: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x800CFFB0: lbu         $t3, 0xBC($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XBC);
    // 0x800CFFB4: sb          $t1, 0xBB($s1)
    MEM_B(0XBB, ctx->r17) = ctx->r9;
    // 0x800CFFB8: sb          $t2, 0xBD($s1)
    MEM_B(0XBD, ctx->r17) = ctx->r10;
    // 0x800CFFBC: sw          $t4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r12;
    // 0x800CFFC0: b           L_800D0020
    // 0x800CFFC4: sb          $t3, 0xC5($s1)
    MEM_B(0XC5, ctx->r17) = ctx->r11;
        goto L_800D0020;
    // 0x800CFFC4: sb          $t3, 0xC5($s1)
    MEM_B(0XC5, ctx->r17) = ctx->r11;
L_800CFFC8:
    // 0x800CFFC8: lbu         $t5, 0xC1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0XC1);
    // 0x800CFFCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CFFD0: beq         $t5, $zero, L_800D0020
    if (ctx->r13 == 0) {
        // 0x800CFFD4: addiu       $a0, $a0, -0x66D8
        ctx->r4 = ADD32(ctx->r4, -0X66D8);
            goto L_800D0020;
    }
    // 0x800CFFD4: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800CFFD8: sb          $zero, 0xC1($s1)
    MEM_B(0XC1, ctx->r17) = 0;
    // 0x800CFFDC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800CFFE0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800CFFE4: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800CFFE8: lw          $t9, -0x6308($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6308);
    // 0x800CFFEC: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CFFF0: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x800CFFF4: sll         $s0, $t6, 2
    ctx->r16 = S32(ctx->r14 << 2);
    // 0x800CFFF8: lw          $a3, -0x62F4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X62F4);
    // 0x800CFFFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0000: jal         0x800D9AE0
    // 0x800D0004: addu        $a1, $s0, $t9
    ctx->r5 = ADD32(ctx->r16, ctx->r25);
    alSynSetVol_recomp(rdram, ctx);
        goto after_7;
    // 0x800D0004: addu        $a1, $s0, $t9
    ctx->r5 = ADD32(ctx->r16, ctx->r25);
    after_7:
    // 0x800D0008: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D000C: lw          $t8, -0x6308($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6308);
    // 0x800D0010: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D0014: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D0018: jal         0x800D9A60
    // 0x800D001C: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    alSynStopVoice_recomp(rdram, ctx);
        goto after_8;
    // 0x800D001C: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    after_8:
L_800D0020:
    // 0x800D0020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0024:
    // 0x800D0024: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0028: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D002C: jr          $ra
    // 0x800D0030: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D0030: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800D0034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D003C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D0040: lbu         $t6, 0xC1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC1);
    // 0x800D0044: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D0048: beq         $t6, $zero, L_800D007C
    if (ctx->r14 == 0) {
        // 0x800D004C: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800D007C;
    }
    // 0x800D004C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D0050: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x800D0054: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800D0058: lw          $t9, -0x6308($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6308);
    // 0x800D005C: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x800D0060: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800D0064: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D0068: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800D006C: jal         0x800D9A60
    // 0x800D0070: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    alSynStopVoice_recomp(rdram, ctx);
        goto after_0;
    // 0x800D0070: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x800D0074: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D0078: nop

L_800D007C:
    // 0x800D007C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D0080: sb          $t0, 0xC1($a3)
    MEM_B(0XC1, ctx->r7) = ctx->r8;
    // 0x800D0084: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0088: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800D008C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800D0090: lw          $t3, -0x6308($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6308);
    // 0x800D0094: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800D0098: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800D009C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D00A0: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x800D00A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800D00A8: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D00AC: jal         0x800D9C20
    // 0x800D00B0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    alSynStartVoice_recomp(rdram, ctx);
        goto after_1;
    // 0x800D00B0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800D00B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D00B8: nop

    // 0x800D00BC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800D00C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D00C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D00C8: jr          $ra
    // 0x800D00CC: nop

    return;
    // 0x800D00CC: nop

;}
RECOMP_FUNC void func_800D00D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D00D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D00D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D00D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D00DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D00E0: lbu         $t7, 0xBC($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XBC);
    // 0x800D00E4: lbu         $t6, 0xB4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XB4);
    // 0x800D00E8: lbu         $t9, 0xB3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB3);
    // 0x800D00EC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D00F0: lh          $t1, 0x96($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X96);
    // 0x800D00F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D00F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800D00FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D0100: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D0104: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800D0108: mflo        $t8
    ctx->r24 = lo;
    // 0x800D010C: nop

    // 0x800D0110: nop

    // 0x800D0114: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0118: mflo        $t0
    ctx->r8 = lo;
    // 0x800D011C: nop

    // 0x800D0120: nop

    // 0x800D0124: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0128: mflo        $v0
    ctx->r2 = lo;
    // 0x800D012C: srl         $t2, $v0, 13
    ctx->r10 = S32(U32(ctx->r2) >> 13);
    // 0x800D0130: sltu        $at, $t2, $at
    ctx->r1 = ctx->r10 < ctx->r1 ? 1 : 0;
    // 0x800D0134: bne         $at, $zero, L_800D0140
    if (ctx->r1 != 0) {
        // 0x800D0138: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800D0140;
    }
    // 0x800D0138: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D013C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800D0140:
    // 0x800D0140: lhu         $t3, 0x9E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X9E);
    // 0x800D0144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0148: bne         $t3, $zero, L_800D016C
    if (ctx->r11 != 0) {
        // 0x800D014C: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_800D016C;
    }
    // 0x800D014C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D0150: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x800D0154: lhu         $t4, -0x62EE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X62EE);
    // 0x800D0158: nop

    // 0x800D015C: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0160: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0164: b           L_800D018C
    // 0x800D0168: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
        goto L_800D018C;
    // 0x800D0168: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_800D016C:
    // 0x800D016C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x800D0170: lhu         $t5, -0x62F0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X62F0);
    // 0x800D0174: nop

    // 0x800D0178: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D017C: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0180: nop

    // 0x800D0184: nop

    // 0x800D0188: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_800D018C:
    // 0x800D018C: srl         $t6, $v0, 15
    ctx->r14 = S32(U32(ctx->r2) >> 15);
    // 0x800D0190: beq         $v1, $at, L_800D01C8
    if (ctx->r3 == ctx->r1) {
        // 0x800D0194: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800D01C8;
    }
    // 0x800D0194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D0198: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D019C: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x800D01A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D01A4: nop

    // 0x800D01A8: nop

    // 0x800D01AC: divu        $zero, $t7, $t8
    lo = S32(U32(ctx->r15) / U32(ctx->r24)); hi = S32(U32(ctx->r15) % U32(ctx->r24));
    // 0x800D01B0: bne         $t8, $zero, L_800D01BC
    if (ctx->r24 != 0) {
        // 0x800D01B4: nop
    
            goto L_800D01BC;
    }
    // 0x800D01B4: nop

    // 0x800D01B8: break       7
    do_break(2148336056);
L_800D01BC:
    // 0x800D01BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800D01C0: nop

    // 0x800D01C4: nop

L_800D01C8:
    // 0x800D01C8: lhu         $t9, 0x98($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X98);
    // 0x800D01CC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800D01D0: beq         $v0, $t9, L_800D0200
    if (ctx->r2 == ctx->r25) {
        // 0x800D01D4: sra         $t3, $a2, 16
        ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
            goto L_800D0200;
    }
    // 0x800D01D4: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800D01D8: sh          $v0, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r2;
    // 0x800D01DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800D01E0: lw          $t2, -0x6308($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6308);
    // 0x800D01E4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D01E8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800D01EC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D01F0: lw          $a3, -0x62F4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X62F4);
    // 0x800D01F4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800D01F8: jal         0x800D9AE0
    // 0x800D01FC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    alSynSetVol_recomp(rdram, ctx);
        goto after_0;
    // 0x800D01FC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_0:
L_800D0200:
    // 0x800D0200: lbu         $v1, 0xB5($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XB5);
    // 0x800D0204: lbu         $t4, 0xB6($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XB6);
    // 0x800D0208: nop

    // 0x800D020C: beq         $t4, $v1, L_800D025C
    if (ctx->r12 == ctx->r3) {
        // 0x800D0210: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D025C;
    }
    // 0x800D0210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0214: lh          $t5, 0xA8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA8);
    // 0x800D0218: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D021C: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0220: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D0224: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D0228: mflo        $v0
    ctx->r2 = lo;
    // 0x800D022C: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800D0230: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800D0234: sb          $t7, 0xB6($s0)
    MEM_B(0XB6, ctx->r16) = ctx->r15;
    // 0x800D0238: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800D023C: lw          $t0, -0x6308($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6308);
    // 0x800D0240: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800D0244: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800D0248: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D024C: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    // 0x800D0250: jal         0x800D9CB0
    // 0x800D0254: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    alSynSetPan_recomp(rdram, ctx);
        goto after_1;
    // 0x800D0254: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_1:
    // 0x800D0258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D025C:
    // 0x800D025C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0260: jr          $ra
    // 0x800D0264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D0264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D0268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D026C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D0274: lbu         $v0, 0xB0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB0);
    // 0x800D0278: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D027C: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800D0280: beq         $v0, $zero, L_800D02EC
    if (ctx->r2 == 0) {
        // 0x800D0284: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800D02EC;
    }
    // 0x800D0284: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D0288: lhu         $a1, 0xA2($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0XA2);
    // 0x800D028C: nop

    // 0x800D0290: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D0294: bne         $at, $zero, L_800D02E8
    if (ctx->r1 != 0) {
        // 0x800D0298: nop
    
            goto L_800D02E8;
    }
    // 0x800D0298: nop

    // 0x800D029C: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D02A0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D02A4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800D02A8: bgez        $v0, L_800D02C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D02AC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D02C0;
    }
    // 0x800D02AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D02B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D02B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D02B8: nop

    // 0x800D02BC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800D02C0:
    // 0x800D02C0: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x800D02C4: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D02C8: bgez        $a1, L_800D02E0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D02CC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800D02E0;
    }
    // 0x800D02CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D02D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D02D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D02D8: nop

    // 0x800D02DC: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_800D02E0:
    // 0x800D02E0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800D02E4: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
L_800D02E8:
    // 0x800D02E8: swc1        $f2, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f2.u32l;
L_800D02EC:
    // 0x800D02EC: lbu         $t7, 0xB2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XB2);
    // 0x800D02F0: lb          $t6, 0xB1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XB1);
    // 0x800D02F4: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800D02F8: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D02FC: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800D0300: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800D0304: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800D0308: sb          $zero, 0xB2($a0)
    MEM_B(0XB2, ctx->r4) = 0;
    // 0x800D030C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0310: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0314: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800D0318: nop

    // 0x800D031C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0320: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800D0324: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800D0328: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x800D032C: nop

    // 0x800D0330: bc1t        L_800D03B4
    if (c1cs) {
        // 0x800D0334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D03B4;
    }
    // 0x800D0334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0338: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x800D033C: lwc1        $f8, -0x20DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X20DC);
    // 0x800D0340: lwc1        $f9, -0x20E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X20E0);
    // 0x800D0344: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800D0348: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800D034C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D0350: jal         0x800D0A34
    // 0x800D0354: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    func_800D0A34(rdram, ctx);
        goto after_0;
    // 0x800D0354: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_0:
    // 0x800D0358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D035C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D0360: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D0364: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D0368: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x800D036C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D0370: bc1f        L_800D0384
    if (!c1cs) {
        // 0x800D0374: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D0384;
    }
    // 0x800D0374: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800D0378: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D037C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D0380: sb          $zero, 0xB3($a0)
    MEM_B(0XB3, ctx->r4) = 0;
L_800D0384:
    // 0x800D0384: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0388: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D038C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D0390: lw          $t2, -0x6308($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6308);
    // 0x800D0394: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800D0398: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D039C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D03A0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800D03A4: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800D03A8: jal         0x800D9D40
    // 0x800D03AC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    alSynSetPitch_recomp(rdram, ctx);
        goto after_1;
    // 0x800D03AC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D03B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D03B4:
    // 0x800D03B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D03B8: jr          $ra
    // 0x800D03BC: nop

    return;
    // 0x800D03BC: nop

;}
RECOMP_FUNC void func_800D03C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D03C0: lhu         $t6, 0x92($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X92);
    // 0x800D03C4: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800D03C8: beq         $t6, $at, L_800D040C
    if (ctx->r14 == ctx->r1) {
        // 0x800D03CC: lui         $t4, 0x7FFF
        ctx->r12 = S32(0X7FFF << 16);
            goto L_800D040C;
    }
    // 0x800D03CC: lui         $t4, 0x7FFF
    ctx->r12 = S32(0X7FFF << 16);
    // 0x800D03D0: lhu         $v0, 0xAA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XAA);
    // 0x800D03D4: nop

    // 0x800D03D8: beq         $v0, $zero, L_800D03F4
    if (ctx->r2 == 0) {
        // 0x800D03DC: nop
    
            goto L_800D03F4;
    }
    // 0x800D03DC: nop

    // 0x800D03E0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800D03E4: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x800D03E8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D03EC: b           L_800D0414
    // 0x800D03F0: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
        goto L_800D0414;
    // 0x800D03F0: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
L_800D03F4:
    // 0x800D03F4: lhu         $t1, 0xAC($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XAC);
    // 0x800D03F8: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x800D03FC: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800D0400: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x800D0404: b           L_800D0414
    // 0x800D0408: sw          $t3, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r11;
        goto L_800D0414;
    // 0x800D0408: sw          $t3, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r11;
L_800D040C:
    // 0x800D040C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800D0410: sw          $t4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r12;
L_800D0414:
    // 0x800D0414: lbu         $t5, 0xB8($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XB8);
    // 0x800D0418: lbu         $t6, 0xB7($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XB7);
    // 0x800D041C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D0420: sb          $t7, 0xBB($a0)
    MEM_B(0XBB, ctx->r4) = ctx->r15;
    // 0x800D0424: sb          $t5, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r13;
    // 0x800D0428: jr          $ra
    // 0x800D042C: sb          $t6, 0xBD($a0)
    MEM_B(0XBD, ctx->r4) = ctx->r14;
    return;
    // 0x800D042C: sb          $t6, 0xBD($a0)
    MEM_B(0XBD, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800D0430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0430: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800D0434: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x800D0438: nop

    // 0x800D043C: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x800D0440: bne         $at, $zero, L_800D046C
    if (ctx->r1 != 0) {
        // 0x800D0444: nop
    
            goto L_800D046C;
    }
    // 0x800D0444: nop

    // 0x800D0448: lbu         $t8, 0xBB($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XBB);
    // 0x800D044C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800D0450: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800D0454: beq         $at, $zero, L_800D046C
    if (ctx->r1 == 0) {
        // 0x800D0458: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800D046C;
    }
    // 0x800D0458: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D045C: lbu         $t1, 0xBC($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XBC);
    // 0x800D0460: sb          $t9, 0xBB($a0)
    MEM_B(0XBB, ctx->r4) = ctx->r25;
    // 0x800D0464: sb          $t0, 0xBD($a0)
    MEM_B(0XBD, ctx->r4) = ctx->r8;
    // 0x800D0468: sb          $t1, 0xC5($a0)
    MEM_B(0XC5, ctx->r4) = ctx->r9;
L_800D046C:
    // 0x800D046C: lbu         $t2, 0xBD($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XBD);
    // 0x800D0470: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0474: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800D0478: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800D047C: bne         $t4, $zero, L_800D0674
    if (ctx->r12 != 0) {
        // 0x800D0480: sb          $t3, 0xBD($a0)
        MEM_B(0XBD, ctx->r4) = ctx->r11;
            goto L_800D0674;
    }
    // 0x800D0480: sb          $t3, 0xBD($a0)
    MEM_B(0XBD, ctx->r4) = ctx->r11;
    // 0x800D0484: lbu         $t5, 0xB7($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XB7);
    // 0x800D0488: lbu         $v0, 0xBB($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XBB);
    // 0x800D048C: sb          $t5, 0xBD($a0)
    MEM_B(0XBD, ctx->r4) = ctx->r13;
    // 0x800D0490: beq         $v0, $at, L_800D04BC
    if (ctx->r2 == ctx->r1) {
        // 0x800D0494: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D04BC;
    }
    // 0x800D0494: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D0498: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D049C: beq         $v1, $at, L_800D0544
    if (ctx->r3 == ctx->r1) {
        // 0x800D04A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800D0544;
    }
    // 0x800D04A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D04A4: beq         $v1, $at, L_800D0674
    if (ctx->r3 == ctx->r1) {
        // 0x800D04A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D0674;
    }
    // 0x800D04A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D04AC: beq         $v1, $at, L_800D05D4
    if (ctx->r3 == ctx->r1) {
        // 0x800D04B0: nop
    
            goto L_800D05D4;
    }
    // 0x800D04B0: nop

    // 0x800D04B4: jr          $ra
    // 0x800D04B8: nop

    return;
    // 0x800D04B8: nop

L_800D04BC:
    // 0x800D04BC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800D04C0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800D04C4: lw          $t0, 0x60($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X60);
    // 0x800D04C8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800D04CC: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x800D04D0: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D04D4: lbu         $t2, 0xBE($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XBE);
    // 0x800D04D8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800D04DC: mflo        $v1
    ctx->r3 = lo;
    // 0x800D04E0: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x800D04E4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800D04E8: beq         $at, $zero, L_800D0534
    if (ctx->r1 == 0) {
        // 0x800D04EC: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_800D0534;
    }
    // 0x800D04EC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D04F0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800D04F4: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800D04F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D04FC: lbu         $t5, 0xB8($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XB8);
    // 0x800D0500: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D0504: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800D0508: nop

    // 0x800D050C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800D0510: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800D0514: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800D0518: nop

    // 0x800D051C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800D0520: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800D0524: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800D0528: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800D052C: jr          $ra
    // 0x800D0530: sb          $t6, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r14;
    return;
    // 0x800D0530: sb          $t6, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r14;
L_800D0534:
    // 0x800D0534: lbu         $t8, 0xB9($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XB9);
    // 0x800D0538: sb          $t7, 0xBB($a0)
    MEM_B(0XBB, ctx->r4) = ctx->r15;
    // 0x800D053C: jr          $ra
    // 0x800D0540: sb          $t8, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r24;
    return;
    // 0x800D0540: sb          $t8, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r24;
L_800D0544:
    // 0x800D0544: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D0548: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x800D054C: lbu         $t3, 0xBE($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XBE);
    // 0x800D0550: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800D0554: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x800D0558: srl         $t2, $t1, 8
    ctx->r10 = S32(U32(ctx->r9) >> 8);
    // 0x800D055C: subu        $t5, $t2, $t3
    ctx->r13 = SUB32(ctx->r10, ctx->r11);
    // 0x800D0560: multu       $t5, $t4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0564: lbu         $t7, 0xBF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XBF);
    // 0x800D0568: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800D056C: mflo        $v1
    ctx->r3 = lo;
    // 0x800D0570: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x800D0574: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D0578: beq         $at, $zero, L_800D05C4
    if (ctx->r1 == 0) {
        // 0x800D057C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D05C4;
    }
    // 0x800D057C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D0580: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800D0584: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800D0588: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D058C: lbu         $t0, 0xB9($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XB9);
    // 0x800D0590: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D0594: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800D0598: nop

    // 0x800D059C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800D05A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800D05A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800D05A8: nop

    // 0x800D05AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800D05B0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800D05B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800D05B8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800D05BC: jr          $ra
    // 0x800D05C0: sb          $t1, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r9;
    return;
    // 0x800D05C0: sb          $t1, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r9;
L_800D05C4:
    // 0x800D05C4: lbu         $t3, 0xBA($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XBA);
    // 0x800D05C8: sb          $t2, 0xBB($a0)
    MEM_B(0XBB, ctx->r4) = ctx->r10;
    // 0x800D05CC: jr          $ra
    // 0x800D05D0: sb          $t3, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r11;
    return;
    // 0x800D05D0: sb          $t3, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r11;
L_800D05D4:
    // 0x800D05D4: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x800D05D8: lw          $t4, 0x50($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X50);
    // 0x800D05DC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x800D05E0: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800D05E4: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x800D05E8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D05EC: lbu         $t9, 0xC0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XC0);
    // 0x800D05F0: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800D05F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800D05F8: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x800D05FC: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D0600: beq         $at, $zero, L_800D066C
    if (ctx->r1 == 0) {
        // 0x800D0604: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800D066C;
    }
    // 0x800D0604: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800D0608: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800D060C: lbu         $v0, 0xC5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XC5);
    // 0x800D0610: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D0614: lwc1        $f16, 0x5C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800D0618: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800D061C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D0620: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0624: bgez        $v0, L_800D0638
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D0628: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D0638;
    }
    // 0x800D0628: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D062C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D0630: nop

    // 0x800D0634: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800D0638:
    // 0x800D0638: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D063C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800D0640: nop

    // 0x800D0644: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800D0648: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800D064C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800D0650: nop

    // 0x800D0654: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800D0658: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800D065C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800D0660: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x800D0664: jr          $ra
    // 0x800D0668: sb          $t3, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r11;
    return;
    // 0x800D0668: sb          $t3, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = ctx->r11;
L_800D066C:
    // 0x800D066C: sb          $t5, 0xBB($a0)
    MEM_B(0XBB, ctx->r4) = ctx->r13;
    // 0x800D0670: sb          $zero, 0xBC($a0)
    MEM_B(0XBC, ctx->r4) = 0;
L_800D0674:
    // 0x800D0674: jr          $ra
    // 0x800D0678: nop

    return;
    // 0x800D0678: nop

;}
RECOMP_FUNC void func_800D067C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D067C: lbu         $t7, 0xB5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XB5);
    // 0x800D0680: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800D0684: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x800D0688: sb          $zero, 0xD1($a0)
    MEM_B(0XD1, ctx->r4) = 0;
    // 0x800D068C: sb          $t8, 0xD2($a0)
    MEM_B(0XD2, ctx->r4) = ctx->r24;
    // 0x800D0690: jr          $ra
    // 0x800D0694: sw          $t6, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r14;
    return;
    // 0x800D0694: sw          $t6, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800D0698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0698: lw          $v0, 0x8C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8C);
    // 0x800D069C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D06A0: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_800D06A4:
    // 0x800D06A4: lbu         $t7, 0xD1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD1);
    // 0x800D06A8: lbu         $t8, 0xCC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XCC);
    // 0x800D06AC: addiu       $t6, $v0, 0x100
    ctx->r14 = ADD32(ctx->r2, 0X100);
    // 0x800D06B0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800D06B4: sltiu       $at, $v1, 0x40
    ctx->r1 = ctx->r3 < 0X40 ? 1 : 0;
    // 0x800D06B8: beq         $at, $zero, L_800D06C8
    if (ctx->r1 == 0) {
        // 0x800D06BC: sw          $t6, 0x8C($a0)
        MEM_W(0X8C, ctx->r4) = ctx->r14;
            goto L_800D06C8;
    }
    // 0x800D06BC: sw          $t6, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r14;
    // 0x800D06C0: b           L_800D0734
    // 0x800D06C4: sb          $v1, 0xD1($a0)
    MEM_B(0XD1, ctx->r4) = ctx->r3;
        goto L_800D0734;
    // 0x800D06C4: sb          $v1, 0xD1($a0)
    MEM_B(0XD1, ctx->r4) = ctx->r3;
L_800D06C8:
    // 0x800D06C8: lbu         $t1, 0xD2($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XD2);
    // 0x800D06CC: andi        $t9, $v1, 0x3F
    ctx->r25 = ctx->r3 & 0X3F;
    // 0x800D06D0: srl         $t0, $v1, 6
    ctx->r8 = S32(U32(ctx->r3) >> 6);
    // 0x800D06D4: sb          $t9, 0xD1($a0)
    MEM_B(0XD1, ctx->r4) = ctx->r25;
    // 0x800D06D8: bne         $t1, $zero, L_800D0708
    if (ctx->r9 != 0) {
        // 0x800D06DC: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800D0708;
    }
    // 0x800D06DC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800D06E0: lbu         $t2, 0xB5($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XB5);
    // 0x800D06E4: nop

    // 0x800D06E8: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x800D06EC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800D06F0: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x800D06F4: bne         $at, $zero, L_800D0734
    if (ctx->r1 != 0) {
        // 0x800D06F8: sb          $t3, 0xB5($a0)
        MEM_B(0XB5, ctx->r4) = ctx->r11;
            goto L_800D0734;
    }
    // 0x800D06F8: sb          $t3, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r11;
    // 0x800D06FC: sb          $a1, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r5;
    // 0x800D0700: b           L_800D0734
    // 0x800D0704: sb          $a2, 0xD2($a0)
    MEM_B(0XD2, ctx->r4) = ctx->r6;
        goto L_800D0734;
    // 0x800D0704: sb          $a2, 0xD2($a0)
    MEM_B(0XD2, ctx->r4) = ctx->r6;
L_800D0708:
    // 0x800D0708: lbu         $t5, 0xB5($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XB5);
    // 0x800D070C: nop

    // 0x800D0710: subu        $t6, $t5, $v1
    ctx->r14 = SUB32(ctx->r13, ctx->r3);
    // 0x800D0714: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800D0718: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800D071C: beq         $at, $zero, L_800D072C
    if (ctx->r1 == 0) {
        // 0x800D0720: sb          $t6, 0xB5($a0)
        MEM_B(0XB5, ctx->r4) = ctx->r14;
            goto L_800D072C;
    }
    // 0x800D0720: sb          $t6, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r14;
    // 0x800D0724: bne         $v0, $zero, L_800D0734
    if (ctx->r2 != 0) {
        // 0x800D0728: nop
    
            goto L_800D0734;
    }
    // 0x800D0728: nop

L_800D072C:
    // 0x800D072C: sb          $zero, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = 0;
    // 0x800D0730: sb          $zero, 0xD2($a0)
    MEM_B(0XD2, ctx->r4) = 0;
L_800D0734:
    // 0x800D0734: lw          $v0, 0x8C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8C);
    // 0x800D0738: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800D073C: nop

    // 0x800D0740: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x800D0744: bne         $at, $zero, L_800D06A4
    if (ctx->r1 != 0) {
        // 0x800D0748: nop
    
            goto L_800D06A4;
    }
    // 0x800D0748: nop

    // 0x800D074C: jr          $ra
    // 0x800D0750: nop

    return;
    // 0x800D0750: nop

;}
RECOMP_FUNC void func_800D0754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0754: lbu         $t6, 0xC8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC8);
    // 0x800D0758: nop

    // 0x800D075C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800D0760: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800D0764: bne         $t8, $zero, L_800D079C
    if (ctx->r24 != 0) {
        // 0x800D0768: sb          $t7, 0xC8($a0)
        MEM_B(0XC8, ctx->r4) = ctx->r15;
            goto L_800D079C;
    }
    // 0x800D0768: sb          $t7, 0xC8($a0)
    MEM_B(0XC8, ctx->r4) = ctx->r15;
    // 0x800D076C: lb          $t9, 0xC9($a0)
    ctx->r25 = MEM_B(ctx->r4, 0XC9);
    // 0x800D0770: nop

    // 0x800D0774: bne         $t9, $zero, L_800D0790
    if (ctx->r25 != 0) {
        // 0x800D0778: nop
    
            goto L_800D0790;
    }
    // 0x800D0778: nop

    // 0x800D077C: lb          $t0, 0xD0($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XD0);
    // 0x800D0780: lbu         $t1, 0xC6($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XC6);
    // 0x800D0784: sb          $t0, 0xC9($a0)
    MEM_B(0XC9, ctx->r4) = ctx->r8;
    // 0x800D0788: b           L_800D079C
    // 0x800D078C: sb          $t1, 0xC8($a0)
    MEM_B(0XC8, ctx->r4) = ctx->r9;
        goto L_800D079C;
    // 0x800D078C: sb          $t1, 0xC8($a0)
    MEM_B(0XC8, ctx->r4) = ctx->r9;
L_800D0790:
    // 0x800D0790: lbu         $t2, 0xC7($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XC7);
    // 0x800D0794: sb          $zero, 0xC9($a0)
    MEM_B(0XC9, ctx->r4) = 0;
    // 0x800D0798: sb          $t2, 0xC8($a0)
    MEM_B(0XC8, ctx->r4) = ctx->r10;
L_800D079C:
    // 0x800D079C: lb          $t3, 0xC9($a0)
    ctx->r11 = MEM_B(ctx->r4, 0XC9);
    // 0x800D07A0: nop

    // 0x800D07A4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800D07A8: jr          $ra
    // 0x800D07AC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x800D07AC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_800D07B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D07B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D07B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D07B8: lbu         $t7, 0xAE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XAE);
    // 0x800D07BC: lhu         $t6, 0xA2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA2);
    // 0x800D07C0: nop

    // 0x800D07C4: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800D07C8: blez        $v0, L_800D0848
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D07CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0848;
    }
    // 0x800D07CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D07D0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800D07D4: lbu         $t8, 0xCD($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XCD);
    // 0x800D07D8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D07DC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800D07E0: bgez        $t8, L_800D07F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D07E4: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800D07F8;
    }
    // 0x800D07E4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D07E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D07EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D07F0: nop

    // 0x800D07F4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800D07F8:
    // 0x800D07F8: nop

    // 0x800D07FC: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D0800: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D0804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0808: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D080C: lwc1        $f7, -0x20D8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20D8);
    // 0x800D0810: lwc1        $f6, -0x20D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20D4);
    // 0x800D0814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D0818: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D081C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800D0820: mul.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800D0824: jal         0x800D68F0
    // 0x800D0828: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800D0828: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_0:
    // 0x800D082C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D0830: nop

    // 0x800D0834: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800D0838: nop

    // 0x800D083C: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800D0840: swc1        $f2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f2.u32l;
    // 0x800D0844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0848:
    // 0x800D0848: lwc1        $f0, 0x64($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X64);
    // 0x800D084C: jr          $ra
    // 0x800D0850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D0850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D0854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0854: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800D0858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D085C:
    // 0x800D085C: lhu         $t7, 0x9A($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X9A);
    // 0x800D0860: addiu       $t6, $v0, 0x100
    ctx->r14 = ADD32(ctx->r2, 0X100);
    // 0x800D0864: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D0868: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D086C: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x800D0870: bne         $t9, $zero, L_800D08F4
    if (ctx->r25 != 0) {
        // 0x800D0874: sh          $t8, 0x9A($a0)
        MEM_H(0X9A, ctx->r4) = ctx->r24;
            goto L_800D08F4;
    }
    // 0x800D0874: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
    // 0x800D0878: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x800D087C: nop

    // 0x800D0880: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0884: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x800D0888: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800D088C: sw          $t0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r8;
    // 0x800D0890: bne         $at, $zero, L_800D08EC
    if (ctx->r1 != 0) {
        // 0x800D0894: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D08EC;
    }
    // 0x800D0894: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D0898: andi        $t1, $a1, 0x7F
    ctx->r9 = ctx->r5 & 0X7F;
    // 0x800D089C: sb          $t1, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r9;
    // 0x800D08A0: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800D08A4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800D08A8: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800D08AC: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
    // 0x800D08B0: bne         $at, $zero, L_800D08E0
    if (ctx->r1 != 0) {
        // 0x800D08B4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D08E0;
    }
    // 0x800D08B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D08B8: andi        $t3, $v0, 0x7F
    ctx->r11 = ctx->r2 & 0X7F;
    // 0x800D08BC: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x800D08C0: sh          $t5, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r13;
    // 0x800D08C4: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x800D08C8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x800D08CC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800D08D0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800D08D4: sh          $t8, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r24;
    // 0x800D08D8: b           L_800D08F4
    // 0x800D08DC: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
        goto L_800D08F4;
    // 0x800D08DC: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
L_800D08E0:
    // 0x800D08E0: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x800D08E4: b           L_800D08F4
    // 0x800D08E8: sh          $t0, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r8;
        goto L_800D08F4;
    // 0x800D08E8: sh          $t0, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r8;
L_800D08EC:
    // 0x800D08EC: sb          $v0, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r2;
    // 0x800D08F0: sh          $a2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r6;
L_800D08F4:
    // 0x800D08F4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800D08F8: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800D08FC: nop

    // 0x800D0900: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x800D0904: bne         $at, $zero, L_800D085C
    if (ctx->r1 != 0) {
        // 0x800D0908: nop
    
            goto L_800D085C;
    }
    // 0x800D0908: nop

    // 0x800D090C: jr          $ra
    // 0x800D0910: nop

    return;
    // 0x800D0910: nop

;}
RECOMP_FUNC void func_800D0914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0914: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x800D0918: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800D091C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800D0920: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D0924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D0928:
    // 0x800D0928: lhu         $t7, 0x9C($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X9C);
    // 0x800D092C: addiu       $t6, $v0, 0x100
    ctx->r14 = ADD32(ctx->r2, 0X100);
    // 0x800D0930: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D0934: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D0938: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800D093C: bne         $t9, $zero, L_800D0A14
    if (ctx->r25 != 0) {
        // 0x800D0940: sh          $t8, 0x9C($a0)
        MEM_H(0X9C, ctx->r4) = ctx->r24;
            goto L_800D0A14;
    }
    // 0x800D0940: sh          $t8, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r24;
    // 0x800D0944: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x800D0948: nop

    // 0x800D094C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0950: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x800D0954: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800D0958: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
    // 0x800D095C: bne         $at, $zero, L_800D09D8
    if (ctx->r1 != 0) {
        // 0x800D0960: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D09D8;
    }
    // 0x800D0960: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D0964: andi        $t1, $a1, 0x7F
    ctx->r9 = ctx->r5 & 0X7F;
    // 0x800D0968: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800D096C: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800D0970: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0974: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800D0978: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x800D097C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800D0980: sub.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f8.d - ctx->f2.d;
    // 0x800D0984: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800D0988: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800D098C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x800D0990: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800D0994: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800D0998: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x800D099C: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800D09A0: bne         $at, $zero, L_800D09CC
    if (ctx->r1 != 0) {
        // 0x800D09A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D09CC;
    }
    // 0x800D09A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D09A8: andi        $t3, $v0, 0x7F
    ctx->r11 = ctx->r2 & 0X7F;
    // 0x800D09AC: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x800D09B0: sh          $t5, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r13;
    // 0x800D09B4: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x800D09B8: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x800D09BC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800D09C0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800D09C4: b           L_800D0A14
    // 0x800D09C8: sh          $t8, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r24;
        goto L_800D0A14;
    // 0x800D09C8: sh          $t8, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r24;
L_800D09CC:
    // 0x800D09CC: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x800D09D0: b           L_800D0A14
    // 0x800D09D4: sh          $t0, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r8;
        goto L_800D0A14;
    // 0x800D09D4: sh          $t0, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r8;
L_800D09D8:
    // 0x800D09D8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D09DC: bgez        $v0, L_800D09F4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D09E0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D09F4;
    }
    // 0x800D09E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D09E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D09E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D09EC: nop

    // 0x800D09F0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800D09F4:
    // 0x800D09F4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800D09F8: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x800D09FC: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800D0A00: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800D0A04: sh          $a2, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r6;
    // 0x800D0A08: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800D0A0C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x800D0A10: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
L_800D0A14:
    // 0x800D0A14: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800D0A18: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800D0A1C: nop

    // 0x800D0A20: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x800D0A24: bne         $at, $zero, L_800D0928
    if (ctx->r1 != 0) {
        // 0x800D0A28: nop
    
            goto L_800D0928;
    }
    // 0x800D0A28: nop

    // 0x800D0A2C: jr          $ra
    // 0x800D0A30: nop

    return;
    // 0x800D0A30: nop

;}
RECOMP_FUNC void func_800D0A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D0A38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D0A3C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800D0A40: nop

    // 0x800D0A44: bc1f        L_800D0A58
    if (!c1cs) {
        // 0x800D0A48: nop
    
            goto L_800D0A58;
    }
    // 0x800D0A48: nop

    // 0x800D0A4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D0A50: jr          $ra
    // 0x800D0A54: nop

    return;
    // 0x800D0A54: nop

L_800D0A58:
    // 0x800D0A58: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800D0A5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D0A60: bc1f        L_800D0B20
    if (!c1cs) {
        // 0x800D0A64: nop
    
            goto L_800D0B20;
    }
    // 0x800D0A64: nop

    // 0x800D0A68: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800D0A6C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D0A70: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D0A74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0A78: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D0A7C: lwc1        $f7, -0x20D0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20D0);
    // 0x800D0A80: lwc1        $f6, -0x20CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20CC);
    // 0x800D0A84: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0A88: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800D0A8C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800D0A90: lwc1        $f4, -0x20C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20C4);
    // 0x800D0A94: lwc1        $f5, -0x20C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X20C8);
    // 0x800D0A98: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x800D0A9C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D0AA0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800D0AA4: add.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d + ctx->f16.d;
    // 0x800D0AA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0AAC: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800D0AB0: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800D0AB4: lwc1        $f10, -0x20BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20BC);
    // 0x800D0AB8: lwc1        $f11, -0x20C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20C0);
    // 0x800D0ABC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800D0AC0: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800D0AC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0AC8: lwc1        $f11, -0x20B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X20B8);
    // 0x800D0ACC: lwc1        $f10, -0x20B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X20B4);
    // 0x800D0AD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0AD4: add.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d + ctx->f6.d;
    // 0x800D0AD8: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800D0ADC: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800D0AE0: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x800D0AE4: lwc1        $f18, -0x20AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X20AC);
    // 0x800D0AE8: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D0AEC: lwc1        $f19, -0x20B0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X20B0);
    // 0x800D0AF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0AF4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800D0AF8: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800D0AFC: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x800D0B00: lwc1        $f6, -0x20A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20A4);
    // 0x800D0B04: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D0B08: lwc1        $f7, -0x20A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20A8);
    // 0x800D0B0C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800D0B10: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800D0B14: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800D0B18: jr          $ra
    // 0x800D0B1C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D0B1C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D0B20:
    // 0x800D0B20: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800D0B24: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800D0B28: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D0B2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0B30: lwc1        $f7, -0x20A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X20A0);
    // 0x800D0B34: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D0B38: lwc1        $f6, -0x209C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X209C);
    // 0x800D0B3C: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x800D0B40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0B44: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800D0B48: lwc1        $f18, -0x2094($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2094);
    // 0x800D0B4C: lwc1        $f19, -0x2098($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2098);
    // 0x800D0B50: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800D0B54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D0B58: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800D0B5C: add.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f4.d + ctx->f16.d;
    // 0x800D0B60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0B64: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800D0B68: add.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f8.d + ctx->f6.d;
    // 0x800D0B6C: lwc1        $f8, -0x208C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X208C);
    // 0x800D0B70: lwc1        $f9, -0x2090($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2090);
    // 0x800D0B74: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800D0B78: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800D0B7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0B80: lwc1        $f9, -0x2088($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2088);
    // 0x800D0B84: lwc1        $f8, -0x2084($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2084);
    // 0x800D0B88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0B8C: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x800D0B90: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x800D0B94: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800D0B98: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800D0B9C: lwc1        $f10, -0x207C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X207C);
    // 0x800D0BA0: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D0BA4: lwc1        $f11, -0x2080($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2080);
    // 0x800D0BA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0BAC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800D0BB0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800D0BB4: add.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d + ctx->f4.d;
    // 0x800D0BB8: lwc1        $f6, -0x2074($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2074);
    // 0x800D0BBC: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D0BC0: lwc1        $f7, -0x2078($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2078);
    // 0x800D0BC4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800D0BC8: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800D0BCC: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x800D0BD0: nop

    // 0x800D0BD4: div.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f8.d);
    // 0x800D0BD8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800D0BDC: jr          $ra
    // 0x800D0BE0: nop

    return;
    // 0x800D0BE0: nop

;}
RECOMP_FUNC void func_800D0BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0BE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D0BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D0BF0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800D0BF4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D0BF8: sll         $t6, $v0, 0
    ctx->r14 = S32(ctx->r2 << 0);
    // 0x800D0BFC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D0C00: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800D0C04: bltz        $t6, L_800D0DEC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800D0C08: or          $t3, $a0, $zero
        ctx->r11 = ctx->r4 | 0;
            goto L_800D0DEC;
    }
    // 0x800D0C08: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x800D0C0C: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x800D0C10: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800D0C14: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800D0C18: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800D0C1C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x800D0C20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D0C24: jal         0x800D1244
    // 0x800D0C28: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D1244(rdram, ctx);
        goto after_0;
    // 0x800D0C28: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800D0C2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800D0C30: nop

    // 0x800D0C34: lw          $a0, 0x2C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X2C);
    // 0x800D0C38: lw          $a2, 0x20($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X20);
    // 0x800D0C3C: jal         0x800D1244
    // 0x800D0C40: nop

    func_800D1244(rdram, ctx);
        goto after_1;
    // 0x800D0C40: nop

    after_1:
    // 0x800D0C44: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800D0C48: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D0C4C: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800D0C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0C54: blez        $t8, L_800D0DE4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D0C58: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800D0DE4;
    }
    // 0x800D0C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D0C5C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800D0C60: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800D0C64: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D0C68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D0C6C: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x800D0C70: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
L_800D0C74:
    // 0x800D0C74: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x800D0C78: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800D0C7C: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x800D0C80: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800D0C84: nop

    // 0x800D0C88: andi        $t5, $v1, 0x80
    ctx->r13 = ctx->r3 & 0X80;
    // 0x800D0C8C: beq         $t5, $zero, L_800D0CA8
    if (ctx->r13 == 0) {
        // 0x800D0C90: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D0CA8;
    }
    // 0x800D0C90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D0C94: subu        $t6, $t0, $v1
    ctx->r14 = SUB32(ctx->r8, ctx->r3);
    // 0x800D0C98: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800D0C9C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D0CA0: b           L_800D0CB4
    // 0x800D0CA4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
        goto L_800D0CB4;
    // 0x800D0CA4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_800D0CA8:
    // 0x800D0CA8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D0CAC: nop

    // 0x800D0CB0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
L_800D0CB4:
    // 0x800D0CB4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800D0CB8: nop

    // 0x800D0CBC: div.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f2.d);
    // 0x800D0CC0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800D0CC4: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800D0CC8: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800D0CCC: nop

    // 0x800D0CD0: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800D0CD4: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800D0CD8: nop

    // 0x800D0CDC: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x800D0CE0: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x800D0CE4: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800D0CE8: beq         $t5, $zero, L_800D0D04
    if (ctx->r13 == 0) {
        // 0x800D0CEC: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_800D0D04;
    }
    // 0x800D0CEC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800D0CF0: subu        $t6, $t0, $t4
    ctx->r14 = SUB32(ctx->r8, ctx->r12);
    // 0x800D0CF4: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800D0CF8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800D0CFC: b           L_800D0D10
    // 0x800D0D00: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
        goto L_800D0D10;
    // 0x800D0D00: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
L_800D0D04:
    // 0x800D0D04: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D0D08: nop

    // 0x800D0D0C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_800D0D10:
    // 0x800D0D10: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D0D14: nop

    // 0x800D0D18: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800D0D1C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800D0D20: lw          $t8, 0x2C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X2C);
    // 0x800D0D24: nop

    // 0x800D0D28: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800D0D2C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800D0D30: nop

    // 0x800D0D34: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x800D0D38: nop

    // 0x800D0D3C: bne         $t4, $zero, L_800D0DD0
    if (ctx->r12 != 0) {
        // 0x800D0D40: nop
    
            goto L_800D0DD0;
    }
    // 0x800D0D40: nop

    // 0x800D0D44: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800D0D48: nop

    // 0x800D0D4C: and         $t5, $v1, $t1
    ctx->r13 = ctx->r3 & ctx->r9;
    // 0x800D0D50: beq         $t1, $t5, L_800D0D70
    if (ctx->r9 == ctx->r13) {
        // 0x800D0D54: addu        $v1, $v1, $s0
        ctx->r3 = ADD32(ctx->r3, ctx->r16);
            goto L_800D0D70;
    }
    // 0x800D0D54: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800D0D58: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800D0D5C: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
    // 0x800D0D60: nop

    // 0x800D0D64: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800D0D68: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800D0D6C: nop

L_800D0D70:
    // 0x800D0D70: sb          $t2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r10;
    // 0x800D0D74: lw          $t8, 0x2C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X2C);
    // 0x800D0D78: nop

    // 0x800D0D7C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800D0D80: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800D0D84: nop

    // 0x800D0D88: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800D0D8C: nop

    // 0x800D0D90: beq         $v1, $zero, L_800D0DB0
    if (ctx->r3 == 0) {
        // 0x800D0D94: addu        $t4, $v1, $a3
        ctx->r12 = ADD32(ctx->r3, ctx->r7);
            goto L_800D0DB0;
    }
    // 0x800D0D94: addu        $t4, $v1, $a3
    ctx->r12 = ADD32(ctx->r3, ctx->r7);
    // 0x800D0D98: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800D0D9C: lw          $t5, 0x2C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X2C);
    // 0x800D0DA0: nop

    // 0x800D0DA4: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800D0DA8: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800D0DAC: nop

L_800D0DB0:
    // 0x800D0DB0: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x800D0DB4: nop

    // 0x800D0DB8: bne         $t7, $zero, L_800D0DD0
    if (ctx->r15 != 0) {
        // 0x800D0DBC: nop
    
            goto L_800D0DD0;
    }
    // 0x800D0DBC: nop

    // 0x800D0DC0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800D0DC4: nop

    // 0x800D0DC8: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800D0DCC: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
L_800D0DD0:
    // 0x800D0DD0: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800D0DD4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D0DD8: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D0DDC: bne         $at, $zero, L_800D0C74
    if (ctx->r1 != 0) {
        // 0x800D0DE0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800D0C74;
    }
    // 0x800D0DE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800D0DE4:
    // 0x800D0DE4: jal         0x800D9DD0
    // 0x800D0DE8: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0DE8: nop

    after_2:
L_800D0DEC:
    // 0x800D0DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0DF4: jr          $ra
    // 0x800D0DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D0DF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D0DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0DFC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800D0E00: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D0E04: addiu       $a2, $a2, -0x62E8
    ctx->r6 = ADD32(ctx->r6, -0X62E8);
    // 0x800D0E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0E0C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800D0E10: lui         $t0, 0x800
    ctx->r8 = S32(0X800 << 16);
    // 0x800D0E14: lui         $a3, 0x4800
    ctx->r7 = S32(0X4800 << 16);
L_800D0E18:
    // 0x800D0E18: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D0E20: and         $v1, $a0, $a3
    ctx->r3 = ctx->r4 & ctx->r7;
    // 0x800D0E24: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800D0E28: beq         $v1, $a3, L_800D0E38
    if (ctx->r3 == ctx->r7) {
        // 0x800D0E2C: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_800D0E38;
    }
    // 0x800D0E2C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D0E30: bne         $v1, $t0, L_800D0E48
    if (ctx->r3 != ctx->r8) {
        // 0x800D0E34: nop
    
            goto L_800D0E48;
    }
    // 0x800D0E34: nop

L_800D0E38:
    // 0x800D0E38: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E3C: nop

    // 0x800D0E40: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800D0E44: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800D0E48:
    // 0x800D0E48: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E4C: nop

    // 0x800D0E50: and         $v1, $a0, $a3
    ctx->r3 = ctx->r4 & ctx->r7;
    // 0x800D0E54: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800D0E58: beq         $v1, $a3, L_800D0E68
    if (ctx->r3 == ctx->r7) {
        // 0x800D0E5C: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_800D0E68;
    }
    // 0x800D0E5C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D0E60: bne         $v1, $t0, L_800D0E78
    if (ctx->r3 != ctx->r8) {
        // 0x800D0E64: nop
    
            goto L_800D0E78;
    }
    // 0x800D0E64: nop

L_800D0E68:
    // 0x800D0E68: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E6C: nop

    // 0x800D0E70: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800D0E74: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_800D0E78:
    // 0x800D0E78: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E7C: nop

    // 0x800D0E80: and         $v1, $a0, $a3
    ctx->r3 = ctx->r4 & ctx->r7;
    // 0x800D0E84: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x800D0E88: beq         $v1, $a3, L_800D0E98
    if (ctx->r3 == ctx->r7) {
        // 0x800D0E8C: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_800D0E98;
    }
    // 0x800D0E8C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800D0E90: bne         $v1, $t0, L_800D0EA8
    if (ctx->r3 != ctx->r8) {
        // 0x800D0E94: nop
    
            goto L_800D0EA8;
    }
    // 0x800D0E94: nop

L_800D0E98:
    // 0x800D0E98: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800D0E9C: nop

    // 0x800D0EA0: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800D0EA4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_800D0EA8:
    // 0x800D0EA8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800D0EAC: nop

    // 0x800D0EB0: and         $v1, $a0, $a3
    ctx->r3 = ctx->r4 & ctx->r7;
    // 0x800D0EB4: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800D0EB8: beq         $v1, $a3, L_800D0EC8
    if (ctx->r3 == ctx->r7) {
        // 0x800D0EBC: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_800D0EC8;
    }
    // 0x800D0EBC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D0EC0: bne         $v1, $t0, L_800D0ED8
    if (ctx->r3 != ctx->r8) {
        // 0x800D0EC4: nop
    
            goto L_800D0ED8;
    }
    // 0x800D0EC4: nop

L_800D0EC8:
    // 0x800D0EC8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D0ECC: nop

    // 0x800D0ED0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800D0ED4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_800D0ED8:
    // 0x800D0ED8: bne         $v0, $t1, L_800D0E18
    if (ctx->r2 != ctx->r9) {
        // 0x800D0EDC: nop
    
            goto L_800D0E18;
    }
    // 0x800D0EDC: nop

    // 0x800D0EE0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x800D0EE4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D0EE8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800D0EEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D0EF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0EF4: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800D0EF8: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D0EFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0F00: nop

    // 0x800D0F04: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800D0F08: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D0F0C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800D0F10: nop

    // 0x800D0F14: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800D0F18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800D0F1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800D0F20: nop

    // 0x800D0F24: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800D0F28: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800D0F2C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800D0F30: jr          $ra
    // 0x800D0F34: nop

    return;
    // 0x800D0F34: nop

;}
RECOMP_FUNC void func_800D0F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0F38: lbu         $v0, 0xC1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XC1);
    // 0x800D0F3C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D0F40: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D0F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D0F48: addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
L_800D0F4C:
    // 0x800D0F4C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800D0F50: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x800D0F54: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x800D0F58: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800D0F5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D0F60: bne         $a1, $a2, L_800D0F4C
    if (ctx->r5 != ctx->r6) {
        // 0x800D0F64: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_800D0F4C;
    }
    // 0x800D0F64: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x800D0F68: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800D0F6C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800D0F70: sh          $t6, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r14;
    // 0x800D0F74: sb          $a1, 0xC4($a0)
    MEM_B(0XC4, ctx->r4) = ctx->r5;
    // 0x800D0F78: sb          $a1, 0xB6($a0)
    MEM_B(0XB6, ctx->r4) = ctx->r5;
    // 0x800D0F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D0F80: lwc1        $f4, -0x2070($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2070);
    // 0x800D0F84: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D0F88: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800D0F8C: lw          $t7, -0x62F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X62F8);
    // 0x800D0F90: addiu       $t8, $zero, 0x6000
    ctx->r24 = ADD32(0, 0X6000);
    // 0x800D0F94: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x800D0F98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D0F9C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x800D0FA0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800D0FA4: bne         $t7, $zero, L_800D0FB0
    if (ctx->r15 != 0) {
        // 0x800D0FA8: nop
    
            goto L_800D0FB0;
    }
    // 0x800D0FA8: nop

    // 0x800D0FAC: break       7
    do_break(2148339628);
L_800D0FB0:
    // 0x800D0FB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0FB4: bne         $t7, $at, L_800D0FC8
    if (ctx->r15 != ctx->r1) {
        // 0x800D0FB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D0FC8;
    }
    // 0x800D0FB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D0FBC: bne         $t8, $at, L_800D0FC8
    if (ctx->r24 != ctx->r1) {
        // 0x800D0FC0: nop
    
            goto L_800D0FC8;
    }
    // 0x800D0FC0: nop

    // 0x800D0FC4: break       6
    do_break(2148339652);
L_800D0FC8:
    // 0x800D0FC8: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x800D0FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D0FD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D0FD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D0FD8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x800D0FDC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800D0FE0: sh          $a2, 0x92($a0)
    MEM_H(0X92, ctx->r4) = ctx->r6;
    // 0x800D0FE4: sb          $zero, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = 0;
    // 0x800D0FE8: sb          $a3, 0xCB($a0)
    MEM_B(0XCB, ctx->r4) = ctx->r7;
    // 0x800D0FEC: sb          $a3, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r7;
    // 0x800D0FF0: sb          $t1, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r9;
    // 0x800D0FF4: sh          $a2, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r6;
    // 0x800D0FF8: sh          $a2, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r6;
    // 0x800D0FFC: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x800D1000: mflo        $v1
    ctx->r3 = lo;
    // 0x800D1004: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x800D1008: sh          $t9, 0xA0($a0)
    MEM_H(0XA0, ctx->r4) = ctx->r25;
    // 0x800D100C: sh          $t9, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r25;
    // 0x800D1010: sh          $t0, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r8;
    // 0x800D1014: sh          $t0, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r8;
    // 0x800D1018: sh          $t0, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r8;
    // 0x800D101C: sb          $a2, 0xB7($a0)
    MEM_B(0XB7, ctx->r4) = ctx->r6;
    // 0x800D1020: sb          $a2, 0xBE($a0)
    MEM_B(0XBE, ctx->r4) = ctx->r6;
    // 0x800D1024: sb          $a3, 0xB9($a0)
    MEM_B(0XB9, ctx->r4) = ctx->r7;
    // 0x800D1028: sb          $a1, 0xBF($a0)
    MEM_B(0XBF, ctx->r4) = ctx->r5;
    // 0x800D102C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D1030: swc1        $f6, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f6.u32l;
    // 0x800D1034: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
    // 0x800D1038: lwc1        $f10, -0x206C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X206C);
    // 0x800D103C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800D1040: sb          $a3, 0xBA($a0)
    MEM_B(0XBA, ctx->r4) = ctx->r7;
    // 0x800D1044: sb          $t3, 0xC0($a0)
    MEM_B(0XC0, ctx->r4) = ctx->r11;
    // 0x800D1048: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D104C: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
    // 0x800D1050: lwc1        $f16, -0x2068($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2068);
    // 0x800D1054: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x800D1058: swc1        $f16, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f16.u32l;
    // 0x800D105C: lw          $t4, -0x62E4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X62E4);
    // 0x800D1060: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800D1064: sb          $v0, 0xC1($a0)
    MEM_B(0XC1, ctx->r4) = ctx->r2;
    // 0x800D1068: jr          $ra
    // 0x800D106C: sw          $t4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r12;
    return;
    // 0x800D106C: sw          $t4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_800D1070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1070: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D1074: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800D1078: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800D107C: lw          $a3, -0x630C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X630C);
    // 0x800D1080: lw          $a2, -0x6304($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6304);
    // 0x800D1084: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800D1088: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800D108C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D1090: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D1094: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D1098: blez        $a3, L_800D10D0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D109C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800D10D0;
    }
    // 0x800D109C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800D10A0:
    // 0x800D10A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D10A4: nop

    // 0x800D10A8: bne         $t6, $zero, L_800D10B8
    if (ctx->r14 != 0) {
        // 0x800D10AC: nop
    
            goto L_800D10B8;
    }
    // 0x800D10AC: nop

    // 0x800D10B0: b           L_800D11FC
    // 0x800D10B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800D11FC;
    // 0x800D10B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D10B8:
    // 0x800D10B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D10BC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D10C0: bne         $at, $zero, L_800D10A0
    if (ctx->r1 != 0) {
        // 0x800D10C4: addiu       $v0, $v0, 0x120
        ctx->r2 = ADD32(ctx->r2, 0X120);
            goto L_800D10A0;
    }
    // 0x800D10C4: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, 0X120);
    // 0x800D10C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D10CC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800D10D0:
    // 0x800D10D0: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x800D10D4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800D10D8: blez        $a3, L_800D111C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D10DC: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800D111C;
    }
    // 0x800D10DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_800D10E0:
    // 0x800D10E0: lhu         $t7, 0x9E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X9E);
    // 0x800D10E4: nop

    // 0x800D10E8: beq         $t7, $zero, L_800D110C
    if (ctx->r15 == 0) {
        // 0x800D10EC: nop
    
            goto L_800D110C;
    }
    // 0x800D10EC: nop

    // 0x800D10F0: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x800D10F4: nop

    // 0x800D10F8: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D10FC: bne         $at, $zero, L_800D110C
    if (ctx->r1 != 0) {
        // 0x800D1100: nop
    
            goto L_800D110C;
    }
    // 0x800D1100: nop

    // 0x800D1104: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800D1108: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800D110C:
    // 0x800D110C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D1110: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D1114: bne         $at, $zero, L_800D10E0
    if (ctx->r1 != 0) {
        // 0x800D1118: addiu       $v0, $v0, 0x120
        ctx->r2 = ADD32(ctx->r2, 0X120);
            goto L_800D10E0;
    }
    // 0x800D1118: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, 0X120);
L_800D111C:
    // 0x800D111C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D1120: beq         $a1, $at, L_800D1134
    if (ctx->r5 == ctx->r1) {
        // 0x800D1124: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D1134;
    }
    // 0x800D1124: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D1128: b           L_800D11FC
    // 0x800D112C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800D11FC;
    // 0x800D112C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D1130: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D1134:
    // 0x800D1134: blez        $a3, L_800D1178
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D1138: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800D1178;
    }
    // 0x800D1138: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800D113C: lhu         $a0, 0x9E($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X9E);
    // 0x800D1140: nop

L_800D1144:
    // 0x800D1144: bne         $a0, $zero, L_800D1164
    if (ctx->r4 != 0) {
        // 0x800D1148: nop
    
            goto L_800D1164;
    }
    // 0x800D1148: nop

    // 0x800D114C: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800D1150: nop

    // 0x800D1154: beq         $s0, $t8, L_800D1164
    if (ctx->r16 == ctx->r24) {
        // 0x800D1158: nop
    
            goto L_800D1164;
    }
    // 0x800D1158: nop

    // 0x800D115C: b           L_800D11FC
    // 0x800D1160: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800D11FC;
    // 0x800D1160: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D1164:
    // 0x800D1164: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D1168: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D116C: bne         $at, $zero, L_800D1144
    if (ctx->r1 != 0) {
        // 0x800D1170: nop
    
            goto L_800D1144;
    }
    // 0x800D1170: nop

    // 0x800D1174: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D1178:
    // 0x800D1178: blez        $a3, L_800D11C8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800D117C: nop
    
            goto L_800D11C8;
    }
    // 0x800D117C: nop

L_800D1180:
    // 0x800D1180: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x800D1184: nop

    // 0x800D1188: bne         $s0, $t9, L_800D11B8
    if (ctx->r16 != ctx->r25) {
        // 0x800D118C: nop
    
            goto L_800D11B8;
    }
    // 0x800D118C: nop

    // 0x800D1190: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800D1194: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800D1198: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800D119C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800D11A0: lw          $t1, 0x78($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X78);
    // 0x800D11A4: nop

    // 0x800D11A8: bne         $t1, $t5, L_800D11B8
    if (ctx->r9 != ctx->r13) {
        // 0x800D11AC: nop
    
            goto L_800D11B8;
    }
    // 0x800D11AC: nop

    // 0x800D11B0: b           L_800D11FC
    // 0x800D11B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800D11FC;
    // 0x800D11B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D11B8:
    // 0x800D11B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D11BC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800D11C0: bne         $at, $zero, L_800D1180
    if (ctx->r1 != 0) {
        // 0x800D11C4: addiu       $v0, $v0, 0x120
        ctx->r2 = ADD32(ctx->r2, 0X120);
            goto L_800D1180;
    }
    // 0x800D11C4: addiu       $v0, $v0, 0x120
    ctx->r2 = ADD32(ctx->r2, 0X120);
L_800D11C8:
    // 0x800D11C8: div         $zero, $s1, $a3
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r7)));
    // 0x800D11CC: bne         $a3, $zero, L_800D11D8
    if (ctx->r7 != 0) {
        // 0x800D11D0: nop
    
            goto L_800D11D8;
    }
    // 0x800D11D0: nop

    // 0x800D11D4: break       7
    do_break(2148340180);
L_800D11D8:
    // 0x800D11D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D11DC: bne         $a3, $at, L_800D11F0
    if (ctx->r7 != ctx->r1) {
        // 0x800D11E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D11F0;
    }
    // 0x800D11E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D11E4: bne         $s1, $at, L_800D11F0
    if (ctx->r17 != ctx->r1) {
        // 0x800D11E8: nop
    
            goto L_800D11F0;
    }
    // 0x800D11E8: nop

    // 0x800D11EC: break       6
    do_break(2148340204);
L_800D11F0:
    // 0x800D11F0: mfhi        $v0
    ctx->r2 = hi;
    // 0x800D11F4: nop

    // 0x800D11F8: nop

L_800D11FC:
    // 0x800D11FC: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800D1200: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800D1204: jr          $ra
    // 0x800D1208: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D1208: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800D120C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D120C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D1210: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D1214: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D1218: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D121C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D1220: beq         $a2, $zero, L_800D123C
    if (ctx->r6 == 0) {
        // 0x800D1224: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800D123C;
    }
    // 0x800D1224: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800D1228:
    // 0x800D1228: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D122C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800D1230: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D1234: bne         $a2, $zero, L_800D1228
    if (ctx->r6 != 0) {
        // 0x800D1238: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800D1228;
    }
    // 0x800D1238: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800D123C:
    // 0x800D123C: jr          $ra
    // 0x800D1240: nop

    return;
    // 0x800D1240: nop

;}
RECOMP_FUNC void func_800D1244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1244: blez        $a2, L_800D12EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D1248: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D12EC;
    }
    // 0x800D1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D124C: andi        $t0, $a2, 0x3
    ctx->r8 = ctx->r6 & 0X3;
    // 0x800D1250: beq         $t0, $zero, L_800D1280
    if (ctx->r8 == 0) {
        // 0x800D1254: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800D1280;
    }
    // 0x800D1254: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800D1258: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800D125C: addu        $a3, $a0, $t6
    ctx->r7 = ADD32(ctx->r4, ctx->r14);
L_800D1260:
    // 0x800D1260: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x800D1264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D1268: beq         $t0, $zero, L_800D1274
    if (ctx->r8 == 0) {
        // 0x800D126C: addu        $t7, $t0, $a1
        ctx->r15 = ADD32(ctx->r8, ctx->r5);
            goto L_800D1274;
    }
    // 0x800D126C: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
    // 0x800D1270: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_800D1274:
    // 0x800D1274: bne         $v1, $v0, L_800D1260
    if (ctx->r3 != ctx->r2) {
        // 0x800D1278: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800D1260;
    }
    // 0x800D1278: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800D127C: beq         $v0, $a2, L_800D12EC
    if (ctx->r2 == ctx->r6) {
        // 0x800D1280: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_800D12EC;
    }
L_800D1280:
    // 0x800D1280: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800D1284: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800D1288: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800D128C: addu        $v1, $t8, $a0
    ctx->r3 = ADD32(ctx->r24, ctx->r4);
L_800D1290:
    // 0x800D1290: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x800D1294: nop

    // 0x800D1298: beq         $t0, $zero, L_800D12A4
    if (ctx->r8 == 0) {
        // 0x800D129C: addu        $t1, $t0, $a1
        ctx->r9 = ADD32(ctx->r8, ctx->r5);
            goto L_800D12A4;
    }
    // 0x800D129C: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x800D12A0: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_800D12A4:
    // 0x800D12A4: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x800D12A8: nop

    // 0x800D12AC: beq         $v0, $zero, L_800D12B8
    if (ctx->r2 == 0) {
        // 0x800D12B0: addu        $t2, $v0, $a1
        ctx->r10 = ADD32(ctx->r2, ctx->r5);
            goto L_800D12B8;
    }
    // 0x800D12B0: addu        $t2, $v0, $a1
    ctx->r10 = ADD32(ctx->r2, ctx->r5);
    // 0x800D12B4: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
L_800D12B8:
    // 0x800D12B8: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800D12BC: nop

    // 0x800D12C0: beq         $v0, $zero, L_800D12CC
    if (ctx->r2 == 0) {
        // 0x800D12C4: addu        $t3, $v0, $a1
        ctx->r11 = ADD32(ctx->r2, ctx->r5);
            goto L_800D12CC;
    }
    // 0x800D12C4: addu        $t3, $v0, $a1
    ctx->r11 = ADD32(ctx->r2, ctx->r5);
    // 0x800D12C8: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
L_800D12CC:
    // 0x800D12CC: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x800D12D0: nop

    // 0x800D12D4: beq         $v0, $zero, L_800D12E0
    if (ctx->r2 == 0) {
        // 0x800D12D8: addu        $t4, $v0, $a1
        ctx->r12 = ADD32(ctx->r2, ctx->r5);
            goto L_800D12E0;
    }
    // 0x800D12D8: addu        $t4, $v0, $a1
    ctx->r12 = ADD32(ctx->r2, ctx->r5);
    // 0x800D12DC: sw          $t4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r12;
L_800D12E0:
    // 0x800D12E0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D12E4: bne         $a3, $v1, L_800D1290
    if (ctx->r7 != ctx->r3) {
        // 0x800D12E8: nop
    
            goto L_800D1290;
    }
    // 0x800D12E8: nop

L_800D12EC:
    // 0x800D12EC: jr          $ra
    // 0x800D12F0: nop

    return;
    // 0x800D12F0: nop

;}
RECOMP_FUNC void func_800D12F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D12F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D12F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D12FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D1300: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D1304: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D1308: jal         0x800D0F38
    // 0x800D130C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D0F38(rdram, ctx);
        goto after_0;
    // 0x800D130C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D1310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D1314: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1318: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D131C: sh          $a2, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = ctx->r6;
    // 0x800D1320: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D1324: addiu       $a1, $a1, -0x62EC
    ctx->r5 = ADD32(ctx->r5, -0X62EC);
    // 0x800D1328: sh          $t6, 0x96($a0)
    MEM_H(0X96, ctx->r4) = ctx->r14;
    // 0x800D132C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800D1330: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D1334: sh          $t7, 0xA8($a0)
    MEM_H(0XA8, ctx->r4) = ctx->r15;
    // 0x800D1338: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800D133C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800D1340: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
    // 0x800D1344: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800D1348: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800D134C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800D1350: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800D1354: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x800D1358: lw          $t2, -0x6300($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6300);
    // 0x800D135C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800D1360: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800D1364: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800D1368: nop

    // 0x800D136C: sw          $v1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r3;
    // 0x800D1370: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800D1374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D137C: jr          $ra
    // 0x800D1380: nop

    return;
    // 0x800D1380: nop

    // 0x800D1384: nop

    // 0x800D1388: nop

    // 0x800D138C: nop

;}
RECOMP_FUNC void func_800D1390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1390: addiu       $sp, $sp, -0x830
    ctx->r29 = ADD32(ctx->r29, -0X830);
    // 0x800D1394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1398: jal         0x800D2A58
    // 0x800D139C: nop

    func_800D2A58(rdram, ctx);
        goto after_0;
    // 0x800D139C: nop

    after_0:
    // 0x800D13A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D13A4: addiu       $a0, $a0, -0x4590
    ctx->r4 = ADD32(ctx->r4, -0X4590);
    // 0x800D13A8: jal         0x800D2AB0
    // 0x800D13AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800D2AB0(rdram, ctx);
        goto after_1;
    // 0x800D13AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x800D13B0: lui         $t6, 0x802E
    ctx->r14 = S32(0X802E << 16);
    // 0x800D13B4: ori         $t6, $t6, 0xA000
    ctx->r14 = ctx->r14 | 0XA000;
    // 0x800D13B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D13BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D13C0: sw          $t6, -0x3D58($at)
    MEM_W(-0X3D58, ctx->r1) = ctx->r14;
    // 0x800D13C4: jal         0x800D2AE0
    // 0x800D13C8: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    func_800D2AE0(rdram, ctx);
        goto after_2;
    // 0x800D13C8: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    after_2:
    // 0x800D13CC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D13D0: addiu       $t7, $t7, -0x45C0
    ctx->r15 = ADD32(ctx->r15, -0X45C0);
    // 0x800D13D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D13D8: jal         0x800D18A0
    // 0x800D13DC: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    func_800D18A0(rdram, ctx);
        goto after_3;
    // 0x800D13DC: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    after_3:
    // 0x800D13E0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D13E4: subu        $a1, $a0, $a0
    ctx->r5 = SUB32(ctx->r4, ctx->r4);
    // 0x800D13E8: lui         $t8, 0xF
    ctx->r24 = S32(0XF << 16);
    // 0x800D13EC: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800D13F0: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800D13F4: lui         $v0, 0xDE00
    ctx->r2 = S32(0XDE00 << 16);
    // 0x800D13F8: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x800D13FC: addiu       $t9, $t9, -0x44B8
    ctx->r25 = ADD32(ctx->r25, -0X44B8);
    // 0x800D1400: lui         $t0, 0xE900
    ctx->r8 = S32(0XE900 << 16);
    // 0x800D1404: lui         $t1, 0xDF00
    ctx->r9 = S32(0XDF00 << 16);
    // 0x800D1408: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D140C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800D1410: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800D1414: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D1418: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D141C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800D1420: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800D1424: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800D1428: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800D142C: sll         $a1, $t2, 3
    ctx->r5 = S32(ctx->r10 << 3);
    // 0x800D1430: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D1434: jal         0x800D1BB4
    // 0x800D1438: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D1BB4(rdram, ctx);
        goto after_4;
    // 0x800D1438: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800D143C: jal         0x800D2B40
    // 0x800D1440: nop

    func_800D2B40(rdram, ctx);
        goto after_5;
    // 0x800D1440: nop

    after_5:
    // 0x800D1444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1448: addiu       $sp, $sp, 0x830
    ctx->r29 = ADD32(ctx->r29, 0X830);
    // 0x800D144C: jr          $ra
    // 0x800D1450: nop

    return;
    // 0x800D1450: nop

;}
