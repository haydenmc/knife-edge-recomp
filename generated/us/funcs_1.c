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

RECOMP_FUNC void func_800C6DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6DBC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C6DC0: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C6DC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6DC8: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x800C6DCC: jr          $ra
    // 0x800C6DD0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C6DD0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C6DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6DDC: jal         0x800C6E40
    // 0x800C6DE0: nop

    func_800C6E40(rdram, ctx);
        goto after_0;
    // 0x800C6DE0: nop

    after_0:
    // 0x800C6DE4: jal         0x800C6ED0
    // 0x800C6DE8: nop

    func_800C6ED0(rdram, ctx);
        goto after_1;
    // 0x800C6DE8: nop

    after_1:
    // 0x800C6DEC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C6DF0: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C6DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6DF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6DFC: andi        $t7, $t6, 0x7FFF
    ctx->r15 = ctx->r14 & 0X7FFF;
    // 0x800C6E00: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    // 0x800C6E04: jr          $ra
    // 0x800C6E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C6E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C6E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6E10: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C6E14: addiu       $t6, $t6, -0x3FC0
    ctx->r14 = ADD32(ctx->r14, -0X3FC0);
    // 0x800C6E18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6E1C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C6E20: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x800C6E24: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x800C6E28: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6E2C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C6E30: sb          $a1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r5;
    // 0x800C6E34: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x800C6E38: jr          $ra
    // 0x800C6E3C: sb          $a2, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r6;
    return;
    // 0x800C6E3C: sb          $a2, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r6;
;}
RECOMP_FUNC void func_800C6E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6E44: addiu       $t6, $t6, -0x3FC0
    ctx->r14 = ADD32(ctx->r14, -0X3FC0);
    // 0x800C6E48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6E4C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x800C6E50: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x800C6E54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6E58: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    // 0x800C6E5C: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x800C6E60: jr          $ra
    // 0x800C6E64: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
    return;
    // 0x800C6E64: sb          $zero, 0x2($t8)
    MEM_B(0X2, ctx->r24) = 0;
;}
RECOMP_FUNC void func_800C6E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6E6C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C6E70: addiu       $t6, $t6, -0x3FC0
    ctx->r14 = ADD32(ctx->r14, -0X3FC0);
    // 0x800C6E74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6E78: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C6E7C: sb          $a0, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r4;
    // 0x800C6E80: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x800C6E84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6E88: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C6E8C: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x800C6E90: sb          $a1, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r5;
    // 0x800C6E94: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x800C6E98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6E9C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800C6EA0: sb          $a2, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r6;
    // 0x800C6EA4: addiu       $t9, $t9, -0x3FC0
    ctx->r25 = ADD32(ctx->r25, -0X3FC0);
    // 0x800C6EA8: sb          $a3, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r7;
    // 0x800C6EAC: lb          $t0, 0x13($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X13);
    // 0x800C6EB0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6EB4: addiu       $t1, $t1, -0x3FC0
    ctx->r9 = ADD32(ctx->r9, -0X3FC0);
    // 0x800C6EB8: sb          $t0, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r8;
    // 0x800C6EBC: lb          $t2, 0x17($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X17);
    // 0x800C6EC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6EC4: addiu       $t3, $t3, -0x3FC0
    ctx->r11 = ADD32(ctx->r11, -0X3FC0);
    // 0x800C6EC8: jr          $ra
    // 0x800C6ECC: sb          $t2, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r10;
    return;
    // 0x800C6ECC: sb          $t2, 0x8($t3)
    MEM_B(0X8, ctx->r11) = ctx->r10;
;}
RECOMP_FUNC void func_800C6ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6ED0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6ED4: addiu       $t6, $t6, -0x3FC0
    ctx->r14 = ADD32(ctx->r14, -0X3FC0);
    // 0x800C6ED8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6EDC: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    // 0x800C6EE0: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x800C6EE4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6EE8: sb          $zero, 0x4($t7)
    MEM_B(0X4, ctx->r15) = 0;
    // 0x800C6EEC: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x800C6EF0: jr          $ra
    // 0x800C6EF4: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    return;
    // 0x800C6EF4: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
;}
RECOMP_FUNC void func_800C6EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6EF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6EFC: addiu       $t6, $t6, -0x3FC0
    ctx->r14 = ADD32(ctx->r14, -0X3FC0);
    // 0x800C6F00: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800C6F04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6F08: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x800C6F0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6F10: addiu       $t8, $t8, -0x3FD8
    ctx->r24 = ADD32(ctx->r24, -0X3FD8);
    // 0x800C6F14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6F18: sb          $a0, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r4;
    // 0x800C6F1C: addiu       $t9, $t9, -0x3FC0
    ctx->r25 = ADD32(ctx->r25, -0X3FC0);
    // 0x800C6F20: sb          $a0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r4;
    // 0x800C6F24: lbu         $a0, 0x1($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1);
    // 0x800C6F28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C6F2C: addiu       $t0, $t0, -0x3FD8
    ctx->r8 = ADD32(ctx->r8, -0X3FD8);
    // 0x800C6F30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6F34: addiu       $t1, $t1, -0x3FD8
    ctx->r9 = ADD32(ctx->r9, -0X3FD8);
    // 0x800C6F38: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C6F3C: sb          $a0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r4;
    // 0x800C6F40: addiu       $t2, $t2, -0x3FC0
    ctx->r10 = ADD32(ctx->r10, -0X3FC0);
    // 0x800C6F44: sb          $a0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r4;
    // 0x800C6F48: lbu         $a0, 0x2($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X2);
    // 0x800C6F4C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6F50: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x800C6F54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C6F58: addiu       $t4, $t4, -0x3FD8
    ctx->r12 = ADD32(ctx->r12, -0X3FD8);
    // 0x800C6F5C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C6F60: sb          $a0, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r4;
    // 0x800C6F64: addiu       $t5, $t5, -0x3FC0
    ctx->r13 = ADD32(ctx->r13, -0X3FC0);
    // 0x800C6F68: sb          $a0, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r4;
    // 0x800C6F6C: lbu         $a0, 0x3($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X3);
    // 0x800C6F70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6F74: addiu       $t6, $t6, -0x3FD8
    ctx->r14 = ADD32(ctx->r14, -0X3FD8);
    // 0x800C6F78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6F7C: addiu       $t7, $t7, -0x3FD8
    ctx->r15 = ADD32(ctx->r15, -0X3FD8);
    // 0x800C6F80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6F84: sb          $a0, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r4;
    // 0x800C6F88: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x800C6F8C: sb          $a0, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r4;
    // 0x800C6F90: lbu         $a0, 0x4($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X4);
    // 0x800C6F94: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6F98: addiu       $t9, $t9, -0x3FD8
    ctx->r25 = ADD32(ctx->r25, -0X3FD8);
    // 0x800C6F9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C6FA0: addiu       $t0, $t0, -0x3FD8
    ctx->r8 = ADD32(ctx->r8, -0X3FD8);
    // 0x800C6FA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6FA8: sb          $a0, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r4;
    // 0x800C6FAC: addiu       $t1, $t1, -0x3FC0
    ctx->r9 = ADD32(ctx->r9, -0X3FC0);
    // 0x800C6FB0: sb          $a0, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r4;
    // 0x800C6FB4: lbu         $a0, 0x5($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X5);
    // 0x800C6FB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C6FBC: addiu       $t2, $t2, -0x3FD8
    ctx->r10 = ADD32(ctx->r10, -0X3FD8);
    // 0x800C6FC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6FC4: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x800C6FC8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C6FCC: sb          $a0, 0xE($t2)
    MEM_B(0XE, ctx->r10) = ctx->r4;
    // 0x800C6FD0: addiu       $t4, $t4, -0x3FC0
    ctx->r12 = ADD32(ctx->r12, -0X3FC0);
    // 0x800C6FD4: sb          $a0, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r4;
    // 0x800C6FD8: lb          $t5, 0x6($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X6);
    // 0x800C6FDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6FE0: addiu       $t6, $t6, -0x3FD8
    ctx->r14 = ADD32(ctx->r14, -0X3FD8);
    // 0x800C6FE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6FE8: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x800C6FEC: sb          $t5, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r13;
    // 0x800C6FF0: lb          $t8, 0x7($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X7);
    // 0x800C6FF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6FF8: addiu       $t9, $t9, -0x3FD8
    ctx->r25 = ADD32(ctx->r25, -0X3FD8);
    // 0x800C6FFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C7000: addiu       $t0, $t0, -0x3FC0
    ctx->r8 = ADD32(ctx->r8, -0X3FC0);
    // 0x800C7004: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800C7008: lb          $t1, 0x8($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X8);
    // 0x800C700C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C7010: addiu       $t2, $t2, -0x3FD8
    ctx->r10 = ADD32(ctx->r10, -0X3FD8);
    // 0x800C7014: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C7018: sb          $t1, 0x12($t2)
    MEM_B(0X12, ctx->r10) = ctx->r9;
    // 0x800C701C: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C7020: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C7024: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C7028: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800C702C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C7030: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C7034: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C7038: lui         $t5, 0xDB02
    ctx->r13 = S32(0XDB02 << 16);
    // 0x800C703C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C7040: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C7044: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x800C7048: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C704C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800C7050: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C7054: lui         $t1, 0xDC08
    ctx->r9 = S32(0XDC08 << 16);
    // 0x800C7058: ori         $t1, $t1, 0x60A
    ctx->r9 = ctx->r9 | 0X60A;
    // 0x800C705C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C7060: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C7064: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C7068: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C706C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C7070: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C7074: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C7078: addiu       $t3, $t3, -0x3FD8
    ctx->r11 = ADD32(ctx->r11, -0X3FD8);
    // 0x800C707C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C7080: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C7084: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800C7088: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C708C: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x800C7090: ori         $t8, $t8, 0x90A
    ctx->r24 = ctx->r24 | 0X90A;
    // 0x800C7094: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C7098: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C709C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C70A0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C70A4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C70A8: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C70AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C70B0: addiu       $t0, $t0, -0x3FD8
    ctx->r8 = ADD32(ctx->r8, -0X3FD8);
    // 0x800C70B4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800C70B8: jr          $ra
    // 0x800C70BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    return;
    // 0x800C70BC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void func_800C70C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C70C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C70C8: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C70CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C70D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C70D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C70D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C70DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C70E0: addiu       $t7, $t7, -0x3FB0
    ctx->r15 = ADD32(ctx->r15, -0X3FB0);
    // 0x800C70E4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800C70E8: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C70EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C70F0: addiu       $t9, $t9, -0x3FB0
    ctx->r25 = ADD32(ctx->r25, -0X3FB0);
    // 0x800C70F4: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x800C70F8: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800C70FC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C7100: addiu       $t1, $t1, -0x3FB0
    ctx->r9 = ADD32(ctx->r9, -0X3FB0);
    // 0x800C7104: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x800C7108: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800C710C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C7110: addiu       $t3, $t3, -0x3FB0
    ctx->r11 = ADD32(ctx->r11, -0X3FB0);
    // 0x800C7114: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x800C7118: lhu         $t4, 0x2A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2A);
    // 0x800C711C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7120: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x800C7124: sh          $t4, -0x3FAC($at)
    MEM_H(-0X3FAC, ctx->r1) = ctx->r12;
    // 0x800C7128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C712C: jal         0x800C721C
    // 0x800C7130: sh          $t5, -0x3FAA($at)
    MEM_H(-0X3FAA, ctx->r1) = ctx->r13;
    func_800C721C(rdram, ctx);
        goto after_0;
    // 0x800C7130: sh          $t5, -0x3FAA($at)
    MEM_H(-0X3FAA, ctx->r1) = ctx->r13;
    after_0:
    // 0x800C7134: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C7138: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C713C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7140: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C7144: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x800C7148: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    // 0x800C714C: jr          $ra
    // 0x800C7150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7154: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C7158: addiu       $t6, $t6, -0x3FB0
    ctx->r14 = ADD32(ctx->r14, -0X3FB0);
    // 0x800C715C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C7160: addiu       $t7, $t7, -0x3FB0
    ctx->r15 = ADD32(ctx->r15, -0X3FB0);
    // 0x800C7164: sb          $zero, 0x3($t6)
    MEM_B(0X3, ctx->r14) = 0;
    // 0x800C7168: lbu         $a1, 0x3($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X3);
    // 0x800C716C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C7170: addiu       $t8, $t8, -0x3FB0
    ctx->r24 = ADD32(ctx->r24, -0X3FB0);
    // 0x800C7174: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C7178: sb          $a1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r5;
    // 0x800C717C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x800C7180: sb          $a0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r4;
    // 0x800C7184: addiu       $t9, $t9, -0x3FB0
    ctx->r25 = ADD32(ctx->r25, -0X3FB0);
    // 0x800C7188: sb          $a0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r4;
    // 0x800C718C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7190: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C7194: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x800C7198: sh          $zero, -0x3FAA($at)
    MEM_H(-0X3FAA, ctx->r1) = 0;
    // 0x800C719C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C71A0: sh          $zero, -0x3FAC($at)
    MEM_H(-0X3FAC, ctx->r1) = 0;
    // 0x800C71A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C71A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C71AC: andi        $t1, $t0, 0xBFFF
    ctx->r9 = ctx->r8 & 0XBFFF;
    // 0x800C71B0: sh          $t1, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r9;
    // 0x800C71B4: jr          $ra
    // 0x800C71B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C71B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C71BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C71BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C71C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C71C4: addiu       $t6, $t6, -0x3FB0
    ctx->r14 = ADD32(ctx->r14, -0X3FB0);
    // 0x800C71C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C71CC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C71D0: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x800C71D4: addiu       $t7, $t7, -0x3FB0
    ctx->r15 = ADD32(ctx->r15, -0X3FB0);
    // 0x800C71D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C71DC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C71E0: sb          $a1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r5;
    // 0x800C71E4: addiu       $t8, $t8, -0x3FB0
    ctx->r24 = ADD32(ctx->r24, -0X3FB0);
    // 0x800C71E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C71EC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C71F0: sb          $a2, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r6;
    // 0x800C71F4: addiu       $t9, $t9, -0x3FB0
    ctx->r25 = ADD32(ctx->r25, -0X3FB0);
    // 0x800C71F8: jr          $ra
    // 0x800C71FC: sb          $a3, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r7;
    return;
    // 0x800C71FC: sb          $a3, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r7;
;}
RECOMP_FUNC void func_800C7200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7200: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800C7204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7208: sh          $a1, -0x3FAC($at)
    MEM_H(-0X3FAC, ctx->r1) = ctx->r5;
    // 0x800C720C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800C7210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7214: jr          $ra
    // 0x800C7218: sh          $a0, -0x3FAA($at)
    MEM_H(-0X3FAA, ctx->r1) = ctx->r4;
    return;
    // 0x800C7218: sh          $a0, -0x3FAA($at)
    MEM_H(-0X3FAA, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800C721C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C721C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C7220: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C7224: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C7228: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C722C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C7230: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C7234: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C7238: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C723C: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x800C7240: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C7244: addiu       $t0, $t0, -0x3FB0
    ctx->r8 = ADD32(ctx->r8, -0X3FB0);
    // 0x800C7248: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C724C: lbu         $t4, 0x1($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1);
    // 0x800C7250: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800C7254: lbu         $t8, 0x2($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X2);
    // 0x800C7258: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C725C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800C7260: lbu         $t4, 0x3($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X3);
    // 0x800C7264: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800C7268: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C726C: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800C7270: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C7274: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C7278: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x800C727C: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x800C7280: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C7284: or          $t3, $t5, $t2
    ctx->r11 = ctx->r13 | ctx->r10;
    // 0x800C7288: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C728C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800C7290: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C7294: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800C7298: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C729C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800C72A0: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800C72A4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800C72A8: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C72AC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800C72B0: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C72B4: lui         $t2, 0xDB08
    ctx->r10 = S32(0XDB08 << 16);
    // 0x800C72B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C72BC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800C72C0: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C72C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C72C8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800C72CC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800C72D0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C72D4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C72D8: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C72DC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C72E0: lhu         $t8, -0x3FAC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3FAC);
    // 0x800C72E4: lhu         $t6, -0x3FAA($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3FAA);
    // 0x800C72E8: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x800C72EC: negu        $t5, $t8
    ctx->r13 = SUB32(0, ctx->r24);
    // 0x800C72F0: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x800C72F4: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x800C72F8: bne         $t9, $zero, L_800C7304
    if (ctx->r25 != 0) {
        // 0x800C72FC: nop
    
            goto L_800C7304;
    }
    // 0x800C72FC: nop

    // 0x800C7300: break       7
    do_break(2148299520);
L_800C7304:
    // 0x800C7304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C7308: bne         $t9, $at, L_800C731C
    if (ctx->r25 != ctx->r1) {
        // 0x800C730C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C731C;
    }
    // 0x800C730C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7310: bne         $t7, $at, L_800C731C
    if (ctx->r15 != ctx->r1) {
        // 0x800C7314: nop
    
            goto L_800C731C;
    }
    // 0x800C7314: nop

    // 0x800C7318: break       6
    do_break(2148299544);
L_800C731C:
    // 0x800C731C: addu        $at, $t7, $zero
    ctx->r1 = ADD32(ctx->r15, 0);
    // 0x800C7320: sll         $t2, $t5, 8
    ctx->r10 = S32(ctx->r13 << 8);
    // 0x800C7324: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800C7328: mflo        $t1
    ctx->r9 = lo;
    // 0x800C732C: andi        $t0, $t1, 0xFFFF
    ctx->r8 = ctx->r9 & 0XFFFF;
    // 0x800C7330: sll         $t4, $t0, 16
    ctx->r12 = S32(ctx->r8 << 16);
    // 0x800C7334: div         $zero, $t3, $t9
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r25)));
    // 0x800C7338: mflo        $t6
    ctx->r14 = lo;
    // 0x800C733C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C7340: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800C7344: or          $t1, $t4, $t7
    ctx->r9 = ctx->r12 | ctx->r15;
    // 0x800C7348: bne         $t9, $zero, L_800C7354
    if (ctx->r25 != 0) {
        // 0x800C734C: nop
    
            goto L_800C7354;
    }
    // 0x800C734C: nop

    // 0x800C7350: break       7
    do_break(2148299600);
L_800C7354:
    // 0x800C7354: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C7358: bne         $t9, $at, L_800C736C
    if (ctx->r25 != ctx->r1) {
        // 0x800C735C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C736C;
    }
    // 0x800C735C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7360: bne         $t3, $at, L_800C736C
    if (ctx->r11 != ctx->r1) {
        // 0x800C7364: nop
    
            goto L_800C736C;
    }
    // 0x800C7364: nop

    // 0x800C7368: break       6
    do_break(2148299624);
L_800C736C:
    // 0x800C736C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800C7370: jr          $ra
    // 0x800C7374: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    return;
    // 0x800C7374: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
;}
RECOMP_FUNC void func_800C7378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7378: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C737C: sb          $zero, 0x7($sp)
    MEM_B(0X7, ctx->r29) = 0;
L_800C7380:
    // 0x800C7380: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x800C7384: lbu         $t8, 0x7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X7);
    // 0x800C7388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C738C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C7390: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C7394: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C7398: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800C739C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C73A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C73A4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800C73A8: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x800C73AC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C73B0: sh          $zero, -0x41DC($at)
    MEM_H(-0X41DC, ctx->r1) = 0;
    // 0x800C73B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C73B8: lhu         $a0, 0x4($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X4);
    // 0x800C73BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C73C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C73C4: sh          $a0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r4;
    // 0x800C73C8: lbu         $t2, 0x7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7);
    // 0x800C73CC: lbu         $t4, 0x7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7);
    // 0x800C73D0: lbu         $t6, 0x7($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7);
    // 0x800C73D4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C73D8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800C73DC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800C73E0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C73E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C73E8: sh          $a0, -0x41E0($at)
    MEM_H(-0X41E0, ctx->r1) = ctx->r4;
    // 0x800C73EC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C73F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C73F4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800C73F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C73FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C7400: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800C7404: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C7408: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x800C740C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C7410: sb          $zero, -0x41D9($at)
    MEM_B(-0X41D9, ctx->r1) = 0;
    // 0x800C7414: lb          $t0, 0x7($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X7);
    // 0x800C7418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C741C: sb          $t0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r8;
    // 0x800C7420: lbu         $t1, 0x7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7);
    // 0x800C7424: lbu         $t3, 0x7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X7);
    // 0x800C7428: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C742C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C7430: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800C7434: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C7438: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C743C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C7440: sb          $zero, -0x41D8($at)
    MEM_B(-0X41D8, ctx->r1) = 0;
    // 0x800C7444: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800C7448: bne         $at, $zero, L_800C7380
    if (ctx->r1 != 0) {
        // 0x800C744C: sb          $t4, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r12;
            goto L_800C7380;
    }
    // 0x800C744C: sb          $t4, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r12;
    // 0x800C7450: jr          $ra
    // 0x800C7454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C7454: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C7458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C745C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7460: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C7464: jal         0x800D1D90
    // 0x800C7468: addiu       $a0, $a0, -0x4200
    ctx->r4 = ADD32(ctx->r4, -0X4200);
    func_800D1D90(rdram, ctx);
        goto after_0;
    // 0x800C7468: addiu       $a0, $a0, -0x4200
    ctx->r4 = ADD32(ctx->r4, -0X4200);
    after_0:
    // 0x800C746C: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
L_800C7470:
    // 0x800C7470: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C7474: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C7478: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C747C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C7480: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x800C7484: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x800C7488: beq         $t0, $zero, L_800C7654
    if (ctx->r8 == 0) {
        // 0x800C748C: nop
    
            goto L_800C7654;
    }
    // 0x800C748C: nop

    // 0x800C7490: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800C7494: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C7498: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C749C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C74A0: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800C74A4: lb          $t2, -0x41FE($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X41FE);
    // 0x800C74A8: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x800C74AC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800C74B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C74B4: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C74B8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C74BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C74C0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C74C4: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800C74C8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800C74CC: sb          $t2, -0x41DA($at)
    MEM_B(-0X41DA, ctx->r1) = ctx->r10;
    // 0x800C74D0: lb          $t8, -0x41FD($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X41FD);
    // 0x800C74D4: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C74D8: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800C74DC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800C74E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C74E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C74E8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800C74EC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C74F0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C74F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800C74F8: lhu         $t1, -0x41FA($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41FA);
    // 0x800C74FC: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800C7500: sb          $t8, -0x41D9($at)
    MEM_B(-0X41D9, ctx->r1) = ctx->r24;
    // 0x800C7504: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C7508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C750C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800C7510: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C7514: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800C7518: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C751C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800C7520: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x800C7524: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800C7528: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C752C: sll         $t6, $t2, 3
    ctx->r14 = S32(ctx->r10 << 3);
    // 0x800C7530: sh          $t1, -0x41DE($at)
    MEM_H(-0X41DE, ctx->r1) = ctx->r9;
    // 0x800C7534: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x800C7538: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x800C753C: lhu         $t0, -0x4200($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4200);
    // 0x800C7540: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    // 0x800C7544: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C7548: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
    // 0x800C754C: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C7550: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x800C7554: lhu         $t8, 0x1C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1C);
    // 0x800C7558: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C755C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800C7560: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800C7564: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x800C7568: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x800C756C: bne         $t5, $t8, L_800C7614
    if (ctx->r13 != ctx->r24) {
        // 0x800C7570: nop
    
            goto L_800C7614;
    }
    // 0x800C7570: nop

    // 0x800C7574: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x800C7578: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C757C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C7580: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x800C7584: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800C7588: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x800C758C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800C7590: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x800C7594: lbu         $t9, 0x8($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X8);
    // 0x800C7598: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800C759C: bne         $at, $zero, L_800C75E8
    if (ctx->r1 != 0) {
        // 0x800C75A0: nop
    
            goto L_800C75E8;
    }
    // 0x800C75A0: nop

    // 0x800C75A4: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800C75A8: andi        $t7, $t1, 0x17
    ctx->r15 = ctx->r9 & 0X17;
    // 0x800C75AC: sb          $t7, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r15;
    // 0x800C75B0: lbu         $t5, 0x1F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C75B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C75B8: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x800C75BC: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800C75C0: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x800C75C4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800C75C8: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x800C75CC: lbu         $t6, 0x8($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X8);
    // 0x800C75D0: andi        $t0, $t6, 0x1
    ctx->r8 = ctx->r14 & 0X1;
    // 0x800C75D4: bne         $t0, $zero, L_800C7654
    if (ctx->r8 != 0) {
        // 0x800C75D8: nop
    
            goto L_800C7654;
    }
    // 0x800C75D8: nop

    // 0x800C75DC: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x800C75E0: b           L_800C7654
    // 0x800C75E4: sh          $t9, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r25;
        goto L_800C7654;
    // 0x800C75E4: sh          $t9, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r25;
L_800C75E8:
    // 0x800C75E8: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C75EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C75F0: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x800C75F4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800C75F8: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800C75FC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800C7600: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x800C7604: lbu         $t8, 0x8($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X8);
    // 0x800C7608: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x800C760C: b           L_800C7654
    // 0x800C7610: sb          $t3, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r11;
        goto L_800C7654;
    // 0x800C7610: sb          $t3, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r11;
L_800C7614:
    // 0x800C7614: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C7618: lbu         $t9, 0x1F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C761C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7620: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x800C7624: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x800C7628: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C762C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800C7630: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C7634: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800C7638: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C763C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800C7640: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x800C7644: sb          $zero, -0x41D8($at)
    MEM_B(-0X41D8, ctx->r1) = 0;
    // 0x800C7648: addu        $t7, $t2, $t1
    ctx->r15 = ADD32(ctx->r10, ctx->r9);
    // 0x800C764C: lhu         $t4, 0x2($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X2);
    // 0x800C7650: sh          $t4, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r12;
L_800C7654:
    // 0x800C7654: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C7658: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x800C765C: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x800C7660: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800C7664: bne         $at, $zero, L_800C7470
    if (ctx->r1 != 0) {
        // 0x800C7668: sb          $t3, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r11;
            goto L_800C7470;
    }
    // 0x800C7668: sb          $t3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r11;
    // 0x800C766C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7674: jr          $ra
    // 0x800C7678: nop

    return;
    // 0x800C7678: nop

;}
RECOMP_FUNC void func_800C767C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C767C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7680: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C7684: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C7688: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C768C: lw          $t9, -0x421C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X421C);
    // 0x800C7690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7694: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C7698: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C769C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C76A0: addiu       $t8, $t8, -0x7990
    ctx->r24 = ADD32(ctx->r24, -0X7990);
    // 0x800C76A4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800C76A8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800C76AC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800C76B0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C76B4: sh          $t1, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r9;
    // 0x800C76B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C76BC: lw          $t2, -0x4218($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4218);
    // 0x800C76C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C76C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C76C8: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800C76CC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C76D0: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x800C76D4: lw          $t6, -0x4218($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4218);
    // 0x800C76D8: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800C76DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800C76E0: lw          $a3, -0x421C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X421C);
    // 0x800C76E4: addiu       $a2, $a2, -0x799C
    ctx->r6 = ADD32(ctx->r6, -0X799C);
    // 0x800C76E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C76EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C76F0: jal         0x800C7B78
    // 0x800C76F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800C7B78(rdram, ctx);
        goto after_0;
    // 0x800C76F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C76F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C76FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C7700: lw          $a2, -0x4220($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4220);
    // 0x800C7704: lw          $a1, -0x4224($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4224);
    // 0x800C7708: jal         0x800D3D78
    // 0x800C770C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    spMove_recomp(rdram, ctx);
        goto after_1;
    // 0x800C770C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800C7710: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C7714: lbu         $t7, -0x4225($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4225);
    // 0x800C7718: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C771C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C7720: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800C7724: lbu         $a3, -0x4226($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X4226);
    // 0x800C7728: lbu         $a2, -0x4227($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X4227);
    // 0x800C772C: lbu         $a1, -0x4228($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X4228);
    // 0x800C7730: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7734: jal         0x800D7380
    // 0x800C7738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    spColor_recomp(rdram, ctx);
        goto after_2;
    // 0x800C7738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800C773C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7740: ldc1        $f4, -0x4210($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4210);
    // 0x800C7744: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7748: ldc1        $f8, -0x4208($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4208);
    // 0x800C774C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800C7750: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7754: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C7758: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800C775C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C7760: jal         0x800D7310
    // 0x800C7764: nop

    spScale_recomp(rdram, ctx);
        goto after_3;
    // 0x800C7764: nop

    after_3:
    // 0x800C7768: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C776C: lhu         $t9, -0x4530($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4530);
    // 0x800C7770: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x800C7774: beq         $t0, $zero, L_800C7798
    if (ctx->r8 == 0) {
        // 0x800C7778: nop
    
            goto L_800C7798;
    }
    // 0x800C7778: nop

    // 0x800C777C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7780: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    // 0x800C7784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7788: jal         0x800D3D84
    // 0x800C778C: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    spScissor_recomp(rdram, ctx);
        goto after_4;
    // 0x800C778C: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    after_4:
    // 0x800C7790: b           L_800C77AC
    // 0x800C7794: nop

        goto L_800C77AC;
    // 0x800C7794: nop

L_800C7798:
    // 0x800C7798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C779C: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
    // 0x800C77A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C77A4: jal         0x800D3D84
    // 0x800C77A8: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    spScissor_recomp(rdram, ctx);
        goto after_5;
    // 0x800C77A8: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    after_5:
L_800C77AC:
    // 0x800C77AC: jal         0x800D55F4
    // 0x800C77B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    spX2Draw_recomp(rdram, ctx);
        goto after_6;
    // 0x800C77B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x800C77B4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C77B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C77BC: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800C77C0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800C77C4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C77C8: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800C77CC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800C77D0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C77D4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800C77D8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800C77DC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C77E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C77E4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800C77E8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800C77EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C77F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C77F4: lhu         $t9, -0x4530($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4530);
    // 0x800C77F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C77FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C7800: ori         $t0, $t9, 0x200
    ctx->r8 = ctx->r25 | 0X200;
    // 0x800C7804: jr          $ra
    // 0x800C7808: sh          $t0, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r8;
    return;
    // 0x800C7808: sh          $t0, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void func_800C780C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C780C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7810: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C7814: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C7818: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C781C: lw          $t9, -0x421C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X421C);
    // 0x800C7820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7824: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C7828: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C782C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C7830: addiu       $t8, $t8, -0x7990
    ctx->r24 = ADD32(ctx->r24, -0X7990);
    // 0x800C7834: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800C7838: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800C783C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800C7840: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C7844: sh          $t1, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r9;
    // 0x800C7848: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C784C: lw          $t2, -0x4218($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4218);
    // 0x800C7850: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7854: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C7858: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800C785C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C7860: sh          $t4, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r12;
    // 0x800C7864: lw          $t6, -0x4218($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4218);
    // 0x800C7868: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800C786C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800C7870: lw          $a3, -0x421C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X421C);
    // 0x800C7874: addiu       $a2, $a2, -0x799C
    ctx->r6 = ADD32(ctx->r6, -0X799C);
    // 0x800C7878: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C787C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7880: jal         0x800C7B78
    // 0x800C7884: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800C7B78(rdram, ctx);
        goto after_0;
    // 0x800C7884: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C7888: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C788C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C7890: lw          $a2, -0x4220($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4220);
    // 0x800C7894: lw          $a1, -0x4224($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4224);
    // 0x800C7898: jal         0x800D3D78
    // 0x800C789C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    spMove_recomp(rdram, ctx);
        goto after_1;
    // 0x800C789C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800C78A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C78A4: lbu         $t7, -0x4225($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4225);
    // 0x800C78A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C78AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C78B0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800C78B4: lbu         $a3, -0x4226($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X4226);
    // 0x800C78B8: lbu         $a2, -0x4227($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X4227);
    // 0x800C78BC: lbu         $a1, -0x4228($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X4228);
    // 0x800C78C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C78C4: jal         0x800D7380
    // 0x800C78C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    spColor_recomp(rdram, ctx);
        goto after_2;
    // 0x800C78C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x800C78CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C78D0: ldc1        $f4, -0x4210($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X4210);
    // 0x800C78D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C78D8: ldc1        $f8, -0x4208($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4208);
    // 0x800C78DC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800C78E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C78E4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800C78E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800C78EC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800C78F0: jal         0x800D7310
    // 0x800C78F4: nop

    spScale_recomp(rdram, ctx);
        goto after_3;
    // 0x800C78F4: nop

    after_3:
    // 0x800C78F8: jal         0x800D55F4
    // 0x800C78FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    spX2Draw_recomp(rdram, ctx);
        goto after_4;
    // 0x800C78FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800C7900: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C7904: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C7908: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800C790C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800C7910: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C7914: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C7918: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C791C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800C7920: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C7924: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C7928: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C792C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C7930: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800C7934: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800C7938: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800C793C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800C7940: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C7944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7948: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C794C: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x800C7950: jr          $ra
    // 0x800C7954: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C7954: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C7958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C795C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7960: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800C7964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7968: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C796C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C7970: jal         0x800D54C8
    // 0x800C7974: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7974: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800C7978: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C797C: lw          $t8, -0x7958($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7958);
    // 0x800C7980: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7984: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C7988: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C798C: sw          $t8, -0x7954($at)
    MEM_W(-0X7954, ctx->r1) = ctx->r24;
    // 0x800C7990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7994: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800C7998: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C799C: sb          $t1, -0x4228($at)
    MEM_B(-0X4228, ctx->r1) = ctx->r9;
    // 0x800C79A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79A4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C79A8: sb          $t2, -0x4227($at)
    MEM_B(-0X4227, ctx->r1) = ctx->r10;
    // 0x800C79AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79B0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800C79B4: sb          $t3, -0x4226($at)
    MEM_B(-0X4226, ctx->r1) = ctx->r11;
    // 0x800C79B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79BC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C79C0: sb          $t4, -0x4225($at)
    MEM_B(-0X4225, ctx->r1) = ctx->r12;
    // 0x800C79C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79C8: sw          $zero, -0x4224($at)
    MEM_W(-0X4224, ctx->r1) = 0;
    // 0x800C79CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79D0: sw          $zero, -0x4220($at)
    MEM_W(-0X4220, ctx->r1) = 0;
    // 0x800C79D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79D8: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x800C79DC: sw          $t5, -0x421C($at)
    MEM_W(-0X421C, ctx->r1) = ctx->r13;
    // 0x800C79E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C79E8: sw          $t6, -0x4218($at)
    MEM_W(-0X4218, ctx->r1) = ctx->r14;
    // 0x800C79EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C79F0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C79F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C79F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C79FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A00: sdc1        $f4, -0x4210($at)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, -0X4210, ctx->r1);
    // 0x800C7A04: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C7A08: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C7A0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C7A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7A18: jr          $ra
    // 0x800C7A1C: sdc1        $f6, -0x4208($at)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X4208, ctx->r1);
    return;
    // 0x800C7A1C: sdc1        $f6, -0x4208($at)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X4208, ctx->r1);
;}
RECOMP_FUNC void func_800C7A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7A24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7A28: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800C7A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7A30: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C7A34: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C7A38: jal         0x800D6320
    // 0x800C7A3C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    spX2Finish_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7A3C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800C7A40: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7A44: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C7A48: addiu       $t9, $t8, -0x8
    ctx->r25 = ADD32(ctx->r24, -0X8);
    // 0x800C7A4C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C7A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7A58: jr          $ra
    // 0x800C7A5C: nop

    return;
    // 0x800C7A5C: nop

;}
RECOMP_FUNC void func_800C7A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A64: sw          $a0, -0x421C($at)
    MEM_W(-0X421C, ctx->r1) = ctx->r4;
    // 0x800C7A68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A6C: jr          $ra
    // 0x800C7A70: sw          $a1, -0x4218($at)
    MEM_W(-0X4218, ctx->r1) = ctx->r5;
    return;
    // 0x800C7A70: sw          $a1, -0x4218($at)
    MEM_W(-0X4218, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_800C7A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A78: sw          $a0, -0x4224($at)
    MEM_W(-0X4224, ctx->r1) = ctx->r4;
    // 0x800C7A7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A80: jr          $ra
    // 0x800C7A84: sw          $a1, -0x4220($at)
    MEM_W(-0X4220, ctx->r1) = ctx->r5;
    return;
    // 0x800C7A84: sw          $a1, -0x4220($at)
    MEM_W(-0X4220, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_800C7A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A8C: sdc1        $f12, -0x4210($at)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, -0X4210, ctx->r1);
    // 0x800C7A90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7A94: jr          $ra
    // 0x800C7A98: sdc1        $f14, -0x4208($at)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, -0X4208, ctx->r1);
    return;
    // 0x800C7A98: sdc1        $f14, -0x4208($at)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, -0X4208, ctx->r1);
;}
RECOMP_FUNC void func_800C7A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A9C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C7AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7AA4: sb          $a0, -0x4228($at)
    MEM_B(-0X4228, ctx->r1) = ctx->r4;
    // 0x800C7AA8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C7AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7AB0: sb          $a1, -0x4227($at)
    MEM_B(-0X4227, ctx->r1) = ctx->r5;
    // 0x800C7AB4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C7AB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7ABC: sb          $a2, -0x4226($at)
    MEM_B(-0X4226, ctx->r1) = ctx->r6;
    // 0x800C7AC0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C7AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7AC8: jr          $ra
    // 0x800C7ACC: sb          $a3, -0x4225($at)
    MEM_B(-0X4225, ctx->r1) = ctx->r7;
    return;
    // 0x800C7ACC: sb          $a3, -0x4225($at)
    MEM_B(-0X4225, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void func_800C7AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7AD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7AD8: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C7ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7AE0: beq         $t6, $zero, L_800C7B00
    if (ctx->r14 == 0) {
        // 0x800C7AE4: nop
    
            goto L_800C7B00;
    }
    // 0x800C7AE4: nop

    // 0x800C7AE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C7AEC: addiu       $a0, $a0, -0x7990
    ctx->r4 = ADD32(ctx->r4, -0X7990);
    // 0x800C7AF0: jal         0x800D73B0
    // 0x800C7AF4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    spSetAttribute_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7AF4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_0:
    // 0x800C7AF8: b           L_800C7B10
    // 0x800C7AFC: nop

        goto L_800C7B10;
    // 0x800C7AFC: nop

L_800C7B00:
    // 0x800C7B00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C7B04: addiu       $a0, $a0, -0x7990
    ctx->r4 = ADD32(ctx->r4, -0X7990);
    // 0x800C7B08: jal         0x800D73C0
    // 0x800C7B0C: addiu       $a1, $zero, 0x7BF
    ctx->r5 = ADD32(0, 0X7BF);
    spClearAttribute_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7B0C: addiu       $a1, $zero, 0x7BF
    ctx->r5 = ADD32(0, 0X7BF);
    after_1:
L_800C7B10:
    // 0x800C7B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7B18: jr          $ra
    // 0x800C7B1C: nop

    return;
    // 0x800C7B1C: nop

;}
RECOMP_FUNC void func_800C7B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B20: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7B24: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C7B28: beq         $t6, $zero, L_800C7B58
    if (ctx->r14 == 0) {
        // 0x800C7B2C: nop
    
            goto L_800C7B58;
    }
    // 0x800C7B2C: nop

    // 0x800C7B30: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7B34: beq         $t7, $a1, L_800C7B58
    if (ctx->r15 == ctx->r5) {
        // 0x800C7B38: nop
    
            goto L_800C7B58;
    }
    // 0x800C7B38: nop

L_800C7B3C:
    // 0x800C7B3C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x800C7B40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C7B44: beq         $t8, $zero, L_800C7B58
    if (ctx->r24 == 0) {
        // 0x800C7B48: nop
    
            goto L_800C7B58;
    }
    // 0x800C7B48: nop

    // 0x800C7B4C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7B50: bne         $t9, $a1, L_800C7B3C
    if (ctx->r25 != ctx->r5) {
        // 0x800C7B54: nop
    
            goto L_800C7B3C;
    }
    // 0x800C7B54: nop

L_800C7B58:
    // 0x800C7B58: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800C7B5C: beq         $t0, $zero, L_800C7B6C
    if (ctx->r8 == 0) {
        // 0x800C7B60: nop
    
            goto L_800C7B6C;
    }
    // 0x800C7B60: nop

    // 0x800C7B64: jr          $ra
    // 0x800C7B68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800C7B68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C7B6C:
    // 0x800C7B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7B70: jr          $ra
    // 0x800C7B74: nop

    return;
    // 0x800C7B74: nop

;}
RECOMP_FUNC void func_800C7B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7B7C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C7B80: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7B84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C7B88: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C7B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7B90: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C7B94: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C7B98: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C7B9C: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x800C7BA0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800C7BA4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800C7BA8: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800C7BAC: sh          $t0, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r8;
    // 0x800C7BB0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C7BB4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C7BB8: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x800C7BBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C7BC0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800C7BC4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C7BC8: blez        $t4, L_800C7E00
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800C7BCC: sw          $t3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r11;
            goto L_800C7E00;
    }
    // 0x800C7BCC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_800C7BD0:
    // 0x800C7BD0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7BD4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800C7BD8: blez        $t5, L_800C7DC4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800C7BDC: nop
    
            goto L_800C7DC4;
    }
    // 0x800C7BDC: nop

L_800C7BE0:
    // 0x800C7BE0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C7BE4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C7BE8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C7BEC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C7BF0: bne         $t9, $zero, L_800C7C58
    if (ctx->r25 != 0) {
        // 0x800C7BF4: nop
    
            goto L_800C7C58;
    }
    // 0x800C7BF4: nop

    // 0x800C7BF8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800C7BFC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7C00: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C7C04: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800C7C08: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800C7C0C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800C7C10: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x800C7C14: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C7C18: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x800C7C1C: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800C7C20: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x800C7C24: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x800C7C28: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x800C7C2C: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x800C7C30: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x800C7C34: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7C38: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C7C3C: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x800C7C40: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800C7C44: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800C7C48: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C7C4C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7C50: b           L_800C7E0C
    // 0x800C7C54: sh          $t4, 0x28($t6)
    MEM_H(0X28, ctx->r14) = ctx->r12;
        goto L_800C7E0C;
    // 0x800C7C54: sh          $t4, 0x28($t6)
    MEM_H(0X28, ctx->r14) = ctx->r12;
L_800C7C58:
    // 0x800C7C58: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C7C5C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800C7C60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C7C64: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800C7C68: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7C6C: bne         $t1, $at, L_800C7CD0
    if (ctx->r9 != ctx->r1) {
        // 0x800C7C70: nop
    
            goto L_800C7CD0;
    }
    // 0x800C7C70: nop

    // 0x800C7C74: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800C7C78: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7C7C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C7C80: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x800C7C84: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x800C7C88: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x800C7C8C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800C7C90: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x800C7C94: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x800C7C98: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x800C7C9C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800C7CA0: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x800C7CA4: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x800C7CA8: sw          $t5, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r13;
    // 0x800C7CAC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7CB0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C7CB4: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x800C7CB8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800C7CBC: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
    // 0x800C7CC0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C7CC4: addiu       $t4, $t8, -0x1
    ctx->r12 = ADD32(ctx->r24, -0X1);
    // 0x800C7CC8: b           L_800C7D94
    // 0x800C7CCC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
        goto L_800C7D94;
    // 0x800C7CCC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_800C7CD0:
    // 0x800C7CD0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800C7CD4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C7CD8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800C7CDC: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x800C7CE0: lbu         $a1, 0x0($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X0);
    // 0x800C7CE4: jal         0x800C7B20
    // 0x800C7CE8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_800C7B20(rdram, ctx);
        goto after_0;
    // 0x800C7CE8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_0:
    // 0x800C7CEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C7CF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7CF4: beq         $t1, $zero, L_800C7D48
    if (ctx->r9 == 0) {
        // 0x800C7CF8: nop
    
            goto L_800C7D48;
    }
    // 0x800C7CF8: nop

    // 0x800C7CFC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800C7D00: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D04: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C7D08: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x800C7D0C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800C7D10: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800C7D14: subu        $t2, $t1, $t3
    ctx->r10 = SUB32(ctx->r9, ctx->r11);
    // 0x800C7D18: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x800C7D1C: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800C7D20: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800C7D24: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800C7D28: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x800C7D2C: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x800C7D30: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800C7D34: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800C7D38: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x800C7D3C: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x800C7D40: b           L_800C7D94
    // 0x800C7D44: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
        goto L_800C7D94;
    // 0x800C7D44: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
L_800C7D48:
    // 0x800C7D48: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800C7D4C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D50: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800C7D54: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800C7D58: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x800C7D5C: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800C7D60: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800C7D64: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x800C7D68: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x800C7D6C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800C7D70: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800C7D74: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x800C7D78: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800C7D7C: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
    // 0x800C7D80: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D84: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C7D88: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x800C7D8C: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x800C7D90: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
L_800C7D94:
    // 0x800C7D94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C7D98: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C7DA0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7DA4: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800C7DA8: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x800C7DAC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800C7DB0: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C7DB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800C7DB8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800C7DBC: bne         $at, $zero, L_800C7BE0
    if (ctx->r1 != 0) {
        // 0x800C7DC0: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800C7BE0;
    }
    // 0x800C7DC0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800C7DC4:
    // 0x800C7DC4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C7DC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800C7DCC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C7DD0: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x800C7DD4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800C7DD8: bne         $t2, $at, L_800C7DE8
    if (ctx->r10 != ctx->r1) {
        // 0x800C7DDC: nop
    
            goto L_800C7DE8;
    }
    // 0x800C7DDC: nop

    // 0x800C7DE0: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x800C7DE4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_800C7DE8:
    // 0x800C7DE8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800C7DEC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800C7DF0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800C7DF4: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7DF8: bne         $at, $zero, L_800C7BD0
    if (ctx->r1 != 0) {
        // 0x800C7DFC: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800C7BD0;
    }
    // 0x800C7DFC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_800C7E00:
    // 0x800C7E00: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7E04: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800C7E08: sh          $t5, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r13;
L_800C7E0C:
    // 0x800C7E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7E10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C7E14: jr          $ra
    // 0x800C7E18: nop

    return;
    // 0x800C7E18: nop

;}
RECOMP_FUNC void func_800C7E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7E1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7E24: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C7E28: jal         0x800C7958
    // 0x800C7E2C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C7958(rdram, ctx);
        goto after_0;
    // 0x800C7E2C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x800C7E30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C7E34: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x800C7E38: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x800C7E3C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C7E40: beq         $t8, $zero, L_800C7E50
    if (ctx->r24 == 0) {
        // 0x800C7E44: nop
    
            goto L_800C7E50;
    }
    // 0x800C7E44: nop

    // 0x800C7E48: jal         0x80193B40
    // 0x800C7E4C: nop

    func_80193B40_1501A0(rdram, ctx);
        goto after_1;
    // 0x800C7E4C: nop

    after_1:
L_800C7E50:
    // 0x800C7E50: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C7E54: lw          $t9, -0x2E50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E50);
    // 0x800C7E58: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x800C7E5C: beq         $at, $zero, L_800C7F60
    if (ctx->r1 == 0) {
        // 0x800C7E60: nop
    
            goto L_800C7F60;
    }
    // 0x800C7E60: nop

    // 0x800C7E64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C7E68: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C7E6C: addu        $at, $at, $t9
    gpr jr_addend_800C7E74 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C7E70: lw          $t9, -0x2BEC($at)
    ctx->r25 = ADD32(ctx->r1, -0X2BEC);
    // 0x800C7E74: jr          $t9
    // 0x800C7E78: nop

    switch (jr_addend_800C7E74 >> 2) {
        case 0: goto L_800C7ED8; break;
        case 1: goto L_800C7EE8; break;
        case 2: goto L_800C7F60; break;
        case 3: goto L_800C7F60; break;
        case 4: goto L_800C7F60; break;
        case 5: goto L_800C7EF8; break;
        case 6: goto L_800C7F08; break;
        case 7: goto L_800C7F18; break;
        case 8: goto L_800C7F38; break;
        case 9: goto L_800C7F28; break;
        case 10: goto L_800C7F48; break;
        case 11: goto L_800C7F60; break;
        case 12: goto L_800C7F58; break;
        case 13: goto L_800C7F60; break;
        case 14: goto L_800C7F60; break;
        case 15: goto L_800C7F60; break;
        case 16: goto L_800C7F60; break;
        case 17: goto L_800C7F60; break;
        case 18: goto L_800C7F60; break;
        case 19: goto L_800C7F60; break;
        case 20: goto L_800C7E7C; break;
        default: switch_error(__func__, 0x800C7E74, 0x800ED414);
    }
    // 0x800C7E78: nop

L_800C7E7C:
    // 0x800C7E7C: jal         0x801752D8
    // 0x800C7E80: nop

    func_801752D8_1501A0(rdram, ctx);
        goto after_2;
    // 0x800C7E80: nop

    after_2:
    // 0x800C7E84: jal         0x80178044
    // 0x800C7E88: nop

    func_80178044_1501A0(rdram, ctx);
        goto after_3;
    // 0x800C7E88: nop

    after_3:
    // 0x800C7E8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C7E90: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x800C7E94: lbu         $t1, 0xA($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XA);
    // 0x800C7E98: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x800C7E9C: beq         $t2, $zero, L_800C7F60
    if (ctx->r10 == 0) {
        // 0x800C7EA0: nop
    
            goto L_800C7F60;
    }
    // 0x800C7EA0: nop

    // 0x800C7EA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C7EA8: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x800C7EAC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x800C7EB0: bne         $t4, $zero, L_800C7EC8
    if (ctx->r12 != 0) {
        // 0x800C7EB4: nop
    
            goto L_800C7EC8;
    }
    // 0x800C7EB4: nop

    // 0x800C7EB8: jal         0x80193A34
    // 0x800C7EBC: nop

    func_80193A34_1501A0(rdram, ctx);
        goto after_4;
    // 0x800C7EBC: nop

    after_4:
    // 0x800C7EC0: b           L_800C7F60
    // 0x800C7EC4: nop

        goto L_800C7F60;
    // 0x800C7EC4: nop

L_800C7EC8:
    // 0x800C7EC8: jal         0x80196810
    // 0x800C7ECC: nop

    func_80196810_1501A0(rdram, ctx);
        goto after_5;
    // 0x800C7ECC: nop

    after_5:
    // 0x800C7ED0: b           L_800C7F60
    // 0x800C7ED4: nop

        goto L_800C7F60;
    // 0x800C7ED4: nop

L_800C7ED8:
    // 0x800C7ED8: jal         0x8017B678
    // 0x800C7EDC: nop

    func_8017B678_03D600(rdram, ctx);
        goto after_6;
    // 0x800C7EDC: nop

    after_6:
    // 0x800C7EE0: b           L_800C7F60
    // 0x800C7EE4: nop

        goto L_800C7F60;
    // 0x800C7EE4: nop

L_800C7EE8:
    // 0x800C7EE8: jal         0x8017BC34
    // 0x800C7EEC: nop

    func_8017BC34_041650(rdram, ctx);
        goto after_7;
    // 0x800C7EEC: nop

    after_7:
    // 0x800C7EF0: b           L_800C7F60
    // 0x800C7EF4: nop

        goto L_800C7F60;
    // 0x800C7EF4: nop

L_800C7EF8:
    // 0x800C7EF8: jal         0x8017D70C
    // 0x800C7EFC: nop

    func_8017D70C_0EF7C0(rdram, ctx);
        goto after_8;
    // 0x800C7EFC: nop

    after_8:
    // 0x800C7F00: b           L_800C7F60
    // 0x800C7F04: nop

        goto L_800C7F60;
    // 0x800C7F04: nop

L_800C7F08:
    // 0x800C7F08: jal         0x8017DEA0
    // 0x800C7F0C: nop

    func_8017DEA0_111CC0(rdram, ctx);
        goto after_9;
    // 0x800C7F0C: nop

    after_9:
    // 0x800C7F10: b           L_800C7F60
    // 0x800C7F14: nop

        goto L_800C7F60;
    // 0x800C7F14: nop

L_800C7F18:
    // 0x800C7F18: jal         0x8017B96C
    // 0x800C7F1C: nop

    func_8017B96C_0F4810(rdram, ctx);
        goto after_10;
    // 0x800C7F1C: nop

    after_10:
    // 0x800C7F20: b           L_800C7F60
    // 0x800C7F24: nop

        goto L_800C7F60;
    // 0x800C7F24: nop

L_800C7F28:
    // 0x800C7F28: jal         0x8017D4CC
    // 0x800C7F2C: nop

    func_8017D4CC_1199D0(rdram, ctx);
        goto after_11;
    // 0x800C7F2C: nop

    after_11:
    // 0x800C7F30: b           L_800C7F60
    // 0x800C7F34: nop

        goto L_800C7F60;
    // 0x800C7F34: nop

L_800C7F38:
    // 0x800C7F38: jal         0x8017BB40
    // 0x800C7F3C: nop

    func_8017BB40_12C2F0(rdram, ctx);
        goto after_12;
    // 0x800C7F3C: nop

    after_12:
    // 0x800C7F40: b           L_800C7F60
    // 0x800C7F44: nop

        goto L_800C7F60;
    // 0x800C7F44: nop

L_800C7F48:
    // 0x800C7F48: jal         0x8017CFEC
    // 0x800C7F4C: nop

    func_8017CFEC_12C2F0(rdram, ctx);
        goto after_13;
    // 0x800C7F4C: nop

    after_13:
    // 0x800C7F50: b           L_800C7F60
    // 0x800C7F54: nop

        goto L_800C7F60;
    // 0x800C7F54: nop

L_800C7F58:
    // 0x800C7F58: jal         0x8017E5D8
    // 0x800C7F5C: nop

    func_8017E5D8_0EF7C0(rdram, ctx);
        goto after_14;
    // 0x800C7F5C: nop

    after_14:
L_800C7F60:
    // 0x800C7F60: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C7F64: lhu         $t5, -0x4530($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X4530);
    // 0x800C7F68: andi        $t6, $t5, 0x200
    ctx->r14 = ctx->r13 & 0X200;
    // 0x800C7F6C: beq         $t6, $zero, L_800C7F94
    if (ctx->r14 == 0) {
        // 0x800C7F70: nop
    
            goto L_800C7F94;
    }
    // 0x800C7F70: nop

    // 0x800C7F74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C7F78: jal         0x800C7A20
    // 0x800C7F7C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C7A20(rdram, ctx);
        goto after_15;
    // 0x800C7F7C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_15:
    // 0x800C7F80: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C7F84: lhu         $t7, -0x4530($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X4530);
    // 0x800C7F88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C7F8C: andi        $t8, $t7, 0xFDFF
    ctx->r24 = ctx->r15 & 0XFDFF;
    // 0x800C7F90: sh          $t8, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r24;
L_800C7F94:
    // 0x800C7F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7F9C: jr          $ra
    // 0x800C7FA0: nop

    return;
    // 0x800C7FA0: nop

;}
RECOMP_FUNC void func_800C7FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7FA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7FAC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C7FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7FB4: bne         $t6, $zero, L_800C7FCC
    if (ctx->r14 != 0) {
        // 0x800C7FB8: nop
    
            goto L_800C7FCC;
    }
    // 0x800C7FB8: nop

    // 0x800C7FBC: jal         0x800C80B8
    // 0x800C7FC0: nop

    func_800C80B8(rdram, ctx);
        goto after_0;
    // 0x800C7FC0: nop

    after_0:
    // 0x800C7FC4: b           L_800C80A8
    // 0x800C7FC8: nop

        goto L_800C80A8;
    // 0x800C7FC8: nop

L_800C7FCC:
    // 0x800C7FCC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C7FD0: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800C7FD4: beq         $t7, $at, L_800C7FEC
    if (ctx->r15 == ctx->r1) {
        // 0x800C7FD8: nop
    
            goto L_800C7FEC;
    }
    // 0x800C7FD8: nop

    // 0x800C7FDC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C7FE0: lw          $t8, -0x6B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6B4C);
    // 0x800C7FE4: beq         $t7, $t8, L_800C80A8
    if (ctx->r15 == ctx->r24) {
        // 0x800C7FE8: nop
    
            goto L_800C80A8;
    }
    // 0x800C7FE8: nop

L_800C7FEC:
    // 0x800C7FEC: jal         0x800C80B8
    // 0x800C7FF0: nop

    func_800C80B8(rdram, ctx);
        goto after_1;
    // 0x800C7FF0: nop

    after_1:
    // 0x800C7FF4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C7FF8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C7FFC: addiu       $t1, $t1, -0x54B0
    ctx->r9 = ADD32(ctx->r9, -0X54B0);
    // 0x800C8000: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C8004: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800C8008: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800C800C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800C8010: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800C8014: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800C8018: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C801C: jal         0x800CD800
    // 0x800C8020: subu        $a1, $t4, $t3
    ctx->r5 = SUB32(ctx->r12, ctx->r11);
    func_800CD800(rdram, ctx);
        goto after_2;
    // 0x800C8020: subu        $a1, $t4, $t3
    ctx->r5 = SUB32(ctx->r12, ctx->r11);
    after_2:
    // 0x800C8024: jal         0x800CD840
    // 0x800C8028: nop

    func_800CD840(rdram, ctx);
        goto after_3;
    // 0x800C8028: nop

    after_3:
    // 0x800C802C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800C8030: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8034: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800C8038: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C803C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800C8040: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C8044: sw          $v0, -0x6B50($at)
    MEM_W(-0X6B50, ctx->r1) = ctx->r2;
    // 0x800C8048: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800C804C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C8050: lw          $a0, -0x6B50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B50);
    // 0x800C8054: jal         0x800CF5B8
    // 0x800C8058: lw          $a1, -0x54B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X54B0);
    func_800CF5B8(rdram, ctx);
        goto after_4;
    // 0x800C8058: lw          $a1, -0x54B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X54B0);
    after_4:
    // 0x800C805C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C8060: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C8064: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C8068: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800C806C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C8070: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800C8074: jal         0x800CB808
    // 0x800C8078: lw          $a0, -0x54B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54B0);
    func_800CB808(rdram, ctx);
        goto after_5;
    // 0x800C8078: lw          $a0, -0x54B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54B0);
    after_5:
    // 0x800C807C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C8080: lw          $t9, -0x6B38($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B38);
    // 0x800C8084: bne         $t9, $zero, L_800C809C
    if (ctx->r25 != 0) {
        // 0x800C8088: nop
    
            goto L_800C809C;
    }
    // 0x800C8088: nop

    // 0x800C808C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C8090: lw          $a0, -0x6B50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B50);
    // 0x800C8094: jal         0x800CF61C
    // 0x800C8098: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800CF61C(rdram, ctx);
        goto after_6;
    // 0x800C8098: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_6:
L_800C809C:
    // 0x800C809C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C80A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C80A4: sw          $t0, -0x6B4C($at)
    MEM_W(-0X6B4C, ctx->r1) = ctx->r8;
L_800C80A8:
    // 0x800C80A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C80AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C80B0: jr          $ra
    // 0x800C80B4: nop

    return;
    // 0x800C80B4: nop

;}
RECOMP_FUNC void func_800C80B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C80B8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C80BC: lw          $t6, -0x6B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6B4C);
    // 0x800C80C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C80C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C80C8: beq         $t6, $zero, L_800C80F0
    if (ctx->r14 == 0) {
        // 0x800C80CC: nop
    
            goto L_800C80F0;
    }
    // 0x800C80CC: nop

    // 0x800C80D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C80D4: lw          $a0, -0x6B50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B50);
    // 0x800C80D8: jal         0x800CF4F4
    // 0x800C80DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CF4F4(rdram, ctx);
        goto after_0;
    // 0x800C80DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800C80E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C80E4: sw          $zero, -0x6B50($at)
    MEM_W(-0X6B50, ctx->r1) = 0;
    // 0x800C80E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C80EC: sw          $zero, -0x6B4C($at)
    MEM_W(-0X6B4C, ctx->r1) = 0;
L_800C80F0:
    // 0x800C80F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C80F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C80F8: jr          $ra
    // 0x800C80FC: nop

    return;
    // 0x800C80FC: nop

;}
RECOMP_FUNC void func_800C8100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C810C: jal         0x800CF568
    // 0x800C8110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800CF568(rdram, ctx);
        goto after_0;
    // 0x800C8110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800C8114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C811C: jr          $ra
    // 0x800C8120: nop

    return;
    // 0x800C8120: nop

;}
RECOMP_FUNC void func_800C8124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C812C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C8130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C8134: jal         0x800CF4F4
    // 0x800C8138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CF4F4(rdram, ctx);
        goto after_0;
    // 0x800C8138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800C813C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8144: jr          $ra
    // 0x800C8148: nop

    return;
    // 0x800C8148: nop

;}
RECOMP_FUNC void func_800C814C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C814C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8150: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C815C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C8160: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800C8164:
    // 0x800C8164: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8168: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C816C: addiu       $t9, $t9, -0x6BF0
    ctx->r25 = ADD32(ctx->r25, -0X6BF0);
    // 0x800C8170: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C8174: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C8178: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C817C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C8180: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800C8184: beq         $t1, $zero, L_800C81D4
    if (ctx->r9 == 0) {
        // 0x800C8188: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_800C81D4;
    }
    // 0x800C8188: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800C818C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x800C8190: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C8194: bne         $t2, $t3, L_800C81D4
    if (ctx->r10 != ctx->r11) {
        // 0x800C8198: nop
    
            goto L_800C81D4;
    }
    // 0x800C8198: nop

    // 0x800C819C: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x800C81A0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800C81A4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C81A8: lw          $t5, -0x69B8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X69B8);
    // 0x800C81AC: beq         $t5, $zero, L_800C81D4
    if (ctx->r13 == 0) {
        // 0x800C81B0: nop
    
            goto L_800C81D4;
    }
    // 0x800C81B0: nop

    // 0x800C81B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C81B8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C81BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C81C0: nop

    // 0x800C81C4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C81C8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C81CC: jal         0x800CF688
    // 0x800C81D0: nop

    func_800CF688(rdram, ctx);
        goto after_0;
    // 0x800C81D0: nop

    after_0:
L_800C81D4:
    // 0x800C81D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C81D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C81DC: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x800C81E0: bne         $at, $zero, L_800C8164
    if (ctx->r1 != 0) {
        // 0x800C81E4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800C8164;
    }
    // 0x800C81E4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800C81E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C81EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C81F0: jr          $ra
    // 0x800C81F4: nop

    return;
    // 0x800C81F4: nop

;}
RECOMP_FUNC void func_800C81F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C81F8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C81FC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C8200: lw          $t7, -0x6AF4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AF4);
    // 0x800C8204: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C820C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800C8210: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800C8214: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800C8218: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C821C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800C8220: bne         $t7, $zero, L_800C8530
    if (ctx->r15 != 0) {
        // 0x800C8224: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_800C8530;
    }
    // 0x800C8224: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800C8228: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C822C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800C8230:
    // 0x800C8230: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800C8234: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C8238: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C823C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C8240: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800C8244: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800C8248: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C824C: lw          $t1, -0x6BF0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6BF0);
    // 0x800C8250: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C8254: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800C8258: lw          $t3, -0x69B8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X69B8);
    // 0x800C825C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800C8260: beq         $t1, $zero, L_800C851C
    if (ctx->r9 == 0) {
        // 0x800C8264: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_800C851C;
    }
    // 0x800C8264: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800C8268: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800C826C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C8270: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800C8274: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C8278: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C827C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C8280: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C8284: lw          $t6, -0x6BEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6BEC);
    // 0x800C8288: bne         $t6, $t7, L_800C851C
    if (ctx->r14 != ctx->r15) {
        // 0x800C828C: nop
    
            goto L_800C851C;
    }
    // 0x800C828C: nop

    // 0x800C8290: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C8294: beq         $t8, $zero, L_800C851C
    if (ctx->r24 == 0) {
        // 0x800C8298: nop
    
            goto L_800C851C;
    }
    // 0x800C8298: nop

    // 0x800C829C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C82A0: lw          $t9, -0x7940($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7940);
    // 0x800C82A4: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800C82A8: bne         $t0, $zero, L_800C851C
    if (ctx->r8 != 0) {
        // 0x800C82AC: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_800C851C;
    }
    // 0x800C82AC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800C82B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C82B4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C82B8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800C82BC: nop

    // 0x800C82C0: bc1f        L_800C82D8
    if (!c1cs) {
        // 0x800C82C4: nop
    
            goto L_800C82D8;
    }
    // 0x800C82C4: nop

    // 0x800C82C8: jal         0x800C8124
    // 0x800C82CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800C8124(rdram, ctx);
        goto after_0;
    // 0x800C82CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800C82D0: b           L_800C8530
    // 0x800C82D4: nop

        goto L_800C8530;
    // 0x800C82D4: nop

L_800C82D8:
    // 0x800C82D8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800C82DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C82E0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C82E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C82E8: lwc1        $f18, -0x2B98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B98);
    // 0x800C82EC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C82F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800C82F4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800C82F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C82FC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C8300: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C8304: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800C8308: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C830C: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x800C8310: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C8314: lwc1        $f18, -0x2B94($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B94);
    // 0x800C8318: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C831C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C8320: lw          $t5, -0x69D0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X69D0);
    // 0x800C8324: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800C8328: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C832C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800C8330: lui         $at, 0x36
    ctx->r1 = S32(0X36 << 16);
    // 0x800C8334: ori         $at, $at, 0xEE80
    ctx->r1 = ctx->r1 | 0XEE80;
    // 0x800C8338: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C833C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x800C8340: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800C8344: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C8348: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C834C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800C8350: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8354: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C8358: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800C835C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x800C8360: mfhi        $t0
    ctx->r8 = hi;
    // 0x800C8364: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800C8368: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C836C: lwc1        $f16, -0x2B90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B90);
    // 0x800C8370: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8374: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800C8378: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C837C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C8380: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C8384: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800C8388: bc1f        L_800C83A0
    if (!c1cs) {
        // 0x800C838C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800C83A0;
    }
    // 0x800C838C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C8390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8394: nop

    // 0x800C8398: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C839C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_800C83A0:
    // 0x800C83A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C83A4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C83A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C83AC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800C83B0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800C83B4: nop

    // 0x800C83B8: bc1f        L_800C83D4
    if (!c1cs) {
        // 0x800C83BC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800C83D4;
    }
    // 0x800C83BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C83C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C83C4: nop

    // 0x800C83C8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C83CC: b           L_800C83E8
    // 0x800C83D0: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
        goto L_800C83E8;
    // 0x800C83D0: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_800C83D4:
    // 0x800C83D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C83D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C83DC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C83E0: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C83E4: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
L_800C83E8:
    // 0x800C83E8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800C83EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C83F0: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C83F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C83F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C83FC: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C8400: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C8404: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C8408: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800C840C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x800C8410: bc1f        L_800C8424
    if (!c1cs) {
        // 0x800C8414: nop
    
            goto L_800C8424;
    }
    // 0x800C8414: nop

    // 0x800C8418: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C841C: nop

    // 0x800C8420: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
L_800C8424:
    // 0x800C8424: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C8428: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C842C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C8430: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C8434: nop

    // 0x800C8438: bc1f        L_800C844C
    if (!c1cs) {
        // 0x800C843C: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800C844C;
    }
    // 0x800C843C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C8440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8444: nop

    // 0x800C8448: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
L_800C844C:
    // 0x800C844C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8450: lwc1        $f16, -0x2B8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B8C);
    // 0x800C8454: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C8458: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800C845C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8460: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C8464: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C8468: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800C846C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800C8470: beq         $s0, $at, L_800C848C
    if (ctx->r16 == ctx->r1) {
        // 0x800C8474: sw          $t1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r9;
            goto L_800C848C;
    }
    // 0x800C8474: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800C8478: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C847C: beq         $s0, $at, L_800C84A8
    if (ctx->r16 == ctx->r1) {
        // 0x800C8480: nop
    
            goto L_800C84A8;
    }
    // 0x800C8480: nop

    // 0x800C8484: b           L_800C84C0
    // 0x800C8488: nop

        goto L_800C84C0;
    // 0x800C8488: nop

L_800C848C:
    // 0x800C848C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C8490: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C8494: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800C8498: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800C849C: lw          $t3, -0x69D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X69D0);
    // 0x800C84A0: b           L_800C84C0
    // 0x800C84A4: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
        goto L_800C84C0;
    // 0x800C84A4: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_800C84A8:
    // 0x800C84A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800C84AC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C84B0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C84B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C84B8: lw          $t8, -0x69CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X69CC);
    // 0x800C84BC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800C84C0:
    // 0x800C84C0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800C84C4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800C84C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C84CC: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800C84D0: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800C84D4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C84D8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C84DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800C84E0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800C84E4: jal         0x800CF5B8
    // 0x800C84E8: sw          $t9, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r25;
    func_800CF5B8(rdram, ctx);
        goto after_1;
    // 0x800C84E8: sw          $t9, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r25;
    after_1:
    // 0x800C84EC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C84F0: lw          $t1, -0x6B38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6B38);
    // 0x800C84F4: bne         $t1, $zero, L_800C8510
    if (ctx->r9 != 0) {
        // 0x800C84F8: nop
    
            goto L_800C8510;
    }
    // 0x800C84F8: nop

    // 0x800C84FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800C8500: jal         0x800CF61C
    // 0x800C8504: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800CF61C(rdram, ctx);
        goto after_2;
    // 0x800C8504: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x800C8508: b           L_800C851C
    // 0x800C850C: nop

        goto L_800C851C;
    // 0x800C850C: nop

L_800C8510:
    // 0x800C8510: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800C8514: jal         0x800CF61C
    // 0x800C8518: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800CF61C(rdram, ctx);
        goto after_3;
    // 0x800C8518: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
L_800C851C:
    // 0x800C851C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800C8520: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C8524: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x800C8528: bne         $at, $zero, L_800C8230
    if (ctx->r1 != 0) {
        // 0x800C852C: sw          $t5, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r13;
            goto L_800C8230;
    }
    // 0x800C852C: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800C8530:
    // 0x800C8530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8534: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8538: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C853C: jr          $ra
    // 0x800C8540: nop

    return;
    // 0x800C8540: nop

;}
RECOMP_FUNC void func_800C8544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C854C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C8550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8554: bne         $t6, $zero, L_800C8570
    if (ctx->r14 != 0) {
        // 0x800C8558: nop
    
            goto L_800C8570;
    }
    // 0x800C8558: nop

    // 0x800C855C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C8560: jal         0x800CF400
    // 0x800C8564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CF400(rdram, ctx);
        goto after_0;
    // 0x800C8564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800C8568: b           L_800C85A0
    // 0x800C856C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C85A0;
    // 0x800C856C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8570:
    // 0x800C8570: jal         0x800CB9A8
    // 0x800C8574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800CB9A8(rdram, ctx);
        goto after_1;
    // 0x800C8574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800C8578: beq         $v0, $zero, L_800C859C
    if (ctx->r2 == 0) {
        // 0x800C857C: nop
    
            goto L_800C859C;
    }
    // 0x800C857C: nop

    // 0x800C8580: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C8584: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800C8588: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C858C: jal         0x800C8604
    // 0x800C8590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C8604(rdram, ctx);
        goto after_2;
    // 0x800C8590: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x800C8594: b           L_800C85A0
    // 0x800C8598: nop

        goto L_800C85A0;
    // 0x800C8598: nop

L_800C859C:
    // 0x800C859C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C85A0:
    // 0x800C85A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C85A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C85A8: jr          $ra
    // 0x800C85AC: nop

    return;
    // 0x800C85AC: nop

;}
RECOMP_FUNC void func_800C85B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C85B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C85B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C85BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C85C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C85C4: jal         0x800CB9A8
    // 0x800C85C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800CB9A8(rdram, ctx);
        goto after_0;
    // 0x800C85C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800C85CC: beq         $v0, $zero, L_800C85F0
    if (ctx->r2 == 0) {
        // 0x800C85D0: nop
    
            goto L_800C85F0;
    }
    // 0x800C85D0: nop

    // 0x800C85D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C85D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C85DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C85E0: jal         0x800C8604
    // 0x800C85E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C8604(rdram, ctx);
        goto after_1;
    // 0x800C85E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800C85E8: b           L_800C85F4
    // 0x800C85EC: nop

        goto L_800C85F4;
    // 0x800C85EC: nop

L_800C85F0:
    // 0x800C85F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C85F4:
    // 0x800C85F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C85F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C85FC: jr          $ra
    // 0x800C8600: nop

    return;
    // 0x800C8600: nop

;}
RECOMP_FUNC void func_800C8604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8604: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C8608: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800C860C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800C8610: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C8614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C8618: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C861C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C8620: lw          $t8, -0x69B8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X69B8);
    // 0x800C8624: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800C8628: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800C862C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800C8630: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C8634: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800C8638: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800C863C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800C8640: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800C8644: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800C8648: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800C864C: bne         $t8, $zero, L_800C8658
    if (ctx->r24 != 0) {
        // 0x800C8650: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_800C8658;
    }
    // 0x800C8650: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800C8654: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_800C8658:
    // 0x800C8658: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800C865C: bne         $t9, $zero, L_800C8698
    if (ctx->r25 != 0) {
        // 0x800C8660: nop
    
            goto L_800C8698;
    }
    // 0x800C8660: nop

    // 0x800C8664: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800C8668: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C866C: addiu       $t2, $t2, -0x69D0
    ctx->r10 = ADD32(ctx->r10, -0X69D0);
    // 0x800C8670: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C8674: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800C8678: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800C867C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800C8680: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800C8684: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800C8688: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800C868C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C8690: b           L_800C88DC
    // 0x800C8694: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_800C88DC;
    // 0x800C8694: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_800C8698:
    // 0x800C8698: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800C869C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C86A0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C86A4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800C86A8: nop

    // 0x800C86AC: bc1f        L_800C86BC
    if (!c1cs) {
        // 0x800C86B0: nop
    
            goto L_800C86BC;
    }
    // 0x800C86B0: nop

    // 0x800C86B4: b           L_800C8DFC
    // 0x800C86B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C86B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C86BC:
    // 0x800C86BC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800C86C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C86C4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C86C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C86CC: lwc1        $f18, -0x2B88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B88);
    // 0x800C86D0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C86D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800C86D8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800C86DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C86E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C86E4: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C86E8: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C86EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C86F0: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C86F4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C86F8: lwc1        $f18, -0x2B84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B84);
    // 0x800C86FC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C8700: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C8704: lw          $t2, -0x69D0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X69D0);
    // 0x800C8708: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800C870C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C8710: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800C8714: lui         $at, 0x36
    ctx->r1 = S32(0X36 << 16);
    // 0x800C8718: ori         $at, $at, 0xEE80
    ctx->r1 = ctx->r1 | 0XEE80;
    // 0x800C871C: multu       $t2, $t9
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8720: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x800C8724: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800C8728: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C872C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C8730: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800C8734: mflo        $t4
    ctx->r12 = lo;
    // 0x800C8738: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800C873C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800C8740: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x800C8744: mfhi        $t7
    ctx->r15 = hi;
    // 0x800C8748: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C874C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8750: lwc1        $f16, -0x2B80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B80);
    // 0x800C8754: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8758: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800C875C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800C8760: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C8764: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C8768: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800C876C: bc1f        L_800C8784
    if (!c1cs) {
        // 0x800C8770: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800C8784;
    }
    // 0x800C8770: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C8774: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8778: nop

    // 0x800C877C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C8780: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_800C8784:
    // 0x800C8784: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C8788: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C878C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C8790: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800C8794: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800C8798: nop

    // 0x800C879C: bc1f        L_800C87B8
    if (!c1cs) {
        // 0x800C87A0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800C87B8;
    }
    // 0x800C87A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C87A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C87A8: nop

    // 0x800C87AC: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C87B0: b           L_800C87CC
    // 0x800C87B4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
        goto L_800C87CC;
    // 0x800C87B4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
L_800C87B8:
    // 0x800C87B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C87BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C87C0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C87C4: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C87C8: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
L_800C87CC:
    // 0x800C87CC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800C87D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C87D4: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C87D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C87DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C87E0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C87E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C87E8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C87EC: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800C87F0: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800C87F4: bc1f        L_800C8808
    if (!c1cs) {
        // 0x800C87F8: nop
    
            goto L_800C8808;
    }
    // 0x800C87F8: nop

    // 0x800C87FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C8800: nop

    // 0x800C8804: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
L_800C8808:
    // 0x800C8808: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C880C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C8810: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C8814: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C8818: nop

    // 0x800C881C: bc1f        L_800C8830
    if (!c1cs) {
        // 0x800C8820: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800C8830;
    }
    // 0x800C8820: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C8824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8828: nop

    // 0x800C882C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
L_800C8830:
    // 0x800C8830: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8834: lwc1        $f16, -0x2B7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B7C);
    // 0x800C8838: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C883C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800C8840: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800C8844: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C8848: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C884C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C8850: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x800C8854: lw          $t9, -0x69C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X69C8);
    // 0x800C8858: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800C885C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C8860: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C8864: sra         $t3, $t5, 16
    ctx->r11 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800C8868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C886C: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x800C8870: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800C8874: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800C8878: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800C887C: beq         $s0, $at, L_800C8898
    if (ctx->r16 == ctx->r1) {
        // 0x800C8880: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_800C8898;
    }
    // 0x800C8880: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800C8884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C8888: beq         $s0, $at, L_800C88B4
    if (ctx->r16 == ctx->r1) {
        // 0x800C888C: nop
    
            goto L_800C88B4;
    }
    // 0x800C888C: nop

    // 0x800C8890: b           L_800C88DC
    // 0x800C8894: nop

        goto L_800C88DC;
    // 0x800C8894: nop

L_800C8898:
    // 0x800C8898: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800C889C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C88A0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800C88A4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800C88A8: lw          $t0, -0x69D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X69D0);
    // 0x800C88AC: b           L_800C88DC
    // 0x800C88B0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_800C88DC;
    // 0x800C88B0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_800C88B4:
    // 0x800C88B4: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800C88B8: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C88BC: addiu       $t4, $t4, -0x69D0
    ctx->r12 = ADD32(ctx->r12, -0X69D0);
    // 0x800C88C0: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C88C4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800C88C8: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800C88CC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800C88D0: lw          $t3, 0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X8);
    // 0x800C88D4: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800C88D8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_800C88DC:
    // 0x800C88DC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800C88E0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C88E4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800C88E8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800C88EC: lw          $t0, -0x69BC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X69BC);
    // 0x800C88F0: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x800C88F4: beq         $t1, $zero, L_800C8970
    if (ctx->r9 == 0) {
        // 0x800C88F8: nop
    
            goto L_800C8970;
    }
    // 0x800C88F8: nop

    // 0x800C88FC: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C8900: lw          $t2, -0x6B30($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6B30);
    // 0x800C8904: beq         $t2, $zero, L_800C8970
    if (ctx->r10 == 0) {
        // 0x800C8908: nop
    
            goto L_800C8970;
    }
    // 0x800C8908: nop

    // 0x800C890C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C8910: lw          $t9, -0x6B28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B28);
    // 0x800C8914: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800C8918: sltu        $at, $t9, $t4
    ctx->r1 = ctx->r25 < ctx->r12 ? 1 : 0;
    // 0x800C891C: bne         $at, $zero, L_800C892C
    if (ctx->r1 != 0) {
        // 0x800C8920: nop
    
            goto L_800C892C;
    }
    // 0x800C8920: nop

    // 0x800C8924: b           L_800C8DFC
    // 0x800C8928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C8928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C892C:
    // 0x800C892C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C8930: jal         0x800C8124
    // 0x800C8934: lw          $a0, -0x6B2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B2C);
    func_800C8124(rdram, ctx);
        goto after_0;
    // 0x800C8934: lw          $a0, -0x6B2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B2C);
    after_0:
    // 0x800C8938: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C893C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C8940: lw          $t5, -0x6B24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6B24);
    // 0x800C8944: sw          $zero, -0x6B2C($at)
    MEM_W(-0X6B2C, ctx->r1) = 0;
    // 0x800C8948: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C894C: sw          $zero, -0x6B30($at)
    MEM_W(-0X6B30, ctx->r1) = 0;
    // 0x800C8950: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8954: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x800C8958: sw          $zero, -0x6B28($at)
    MEM_W(-0X6B28, ctx->r1) = 0;
    // 0x800C895C: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800C8960: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C8964: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8968: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C896C: sw          $zero, -0x6BE4($at)
    MEM_W(-0X6BE4, ctx->r1) = 0;
L_800C8970:
    // 0x800C8970: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8974: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_800C8978:
    // 0x800C8978: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800C897C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C8980: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C8984: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C8988: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C898C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800C8990: lw          $t0, -0x6BF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6BF0);
    // 0x800C8994: bne         $t0, $zero, L_800C89A4
    if (ctx->r8 != 0) {
        // 0x800C8998: nop
    
            goto L_800C89A4;
    }
    // 0x800C8998: nop

    // 0x800C899C: b           L_800C8A0C
    // 0x800C89A0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_800C8A0C;
    // 0x800C89A0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_800C89A4:
    // 0x800C89A4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800C89A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C89AC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C89B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C89B4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C89B8: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x800C89BC: jal         0x800CF568
    // 0x800C89C0: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    func_800CF568(rdram, ctx);
        goto after_1;
    // 0x800C89C0: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    after_1:
    // 0x800C89C4: bne         $v0, $zero, L_800C8A0C
    if (ctx->r2 != 0) {
        // 0x800C89C8: nop
    
            goto L_800C8A0C;
    }
    // 0x800C89C8: nop

    // 0x800C89CC: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800C89D0: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C89D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C89D8: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x800C89DC: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x800C89E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C89E4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C89E8: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x800C89EC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800C89F0: sw          $zero, -0x6BF0($at)
    MEM_W(-0X6BF0, ctx->r1) = 0;
    // 0x800C89F4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800C89F8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C89FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8A00: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C8A04: sw          $zero, -0x6BEC($at)
    MEM_W(-0X6BEC, ctx->r1) = 0;
    // 0x800C8A08: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
L_800C8A0C:
    // 0x800C8A0C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800C8A10: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C8A14: addiu       $t7, $t7, -0x6BF0
    ctx->r15 = ADD32(ctx->r15, -0X6BF0);
    // 0x800C8A18: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800C8A1C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800C8A20: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800C8A24: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x800C8A28: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C8A2C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800C8A30: bne         $t2, $t4, L_800C8AC4
    if (ctx->r10 != ctx->r12) {
        // 0x800C8A34: nop
    
            goto L_800C8AC4;
    }
    // 0x800C8A34: nop

    // 0x800C8A38: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800C8A3C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800C8A40: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800C8A44: bne         $at, $zero, L_800C8AA0
    if (ctx->r1 != 0) {
        // 0x800C8A48: nop
    
            goto L_800C8AA0;
    }
    // 0x800C8A48: nop

    // 0x800C8A4C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800C8A50: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x800C8A54: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800C8A58: lw          $t8, 0xC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XC);
    // 0x800C8A5C: beq         $t8, $zero, L_800C8A6C
    if (ctx->r24 == 0) {
        // 0x800C8A60: nop
    
            goto L_800C8A6C;
    }
    // 0x800C8A60: nop

    // 0x800C8A64: b           L_800C8DFC
    // 0x800C8A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C8A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8A6C:
    // 0x800C8A6C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800C8A70: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C8A74: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800C8A78: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800C8A7C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800C8A80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C8A84: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800C8A88: lw          $t4, -0x6BE8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6BE8);
    // 0x800C8A8C: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x800C8A90: beq         $at, $zero, L_800C8AC4
    if (ctx->r1 == 0) {
        // 0x800C8A94: nop
    
            goto L_800C8AC4;
    }
    // 0x800C8A94: nop

    // 0x800C8A98: b           L_800C8AC4
    // 0x800C8A9C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
        goto L_800C8AC4;
    // 0x800C8A9C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
L_800C8AA0:
    // 0x800C8AA0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800C8AA4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C8AA8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800C8AAC: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x800C8AB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C8AB4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800C8AB8: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    // 0x800C8ABC: jal         0x800C8124
    // 0x800C8AC0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    func_800C8124(rdram, ctx);
        goto after_2;
    // 0x800C8AC0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    after_2:
L_800C8AC4:
    // 0x800C8AC4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800C8AC8: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x800C8ACC: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x800C8AD0: bne         $at, $zero, L_800C8978
    if (ctx->r1 != 0) {
        // 0x800C8AD4: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_800C8978;
    }
    // 0x800C8AD4: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x800C8AD8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800C8ADC: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x800C8AE0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800C8AE4: bne         $t8, $zero, L_800C8B74
    if (ctx->r24 != 0) {
        // 0x800C8AE8: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_800C8B74;
    }
    // 0x800C8AE8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800C8AEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8AF0: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_800C8AF4:
    // 0x800C8AF4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800C8AF8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C8AFC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8B00: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800C8B04: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x800C8B08: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C8B0C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x800C8B10: lw          $t9, -0x6BE8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6BE8);
    // 0x800C8B14: sltu        $at, $t9, $t2
    ctx->r1 = ctx->r25 < ctx->r10 ? 1 : 0;
    // 0x800C8B18: beq         $at, $zero, L_800C8B28
    if (ctx->r1 == 0) {
        // 0x800C8B1C: nop
    
            goto L_800C8B28;
    }
    // 0x800C8B1C: nop

    // 0x800C8B20: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800C8B24: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
L_800C8B28:
    // 0x800C8B28: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C8B2C: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800C8B30: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x800C8B34: bne         $at, $zero, L_800C8AF4
    if (ctx->r1 != 0) {
        // 0x800C8B38: sw          $t3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r11;
            goto L_800C8AF4;
    }
    // 0x800C8B38: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800C8B3C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800C8B40: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800C8B44: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x800C8B48: beq         $at, $zero, L_800C8B74
    if (ctx->r1 == 0) {
        // 0x800C8B4C: nop
    
            goto L_800C8B74;
    }
    // 0x800C8B4C: nop

    // 0x800C8B50: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800C8B54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C8B58: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800C8B5C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800C8B60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C8B64: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800C8B68: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    // 0x800C8B6C: jal         0x800C8124
    // 0x800C8B70: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    func_800C8124(rdram, ctx);
        goto after_3;
    // 0x800C8B70: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    after_3:
L_800C8B74:
    // 0x800C8B74: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800C8B78: bne         $t4, $zero, L_800C8B88
    if (ctx->r12 != 0) {
        // 0x800C8B7C: nop
    
            goto L_800C8B88;
    }
    // 0x800C8B7C: nop

    // 0x800C8B80: b           L_800C8DFC
    // 0x800C8B84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C8B84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8B88:
    // 0x800C8B88: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800C8B8C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C8B90: addiu       $t0, $t0, -0x69D0
    ctx->r8 = ADD32(ctx->r8, -0X69D0);
    // 0x800C8B94: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x800C8B98: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800C8B9C: lw          $t3, 0xC($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC);
    // 0x800C8BA0: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800C8BA4: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800C8BA8: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x800C8BAC: andi        $t1, $t6, 0xF
    ctx->r9 = ctx->r14 & 0XF;
    // 0x800C8BB0: sltu        $at, $t8, $t1
    ctx->r1 = ctx->r24 < ctx->r9 ? 1 : 0;
    // 0x800C8BB4: bne         $at, $zero, L_800C8BFC
    if (ctx->r1 != 0) {
        // 0x800C8BB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C8BFC;
    }
    // 0x800C8BB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C8BBC: bne         $t3, $at, L_800C8BCC
    if (ctx->r11 != ctx->r1) {
        // 0x800C8BC0: nop
    
            goto L_800C8BCC;
    }
    // 0x800C8BC0: nop

    // 0x800C8BC4: b           L_800C8DFC
    // 0x800C8BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C8BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8BCC:
    // 0x800C8BCC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800C8BD0: bne         $t7, $zero, L_800C8BFC
    if (ctx->r15 != 0) {
        // 0x800C8BD4: nop
    
            goto L_800C8BFC;
    }
    // 0x800C8BD4: nop

    // 0x800C8BD8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800C8BDC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800C8BE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C8BE4: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800C8BE8: sltu        $at, $t9, $t2
    ctx->r1 = ctx->r25 < ctx->r10 ? 1 : 0;
    // 0x800C8BEC: beq         $at, $zero, L_800C8BFC
    if (ctx->r1 == 0) {
        // 0x800C8BF0: nop
    
            goto L_800C8BFC;
    }
    // 0x800C8BF0: nop

    // 0x800C8BF4: b           L_800C8DFC
    // 0x800C8BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8DFC;
    // 0x800C8BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8BFC:
    // 0x800C8BFC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800C8C00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C8C04: bne         $t0, $at, L_800C8C10
    if (ctx->r8 != ctx->r1) {
        // 0x800C8C08: nop
    
            goto L_800C8C10;
    }
    // 0x800C8C08: nop

    // 0x800C8C0C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800C8C10:
    // 0x800C8C10: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C8C14: lw          $t5, -0x6AF4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6AF4);
    // 0x800C8C18: beq         $t5, $zero, L_800C8C64
    if (ctx->r13 == 0) {
        // 0x800C8C1C: nop
    
            goto L_800C8C64;
    }
    // 0x800C8C1C: nop

    // 0x800C8C20: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800C8C24: slti        $at, $t6, 0x2000
    ctx->r1 = SIGNED(ctx->r14) < 0X2000 ? 1 : 0;
    // 0x800C8C28: beq         $at, $zero, L_800C8C64
    if (ctx->r1 == 0) {
        // 0x800C8C2C: nop
    
            goto L_800C8C64;
    }
    // 0x800C8C2C: nop

    // 0x800C8C30: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800C8C34: slti        $at, $t1, 0x81
    ctx->r1 = SIGNED(ctx->r9) < 0X81 ? 1 : 0;
    // 0x800C8C38: bne         $at, $zero, L_800C8C48
    if (ctx->r1 != 0) {
        // 0x800C8C3C: nop
    
            goto L_800C8C48;
    }
    // 0x800C8C3C: nop

    // 0x800C8C40: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800C8C44: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800C8C48:
    // 0x800C8C48: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C8C4C: lw          $t7, -0x6AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AF8);
    // 0x800C8C50: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800C8C54: subu        $t4, $t3, $t7
    ctx->r12 = SUB32(ctx->r11, ctx->r15);
    // 0x800C8C58: bgez        $t4, L_800C8C64
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C8C5C: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_800C8C64;
    }
    // 0x800C8C5C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800C8C60: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_800C8C64:
    // 0x800C8C64: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800C8C68: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800C8C6C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C8C70: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x800C8C74: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8C78: lw          $a0, -0x69B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X69B4);
    // 0x800C8C7C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C8C80: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800C8C84: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C8C88: jal         0x800CD890
    // 0x800C8C8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800CD890(rdram, ctx);
        goto after_4;
    // 0x800C8C8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x800C8C90: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C8C94: lw          $t5, -0x6B38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6B38);
    // 0x800C8C98: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800C8C9C: bne         $t5, $zero, L_800C8CB0
    if (ctx->r13 != 0) {
        // 0x800C8CA0: nop
    
            goto L_800C8CB0;
    }
    // 0x800C8CA0: nop

    // 0x800C8CA4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8CA8: jal         0x800CF61C
    // 0x800C8CAC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800CF61C(rdram, ctx);
        goto after_5;
    // 0x800C8CAC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_5:
L_800C8CB0:
    // 0x800C8CB0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800C8CB4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800C8CB8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800C8CBC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800C8CC0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800C8CC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C8CC8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8CCC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C8CD0: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800C8CD4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800C8CD8: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x800C8CDC: sw          $t6, -0x6BF0($at)
    MEM_W(-0X6BF0, ctx->r1) = ctx->r14;
    // 0x800C8CE0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8CE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8CE8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800C8CEC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800C8CF0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C8CF4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800C8CF8: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800C8CFC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800C8D00: sw          $t3, -0x6BEC($at)
    MEM_W(-0X6BEC, ctx->r1) = ctx->r11;
    // 0x800C8D04: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800C8D08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8D0C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800C8D10: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C8D14: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800C8D18: sw          $t2, -0x6BE8($at)
    MEM_W(-0X6BE8, ctx->r1) = ctx->r10;
    // 0x800C8D1C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800C8D20: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C8D24: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C8D28: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x800C8D2C: sll         $t9, $t4, 5
    ctx->r25 = S32(ctx->r12 << 5);
    // 0x800C8D30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C8D34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8D38: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800C8D3C: lw          $t2, -0x69BC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X69BC);
    // 0x800C8D40: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C8D44: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800C8D48: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x800C8D4C: sw          $t5, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = ctx->r13;
    // 0x800C8D50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8D54: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C8D58: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C8D5C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800C8D60: andi        $t0, $t2, 0x40
    ctx->r8 = ctx->r10 & 0X40;
    // 0x800C8D64: beq         $t0, $zero, L_800C8D8C
    if (ctx->r8 == 0) {
        // 0x800C8D68: sw          $t8, -0x6BE4($at)
        MEM_W(-0X6BE4, ctx->r1) = ctx->r24;
            goto L_800C8D8C;
    }
    // 0x800C8D68: sw          $t8, -0x6BE4($at)
    MEM_W(-0X6BE4, ctx->r1) = ctx->r24;
    // 0x800C8D6C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800C8D70: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8D74: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800C8D78: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C8D7C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C8D80: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C8D84: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C8D88: sw          $t1, -0x6BE4($at)
    MEM_W(-0X6BE4, ctx->r1) = ctx->r9;
L_800C8D8C:
    // 0x800C8D8C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800C8D90: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C8D94: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800C8D98: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x800C8D9C: lw          $t3, -0x69BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X69BC);
    // 0x800C8DA0: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x800C8DA4: beq         $t4, $zero, L_800C8DDC
    if (ctx->r12 == 0) {
        // 0x800C8DA8: nop
    
            goto L_800C8DDC;
    }
    // 0x800C8DA8: nop

    // 0x800C8DAC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8DB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8DB4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800C8DB8: sw          $t9, -0x6B2C($at)
    MEM_W(-0X6B2C, ctx->r1) = ctx->r25;
    // 0x800C8DBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8DC0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800C8DC4: sw          $t2, -0x6B30($at)
    MEM_W(-0X6B30, ctx->r1) = ctx->r10;
    // 0x800C8DC8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800C8DCC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8DD0: sw          $t0, -0x6B28($at)
    MEM_W(-0X6B28, ctx->r1) = ctx->r8;
    // 0x800C8DD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8DD8: sw          $t5, -0x6B24($at)
    MEM_W(-0X6B24, ctx->r1) = ctx->r13;
L_800C8DDC:
    // 0x800C8DDC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800C8DE0: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800C8DE4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8DE8: sll         $t6, $t1, 5
    ctx->r14 = S32(ctx->r9 << 5);
    // 0x800C8DEC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800C8DF0: jal         0x800CF78C
    // 0x800C8DF4: lw          $a1, -0x69C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X69C0);
    func_800CF78C(rdram, ctx);
        goto after_6;
    // 0x800C8DF4: lw          $a1, -0x69C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X69C0);
    after_6:
    // 0x800C8DF8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_800C8DFC:
    // 0x800C8DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8E00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C8E04: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C8E08: jr          $ra
    // 0x800C8E0C: nop

    return;
    // 0x800C8E0C: nop

;}
RECOMP_FUNC void func_800C8E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8E14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C8E18: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C8E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8E20: bne         $t6, $zero, L_800C8E30
    if (ctx->r14 != 0) {
        // 0x800C8E24: nop
    
            goto L_800C8E30;
    }
    // 0x800C8E24: nop

    // 0x800C8E28: b           L_800C8E54
    // 0x800C8E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8E54;
    // 0x800C8E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8E30:
    // 0x800C8E30: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C8E34: addiu       $t8, $t7, -0x474
    ctx->r24 = ADD32(ctx->r15, -0X474);
    // 0x800C8E38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800C8E3C: jal         0x800C8544
    // 0x800C8E40: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x800C8E40: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800C8E44: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8E48: sw          $v0, -0x6B34($at)
    MEM_W(-0X6B34, ctx->r1) = ctx->r2;
    // 0x800C8E4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C8E50: lw          $v0, -0x6B34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B34);
L_800C8E54:
    // 0x800C8E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8E5C: jr          $ra
    // 0x800C8E60: nop

    return;
    // 0x800C8E60: nop

;}
RECOMP_FUNC void func_800C8E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8E68: sw          $zero, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = 0;
    // 0x800C8E6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8E70: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
    // 0x800C8E74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8E78: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
    // 0x800C8E7C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8E80: sw          $zero, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = 0;
    // 0x800C8E84: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8E88: jr          $ra
    // 0x800C8E8C: sw          $zero, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = 0;
    return;
    // 0x800C8E8C: sw          $zero, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800C8E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8E94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C8E98: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C8E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8EA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8EA4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C8EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C8EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800C8EB0: jal         0x800C8F78
    // 0x800C8EB4: sw          $t6, -0x6AF0($at)
    MEM_W(-0X6AF0, ctx->r1) = ctx->r14;
    func_800C8F78(rdram, ctx);
        goto after_0;
    // 0x800C8EB4: sw          $t6, -0x6AF0($at)
    MEM_W(-0X6AF0, ctx->r1) = ctx->r14;
    after_0:
    // 0x800C8EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8EC0: jr          $ra
    // 0x800C8EC4: nop

    return;
    // 0x800C8EC4: nop

;}
RECOMP_FUNC void func_800C8EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8EC8: divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // 0x800C8ECC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8ED0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8ED4: sw          $t6, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = ctx->r14;
    // 0x800C8ED8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8EDC: sw          $a1, -0x6B00($at)
    MEM_W(-0X6B00, ctx->r1) = ctx->r5;
    // 0x800C8EE0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8EE4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8EE8: sw          $t7, -0x6AFC($at)
    MEM_W(-0X6AFC, ctx->r1) = ctx->r15;
    // 0x800C8EEC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C8EF0: lw          $t8, -0x6AFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6AFC);
    // 0x800C8EF4: bne         $a0, $zero, L_800C8F00
    if (ctx->r4 != 0) {
        // 0x800C8EF8: nop
    
            goto L_800C8F00;
    }
    // 0x800C8EF8: nop

    // 0x800C8EFC: break       7
    do_break(2148306684);
L_800C8F00:
    // 0x800C8F00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F04: beq         $t8, $zero, L_800C8F18
    if (ctx->r24 == 0) {
        // 0x800C8F08: sw          $zero, -0x6AF8($at)
        MEM_W(-0X6AF8, ctx->r1) = 0;
            goto L_800C8F18;
    }
    // 0x800C8F08: sw          $zero, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = 0;
    // 0x800C8F0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C8F10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F14: sw          $t9, -0x6AFC($at)
    MEM_W(-0X6AFC, ctx->r1) = ctx->r25;
L_800C8F18:
    // 0x800C8F18: jr          $ra
    // 0x800C8F1C: nop

    return;
    // 0x800C8F1C: nop

;}
RECOMP_FUNC void func_800C8F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8F20: divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // 0x800C8F24: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C8F28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8F2C: sw          $t6, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = ctx->r14;
    // 0x800C8F30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F34: sw          $zero, -0x6B00($at)
    MEM_W(-0X6B00, ctx->r1) = 0;
    // 0x800C8F38: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F3C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8F40: sw          $t7, -0x6AFC($at)
    MEM_W(-0X6AFC, ctx->r1) = ctx->r15;
    // 0x800C8F44: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C8F48: lw          $t8, -0x6AFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6AFC);
    // 0x800C8F4C: bne         $a0, $zero, L_800C8F58
    if (ctx->r4 != 0) {
        // 0x800C8F50: nop
    
            goto L_800C8F58;
    }
    // 0x800C8F50: nop

    // 0x800C8F54: break       7
    do_break(2148306772);
L_800C8F58:
    // 0x800C8F58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F5C: bgtz        $t8, L_800C8F70
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C8F60: sw          $a1, -0x6AF8($at)
        MEM_W(-0X6AF8, ctx->r1) = ctx->r5;
            goto L_800C8F70;
    }
    // 0x800C8F60: sw          $a1, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = ctx->r5;
    // 0x800C8F64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C8F68: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8F6C: sw          $t9, -0x6AFC($at)
    MEM_W(-0X6AFC, ctx->r1) = ctx->r25;
L_800C8F70:
    // 0x800C8F70: jr          $ra
    // 0x800C8F74: nop

    return;
    // 0x800C8F74: nop

;}
RECOMP_FUNC void func_800C8F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8F78: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C8F7C: beq         $a3, $zero, L_800C8FA0
    if (ctx->r7 == 0) {
        // 0x800C8F80: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_800C8FA0;
    }
    // 0x800C8F80: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C8F84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C8F88: beq         $a3, $at, L_800C8FB0
    if (ctx->r7 == ctx->r1) {
        // 0x800C8F8C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C8FB0;
    }
    // 0x800C8F8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C8F90: beq         $a3, $at, L_800C8FC0
    if (ctx->r7 == ctx->r1) {
        // 0x800C8F94: nop
    
            goto L_800C8FC0;
    }
    // 0x800C8F94: nop

    // 0x800C8F98: b           L_800C9020
    // 0x800C8F9C: nop

        goto L_800C9020;
    // 0x800C8F9C: nop

L_800C8FA0:
    // 0x800C8FA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8FA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8FA8: b           L_800C9020
    // 0x800C8FAC: sw          $t6, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r14;
        goto L_800C9020;
    // 0x800C8FAC: sw          $t6, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r14;
L_800C8FB0:
    // 0x800C8FB0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800C8FB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8FB8: b           L_800C9020
    // 0x800C8FBC: sw          $t7, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r15;
        goto L_800C9020;
    // 0x800C8FBC: sw          $t7, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r15;
L_800C8FC0:
    // 0x800C8FC0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C8FC4: lw          $t9, -0x6B44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B44);
    // 0x800C8FC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C8FCC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8FD0: subu        $t0, $t9, $a1
    ctx->r8 = SUB32(ctx->r25, ctx->r5);
    // 0x800C8FD4: divu        $zero, $t0, $a0
    lo = S32(U32(ctx->r8) / U32(ctx->r4)); hi = S32(U32(ctx->r8) % U32(ctx->r4));
    // 0x800C8FD8: sw          $t8, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r24;
    // 0x800C8FDC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8FE0: sw          $a1, -0x6B10($at)
    MEM_W(-0X6B10, ctx->r1) = ctx->r5;
    // 0x800C8FE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8FE8: mflo        $t1
    ctx->r9 = lo;
    // 0x800C8FEC: sw          $t1, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r9;
    // 0x800C8FF0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8FF4: sw          $t9, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r25;
    // 0x800C8FF8: bne         $a0, $zero, L_800C9004
    if (ctx->r4 != 0) {
        // 0x800C8FFC: nop
    
            goto L_800C9004;
    }
    // 0x800C8FFC: nop

    // 0x800C9000: break       7
    do_break(2148306944);
L_800C9004:
    // 0x800C9004: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9008: bgtz        $t1, L_800C9070
    if (SIGNED(ctx->r9) > 0) {
        // 0x800C900C: sw          $t9, -0x6B04($at)
        MEM_W(-0X6B04, ctx->r1) = ctx->r25;
            goto L_800C9070;
    }
    // 0x800C900C: sw          $t9, -0x6B04($at)
    MEM_W(-0X6B04, ctx->r1) = ctx->r25;
    // 0x800C9010: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C9014: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9018: b           L_800C9070
    // 0x800C901C: sw          $t2, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r10;
        goto L_800C9070;
    // 0x800C901C: sw          $t2, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r10;
L_800C9020:
    // 0x800C9020: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C9024: lw          $t3, -0x6B48($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6B48);
    // 0x800C9028: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C902C: sw          $a1, -0x6B20($at)
    MEM_W(-0X6B20, ctx->r1) = ctx->r5;
    // 0x800C9030: subu        $t4, $t3, $a1
    ctx->r12 = SUB32(ctx->r11, ctx->r5);
    // 0x800C9034: divu        $zero, $t4, $a0
    lo = S32(U32(ctx->r12) / U32(ctx->r4)); hi = S32(U32(ctx->r12) % U32(ctx->r4));
    // 0x800C9038: mflo        $t5
    ctx->r13 = lo;
    // 0x800C903C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9040: sw          $t5, -0x6B1C($at)
    MEM_W(-0X6B1C, ctx->r1) = ctx->r13;
    // 0x800C9044: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9048: sw          $t3, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r11;
    // 0x800C904C: bne         $a0, $zero, L_800C9058
    if (ctx->r4 != 0) {
        // 0x800C9050: nop
    
            goto L_800C9058;
    }
    // 0x800C9050: nop

    // 0x800C9054: break       7
    do_break(2148307028);
L_800C9058:
    // 0x800C9058: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C905C: bgtz        $t5, L_800C9070
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C9060: sw          $t3, -0x6B14($at)
        MEM_W(-0X6B14, ctx->r1) = ctx->r11;
            goto L_800C9070;
    }
    // 0x800C9060: sw          $t3, -0x6B14($at)
    MEM_W(-0X6B14, ctx->r1) = ctx->r11;
    // 0x800C9064: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C9068: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C906C: sw          $t6, -0x6B1C($at)
    MEM_W(-0X6B1C, ctx->r1) = ctx->r14;
L_800C9070:
    // 0x800C9070: jr          $ra
    // 0x800C9074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C9074: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C9078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9078: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C907C: lw          $t7, -0x6B14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6B14);
    // 0x800C9080: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C9084: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9088: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x800C908C: divu        $zero, $t8, $a0
    lo = S32(U32(ctx->r24) / U32(ctx->r4)); hi = S32(U32(ctx->r24) % U32(ctx->r4));
    // 0x800C9090: sw          $t6, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r14;
    // 0x800C9094: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9098: sw          $t7, -0x6B20($at)
    MEM_W(-0X6B20, ctx->r1) = ctx->r15;
    // 0x800C909C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C90A0: mflo        $t9
    ctx->r25 = lo;
    // 0x800C90A4: sw          $t9, -0x6B1C($at)
    MEM_W(-0X6B1C, ctx->r1) = ctx->r25;
    // 0x800C90A8: bne         $a0, $zero, L_800C90B4
    if (ctx->r4 != 0) {
        // 0x800C90AC: nop
    
            goto L_800C90B4;
    }
    // 0x800C90AC: nop

    // 0x800C90B0: break       7
    do_break(2148307120);
L_800C90B4:
    // 0x800C90B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C90B8: bgtz        $t9, L_800C90CC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C90BC: sw          $a1, -0x6B18($at)
        MEM_W(-0X6B18, ctx->r1) = ctx->r5;
            goto L_800C90CC;
    }
    // 0x800C90BC: sw          $a1, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r5;
    // 0x800C90C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C90C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C90C8: sw          $t0, -0x6B1C($at)
    MEM_W(-0X6B1C, ctx->r1) = ctx->r8;
L_800C90CC:
    // 0x800C90CC: jr          $ra
    // 0x800C90D0: nop

    return;
    // 0x800C90D0: nop

;}
RECOMP_FUNC void func_800C90D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C90D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C90D8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C90DC: lw          $t7, -0x6B44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6B44);
    // 0x800C90E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C90E4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C90E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C90EC: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x800C90F0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C90F4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C90F8: sll         $t1, $t0, 7
    ctx->r9 = S32(ctx->r8 << 7);
    // 0x800C90FC: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x800C9100: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C9104: divu        $zero, $t3, $t4
    lo = S32(U32(ctx->r11) / U32(ctx->r12)); hi = S32(U32(ctx->r11) % U32(ctx->r12));
    // 0x800C9108: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800C910C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9110: sw          $t6, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r14;
    // 0x800C9114: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9118: sw          $t9, -0x6B10($at)
    MEM_W(-0X6B10, ctx->r1) = ctx->r25;
    // 0x800C911C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9120: mflo        $t5
    ctx->r13 = lo;
    // 0x800C9124: sw          $t5, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r13;
    // 0x800C9128: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C912C: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x800C9130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9134: bne         $t4, $zero, L_800C9140
    if (ctx->r12 != 0) {
        // 0x800C9138: nop
    
            goto L_800C9140;
    }
    // 0x800C9138: nop

    // 0x800C913C: break       7
    do_break(2148307260);
L_800C9140:
    // 0x800C9140: sw          $t6, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r14;
    // 0x800C9144: bgtz        $t5, L_800C9158
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C9148: nop
    
            goto L_800C9158;
    }
    // 0x800C9148: nop

    // 0x800C914C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C9150: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9154: sw          $t7, -0x6B0C($at)
    MEM_W(-0X6B0C, ctx->r1) = ctx->r15;
L_800C9158:
    // 0x800C9158: jal         0x800CB808
    // 0x800C915C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800CB808(rdram, ctx);
        goto after_0;
    // 0x800C915C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800C9160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9168: jr          $ra
    // 0x800C916C: nop

    return;
    // 0x800C916C: nop

;}
RECOMP_FUNC void func_800C9170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9170: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C9174: lw          $t6, -0x6AF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AF4);
    // 0x800C9178: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C917C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C9180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9184: bne         $t6, $at, L_800C91B0
    if (ctx->r14 != ctx->r1) {
        // 0x800C9188: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C91B0;
    }
    // 0x800C9188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C918C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C9190: lw          $t7, -0x794C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X794C);
    // 0x800C9194: bne         $t7, $zero, L_800C91B0
    if (ctx->r15 != 0) {
        // 0x800C9198: nop
    
            goto L_800C91B0;
    }
    // 0x800C9198: nop

    // 0x800C919C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C91A0: lw          $t8, -0x7944($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7944);
    // 0x800C91A4: bne         $t8, $zero, L_800C91B0
    if (ctx->r24 != 0) {
        // 0x800C91A8: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C91B0;
    }
    // 0x800C91A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C91AC: sw          $zero, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = 0;
L_800C91B0:
    // 0x800C91B0: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C91B4: lw          $t9, -0x794C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X794C);
    // 0x800C91B8: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x800C91BC: beq         $at, $zero, L_800C92EC
    if (ctx->r1 == 0) {
        // 0x800C91C0: nop
    
            goto L_800C92EC;
    }
    // 0x800C91C0: nop

    // 0x800C91C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C91C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C91CC: addu        $at, $at, $t9
    gpr jr_addend_800C91D4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C91D0: lw          $t9, -0x2B78($at)
    ctx->r25 = ADD32(ctx->r1, -0X2B78);
    // 0x800C91D4: jr          $t9
    // 0x800C91D8: nop

    switch (jr_addend_800C91D4 >> 2) {
        case 0: goto L_800C92EC; break;
        case 1: goto L_800C91DC; break;
        case 2: goto L_800C922C; break;
        case 3: goto L_800C92EC; break;
        case 4: goto L_800C92EC; break;
        case 5: goto L_800C92EC; break;
        case 6: goto L_800C92EC; break;
        case 7: goto L_800C92EC; break;
        case 8: goto L_800C92EC; break;
        case 9: goto L_800C92EC; break;
        case 10: goto L_800C927C; break;
        case 11: goto L_800C92D8; break;
        default: switch_error(__func__, 0x800C91D4, 0x800ED488);
    }
    // 0x800C91D8: nop

L_800C91DC:
    // 0x800C91DC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C91E0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C91E4: lw          $t1, -0x6B1C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6B1C);
    // 0x800C91E8: lw          $t0, -0x6B18($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6B18);
    // 0x800C91EC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C91F0: lw          $t3, -0x6B20($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6B20);
    // 0x800C91F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C91F8: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800C91FC: sw          $t2, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r10;
    // 0x800C9200: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C9204: bne         $at, $zero, L_800C9218
    if (ctx->r1 != 0) {
        // 0x800C9208: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C9218;
    }
    // 0x800C9208: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C920C: sw          $t3, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r11;
    // 0x800C9210: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9214: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
L_800C9218:
    // 0x800C9218: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C921C: jal         0x800CB7D4
    // 0x800C9220: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    func_800CB7D4(rdram, ctx);
        goto after_0;
    // 0x800C9220: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    after_0:
    // 0x800C9224: b           L_800C92EC
    // 0x800C9228: nop

        goto L_800C92EC;
    // 0x800C9228: nop

L_800C922C:
    // 0x800C922C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C9230: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C9234: lw          $t5, -0x6B1C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6B1C);
    // 0x800C9238: lw          $t4, -0x6B18($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6B18);
    // 0x800C923C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C9240: lw          $t7, -0x6B20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6B20);
    // 0x800C9244: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9248: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C924C: sw          $t6, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r14;
    // 0x800C9250: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C9254: bne         $at, $zero, L_800C9268
    if (ctx->r1 != 0) {
        // 0x800C9258: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C9268;
    }
    // 0x800C9258: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C925C: sw          $t7, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r15;
    // 0x800C9260: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9264: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
L_800C9268:
    // 0x800C9268: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C926C: jal         0x800CB7D4
    // 0x800C9270: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    func_800CB7D4(rdram, ctx);
        goto after_1;
    // 0x800C9270: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    after_1:
    // 0x800C9274: b           L_800C92EC
    // 0x800C9278: nop

        goto L_800C92EC;
    // 0x800C9278: nop

L_800C927C:
    // 0x800C927C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C9280: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C9284: lw          $t9, -0x6B1C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B1C);
    // 0x800C9288: lw          $t8, -0x6B18($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6B18);
    // 0x800C928C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C9290: lw          $t1, -0x6B20($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6B20);
    // 0x800C9294: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9298: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C929C: sw          $t0, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r8;
    // 0x800C92A0: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C92A4: bne         $at, $zero, L_800C92C4
    if (ctx->r1 != 0) {
        // 0x800C92A8: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C92C4;
    }
    // 0x800C92A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C92AC: sw          $t1, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = ctx->r9;
    // 0x800C92B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C92B4: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x800C92B8: sw          $t2, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = ctx->r10;
    // 0x800C92BC: jal         0x800C7FA4
    // 0x800C92C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C7FA4(rdram, ctx);
        goto after_2;
    // 0x800C92C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_800C92C4:
    // 0x800C92C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C92C8: jal         0x800CB7D4
    // 0x800C92CC: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    func_800CB7D4(rdram, ctx);
        goto after_3;
    // 0x800C92CC: lw          $a0, -0x6B18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B18);
    after_3:
    // 0x800C92D0: b           L_800C92EC
    // 0x800C92D4: nop

        goto L_800C92EC;
    // 0x800C92D4: nop

L_800C92D8:
    // 0x800C92D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C92DC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C92E0: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
    // 0x800C92E4: jal         0x800CB7D4
    // 0x800C92E8: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    func_800CB7D4(rdram, ctx);
        goto after_4;
    // 0x800C92E8: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    after_4:
L_800C92EC:
    // 0x800C92EC: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C92F0: lw          $t3, -0x7948($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7948);
    // 0x800C92F4: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x800C92F8: beq         $at, $zero, L_800C945C
    if (ctx->r1 == 0) {
        // 0x800C92FC: nop
    
            goto L_800C945C;
    }
    // 0x800C92FC: nop

    // 0x800C9300: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C9304: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9308: addu        $at, $at, $t3
    gpr jr_addend_800C9310 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C930C: lw          $t3, -0x2B48($at)
    ctx->r11 = ADD32(ctx->r1, -0X2B48);
    // 0x800C9310: jr          $t3
    // 0x800C9314: nop

    switch (jr_addend_800C9310 >> 2) {
        case 0: goto L_800C945C; break;
        case 1: goto L_800C9318; break;
        case 2: goto L_800C9380; break;
        case 3: goto L_800C9398; break;
        case 4: goto L_800C93B0; break;
        case 5: goto L_800C93C8; break;
        case 6: goto L_800C93E0; break;
        case 7: goto L_800C945C; break;
        case 8: goto L_800C945C; break;
        case 9: goto L_800C945C; break;
        case 10: goto L_800C93FC; break;
        default: switch_error(__func__, 0x800C9310, 0x800ED4B8);
    }
    // 0x800C9314: nop

L_800C9318:
    // 0x800C9318: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C931C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C9320: lw          $t5, -0x6B0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6B0C);
    // 0x800C9324: lw          $t4, -0x6B08($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6B08);
    // 0x800C9328: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C932C: lw          $t7, -0x6B10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6B10);
    // 0x800C9330: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9334: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C9338: sw          $t6, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r14;
    // 0x800C933C: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C9340: bne         $at, $zero, L_800C936C
    if (ctx->r1 != 0) {
        // 0x800C9344: nop
    
            goto L_800C936C;
    }
    // 0x800C9344: nop

    // 0x800C9348: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C934C: lw          $t8, -0x7948($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7948);
    // 0x800C9350: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9354: sw          $t7, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r15;
    // 0x800C9358: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C935C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C9360: sw          $t9, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r25;
    // 0x800C9364: jal         0x800C7FA4
    // 0x800C9368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C7FA4(rdram, ctx);
        goto after_5;
    // 0x800C9368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_800C936C:
    // 0x800C936C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C9370: jal         0x800CB808
    // 0x800C9374: lw          $a0, -0x6B08($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B08);
    func_800CB808(rdram, ctx);
        goto after_6;
    // 0x800C9374: lw          $a0, -0x6B08($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B08);
    after_6:
    // 0x800C9378: b           L_800C945C
    // 0x800C937C: nop

        goto L_800C945C;
    // 0x800C937C: nop

L_800C9380:
    // 0x800C9380: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9384: lw          $t0, -0x7948($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7948);
    // 0x800C9388: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C938C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C9390: b           L_800C945C
    // 0x800C9394: sw          $t1, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r9;
        goto L_800C945C;
    // 0x800C9394: sw          $t1, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r9;
L_800C9398:
    // 0x800C9398: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C939C: lw          $t2, -0x7948($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7948);
    // 0x800C93A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C93A4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C93A8: b           L_800C945C
    // 0x800C93AC: sw          $t3, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r11;
        goto L_800C945C;
    // 0x800C93AC: sw          $t3, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r11;
L_800C93B0:
    // 0x800C93B0: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C93B4: lw          $t4, -0x7948($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7948);
    // 0x800C93B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C93BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C93C0: b           L_800C945C
    // 0x800C93C4: sw          $t5, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r13;
        goto L_800C945C;
    // 0x800C93C4: sw          $t5, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r13;
L_800C93C8:
    // 0x800C93C8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C93CC: lw          $t6, -0x7948($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7948);
    // 0x800C93D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C93D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C93D8: b           L_800C945C
    // 0x800C93DC: sw          $t7, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r15;
        goto L_800C945C;
    // 0x800C93DC: sw          $t7, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->r15;
L_800C93E0:
    // 0x800C93E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C93E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C93E8: sw          $zero, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = 0;
    // 0x800C93EC: jal         0x800C7FA4
    // 0x800C93F0: lw          $a0, -0x6AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6AF0);
    func_800C7FA4(rdram, ctx);
        goto after_7;
    // 0x800C93F0: lw          $a0, -0x6AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6AF0);
    after_7:
    // 0x800C93F4: b           L_800C945C
    // 0x800C93F8: nop

        goto L_800C945C;
    // 0x800C93F8: nop

L_800C93FC:
    // 0x800C93FC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C9400: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C9404: lw          $t9, -0x6B0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B0C);
    // 0x800C9408: lw          $t8, -0x6B08($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6B08);
    // 0x800C940C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C9410: lw          $t1, -0x6B10($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6B10);
    // 0x800C9414: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9418: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C941C: sw          $t0, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r8;
    // 0x800C9420: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C9424: bne         $at, $zero, L_800C9438
    if (ctx->r1 != 0) {
        // 0x800C9428: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C9438;
    }
    // 0x800C9428: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C942C: sw          $t1, -0x6B08($at)
    MEM_W(-0X6B08, ctx->r1) = ctx->r9;
    // 0x800C9430: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9434: sw          $zero, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = 0;
L_800C9438:
    // 0x800C9438: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C943C: lw          $a0, -0x6B08($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B08);
    // 0x800C9440: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C9444: bgez        $a0, L_800C9454
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C9448: sra         $t2, $a0, 7
        ctx->r10 = S32(SIGNED(ctx->r4) >> 7);
            goto L_800C9454;
    }
    // 0x800C9448: sra         $t2, $a0, 7
    ctx->r10 = S32(SIGNED(ctx->r4) >> 7);
    // 0x800C944C: addiu       $at, $a0, 0x7F
    ctx->r1 = ADD32(ctx->r4, 0X7F);
    // 0x800C9450: sra         $t2, $at, 7
    ctx->r10 = S32(SIGNED(ctx->r1) >> 7);
L_800C9454:
    // 0x800C9454: jal         0x800CB808
    // 0x800C9458: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800CB808(rdram, ctx);
        goto after_8;
    // 0x800C9458: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_8:
L_800C945C:
    // 0x800C945C: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800C9460: lw          $s0, -0x7944($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7944);
    // 0x800C9464: beq         $s0, $zero, L_800C9500
    if (ctx->r16 == 0) {
        // 0x800C9468: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C9500;
    }
    // 0x800C9468: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C946C: beq         $s0, $at, L_800C9484
    if (ctx->r16 == ctx->r1) {
        // 0x800C9470: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C9484;
    }
    // 0x800C9470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C9474: beq         $s0, $at, L_800C94C4
    if (ctx->r16 == ctx->r1) {
        // 0x800C9478: nop
    
            goto L_800C94C4;
    }
    // 0x800C9478: nop

    // 0x800C947C: b           L_800C9500
    // 0x800C9480: nop

        goto L_800C9500;
    // 0x800C9480: nop

L_800C9484:
    // 0x800C9484: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C9488: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C948C: lw          $t4, -0x6AFC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6AFC);
    // 0x800C9490: lw          $t3, -0x6AF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6AF8);
    // 0x800C9494: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C9498: lw          $t6, -0x6B00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6B00);
    // 0x800C949C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C94A0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800C94A4: sw          $t5, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = ctx->r13;
    // 0x800C94A8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C94AC: bne         $at, $zero, L_800C9500
    if (ctx->r1 != 0) {
        // 0x800C94B0: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C9500;
    }
    // 0x800C94B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C94B4: sw          $t6, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = ctx->r14;
    // 0x800C94B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C94BC: b           L_800C9500
    // 0x800C94C0: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
        goto L_800C9500;
    // 0x800C94C0: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
L_800C94C4:
    // 0x800C94C4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C94C8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C94CC: lw          $t8, -0x6AFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6AFC);
    // 0x800C94D0: lw          $t7, -0x6AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AF8);
    // 0x800C94D4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C94D8: lw          $t0, -0x6B00($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6B00);
    // 0x800C94DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C94E0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800C94E4: sw          $t9, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = ctx->r25;
    // 0x800C94E8: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C94EC: bne         $at, $zero, L_800C9500
    if (ctx->r1 != 0) {
        // 0x800C94F0: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C9500;
    }
    // 0x800C94F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C94F4: sw          $t0, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = ctx->r8;
    // 0x800C94F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C94FC: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
L_800C9500:
    // 0x800C9500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9508: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C950C: jr          $ra
    // 0x800C9510: nop

    return;
    // 0x800C9510: nop

;}
RECOMP_FUNC void func_800C9514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C951C: jal         0x800C7FA4
    // 0x800C9520: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800C7FA4(rdram, ctx);
        goto after_0;
    // 0x800C9520: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x800C9524: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x800C9528: jal         0x800C90D4
    // 0x800C952C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C90D4(rdram, ctx);
        goto after_1;
    // 0x800C952C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800C9530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9538: jr          $ra
    // 0x800C953C: nop

    return;
    // 0x800C953C: nop

;}
RECOMP_FUNC void func_800C9540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9548: jal         0x800C8E90
    // 0x800C954C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800C8E90(rdram, ctx);
        goto after_0;
    // 0x800C954C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x800C9550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9558: jr          $ra
    // 0x800C955C: nop

    return;
    // 0x800C955C: nop

;}
RECOMP_FUNC void func_800C9560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9568: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C956C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800C9570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9574: bne         $t6, $at, L_800C963C
    if (ctx->r14 != ctx->r1) {
        // 0x800C9578: nop
    
            goto L_800C963C;
    }
    // 0x800C9578: nop

    // 0x800C957C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C9580: addiu       $t7, $t7, -0x6BF0
    ctx->r15 = ADD32(ctx->r15, -0X6BF0);
    // 0x800C9584: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C9588: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C958C: bne         $t8, $at, L_800C959C
    if (ctx->r24 != ctx->r1) {
        // 0x800C9590: nop
    
            goto L_800C959C;
    }
    // 0x800C9590: nop

    // 0x800C9594: jal         0x800C8124
    // 0x800C9598: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800C8124(rdram, ctx);
        goto after_0;
    // 0x800C9598: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_0:
L_800C959C:
    // 0x800C959C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C95A0: addiu       $t9, $t9, -0x6BF0
    ctx->r25 = ADD32(ctx->r25, -0X6BF0);
    // 0x800C95A4: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x800C95A8: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C95AC: bne         $t0, $at, L_800C95BC
    if (ctx->r8 != ctx->r1) {
        // 0x800C95B0: nop
    
            goto L_800C95BC;
    }
    // 0x800C95B0: nop

    // 0x800C95B4: jal         0x800C8124
    // 0x800C95B8: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    func_800C8124(rdram, ctx);
        goto after_1;
    // 0x800C95B8: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    after_1:
L_800C95BC:
    // 0x800C95BC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C95C0: addiu       $t1, $t1, -0x6BF0
    ctx->r9 = ADD32(ctx->r9, -0X6BF0);
    // 0x800C95C4: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x800C95C8: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C95CC: bne         $t2, $at, L_800C95DC
    if (ctx->r10 != ctx->r1) {
        // 0x800C95D0: nop
    
            goto L_800C95DC;
    }
    // 0x800C95D0: nop

    // 0x800C95D4: jal         0x800C8124
    // 0x800C95D8: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    func_800C8124(rdram, ctx);
        goto after_2;
    // 0x800C95D8: lw          $a0, 0x2C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X2C);
    after_2:
L_800C95DC:
    // 0x800C95DC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C95E0: addiu       $t3, $t3, -0x6BF0
    ctx->r11 = ADD32(ctx->r11, -0X6BF0);
    // 0x800C95E4: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x800C95E8: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C95EC: bne         $t4, $at, L_800C95FC
    if (ctx->r12 != ctx->r1) {
        // 0x800C95F0: nop
    
            goto L_800C95FC;
    }
    // 0x800C95F0: nop

    // 0x800C95F4: jal         0x800C8124
    // 0x800C95F8: lw          $a0, 0x40($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X40);
    func_800C8124(rdram, ctx);
        goto after_3;
    // 0x800C95F8: lw          $a0, 0x40($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X40);
    after_3:
L_800C95FC:
    // 0x800C95FC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C9600: addiu       $t5, $t5, -0x6BF0
    ctx->r13 = ADD32(ctx->r13, -0X6BF0);
    // 0x800C9604: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x800C9608: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C960C: bne         $t6, $at, L_800C961C
    if (ctx->r14 != ctx->r1) {
        // 0x800C9610: nop
    
            goto L_800C961C;
    }
    // 0x800C9610: nop

    // 0x800C9614: jal         0x800C8124
    // 0x800C9618: lw          $a0, 0x54($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X54);
    func_800C8124(rdram, ctx);
        goto after_4;
    // 0x800C9618: lw          $a0, 0x54($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X54);
    after_4:
L_800C961C:
    // 0x800C961C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C9620: addiu       $t8, $t8, -0x6BF0
    ctx->r24 = ADD32(ctx->r24, -0X6BF0);
    // 0x800C9624: lw          $t7, 0x64($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X64);
    // 0x800C9628: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800C962C: bne         $t7, $at, L_800C963C
    if (ctx->r15 != ctx->r1) {
        // 0x800C9630: nop
    
            goto L_800C963C;
    }
    // 0x800C9630: nop

    // 0x800C9634: jal         0x800C8124
    // 0x800C9638: lw          $a0, 0x68($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X68);
    func_800C8124(rdram, ctx);
        goto after_5;
    // 0x800C9638: lw          $a0, 0x68($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X68);
    after_5:
L_800C963C:
    // 0x800C963C: jal         0x800C8E90
    // 0x800C9640: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C8E90(rdram, ctx);
        goto after_6;
    // 0x800C9640: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x800C9644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C964C: jr          $ra
    // 0x800C9650: nop

    return;
    // 0x800C9650: nop

;}
RECOMP_FUNC void func_800C9654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9654: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C965C: jal         0x800C9848
    // 0x800C9660: nop

    func_800C9848(rdram, ctx);
        goto after_0;
    // 0x800C9660: nop

    after_0:
    // 0x800C9664: jal         0x800C8544
    // 0x800C9668: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x800C9668: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_1:
    // 0x800C966C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9674: jr          $ra
    // 0x800C9678: nop

    return;
    // 0x800C9678: nop

;}
RECOMP_FUNC void func_800C967C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C967C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9680: lw          $t6, -0x5324($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5324);
    // 0x800C9684: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C968C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C9690: sw          $t7, -0x5324($at)
    MEM_W(-0X5324, ctx->r1) = ctx->r15;
    // 0x800C9694: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C9698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C969C: beq         $t8, $zero, L_800C96D8
    if (ctx->r24 == 0) {
        // 0x800C96A0: sw          $t8, -0x5324($at)
        MEM_W(-0X5324, ctx->r1) = ctx->r24;
            goto L_800C96D8;
    }
    // 0x800C96A0: sw          $t8, -0x5324($at)
    MEM_W(-0X5324, ctx->r1) = ctx->r24;
    // 0x800C96A4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800C96A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C96AC: sw          $t9, -0x5330($at)
    MEM_W(-0X5330, ctx->r1) = ctx->r25;
    // 0x800C96B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C96B4: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x800C96B8: sw          $t0, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = ctx->r8;
    // 0x800C96BC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800C96C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800C96C4: jal         0x800C85B0
    // 0x800C96C8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_800C85B0(rdram, ctx);
        goto after_0;
    // 0x800C96C8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_0:
    // 0x800C96CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C96D0: b           L_800C9708
    // 0x800C96D4: sw          $v0, -0x5328($at)
    MEM_W(-0X5328, ctx->r1) = ctx->r2;
        goto L_800C9708;
    // 0x800C96D4: sw          $v0, -0x5328($at)
    MEM_W(-0X5328, ctx->r1) = ctx->r2;
L_800C96D8:
    // 0x800C96D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C96DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C96E0: sw          $t1, -0x5330($at)
    MEM_W(-0X5330, ctx->r1) = ctx->r9;
    // 0x800C96E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C96E8: addiu       $t2, $zero, 0x21C
    ctx->r10 = ADD32(0, 0X21C);
    // 0x800C96EC: sw          $t2, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = ctx->r10;
    // 0x800C96F0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800C96F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800C96F8: jal         0x800C85B0
    // 0x800C96FC: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    func_800C85B0(rdram, ctx);
        goto after_1;
    // 0x800C96FC: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    after_1:
    // 0x800C9700: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9704: sw          $v0, -0x5328($at)
    MEM_W(-0X5328, ctx->r1) = ctx->r2;
L_800C9708:
    // 0x800C9708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C970C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C9710: lw          $v0, -0x5328($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5328);
    // 0x800C9714: jr          $ra
    // 0x800C9718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C9718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C971C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C971C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9720: lw          $t6, -0x7940($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7940);
    // 0x800C9724: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C972C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800C9730: bne         $t7, $zero, L_800C9834
    if (ctx->r15 != 0) {
        // 0x800C9734: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C9834;
    }
    // 0x800C9734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9738: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800C973C: lw          $s0, -0x5330($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5330);
    // 0x800C9740: beq         $s0, $zero, L_800C9834
    if (ctx->r16 == 0) {
        // 0x800C9744: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C9834;
    }
    // 0x800C9744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C9748: beq         $s0, $at, L_800C9760
    if (ctx->r16 == ctx->r1) {
        // 0x800C974C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C9760;
    }
    // 0x800C974C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C9750: beq         $s0, $at, L_800C97D0
    if (ctx->r16 == ctx->r1) {
        // 0x800C9754: nop
    
            goto L_800C97D0;
    }
    // 0x800C9754: nop

    // 0x800C9758: b           L_800C9834
    // 0x800C975C: nop

        goto L_800C9834;
    // 0x800C975C: nop

L_800C9760:
    // 0x800C9760: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C9764: lw          $t8, -0x532C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X532C);
    // 0x800C9768: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C976C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C9770: sw          $t9, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = ctx->r25;
    // 0x800C9774: slti        $at, $t9, 0x2D0
    ctx->r1 = SIGNED(ctx->r25) < 0X2D0 ? 1 : 0;
    // 0x800C9778: bne         $at, $zero, L_800C978C
    if (ctx->r1 != 0) {
        // 0x800C977C: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800C978C;
    }
    // 0x800C977C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9780: sw          $zero, -0x5330($at)
    MEM_W(-0X5330, ctx->r1) = 0;
    // 0x800C9784: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9788: sw          $zero, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = 0;
L_800C978C:
    // 0x800C978C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9790: lw          $t0, -0x532C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X532C);
    // 0x800C9794: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C9798: lw          $a0, -0x5328($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5328);
    // 0x800C979C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800C97A0: bgez        $t0, L_800C97B0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C97A4: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800C97B0;
    }
    // 0x800C97A4: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800C97A8: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800C97AC: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800C97B0:
    // 0x800C97B0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C97B4: nop

    // 0x800C97B8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C97BC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C97C0: jal         0x800C81F8
    // 0x800C97C4: nop

    func_800C81F8(rdram, ctx);
        goto after_0;
    // 0x800C97C4: nop

    after_0:
    // 0x800C97C8: b           L_800C9834
    // 0x800C97CC: nop

        goto L_800C9834;
    // 0x800C97CC: nop

L_800C97D0:
    // 0x800C97D0: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C97D4: lw          $t2, -0x532C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X532C);
    // 0x800C97D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C97DC: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x800C97E0: bgtz        $t3, L_800C97F8
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C97E4: sw          $t3, -0x532C($at)
        MEM_W(-0X532C, ctx->r1) = ctx->r11;
            goto L_800C97F8;
    }
    // 0x800C97E4: sw          $t3, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = ctx->r11;
    // 0x800C97E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C97EC: sw          $zero, -0x5330($at)
    MEM_W(-0X5330, ctx->r1) = 0;
    // 0x800C97F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C97F4: sw          $zero, -0x532C($at)
    MEM_W(-0X532C, ctx->r1) = 0;
L_800C97F8:
    // 0x800C97F8: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C97FC: lw          $t4, -0x532C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X532C);
    // 0x800C9800: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C9804: lw          $a0, -0x5328($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5328);
    // 0x800C9808: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800C980C: bgez        $t4, L_800C981C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C9810: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800C981C;
    }
    // 0x800C9810: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800C9814: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800C9818: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800C981C:
    // 0x800C981C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800C9820: nop

    // 0x800C9824: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C9828: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800C982C: jal         0x800C81F8
    // 0x800C9830: nop

    func_800C81F8(rdram, ctx);
        goto after_1;
    // 0x800C9830: nop

    after_1:
L_800C9834:
    // 0x800C9834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C983C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9840: jr          $ra
    // 0x800C9844: nop

    return;
    // 0x800C9844: nop

;}
