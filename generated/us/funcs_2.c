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

RECOMP_FUNC void func_800C9848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C984C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9850: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9854: sw          $zero, -0x6AF0($at)
    MEM_W(-0X6AF0, ctx->r1) = 0;
    // 0x800C9858: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C985C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9860: jal         0x800C8F78
    // 0x800C9864: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800C8F78(rdram, ctx);
        goto after_0;
    // 0x800C9864: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800C9868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C986C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9870: jr          $ra
    // 0x800C9874: nop

    return;
    // 0x800C9874: nop

;}
RECOMP_FUNC void func_800C9878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9878: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C987C: lw          $t6, -0x6AF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AF4);
    // 0x800C9880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9888: bne         $t6, $zero, L_800C98C4
    if (ctx->r14 != 0) {
        // 0x800C988C: nop
    
            goto L_800C98C4;
    }
    // 0x800C988C: nop

    // 0x800C9890: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800C9894: lw          $a1, -0x6B48($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6B48);
    // 0x800C9898: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800C989C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C98A0: bgez        $a1, L_800C98B0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C98A4: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800C98B0;
    }
    // 0x800C98A4: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C98A8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800C98AC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800C98B0:
    // 0x800C98B0: jal         0x800C8F78
    // 0x800C98B4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800C8F78(rdram, ctx);
        goto after_0;
    // 0x800C98B4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x800C98B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C98BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C98C0: sw          $t8, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = ctx->r24;
L_800C98C4:
    // 0x800C98C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C98C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C98CC: jr          $ra
    // 0x800C98D0: nop

    return;
    // 0x800C98D0: nop

;}
RECOMP_FUNC void func_800C98D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C98D4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C98D8: lw          $t6, -0x6AF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AF4);
    // 0x800C98DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C98E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C98E4: bne         $t6, $at, L_800C991C
    if (ctx->r14 != ctx->r1) {
        // 0x800C98E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C991C;
    }
    // 0x800C98E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C98EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800C98F0: lw          $a1, -0x6B48($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6B48);
    // 0x800C98F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x800C98F8: bgez        $a1, L_800C9908
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C98FC: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800C9908;
    }
    // 0x800C98FC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C9900: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800C9904: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800C9908:
    // 0x800C9908: jal         0x800C9078
    // 0x800C990C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800C9078(rdram, ctx);
        goto after_0;
    // 0x800C990C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x800C9910: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C9914: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C9918: sw          $t8, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = ctx->r24;
L_800C991C:
    // 0x800C991C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9924: jr          $ra
    // 0x800C9928: nop

    return;
    // 0x800C9928: nop

;}
RECOMP_FUNC void func_800C992C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C992C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9930: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C9934: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9938: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C993C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9940: sltiu       $at, $s0, 0x1A5
    ctx->r1 = ctx->r16 < 0X1A5 ? 1 : 0;
    // 0x800C9944: bne         $at, $zero, L_800C9974
    if (ctx->r1 != 0) {
        // 0x800C9948: nop
    
            goto L_800C9974;
    }
    // 0x800C9948: nop

    // 0x800C994C: addiu       $t6, $s0, -0x1C2
    ctx->r14 = ADD32(ctx->r16, -0X1C2);
    // 0x800C9950: sltiu       $at, $t6, 0xDD
    ctx->r1 = ctx->r14 < 0XDD ? 1 : 0;
    // 0x800C9954: beq         $at, $zero, L_800CAC80
    if (ctx->r1 == 0) {
        // 0x800C9958: nop
    
            goto L_800CAC80;
    }
    // 0x800C9958: nop

    // 0x800C995C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C9960: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9964: addu        $at, $at, $t6
    gpr jr_addend_800C996C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C9968: lw          $t6, -0x2B1C($at)
    ctx->r14 = ADD32(ctx->r1, -0X2B1C);
    // 0x800C996C: jr          $t6
    // 0x800C9970: nop

    switch (jr_addend_800C996C >> 2) {
        case 0: goto L_800CA610; break;
        case 1: goto L_800CAC80; break;
        case 2: goto L_800CAC80; break;
        case 3: goto L_800CAC80; break;
        case 4: goto L_800CAC80; break;
        case 5: goto L_800CA654; break;
        case 6: goto L_800CAC80; break;
        case 7: goto L_800CAC80; break;
        case 8: goto L_800CAC80; break;
        case 9: goto L_800CAC80; break;
        case 10: goto L_800CA678; break;
        case 11: goto L_800CAC80; break;
        case 12: goto L_800CAC80; break;
        case 13: goto L_800CAC80; break;
        case 14: goto L_800CAC80; break;
        case 15: goto L_800CA6B0; break;
        case 16: goto L_800CAC80; break;
        case 17: goto L_800CAC80; break;
        case 18: goto L_800CAC80; break;
        case 19: goto L_800CAC80; break;
        case 20: goto L_800CA6D8; break;
        case 21: goto L_800CAC80; break;
        case 22: goto L_800CAC80; break;
        case 23: goto L_800CAC80; break;
        case 24: goto L_800CAC80; break;
        case 25: goto L_800CA710; break;
        case 26: goto L_800CAC80; break;
        case 27: goto L_800CAC80; break;
        case 28: goto L_800CAC80; break;
        case 29: goto L_800CAC80; break;
        case 30: goto L_800CA734; break;
        case 31: goto L_800CAC80; break;
        case 32: goto L_800CAC80; break;
        case 33: goto L_800CAC80; break;
        case 34: goto L_800CAC80; break;
        case 35: goto L_800CA76C; break;
        case 36: goto L_800CAC80; break;
        case 37: goto L_800CAC80; break;
        case 38: goto L_800CAC80; break;
        case 39: goto L_800CAC80; break;
        case 40: goto L_800CA7A4; break;
        case 41: goto L_800CAC80; break;
        case 42: goto L_800CAC80; break;
        case 43: goto L_800CAC80; break;
        case 44: goto L_800CAC80; break;
        case 45: goto L_800CA7CC; break;
        case 46: goto L_800CAC80; break;
        case 47: goto L_800CAC80; break;
        case 48: goto L_800CAC80; break;
        case 49: goto L_800CAC80; break;
        case 50: goto L_800CAC80; break;
        case 51: goto L_800CAC80; break;
        case 52: goto L_800CAC80; break;
        case 53: goto L_800CAC80; break;
        case 54: goto L_800CAC80; break;
        case 55: goto L_800CAC80; break;
        case 56: goto L_800CAC80; break;
        case 57: goto L_800CAC80; break;
        case 58: goto L_800CAC80; break;
        case 59: goto L_800CAC80; break;
        case 60: goto L_800CAC80; break;
        case 61: goto L_800CAC80; break;
        case 62: goto L_800CAC80; break;
        case 63: goto L_800CAC80; break;
        case 64: goto L_800CAC80; break;
        case 65: goto L_800CAC80; break;
        case 66: goto L_800CAC80; break;
        case 67: goto L_800CAC80; break;
        case 68: goto L_800CAC80; break;
        case 69: goto L_800CAC80; break;
        case 70: goto L_800CA7F8; break;
        case 71: goto L_800CAC80; break;
        case 72: goto L_800CAC80; break;
        case 73: goto L_800CAC80; break;
        case 74: goto L_800CAC80; break;
        case 75: goto L_800CA83C; break;
        case 76: goto L_800CAC80; break;
        case 77: goto L_800CAC80; break;
        case 78: goto L_800CAC80; break;
        case 79: goto L_800CAC80; break;
        case 80: goto L_800CA864; break;
        case 81: goto L_800CAC80; break;
        case 82: goto L_800CAC80; break;
        case 83: goto L_800CAC80; break;
        case 84: goto L_800CAC80; break;
        case 85: goto L_800CA894; break;
        case 86: goto L_800CAC80; break;
        case 87: goto L_800CAC80; break;
        case 88: goto L_800CAC80; break;
        case 89: goto L_800CAC80; break;
        case 90: goto L_800CA8BC; break;
        case 91: goto L_800CAC80; break;
        case 92: goto L_800CAC80; break;
        case 93: goto L_800CAC80; break;
        case 94: goto L_800CAC80; break;
        case 95: goto L_800CA8E4; break;
        case 96: goto L_800CAC80; break;
        case 97: goto L_800CAC80; break;
        case 98: goto L_800CAC80; break;
        case 99: goto L_800CAC80; break;
        case 100: goto L_800CA91C; break;
        case 101: goto L_800CAC80; break;
        case 102: goto L_800CAC80; break;
        case 103: goto L_800CAC80; break;
        case 104: goto L_800CAC80; break;
        case 105: goto L_800CAC80; break;
        case 106: goto L_800CAC80; break;
        case 107: goto L_800CAC80; break;
        case 108: goto L_800CAC80; break;
        case 109: goto L_800CAC80; break;
        case 110: goto L_800CA948; break;
        case 111: goto L_800CAC80; break;
        case 112: goto L_800CAC80; break;
        case 113: goto L_800CAC80; break;
        case 114: goto L_800CAC80; break;
        case 115: goto L_800CA98C; break;
        case 116: goto L_800CAC80; break;
        case 117: goto L_800CAC80; break;
        case 118: goto L_800CAC80; break;
        case 119: goto L_800CAC80; break;
        case 120: goto L_800CA9C4; break;
        case 121: goto L_800CAC80; break;
        case 122: goto L_800CAC80; break;
        case 123: goto L_800CAC80; break;
        case 124: goto L_800CAC80; break;
        case 125: goto L_800CA9D8; break;
        case 126: goto L_800CAC80; break;
        case 127: goto L_800CAC80; break;
        case 128: goto L_800CAC80; break;
        case 129: goto L_800CAC80; break;
        case 130: goto L_800CA9F0; break;
        case 131: goto L_800CAC80; break;
        case 132: goto L_800CAC80; break;
        case 133: goto L_800CAC80; break;
        case 134: goto L_800CAC80; break;
        case 135: goto L_800CAC80; break;
        case 136: goto L_800CAC80; break;
        case 137: goto L_800CAC80; break;
        case 138: goto L_800CAC80; break;
        case 139: goto L_800CAC80; break;
        case 140: goto L_800CAA1C; break;
        case 141: goto L_800CAC80; break;
        case 142: goto L_800CAC80; break;
        case 143: goto L_800CAC80; break;
        case 144: goto L_800CAC80; break;
        case 145: goto L_800CAA60; break;
        case 146: goto L_800CAC80; break;
        case 147: goto L_800CAC80; break;
        case 148: goto L_800CAC80; break;
        case 149: goto L_800CAC80; break;
        case 150: goto L_800CAA74; break;
        case 151: goto L_800CAC80; break;
        case 152: goto L_800CAC80; break;
        case 153: goto L_800CAC80; break;
        case 154: goto L_800CAC80; break;
        case 155: goto L_800CAA9C; break;
        case 156: goto L_800CAC80; break;
        case 157: goto L_800CAC80; break;
        case 158: goto L_800CAC80; break;
        case 159: goto L_800CAC80; break;
        case 160: goto L_800CAAD0; break;
        case 161: goto L_800CAC80; break;
        case 162: goto L_800CAC80; break;
        case 163: goto L_800CAC80; break;
        case 164: goto L_800CAC80; break;
        case 165: goto L_800CAAF8; break;
        case 166: goto L_800CAC80; break;
        case 167: goto L_800CAC80; break;
        case 168: goto L_800CAC80; break;
        case 169: goto L_800CAC80; break;
        case 170: goto L_800CAB20; break;
        case 171: goto L_800CAC80; break;
        case 172: goto L_800CAC80; break;
        case 173: goto L_800CAC80; break;
        case 174: goto L_800CAC80; break;
        case 175: goto L_800CAB48; break;
        case 176: goto L_800CAC80; break;
        case 177: goto L_800CAC80; break;
        case 178: goto L_800CAC80; break;
        case 179: goto L_800CAC80; break;
        case 180: goto L_800CAC80; break;
        case 181: goto L_800CAC80; break;
        case 182: goto L_800CAC80; break;
        case 183: goto L_800CAC80; break;
        case 184: goto L_800CAC80; break;
        case 185: goto L_800CAC80; break;
        case 186: goto L_800CAC80; break;
        case 187: goto L_800CAC80; break;
        case 188: goto L_800CAC80; break;
        case 189: goto L_800CAC80; break;
        case 190: goto L_800CAB74; break;
        case 191: goto L_800CAC80; break;
        case 192: goto L_800CAC80; break;
        case 193: goto L_800CAC80; break;
        case 194: goto L_800CAC80; break;
        case 195: goto L_800CABB4; break;
        case 196: goto L_800CAC80; break;
        case 197: goto L_800CAC80; break;
        case 198: goto L_800CAC80; break;
        case 199: goto L_800CAC80; break;
        case 200: goto L_800CAC80; break;
        case 201: goto L_800CAC80; break;
        case 202: goto L_800CAC80; break;
        case 203: goto L_800CAC80; break;
        case 204: goto L_800CAC80; break;
        case 205: goto L_800CAC80; break;
        case 206: goto L_800CAC80; break;
        case 207: goto L_800CAC80; break;
        case 208: goto L_800CAC80; break;
        case 209: goto L_800CAC80; break;
        case 210: goto L_800CABE0; break;
        case 211: goto L_800CAC80; break;
        case 212: goto L_800CAC80; break;
        case 213: goto L_800CAC80; break;
        case 214: goto L_800CAC80; break;
        case 215: goto L_800CAC24; break;
        case 216: goto L_800CAC80; break;
        case 217: goto L_800CAC80; break;
        case 218: goto L_800CAC80; break;
        case 219: goto L_800CAC80; break;
        case 220: goto L_800CAC5C; break;
        default: switch_error(__func__, 0x800C996C, 0x800ED4E4);
    }
    // 0x800C9970: nop

L_800C9974:
    // 0x800C9974: sltiu       $at, $s0, 0x15F
    ctx->r1 = ctx->r16 < 0X15F ? 1 : 0;
    // 0x800C9978: bne         $at, $zero, L_800C99A8
    if (ctx->r1 != 0) {
        // 0x800C997C: nop
    
            goto L_800C99A8;
    }
    // 0x800C997C: nop

    // 0x800C9980: addiu       $t7, $s0, -0x190
    ctx->r15 = ADD32(ctx->r16, -0X190);
    // 0x800C9984: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x800C9988: beq         $at, $zero, L_800CAC80
    if (ctx->r1 == 0) {
        // 0x800C998C: nop
    
            goto L_800CAC80;
    }
    // 0x800C998C: nop

    // 0x800C9990: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C9994: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C9998: addu        $at, $at, $t7
    gpr jr_addend_800C99A0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C999C: lw          $t7, -0x27A8($at)
    ctx->r15 = ADD32(ctx->r1, -0X27A8);
    // 0x800C99A0: jr          $t7
    // 0x800C99A4: nop

    switch (jr_addend_800C99A0 >> 2) {
        case 0: goto L_800CA530; break;
        case 1: goto L_800CAC80; break;
        case 2: goto L_800CAC80; break;
        case 3: goto L_800CAC80; break;
        case 4: goto L_800CAC80; break;
        case 5: goto L_800CA564; break;
        case 6: goto L_800CAC80; break;
        case 7: goto L_800CAC80; break;
        case 8: goto L_800CAC80; break;
        case 9: goto L_800CAC80; break;
        case 10: goto L_800CA598; break;
        case 11: goto L_800CAC80; break;
        case 12: goto L_800CAC80; break;
        case 13: goto L_800CAC80; break;
        case 14: goto L_800CAC80; break;
        case 15: goto L_800CA5BC; break;
        case 16: goto L_800CAC80; break;
        case 17: goto L_800CAC80; break;
        case 18: goto L_800CAC80; break;
        case 19: goto L_800CAC80; break;
        case 20: goto L_800CA5E4; break;
        default: switch_error(__func__, 0x800C99A0, 0x800ED858);
    }
    // 0x800C99A4: nop

L_800C99A8:
    // 0x800C99A8: sltiu       $at, $s0, 0x15F
    ctx->r1 = ctx->r16 < 0X15F ? 1 : 0;
    // 0x800C99AC: beq         $at, $zero, L_800CAC80
    if (ctx->r1 == 0) {
        // 0x800C99B0: nop
    
            goto L_800CAC80;
    }
    // 0x800C99B0: nop

    // 0x800C99B4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800C99B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C99BC: addu        $at, $at, $t8
    gpr jr_addend_800C99C4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C99C0: lw          $t8, -0x2754($at)
    ctx->r24 = ADD32(ctx->r1, -0X2754);
    // 0x800C99C4: jr          $t8
    // 0x800C99C8: nop

    switch (jr_addend_800C99C4 >> 2) {
        case 0: goto L_800C99CC; break;
        case 1: goto L_800C99DC; break;
        case 2: goto L_800CAC80; break;
        case 3: goto L_800CAC80; break;
        case 4: goto L_800CAC80; break;
        case 5: goto L_800C9A20; break;
        case 6: goto L_800CAC80; break;
        case 7: goto L_800CAC80; break;
        case 8: goto L_800CAC80; break;
        case 9: goto L_800CAC80; break;
        case 10: goto L_800C9A48; break;
        case 11: goto L_800CAC80; break;
        case 12: goto L_800CAC80; break;
        case 13: goto L_800CAC80; break;
        case 14: goto L_800CAC80; break;
        case 15: goto L_800C9A78; break;
        case 16: goto L_800CAC80; break;
        case 17: goto L_800CAC80; break;
        case 18: goto L_800CAC80; break;
        case 19: goto L_800CAC80; break;
        case 20: goto L_800C9AA0; break;
        case 21: goto L_800CAC80; break;
        case 22: goto L_800CAC80; break;
        case 23: goto L_800CAC80; break;
        case 24: goto L_800CAC80; break;
        case 25: goto L_800CAC80; break;
        case 26: goto L_800CAC80; break;
        case 27: goto L_800CAC80; break;
        case 28: goto L_800CAC80; break;
        case 29: goto L_800CAC80; break;
        case 30: goto L_800C9ACC; break;
        case 31: goto L_800CAC80; break;
        case 32: goto L_800CAC80; break;
        case 33: goto L_800CAC80; break;
        case 34: goto L_800CAC80; break;
        case 35: goto L_800C9B00; break;
        case 36: goto L_800CAC80; break;
        case 37: goto L_800CAC80; break;
        case 38: goto L_800CAC80; break;
        case 39: goto L_800CAC80; break;
        case 40: goto L_800C9B28; break;
        case 41: goto L_800CAC80; break;
        case 42: goto L_800CAC80; break;
        case 43: goto L_800CAC80; break;
        case 44: goto L_800CAC80; break;
        case 45: goto L_800C9B4C; break;
        case 46: goto L_800CAC80; break;
        case 47: goto L_800CAC80; break;
        case 48: goto L_800CAC80; break;
        case 49: goto L_800CAC80; break;
        case 50: goto L_800C9B70; break;
        case 51: goto L_800CAC80; break;
        case 52: goto L_800CAC80; break;
        case 53: goto L_800CAC80; break;
        case 54: goto L_800CAC80; break;
        case 55: goto L_800C9BA4; break;
        case 56: goto L_800CAC80; break;
        case 57: goto L_800CAC80; break;
        case 58: goto L_800CAC80; break;
        case 59: goto L_800CAC80; break;
        case 60: goto L_800C9BD0; break;
        case 61: goto L_800CAC80; break;
        case 62: goto L_800CAC80; break;
        case 63: goto L_800CAC80; break;
        case 64: goto L_800CAC80; break;
        case 65: goto L_800C9C04; break;
        case 66: goto L_800CAC80; break;
        case 67: goto L_800CAC80; break;
        case 68: goto L_800CAC80; break;
        case 69: goto L_800CAC80; break;
        case 70: goto L_800C9C28; break;
        case 71: goto L_800CAC80; break;
        case 72: goto L_800CAC80; break;
        case 73: goto L_800CAC80; break;
        case 74: goto L_800CAC80; break;
        case 75: goto L_800C9C60; break;
        case 76: goto L_800CAC80; break;
        case 77: goto L_800CAC80; break;
        case 78: goto L_800CAC80; break;
        case 79: goto L_800CAC80; break;
        case 80: goto L_800C9C88; break;
        case 81: goto L_800CAC80; break;
        case 82: goto L_800CAC80; break;
        case 83: goto L_800CAC80; break;
        case 84: goto L_800CAC80; break;
        case 85: goto L_800C9CB0; break;
        case 86: goto L_800CAC80; break;
        case 87: goto L_800CAC80; break;
        case 88: goto L_800CAC80; break;
        case 89: goto L_800CAC80; break;
        case 90: goto L_800C9CE0; break;
        case 91: goto L_800CAC80; break;
        case 92: goto L_800CAC80; break;
        case 93: goto L_800CAC80; break;
        case 94: goto L_800CAC80; break;
        case 95: goto L_800C9D08; break;
        case 96: goto L_800CAC80; break;
        case 97: goto L_800CAC80; break;
        case 98: goto L_800CAC80; break;
        case 99: goto L_800CAC80; break;
        case 100: goto L_800C9D40; break;
        case 101: goto L_800CAC80; break;
        case 102: goto L_800CAC80; break;
        case 103: goto L_800CAC80; break;
        case 104: goto L_800CAC80; break;
        case 105: goto L_800C9D74; break;
        case 106: goto L_800CAC80; break;
        case 107: goto L_800CAC80; break;
        case 108: goto L_800CAC80; break;
        case 109: goto L_800CAC80; break;
        case 110: goto L_800C9DAC; break;
        case 111: goto L_800CAC80; break;
        case 112: goto L_800CAC80; break;
        case 113: goto L_800CAC80; break;
        case 114: goto L_800CAC80; break;
        case 115: goto L_800CAC80; break;
        case 116: goto L_800CAC80; break;
        case 117: goto L_800CAC80; break;
        case 118: goto L_800CAC80; break;
        case 119: goto L_800CAC80; break;
        case 120: goto L_800C9DD8; break;
        case 121: goto L_800CAC80; break;
        case 122: goto L_800CAC80; break;
        case 123: goto L_800CAC80; break;
        case 124: goto L_800CAC80; break;
        case 125: goto L_800C9E0C; break;
        case 126: goto L_800CAC80; break;
        case 127: goto L_800CAC80; break;
        case 128: goto L_800CAC80; break;
        case 129: goto L_800CAC80; break;
        case 130: goto L_800C9E48; break;
        case 131: goto L_800CAC80; break;
        case 132: goto L_800CAC80; break;
        case 133: goto L_800CAC80; break;
        case 134: goto L_800CAC80; break;
        case 135: goto L_800C9E8C; break;
        case 136: goto L_800CAC80; break;
        case 137: goto L_800CAC80; break;
        case 138: goto L_800CAC80; break;
        case 139: goto L_800CAC80; break;
        case 140: goto L_800C9EB4; break;
        case 141: goto L_800CAC80; break;
        case 142: goto L_800CAC80; break;
        case 143: goto L_800CAC80; break;
        case 144: goto L_800CAC80; break;
        case 145: goto L_800C9ED8; break;
        case 146: goto L_800CAC80; break;
        case 147: goto L_800CAC80; break;
        case 148: goto L_800CAC80; break;
        case 149: goto L_800CAC80; break;
        case 150: goto L_800C9F00; break;
        case 151: goto L_800CAC80; break;
        case 152: goto L_800CAC80; break;
        case 153: goto L_800CAC80; break;
        case 154: goto L_800CAC80; break;
        case 155: goto L_800C9F24; break;
        case 156: goto L_800CAC80; break;
        case 157: goto L_800CAC80; break;
        case 158: goto L_800CAC80; break;
        case 159: goto L_800CAC80; break;
        case 160: goto L_800C9F60; break;
        case 161: goto L_800CAC80; break;
        case 162: goto L_800CAC80; break;
        case 163: goto L_800CAC80; break;
        case 164: goto L_800CAC80; break;
        case 165: goto L_800C9FA4; break;
        case 166: goto L_800CAC80; break;
        case 167: goto L_800CAC80; break;
        case 168: goto L_800CAC80; break;
        case 169: goto L_800CAC80; break;
        case 170: goto L_800C9FDC; break;
        case 171: goto L_800CAC80; break;
        case 172: goto L_800CAC80; break;
        case 173: goto L_800CAC80; break;
        case 174: goto L_800CAC80; break;
        case 175: goto L_800CA008; break;
        case 176: goto L_800CAC80; break;
        case 177: goto L_800CAC80; break;
        case 178: goto L_800CAC80; break;
        case 179: goto L_800CAC80; break;
        case 180: goto L_800CA04C; break;
        case 181: goto L_800CAC80; break;
        case 182: goto L_800CAC80; break;
        case 183: goto L_800CAC80; break;
        case 184: goto L_800CAC80; break;
        case 185: goto L_800CA064; break;
        case 186: goto L_800CAC80; break;
        case 187: goto L_800CAC80; break;
        case 188: goto L_800CAC80; break;
        case 189: goto L_800CAC80; break;
        case 190: goto L_800CA090; break;
        case 191: goto L_800CAC80; break;
        case 192: goto L_800CAC80; break;
        case 193: goto L_800CAC80; break;
        case 194: goto L_800CAC80; break;
        case 195: goto L_800CA0C4; break;
        case 196: goto L_800CAC80; break;
        case 197: goto L_800CAC80; break;
        case 198: goto L_800CAC80; break;
        case 199: goto L_800CAC80; break;
        case 200: goto L_800CA0F4; break;
        case 201: goto L_800CAC80; break;
        case 202: goto L_800CAC80; break;
        case 203: goto L_800CAC80; break;
        case 204: goto L_800CAC80; break;
        case 205: goto L_800CA128; break;
        case 206: goto L_800CAC80; break;
        case 207: goto L_800CAC80; break;
        case 208: goto L_800CAC80; break;
        case 209: goto L_800CAC80; break;
        case 210: goto L_800CA160; break;
        case 211: goto L_800CAC80; break;
        case 212: goto L_800CAC80; break;
        case 213: goto L_800CAC80; break;
        case 214: goto L_800CAC80; break;
        case 215: goto L_800CAC80; break;
        case 216: goto L_800CAC80; break;
        case 217: goto L_800CAC80; break;
        case 218: goto L_800CAC80; break;
        case 219: goto L_800CAC80; break;
        case 220: goto L_800CA18C; break;
        case 221: goto L_800CAC80; break;
        case 222: goto L_800CAC80; break;
        case 223: goto L_800CAC80; break;
        case 224: goto L_800CAC80; break;
        case 225: goto L_800CAC80; break;
        case 226: goto L_800CAC80; break;
        case 227: goto L_800CAC80; break;
        case 228: goto L_800CAC80; break;
        case 229: goto L_800CAC80; break;
        case 230: goto L_800CA1C0; break;
        case 231: goto L_800CAC80; break;
        case 232: goto L_800CAC80; break;
        case 233: goto L_800CAC80; break;
        case 234: goto L_800CAC80; break;
        case 235: goto L_800CA1F4; break;
        case 236: goto L_800CAC80; break;
        case 237: goto L_800CAC80; break;
        case 238: goto L_800CAC80; break;
        case 239: goto L_800CAC80; break;
        case 240: goto L_800CA22C; break;
        case 241: goto L_800CAC80; break;
        case 242: goto L_800CAC80; break;
        case 243: goto L_800CAC80; break;
        case 244: goto L_800CAC80; break;
        case 245: goto L_800CA264; break;
        case 246: goto L_800CAC80; break;
        case 247: goto L_800CAC80; break;
        case 248: goto L_800CAC80; break;
        case 249: goto L_800CAC80; break;
        case 250: goto L_800CA298; break;
        case 251: goto L_800CAC80; break;
        case 252: goto L_800CAC80; break;
        case 253: goto L_800CAC80; break;
        case 254: goto L_800CAC80; break;
        case 255: goto L_800CA2B0; break;
        case 256: goto L_800CAC80; break;
        case 257: goto L_800CAC80; break;
        case 258: goto L_800CAC80; break;
        case 259: goto L_800CAC80; break;
        case 260: goto L_800CAC80; break;
        case 261: goto L_800CAC80; break;
        case 262: goto L_800CAC80; break;
        case 263: goto L_800CAC80; break;
        case 264: goto L_800CAC80; break;
        case 265: goto L_800CA2D4; break;
        case 266: goto L_800CAC80; break;
        case 267: goto L_800CAC80; break;
        case 268: goto L_800CAC80; break;
        case 269: goto L_800CAC80; break;
        case 270: goto L_800CAC80; break;
        case 271: goto L_800CAC80; break;
        case 272: goto L_800CAC80; break;
        case 273: goto L_800CAC80; break;
        case 274: goto L_800CAC80; break;
        case 275: goto L_800CAC80; break;
        case 276: goto L_800CAC80; break;
        case 277: goto L_800CAC80; break;
        case 278: goto L_800CAC80; break;
        case 279: goto L_800CAC80; break;
        case 280: goto L_800CAC80; break;
        case 281: goto L_800CAC80; break;
        case 282: goto L_800CAC80; break;
        case 283: goto L_800CAC80; break;
        case 284: goto L_800CAC80; break;
        case 285: goto L_800CAC80; break;
        case 286: goto L_800CAC80; break;
        case 287: goto L_800CAC80; break;
        case 288: goto L_800CAC80; break;
        case 289: goto L_800CAC80; break;
        case 290: goto L_800CA300; break;
        case 291: goto L_800CAC80; break;
        case 292: goto L_800CAC80; break;
        case 293: goto L_800CAC80; break;
        case 294: goto L_800CAC80; break;
        case 295: goto L_800CA334; break;
        case 296: goto L_800CAC80; break;
        case 297: goto L_800CAC80; break;
        case 298: goto L_800CAC80; break;
        case 299: goto L_800CAC80; break;
        case 300: goto L_800CA36C; break;
        case 301: goto L_800CAC80; break;
        case 302: goto L_800CAC80; break;
        case 303: goto L_800CAC80; break;
        case 304: goto L_800CAC80; break;
        case 305: goto L_800CA390; break;
        case 306: goto L_800CAC80; break;
        case 307: goto L_800CAC80; break;
        case 308: goto L_800CAC80; break;
        case 309: goto L_800CAC80; break;
        case 310: goto L_800CA3B8; break;
        case 311: goto L_800CAC80; break;
        case 312: goto L_800CAC80; break;
        case 313: goto L_800CAC80; break;
        case 314: goto L_800CAC80; break;
        case 315: goto L_800CAC80; break;
        case 316: goto L_800CAC80; break;
        case 317: goto L_800CAC80; break;
        case 318: goto L_800CAC80; break;
        case 319: goto L_800CAC80; break;
        case 320: goto L_800CA3E4; break;
        case 321: goto L_800CAC80; break;
        case 322: goto L_800CAC80; break;
        case 323: goto L_800CAC80; break;
        case 324: goto L_800CAC80; break;
        case 325: goto L_800CA418; break;
        case 326: goto L_800CAC80; break;
        case 327: goto L_800CAC80; break;
        case 328: goto L_800CAC80; break;
        case 329: goto L_800CAC80; break;
        case 330: goto L_800CA43C; break;
        case 331: goto L_800CAC80; break;
        case 332: goto L_800CAC80; break;
        case 333: goto L_800CAC80; break;
        case 334: goto L_800CAC80; break;
        case 335: goto L_800CA464; break;
        case 336: goto L_800CAC80; break;
        case 337: goto L_800CAC80; break;
        case 338: goto L_800CAC80; break;
        case 339: goto L_800CAC80; break;
        case 340: goto L_800CA498; break;
        case 341: goto L_800CAC80; break;
        case 342: goto L_800CAC80; break;
        case 343: goto L_800CAC80; break;
        case 344: goto L_800CAC80; break;
        case 345: goto L_800CA4CC; break;
        case 346: goto L_800CAC80; break;
        case 347: goto L_800CAC80; break;
        case 348: goto L_800CAC80; break;
        case 349: goto L_800CAC80; break;
        case 350: goto L_800CA504; break;
        default: switch_error(__func__, 0x800C99C4, 0x800ED8AC);
    }
    // 0x800C99C8: nop

L_800C99CC:
    // 0x800C99CC: jal         0x800CAD14
    // 0x800C99D0: nop

    func_800CAD14(rdram, ctx);
        goto after_0;
    // 0x800C99D0: nop

    after_0:
    // 0x800C99D4: b           L_800CAC80
    // 0x800C99D8: nop

        goto L_800CAC80;
    // 0x800C99D8: nop

L_800C99DC:
    // 0x800C99DC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C99E0: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800C99E4: bne         $t9, $zero, L_800CAC80
    if (ctx->r25 != 0) {
        // 0x800C99E8: nop
    
            goto L_800CAC80;
    }
    // 0x800C99E8: nop

    // 0x800C99EC: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x800C99F0: jal         0x800CAC94
    // 0x800C99F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_1;
    // 0x800C99F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800C99F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C99FC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9A00: jal         0x800CAD20
    // 0x800C9A04: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800CAD20(rdram, ctx);
        goto after_2;
    // 0x800C9A04: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_2:
    // 0x800C9A08: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x800C9A0C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x800C9A10: jal         0x800CAE20
    // 0x800C9A14: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800CAE20(rdram, ctx);
        goto after_3;
    // 0x800C9A14: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800C9A18: b           L_800CAC80
    // 0x800C9A1C: nop

        goto L_800CAC80;
    // 0x800C9A1C: nop

L_800C9A20:
    // 0x800C9A20: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9A24: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800C9A28: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800C9A2C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9A2C: nop

    // 0x800C9A30: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x800C9A34: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800C9A38: jal         0x800CAE20
    // 0x800C9A3C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    func_800CAE20(rdram, ctx);
        goto after_4;
    // 0x800C9A3C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_4:
    // 0x800C9A40: b           L_800CAC80
    // 0x800C9A44: nop

        goto L_800CAC80;
    // 0x800C9A44: nop

L_800C9A48:
    // 0x800C9A48: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C9A4C: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800C9A50: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800C9A54: nop
    
            goto L_800CAC80;
    }
    // 0x800C9A54: nop

    // 0x800C9A58: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800C9A5C: addiu       $a1, $zero, 0x640
    ctx->r5 = ADD32(0, 0X640);
    // 0x800C9A60: jal         0x800CAE20
    // 0x800C9A64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_5;
    // 0x800C9A64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x800C9A68: jal         0x800C8544
    // 0x800C9A6C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x800C9A6C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_6:
    // 0x800C9A70: b           L_800CAC80
    // 0x800C9A74: nop

        goto L_800CAC80;
    // 0x800C9A74: nop

L_800C9A78:
    // 0x800C9A78: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C9A7C: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800C9A80: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800C9A84: nop
    
            goto L_800CAC80;
    }
    // 0x800C9A84: nop

    // 0x800C9A88: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    // 0x800C9A8C: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    // 0x800C9A90: jal         0x800CAE20
    // 0x800C9A94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800CAE20(rdram, ctx);
        goto after_7;
    // 0x800C9A94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x800C9A98: b           L_800CAC80
    // 0x800C9A9C: nop

        goto L_800CAC80;
    // 0x800C9A9C: nop

L_800C9AA0:
    // 0x800C9AA0: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C9AA4: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800C9AA8: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800C9AAC: nop
    
            goto L_800CAC80;
    }
    // 0x800C9AAC: nop

    // 0x800C9AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9AB4: jal         0x800CAD98
    // 0x800C9AB8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_800CAD98(rdram, ctx);
        goto after_8;
    // 0x800C9AB8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_8:
    // 0x800C9ABC: jal         0x800CAD14
    // 0x800C9AC0: nop

    func_800CAD14(rdram, ctx);
        goto after_9;
    // 0x800C9AC0: nop

    after_9:
    // 0x800C9AC4: b           L_800CAC80
    // 0x800C9AC8: nop

        goto L_800CAC80;
    // 0x800C9AC8: nop

L_800C9ACC:
    // 0x800C9ACC: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C9AD0: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800C9AD4: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800C9AD8: nop
    
            goto L_800CAC80;
    }
    // 0x800C9AD8: nop

    // 0x800C9ADC: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9AE0: jal         0x800CAC94
    // 0x800C9AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_10;
    // 0x800C9AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800C9AE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9AEC: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800C9AF0: jal         0x800CAD20
    // 0x800C9AF4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800CAD20(rdram, ctx);
        goto after_11;
    // 0x800C9AF4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_11:
    // 0x800C9AF8: b           L_800CAC80
    // 0x800C9AFC: nop

        goto L_800CAC80;
    // 0x800C9AFC: nop

L_800C9B00:
    // 0x800C9B00: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800C9B04: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800C9B08: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800C9B0C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9B0C: nop

    // 0x800C9B10: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9B14: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9B18: jal         0x800CAD20
    // 0x800C9B1C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800CAD20(rdram, ctx);
        goto after_12;
    // 0x800C9B1C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_12:
    // 0x800C9B20: b           L_800CAC80
    // 0x800C9B24: nop

        goto L_800CAC80;
    // 0x800C9B24: nop

L_800C9B28:
    // 0x800C9B28: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9B2C: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800C9B30: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800C9B34: nop
    
            goto L_800CAC80;
    }
    // 0x800C9B34: nop

    // 0x800C9B38: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800C9B3C: jal         0x800CAD98
    // 0x800C9B40: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800CAD98(rdram, ctx);
        goto after_13;
    // 0x800C9B40: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_13:
    // 0x800C9B44: b           L_800CAC80
    // 0x800C9B48: nop

        goto L_800CAC80;
    // 0x800C9B48: nop

L_800C9B4C:
    // 0x800C9B4C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C9B50: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800C9B54: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800C9B58: nop
    
            goto L_800CAC80;
    }
    // 0x800C9B58: nop

    // 0x800C9B5C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9B60: jal         0x800CAD98
    // 0x800C9B64: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800CAD98(rdram, ctx);
        goto after_14;
    // 0x800C9B64: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_14:
    // 0x800C9B68: b           L_800CAC80
    // 0x800C9B6C: nop

        goto L_800CAC80;
    // 0x800C9B6C: nop

L_800C9B70:
    // 0x800C9B70: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C9B74: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800C9B78: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800C9B7C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9B7C: nop

    // 0x800C9B80: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x800C9B84: jal         0x800CAD98
    // 0x800C9B88: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_15;
    // 0x800C9B88: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_15:
    // 0x800C9B8C: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9B90: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    // 0x800C9B94: jal         0x800CAE20
    // 0x800C9B98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_16;
    // 0x800C9B98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_16:
    // 0x800C9B9C: b           L_800CAC80
    // 0x800C9BA0: nop

        goto L_800CAC80;
    // 0x800C9BA0: nop

L_800C9BA4:
    // 0x800C9BA4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C9BA8: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800C9BAC: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800C9BB0: nop
    
            goto L_800CAC80;
    }
    // 0x800C9BB0: nop

    // 0x800C9BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9BB8: jal         0x800CAD98
    // 0x800C9BBC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_17;
    // 0x800C9BBC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_17:
    // 0x800C9BC0: jal         0x800CAD14
    // 0x800C9BC4: nop

    func_800CAD14(rdram, ctx);
        goto after_18;
    // 0x800C9BC4: nop

    after_18:
    // 0x800C9BC8: b           L_800CAC80
    // 0x800C9BCC: nop

        goto L_800CAC80;
    // 0x800C9BCC: nop

L_800C9BD0:
    // 0x800C9BD0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9BD4: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800C9BD8: bne         $t0, $zero, L_800CAC80
    if (ctx->r8 != 0) {
        // 0x800C9BDC: nop
    
            goto L_800CAC80;
    }
    // 0x800C9BDC: nop

    // 0x800C9BE0: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9BE4: jal         0x800CAC94
    // 0x800C9BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_19;
    // 0x800C9BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x800C9BEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9BF0: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800C9BF4: jal         0x800CAD20
    // 0x800C9BF8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800CAD20(rdram, ctx);
        goto after_20;
    // 0x800C9BF8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_20:
    // 0x800C9BFC: b           L_800CAC80
    // 0x800C9C00: nop

        goto L_800CAC80;
    // 0x800C9C00: nop

L_800C9C04:
    // 0x800C9C04: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C9C08: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800C9C0C: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800C9C10: nop
    
            goto L_800CAC80;
    }
    // 0x800C9C10: nop

    // 0x800C9C14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9C18: jal         0x800CAD98
    // 0x800C9C1C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800CAD98(rdram, ctx);
        goto after_21;
    // 0x800C9C1C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_21:
    // 0x800C9C20: b           L_800CAC80
    // 0x800C9C24: nop

        goto L_800CAC80;
    // 0x800C9C24: nop

L_800C9C28:
    // 0x800C9C28: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C9C2C: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800C9C30: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800C9C34: nop
    
            goto L_800CAC80;
    }
    // 0x800C9C34: nop

    // 0x800C9C38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9C3C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800C9C40: jal         0x800CAD20
    // 0x800C9C44: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CAD20(rdram, ctx);
        goto after_22;
    // 0x800C9C44: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_22:
    // 0x800C9C48: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9C4C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x800C9C50: jal         0x800CAE20
    // 0x800C9C54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CAE20(rdram, ctx);
        goto after_23;
    // 0x800C9C54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_23:
    // 0x800C9C58: b           L_800CAC80
    // 0x800C9C5C: nop

        goto L_800CAC80;
    // 0x800C9C5C: nop

L_800C9C60:
    // 0x800C9C60: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C9C64: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800C9C68: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800C9C6C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9C6C: nop

    // 0x800C9C70: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    // 0x800C9C74: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800C9C78: jal         0x800CAE74
    // 0x800C9C7C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAE74(rdram, ctx);
        goto after_24;
    // 0x800C9C7C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_24:
    // 0x800C9C80: b           L_800CAC80
    // 0x800C9C84: nop

        goto L_800CAC80;
    // 0x800C9C84: nop

L_800C9C88:
    // 0x800C9C88: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C9C8C: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800C9C90: beq         $t4, $zero, L_800CAC80
    if (ctx->r12 == 0) {
        // 0x800C9C94: nop
    
            goto L_800CAC80;
    }
    // 0x800C9C94: nop

    // 0x800C9C98: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9C9C: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800C9CA0: jal         0x800CAE74
    // 0x800C9CA4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAE74(rdram, ctx);
        goto after_25;
    // 0x800C9CA4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_25:
    // 0x800C9CA8: b           L_800CAC80
    // 0x800C9CAC: nop

        goto L_800CAC80;
    // 0x800C9CAC: nop

L_800C9CB0:
    // 0x800C9CB0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800C9CB4: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800C9CB8: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800C9CBC: nop
    
            goto L_800CAC80;
    }
    // 0x800C9CBC: nop

    // 0x800C9CC0: jal         0x800C8544
    // 0x800C9CC4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800C8544(rdram, ctx);
        goto after_26;
    // 0x800C9CC4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_26:
    // 0x800C9CC8: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800C9CCC: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800C9CD0: jal         0x800CAE20
    // 0x800C9CD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_27;
    // 0x800C9CD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_27:
    // 0x800C9CD8: b           L_800CAC80
    // 0x800C9CDC: nop

        goto L_800CAC80;
    // 0x800C9CDC: nop

L_800C9CE0:
    // 0x800C9CE0: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9CE4: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800C9CE8: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800C9CEC: nop
    
            goto L_800CAC80;
    }
    // 0x800C9CEC: nop

    // 0x800C9CF0: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9CF4: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800C9CF8: jal         0x800CAE20
    // 0x800C9CFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CAE20(rdram, ctx);
        goto after_28;
    // 0x800C9CFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_28:
    // 0x800C9D00: b           L_800CAC80
    // 0x800C9D04: nop

        goto L_800CAC80;
    // 0x800C9D04: nop

L_800C9D08:
    // 0x800C9D08: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C9D0C: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800C9D10: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800C9D14: nop
    
            goto L_800CAC80;
    }
    // 0x800C9D14: nop

    // 0x800C9D18: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800C9D1C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9D20: jal         0x800CAD20
    // 0x800C9D24: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_29;
    // 0x800C9D24: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_29:
    // 0x800C9D28: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9D2C: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800C9D30: jal         0x800CAE74
    // 0x800C9D34: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800CAE74(rdram, ctx);
        goto after_30;
    // 0x800C9D34: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_30:
    // 0x800C9D38: b           L_800CAC80
    // 0x800C9D3C: nop

        goto L_800CAC80;
    // 0x800C9D3C: nop

L_800C9D40:
    // 0x800C9D40: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C9D44: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800C9D48: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800C9D4C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9D4C: nop

    // 0x800C9D50: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800C9D54: jal         0x800CAD98
    // 0x800C9D58: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_31;
    // 0x800C9D58: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_31:
    // 0x800C9D5C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800C9D60: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800C9D64: jal         0x800CAE20
    // 0x800C9D68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_32;
    // 0x800C9D68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_32:
    // 0x800C9D6C: b           L_800CAC80
    // 0x800C9D70: nop

        goto L_800CAC80;
    // 0x800C9D70: nop

L_800C9D74:
    // 0x800C9D74: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C9D78: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800C9D7C: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800C9D80: nop
    
            goto L_800CAC80;
    }
    // 0x800C9D80: nop

    // 0x800C9D84: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800C9D88: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9D8C: jal         0x800CAD20
    // 0x800C9D90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_33;
    // 0x800C9D90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_33:
    // 0x800C9D94: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9D98: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800C9D9C: jal         0x800CAE20
    // 0x800C9DA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CAE20(rdram, ctx);
        goto after_34;
    // 0x800C9DA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_34:
    // 0x800C9DA4: b           L_800CAC80
    // 0x800C9DA8: nop

        goto L_800CAC80;
    // 0x800C9DA8: nop

L_800C9DAC:
    // 0x800C9DAC: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9DB0: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800C9DB4: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800C9DB8: nop
    
            goto L_800CAC80;
    }
    // 0x800C9DB8: nop

    // 0x800C9DBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9DC0: jal         0x800CAD98
    // 0x800C9DC4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800CAD98(rdram, ctx);
        goto after_35;
    // 0x800C9DC4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_35:
    // 0x800C9DC8: jal         0x800CAD14
    // 0x800C9DCC: nop

    func_800CAD14(rdram, ctx);
        goto after_36;
    // 0x800C9DCC: nop

    after_36:
    // 0x800C9DD0: b           L_800CAC80
    // 0x800C9DD4: nop

        goto L_800CAC80;
    // 0x800C9DD4: nop

L_800C9DD8:
    // 0x800C9DD8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C9DDC: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800C9DE0: bne         $t1, $zero, L_800CAC80
    if (ctx->r9 != 0) {
        // 0x800C9DE4: nop
    
            goto L_800CAC80;
    }
    // 0x800C9DE4: nop

    // 0x800C9DE8: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800C9DEC: jal         0x800CAC94
    // 0x800C9DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_37;
    // 0x800C9DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x800C9DF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9DF8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9DFC: jal         0x800CAD20
    // 0x800C9E00: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_38;
    // 0x800C9E00: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_38:
    // 0x800C9E04: b           L_800CAC80
    // 0x800C9E08: nop

        goto L_800CAC80;
    // 0x800C9E08: nop

L_800C9E0C:
    // 0x800C9E0C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800C9E10: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800C9E14: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800C9E18: nop
    
            goto L_800CAC80;
    }
    // 0x800C9E18: nop

    // 0x800C9E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9E20: jal         0x800CAD98
    // 0x800C9E24: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_39;
    // 0x800C9E24: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_39:
    // 0x800C9E28: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800C9E2C: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800C9E30: jal         0x800CAE20
    // 0x800C9E34: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAE20(rdram, ctx);
        goto after_40;
    // 0x800C9E34: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_40:
    // 0x800C9E38: jal         0x800CAD14
    // 0x800C9E3C: nop

    func_800CAD14(rdram, ctx);
        goto after_41;
    // 0x800C9E3C: nop

    after_41:
    // 0x800C9E40: b           L_800CAC80
    // 0x800C9E44: nop

        goto L_800CAC80;
    // 0x800C9E44: nop

L_800C9E48:
    // 0x800C9E48: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C9E4C: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800C9E50: bne         $t3, $zero, L_800CAC80
    if (ctx->r11 != 0) {
        // 0x800C9E54: nop
    
            goto L_800CAC80;
    }
    // 0x800C9E54: nop

    // 0x800C9E58: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9E5C: jal         0x800CAC94
    // 0x800C9E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_42;
    // 0x800C9E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x800C9E64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9E68: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800C9E6C: jal         0x800CAD20
    // 0x800C9E70: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_43;
    // 0x800C9E70: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_43:
    // 0x800C9E74: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9E78: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800C9E7C: jal         0x800CAE74
    // 0x800C9E80: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800CAE74(rdram, ctx);
        goto after_44;
    // 0x800C9E80: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_44:
    // 0x800C9E84: b           L_800CAC80
    // 0x800C9E88: nop

        goto L_800CAC80;
    // 0x800C9E88: nop

L_800C9E8C:
    // 0x800C9E8C: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800C9E90: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800C9E94: beq         $t4, $zero, L_800CAC80
    if (ctx->r12 == 0) {
        // 0x800C9E98: nop
    
            goto L_800CAC80;
    }
    // 0x800C9E98: nop

    // 0x800C9E9C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9EA0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9EA4: jal         0x800CAD20
    // 0x800C9EA8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAD20(rdram, ctx);
        goto after_45;
    // 0x800C9EA8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_45:
    // 0x800C9EAC: b           L_800CAC80
    // 0x800C9EB0: nop

        goto L_800CAC80;
    // 0x800C9EB0: nop

L_800C9EB4:
    // 0x800C9EB4: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800C9EB8: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800C9EBC: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800C9EC0: nop
    
            goto L_800CAC80;
    }
    // 0x800C9EC0: nop

    // 0x800C9EC4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9EC8: jal         0x800CAD98
    // 0x800C9ECC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800CAD98(rdram, ctx);
        goto after_46;
    // 0x800C9ECC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_46:
    // 0x800C9ED0: b           L_800CAC80
    // 0x800C9ED4: nop

        goto L_800CAC80;
    // 0x800C9ED4: nop

L_800C9ED8:
    // 0x800C9ED8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9EDC: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800C9EE0: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800C9EE4: nop
    
            goto L_800CAC80;
    }
    // 0x800C9EE4: nop

    // 0x800C9EE8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9EEC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9EF0: jal         0x800CAD20
    // 0x800C9EF4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAD20(rdram, ctx);
        goto after_47;
    // 0x800C9EF4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_47:
    // 0x800C9EF8: b           L_800CAC80
    // 0x800C9EFC: nop

        goto L_800CAC80;
    // 0x800C9EFC: nop

L_800C9F00:
    // 0x800C9F00: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C9F04: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800C9F08: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800C9F0C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9F0C: nop

    // 0x800C9F10: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9F14: jal         0x800CAD98
    // 0x800C9F18: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800CAD98(rdram, ctx);
        goto after_48;
    // 0x800C9F18: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_48:
    // 0x800C9F1C: b           L_800CAC80
    // 0x800C9F20: nop

        goto L_800CAC80;
    // 0x800C9F20: nop

L_800C9F24:
    // 0x800C9F24: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800C9F28: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800C9F2C: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800C9F30: nop
    
            goto L_800CAC80;
    }
    // 0x800C9F30: nop

    // 0x800C9F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9F38: jal         0x800CAD98
    // 0x800C9F3C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800CAD98(rdram, ctx);
        goto after_49;
    // 0x800C9F3C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_49:
    // 0x800C9F40: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800C9F44: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800C9F48: jal         0x800CAE20
    // 0x800C9F4C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAE20(rdram, ctx);
        goto after_50;
    // 0x800C9F4C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_50:
    // 0x800C9F50: jal         0x800CAD14
    // 0x800C9F54: nop

    func_800CAD14(rdram, ctx);
        goto after_51;
    // 0x800C9F54: nop

    after_51:
    // 0x800C9F58: b           L_800CAC80
    // 0x800C9F5C: nop

        goto L_800CAC80;
    // 0x800C9F5C: nop

L_800C9F60:
    // 0x800C9F60: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C9F64: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800C9F68: bne         $t9, $zero, L_800CAC80
    if (ctx->r25 != 0) {
        // 0x800C9F6C: nop
    
            goto L_800CAC80;
    }
    // 0x800C9F6C: nop

    // 0x800C9F70: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9F74: jal         0x800CAC94
    // 0x800C9F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_52;
    // 0x800C9F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_52:
    // 0x800C9F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9F80: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800C9F84: jal         0x800CAD20
    // 0x800C9F88: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CAD20(rdram, ctx);
        goto after_53;
    // 0x800C9F88: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_53:
    // 0x800C9F8C: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800C9F90: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800C9F94: jal         0x800CAE20
    // 0x800C9F98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_54;
    // 0x800C9F98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_54:
    // 0x800C9F9C: b           L_800CAC80
    // 0x800C9FA0: nop

        goto L_800CAC80;
    // 0x800C9FA0: nop

L_800C9FA4:
    // 0x800C9FA4: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C9FA8: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800C9FAC: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800C9FB0: nop
    
            goto L_800CAC80;
    }
    // 0x800C9FB0: nop

    // 0x800C9FB4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800C9FB8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9FBC: jal         0x800CAD20
    // 0x800C9FC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_55;
    // 0x800C9FC0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_55:
    // 0x800C9FC4: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800C9FC8: addiu       $a1, $zero, 0x640
    ctx->r5 = ADD32(0, 0X640);
    // 0x800C9FCC: jal         0x800CAE20
    // 0x800C9FD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800CAE20(rdram, ctx);
        goto after_56;
    // 0x800C9FD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_56:
    // 0x800C9FD4: b           L_800CAC80
    // 0x800C9FD8: nop

        goto L_800CAC80;
    // 0x800C9FD8: nop

L_800C9FDC:
    // 0x800C9FDC: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C9FE0: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800C9FE4: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800C9FE8: nop
    
            goto L_800CAC80;
    }
    // 0x800C9FE8: nop

    // 0x800C9FEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9FF0: jal         0x800CAD98
    // 0x800C9FF4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_57;
    // 0x800C9FF4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_57:
    // 0x800C9FF8: jal         0x800CAD14
    // 0x800C9FFC: nop

    func_800CAD14(rdram, ctx);
        goto after_58;
    // 0x800C9FFC: nop

    after_58:
    // 0x800CA000: b           L_800CAC80
    // 0x800CA004: nop

        goto L_800CAC80;
    // 0x800CA004: nop

L_800CA008:
    // 0x800CA008: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA00C: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA010: bne         $t2, $zero, L_800CAC80
    if (ctx->r10 != 0) {
        // 0x800CA014: nop
    
            goto L_800CAC80;
    }
    // 0x800CA014: nop

    // 0x800CA018: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA01C: jal         0x800CAC94
    // 0x800CA020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_59;
    // 0x800CA020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_59:
    // 0x800CA024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA028: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA02C: jal         0x800CAD20
    // 0x800CA030: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_60;
    // 0x800CA030: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_60:
    // 0x800CA034: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA038: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CA03C: jal         0x800CAE20
    // 0x800CA040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_61;
    // 0x800CA040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_61:
    // 0x800CA044: b           L_800CAC80
    // 0x800CA048: nop

        goto L_800CAC80;
    // 0x800CA048: nop

L_800CA04C:
    // 0x800CA04C: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA050: addiu       $a1, $zero, 0x640
    ctx->r5 = ADD32(0, 0X640);
    // 0x800CA054: jal         0x800CAE20
    // 0x800CA058: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_62;
    // 0x800CA058: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_62:
    // 0x800CA05C: b           L_800CAC80
    // 0x800CA060: nop

        goto L_800CAC80;
    // 0x800CA060: nop

L_800CA064:
    // 0x800CA064: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA068: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA06C: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA070: nop
    
            goto L_800CAC80;
    }
    // 0x800CA070: nop

    // 0x800CA074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA078: jal         0x800CAD98
    // 0x800CA07C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800CAD98(rdram, ctx);
        goto after_63;
    // 0x800CA07C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_63:
    // 0x800CA080: jal         0x800CAD14
    // 0x800CA084: nop

    func_800CAD14(rdram, ctx);
        goto after_64;
    // 0x800CA084: nop

    after_64:
    // 0x800CA088: b           L_800CAC80
    // 0x800CA08C: nop

        goto L_800CAC80;
    // 0x800CA08C: nop

L_800CA090:
    // 0x800CA090: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CA094: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CA098: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800CA09C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA09C: nop

    // 0x800CA0A0: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA0A4: jal         0x800CAC94
    // 0x800CA0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_65;
    // 0x800CA0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_65:
    // 0x800CA0AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA0B0: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA0B4: jal         0x800CAD20
    // 0x800CA0B8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_66;
    // 0x800CA0B8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_66:
    // 0x800CA0BC: b           L_800CAC80
    // 0x800CA0C0: nop

        goto L_800CAC80;
    // 0x800CA0C0: nop

L_800CA0C4:
    // 0x800CA0C4: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CA0C8: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CA0CC: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CA0D0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA0D0: nop

    // 0x800CA0D4: jal         0x800C8544
    // 0x800CA0D8: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800C8544(rdram, ctx);
        goto after_67;
    // 0x800CA0D8: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_67:
    // 0x800CA0DC: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA0E0: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA0E4: jal         0x800CAE20
    // 0x800CA0E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CAE20(rdram, ctx);
        goto after_68;
    // 0x800CA0E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_68:
    // 0x800CA0EC: b           L_800CAC80
    // 0x800CA0F0: nop

        goto L_800CAC80;
    // 0x800CA0F0: nop

L_800CA0F4:
    // 0x800CA0F4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CA0F8: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CA0FC: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CA100: nop
    
            goto L_800CAC80;
    }
    // 0x800CA100: nop

    // 0x800CA104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA108: jal         0x800CAD98
    // 0x800CA10C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_69;
    // 0x800CA10C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_69:
    // 0x800CA110: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CA114: addiu       $a1, $zero, 0x6A4
    ctx->r5 = ADD32(0, 0X6A4);
    // 0x800CA118: jal         0x800CAE20
    // 0x800CA11C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAE20(rdram, ctx);
        goto after_70;
    // 0x800CA11C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_70:
    // 0x800CA120: b           L_800CAC80
    // 0x800CA124: nop

        goto L_800CAC80;
    // 0x800CA124: nop

L_800CA128:
    // 0x800CA128: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CA12C: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CA130: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800CA134: nop
    
            goto L_800CAC80;
    }
    // 0x800CA134: nop

    // 0x800CA138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA13C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA140: jal         0x800CAD20
    // 0x800CA144: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CAD20(rdram, ctx);
        goto after_71;
    // 0x800CA144: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_71:
    // 0x800CA148: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA14C: addiu       $a1, $zero, 0xA28
    ctx->r5 = ADD32(0, 0XA28);
    // 0x800CA150: jal         0x800CAE20
    // 0x800CA154: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800CAE20(rdram, ctx);
        goto after_72;
    // 0x800CA154: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_72:
    // 0x800CA158: b           L_800CAC80
    // 0x800CA15C: nop

        goto L_800CAC80;
    // 0x800CA15C: nop

L_800CA160:
    // 0x800CA160: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CA164: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CA168: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CA16C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA16C: nop

    // 0x800CA170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA174: jal         0x800CAD98
    // 0x800CA178: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800CAD98(rdram, ctx);
        goto after_73;
    // 0x800CA178: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_73:
    // 0x800CA17C: jal         0x800CAD14
    // 0x800CA180: nop

    func_800CAD14(rdram, ctx);
        goto after_74;
    // 0x800CA180: nop

    after_74:
    // 0x800CA184: b           L_800CAC80
    // 0x800CA188: nop

        goto L_800CAC80;
    // 0x800CA188: nop

L_800CA18C:
    // 0x800CA18C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CA190: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CA194: bne         $t9, $zero, L_800CAC80
    if (ctx->r25 != 0) {
        // 0x800CA198: nop
    
            goto L_800CAC80;
    }
    // 0x800CA198: nop

    // 0x800CA19C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA1A0: jal         0x800CAC94
    // 0x800CA1A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_75;
    // 0x800CA1A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_75:
    // 0x800CA1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA1AC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA1B0: jal         0x800CAD20
    // 0x800CA1B4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800CAD20(rdram, ctx);
        goto after_76;
    // 0x800CA1B4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_76:
    // 0x800CA1B8: b           L_800CAC80
    // 0x800CA1BC: nop

        goto L_800CAC80;
    // 0x800CA1BC: nop

L_800CA1C0:
    // 0x800CA1C0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CA1C4: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CA1C8: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800CA1CC: nop
    
            goto L_800CAC80;
    }
    // 0x800CA1CC: nop

    // 0x800CA1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA1D4: jal         0x800CAD98
    // 0x800CA1D8: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    func_800CAD98(rdram, ctx);
        goto after_77;
    // 0x800CA1D8: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_77:
    // 0x800CA1DC: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA1E0: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    // 0x800CA1E4: jal         0x800CAE20
    // 0x800CA1E8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAE20(rdram, ctx);
        goto after_78;
    // 0x800CA1E8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_78:
    // 0x800CA1EC: b           L_800CAC80
    // 0x800CA1F0: nop

        goto L_800CAC80;
    // 0x800CA1F0: nop

L_800CA1F4:
    // 0x800CA1F4: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CA1F8: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CA1FC: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800CA200: nop
    
            goto L_800CAC80;
    }
    // 0x800CA200: nop

    // 0x800CA204: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA208: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA20C: jal         0x800CAD20
    // 0x800CA210: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_79;
    // 0x800CA210: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_79:
    // 0x800CA214: addiu       $a0, $zero, 0x4E2
    ctx->r4 = ADD32(0, 0X4E2);
    // 0x800CA218: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800CA21C: jal         0x800CAE74
    // 0x800CA220: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800CAE74(rdram, ctx);
        goto after_80;
    // 0x800CA220: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_80:
    // 0x800CA224: b           L_800CAC80
    // 0x800CA228: nop

        goto L_800CAC80;
    // 0x800CA228: nop

L_800CA22C:
    // 0x800CA22C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA230: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA234: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800CA238: nop
    
            goto L_800CAC80;
    }
    // 0x800CA238: nop

    // 0x800CA23C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA240: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA244: jal         0x800CAD20
    // 0x800CA248: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800CAD20(rdram, ctx);
        goto after_81;
    // 0x800CA248: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_81:
    // 0x800CA24C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA250: addiu       $a1, $zero, 0x640
    ctx->r5 = ADD32(0, 0X640);
    // 0x800CA254: jal         0x800CAE20
    // 0x800CA258: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAE20(rdram, ctx);
        goto after_82;
    // 0x800CA258: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_82:
    // 0x800CA25C: b           L_800CAC80
    // 0x800CA260: nop

        goto L_800CAC80;
    // 0x800CA260: nop

L_800CA264:
    // 0x800CA264: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA268: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA26C: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA270: nop
    
            goto L_800CAC80;
    }
    // 0x800CA270: nop

    // 0x800CA274: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA278: jal         0x800CAD98
    // 0x800CA27C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_800CAD98(rdram, ctx);
        goto after_83;
    // 0x800CA27C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_83:
    // 0x800CA280: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    // 0x800CA284: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800CA288: jal         0x800CAE74
    // 0x800CA28C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800CAE74(rdram, ctx);
        goto after_84;
    // 0x800CA28C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_84:
    // 0x800CA290: b           L_800CAC80
    // 0x800CA294: nop

        goto L_800CAC80;
    // 0x800CA294: nop

L_800CA298:
    // 0x800CA298: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CA29C: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CA2A0: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800CA2A4: nop
    
            goto L_800CAC80;
    }
    // 0x800CA2A4: nop

    // 0x800CA2A8: b           L_800CAC80
    // 0x800CA2AC: nop

        goto L_800CAC80;
    // 0x800CA2AC: nop

L_800CA2B0:
    // 0x800CA2B0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CA2B4: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CA2B8: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CA2BC: nop
    
            goto L_800CAC80;
    }
    // 0x800CA2BC: nop

    // 0x800CA2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA2C4: jal         0x800CAD98
    // 0x800CA2C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800CAD98(rdram, ctx);
        goto after_85;
    // 0x800CA2C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_85:
    // 0x800CA2CC: b           L_800CAC80
    // 0x800CA2D0: nop

        goto L_800CAC80;
    // 0x800CA2D0: nop

L_800CA2D4:
    // 0x800CA2D4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CA2D8: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CA2DC: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CA2E0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA2E0: nop

    // 0x800CA2E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA2E8: jal         0x800CAD98
    // 0x800CA2EC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_800CAD98(rdram, ctx);
        goto after_86;
    // 0x800CA2EC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_86:
    // 0x800CA2F0: jal         0x800CAD14
    // 0x800CA2F4: nop

    func_800CAD14(rdram, ctx);
        goto after_87;
    // 0x800CA2F4: nop

    after_87:
    // 0x800CA2F8: b           L_800CAC80
    // 0x800CA2FC: nop

        goto L_800CAC80;
    // 0x800CA2FC: nop

L_800CA300:
    // 0x800CA300: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CA304: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CA308: bne         $t7, $zero, L_800CAC80
    if (ctx->r15 != 0) {
        // 0x800CA30C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA30C: nop

    // 0x800CA310: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA314: jal         0x800CAC94
    // 0x800CA318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_88;
    // 0x800CA318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_88:
    // 0x800CA31C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA320: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA324: jal         0x800CAD20
    // 0x800CA328: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CAD20(rdram, ctx);
        goto after_89;
    // 0x800CA328: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_89:
    // 0x800CA32C: b           L_800CAC80
    // 0x800CA330: nop

        goto L_800CAC80;
    // 0x800CA330: nop

L_800CA334:
    // 0x800CA334: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CA338: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CA33C: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CA340: nop
    
            goto L_800CAC80;
    }
    // 0x800CA340: nop

    // 0x800CA344: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA348: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA34C: jal         0x800CAD20
    // 0x800CA350: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_90;
    // 0x800CA350: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_90:
    // 0x800CA354: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA358: addiu       $a1, $zero, 0x546
    ctx->r5 = ADD32(0, 0X546);
    // 0x800CA35C: jal         0x800CAE20
    // 0x800CA360: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800CAE20(rdram, ctx);
        goto after_91;
    // 0x800CA360: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_91:
    // 0x800CA364: b           L_800CAC80
    // 0x800CA368: nop

        goto L_800CAC80;
    // 0x800CA368: nop

L_800CA36C:
    // 0x800CA36C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CA370: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CA374: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800CA378: nop
    
            goto L_800CAC80;
    }
    // 0x800CA378: nop

    // 0x800CA37C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA380: jal         0x800CAD98
    // 0x800CA384: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_800CAD98(rdram, ctx);
        goto after_92;
    // 0x800CA384: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_92:
    // 0x800CA388: b           L_800CAC80
    // 0x800CA38C: nop

        goto L_800CAC80;
    // 0x800CA38C: nop

L_800CA390:
    // 0x800CA390: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CA394: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CA398: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800CA39C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA39C: nop

    // 0x800CA3A0: addiu       $a0, $zero, 0x546
    ctx->r4 = ADD32(0, 0X546);
    // 0x800CA3A4: addiu       $a1, $zero, 0x708
    ctx->r5 = ADD32(0, 0X708);
    // 0x800CA3A8: jal         0x800CAE20
    // 0x800CA3AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_93;
    // 0x800CA3AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_93:
    // 0x800CA3B0: b           L_800CAC80
    // 0x800CA3B4: nop

        goto L_800CAC80;
    // 0x800CA3B4: nop

L_800CA3B8:
    // 0x800CA3B8: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CA3BC: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CA3C0: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800CA3C4: nop
    
            goto L_800CAC80;
    }
    // 0x800CA3C4: nop

    // 0x800CA3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA3CC: jal         0x800CAD98
    // 0x800CA3D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_94;
    // 0x800CA3D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_94:
    // 0x800CA3D4: jal         0x800CAD14
    // 0x800CA3D8: nop

    func_800CAD14(rdram, ctx);
        goto after_95;
    // 0x800CA3D8: nop

    after_95:
    // 0x800CA3DC: b           L_800CAC80
    // 0x800CA3E0: nop

        goto L_800CAC80;
    // 0x800CA3E0: nop

L_800CA3E4:
    // 0x800CA3E4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA3E8: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA3EC: bne         $t2, $zero, L_800CAC80
    if (ctx->r10 != 0) {
        // 0x800CA3F0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA3F0: nop

    // 0x800CA3F4: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA3F8: jal         0x800CAC94
    // 0x800CA3FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_96;
    // 0x800CA3FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_96:
    // 0x800CA400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA404: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA408: jal         0x800CAD20
    // 0x800CA40C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_800CAD20(rdram, ctx);
        goto after_97;
    // 0x800CA40C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_97:
    // 0x800CA410: b           L_800CAC80
    // 0x800CA414: nop

        goto L_800CAC80;
    // 0x800CA414: nop

L_800CA418:
    // 0x800CA418: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA41C: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA420: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA424: nop
    
            goto L_800CAC80;
    }
    // 0x800CA424: nop

    // 0x800CA428: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA42C: jal         0x800CAD98
    // 0x800CA430: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800CAD98(rdram, ctx);
        goto after_98;
    // 0x800CA430: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_98:
    // 0x800CA434: b           L_800CAC80
    // 0x800CA438: nop

        goto L_800CAC80;
    // 0x800CA438: nop

L_800CA43C:
    // 0x800CA43C: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CA440: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CA444: beq         $t4, $zero, L_800CAC80
    if (ctx->r12 == 0) {
        // 0x800CA448: nop
    
            goto L_800CAC80;
    }
    // 0x800CA448: nop

    // 0x800CA44C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA450: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA454: jal         0x800CAD20
    // 0x800CA458: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_99;
    // 0x800CA458: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_99:
    // 0x800CA45C: b           L_800CAC80
    // 0x800CA460: nop

        goto L_800CAC80;
    // 0x800CA460: nop

L_800CA464:
    // 0x800CA464: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CA468: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CA46C: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CA470: nop
    
            goto L_800CAC80;
    }
    // 0x800CA470: nop

    // 0x800CA474: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x800CA478: jal         0x800CAD98
    // 0x800CA47C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_800CAD98(rdram, ctx);
        goto after_100;
    // 0x800CA47C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_100:
    // 0x800CA480: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA484: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CA488: jal         0x800CAE20
    // 0x800CA48C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_101;
    // 0x800CA48C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_101:
    // 0x800CA490: b           L_800CAC80
    // 0x800CA494: nop

        goto L_800CAC80;
    // 0x800CA494: nop

L_800CA498:
    // 0x800CA498: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CA49C: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CA4A0: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CA4A4: nop
    
            goto L_800CAC80;
    }
    // 0x800CA4A4: nop

    // 0x800CA4A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA4AC: jal         0x800CAD98
    // 0x800CA4B0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_102;
    // 0x800CA4B0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_102:
    // 0x800CA4B4: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA4B8: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA4BC: jal         0x800CAE20
    // 0x800CA4C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_103;
    // 0x800CA4C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_103:
    // 0x800CA4C4: b           L_800CAC80
    // 0x800CA4C8: nop

        goto L_800CAC80;
    // 0x800CA4C8: nop

L_800CA4CC:
    // 0x800CA4CC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CA4D0: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CA4D4: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800CA4D8: nop
    
            goto L_800CAC80;
    }
    // 0x800CA4D8: nop

    // 0x800CA4DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA4E0: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA4E4: jal         0x800CAD20
    // 0x800CA4E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAD20(rdram, ctx);
        goto after_104;
    // 0x800CA4E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_104:
    // 0x800CA4EC: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CA4F0: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800CA4F4: jal         0x800CAE74
    // 0x800CA4F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE74(rdram, ctx);
        goto after_105;
    // 0x800CA4F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_105:
    // 0x800CA4FC: b           L_800CAC80
    // 0x800CA500: nop

        goto L_800CAC80;
    // 0x800CA500: nop

L_800CA504:
    // 0x800CA504: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CA508: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CA50C: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CA510: nop
    
            goto L_800CAC80;
    }
    // 0x800CA510: nop

    // 0x800CA514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA518: jal         0x800CAD98
    // 0x800CA51C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_106;
    // 0x800CA51C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_106:
    // 0x800CA520: jal         0x800CAD14
    // 0x800CA524: nop

    func_800CAD14(rdram, ctx);
        goto after_107;
    // 0x800CA524: nop

    after_107:
    // 0x800CA528: b           L_800CAC80
    // 0x800CA52C: nop

        goto L_800CAC80;
    // 0x800CA52C: nop

L_800CA530:
    // 0x800CA530: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CA534: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CA538: bne         $t9, $zero, L_800CAC80
    if (ctx->r25 != 0) {
        // 0x800CA53C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA53C: nop

    // 0x800CA540: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA544: jal         0x800CAC94
    // 0x800CA548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_108;
    // 0x800CA548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_108:
    // 0x800CA54C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA550: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA554: jal         0x800CAD20
    // 0x800CA558: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAD20(rdram, ctx);
        goto after_109;
    // 0x800CA558: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_109:
    // 0x800CA55C: b           L_800CAC80
    // 0x800CA560: nop

        goto L_800CAC80;
    // 0x800CA560: nop

L_800CA564:
    // 0x800CA564: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CA568: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CA56C: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800CA570: nop
    
            goto L_800CAC80;
    }
    // 0x800CA570: nop

    // 0x800CA574: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x800CA578: jal         0x800CAD98
    // 0x800CA57C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_800CAD98(rdram, ctx);
        goto after_110;
    // 0x800CA57C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_110:
    // 0x800CA580: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA584: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800CA588: jal         0x800CAE74
    // 0x800CA58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE74(rdram, ctx);
        goto after_111;
    // 0x800CA58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_111:
    // 0x800CA590: b           L_800CAC80
    // 0x800CA594: nop

        goto L_800CAC80;
    // 0x800CA594: nop

L_800CA598:
    // 0x800CA598: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CA59C: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CA5A0: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800CA5A4: nop
    
            goto L_800CAC80;
    }
    // 0x800CA5A4: nop

    // 0x800CA5A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA5AC: jal         0x800CAD98
    // 0x800CA5B0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800CAD98(rdram, ctx);
        goto after_112;
    // 0x800CA5B0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_112:
    // 0x800CA5B4: b           L_800CAC80
    // 0x800CA5B8: nop

        goto L_800CAC80;
    // 0x800CA5B8: nop

L_800CA5BC:
    // 0x800CA5BC: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA5C0: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA5C4: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800CA5C8: nop
    
            goto L_800CAC80;
    }
    // 0x800CA5C8: nop

    // 0x800CA5CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA5D0: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA5D4: jal         0x800CAD20
    // 0x800CA5D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_113;
    // 0x800CA5D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_113:
    // 0x800CA5DC: b           L_800CAC80
    // 0x800CA5E0: nop

        goto L_800CAC80;
    // 0x800CA5E0: nop

L_800CA5E4:
    // 0x800CA5E4: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA5E8: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA5EC: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA5F0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA5F0: nop

    // 0x800CA5F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA5F8: jal         0x800CAD98
    // 0x800CA5FC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_114;
    // 0x800CA5FC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_114:
    // 0x800CA600: jal         0x800CAD14
    // 0x800CA604: nop

    func_800CAD14(rdram, ctx);
        goto after_115;
    // 0x800CA604: nop

    after_115:
    // 0x800CA608: b           L_800CAC80
    // 0x800CA60C: nop

        goto L_800CAC80;
    // 0x800CA60C: nop

L_800CA610:
    // 0x800CA610: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CA614: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CA618: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800CA61C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA61C: nop

    // 0x800CA620: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA624: jal         0x800CAC94
    // 0x800CA628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_116;
    // 0x800CA628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_116:
    // 0x800CA62C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA630: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA634: jal         0x800CAD20
    // 0x800CA638: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_800CAD20(rdram, ctx);
        goto after_117;
    // 0x800CA638: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_117:
    // 0x800CA63C: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA640: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA644: jal         0x800CAE20
    // 0x800CA648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_118;
    // 0x800CA648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_118:
    // 0x800CA64C: b           L_800CAC80
    // 0x800CA650: nop

        goto L_800CAC80;
    // 0x800CA650: nop

L_800CA654:
    // 0x800CA654: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CA658: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CA65C: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CA660: nop
    
            goto L_800CAC80;
    }
    // 0x800CA660: nop

    // 0x800CA664: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA668: jal         0x800CAD98
    // 0x800CA66C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800CAD98(rdram, ctx);
        goto after_119;
    // 0x800CA66C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_119:
    // 0x800CA670: b           L_800CAC80
    // 0x800CA674: nop

        goto L_800CAC80;
    // 0x800CA674: nop

L_800CA678:
    // 0x800CA678: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CA67C: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CA680: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CA684: nop
    
            goto L_800CAC80;
    }
    // 0x800CA684: nop

    // 0x800CA688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA68C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x800CA690: jal         0x800CAD20
    // 0x800CA694: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_120;
    // 0x800CA694: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_120:
    // 0x800CA698: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CA69C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x800CA6A0: jal         0x800CAE20
    // 0x800CA6A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_121;
    // 0x800CA6A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_121:
    // 0x800CA6A8: b           L_800CAC80
    // 0x800CA6AC: nop

        goto L_800CAC80;
    // 0x800CA6AC: nop

L_800CA6B0:
    // 0x800CA6B0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CA6B4: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CA6B8: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800CA6BC: nop
    
            goto L_800CAC80;
    }
    // 0x800CA6BC: nop

    // 0x800CA6C0: addiu       $a0, $zero, 0x5DC
    ctx->r4 = ADD32(0, 0X5DC);
    // 0x800CA6C4: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA6C8: jal         0x800CAE74
    // 0x800CA6CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800CAE74(rdram, ctx);
        goto after_122;
    // 0x800CA6CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_122:
    // 0x800CA6D0: b           L_800CAC80
    // 0x800CA6D4: nop

        goto L_800CAC80;
    // 0x800CA6D4: nop

L_800CA6D8:
    // 0x800CA6D8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CA6DC: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CA6E0: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CA6E4: nop
    
            goto L_800CAC80;
    }
    // 0x800CA6E4: nop

    // 0x800CA6E8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA6EC: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA6F0: jal         0x800CAD20
    // 0x800CA6F4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_123;
    // 0x800CA6F4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_123:
    // 0x800CA6F8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CA6FC: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x800CA700: jal         0x800CAE20
    // 0x800CA704: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_124;
    // 0x800CA704: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_124:
    // 0x800CA708: b           L_800CAC80
    // 0x800CA70C: nop

        goto L_800CAC80;
    // 0x800CA70C: nop

L_800CA710:
    // 0x800CA710: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CA714: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CA718: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800CA71C: nop
    
            goto L_800CAC80;
    }
    // 0x800CA71C: nop

    // 0x800CA720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA724: jal         0x800CAD98
    // 0x800CA728: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800CAD98(rdram, ctx);
        goto after_125;
    // 0x800CA728: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_125:
    // 0x800CA72C: b           L_800CAC80
    // 0x800CA730: nop

        goto L_800CAC80;
    // 0x800CA730: nop

L_800CA734:
    // 0x800CA734: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CA738: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CA73C: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800CA740: nop
    
            goto L_800CAC80;
    }
    // 0x800CA740: nop

    // 0x800CA744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CA748: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800CA74C: jal         0x800CAD20
    // 0x800CA750: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_126;
    // 0x800CA750: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_126:
    // 0x800CA754: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA758: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA75C: jal         0x800CAE20
    // 0x800CA760: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_127;
    // 0x800CA760: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_127:
    // 0x800CA764: b           L_800CAC80
    // 0x800CA768: nop

        goto L_800CAC80;
    // 0x800CA768: nop

L_800CA76C:
    // 0x800CA76C: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CA770: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CA774: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800CA778: nop
    
            goto L_800CAC80;
    }
    // 0x800CA778: nop

    // 0x800CA77C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800CA780: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA784: jal         0x800CAD20
    // 0x800CA788: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800CAD20(rdram, ctx);
        goto after_128;
    // 0x800CA788: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_128:
    // 0x800CA78C: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CA790: addiu       $a1, $zero, 0x5AA
    ctx->r5 = ADD32(0, 0X5AA);
    // 0x800CA794: jal         0x800CAE20
    // 0x800CA798: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_129;
    // 0x800CA798: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_129:
    // 0x800CA79C: b           L_800CAC80
    // 0x800CA7A0: nop

        goto L_800CAC80;
    // 0x800CA7A0: nop

L_800CA7A4:
    // 0x800CA7A4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA7A8: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA7AC: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800CA7B0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA7B0: nop

    // 0x800CA7B4: addiu       $a0, $zero, 0x5AA
    ctx->r4 = ADD32(0, 0X5AA);
    // 0x800CA7B8: addiu       $a1, $zero, 0x60E
    ctx->r5 = ADD32(0, 0X60E);
    // 0x800CA7BC: jal         0x800CAE20
    // 0x800CA7C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800CAE20(rdram, ctx);
        goto after_130;
    // 0x800CA7C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_130:
    // 0x800CA7C4: b           L_800CAC80
    // 0x800CA7C8: nop

        goto L_800CAC80;
    // 0x800CA7C8: nop

L_800CA7CC:
    // 0x800CA7CC: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA7D0: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA7D4: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA7D8: nop
    
            goto L_800CAC80;
    }
    // 0x800CA7D8: nop

    // 0x800CA7DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA7E0: jal         0x800CAD98
    // 0x800CA7E4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_131;
    // 0x800CA7E4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_131:
    // 0x800CA7E8: jal         0x800CAD14
    // 0x800CA7EC: nop

    func_800CAD14(rdram, ctx);
        goto after_132;
    // 0x800CA7EC: nop

    after_132:
    // 0x800CA7F0: b           L_800CAC80
    // 0x800CA7F4: nop

        goto L_800CAC80;
    // 0x800CA7F4: nop

L_800CA7F8:
    // 0x800CA7F8: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CA7FC: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CA800: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800CA804: nop
    
            goto L_800CAC80;
    }
    // 0x800CA804: nop

    // 0x800CA808: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800CA80C: jal         0x800CAC94
    // 0x800CA810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_133;
    // 0x800CA810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_133:
    // 0x800CA814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA818: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA81C: jal         0x800CAD20
    // 0x800CA820: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_800CAD20(rdram, ctx);
        goto after_134;
    // 0x800CA820: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_134:
    // 0x800CA824: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800CA828: addiu       $a1, $zero, 0x41A
    ctx->r5 = ADD32(0, 0X41A);
    // 0x800CA82C: jal         0x800CAE20
    // 0x800CA830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_135;
    // 0x800CA830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_135:
    // 0x800CA834: b           L_800CAC80
    // 0x800CA838: nop

        goto L_800CAC80;
    // 0x800CA838: nop

L_800CA83C:
    // 0x800CA83C: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CA840: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CA844: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CA848: nop
    
            goto L_800CAC80;
    }
    // 0x800CA848: nop

    // 0x800CA84C: addiu       $a0, $zero, 0x41A
    ctx->r4 = ADD32(0, 0X41A);
    // 0x800CA850: addiu       $a1, $zero, 0x47E
    ctx->r5 = ADD32(0, 0X47E);
    // 0x800CA854: jal         0x800CAE20
    // 0x800CA858: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800CAE20(rdram, ctx);
        goto after_136;
    // 0x800CA858: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_136:
    // 0x800CA85C: b           L_800CAC80
    // 0x800CA860: nop

        goto L_800CAC80;
    // 0x800CA860: nop

L_800CA864:
    // 0x800CA864: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CA868: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CA86C: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CA870: nop
    
            goto L_800CAC80;
    }
    // 0x800CA870: nop

    // 0x800CA874: jal         0x800C8544
    // 0x800CA878: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_800C8544(rdram, ctx);
        goto after_137;
    // 0x800CA878: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_137:
    // 0x800CA87C: addiu       $a0, $zero, 0x47E
    ctx->r4 = ADD32(0, 0X47E);
    // 0x800CA880: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CA884: jal         0x800CAE20
    // 0x800CA888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_138;
    // 0x800CA888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_138:
    // 0x800CA88C: b           L_800CAC80
    // 0x800CA890: nop

        goto L_800CAC80;
    // 0x800CA890: nop

L_800CA894:
    // 0x800CA894: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CA898: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CA89C: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800CA8A0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA8A0: nop

    // 0x800CA8A4: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA8A8: addiu       $a1, $zero, 0x546
    ctx->r5 = ADD32(0, 0X546);
    // 0x800CA8AC: jal         0x800CAE20
    // 0x800CA8B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_139;
    // 0x800CA8B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_139:
    // 0x800CA8B4: b           L_800CAC80
    // 0x800CA8B8: nop

        goto L_800CAC80;
    // 0x800CA8B8: nop

L_800CA8BC:
    // 0x800CA8BC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CA8C0: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CA8C4: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CA8C8: nop
    
            goto L_800CAC80;
    }
    // 0x800CA8C8: nop

    // 0x800CA8CC: addiu       $a0, $zero, 0x546
    ctx->r4 = ADD32(0, 0X546);
    // 0x800CA8D0: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CA8D4: jal         0x800CAE74
    // 0x800CA8D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE74(rdram, ctx);
        goto after_140;
    // 0x800CA8D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_140:
    // 0x800CA8DC: b           L_800CAC80
    // 0x800CA8E0: nop

        goto L_800CAC80;
    // 0x800CA8E0: nop

L_800CA8E4:
    // 0x800CA8E4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CA8E8: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CA8EC: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800CA8F0: nop
    
            goto L_800CAC80;
    }
    // 0x800CA8F0: nop

    // 0x800CA8F4: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA8F8: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CA8FC: jal         0x800CAE20
    // 0x800CA900: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_141;
    // 0x800CA900: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_141:
    // 0x800CA904: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800CA908: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA90C: jal         0x800CAD20
    // 0x800CA910: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800CAD20(rdram, ctx);
        goto after_142;
    // 0x800CA910: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_142:
    // 0x800CA914: b           L_800CAC80
    // 0x800CA918: nop

        goto L_800CAC80;
    // 0x800CA918: nop

L_800CA91C:
    // 0x800CA91C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CA920: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CA924: beq         $t0, $zero, L_800CAC80
    if (ctx->r8 == 0) {
        // 0x800CA928: nop
    
            goto L_800CAC80;
    }
    // 0x800CA928: nop

    // 0x800CA92C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA930: jal         0x800CAD98
    // 0x800CA934: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_143;
    // 0x800CA934: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_143:
    // 0x800CA938: jal         0x800CAD14
    // 0x800CA93C: nop

    func_800CAD14(rdram, ctx);
        goto after_144;
    // 0x800CA93C: nop

    after_144:
    // 0x800CA940: b           L_800CAC80
    // 0x800CA944: nop

        goto L_800CAC80;
    // 0x800CA944: nop

L_800CA948:
    // 0x800CA948: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CA94C: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CA950: bne         $t1, $zero, L_800CAC80
    if (ctx->r9 != 0) {
        // 0x800CA954: nop
    
            goto L_800CAC80;
    }
    // 0x800CA954: nop

    // 0x800CA958: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA95C: jal         0x800CAC94
    // 0x800CA960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_145;
    // 0x800CA960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_145:
    // 0x800CA964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CA968: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CA96C: jal         0x800CAD20
    // 0x800CA970: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CAD20(rdram, ctx);
        goto after_146;
    // 0x800CA970: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_146:
    // 0x800CA974: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CA978: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CA97C: jal         0x800CAE20
    // 0x800CA980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_147;
    // 0x800CA980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_147:
    // 0x800CA984: b           L_800CAC80
    // 0x800CA988: nop

        goto L_800CAC80;
    // 0x800CA988: nop

L_800CA98C:
    // 0x800CA98C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CA990: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CA994: beq         $t2, $zero, L_800CAC80
    if (ctx->r10 == 0) {
        // 0x800CA998: nop
    
            goto L_800CAC80;
    }
    // 0x800CA998: nop

    // 0x800CA99C: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CA9A0: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x800CA9A4: jal         0x800CAE20
    // 0x800CA9A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_148;
    // 0x800CA9A8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_148:
    // 0x800CA9AC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800CA9B0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA9B4: jal         0x800CAD20
    // 0x800CA9B8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_800CAD20(rdram, ctx);
        goto after_149;
    // 0x800CA9B8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_149:
    // 0x800CA9BC: b           L_800CAC80
    // 0x800CA9C0: nop

        goto L_800CAC80;
    // 0x800CA9C0: nop

L_800CA9C4:
    // 0x800CA9C4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA9C8: jal         0x800CAD98
    // 0x800CA9CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800CAD98(rdram, ctx);
        goto after_150;
    // 0x800CA9CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_150:
    // 0x800CA9D0: b           L_800CAC80
    // 0x800CA9D4: nop

        goto L_800CAC80;
    // 0x800CA9D4: nop

L_800CA9D8:
    // 0x800CA9D8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CA9DC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CA9E0: jal         0x800CAD20
    // 0x800CA9E4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_151;
    // 0x800CA9E4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_151:
    // 0x800CA9E8: b           L_800CAC80
    // 0x800CA9EC: nop

        goto L_800CAC80;
    // 0x800CA9EC: nop

L_800CA9F0:
    // 0x800CA9F0: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CA9F4: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CA9F8: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CA9FC: nop
    
            goto L_800CAC80;
    }
    // 0x800CA9FC: nop

    // 0x800CAA00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CAA04: jal         0x800CAD98
    // 0x800CAA08: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_152;
    // 0x800CAA08: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_152:
    // 0x800CAA0C: jal         0x800CAD14
    // 0x800CAA10: nop

    func_800CAD14(rdram, ctx);
        goto after_153;
    // 0x800CAA10: nop

    after_153:
    // 0x800CAA14: b           L_800CAC80
    // 0x800CAA18: nop

        goto L_800CAC80;
    // 0x800CAA18: nop

L_800CAA1C:
    // 0x800CAA1C: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CAA20: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CAA24: bne         $t4, $zero, L_800CAC80
    if (ctx->r12 != 0) {
        // 0x800CAA28: nop
    
            goto L_800CAC80;
    }
    // 0x800CAA28: nop

    // 0x800CAA2C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CAA30: jal         0x800CAC94
    // 0x800CAA34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_154;
    // 0x800CAA34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_154:
    // 0x800CAA38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CAA3C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CAA40: jal         0x800CAD20
    // 0x800CAA44: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800CAD20(rdram, ctx);
        goto after_155;
    // 0x800CAA44: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_155:
    // 0x800CAA48: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CAA4C: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CAA50: jal         0x800CAE20
    // 0x800CAA54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_156;
    // 0x800CAA54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_156:
    // 0x800CAA58: b           L_800CAC80
    // 0x800CAA5C: nop

        goto L_800CAC80;
    // 0x800CAA5C: nop

L_800CAA60:
    // 0x800CAA60: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x800CAA64: jal         0x800CAD98
    // 0x800CAA68: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_800CAD98(rdram, ctx);
        goto after_157;
    // 0x800CAA68: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_157:
    // 0x800CAA6C: b           L_800CAC80
    // 0x800CAA70: nop

        goto L_800CAC80;
    // 0x800CAA70: nop

L_800CAA74:
    // 0x800CAA74: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CAA78: lw          $t5, -0x5320($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5320);
    // 0x800CAA7C: beq         $t5, $zero, L_800CAC80
    if (ctx->r13 == 0) {
        // 0x800CAA80: nop
    
            goto L_800CAC80;
    }
    // 0x800CAA80: nop

    // 0x800CAA84: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CAA88: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    // 0x800CAA8C: jal         0x800CAE74
    // 0x800CAA90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE74(rdram, ctx);
        goto after_158;
    // 0x800CAA90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_158:
    // 0x800CAA94: b           L_800CAC80
    // 0x800CAA98: nop

        goto L_800CAC80;
    // 0x800CAA98: nop

L_800CAA9C:
    // 0x800CAA9C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CAAA0: lw          $t6, -0x5320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5320);
    // 0x800CAAA4: beq         $t6, $zero, L_800CAC80
    if (ctx->r14 == 0) {
        // 0x800CAAA8: nop
    
            goto L_800CAC80;
    }
    // 0x800CAAA8: nop

    // 0x800CAAAC: addiu       $a0, $zero, 0x4E2
    ctx->r4 = ADD32(0, 0X4E2);
    // 0x800CAAB0: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CAAB4: jal         0x800CAE20
    // 0x800CAAB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE20(rdram, ctx);
        goto after_159;
    // 0x800CAAB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_159:
    // 0x800CAABC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CAAC0: jal         0x800CAD98
    // 0x800CAAC4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_160;
    // 0x800CAAC4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_160:
    // 0x800CAAC8: b           L_800CAC80
    // 0x800CAACC: nop

        goto L_800CAC80;
    // 0x800CAACC: nop

L_800CAAD0:
    // 0x800CAAD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CAAD4: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CAAD8: jal         0x800CAD20
    // 0x800CAADC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_161;
    // 0x800CAADC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_161:
    // 0x800CAAE0: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CAAE4: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CAAE8: jal         0x800CAE74
    // 0x800CAAEC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800CAE74(rdram, ctx);
        goto after_162;
    // 0x800CAAEC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_162:
    // 0x800CAAF0: b           L_800CAC80
    // 0x800CAAF4: nop

        goto L_800CAC80;
    // 0x800CAAF4: nop

L_800CAAF8:
    // 0x800CAAF8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CAAFC: lw          $t7, -0x5320($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5320);
    // 0x800CAB00: beq         $t7, $zero, L_800CAC80
    if (ctx->r15 == 0) {
        // 0x800CAB04: nop
    
            goto L_800CAC80;
    }
    // 0x800CAB04: nop

    // 0x800CAB08: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CAB0C: addiu       $a1, $zero, 0x578
    ctx->r5 = ADD32(0, 0X578);
    // 0x800CAB10: jal         0x800CAE20
    // 0x800CAB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_163;
    // 0x800CAB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_163:
    // 0x800CAB18: b           L_800CAC80
    // 0x800CAB1C: nop

        goto L_800CAC80;
    // 0x800CAB1C: nop

L_800CAB20:
    // 0x800CAB20: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CAB24: lw          $t8, -0x5320($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5320);
    // 0x800CAB28: beq         $t8, $zero, L_800CAC80
    if (ctx->r24 == 0) {
        // 0x800CAB2C: nop
    
            goto L_800CAC80;
    }
    // 0x800CAB2C: nop

    // 0x800CAB30: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CAB34: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CAB38: jal         0x800CAE74
    // 0x800CAB3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800CAE74(rdram, ctx);
        goto after_164;
    // 0x800CAB3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_164:
    // 0x800CAB40: b           L_800CAC80
    // 0x800CAB44: nop

        goto L_800CAC80;
    // 0x800CAB44: nop

L_800CAB48:
    // 0x800CAB48: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CAB4C: lw          $t9, -0x5320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5320);
    // 0x800CAB50: beq         $t9, $zero, L_800CAC80
    if (ctx->r25 == 0) {
        // 0x800CAB54: nop
    
            goto L_800CAC80;
    }
    // 0x800CAB54: nop

    // 0x800CAB58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CAB5C: jal         0x800CAD98
    // 0x800CAB60: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_165;
    // 0x800CAB60: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_165:
    // 0x800CAB64: jal         0x800CAD14
    // 0x800CAB68: nop

    func_800CAD14(rdram, ctx);
        goto after_166;
    // 0x800CAB68: nop

    after_166:
    // 0x800CAB6C: b           L_800CAC80
    // 0x800CAB70: nop

        goto L_800CAC80;
    // 0x800CAB70: nop

L_800CAB74:
    // 0x800CAB74: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CAB78: lw          $t0, -0x5320($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5320);
    // 0x800CAB7C: bne         $t0, $zero, L_800CAC80
    if (ctx->r8 != 0) {
        // 0x800CAB80: nop
    
            goto L_800CAC80;
    }
    // 0x800CAB80: nop

    // 0x800CAB84: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CAB88: jal         0x800CAC94
    // 0x800CAB8C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800CAC94(rdram, ctx);
        goto after_167;
    // 0x800CAB8C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_167:
    // 0x800CAB90: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x800CAB94: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x800CAB98: jal         0x800CAE20
    // 0x800CAB9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_168;
    // 0x800CAB9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_168:
    // 0x800CABA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CABA4: jal         0x800CAD98
    // 0x800CABA8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_800CAD98(rdram, ctx);
        goto after_169;
    // 0x800CABA8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_169:
    // 0x800CABAC: b           L_800CAC80
    // 0x800CABB0: nop

        goto L_800CAC80;
    // 0x800CABB0: nop

L_800CABB4:
    // 0x800CABB4: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CABB8: lw          $t1, -0x5320($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5320);
    // 0x800CABBC: beq         $t1, $zero, L_800CAC80
    if (ctx->r9 == 0) {
        // 0x800CABC0: nop
    
            goto L_800CAC80;
    }
    // 0x800CABC0: nop

    // 0x800CABC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CABC8: jal         0x800CAD98
    // 0x800CABCC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_170;
    // 0x800CABCC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_170:
    // 0x800CABD0: jal         0x800CAD14
    // 0x800CABD4: nop

    func_800CAD14(rdram, ctx);
        goto after_171;
    // 0x800CABD4: nop

    after_171:
    // 0x800CABD8: b           L_800CAC80
    // 0x800CABDC: nop

        goto L_800CAC80;
    // 0x800CABDC: nop

L_800CABE0:
    // 0x800CABE0: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CABE4: lw          $t2, -0x5320($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5320);
    // 0x800CABE8: bne         $t2, $zero, L_800CAC80
    if (ctx->r10 != 0) {
        // 0x800CABEC: nop
    
            goto L_800CAC80;
    }
    // 0x800CABEC: nop

    // 0x800CABF0: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CABF4: jal         0x800CAC94
    // 0x800CABF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CAC94(rdram, ctx);
        goto after_172;
    // 0x800CABF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_172:
    // 0x800CABFC: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    // 0x800CAC00: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    // 0x800CAC04: jal         0x800CAE74
    // 0x800CAC08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE74(rdram, ctx);
        goto after_173;
    // 0x800CAC08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_173:
    // 0x800CAC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CAC10: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x800CAC14: jal         0x800CAD20
    // 0x800CAC18: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_174;
    // 0x800CAC18: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_174:
    // 0x800CAC1C: b           L_800CAC80
    // 0x800CAC20: nop

        goto L_800CAC80;
    // 0x800CAC20: nop

L_800CAC24:
    // 0x800CAC24: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CAC28: lw          $t3, -0x5320($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5320);
    // 0x800CAC2C: beq         $t3, $zero, L_800CAC80
    if (ctx->r11 == 0) {
        // 0x800CAC30: nop
    
            goto L_800CAC80;
    }
    // 0x800CAC30: nop

    // 0x800CAC34: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x800CAC38: addiu       $a1, $zero, 0x514
    ctx->r5 = ADD32(0, 0X514);
    // 0x800CAC3C: jal         0x800CAE20
    // 0x800CAC40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CAE20(rdram, ctx);
        goto after_175;
    // 0x800CAC40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_175:
    // 0x800CAC44: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800CAC48: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800CAC4C: jal         0x800CAD20
    // 0x800CAC50: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CAD20(rdram, ctx);
        goto after_176;
    // 0x800CAC50: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_176:
    // 0x800CAC54: b           L_800CAC80
    // 0x800CAC58: nop

        goto L_800CAC80;
    // 0x800CAC58: nop

L_800CAC5C:
    // 0x800CAC5C: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800CAC60: lw          $t4, -0x5320($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5320);
    // 0x800CAC64: beq         $t4, $zero, L_800CAC80
    if (ctx->r12 == 0) {
        // 0x800CAC68: nop
    
            goto L_800CAC80;
    }
    // 0x800CAC68: nop

    // 0x800CAC6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CAC70: jal         0x800CAD98
    // 0x800CAC74: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_800CAD98(rdram, ctx);
        goto after_177;
    // 0x800CAC74: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_177:
    // 0x800CAC78: jal         0x800CAD14
    // 0x800CAC7C: nop

    func_800CAD14(rdram, ctx);
        goto after_178;
    // 0x800CAC7C: nop

    after_178:
L_800CAC80:
    // 0x800CAC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CAC88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CAC8C: jr          $ra
    // 0x800CAC90: nop

    return;
    // 0x800CAC90: nop

;}
RECOMP_FUNC void func_800CAC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CAC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CAC9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CACA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CACA4: jal         0x800C8544
    // 0x800CACA8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x800CACA8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x800CACAC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CACB0: sw          $v0, -0x6ABC($at)
    MEM_W(-0X6ABC, ctx->r1) = ctx->r2;
    // 0x800CACB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CACB8: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CACBC: jal         0x800CF5B8
    // 0x800CACC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800CF5B8(rdram, ctx);
        goto after_1;
    // 0x800CACC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800CACC4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CACC8: lui         $at, 0x44B4
    ctx->r1 = S32(0X44B4 << 16);
    // 0x800CACCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CACD0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CACD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CACD8: lwc1        $f16, -0x21D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X21D8);
    // 0x800CACDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CACE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CACE4: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CACE8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CACEC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CACF0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800CACF4: jal         0x800CF688
    // 0x800CACF8: nop

    func_800CF688(rdram, ctx);
        goto after_2;
    // 0x800CACF8: nop

    after_2:
    // 0x800CACFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CAD00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CAD04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAD08: sw          $t7, -0x5320($at)
    MEM_W(-0X5320, ctx->r1) = ctx->r15;
    // 0x800CAD0C: jr          $ra
    // 0x800CAD10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CAD10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CAD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAD18: jr          $ra
    // 0x800CAD1C: sw          $zero, -0x5320($at)
    MEM_W(-0X5320, ctx->r1) = 0;
    return;
    // 0x800CAD1C: sw          $zero, -0x5320($at)
    MEM_W(-0X5320, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800CAD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD20: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800CAD24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAD28: sw          $t6, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = ctx->r14;
    // 0x800CAD2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAD30: sw          $a1, -0x6AE0($at)
    MEM_W(-0X6AE0, ctx->r1) = ctx->r5;
    // 0x800CAD34: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CAD38: lw          $t7, -0x6AE0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AE0);
    // 0x800CAD3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAD40: sw          $a0, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r4;
    // 0x800CAD44: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x800CAD48: bne         $a2, $zero, L_800CAD54
    if (ctx->r6 != 0) {
        // 0x800CAD4C: nop
    
            goto L_800CAD54;
    }
    // 0x800CAD4C: nop

    // 0x800CAD50: break       7
    do_break(2148314448);
L_800CAD54:
    // 0x800CAD54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CAD58: bne         $a2, $at, L_800CAD6C
    if (ctx->r6 != ctx->r1) {
        // 0x800CAD5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CAD6C;
    }
    // 0x800CAD5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CAD60: bne         $t7, $at, L_800CAD6C
    if (ctx->r15 != ctx->r1) {
        // 0x800CAD64: nop
    
            goto L_800CAD6C;
    }
    // 0x800CAD64: nop

    // 0x800CAD68: break       6
    do_break(2148314472);
L_800CAD6C:
    // 0x800CAD6C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAD70: mflo        $t8
    ctx->r24 = lo;
    // 0x800CAD74: sw          $t8, -0x6AE4($at)
    MEM_W(-0X6AE4, ctx->r1) = ctx->r24;
    // 0x800CAD78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAD7C: bgtz        $t8, L_800CAD90
    if (SIGNED(ctx->r24) > 0) {
        // 0x800CAD80: sw          $t7, -0x6AE8($at)
        MEM_W(-0X6AE8, ctx->r1) = ctx->r15;
            goto L_800CAD90;
    }
    // 0x800CAD80: sw          $t7, -0x6AE8($at)
    MEM_W(-0X6AE8, ctx->r1) = ctx->r15;
    // 0x800CAD84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CAD88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAD8C: sw          $t9, -0x6AE4($at)
    MEM_W(-0X6AE4, ctx->r1) = ctx->r25;
L_800CAD90:
    // 0x800CAD90: jr          $ra
    // 0x800CAD94: nop

    return;
    // 0x800CAD94: nop

;}
RECOMP_FUNC void func_800CAD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD98: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CAD9C: lw          $t7, -0x6AE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AE8);
    // 0x800CADA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CADA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CADA8: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x800CADAC: sw          $t6, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = ctx->r14;
    // 0x800CADB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CADB4: sw          $a0, -0x6AE0($at)
    MEM_W(-0X6AE0, ctx->r1) = ctx->r4;
    // 0x800CADB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CADBC: sw          $t7, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r15;
    // 0x800CADC0: bne         $a1, $zero, L_800CADCC
    if (ctx->r5 != 0) {
        // 0x800CADC4: nop
    
            goto L_800CADCC;
    }
    // 0x800CADC4: nop

    // 0x800CADC8: break       7
    do_break(2148314568);
L_800CADCC:
    // 0x800CADCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CADD0: bne         $a1, $at, L_800CADE4
    if (ctx->r5 != ctx->r1) {
        // 0x800CADD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CADE4;
    }
    // 0x800CADD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CADD8: bne         $t7, $at, L_800CADE4
    if (ctx->r15 != ctx->r1) {
        // 0x800CADDC: nop
    
            goto L_800CADE4;
    }
    // 0x800CADDC: nop

    // 0x800CADE0: break       6
    do_break(2148314592);
L_800CADE4:
    // 0x800CADE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CADE8: mflo        $t8
    ctx->r24 = lo;
    // 0x800CADEC: sw          $t8, -0x6AE4($at)
    MEM_W(-0X6AE4, ctx->r1) = ctx->r24;
    // 0x800CADF0: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800CADF4: lw          $t0, -0x6AE4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6AE4);
    // 0x800CADF8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CADFC: lw          $t9, -0x6AE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6AE0);
    // 0x800CAE00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE04: bgtz        $t0, L_800CAE18
    if (SIGNED(ctx->r8) > 0) {
        // 0x800CAE08: sw          $t9, -0x6AE8($at)
        MEM_W(-0X6AE8, ctx->r1) = ctx->r25;
            goto L_800CAE18;
    }
    // 0x800CAE08: sw          $t9, -0x6AE8($at)
    MEM_W(-0X6AE8, ctx->r1) = ctx->r25;
    // 0x800CAE0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CAE10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE14: sw          $t1, -0x6AE4($at)
    MEM_W(-0X6AE4, ctx->r1) = ctx->r9;
L_800CAE18:
    // 0x800CAE18: jr          $ra
    // 0x800CAE1C: nop

    return;
    // 0x800CAE1C: nop

;}
RECOMP_FUNC void func_800CAE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAE20: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800CAE24: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAE28: sw          $t6, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = ctx->r14;
    // 0x800CAE2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE30: sw          $a1, -0x6AD0($at)
    MEM_W(-0X6AD0, ctx->r1) = ctx->r5;
    // 0x800CAE34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE38: sw          $a0, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r4;
    // 0x800CAE3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE40: sw          $a2, -0x6AD4($at)
    MEM_W(-0X6AD4, ctx->r1) = ctx->r6;
    // 0x800CAE44: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800CAE48: lw          $t8, -0x6AD4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6AD4);
    // 0x800CAE4C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CAE50: lw          $t7, -0x6AD0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AD0);
    // 0x800CAE54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE58: bgtz        $t8, L_800CAE6C
    if (SIGNED(ctx->r24) > 0) {
        // 0x800CAE5C: sw          $t7, -0x6AD8($at)
        MEM_W(-0X6AD8, ctx->r1) = ctx->r15;
            goto L_800CAE6C;
    }
    // 0x800CAE5C: sw          $t7, -0x6AD8($at)
    MEM_W(-0X6AD8, ctx->r1) = ctx->r15;
    // 0x800CAE60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CAE64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE68: sw          $t9, -0x6AD4($at)
    MEM_W(-0X6AD4, ctx->r1) = ctx->r25;
L_800CAE6C:
    // 0x800CAE6C: jr          $ra
    // 0x800CAE70: nop

    return;
    // 0x800CAE70: nop

;}
RECOMP_FUNC void func_800CAE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAE74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CAE78: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAE7C: sw          $t6, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = ctx->r14;
    // 0x800CAE80: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE84: sw          $a1, -0x6AD0($at)
    MEM_W(-0X6AD0, ctx->r1) = ctx->r5;
    // 0x800CAE88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE8C: sw          $a0, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r4;
    // 0x800CAE90: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAE94: sw          $a2, -0x6AD4($at)
    MEM_W(-0X6AD4, ctx->r1) = ctx->r6;
    // 0x800CAE98: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CAE9C: lw          $t7, -0x6AD4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6AD4);
    // 0x800CAEA0: bgtz        $t7, L_800CAEB4
    if (SIGNED(ctx->r15) > 0) {
        // 0x800CAEA4: nop
    
            goto L_800CAEB4;
    }
    // 0x800CAEA4: nop

    // 0x800CAEA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CAEAC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAEB0: sw          $t8, -0x6AD4($at)
    MEM_W(-0X6AD4, ctx->r1) = ctx->r24;
L_800CAEB4:
    // 0x800CAEB4: jr          $ra
    // 0x800CAEB8: nop

    return;
    // 0x800CAEB8: nop

;}
RECOMP_FUNC void func_800CAEBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAEBC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CAEC0: lw          $t6, -0x7940($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7940);
    // 0x800CAEC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CAEC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAECC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800CAED0: bne         $t7, $zero, L_800CB220
    if (ctx->r15 != 0) {
        // 0x800CAED4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800CB220;
    }
    // 0x800CAED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CAED8: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800CAEDC: lw          $s0, -0x531C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X531C);
    // 0x800CAEE0: beq         $s0, $zero, L_800CAFE0
    if (ctx->r16 == 0) {
        // 0x800CAEE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CAFE0;
    }
    // 0x800CAEE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CAEE8: beq         $s0, $at, L_800CAF00
    if (ctx->r16 == ctx->r1) {
        // 0x800CAEEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CAF00;
    }
    // 0x800CAEEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CAEF0: beq         $s0, $at, L_800CAF7C
    if (ctx->r16 == ctx->r1) {
        // 0x800CAEF4: nop
    
            goto L_800CAF7C;
    }
    // 0x800CAEF4: nop

    // 0x800CAEF8: b           L_800CAFE0
    // 0x800CAEFC: nop

        goto L_800CAFE0;
    // 0x800CAEFC: nop

L_800CAF00:
    // 0x800CAF00: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800CAF04: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CAF08: lw          $t9, -0x6AE4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6AE4);
    // 0x800CAF0C: lw          $t8, -0x6AEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6AEC);
    // 0x800CAF10: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800CAF14: lw          $t1, -0x6AE0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6AE0);
    // 0x800CAF18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAF1C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CAF20: sw          $t0, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r8;
    // 0x800CAF24: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CAF28: bne         $at, $zero, L_800CAF4C
    if (ctx->r1 != 0) {
        // 0x800CAF2C: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CAF4C;
    }
    // 0x800CAF2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAF30: sw          $t1, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r9;
    // 0x800CAF34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAF38: bne         $t1, $zero, L_800CAF4C
    if (ctx->r9 != 0) {
        // 0x800CAF3C: sw          $zero, -0x531C($at)
        MEM_W(-0X531C, ctx->r1) = 0;
            goto L_800CAF4C;
    }
    // 0x800CAF3C: sw          $zero, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = 0;
    // 0x800CAF40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CAF44: jal         0x800C8124
    // 0x800CAF48: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    func_800C8124(rdram, ctx);
        goto after_0;
    // 0x800CAF48: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    after_0:
L_800CAF4C:
    // 0x800CAF4C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800CAF50: lw          $a1, -0x6AEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6AEC);
    // 0x800CAF54: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CAF58: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CAF5C: bgez        $a1, L_800CAF6C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800CAF60: sra         $t2, $a1, 1
        ctx->r10 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800CAF6C;
    }
    // 0x800CAF60: sra         $t2, $a1, 1
    ctx->r10 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800CAF64: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800CAF68: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800CAF6C:
    // 0x800CAF6C: jal         0x800CF5B8
    // 0x800CAF70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_800CF5B8(rdram, ctx);
        goto after_1;
    // 0x800CAF70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_1:
    // 0x800CAF74: b           L_800CAFE0
    // 0x800CAF78: nop

        goto L_800CAFE0;
    // 0x800CAF78: nop

L_800CAF7C:
    // 0x800CAF7C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800CAF80: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800CAF84: lw          $t4, -0x6AE4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6AE4);
    // 0x800CAF88: lw          $t3, -0x6AEC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6AEC);
    // 0x800CAF8C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CAF90: lw          $t6, -0x6AE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AE0);
    // 0x800CAF94: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAF98: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CAF9C: sw          $t5, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r13;
    // 0x800CAFA0: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800CAFA4: bne         $at, $zero, L_800CAFB8
    if (ctx->r1 != 0) {
        // 0x800CAFA8: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CAFB8;
    }
    // 0x800CAFA8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CAFAC: sw          $t6, -0x6AEC($at)
    MEM_W(-0X6AEC, ctx->r1) = ctx->r14;
    // 0x800CAFB0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CAFB4: sw          $zero, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = 0;
L_800CAFB8:
    // 0x800CAFB8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800CAFBC: lw          $a1, -0x6AEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6AEC);
    // 0x800CAFC0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CAFC4: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CAFC8: bgez        $a1, L_800CAFD8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800CAFCC: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800CAFD8;
    }
    // 0x800CAFCC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800CAFD0: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800CAFD4: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800CAFD8:
    // 0x800CAFD8: jal         0x800CF5B8
    // 0x800CAFDC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800CF5B8(rdram, ctx);
        goto after_2;
    // 0x800CAFDC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_2:
L_800CAFE0:
    // 0x800CAFE0: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800CAFE4: lw          $s0, -0x5318($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5318);
    // 0x800CAFE8: beq         $s0, $zero, L_800CB100
    if (ctx->r16 == 0) {
        // 0x800CAFEC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CB100;
    }
    // 0x800CAFEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CAFF0: beq         $s0, $at, L_800CB008
    if (ctx->r16 == ctx->r1) {
        // 0x800CAFF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CB008;
    }
    // 0x800CAFF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CAFF8: beq         $s0, $at, L_800CB088
    if (ctx->r16 == ctx->r1) {
        // 0x800CAFFC: nop
    
            goto L_800CB088;
    }
    // 0x800CAFFC: nop

    // 0x800CB000: b           L_800CB100
    // 0x800CB004: nop

        goto L_800CB100;
    // 0x800CB004: nop

L_800CB008:
    // 0x800CB008: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800CB00C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CB010: lw          $t9, -0x6AD4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6AD4);
    // 0x800CB014: lw          $t8, -0x6ADC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6ADC);
    // 0x800CB018: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800CB01C: lw          $t1, -0x6AD0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6AD0);
    // 0x800CB020: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB024: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CB028: sw          $t0, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r8;
    // 0x800CB02C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CB030: bne         $at, $zero, L_800CB044
    if (ctx->r1 != 0) {
        // 0x800CB034: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CB044;
    }
    // 0x800CB034: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB038: sw          $t1, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r9;
    // 0x800CB03C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB040: sw          $zero, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = 0;
L_800CB044:
    // 0x800CB044: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800CB048: lw          $t2, -0x6ADC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6ADC);
    // 0x800CB04C: lui         $at, 0x44B4
    ctx->r1 = S32(0X44B4 << 16);
    // 0x800CB050: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CB054: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800CB058: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB05C: lwc1        $f16, -0x21D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X21D4);
    // 0x800CB060: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CB064: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB068: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CB06C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CB070: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CB074: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800CB078: jal         0x800CF688
    // 0x800CB07C: nop

    func_800CF688(rdram, ctx);
        goto after_3;
    // 0x800CB07C: nop

    after_3:
    // 0x800CB080: b           L_800CB100
    // 0x800CB084: nop

        goto L_800CB100;
    // 0x800CB084: nop

L_800CB088:
    // 0x800CB088: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800CB08C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800CB090: lw          $t4, -0x6AD4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6AD4);
    // 0x800CB094: lw          $t3, -0x6ADC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6ADC);
    // 0x800CB098: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CB09C: lw          $t6, -0x6AD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AD0);
    // 0x800CB0A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB0A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CB0A8: sw          $t5, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r13;
    // 0x800CB0AC: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800CB0B0: bne         $at, $zero, L_800CB0C4
    if (ctx->r1 != 0) {
        // 0x800CB0B4: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CB0C4;
    }
    // 0x800CB0B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB0B8: sw          $t6, -0x6ADC($at)
    MEM_W(-0X6ADC, ctx->r1) = ctx->r14;
    // 0x800CB0BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB0C0: sw          $zero, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = 0;
L_800CB0C4:
    // 0x800CB0C4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CB0C8: lw          $t7, -0x6ADC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6ADC);
    // 0x800CB0CC: lui         $at, 0x44B4
    ctx->r1 = S32(0X44B4 << 16);
    // 0x800CB0D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CB0D4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800CB0D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB0DC: lwc1        $f16, -0x21D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X21D0);
    // 0x800CB0E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CB0E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB0E8: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CB0EC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CB0F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CB0F4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800CB0F8: jal         0x800CF688
    // 0x800CB0FC: nop

    func_800CF688(rdram, ctx);
        goto after_4;
    // 0x800CB0FC: nop

    after_4:
L_800CB100:
    // 0x800CB100: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x800CB104: lw          $s0, -0x5314($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5314);
    // 0x800CB108: beq         $s0, $zero, L_800CB220
    if (ctx->r16 == 0) {
        // 0x800CB10C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CB220;
    }
    // 0x800CB10C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB110: beq         $s0, $at, L_800CB128
    if (ctx->r16 == ctx->r1) {
        // 0x800CB114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CB128;
    }
    // 0x800CB114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CB118: beq         $s0, $at, L_800CB1A8
    if (ctx->r16 == ctx->r1) {
        // 0x800CB11C: nop
    
            goto L_800CB1A8;
    }
    // 0x800CB11C: nop

    // 0x800CB120: b           L_800CB220
    // 0x800CB124: nop

        goto L_800CB220;
    // 0x800CB124: nop

L_800CB128:
    // 0x800CB128: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800CB12C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CB130: lw          $t9, -0x6AC4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6AC4);
    // 0x800CB134: lw          $t8, -0x6ACC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6ACC);
    // 0x800CB138: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800CB13C: lw          $t1, -0x6AC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6AC0);
    // 0x800CB140: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB144: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CB148: sw          $t0, -0x6ACC($at)
    MEM_W(-0X6ACC, ctx->r1) = ctx->r8;
    // 0x800CB14C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CB150: bne         $at, $zero, L_800CB164
    if (ctx->r1 != 0) {
        // 0x800CB154: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CB164;
    }
    // 0x800CB154: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB158: sw          $t1, -0x6ACC($at)
    MEM_W(-0X6ACC, ctx->r1) = ctx->r9;
    // 0x800CB15C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB160: sw          $zero, -0x5314($at)
    MEM_W(-0X5314, ctx->r1) = 0;
L_800CB164:
    // 0x800CB164: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800CB168: lw          $t2, -0x6B38($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6B38);
    // 0x800CB16C: bne         $t2, $zero, L_800CB18C
    if (ctx->r10 != 0) {
        // 0x800CB170: nop
    
            goto L_800CB18C;
    }
    // 0x800CB170: nop

    // 0x800CB174: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB178: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CB17C: jal         0x800CF61C
    // 0x800CB180: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800CF61C(rdram, ctx);
        goto after_5;
    // 0x800CB180: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_5:
    // 0x800CB184: b           L_800CB220
    // 0x800CB188: nop

        goto L_800CB220;
    // 0x800CB188: nop

L_800CB18C:
    // 0x800CB18C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB190: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800CB194: lw          $a1, -0x6ACC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6ACC);
    // 0x800CB198: jal         0x800CF61C
    // 0x800CB19C: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    func_800CF61C(rdram, ctx);
        goto after_6;
    // 0x800CB19C: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    after_6:
    // 0x800CB1A0: b           L_800CB220
    // 0x800CB1A4: nop

        goto L_800CB220;
    // 0x800CB1A4: nop

L_800CB1A8:
    // 0x800CB1A8: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800CB1AC: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800CB1B0: lw          $t4, -0x6AC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6AC4);
    // 0x800CB1B4: lw          $t3, -0x6ACC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6ACC);
    // 0x800CB1B8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CB1BC: lw          $t6, -0x6AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AC0);
    // 0x800CB1C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB1C4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CB1C8: sw          $t5, -0x6ACC($at)
    MEM_W(-0X6ACC, ctx->r1) = ctx->r13;
    // 0x800CB1CC: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800CB1D0: bne         $at, $zero, L_800CB1E4
    if (ctx->r1 != 0) {
        // 0x800CB1D4: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CB1E4;
    }
    // 0x800CB1D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB1D8: sw          $t6, -0x6ACC($at)
    MEM_W(-0X6ACC, ctx->r1) = ctx->r14;
    // 0x800CB1DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB1E0: sw          $zero, -0x5314($at)
    MEM_W(-0X5314, ctx->r1) = 0;
L_800CB1E4:
    // 0x800CB1E4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800CB1E8: lw          $t7, -0x6B38($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6B38);
    // 0x800CB1EC: bne         $t7, $zero, L_800CB20C
    if (ctx->r15 != 0) {
        // 0x800CB1F0: nop
    
            goto L_800CB20C;
    }
    // 0x800CB1F0: nop

    // 0x800CB1F4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB1F8: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    // 0x800CB1FC: jal         0x800CF61C
    // 0x800CB200: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800CF61C(rdram, ctx);
        goto after_7;
    // 0x800CB200: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_7:
    // 0x800CB204: b           L_800CB220
    // 0x800CB208: nop

        goto L_800CB220;
    // 0x800CB208: nop

L_800CB20C:
    // 0x800CB20C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB210: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800CB214: lw          $a1, -0x6ACC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6ACC);
    // 0x800CB218: jal         0x800CF61C
    // 0x800CB21C: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    func_800CF61C(rdram, ctx);
        goto after_8;
    // 0x800CB21C: lw          $a0, -0x6ABC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6ABC);
    after_8:
L_800CB220:
    // 0x800CB220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CB22C: jr          $ra
    // 0x800CB230: nop

    return;
    // 0x800CB230: nop

;}
RECOMP_FUNC void func_800CB234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB234: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CB238: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CB23C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800CB240: addiu       $t6, $zero, 0x7D00
    ctx->r14 = ADD32(0, 0X7D00);
    // 0x800CB244: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB24C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CB250: sw          $t6, -0x52F8($at)
    MEM_W(-0X52F8, ctx->r1) = ctx->r14;
    // 0x800CB254: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800CB258: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800CB25C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800CB260: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800CB264: lui         $t2, 0x8
    ctx->r10 = S32(0X8 << 16);
    // 0x800CB268: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x800CB26C: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x800CB270: lui         $t1, 0x8038
    ctx->r9 = S32(0X8038 << 16);
    // 0x800CB274: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800CB278: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800CB27C: lui         $s0, 0x8
    ctx->r16 = S32(0X8 << 16);
    // 0x800CB280: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800CB284: beq         $s0, $zero, L_800CB2B4
    if (ctx->r16 == 0) {
        // 0x800CB288: sw          $t3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r11;
            goto L_800CB2B4;
    }
    // 0x800CB288: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_800CB28C:
    // 0x800CB28C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB290: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x800CB294: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CB298: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB29C: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800CB2A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800CB2A4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800CB2A8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CB2AC: bne         $s0, $zero, L_800CB28C
    if (ctx->r16 != 0) {
        // 0x800CB2B0: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_800CB28C;
    }
    // 0x800CB2B0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800CB2B4:
    // 0x800CB2B4: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800CB2B8: addiu       $a2, $a2, -0x5310
    ctx->r6 = ADD32(ctx->r6, -0X5310);
    // 0x800CB2BC: lui         $a0, 0x8038
    ctx->r4 = S32(0X8038 << 16);
    // 0x800CB2C0: jal         0x800CDC58
    // 0x800CB2C4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    func_800CDC58(rdram, ctx);
        goto after_0;
    // 0x800CB2C4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_0:
    // 0x800CB2C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800CB2CC: jal         0x800CE190
    // 0x800CB2D0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800CE190(rdram, ctx);
        goto after_1;
    // 0x800CB2D0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x800CB2D4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CB2D8: jal         0x800CE1E0
    // 0x800CB2DC: addiu       $a0, $a0, -0x1DE0
    ctx->r4 = ADD32(ctx->r4, -0X1DE0);
    func_800CE1E0(rdram, ctx);
        goto after_2;
    // 0x800CB2DC: addiu       $a0, $a0, -0x1DE0
    ctx->r4 = ADD32(ctx->r4, -0X1DE0);
    after_2:
    // 0x800CB2E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB2E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB2E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CB2EC: jr          $ra
    // 0x800CB2F0: nop

    return;
    // 0x800CB2F0: nop

;}
RECOMP_FUNC void func_800CB2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB2F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB2F8: sw          $zero, -0x6B4C($at)
    MEM_W(-0X6B4C, ctx->r1) = 0;
    // 0x800CB2FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB300: sw          $zero, -0x6B50($at)
    MEM_W(-0X6B50, ctx->r1) = 0;
    // 0x800CB304: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB308: addiu       $t6, $zero, 0x4FFF
    ctx->r14 = ADD32(0, 0X4FFF);
    // 0x800CB30C: sw          $t6, -0x6B48($at)
    MEM_W(-0X6B48, ctx->r1) = ctx->r14;
    // 0x800CB310: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB314: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800CB318: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CB31C: sw          $t7, -0x6B44($at)
    MEM_W(-0X6B44, ctx->r1) = ctx->r15;
    // 0x800CB320: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB324: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x800CB328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB32C: sw          $t8, -0x6B40($at)
    MEM_W(-0X6B40, ctx->r1) = ctx->r24;
    // 0x800CB330: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800CB334:
    // 0x800CB334: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB338: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB33C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB340: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CB344: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800CB348: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800CB34C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB350: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800CB354: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800CB358: sw          $zero, -0x6BF0($at)
    MEM_W(-0X6BF0, ctx->r1) = 0;
    // 0x800CB35C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800CB360: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800CB364: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB368: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB36C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CB370: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800CB374: sw          $zero, -0x6BEC($at)
    MEM_W(-0X6BEC, ctx->r1) = 0;
    // 0x800CB378: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800CB37C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CB380: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB384: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB388: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CB38C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800CB390: sw          $zero, -0x6BE8($at)
    MEM_W(-0X6BE8, ctx->r1) = 0;
    // 0x800CB394: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800CB398: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CB39C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CB3A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CB3A8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB3AC: sw          $zero, -0x6BE4($at)
    MEM_W(-0X6BE4, ctx->r1) = 0;
    // 0x800CB3B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CB3B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800CB3B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3BC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800CB3C0: sw          $zero, -0x6BE0($at)
    MEM_W(-0X6BE0, ctx->r1) = 0;
    // 0x800CB3C4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CB3C8: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x800CB3CC: bne         $at, $zero, L_800CB334
    if (ctx->r1 != 0) {
        // 0x800CB3D0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_800CB334;
    }
    // 0x800CB3D0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800CB3D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3D8: sw          $zero, -0x6B2C($at)
    MEM_W(-0X6B2C, ctx->r1) = 0;
    // 0x800CB3DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3E0: sw          $zero, -0x6B30($at)
    MEM_W(-0X6B30, ctx->r1) = 0;
    // 0x800CB3E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3E8: sw          $zero, -0x6B28($at)
    MEM_W(-0X6B28, ctx->r1) = 0;
    // 0x800CB3EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3F0: sw          $zero, -0x6B24($at)
    MEM_W(-0X6B24, ctx->r1) = 0;
    // 0x800CB3F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB3F8: sw          $zero, -0x6B34($at)
    MEM_W(-0X6B34, ctx->r1) = 0;
    // 0x800CB3FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB400: sw          $zero, -0x6B20($at)
    MEM_W(-0X6B20, ctx->r1) = 0;
    // 0x800CB404: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB408: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
    // 0x800CB40C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB410: sw          $zero, -0x6B1C($at)
    MEM_W(-0X6B1C, ctx->r1) = 0;
    // 0x800CB414: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB418: sw          $zero, -0x6B18($at)
    MEM_W(-0X6B18, ctx->r1) = 0;
    // 0x800CB41C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB420: sw          $zero, -0x6B14($at)
    MEM_W(-0X6B14, ctx->r1) = 0;
    // 0x800CB424: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB428: sw          $zero, -0x6B00($at)
    MEM_W(-0X6B00, ctx->r1) = 0;
    // 0x800CB42C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB430: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
    // 0x800CB434: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB438: sw          $zero, -0x6AFC($at)
    MEM_W(-0X6AFC, ctx->r1) = 0;
    // 0x800CB43C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB440: sw          $zero, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = 0;
    // 0x800CB444: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800CB448: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800CB44C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB450: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800CB454: addiu       $t2, $t2, -0x6E30
    ctx->r10 = ADD32(ctx->r10, -0X6E30);
    // 0x800CB458: addiu       $t3, $t3, -0x6C00
    ctx->r11 = ADD32(ctx->r11, -0X6C00);
    // 0x800CB45C: ori         $t4, $zero, 0xAC44
    ctx->r12 = 0 | 0XAC44;
    // 0x800CB460: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x800CB464: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800CB468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CB46C: addiu       $t8, $zero, 0x24
    ctx->r24 = ADD32(0, 0X24);
    // 0x800CB470: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800CB474: sw          $zero, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = 0;
    // 0x800CB478: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800CB47C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800CB480: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800CB484: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800CB488: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CB48C: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800CB490: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800CB494: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800CB498: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800CB49C: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800CB4A0: jal         0x800CB234
    // 0x800CB4A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800CB234(rdram, ctx);
        goto after_0;
    // 0x800CB4A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800CB4A8: lui         $t0, 0x5B
    ctx->r8 = S32(0X5B << 16);
    // 0x800CB4AC: lui         $t1, 0x5C
    ctx->r9 = S32(0X5C << 16);
    // 0x800CB4B0: addiu       $t1, $t1, -0xD80
    ctx->r9 = ADD32(ctx->r9, -0XD80);
    // 0x800CB4B4: addiu       $t0, $t0, 0x6F20
    ctx->r8 = ADD32(ctx->r8, 0X6F20);
    // 0x800CB4B8: lui         $a2, 0x5C
    ctx->r6 = S32(0X5C << 16);
    // 0x800CB4BC: addiu       $a2, $a2, -0xD80
    ctx->r6 = ADD32(ctx->r6, -0XD80);
    // 0x800CB4C0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800CB4C4: jal         0x800CE290
    // 0x800CB4C8: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    func_800CE290(rdram, ctx);
        goto after_1;
    // 0x800CB4C8: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_1:
    // 0x800CB4CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB4D0: jal         0x800CB7A4
    // 0x800CB4D4: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    func_800CB7A4(rdram, ctx);
        goto after_2;
    // 0x800CB4D4: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    after_2:
    // 0x800CB4D8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB4DC: jal         0x800CB83C
    // 0x800CB4E0: lw          $a0, -0x6B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B40);
    func_800CB83C(rdram, ctx);
        goto after_3;
    // 0x800CB4E0: lw          $a0, -0x6B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B40);
    after_3:
    // 0x800CB4E4: jal         0x800CB8AC
    // 0x800CB4E8: nop

    func_800CB8AC(rdram, ctx);
        goto after_4;
    // 0x800CB4E8: nop

    after_4:
    // 0x800CB4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB4F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CB4F4: jr          $ra
    // 0x800CB4F8: nop

    return;
    // 0x800CB4F8: nop

;}
RECOMP_FUNC void func_800CB4FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB4FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB500: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB508: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_800CB50C:
    // 0x800CB50C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB510: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CB514: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CB518: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CB51C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800CB520: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800CB524: lw          $t9, -0x6BE4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6BE4);
    // 0x800CB528: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800CB52C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800CB530: bgez        $t0, L_800CB53C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CB534: sw          $t0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r8;
            goto L_800CB53C;
    }
    // 0x800CB534: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800CB538: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800CB53C:
    // 0x800CB53C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB540: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB544: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800CB548: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800CB54C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800CB550: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800CB554: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB558: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800CB55C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800CB560: sw          $t1, -0x6BE4($at)
    MEM_W(-0X6BE4, ctx->r1) = ctx->r9;
    // 0x800CB564: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x800CB568: bne         $at, $zero, L_800CB50C
    if (ctx->r1 != 0) {
        // 0x800CB56C: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_800CB50C;
    }
    // 0x800CB56C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800CB570: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CB574: lw          $t6, -0x6B30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6B30);
    // 0x800CB578: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CB57C: bgez        $t7, L_800CB5A0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CB580: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_800CB5A0;
    }
    // 0x800CB580: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800CB584: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB588: sw          $zero, -0x6B2C($at)
    MEM_W(-0X6B2C, ctx->r1) = 0;
    // 0x800CB58C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB590: sw          $zero, -0x6B28($at)
    MEM_W(-0X6B28, ctx->r1) = 0;
    // 0x800CB594: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB598: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800CB59C: sw          $zero, -0x6B24($at)
    MEM_W(-0X6B24, ctx->r1) = 0;
L_800CB5A0:
    // 0x800CB5A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800CB5A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB5A8: jal         0x800CB5D8
    // 0x800CB5AC: sw          $t8, -0x6B30($at)
    MEM_W(-0X6B30, ctx->r1) = ctx->r24;
    func_800CB5D8(rdram, ctx);
        goto after_0;
    // 0x800CB5AC: sw          $t8, -0x6B30($at)
    MEM_W(-0X6B30, ctx->r1) = ctx->r24;
    after_0:
    // 0x800CB5B0: jal         0x800C9170
    // 0x800CB5B4: nop

    func_800C9170(rdram, ctx);
        goto after_1;
    // 0x800CB5B4: nop

    after_1:
    // 0x800CB5B8: jal         0x800C971C
    // 0x800CB5BC: nop

    func_800C971C(rdram, ctx);
        goto after_2;
    // 0x800CB5BC: nop

    after_2:
    // 0x800CB5C0: jal         0x800CAEBC
    // 0x800CB5C4: nop

    func_800CAEBC(rdram, ctx);
        goto after_3;
    // 0x800CB5C4: nop

    after_3:
    // 0x800CB5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB5CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB5D0: jr          $ra
    // 0x800CB5D4: nop

    return;
    // 0x800CB5D4: nop

;}
RECOMP_FUNC void func_800CB5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB5D8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CB5DC: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800CB5E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB5E8: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x800CB5EC: beq         $t7, $zero, L_800CB6E0
    if (ctx->r15 == 0) {
        // 0x800CB5F0: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800CB6E0;
    }
    // 0x800CB5F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB5F4: sw          $zero, -0x6AF4($at)
    MEM_W(-0X6AF4, ctx->r1) = 0;
    // 0x800CB5F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB5FC: sw          $zero, -0x794C($at)
    MEM_W(-0X794C, ctx->r1) = 0;
    // 0x800CB600: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800CB604: lbu         $t8, -0x452E($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X452E);
    // 0x800CB608: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB60C: sw          $zero, -0x7944($at)
    MEM_W(-0X7944, ctx->r1) = 0;
    // 0x800CB610: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB614: sw          $zero, -0x6AF8($at)
    MEM_W(-0X6AF8, ctx->r1) = 0;
    // 0x800CB618: addiu       $t9, $t8, -0x64
    ctx->r25 = ADD32(ctx->r24, -0X64);
    // 0x800CB61C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB620: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800CB624: sw          $zero, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = 0;
    // 0x800CB628: bgtz        $t0, L_800CB634
    if (SIGNED(ctx->r8) > 0) {
        // 0x800CB62C: sb          $t9, 0x1F($sp)
        MEM_B(0X1F, ctx->r29) = ctx->r25;
            goto L_800CB634;
    }
    // 0x800CB62C: sb          $t9, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r25;
    // 0x800CB630: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
L_800CB634:
    // 0x800CB634: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x800CB638: slti        $at, $t1, 0x83
    ctx->r1 = SIGNED(ctx->r9) < 0X83 ? 1 : 0;
    // 0x800CB63C: bne         $at, $zero, L_800CB654
    if (ctx->r1 != 0) {
        // 0x800CB640: nop
    
            goto L_800CB654;
    }
    // 0x800CB640: nop

    // 0x800CB644: jal         0x800CB6F8
    // 0x800CB648: nop

    func_800CB6F8(rdram, ctx);
        goto after_0;
    // 0x800CB648: nop

    after_0:
    // 0x800CB64C: b           L_800CB6B4
    // 0x800CB650: nop

        goto L_800CB6B4;
    // 0x800CB650: nop

L_800CB654:
    // 0x800CB654: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x800CB658: addiu       $t3, $zero, 0x9B
    ctx->r11 = ADD32(0, 0X9B);
    // 0x800CB65C: addiu       $t5, $zero, 0x7FFF
    ctx->r13 = ADD32(0, 0X7FFF);
    // 0x800CB660: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x800CB664: div         $zero, $t5, $t4
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r12)));
    // 0x800CB668: mflo        $t6
    ctx->r14 = lo;
    // 0x800CB66C: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x800CB670: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800CB674: bne         $t4, $zero, L_800CB680
    if (ctx->r12 != 0) {
        // 0x800CB678: nop
    
            goto L_800CB680;
    }
    // 0x800CB678: nop

    // 0x800CB67C: break       7
    do_break(2148316796);
L_800CB680:
    // 0x800CB680: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CB684: bne         $t4, $at, L_800CB698
    if (ctx->r12 != ctx->r1) {
        // 0x800CB688: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CB698;
    }
    // 0x800CB688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CB68C: bne         $t5, $at, L_800CB698
    if (ctx->r13 != ctx->r1) {
        // 0x800CB690: nop
    
            goto L_800CB698;
    }
    // 0x800CB690: nop

    // 0x800CB694: break       6
    do_break(2148316820);
L_800CB698:
    // 0x800CB698: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800CB69C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800CB6A0: jal         0x800CF02C
    // 0x800CB6A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CF02C(rdram, ctx);
        goto after_1;
    // 0x800CB6A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800CB6A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CB6AC: jal         0x800CF02C
    // 0x800CB6B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CF02C(rdram, ctx);
        goto after_2;
    // 0x800CB6B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_800CB6B4:
    // 0x800CB6B4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800CB6B8: lbu         $t9, -0x452E($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X452E);
    // 0x800CB6BC: slti        $at, $t9, 0xFB
    ctx->r1 = SIGNED(ctx->r25) < 0XFB ? 1 : 0;
    // 0x800CB6C0: bne         $at, $zero, L_800CB6E0
    if (ctx->r1 != 0) {
        // 0x800CB6C4: nop
    
            goto L_800CB6E0;
    }
    // 0x800CB6C4: nop

    // 0x800CB6C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB6CC: jal         0x800CB7A4
    // 0x800CB6D0: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    func_800CB7A4(rdram, ctx);
        goto after_3;
    // 0x800CB6D0: lw          $a0, -0x6B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B48);
    after_3:
    // 0x800CB6D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB6D8: jal         0x800CB83C
    // 0x800CB6DC: lw          $a0, -0x6B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B40);
    func_800CB83C(rdram, ctx);
        goto after_4;
    // 0x800CB6DC: lw          $a0, -0x6B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B40);
    after_4:
L_800CB6E0:
    // 0x800CB6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB6E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB6E8: jr          $ra
    // 0x800CB6EC: nop

    return;
    // 0x800CB6EC: nop

;}
RECOMP_FUNC void func_800CB6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB6F0: jr          $ra
    // 0x800CB6F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800CB6F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800CB6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB700: jal         0x800C7FA4
    // 0x800CB704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C7FA4(rdram, ctx);
        goto after_0;
    // 0x800CB704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CB708: jal         0x800C8544
    // 0x800CB70C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x800CB70C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800CB710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB718: jr          $ra
    // 0x800CB71C: nop

    return;
    // 0x800CB71C: nop

;}
RECOMP_FUNC void func_800CB720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB728: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800CB72C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800CB730: jal         0x800CF488
    // 0x800CB734: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CF488(rdram, ctx);
        goto after_0;
    // 0x800CB734: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800CB738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800CB73C: jal         0x800CF488
    // 0x800CB740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF488(rdram, ctx);
        goto after_1;
    // 0x800CB740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800CB744: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800CB748: lw          $t6, -0x6B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6B4C);
    // 0x800CB74C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800CB750: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800CB754: bne         $t6, $at, L_800CB760
    if (ctx->r14 != ctx->r1) {
        // 0x800CB758: nop
    
            goto L_800CB760;
    }
    // 0x800CB758: nop

    // 0x800CB75C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800CB760:
    // 0x800CB760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB764: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB768: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800CB76C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB770: jr          $ra
    // 0x800CB774: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800CB774: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_800CB778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB784: jal         0x800CB7A4
    // 0x800CB788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800CB7A4(rdram, ctx);
        goto after_0;
    // 0x800CB788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800CB78C: jal         0x800CB83C
    // 0x800CB790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800CB83C(rdram, ctx);
        goto after_1;
    // 0x800CB790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800CB794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB79C: jr          $ra
    // 0x800CB7A0: nop

    return;
    // 0x800CB7A0: nop

;}
RECOMP_FUNC void func_800CB7A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB7A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB7AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB7B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800CB7B4: jal         0x800CF02C
    // 0x800CB7B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CF02C(rdram, ctx);
        goto after_0;
    // 0x800CB7B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800CB7BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB7C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB7C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB7C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB7CC: jr          $ra
    // 0x800CB7D0: sw          $t6, -0x6B48($at)
    MEM_W(-0X6B48, ctx->r1) = ctx->r14;
    return;
    // 0x800CB7D0: sw          $t6, -0x6B48($at)
    MEM_W(-0X6B48, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800CB7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB7DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB7E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800CB7E4: jal         0x800CF02C
    // 0x800CB7E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CF02C(rdram, ctx);
        goto after_0;
    // 0x800CB7E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800CB7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB7F4: jr          $ra
    // 0x800CB7F8: nop

    return;
    // 0x800CB7F8: nop

;}
RECOMP_FUNC void func_800CB7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800CB800: jr          $ra
    // 0x800CB804: lw          $v0, -0x6B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B48);
    return;
    // 0x800CB804: lw          $v0, -0x6B48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B48);
;}
RECOMP_FUNC void func_800CB808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB80C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB814: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB818: lw          $a0, -0x6B50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6B50);
    // 0x800CB81C: jal         0x800CF5B8
    // 0x800CB820: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CF5B8(rdram, ctx);
        goto after_0;
    // 0x800CB820: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800CB824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB828: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB82C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB834: jr          $ra
    // 0x800CB838: sw          $t6, -0x6B44($at)
    MEM_W(-0X6B44, ctx->r1) = ctx->r14;
    return;
    // 0x800CB838: sw          $t6, -0x6B44($at)
    MEM_W(-0X6B44, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800CB83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB844: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB848: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800CB84C: jal         0x800CF02C
    // 0x800CB850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF02C(rdram, ctx);
        goto after_0;
    // 0x800CB850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CB854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB858: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB85C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB864: jr          $ra
    // 0x800CB868: sw          $t6, -0x6B40($at)
    MEM_W(-0X6B40, ctx->r1) = ctx->r14;
    return;
    // 0x800CB868: sw          $t6, -0x6B40($at)
    MEM_W(-0X6B40, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800CB86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB86C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB878: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800CB87C: jal         0x800CF02C
    // 0x800CB880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF02C(rdram, ctx);
        goto after_0;
    // 0x800CB880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CB884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB88C: jr          $ra
    // 0x800CB890: nop

    return;
    // 0x800CB890: nop

;}
RECOMP_FUNC void func_800CB894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB894: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800CB898: jr          $ra
    // 0x800CB89C: lw          $v0, -0x6B40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B40);
    return;
    // 0x800CB89C: lw          $v0, -0x6B40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B40);
;}
RECOMP_FUNC void func_800CB8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB8A4: jr          $ra
    // 0x800CB8A8: sw          $zero, -0x6B38($at)
    MEM_W(-0X6B38, ctx->r1) = 0;
    return;
    // 0x800CB8A8: sw          $zero, -0x6B38($at)
    MEM_W(-0X6B38, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800CB8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB8B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CB8B4: jr          $ra
    // 0x800CB8B8: sw          $t6, -0x6B38($at)
    MEM_W(-0X6B38, ctx->r1) = ctx->r14;
    return;
    // 0x800CB8B8: sw          $t6, -0x6B38($at)
    MEM_W(-0X6B38, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800CB8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800CB8C0: jr          $ra
    // 0x800CB8C4: lw          $v0, -0x6B38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B38);
    return;
    // 0x800CB8C4: lw          $v0, -0x6B38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B38);
;}
RECOMP_FUNC void func_800CB8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB8C8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CB8CC: lw          $t6, -0x7940($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7940);
    // 0x800CB8D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB8D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB8D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CB8DC: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800CB8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB8E4: sw          $t7, -0x7940($at)
    MEM_W(-0X7940, ctx->r1) = ctx->r15;
    // 0x800CB8E8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800CB8EC:
    // 0x800CB8EC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB8F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800CB8F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CB8F8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CB8FC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800CB900: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800CB904: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800CB908: jal         0x800CF5B8
    // 0x800CB90C: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    func_800CF5B8(rdram, ctx);
        goto after_0;
    // 0x800CB90C: lw          $a0, -0x6BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6BEC);
    after_0:
    // 0x800CB910: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB914: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CB918: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x800CB91C: bne         $at, $zero, L_800CB8EC
    if (ctx->r1 != 0) {
        // 0x800CB920: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800CB8EC;
    }
    // 0x800CB920: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800CB924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB92C: jr          $ra
    // 0x800CB930: nop

    return;
    // 0x800CB930: nop

;}
RECOMP_FUNC void func_800CB934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB934: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CB938: lw          $t6, -0x7940($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7940);
    // 0x800CB93C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800CB940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB944: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800CB948: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB94C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CB950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB954: sw          $t7, -0x7940($at)
    MEM_W(-0X7940, ctx->r1) = ctx->r15;
    // 0x800CB958: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_800CB95C:
    // 0x800CB95C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB960: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800CB964: addiu       $t1, $t1, -0x6BF0
    ctx->r9 = ADD32(ctx->r9, -0X6BF0);
    // 0x800CB968: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CB96C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800CB970: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800CB974: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800CB978: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    // 0x800CB97C: jal         0x800CF5B8
    // 0x800CB980: lw          $a1, 0x10($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X10);
    func_800CF5B8(rdram, ctx);
        goto after_0;
    // 0x800CB980: lw          $a1, 0x10($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X10);
    after_0:
    // 0x800CB984: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB988: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CB98C: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x800CB990: bne         $at, $zero, L_800CB95C
    if (ctx->r1 != 0) {
        // 0x800CB994: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800CB95C;
    }
    // 0x800CB994: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800CB998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB99C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB9A0: jr          $ra
    // 0x800CB9A4: nop

    return;
    // 0x800CB9A4: nop

;}
RECOMP_FUNC void func_800CB9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB9A8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CB9AC: lw          $t6, -0x7940($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7940);
    // 0x800CB9B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800CB9B4: beq         $t7, $zero, L_800CB9E8
    if (ctx->r15 == 0) {
        // 0x800CB9B8: nop
    
            goto L_800CB9E8;
    }
    // 0x800CB9B8: nop

    // 0x800CB9BC: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x800CB9C0: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CB9C4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800CB9C8: lw          $t9, -0x69BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X69BC);
    // 0x800CB9CC: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x800CB9D0: beq         $t0, $zero, L_800CB9E0
    if (ctx->r8 == 0) {
        // 0x800CB9D4: nop
    
            goto L_800CB9E0;
    }
    // 0x800CB9D4: nop

    // 0x800CB9D8: jr          $ra
    // 0x800CB9DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CB9DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CB9E0:
    // 0x800CB9E0: jr          $ra
    // 0x800CB9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CB9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CB9E8:
    // 0x800CB9E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB9EC: jr          $ra
    // 0x800CB9F0: nop

    return;
    // 0x800CB9F0: nop

    // 0x800CB9F4: nop

    // 0x800CB9F8: nop

    // 0x800CB9FC: nop

;}
RECOMP_FUNC void func_800CBA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBA08: jal         0x800CC174
    // 0x800CBA0C: nop

    func_800CC174(rdram, ctx);
        goto after_0;
    // 0x800CBA0C: nop

    after_0:
    // 0x800CBA10: jal         0x800C25A4
    // 0x800CBA14: nop

    func_800C25A4(rdram, ctx);
        goto after_1;
    // 0x800CBA14: nop

    after_1:
    // 0x800CBA18: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA1C: jal         0x800C38C8
    // 0x800CBA20: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_2;
    // 0x800CBA20: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_2:
    // 0x800CBA24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA28: jal         0x800C3930
    // 0x800CBA2C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_3;
    // 0x800CBA2C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_3:
    // 0x800CBA30: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA34: jal         0x800C38C8
    // 0x800CBA38: addiu       $a0, $a0, -0x4B30
    ctx->r4 = ADD32(ctx->r4, -0X4B30);
    func_800C38C8(rdram, ctx);
        goto after_4;
    // 0x800CBA38: addiu       $a0, $a0, -0x4B30
    ctx->r4 = ADD32(ctx->r4, -0X4B30);
    after_4:
    // 0x800CBA3C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA40: jal         0x800C3930
    // 0x800CBA44: addiu       $a0, $a0, -0x4B10
    ctx->r4 = ADD32(ctx->r4, -0X4B10);
    func_800C3930(rdram, ctx);
        goto after_5;
    // 0x800CBA44: addiu       $a0, $a0, -0x4B10
    ctx->r4 = ADD32(ctx->r4, -0X4B10);
    after_5:
    // 0x800CBA48: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA4C: jal         0x800C3968
    // 0x800CBA50: addiu       $a0, $a0, -0x4B00
    ctx->r4 = ADD32(ctx->r4, -0X4B00);
    func_800C3968(rdram, ctx);
        goto after_6;
    // 0x800CBA50: addiu       $a0, $a0, -0x4B00
    ctx->r4 = ADD32(ctx->r4, -0X4B00);
    after_6:
    // 0x800CBA54: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBA58: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBA5C: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBA60: jal         0x800C39A0
    // 0x800CBA64: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_7;
    // 0x800CBA64: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_7:
    // 0x800CBA68: jal         0x8017B0C0
    // 0x800CBA6C: nop

    LOOKUP_FUNC(0x8017B0C0)(rdram, ctx);
        goto after_8;
    // 0x800CBA6C: nop

    after_8:
L_800CBA70:
    // 0x800CBA70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CBA74: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x800CBA78: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CBA7C: beq         $t6, $at, L_800CBA8C
    if (ctx->r14 == ctx->r1) {
        // 0x800CBA80: nop
    
            goto L_800CBA8C;
    }
    // 0x800CBA80: nop

    // 0x800CBA84: jal         0x800CBB10
    // 0x800CBA88: nop

    func_800CBB10(rdram, ctx);
        goto after_9;
    // 0x800CBA88: nop

    after_9:
L_800CBA8C:
    // 0x800CBA8C: jal         0x800C25A4
    // 0x800CBA90: nop

    func_800C25A4(rdram, ctx);
        goto after_10;
    // 0x800CBA90: nop

    after_10:
    // 0x800CBA94: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBA98: jal         0x800C38C8
    // 0x800CBA9C: addiu       $a0, $a0, -0x4AB8
    ctx->r4 = ADD32(ctx->r4, -0X4AB8);
    func_800C38C8(rdram, ctx);
        goto after_11;
    // 0x800CBA9C: addiu       $a0, $a0, -0x4AB8
    ctx->r4 = ADD32(ctx->r4, -0X4AB8);
    after_11:
    // 0x800CBAA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBAA4: jal         0x800C3930
    // 0x800CBAA8: addiu       $a0, $a0, -0x4A98
    ctx->r4 = ADD32(ctx->r4, -0X4A98);
    func_800C3930(rdram, ctx);
        goto after_12;
    // 0x800CBAA8: addiu       $a0, $a0, -0x4A98
    ctx->r4 = ADD32(ctx->r4, -0X4A98);
    after_12:
    // 0x800CBAAC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBAB0: jal         0x800C3968
    // 0x800CBAB4: addiu       $a0, $a0, -0x4A88
    ctx->r4 = ADD32(ctx->r4, -0X4A88);
    func_800C3968(rdram, ctx);
        goto after_13;
    // 0x800CBAB4: addiu       $a0, $a0, -0x4A88
    ctx->r4 = ADD32(ctx->r4, -0X4A88);
    after_13:
    // 0x800CBAB8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBABC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBAC0: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBAC4: jal         0x800C39A0
    // 0x800CBAC8: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_14;
    // 0x800CBAC8: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_14:
    // 0x800CBACC: jal         0x8017B0C0
    // 0x800CBAD0: nop

    LOOKUP_FUNC(0x8017B0C0)(rdram, ctx);
        goto after_15;
    // 0x800CBAD0: nop

    after_15:
    // 0x800CBAD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CBAD8: lw          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E4C);
    // 0x800CBADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CBAE0: bne         $t7, $at, L_800CBA70
    if (ctx->r15 != ctx->r1) {
        // 0x800CBAE4: nop
    
            goto L_800CBA70;
    }
    // 0x800CBAE4: nop

    // 0x800CBAE8: jal         0x800CBD04
    // 0x800CBAEC: nop

    func_800CBD04(rdram, ctx);
        goto after_16;
    // 0x800CBAEC: nop

    after_16:
    // 0x800CBAF0: b           L_800CBA70
    // 0x800CBAF4: nop

        goto L_800CBA70;
    // 0x800CBAF4: nop

    // 0x800CBAF8: nop

    // 0x800CBAFC: nop

    // 0x800CBB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBB08: jr          $ra
    // 0x800CBB0C: nop

    return;
    // 0x800CBB0C: nop

;}
RECOMP_FUNC void func_800CBB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBB18: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBB1C: jal         0x800C38C8
    // 0x800CBB20: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_0;
    // 0x800CBB20: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_0:
    // 0x800CBB24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBB28: jal         0x800C3930
    // 0x800CBB2C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_1;
    // 0x800CBB2C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_1:
L_800CBB30:
    // 0x800CBB30: jal         0x800C25A4
    // 0x800CBB34: nop

    func_800C25A4(rdram, ctx);
        goto after_2;
    // 0x800CBB34: nop

    after_2:
    // 0x800CBB38: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBB3C: jal         0x800C38C8
    // 0x800CBB40: addiu       $a0, $a0, -0x4AF4
    ctx->r4 = ADD32(ctx->r4, -0X4AF4);
    func_800C38C8(rdram, ctx);
        goto after_3;
    // 0x800CBB40: addiu       $a0, $a0, -0x4AF4
    ctx->r4 = ADD32(ctx->r4, -0X4AF4);
    after_3:
    // 0x800CBB44: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBB48: jal         0x800C3930
    // 0x800CBB4C: addiu       $a0, $a0, -0x4AD4
    ctx->r4 = ADD32(ctx->r4, -0X4AD4);
    func_800C3930(rdram, ctx);
        goto after_4;
    // 0x800CBB4C: addiu       $a0, $a0, -0x4AD4
    ctx->r4 = ADD32(ctx->r4, -0X4AD4);
    after_4:
    // 0x800CBB50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBB54: jal         0x800C3968
    // 0x800CBB58: addiu       $a0, $a0, -0x4AC4
    ctx->r4 = ADD32(ctx->r4, -0X4AC4);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x800CBB58: addiu       $a0, $a0, -0x4AC4
    ctx->r4 = ADD32(ctx->r4, -0X4AC4);
    after_5:
    // 0x800CBB5C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBB60: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBB64: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBB68: jal         0x800C39A0
    // 0x800CBB6C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_6;
    // 0x800CBB6C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // 0x800CBB70: jal         0x8017B0C0
    // 0x800CBB74: nop

    LOOKUP_FUNC(0x8017B0C0)(rdram, ctx);
        goto after_7;
    // 0x800CBB74: nop

    after_7:
    // 0x800CBB78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CBB7C: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x800CBB80: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800CBB84: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x800CBB88: beq         $at, $zero, L_800CBB30
    if (ctx->r1 == 0) {
        // 0x800CBB8C: nop
    
            goto L_800CBB30;
    }
    // 0x800CBB8C: nop

    // 0x800CBB90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CBB94: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CBB98: addu        $at, $at, $t7
    gpr jr_addend_800CBBA0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800CBB9C: lw          $t7, -0x21C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X21C0);
    // 0x800CBBA0: jr          $t7
    // 0x800CBBA4: nop

    switch (jr_addend_800CBBA0 >> 2) {
        case 0: goto L_800CBCF4; break;
        case 1: goto L_800CBB30; break;
        case 2: goto L_800CBB30; break;
        case 3: goto L_800CBB30; break;
        case 4: goto L_800CBBA8; break;
        case 5: goto L_800CBBA8; break;
        case 6: goto L_800CBBA8; break;
        case 7: goto L_800CBBA8; break;
        case 8: goto L_800CBB30; break;
        case 9: goto L_800CBC20; break;
        case 10: goto L_800CBB30; break;
        case 11: goto L_800CBB30; break;
        case 12: goto L_800CBB30; break;
        case 13: goto L_800CBB30; break;
        case 14: goto L_800CBB30; break;
        case 15: goto L_800CBB30; break;
        case 16: goto L_800CBB30; break;
        case 17: goto L_800CBB30; break;
        case 18: goto L_800CBB30; break;
        case 19: goto L_800CBC70; break;
        default: switch_error(__func__, 0x800CBBA0, 0x800EDE40);
    }
    // 0x800CBBA4: nop

L_800CBBA8:
    // 0x800CBBA8: jal         0x800C25A4
    // 0x800CBBAC: nop

    func_800C25A4(rdram, ctx);
        goto after_8;
    // 0x800CBBAC: nop

    after_8:
    // 0x800CBBB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBBB4: jal         0x800C38C8
    // 0x800CBBB8: addiu       $a0, $a0, -0x4A7C
    ctx->r4 = ADD32(ctx->r4, -0X4A7C);
    func_800C38C8(rdram, ctx);
        goto after_9;
    // 0x800CBBB8: addiu       $a0, $a0, -0x4A7C
    ctx->r4 = ADD32(ctx->r4, -0X4A7C);
    after_9:
    // 0x800CBBBC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBBC0: jal         0x800C3930
    // 0x800CBBC4: addiu       $a0, $a0, -0x4A5C
    ctx->r4 = ADD32(ctx->r4, -0X4A5C);
    func_800C3930(rdram, ctx);
        goto after_10;
    // 0x800CBBC4: addiu       $a0, $a0, -0x4A5C
    ctx->r4 = ADD32(ctx->r4, -0X4A5C);
    after_10:
    // 0x800CBBC8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBBCC: jal         0x800C3968
    // 0x800CBBD0: addiu       $a0, $a0, -0x4A4C
    ctx->r4 = ADD32(ctx->r4, -0X4A4C);
    func_800C3968(rdram, ctx);
        goto after_11;
    // 0x800CBBD0: addiu       $a0, $a0, -0x4A4C
    ctx->r4 = ADD32(ctx->r4, -0X4A4C);
    after_11:
    // 0x800CBBD4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBBD8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBBDC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBBE0: jal         0x800C39A0
    // 0x800CBBE4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_12;
    // 0x800CBBE4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_12:
    // 0x800CBBE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBBEC: jal         0x800C3968
    // 0x800CBBF0: addiu       $a0, $a0, -0x4A40
    ctx->r4 = ADD32(ctx->r4, -0X4A40);
    func_800C3968(rdram, ctx);
        goto after_13;
    // 0x800CBBF0: addiu       $a0, $a0, -0x4A40
    ctx->r4 = ADD32(ctx->r4, -0X4A40);
    after_13:
    // 0x800CBBF4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBBF8: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x800CBBFC: addiu       $a1, $a1, -0x1C00
    ctx->r5 = ADD32(ctx->r5, -0X1C00);
    // 0x800CBC00: jal         0x800C39A0
    // 0x800CBC04: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_14;
    // 0x800CBC04: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_14:
    // 0x800CBC08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CBC0C: lw          $a0, -0x2E4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2E4C);
    // 0x800CBC10: jal         0x8017BAA4
    // 0x800CBC14: addiu       $a0, $a0, -0x5
    ctx->r4 = ADD32(ctx->r4, -0X5);
    func_8017BAA4_0F4810(rdram, ctx);
        goto after_15;
    // 0x800CBC14: addiu       $a0, $a0, -0x5
    ctx->r4 = ADD32(ctx->r4, -0X5);
    after_15:
    // 0x800CBC18: b           L_800CBB30
    // 0x800CBC1C: nop

        goto L_800CBB30;
    // 0x800CBC1C: nop

L_800CBC20:
    // 0x800CBC20: jal         0x800C25A4
    // 0x800CBC24: nop

    func_800C25A4(rdram, ctx);
        goto after_16;
    // 0x800CBC24: nop

    after_16:
    // 0x800CBC28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC2C: jal         0x800C38C8
    // 0x800CBC30: addiu       $a0, $a0, -0x4A34
    ctx->r4 = ADD32(ctx->r4, -0X4A34);
    func_800C38C8(rdram, ctx);
        goto after_17;
    // 0x800CBC30: addiu       $a0, $a0, -0x4A34
    ctx->r4 = ADD32(ctx->r4, -0X4A34);
    after_17:
    // 0x800CBC34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC38: jal         0x800C3930
    // 0x800CBC3C: addiu       $a0, $a0, -0x4A14
    ctx->r4 = ADD32(ctx->r4, -0X4A14);
    func_800C3930(rdram, ctx);
        goto after_18;
    // 0x800CBC3C: addiu       $a0, $a0, -0x4A14
    ctx->r4 = ADD32(ctx->r4, -0X4A14);
    after_18:
    // 0x800CBC40: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC44: jal         0x800C3968
    // 0x800CBC48: addiu       $a0, $a0, -0x4A04
    ctx->r4 = ADD32(ctx->r4, -0X4A04);
    func_800C3968(rdram, ctx);
        goto after_19;
    // 0x800CBC48: addiu       $a0, $a0, -0x4A04
    ctx->r4 = ADD32(ctx->r4, -0X4A04);
    after_19:
    // 0x800CBC4C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBC50: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBC54: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBC58: jal         0x800C39A0
    // 0x800CBC5C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_20;
    // 0x800CBC5C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_20:
    // 0x800CBC60: jal         0x8017E07C
    // 0x800CBC64: nop

    func_8017E07C_111CC0(rdram, ctx);
        goto after_21;
    // 0x800CBC64: nop

    after_21:
    // 0x800CBC68: b           L_800CBB30
    // 0x800CBC6C: nop

        goto L_800CBB30;
    // 0x800CBC6C: nop

L_800CBC70:
    // 0x800CBC70: jal         0x800C25A4
    // 0x800CBC74: nop

    func_800C25A4(rdram, ctx);
        goto after_22;
    // 0x800CBC74: nop

    after_22:
    // 0x800CBC78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC7C: jal         0x800C3930
    // 0x800CBC80: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    func_800C3930(rdram, ctx);
        goto after_23;
    // 0x800CBC80: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    after_23:
    // 0x800CBC84: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC88: jal         0x800C38C8
    // 0x800CBC8C: addiu       $a0, $a0, -0x49BC
    ctx->r4 = ADD32(ctx->r4, -0X49BC);
    func_800C38C8(rdram, ctx);
        goto after_24;
    // 0x800CBC8C: addiu       $a0, $a0, -0x49BC
    ctx->r4 = ADD32(ctx->r4, -0X49BC);
    after_24:
    // 0x800CBC90: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBC94: jal         0x800C3968
    // 0x800CBC98: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    func_800C3968(rdram, ctx);
        goto after_25;
    // 0x800CBC98: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    after_25:
    // 0x800CBC9C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBCA0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CBCA4: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CBCA8: jal         0x800C39A0
    // 0x800CBCAC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_26;
    // 0x800CBCAC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_26:
    // 0x800CBCB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CBCB4: jal         0x800C3968
    // 0x800CBCB8: addiu       $a0, $a0, -0x4980
    ctx->r4 = ADD32(ctx->r4, -0X4980);
    func_800C3968(rdram, ctx);
        goto after_27;
    // 0x800CBCB8: addiu       $a0, $a0, -0x4980
    ctx->r4 = ADD32(ctx->r4, -0X4980);
    after_27:
    // 0x800CBCBC: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CBCC0: lui         $a1, 0x802D
    ctx->r5 = S32(0X802D << 16);
    // 0x800CBCC4: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x800CBCC8: jal         0x800C39A0
    // 0x800CBCCC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_28;
    // 0x800CBCCC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_28:
    // 0x800CBCD0: jal         0x801DC320
    // 0x800CBCD4: nop

    LOOKUP_FUNC(0x801DC320)(rdram, ctx);
        goto after_29;
    // 0x800CBCD4: nop

    after_29:
    // 0x800CBCD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CBCDC: lw          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E4C);
    // 0x800CBCE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CBCE4: bne         $t8, $at, L_800CBB30
    if (ctx->r24 != ctx->r1) {
        // 0x800CBCE8: nop
    
            goto L_800CBB30;
    }
    // 0x800CBCE8: nop

    // 0x800CBCEC: b           L_800CBCF4
    // 0x800CBCF0: nop

        goto L_800CBCF4;
    // 0x800CBCF0: nop

L_800CBCF4:
    // 0x800CBCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBCF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBCFC: jr          $ra
    // 0x800CBD00: nop

    return;
    // 0x800CBD00: nop

;}
RECOMP_FUNC void func_800CBD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBD04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CBD08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CBD0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CBD10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CBD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CBD18: jal         0x800CC378
    // 0x800CBD1C: sw          $t6, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r14;
    func_800CC378(rdram, ctx);
        goto after_0;
    // 0x800CBD1C: sw          $t6, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r14;
    after_0:
    // 0x800CBD20: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800CBD24: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x800CBD28: beq         $s0, $zero, L_800CBD50
    if (ctx->r16 == 0) {
        // 0x800CBD2C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CBD50;
    }
    // 0x800CBD2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CBD30: beq         $s0, $at, L_800CBEBC
    if (ctx->r16 == ctx->r1) {
        // 0x800CBD34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CBEBC;
    }
    // 0x800CBD34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBD38: beq         $s0, $at, L_800CC028
    if (ctx->r16 == ctx->r1) {
        // 0x800CBD3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CC028;
    }
    // 0x800CBD3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CBD40: beq         $s0, $at, L_800CC0F8
    if (ctx->r16 == ctx->r1) {
        // 0x800CBD44: nop
    
            goto L_800CC0F8;
    }
    // 0x800CBD44: nop

    // 0x800CBD48: b           L_800CC160
    // 0x800CBD4C: nop

        goto L_800CC160;
    // 0x800CBD4C: nop

L_800CBD50:
    // 0x800CBD50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CBD54: lw          $t7, -0x2E44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E44);
    // 0x800CBD58: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CBD5C: bne         $t7, $at, L_800CBD74
    if (ctx->r15 != ctx->r1) {
        // 0x800CBD60: nop
    
            goto L_800CBD74;
    }
    // 0x800CBD60: nop

    // 0x800CBD64: jal         0x800CC768
    // 0x800CBD68: nop

    func_800CC768(rdram, ctx);
        goto after_1;
    // 0x800CBD68: nop

    after_1:
    // 0x800CBD6C: b           L_800CBD90
    // 0x800CBD70: nop

        goto L_800CBD90;
    // 0x800CBD70: nop

L_800CBD74:
    // 0x800CBD74: jal         0x800CC8D0
    // 0x800CBD78: nop

    func_800CC8D0(rdram, ctx);
        goto after_2;
    // 0x800CBD78: nop

    after_2:
    // 0x800CBD7C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CBD80: lw          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E4C);
    // 0x800CBD84: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CBD88: beq         $t8, $at, L_800CC160
    if (ctx->r24 == ctx->r1) {
        // 0x800CBD8C: nop
    
            goto L_800CC160;
    }
    // 0x800CBD8C: nop

L_800CBD90:
    // 0x800CBD90: jal         0x800CC9F0
    // 0x800CBD94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_800CC9F0(rdram, ctx);
        goto after_3;
    // 0x800CBD94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_3:
    // 0x800CBD98: jal         0x800CC690
    // 0x800CBD9C: nop

    func_800CC690(rdram, ctx);
        goto after_4;
    // 0x800CBD9C: nop

    after_4:
    // 0x800CBDA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CBDA4: lw          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E4C);
    // 0x800CBDA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CBDAC: bne         $t9, $at, L_800CBDC8
    if (ctx->r25 != ctx->r1) {
        // 0x800CBDB0: nop
    
            goto L_800CBDC8;
    }
    // 0x800CBDB0: nop

    // 0x800CBDB4: jal         0x800CC4D0
    // 0x800CBDB8: nop

    func_800CC4D0(rdram, ctx);
        goto after_5;
    // 0x800CBDB8: nop

    after_5:
    // 0x800CBDBC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800CBDC0: b           L_800CBE48
    // 0x800CBDC4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_800CBE48;
    // 0x800CBDC4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_800CBDC8:
    // 0x800CBDC8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CBDCC: lw          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E4C);
    // 0x800CBDD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBDD4: bne         $t1, $at, L_800CBE10
    if (ctx->r9 != ctx->r1) {
        // 0x800CBDD8: nop
    
            goto L_800CBE10;
    }
    // 0x800CBDD8: nop

    // 0x800CBDDC: jal         0x800CC4D0
    // 0x800CBDE0: nop

    func_800CC4D0(rdram, ctx);
        goto after_6;
    // 0x800CBDE0: nop

    after_6:
    // 0x800CBDE4: jal         0x800CC6F0
    // 0x800CBDE8: nop

    func_800CC6F0(rdram, ctx);
        goto after_7;
    // 0x800CBDE8: nop

    after_7:
    // 0x800CBDEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CBDF0: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x800CBDF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBDF8: beq         $t2, $at, L_800CC160
    if (ctx->r10 == ctx->r1) {
        // 0x800CBDFC: nop
    
            goto L_800CC160;
    }
    // 0x800CBDFC: nop

    // 0x800CBE00: jal         0x800CC378
    // 0x800CBE04: nop

    func_800CC378(rdram, ctx);
        goto after_8;
    // 0x800CBE04: nop

    after_8:
    // 0x800CBE08: b           L_800CBE48
    // 0x800CBE0C: nop

        goto L_800CBE48;
    // 0x800CBE0C: nop

L_800CBE10:
    // 0x800CBE10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CBE14: lw          $t3, -0x2E4C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E4C);
    // 0x800CBE18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CBE1C: bne         $t3, $at, L_800CBE2C
    if (ctx->r11 != ctx->r1) {
        // 0x800CBE20: nop
    
            goto L_800CBE2C;
    }
    // 0x800CBE20: nop

    // 0x800CBE24: jal         0x800CCABC
    // 0x800CBE28: nop

    func_800CCABC(rdram, ctx);
        goto after_9;
    // 0x800CBE28: nop

    after_9:
L_800CBE2C:
    // 0x800CBE2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CBE30: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x800CBE34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CBE38: bne         $t4, $at, L_800CBD90
    if (ctx->r12 != ctx->r1) {
        // 0x800CBE3C: nop
    
            goto L_800CBD90;
    }
    // 0x800CBE3C: nop

    // 0x800CBE40: b           L_800CC160
    // 0x800CBE44: nop

        goto L_800CC160;
    // 0x800CBE44: nop

L_800CBE48:
    // 0x800CBE48: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800CBE4C: beq         $t5, $zero, L_800CBD50
    if (ctx->r13 == 0) {
        // 0x800CBE50: nop
    
            goto L_800CBD50;
    }
    // 0x800CBE50: nop

    // 0x800CBE54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CBE58: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x800CBE5C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CBE60: bne         $t6, $at, L_800CBEA4
    if (ctx->r14 != ctx->r1) {
        // 0x800CBE64: nop
    
            goto L_800CBEA4;
    }
    // 0x800CBE64: nop

    // 0x800CBE68: jal         0x800CC858
    // 0x800CBE6C: nop

    func_800CC858(rdram, ctx);
        goto after_10;
    // 0x800CBE6C: nop

    after_10:
    // 0x800CBE70: jal         0x800CC7E0
    // 0x800CBE74: nop

    func_800CC7E0(rdram, ctx);
        goto after_11;
    // 0x800CBE74: nop

    after_11:
    // 0x800CBE78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CBE7C: lw          $t7, -0x2E40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E40);
    // 0x800CBE80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBE84: bne         $t7, $at, L_800CC160
    if (ctx->r15 != ctx->r1) {
        // 0x800CBE88: nop
    
            goto L_800CC160;
    }
    // 0x800CBE88: nop

    // 0x800CBE8C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CBE90: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x800CBE94: lbu         $t9, 0xF($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XF);
    // 0x800CBE98: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800CBE9C: b           L_800CC160
    // 0x800CBEA0: sb          $t0, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r8;
        goto L_800CC160;
    // 0x800CBEA0: sb          $t0, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r8;
L_800CBEA4:
    // 0x800CBEA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CBEA8: lw          $t1, -0x2E44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E44);
    // 0x800CBEAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CBEB0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CBEB4: b           L_800CBD50
    // 0x800CBEB8: sw          $t2, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r10;
        goto L_800CBD50;
    // 0x800CBEB8: sw          $t2, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r10;
L_800CBEBC:
    // 0x800CBEBC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CBEC0: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x800CBEC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CBEC8: bne         $t3, $at, L_800CBEE0
    if (ctx->r11 != ctx->r1) {
        // 0x800CBECC: nop
    
            goto L_800CBEE0;
    }
    // 0x800CBECC: nop

    // 0x800CBED0: jal         0x800CC768
    // 0x800CBED4: nop

    func_800CC768(rdram, ctx);
        goto after_12;
    // 0x800CBED4: nop

    after_12:
    // 0x800CBED8: b           L_800CBEFC
    // 0x800CBEDC: nop

        goto L_800CBEFC;
    // 0x800CBEDC: nop

L_800CBEE0:
    // 0x800CBEE0: jal         0x800CC8D0
    // 0x800CBEE4: nop

    func_800CC8D0(rdram, ctx);
        goto after_13;
    // 0x800CBEE4: nop

    after_13:
    // 0x800CBEE8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CBEEC: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x800CBEF0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CBEF4: beq         $t4, $at, L_800CC160
    if (ctx->r12 == ctx->r1) {
        // 0x800CBEF8: nop
    
            goto L_800CC160;
    }
    // 0x800CBEF8: nop

L_800CBEFC:
    // 0x800CBEFC: jal         0x800CC9F0
    // 0x800CBF00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_800CC9F0(rdram, ctx);
        goto after_14;
    // 0x800CBF00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_14:
    // 0x800CBF04: jal         0x800CC690
    // 0x800CBF08: nop

    func_800CC690(rdram, ctx);
        goto after_15;
    // 0x800CBF08: nop

    after_15:
    // 0x800CBF0C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CBF10: lw          $t5, -0x2E4C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E4C);
    // 0x800CBF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CBF18: bne         $t5, $at, L_800CBF34
    if (ctx->r13 != ctx->r1) {
        // 0x800CBF1C: nop
    
            goto L_800CBF34;
    }
    // 0x800CBF1C: nop

    // 0x800CBF20: jal         0x800CC4D0
    // 0x800CBF24: nop

    func_800CC4D0(rdram, ctx);
        goto after_16;
    // 0x800CBF24: nop

    after_16:
    // 0x800CBF28: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800CBF2C: b           L_800CBFB4
    // 0x800CBF30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_800CBFB4;
    // 0x800CBF30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800CBF34:
    // 0x800CBF34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CBF38: lw          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E4C);
    // 0x800CBF3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBF40: bne         $t7, $at, L_800CBF7C
    if (ctx->r15 != ctx->r1) {
        // 0x800CBF44: nop
    
            goto L_800CBF7C;
    }
    // 0x800CBF44: nop

    // 0x800CBF48: jal         0x800CC4D0
    // 0x800CBF4C: nop

    func_800CC4D0(rdram, ctx);
        goto after_17;
    // 0x800CBF4C: nop

    after_17:
    // 0x800CBF50: jal         0x800CC6F0
    // 0x800CBF54: nop

    func_800CC6F0(rdram, ctx);
        goto after_18;
    // 0x800CBF54: nop

    after_18:
    // 0x800CBF58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CBF5C: lw          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E4C);
    // 0x800CBF60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBF64: beq         $t9, $at, L_800CC160
    if (ctx->r25 == ctx->r1) {
        // 0x800CBF68: nop
    
            goto L_800CC160;
    }
    // 0x800CBF68: nop

    // 0x800CBF6C: jal         0x800CC378
    // 0x800CBF70: nop

    func_800CC378(rdram, ctx);
        goto after_19;
    // 0x800CBF70: nop

    after_19:
    // 0x800CBF74: b           L_800CBFB4
    // 0x800CBF78: nop

        goto L_800CBFB4;
    // 0x800CBF78: nop

L_800CBF7C:
    // 0x800CBF7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CBF80: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x800CBF84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CBF88: bne         $t0, $at, L_800CBF98
    if (ctx->r8 != ctx->r1) {
        // 0x800CBF8C: nop
    
            goto L_800CBF98;
    }
    // 0x800CBF8C: nop

    // 0x800CBF90: jal         0x800CCABC
    // 0x800CBF94: nop

    func_800CCABC(rdram, ctx);
        goto after_20;
    // 0x800CBF94: nop

    after_20:
L_800CBF98:
    // 0x800CBF98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CBF9C: lw          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E4C);
    // 0x800CBFA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CBFA4: bne         $t8, $at, L_800CBEFC
    if (ctx->r24 != ctx->r1) {
        // 0x800CBFA8: nop
    
            goto L_800CBEFC;
    }
    // 0x800CBFA8: nop

    // 0x800CBFAC: b           L_800CC160
    // 0x800CBFB0: nop

        goto L_800CC160;
    // 0x800CBFB0: nop

L_800CBFB4:
    // 0x800CBFB4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CBFB8: beq         $t1, $zero, L_800CBEBC
    if (ctx->r9 == 0) {
        // 0x800CBFBC: nop
    
            goto L_800CBEBC;
    }
    // 0x800CBFBC: nop

    // 0x800CBFC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CBFC4: lw          $t2, -0x2E44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E44);
    // 0x800CBFC8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CBFCC: bne         $t2, $at, L_800CC010
    if (ctx->r10 != ctx->r1) {
        // 0x800CBFD0: nop
    
            goto L_800CC010;
    }
    // 0x800CBFD0: nop

    // 0x800CBFD4: jal         0x800CC858
    // 0x800CBFD8: nop

    func_800CC858(rdram, ctx);
        goto after_21;
    // 0x800CBFD8: nop

    after_21:
    // 0x800CBFDC: jal         0x800CC7E0
    // 0x800CBFE0: nop

    func_800CC7E0(rdram, ctx);
        goto after_22;
    // 0x800CBFE0: nop

    after_22:
    // 0x800CBFE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CBFE8: lw          $t3, -0x2E40($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E40);
    // 0x800CBFEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CBFF0: bne         $t3, $at, L_800CC160
    if (ctx->r11 != ctx->r1) {
        // 0x800CBFF4: nop
    
            goto L_800CC160;
    }
    // 0x800CBFF4: nop

    // 0x800CBFF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CBFFC: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x800CC000: lbu         $t5, 0xF($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XF);
    // 0x800CC004: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800CC008: b           L_800CC160
    // 0x800CC00C: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
        goto L_800CC160;
    // 0x800CC00C: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
L_800CC010:
    // 0x800CC010: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC014: lw          $t7, -0x2E44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E44);
    // 0x800CC018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC01C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800CC020: b           L_800CBEBC
    // 0x800CC024: sw          $t9, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r25;
        goto L_800CBEBC;
    // 0x800CC024: sw          $t9, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r25;
L_800CC028:
    // 0x800CC028: jal         0x800CC8D0
    // 0x800CC02C: nop

    func_800CC8D0(rdram, ctx);
        goto after_23;
    // 0x800CC02C: nop

    after_23:
    // 0x800CC030: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CC034: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x800CC038: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CC03C: beq         $t0, $at, L_800CC160
    if (ctx->r8 == ctx->r1) {
        // 0x800CC040: nop
    
            goto L_800CC160;
    }
    // 0x800CC040: nop

L_800CC044:
    // 0x800CC044: jal         0x800CC690
    // 0x800CC048: nop

    func_800CC690(rdram, ctx);
        goto after_24;
    // 0x800CC048: nop

    after_24:
    // 0x800CC04C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800CC050: lw          $s0, -0x2E4C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E4C);
    // 0x800CC054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC058: beq         $s0, $at, L_800CC080
    if (ctx->r16 == ctx->r1) {
        // 0x800CC05C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CC080;
    }
    // 0x800CC05C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC060: beq         $s0, $at, L_800CC160
    if (ctx->r16 == ctx->r1) {
        // 0x800CC064: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CC160;
    }
    // 0x800CC064: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC068: beq         $s0, $at, L_800CC0E8
    if (ctx->r16 == ctx->r1) {
        // 0x800CC06C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800CC0E8;
    }
    // 0x800CC06C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CC070: beq         $s0, $at, L_800CC160
    if (ctx->r16 == ctx->r1) {
        // 0x800CC074: nop
    
            goto L_800CC160;
    }
    // 0x800CC074: nop

    // 0x800CC078: b           L_800CC044
    // 0x800CC07C: nop

        goto L_800CC044;
    // 0x800CC07C: nop

L_800CC080:
    // 0x800CC080: jal         0x800C25A4
    // 0x800CC084: nop

    func_800C25A4(rdram, ctx);
        goto after_25;
    // 0x800CC084: nop

    after_25:
    // 0x800CC088: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC08C: jal         0x800C38C8
    // 0x800CC090: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_26;
    // 0x800CC090: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_26:
    // 0x800CC094: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC098: jal         0x800C3930
    // 0x800CC09C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_27;
    // 0x800CC09C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_27:
    // 0x800CC0A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC0A4: jal         0x800C38C8
    // 0x800CC0A8: addiu       $a0, $a0, -0x4AB8
    ctx->r4 = ADD32(ctx->r4, -0X4AB8);
    func_800C38C8(rdram, ctx);
        goto after_28;
    // 0x800CC0A8: addiu       $a0, $a0, -0x4AB8
    ctx->r4 = ADD32(ctx->r4, -0X4AB8);
    after_28:
    // 0x800CC0AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC0B0: jal         0x800C3930
    // 0x800CC0B4: addiu       $a0, $a0, -0x4A98
    ctx->r4 = ADD32(ctx->r4, -0X4A98);
    func_800C3930(rdram, ctx);
        goto after_29;
    // 0x800CC0B4: addiu       $a0, $a0, -0x4A98
    ctx->r4 = ADD32(ctx->r4, -0X4A98);
    after_29:
    // 0x800CC0B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC0BC: jal         0x800C3968
    // 0x800CC0C0: addiu       $a0, $a0, -0x4A88
    ctx->r4 = ADD32(ctx->r4, -0X4A88);
    func_800C3968(rdram, ctx);
        goto after_30;
    // 0x800CC0C0: addiu       $a0, $a0, -0x4A88
    ctx->r4 = ADD32(ctx->r4, -0X4A88);
    after_30:
    // 0x800CC0C4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC0C8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC0CC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC0D0: jal         0x800C39A0
    // 0x800CC0D4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_31;
    // 0x800CC0D4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_31:
    // 0x800CC0D8: jal         0x8017DA00
    // 0x800CC0DC: nop

    func_8017DA00_0EF7C0(rdram, ctx);
        goto after_32;
    // 0x800CC0DC: nop

    after_32:
    // 0x800CC0E0: b           L_800CC160
    // 0x800CC0E4: nop

        goto L_800CC160;
    // 0x800CC0E4: nop

L_800CC0E8:
    // 0x800CC0E8: jal         0x800CC378
    // 0x800CC0EC: nop

    func_800CC378(rdram, ctx);
        goto after_33;
    // 0x800CC0EC: nop

    after_33:
    // 0x800CC0F0: b           L_800CC044
    // 0x800CC0F4: nop

        goto L_800CC044;
    // 0x800CC0F4: nop

L_800CC0F8:
    // 0x800CC0F8: jal         0x800CC8D0
    // 0x800CC0FC: nop

    func_800CC8D0(rdram, ctx);
        goto after_34;
    // 0x800CC0FC: nop

    after_34:
    // 0x800CC100: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC104: lw          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E4C);
    // 0x800CC108: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CC10C: beq         $t8, $at, L_800CC160
    if (ctx->r24 == ctx->r1) {
        // 0x800CC110: nop
    
            goto L_800CC160;
    }
    // 0x800CC110: nop

    // 0x800CC114: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CC118: lw          $t1, -0x2E40($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E40);
    // 0x800CC11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC120: sw          $zero, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = 0;
    // 0x800CC124: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_800CC128:
    // 0x800CC128: jal         0x800CC690
    // 0x800CC12C: nop

    func_800CC690(rdram, ctx);
        goto after_35;
    // 0x800CC12C: nop

    after_35:
    // 0x800CC130: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CC134: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x800CC138: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC13C: bne         $t2, $at, L_800CC154
    if (ctx->r10 != ctx->r1) {
        // 0x800CC140: nop
    
            goto L_800CC154;
    }
    // 0x800CC140: nop

    // 0x800CC144: jal         0x800CC378
    // 0x800CC148: nop

    func_800CC378(rdram, ctx);
        goto after_36;
    // 0x800CC148: nop

    after_36:
    // 0x800CC14C: b           L_800CC128
    // 0x800CC150: nop

        goto L_800CC128;
    // 0x800CC150: nop

L_800CC154:
    // 0x800CC154: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800CC158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC15C: sw          $t3, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r11;
L_800CC160:
    // 0x800CC160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CC168: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CC16C: jr          $ra
    // 0x800CC170: nop

    return;
    // 0x800CC170: nop

;}
RECOMP_FUNC void func_800CC174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC174: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800CC178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC17C: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x800CC180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CC184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC188: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC190: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x800CC194: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x800CC198: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x800CC19C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC1A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CC1A4: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x800CC1A8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    // 0x800CC1AC: sw          $zero, -0x2E48($at)
    MEM_W(-0X2E48, ctx->r1) = 0;
    // 0x800CC1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC1B4: jal         0x800C2500
    // 0x800CC1B8: sw          $t0, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r8;
    func_800C2500(rdram, ctx);
        goto after_0;
    // 0x800CC1B8: sw          $t0, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r8;
    after_0:
    // 0x800CC1BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800CC1C0:
    // 0x800CC1C0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CC1C4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800CC1C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC1CC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800CC1D0: sb          $zero, -0x2E28($at)
    MEM_B(-0X2E28, ctx->r1) = 0;
    // 0x800CC1D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800CC1D8: sltiu       $at, $t3, 0x10
    ctx->r1 = ctx->r11 < 0X10 ? 1 : 0;
    // 0x800CC1DC: bne         $at, $zero, L_800CC1C0
    if (ctx->r1 != 0) {
        // 0x800CC1E0: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800CC1C0;
    }
    // 0x800CC1E0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800CC1E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800CC1E8:
    // 0x800CC1E8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800CC1EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800CC1F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC1F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800CC1F8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800CC1FC: sw          $zero, -0x2E18($at)
    MEM_W(-0X2E18, ctx->r1) = 0;
    // 0x800CC200: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800CC204: sltiu       $at, $t8, 0x20
    ctx->r1 = ctx->r24 < 0X20 ? 1 : 0;
    // 0x800CC208: bne         $at, $zero, L_800CC1E8
    if (ctx->r1 != 0) {
        // 0x800CC20C: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800CC1E8;
    }
    // 0x800CC20C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800CC210: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800CC214:
    // 0x800CC214: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CC218: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CC21C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC220: sll         $t7, $t9, 5
    ctx->r15 = S32(ctx->r25 << 5);
    // 0x800CC224: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800CC228: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800CC22C: sw          $zero, 0x39A0($at)
    MEM_W(0X39A0, ctx->r1) = 0;
    // 0x800CC230: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC234: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800CC238: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CC23C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CC240: sw          $t0, 0x39A4($at)
    MEM_W(0X39A4, ctx->r1) = ctx->r8;
    // 0x800CC244: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CC248: sltiu       $at, $t4, 0x4
    ctx->r1 = ctx->r12 < 0X4 ? 1 : 0;
    // 0x800CC24C: bne         $at, $zero, L_800CC214
    if (ctx->r1 != 0) {
        // 0x800CC250: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_800CC214;
    }
    // 0x800CC250: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800CC254: addiu       $t5, $zero, 0x1770
    ctx->r13 = ADD32(0, 0X1770);
    // 0x800CC258: addiu       $t6, $zero, 0x2BC
    ctx->r14 = ADD32(0, 0X2BC);
    // 0x800CC25C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800CC260: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800CC264: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800CC268:
    // 0x800CC268: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CC26C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800CC270: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800CC274: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800CC278: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800CC27C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800CC280: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CC284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC288: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800CC28C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800CC290: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800CC294: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC298: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800CC29C: sw          $t8, 0x3A38($at)
    MEM_W(0X3A38, ctx->r1) = ctx->r24;
    // 0x800CC2A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC2A4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800CC2A8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CC2AC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800CC2B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CC2B4: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x800CC2B8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800CC2BC: sw          $t1, 0x3A40($at)
    MEM_W(0X3A40, ctx->r1) = ctx->r9;
    // 0x800CC2C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC2C4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800CC2C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC2CC: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800CC2D0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800CC2D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CC2D8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800CC2DC: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x800CC2E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CC2E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800CC2E8: addiu       $t0, $t0, -0x52C0
    ctx->r8 = ADD32(ctx->r8, -0X52C0);
    // 0x800CC2EC: addiu       $t8, $t8, 0x3A20
    ctx->r24 = ADD32(ctx->r24, 0X3A20);
    // 0x800CC2F0: sw          $t3, 0x3A3C($at)
    MEM_W(0X3A3C, ctx->r1) = ctx->r11;
    // 0x800CC2F4: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800CC2F8: jal         0x800E4C90
    // 0x800CC2FC: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    func_800E4C90(rdram, ctx);
        goto after_1;
    // 0x800CC2FC: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_1:
    // 0x800CC300: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CC304: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC308: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800CC30C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800CC310: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800CC314: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x800CC318: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800CC31C: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800CC320: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800CC324: addiu       $t4, $t2, 0xC
    ctx->r12 = ADD32(ctx->r10, 0XC);
    // 0x800CC328: addiu       $t9, $t9, -0x5284
    ctx->r25 = ADD32(ctx->r25, -0X5284);
    // 0x800CC32C: addiu       $t3, $t3, 0x3A20
    ctx->r11 = ADD32(ctx->r11, 0X3A20);
    // 0x800CC330: addu        $a0, $t4, $t3
    ctx->r4 = ADD32(ctx->r12, ctx->r11);
    // 0x800CC334: jal         0x800E4C90
    // 0x800CC338: addu        $a1, $t5, $t9
    ctx->r5 = ADD32(ctx->r13, ctx->r25);
    func_800E4C90(rdram, ctx);
        goto after_2;
    // 0x800CC338: addu        $a1, $t5, $t9
    ctx->r5 = ADD32(ctx->r13, ctx->r25);
    after_2:
    // 0x800CC33C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800CC340: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800CC344: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC348: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800CC34C: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x800CC350: addiu       $t6, $t8, -0x3E8
    ctx->r14 = ADD32(ctx->r24, -0X3E8);
    // 0x800CC354: addiu       $t0, $t7, -0x64
    ctx->r8 = ADD32(ctx->r15, -0X64);
    // 0x800CC358: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800CC35C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800CC360: bne         $at, $zero, L_800CC268
    if (ctx->r1 != 0) {
        // 0x800CC364: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800CC268;
    }
    // 0x800CC364: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800CC368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC36C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CC370: jr          $ra
    // 0x800CC374: nop

    return;
    // 0x800CC374: nop

;}
RECOMP_FUNC void func_800CC378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC378: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC37C: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x800CC380: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC384: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x800CC388: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x800CC38C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800CC390: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CC394: addiu       $t9, $t9, 0x3988
    ctx->r25 = ADD32(ctx->r25, 0X3988);
    // 0x800CC398: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CC39C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800CC3A0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800CC3A4: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x800CC3A8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800CC3AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CC3B0: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x800CC3B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC3B8: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800CC3BC: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x800CC3C0: addiu       $t3, $t3, 0x3988
    ctx->r11 = ADD32(ctx->r11, 0X3988);
    // 0x800CC3C4: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x800CC3C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CC3CC: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x800CC3D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC3D4: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    // 0x800CC3D8: sw          $zero, 0x18($t5)
    MEM_W(0X18, ctx->r13) = 0;
    // 0x800CC3DC: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x800CC3E0: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800CC3E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC3E8: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x800CC3EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CC3F0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x800CC3F4: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
    // 0x800CC3F8: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x800CC3FC: lw          $t1, 0x20($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X20);
    // 0x800CC400: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CC404: sw          $t1, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r9;
    // 0x800CC408: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CC40C:
    // 0x800CC40C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CC410: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800CC414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC418: sll         $t2, $t0, 5
    ctx->r10 = S32(ctx->r8 << 5);
    // 0x800CC41C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CC420: sw          $zero, 0x39B0($at)
    MEM_W(0X39B0, ctx->r1) = 0;
    // 0x800CC424: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800CC428: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800CC42C: bne         $at, $zero, L_800CC40C
    if (ctx->r1 != 0) {
        // 0x800CC430: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800CC40C;
    }
    // 0x800CC430: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800CC434: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CC438: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x800CC43C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC440: beq         $t5, $at, L_800CC47C
    if (ctx->r13 == ctx->r1) {
        // 0x800CC444: nop
    
            goto L_800CC47C;
    }
    // 0x800CC444: nop

    // 0x800CC448: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CC44C:
    // 0x800CC44C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CC450: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800CC454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC458: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800CC45C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CC460: sw          $t8, 0x39A8($at)
    MEM_W(0X39A8, ctx->r1) = ctx->r24;
    // 0x800CC464: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x800CC468: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x800CC46C: bne         $at, $zero, L_800CC44C
    if (ctx->r1 != 0) {
        // 0x800CC470: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800CC44C;
    }
    // 0x800CC470: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800CC474: b           L_800CC4AC
    // 0x800CC478: nop

        goto L_800CC4AC;
    // 0x800CC478: nop

L_800CC47C:
    // 0x800CC47C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CC480:
    // 0x800CC480: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CC484: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800CC488: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CC48C: sll         $t2, $t0, 5
    ctx->r10 = S32(ctx->r8 << 5);
    // 0x800CC490: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CC494: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800CC498: sw          $t9, 0x39A8($at)
    MEM_W(0X39A8, ctx->r1) = ctx->r25;
    // 0x800CC49C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800CC4A0: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800CC4A4: bne         $at, $zero, L_800CC480
    if (ctx->r1 != 0) {
        // 0x800CC4A8: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800CC480;
    }
    // 0x800CC4A8: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_800CC4AC:
    // 0x800CC4AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CC4B0: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x800CC4B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC4B8: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x800CC4BC: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x800CC4C0: lw          $t6, 0x4C($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4C);
    // 0x800CC4C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800CC4C8: jr          $ra
    // 0x800CC4CC: sw          $t6, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r14;
    return;
    // 0x800CC4CC: sw          $t6, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_800CC4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC4D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CC4D4: lw          $a0, -0x2E48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2E48);
    // 0x800CC4D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CC4DC: beq         $a0, $zero, L_800CC4FC
    if (ctx->r4 == 0) {
        // 0x800CC4E0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CC4FC;
    }
    // 0x800CC4E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC4E4: beq         $a0, $at, L_800CC540
    if (ctx->r4 == ctx->r1) {
        // 0x800CC4E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CC540;
    }
    // 0x800CC4E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC4EC: beq         $a0, $at, L_800CC5C0
    if (ctx->r4 == ctx->r1) {
        // 0x800CC4F0: nop
    
            goto L_800CC5C0;
    }
    // 0x800CC4F0: nop

    // 0x800CC4F4: b           L_800CC688
    // 0x800CC4F8: nop

        goto L_800CC688;
    // 0x800CC4F8: nop

L_800CC4FC:
    // 0x800CC4FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC500: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC504: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x800CC508: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x800CC50C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CC510: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x800CC514: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CC518: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC51C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800CC520: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800CC524: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x800CC528: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x800CC52C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800CC530: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800CC534: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800CC538: b           L_800CC688
    // 0x800CC53C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
        goto L_800CC688;
    // 0x800CC53C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
L_800CC540:
    // 0x800CC540: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC544: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CC548: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x800CC54C: addiu       $t8, $t8, 0x3988
    ctx->r24 = ADD32(ctx->r24, 0X3988);
    // 0x800CC550: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x800CC554: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x800CC558: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC55C: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x800CC560: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800CC564: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x800CC568: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800CC56C: beq         $t3, $zero, L_800CC688
    if (ctx->r11 == 0) {
        // 0x800CC570: nop
    
            goto L_800CC688;
    }
    // 0x800CC570: nop

L_800CC574:
    // 0x800CC574: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800CC578: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CC57C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CC580: sll         $t1, $t5, 5
    ctx->r9 = S32(ctx->r13 << 5);
    // 0x800CC584: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x800CC588: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x800CC58C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800CC590: lw          $t9, 0x39BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X39BC);
    // 0x800CC594: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC598: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x800CC59C: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x800CC5A0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CC5A4: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x800CC5A8: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x800CC5AC: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x800CC5B0: bne         $at, $zero, L_800CC574
    if (ctx->r1 != 0) {
        // 0x800CC5B4: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800CC574;
    }
    // 0x800CC5B4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800CC5B8: b           L_800CC688
    // 0x800CC5BC: nop

        goto L_800CC688;
    // 0x800CC5BC: nop

L_800CC5C0:
    // 0x800CC5C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC5C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CC5C8: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x800CC5CC: addiu       $t3, $t3, 0x3988
    ctx->r11 = ADD32(ctx->r11, 0X3988);
    // 0x800CC5D0: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800CC5D4: lw          $t4, 0x64($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X64);
    // 0x800CC5D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC5DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC5E0: addu        $t9, $t5, $t4
    ctx->r25 = ADD32(ctx->r13, ctx->r12);
    // 0x800CC5E4: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x800CC5E8: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x800CC5EC: bne         $t7, $at, L_800CC638
    if (ctx->r15 != ctx->r1) {
        // 0x800CC5F0: nop
    
            goto L_800CC638;
    }
    // 0x800CC5F0: nop

    // 0x800CC5F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CC5F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC5FC: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x800CC600: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x800CC604: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x800CC608: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x800CC60C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CC610: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CC614: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x800CC618: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800CC61C: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x800CC620: addiu       $t5, $t5, 0x3988
    ctx->r13 = ADD32(ctx->r13, 0X3988);
    // 0x800CC624: lw          $t4, 0x14($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X14);
    // 0x800CC628: lw          $t3, 0x3C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X3C);
    // 0x800CC62C: addu        $t7, $t4, $t3
    ctx->r15 = ADD32(ctx->r12, ctx->r11);
    // 0x800CC630: b           L_800CC688
    // 0x800CC634: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_800CC688;
    // 0x800CC634: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_800CC638:
    // 0x800CC638: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC63C: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x800CC640: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CC644: lw          $t0, 0x1C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X1C);
    // 0x800CC648: lw          $t8, 0x5C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X5C);
    // 0x800CC64C: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x800CC650: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x800CC654: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x800CC658: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CC65C: addu        $t4, $t9, $t1
    ctx->r12 = ADD32(ctx->r25, ctx->r9);
    // 0x800CC660: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x800CC664: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x800CC668: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CC66C: lw          $t7, 0x3C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X3C);
    // 0x800CC670: lw          $t5, 0x7C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X7C);
    // 0x800CC674: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x800CC678: lw          $t8, 0x14($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X14);
    // 0x800CC67C: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800CC680: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800CC684: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
L_800CC688:
    // 0x800CC688: jr          $ra
    // 0x800CC68C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CC68C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CC690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC698: jal         0x800C25A4
    // 0x800CC69C: nop

    func_800C25A4(rdram, ctx);
        goto after_0;
    // 0x800CC69C: nop

    after_0:
    // 0x800CC6A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC6A4: jal         0x800C38C8
    // 0x800CC6A8: addiu       $a0, $a0, -0x4938
    ctx->r4 = ADD32(ctx->r4, -0X4938);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x800CC6A8: addiu       $a0, $a0, -0x4938
    ctx->r4 = ADD32(ctx->r4, -0X4938);
    after_1:
    // 0x800CC6AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC6B0: jal         0x800C3930
    // 0x800CC6B4: addiu       $a0, $a0, -0x4918
    ctx->r4 = ADD32(ctx->r4, -0X4918);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x800CC6B4: addiu       $a0, $a0, -0x4918
    ctx->r4 = ADD32(ctx->r4, -0X4918);
    after_2:
    // 0x800CC6B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC6BC: jal         0x800C3968
    // 0x800CC6C0: addiu       $a0, $a0, -0x4908
    ctx->r4 = ADD32(ctx->r4, -0X4908);
    func_800C3968(rdram, ctx);
        goto after_3;
    // 0x800CC6C0: addiu       $a0, $a0, -0x4908
    ctx->r4 = ADD32(ctx->r4, -0X4908);
    after_3:
    // 0x800CC6C4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC6C8: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x800CC6CC: addiu       $a1, $a1, -0x1C00
    ctx->r5 = ADD32(ctx->r5, -0X1C00);
    // 0x800CC6D0: jal         0x800C39A0
    // 0x800CC6D4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_4;
    // 0x800CC6D4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_4:
    // 0x800CC6D8: jal         0x8019CE04
    // 0x800CC6DC: nop

    func_8019CE04_1501A0(rdram, ctx);
        goto after_5;
    // 0x800CC6DC: nop

    after_5:
    // 0x800CC6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC6E8: jr          $ra
    // 0x800CC6EC: nop

    return;
    // 0x800CC6EC: nop

;}
RECOMP_FUNC void func_800CC6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC6F8: jal         0x800C25A4
    // 0x800CC6FC: nop

    func_800C25A4(rdram, ctx);
        goto after_0;
    // 0x800CC6FC: nop

    after_0:
    // 0x800CC700: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC704: jal         0x800C38C8
    // 0x800CC708: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x800CC708: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_1:
    // 0x800CC70C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC710: jal         0x800C3930
    // 0x800CC714: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x800CC714: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_2:
    // 0x800CC718: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC71C: jal         0x800C38C8
    // 0x800CC720: addiu       $a0, $a0, -0x4974
    ctx->r4 = ADD32(ctx->r4, -0X4974);
    func_800C38C8(rdram, ctx);
        goto after_3;
    // 0x800CC720: addiu       $a0, $a0, -0x4974
    ctx->r4 = ADD32(ctx->r4, -0X4974);
    after_3:
    // 0x800CC724: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC728: jal         0x800C3930
    // 0x800CC72C: addiu       $a0, $a0, -0x4954
    ctx->r4 = ADD32(ctx->r4, -0X4954);
    func_800C3930(rdram, ctx);
        goto after_4;
    // 0x800CC72C: addiu       $a0, $a0, -0x4954
    ctx->r4 = ADD32(ctx->r4, -0X4954);
    after_4:
    // 0x800CC730: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC734: jal         0x800C3968
    // 0x800CC738: addiu       $a0, $a0, -0x4944
    ctx->r4 = ADD32(ctx->r4, -0X4944);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x800CC738: addiu       $a0, $a0, -0x4944
    ctx->r4 = ADD32(ctx->r4, -0X4944);
    after_5:
    // 0x800CC73C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC740: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC744: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC748: jal         0x800C39A0
    // 0x800CC74C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_6;
    // 0x800CC74C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // 0x800CC750: jal         0x8017B0C0
    // 0x800CC754: nop

    LOOKUP_FUNC(0x8017B0C0)(rdram, ctx);
        goto after_7;
    // 0x800CC754: nop

    after_7:
    // 0x800CC758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC760: jr          $ra
    // 0x800CC764: nop

    return;
    // 0x800CC764: nop

;}
RECOMP_FUNC void func_800CC768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC770: jal         0x800C25A4
    // 0x800CC774: nop

    func_800C25A4(rdram, ctx);
        goto after_0;
    // 0x800CC774: nop

    after_0:
    // 0x800CC778: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC77C: jal         0x800C38C8
    // 0x800CC780: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x800CC780: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_1:
    // 0x800CC784: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC788: jal         0x800C3930
    // 0x800CC78C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x800CC78C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_2:
    // 0x800CC790: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC794: jal         0x800C3930
    // 0x800CC798: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    func_800C3930(rdram, ctx);
        goto after_3;
    // 0x800CC798: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    after_3:
    // 0x800CC79C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC7A0: jal         0x800C38C8
    // 0x800CC7A4: addiu       $a0, $a0, -0x4730
    ctx->r4 = ADD32(ctx->r4, -0X4730);
    func_800C38C8(rdram, ctx);
        goto after_4;
    // 0x800CC7A4: addiu       $a0, $a0, -0x4730
    ctx->r4 = ADD32(ctx->r4, -0X4730);
    after_4:
    // 0x800CC7A8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC7AC: jal         0x800C3968
    // 0x800CC7B0: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x800CC7B0: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    after_5:
    // 0x800CC7B4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC7B8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC7BC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC7C0: jal         0x800C39A0
    // 0x800CC7C4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_6;
    // 0x800CC7C4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // 0x800CC7C8: jal         0x801DC320
    // 0x800CC7CC: nop

    LOOKUP_FUNC(0x801DC320)(rdram, ctx);
        goto after_7;
    // 0x800CC7CC: nop

    after_7:
    // 0x800CC7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC7D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC7D8: jr          $ra
    // 0x800CC7DC: nop

    return;
    // 0x800CC7DC: nop

;}
RECOMP_FUNC void func_800CC7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC7E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC7E8: jal         0x800C25A4
    // 0x800CC7EC: nop

    func_800C25A4(rdram, ctx);
        goto after_0;
    // 0x800CC7EC: nop

    after_0:
    // 0x800CC7F0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC7F4: jal         0x800C38C8
    // 0x800CC7F8: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x800CC7F8: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_1:
    // 0x800CC7FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC800: jal         0x800C3930
    // 0x800CC804: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x800CC804: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_2:
    // 0x800CC808: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC80C: jal         0x800C38C8
    // 0x800CC810: addiu       $a0, $a0, -0x4974
    ctx->r4 = ADD32(ctx->r4, -0X4974);
    func_800C38C8(rdram, ctx);
        goto after_3;
    // 0x800CC810: addiu       $a0, $a0, -0x4974
    ctx->r4 = ADD32(ctx->r4, -0X4974);
    after_3:
    // 0x800CC814: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC818: jal         0x800C3930
    // 0x800CC81C: addiu       $a0, $a0, -0x4954
    ctx->r4 = ADD32(ctx->r4, -0X4954);
    func_800C3930(rdram, ctx);
        goto after_4;
    // 0x800CC81C: addiu       $a0, $a0, -0x4954
    ctx->r4 = ADD32(ctx->r4, -0X4954);
    after_4:
    // 0x800CC820: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC824: jal         0x800C3968
    // 0x800CC828: addiu       $a0, $a0, -0x4944
    ctx->r4 = ADD32(ctx->r4, -0X4944);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x800CC828: addiu       $a0, $a0, -0x4944
    ctx->r4 = ADD32(ctx->r4, -0X4944);
    after_5:
    // 0x800CC82C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC830: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC834: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC838: jal         0x800C39A0
    // 0x800CC83C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_6;
    // 0x800CC83C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // 0x800CC840: jal         0x8017BE90
    // 0x800CC844: nop

    func_8017BE90_12C2F0(rdram, ctx);
        goto after_7;
    // 0x800CC844: nop

    after_7:
    // 0x800CC848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC84C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC850: jr          $ra
    // 0x800CC854: nop

    return;
    // 0x800CC854: nop

;}
RECOMP_FUNC void func_800CC858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC860: jal         0x800C25A4
    // 0x800CC864: nop

    func_800C25A4(rdram, ctx);
        goto after_0;
    // 0x800CC864: nop

    after_0:
    // 0x800CC868: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC86C: jal         0x800C38C8
    // 0x800CC870: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x800CC870: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_1:
    // 0x800CC874: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC878: jal         0x800C3930
    // 0x800CC87C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x800CC87C: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_2:
    // 0x800CC880: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC884: jal         0x800C3930
    // 0x800CC888: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    func_800C3930(rdram, ctx);
        goto after_3;
    // 0x800CC888: addiu       $a0, $a0, -0x499C
    ctx->r4 = ADD32(ctx->r4, -0X499C);
    after_3:
    // 0x800CC88C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC890: jal         0x800C38C8
    // 0x800CC894: addiu       $a0, $a0, -0x49BC
    ctx->r4 = ADD32(ctx->r4, -0X49BC);
    func_800C38C8(rdram, ctx);
        goto after_4;
    // 0x800CC894: addiu       $a0, $a0, -0x49BC
    ctx->r4 = ADD32(ctx->r4, -0X49BC);
    after_4:
    // 0x800CC898: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC89C: jal         0x800C3968
    // 0x800CC8A0: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x800CC8A0: addiu       $a0, $a0, -0x498C
    ctx->r4 = ADD32(ctx->r4, -0X498C);
    after_5:
    // 0x800CC8A4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC8A8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC8AC: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC8B0: jal         0x800C39A0
    // 0x800CC8B4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_6;
    // 0x800CC8B4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_6:
    // 0x800CC8B8: jal         0x801E02C0
    // 0x800CC8BC: nop

    func_801E02C0_0BA450(rdram, ctx);
        goto after_7;
    // 0x800CC8BC: nop

    after_7:
    // 0x800CC8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC8C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC8C8: jr          $ra
    // 0x800CC8CC: nop

    return;
    // 0x800CC8CC: nop

;}
RECOMP_FUNC void func_800CC8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC8D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CC8D4: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x800CC8D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CC8DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CC8E0: beq         $t6, $at, L_800CC9E0
    if (ctx->r14 == ctx->r1) {
        // 0x800CC8E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CC9E0;
    }
    // 0x800CC8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC8E8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC8EC: jal         0x800C38C8
    // 0x800CC8F0: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    func_800C38C8(rdram, ctx);
        goto after_0;
    // 0x800CC8F0: addiu       $a0, $a0, -0x4B60
    ctx->r4 = ADD32(ctx->r4, -0X4B60);
    after_0:
    // 0x800CC8F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC8F8: jal         0x800C3930
    // 0x800CC8FC: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    func_800C3930(rdram, ctx);
        goto after_1;
    // 0x800CC8FC: addiu       $a0, $a0, -0x4B40
    ctx->r4 = ADD32(ctx->r4, -0X4B40);
    after_1:
    // 0x800CC900: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC904: jal         0x800C38C8
    // 0x800CC908: addiu       $a0, $a0, -0x49F8
    ctx->r4 = ADD32(ctx->r4, -0X49F8);
    func_800C38C8(rdram, ctx);
        goto after_2;
    // 0x800CC908: addiu       $a0, $a0, -0x49F8
    ctx->r4 = ADD32(ctx->r4, -0X49F8);
    after_2:
    // 0x800CC90C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC910: jal         0x800C3930
    // 0x800CC914: addiu       $a0, $a0, -0x49D8
    ctx->r4 = ADD32(ctx->r4, -0X49D8);
    func_800C3930(rdram, ctx);
        goto after_3;
    // 0x800CC914: addiu       $a0, $a0, -0x49D8
    ctx->r4 = ADD32(ctx->r4, -0X49D8);
    after_3:
    // 0x800CC918: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CC91C: jal         0x800C3968
    // 0x800CC920: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    func_800C3968(rdram, ctx);
        goto after_4;
    // 0x800CC920: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    after_4:
    // 0x800CC924: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800CC928: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800CC92C: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x800CC930: jal         0x800C39A0
    // 0x800CC934: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_5;
    // 0x800CC934: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_5:
    // 0x800CC938: jal         0x8017B650
    // 0x800CC93C: nop

    func_8017B650_1199D0(rdram, ctx);
        goto after_6;
    // 0x800CC93C: nop

    after_6:
    // 0x800CC940: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CC944: lw          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E4C);
    // 0x800CC948: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CC94C: beq         $t7, $at, L_800CC9E0
    if (ctx->r15 == ctx->r1) {
        // 0x800CC950: nop
    
            goto L_800CC9E0;
    }
    // 0x800CC950: nop

    // 0x800CC954: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC958: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x800CC95C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800CC960: beq         $t8, $zero, L_800CC9E0
    if (ctx->r24 == 0) {
        // 0x800CC964: nop
    
            goto L_800CC9E0;
    }
    // 0x800CC964: nop

L_800CC968:
    // 0x800CC968: jal         0x800D1E30
    // 0x800CC96C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D1E30(rdram, ctx);
        goto after_7;
    // 0x800CC96C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x800CC970: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800CC974: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800CC978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC97C: beq         $t9, $at, L_800CC9C0
    if (ctx->r25 == ctx->r1) {
        // 0x800CC980: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800CC9C0;
    }
    // 0x800CC980: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800CC984: beq         $t9, $at, L_800CC9C0
    if (ctx->r25 == ctx->r1) {
        // 0x800CC988: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800CC9C0;
    }
    // 0x800CC988: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CC98C: beq         $t9, $at, L_800CC9C0
    if (ctx->r25 == ctx->r1) {
        // 0x800CC990: nop
    
            goto L_800CC9C0;
    }
    // 0x800CC990: nop

    // 0x800CC994: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CC998: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC99C: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x800CC9A0: lbu         $t1, 0xF($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XF);
    // 0x800CC9A4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800CC9A8: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x800CC9AC: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x800CC9B0: sb          $t5, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r13;
    // 0x800CC9B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC9B8: jal         0x800D1F00
    // 0x800CC9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D1F00(rdram, ctx);
        goto after_8;
    // 0x800CC9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_800CC9C0:
    // 0x800CC9C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC9C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CC9C8: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x800CC9CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CC9D0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800CC9D4: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x800CC9D8: bne         $at, $zero, L_800CC968
    if (ctx->r1 != 0) {
        // 0x800CC9DC: nop
    
            goto L_800CC968;
    }
    // 0x800CC9DC: nop

L_800CC9E0:
    // 0x800CC9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC9E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CC9E8: jr          $ra
    // 0x800CC9EC: nop

    return;
    // 0x800CC9EC: nop

;}
RECOMP_FUNC void func_800CC9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC9F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CC9F4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CC9F8:
    // 0x800CC9F8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800CC9FC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CCA00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CCA04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CCA08: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CCA0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CCA10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CCA14: lw          $t8, 0x3988($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3988);
    // 0x800CCA18: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800CCA1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCA20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CCA24: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800CCA28: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800CCA2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CCA30: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800CCA34: lw          $t2, -0x2B94($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B94);
    // 0x800CCA38: sw          $t8, 0x3AD8($at)
    MEM_W(0X3AD8, ctx->r1) = ctx->r24;
    // 0x800CCA3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCA40: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CCA44: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800CCA48: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800CCA4C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800CCA50: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800CCA54: lw          $t5, -0x2B8C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2B8C);
    // 0x800CCA58: sw          $t2, 0x3AE0($at)
    MEM_W(0X3AE0, ctx->r1) = ctx->r10;
    // 0x800CCA5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCA60: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CCA64: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800CCA68: sw          $t5, 0x3AE8($at)
    MEM_W(0X3AE8, ctx->r1) = ctx->r13;
    // 0x800CCA6C: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x800CCA70: bne         $at, $zero, L_800CC9F8
    if (ctx->r1 != 0) {
        // 0x800CCA74: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800CC9F8;
    }
    // 0x800CCA74: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800CCA78: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CCA7C:
    // 0x800CCA7C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CCA80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CCA84: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800CCA88: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800CCA8C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800CCA90: lw          $t0, 0x39B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X39B0);
    // 0x800CCA94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCA98: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800CCA9C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CCAA0: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800CCAA4: sw          $t0, 0x3AF0($at)
    MEM_W(0X3AF0, ctx->r1) = ctx->r8;
    // 0x800CCAA8: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800CCAAC: bne         $at, $zero, L_800CCA7C
    if (ctx->r1 != 0) {
        // 0x800CCAB0: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800CCA7C;
    }
    // 0x800CCAB0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800CCAB4: jr          $ra
    // 0x800CCAB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CCAB8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CCABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCABC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CCAC0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CCAC4:
    // 0x800CCAC4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800CCAC8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CCACC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CCAD0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CCAD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CCAD8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800CCADC: lw          $t8, 0x3AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3AD8);
    // 0x800CCAE0: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800CCAE4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800CCAE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800CCAEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCAF0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CCAF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800CCAF8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CCAFC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800CCB00: lw          $t2, 0x3AE0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3AE0);
    // 0x800CCB04: sw          $t8, 0x3988($at)
    MEM_W(0X3988, ctx->r1) = ctx->r24;
    // 0x800CCB08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCB0C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CCB10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800CCB14: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800CCB18: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800CCB1C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800CCB20: lw          $t5, 0x3AE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AE8);
    // 0x800CCB24: sw          $t2, -0x2B94($at)
    MEM_W(-0X2B94, ctx->r1) = ctx->r10;
    // 0x800CCB28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCB2C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CCB30: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800CCB34: sw          $t5, -0x2B8C($at)
    MEM_W(-0X2B8C, ctx->r1) = ctx->r13;
    // 0x800CCB38: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x800CCB3C: bne         $at, $zero, L_800CCAC4
    if (ctx->r1 != 0) {
        // 0x800CCB40: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800CCAC4;
    }
    // 0x800CCB40: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800CCB44: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CCB48:
    // 0x800CCB48: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CCB4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CCB50: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800CCB54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CCB58: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800CCB5C: lw          $t0, 0x3AF0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3AF0);
    // 0x800CCB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCB64: sll         $t2, $t8, 5
    ctx->r10 = S32(ctx->r24 << 5);
    // 0x800CCB68: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CCB6C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800CCB70: sw          $t0, 0x39B0($at)
    MEM_W(0X39B0, ctx->r1) = ctx->r8;
    // 0x800CCB74: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800CCB78: bne         $at, $zero, L_800CCB48
    if (ctx->r1 != 0) {
        // 0x800CCB7C: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800CCB48;
    }
    // 0x800CCB7C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800CCB80: jr          $ra
    // 0x800CCB84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CCB84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CCB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCB88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CCB8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCB90: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CCB94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CCB98: jal         0x800C3968
    // 0x800CCB9C: addiu       $a0, $a0, -0x48FC
    ctx->r4 = ADD32(ctx->r4, -0X48FC);
    func_800C3968(rdram, ctx);
        goto after_0;
    // 0x800CCB9C: addiu       $a0, $a0, -0x48FC
    ctx->r4 = ADD32(ctx->r4, -0X48FC);
    after_0:
    // 0x800CCBA0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800CCBA4: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, 0X400);
    // 0x800CCBA8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800CCBAC: addu        $a1, $t6, $at
    ctx->r5 = ADD32(ctx->r14, ctx->r1);
    // 0x800CCBB0: jal         0x800C39A0
    // 0x800CCBB4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800C39A0(rdram, ctx);
        goto after_1;
    // 0x800CCBB4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800CCBB8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800CCBBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800CCBC0:
    // 0x800CCBC0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CCBC4: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x800CCBC8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800CCBCC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CCBD0: lbu         $t8, 0x400($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X400);
    // 0x800CCBD4: sb          $t8, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r24;
L_800CCBD8:
    // 0x800CCBD8: lbu         $s0, 0x37($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X37);
    // 0x800CCBDC: andi        $t9, $s0, 0xC0
    ctx->r25 = ctx->r16 & 0XC0;
    // 0x800CCBE0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x800CCBE4: beq         $s0, $zero, L_800CCC0C
    if (ctx->r16 == 0) {
        // 0x800CCBE8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800CCC0C;
    }
    // 0x800CCBE8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800CCBEC: beq         $s0, $at, L_800CCC2C
    if (ctx->r16 == ctx->r1) {
        // 0x800CCBF0: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800CCC2C;
    }
    // 0x800CCBF0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800CCBF4: beq         $s0, $at, L_800CCC50
    if (ctx->r16 == ctx->r1) {
        // 0x800CCBF8: addiu       $at, $zero, 0xC0
        ctx->r1 = ADD32(0, 0XC0);
            goto L_800CCC50;
    }
    // 0x800CCBF8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800CCBFC: beq         $s0, $at, L_800CCC74
    if (ctx->r16 == ctx->r1) {
        // 0x800CCC00: nop
    
            goto L_800CCC74;
    }
    // 0x800CCC00: nop

    // 0x800CCC04: b           L_800CCC94
    // 0x800CCC08: nop

        goto L_800CCC94;
    // 0x800CCC08: nop

L_800CCC0C:
    // 0x800CCC0C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC14: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CCC18: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800CCC1C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CCC20: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800CCC24: b           L_800CCC94
    // 0x800CCC28: sb          $zero, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = 0;
        goto L_800CCC94;
    // 0x800CCC28: sb          $zero, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = 0;
L_800CCC2C:
    // 0x800CCC2C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC34: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CCC38: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800CCC3C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CCC40: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800CCC44: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800CCC48: b           L_800CCC94
    // 0x800CCC4C: sb          $t3, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = ctx->r11;
        goto L_800CCC94;
    // 0x800CCC4C: sb          $t3, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = ctx->r11;
L_800CCC50:
    // 0x800CCC50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC54: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CCC5C: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800CCC60: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800CCC64: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CCC68: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800CCC6C: b           L_800CCC94
    // 0x800CCC70: sb          $t7, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = ctx->r15;
        goto L_800CCC94;
    // 0x800CCC70: sb          $t7, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = ctx->r15;
L_800CCC74:
    // 0x800CCC74: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC78: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800CCC7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CCC80: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800CCC84: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800CCC88: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CCC8C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CCC90: sb          $t1, -0x3C00($at)
    MEM_B(-0X3C00, ctx->r1) = ctx->r9;
L_800CCC94:
    // 0x800CCC94: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CCC98: lbu         $t5, 0x37($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X37);
    // 0x800CCC9C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800CCCA0: sltiu       $at, $t8, 0x4
    ctx->r1 = ctx->r24 < 0X4 ? 1 : 0;
    // 0x800CCCA4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800CCCA8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800CCCAC: bne         $at, $zero, L_800CCBD8
    if (ctx->r1 != 0) {
        // 0x800CCCB0: sb          $t6, 0x37($sp)
        MEM_B(0X37, ctx->r29) = ctx->r14;
            goto L_800CCBD8;
    }
    // 0x800CCCB0: sb          $t6, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r14;
    // 0x800CCCB4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800CCCB8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CCCBC: sltiu       $at, $t0, 0x800
    ctx->r1 = ctx->r8 < 0X800 ? 1 : 0;
    // 0x800CCCC0: bne         $at, $zero, L_800CCBC0
    if (ctx->r1 != 0) {
        // 0x800CCCC4: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_800CCBC0;
    }
    // 0x800CCCC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800CCCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CCCD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CCCD4: jr          $ra
    // 0x800CCCD8: nop

    return;
    // 0x800CCCD8: nop

;}
RECOMP_FUNC void func_800CCCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCCDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CCCE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CCCE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCCE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CCCEC: sw          $t6, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r14;
    // 0x800CCCF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CCCF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCCF8: sw          $zero, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = 0;
    // 0x800CCCFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCD00: sw          $t7, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r15;
    // 0x800CCD04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCD08: sw          $zero, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = 0;
    // 0x800CCD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCD10: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
    // 0x800CCD14: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800CCD18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCD1C: addiu       $t8, $t8, -0x1C00
    ctx->r24 = ADD32(ctx->r24, -0X1C00);
    // 0x800CCD20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCD24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CCD28: sw          $zero, -0x2D50($at)
    MEM_W(-0X2D50, ctx->r1) = 0;
    // 0x800CCD2C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800CCD30: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800CCD34: ori         $at, $zero, 0x8030
    ctx->r1 = 0 | 0X8030;
    // 0x800CCD38: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800CCD3C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x800CCD40: lbu         $t2, 0x1($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1);
    // 0x800CCD44: andi        $t6, $t1, 0xFFFF
    ctx->r14 = ctx->r9 & 0XFFFF;
    // 0x800CCD48: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800CCD4C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CCD50: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800CCD54: addu        $s0, $t6, $t5
    ctx->r16 = ADD32(ctx->r14, ctx->r13);
    // 0x800CCD58: beq         $s0, $at, L_800CCD8C
    if (ctx->r16 == ctx->r1) {
        // 0x800CCD5C: sh          $t3, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r11;
            goto L_800CCD8C;
    }
    // 0x800CCD5C: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x800CCD60: ori         $at, $zero, 0x8031
    ctx->r1 = 0 | 0X8031;
    // 0x800CCD64: bne         $s0, $at, L_800CCDAC
    if (ctx->r16 != ctx->r1) {
        // 0x800CCD68: nop
    
            goto L_800CCDAC;
    }
    // 0x800CCD68: nop

    // 0x800CCD6C: jal         0x800CD438
    // 0x800CCD70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_0;
    // 0x800CCD70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CCD74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CCD78: lw          $t7, -0x2D54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D54);
    // 0x800CCD7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCD80: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800CCD84: b           L_800CCDB4
    // 0x800CCD88: sw          $t8, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r24;
        goto L_800CCDB4;
    // 0x800CCD88: sw          $t8, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r24;
L_800CCD8C:
    // 0x800CCD8C: jal         0x800CD438
    // 0x800CCD90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_1;
    // 0x800CCD90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800CCD94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CCD98: lw          $t0, -0x2D54($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D54);
    // 0x800CCD9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCDA0: addiu       $t9, $t0, 0x2
    ctx->r25 = ADD32(ctx->r8, 0X2);
    // 0x800CCDA4: b           L_800CCDB4
    // 0x800CCDA8: sw          $t9, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r25;
        goto L_800CCDB4;
    // 0x800CCDA8: sw          $t9, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r25;
L_800CCDAC:
    // 0x800CCDAC: jal         0x800CD438
    // 0x800CCDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_2;
    // 0x800CCDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_800CCDB4:
    // 0x800CCDB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCDB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CCDBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CCDC0: jr          $ra
    // 0x800CCDC4: nop

    return;
    // 0x800CCDC4: nop

;}
RECOMP_FUNC void func_800CCDC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCDC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CCDCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CCDD0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800CCDD4: lw          $s0, -0x2D68($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D68);
    // 0x800CCDD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCDDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCDE0: beq         $s0, $at, L_800CCE00
    if (ctx->r16 == ctx->r1) {
        // 0x800CCDE4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CCE00;
    }
    // 0x800CCDE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CCDE8: beq         $s0, $at, L_800CCE30
    if (ctx->r16 == ctx->r1) {
        // 0x800CCDEC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CCE30;
    }
    // 0x800CCDEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CCDF0: beq         $s0, $at, L_800CD1EC
    if (ctx->r16 == ctx->r1) {
        // 0x800CCDF4: nop
    
            goto L_800CD1EC;
    }
    // 0x800CCDF4: nop

    // 0x800CCDF8: b           L_800CD21C
    // 0x800CCDFC: nop

        goto L_800CD21C;
    // 0x800CCDFC: nop

L_800CCE00:
    // 0x800CCE00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CCE04: lw          $t6, -0x2D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D58);
    // 0x800CCE08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCE0C: addiu       $t7, $t6, 0x16
    ctx->r15 = ADD32(ctx->r14, 0X16);
    // 0x800CCE10: sw          $t7, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = ctx->r15;
    // 0x800CCE14: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x800CCE18: bne         $t7, $at, L_800CD21C
    if (ctx->r15 != ctx->r1) {
        // 0x800CCE1C: nop
    
            goto L_800CD21C;
    }
    // 0x800CCE1C: nop

    // 0x800CCE20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800CCE24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCE28: b           L_800CD21C
    // 0x800CCE2C: sw          $t8, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r24;
        goto L_800CD21C;
    // 0x800CCE2C: sw          $t8, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r24;
L_800CCE30:
    // 0x800CCE30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CCE34: lw          $t9, -0x2D48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D48);
    // 0x800CCE38: beq         $t9, $zero, L_800CCE50
    if (ctx->r25 == 0) {
        // 0x800CCE3C: nop
    
            goto L_800CCE50;
    }
    // 0x800CCE3C: nop

    // 0x800CCE40: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800CCE44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCE48: b           L_800CD21C
    // 0x800CCE4C: sw          $t0, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r8;
        goto L_800CD21C;
    // 0x800CCE4C: sw          $t0, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r8;
L_800CCE50:
    // 0x800CCE50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CCE54: lw          $t1, -0x2D54($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D54);
    // 0x800CCE58: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800CCE5C: addiu       $t2, $t2, -0x1C00
    ctx->r10 = ADD32(ctx->r10, -0X1C00);
    // 0x800CCE60: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800CCE64: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800CCE68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCE6C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800CCE70: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800CCE74: sh          $t5, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r13;
    // 0x800CCE78: lbu         $t6, 0x1($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X1);
    // 0x800CCE7C: andi        $t0, $t5, 0xFFFF
    ctx->r8 = ctx->r13 & 0XFFFF;
    // 0x800CCE80: addiu       $t4, $t1, 0x2
    ctx->r12 = ADD32(ctx->r9, 0X2);
    // 0x800CCE84: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800CCE88: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CCE8C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800CCE90: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x800CCE94: sw          $t2, -0x2D50($at)
    MEM_W(-0X2D50, ctx->r1) = ctx->r10;
    // 0x800CCE98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCE9C: sw          $t4, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r12;
    // 0x800CCEA0: lw          $s0, -0x2D50($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D50);
    // 0x800CCEA4: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x800CCEA8: andi        $t3, $s0, 0xC000
    ctx->r11 = ctx->r16 & 0XC000;
    // 0x800CCEAC: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800CCEB0: beq         $s0, $zero, L_800CCEC8
    if (ctx->r16 == 0) {
        // 0x800CCEB4: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_800CCEC8;
    }
    // 0x800CCEB4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800CCEB8: beq         $s0, $at, L_800CCF18
    if (ctx->r16 == ctx->r1) {
        // 0x800CCEBC: nop
    
            goto L_800CCF18;
    }
    // 0x800CCEBC: nop

    // 0x800CCEC0: b           L_800CD21C
    // 0x800CCEC4: nop

        goto L_800CD21C;
    // 0x800CCEC4: nop

L_800CCEC8:
    // 0x800CCEC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CCECC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CCED0: lw          $t5, -0x2D5C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D5C);
    // 0x800CCED4: lw          $t7, -0x2D60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D60);
    // 0x800CCED8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CCEDC: lw          $t6, -0x2D50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D50);
    // 0x800CCEE0: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x800CCEE4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800CCEE8: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800CCEEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCEF0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CCEF4: sh          $t6, -0x2D30($at)
    MEM_H(-0X2D30, ctx->r1) = ctx->r14;
    // 0x800CCEF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCEFC: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
    // 0x800CCF00: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CCF04: lw          $t2, -0x2D60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D60);
    // 0x800CCF08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCF0C: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800CCF10: b           L_800CD21C
    // 0x800CCF14: sw          $t1, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = ctx->r9;
        goto L_800CD21C;
    // 0x800CCF14: sw          $t1, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = ctx->r9;
L_800CCF18:
    // 0x800CCF18: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800CCF1C: lw          $s0, -0x2D50($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D50);
    // 0x800CCF20: ori         $at, $zero, 0x8081
    ctx->r1 = 0 | 0X8081;
    // 0x800CCF24: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x800CCF28: bne         $at, $zero, L_800CCF48
    if (ctx->r1 != 0) {
        // 0x800CCF2C: ori         $at, $zero, 0x8081
        ctx->r1 = 0 | 0X8081;
            goto L_800CCF48;
    }
    // 0x800CCF2C: ori         $at, $zero, 0x8081
    ctx->r1 = 0 | 0X8081;
    // 0x800CCF30: beq         $s0, $at, L_800CCFBC
    if (ctx->r16 == ctx->r1) {
        // 0x800CCF34: ori         $at, $zero, 0x8082
        ctx->r1 = 0 | 0X8082;
            goto L_800CCFBC;
    }
    // 0x800CCF34: ori         $at, $zero, 0x8082
    ctx->r1 = 0 | 0X8082;
    // 0x800CCF38: beq         $s0, $at, L_800CCFE0
    if (ctx->r16 == ctx->r1) {
        // 0x800CCF3C: nop
    
            goto L_800CCFE0;
    }
    // 0x800CCF3C: nop

    // 0x800CCF40: b           L_800CD21C
    // 0x800CCF44: nop

        goto L_800CD21C;
    // 0x800CCF44: nop

L_800CCF48:
    // 0x800CCF48: ori         $at, $zero, 0x8032
    ctx->r1 = 0 | 0X8032;
    // 0x800CCF4C: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x800CCF50: bne         $at, $zero, L_800CCF68
    if (ctx->r1 != 0) {
        // 0x800CCF54: ori         $at, $zero, 0x8080
        ctx->r1 = 0 | 0X8080;
            goto L_800CCF68;
    }
    // 0x800CCF54: ori         $at, $zero, 0x8080
    ctx->r1 = 0 | 0X8080;
    // 0x800CCF58: beq         $s0, $at, L_800CCF98
    if (ctx->r16 == ctx->r1) {
        // 0x800CCF5C: nop
    
            goto L_800CCF98;
    }
    // 0x800CCF5C: nop

    // 0x800CCF60: b           L_800CD21C
    // 0x800CCF64: nop

        goto L_800CD21C;
    // 0x800CCF64: nop

L_800CCF68:
    // 0x800CCF68: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800CCF6C: ori         $at, $at, 0x7FF0
    ctx->r1 = ctx->r1 | 0X7FF0;
    // 0x800CCF70: addu        $t4, $s0, $at
    ctx->r12 = ADD32(ctx->r16, ctx->r1);
    // 0x800CCF74: sltiu       $at, $t4, 0x22
    ctx->r1 = ctx->r12 < 0X22 ? 1 : 0;
    // 0x800CCF78: beq         $at, $zero, L_800CD21C
    if (ctx->r1 == 0) {
        // 0x800CCF7C: nop
    
            goto L_800CD21C;
    }
    // 0x800CCF7C: nop

    // 0x800CCF80: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CCF84: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CCF88: addu        $at, $at, $t4
    gpr jr_addend_800CCF90 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CCF8C: lw          $t4, -0x2170($at)
    ctx->r12 = ADD32(ctx->r1, -0X2170);
    // 0x800CCF90: jr          $t4
    // 0x800CCF94: nop

    switch (jr_addend_800CCF90 >> 2) {
        case 0: goto L_800CD004; break;
        case 1: goto L_800CD004; break;
        case 2: goto L_800CD004; break;
        case 3: goto L_800CD004; break;
        case 4: goto L_800CD004; break;
        case 5: goto L_800CD004; break;
        case 6: goto L_800CD004; break;
        case 7: goto L_800CD004; break;
        case 8: goto L_800CD004; break;
        case 9: goto L_800CD004; break;
        case 10: goto L_800CD21C; break;
        case 11: goto L_800CD21C; break;
        case 12: goto L_800CD21C; break;
        case 13: goto L_800CD21C; break;
        case 14: goto L_800CD21C; break;
        case 15: goto L_800CD21C; break;
        case 16: goto L_800CD028; break;
        case 17: goto L_800CD170; break;
        case 18: goto L_800CD1A0; break;
        case 19: goto L_800CD21C; break;
        case 20: goto L_800CD21C; break;
        case 21: goto L_800CD21C; break;
        case 22: goto L_800CD21C; break;
        case 23: goto L_800CD21C; break;
        case 24: goto L_800CD21C; break;
        case 25: goto L_800CD21C; break;
        case 26: goto L_800CD21C; break;
        case 27: goto L_800CD21C; break;
        case 28: goto L_800CD21C; break;
        case 29: goto L_800CD21C; break;
        case 30: goto L_800CD21C; break;
        case 31: goto L_800CD21C; break;
        case 32: goto L_800CD1C4; break;
        case 33: goto L_800CD1D4; break;
        default: switch_error(__func__, 0x800CCF90, 0x800EDE90);
    }
    // 0x800CCF94: nop

L_800CCF98:
    // 0x800CCF98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CCF9C: lw          $t3, -0x2D50($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D50);
    // 0x800CCFA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCFA4: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CCFA8: addiu       $t5, $t5, -0x4C10
    ctx->r13 = ADD32(ctx->r13, -0X4C10);
    // 0x800CCFAC: addiu       $t7, $zero, 0x7FF
    ctx->r15 = ADD32(0, 0X7FF);
    // 0x800CCFB0: sw          $t3, -0x2D3C($at)
    MEM_W(-0X2D3C, ctx->r1) = ctx->r11;
    // 0x800CCFB4: b           L_800CD21C
    // 0x800CCFB8: sh          $t7, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r15;
        goto L_800CD21C;
    // 0x800CCFB8: sh          $t7, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r15;
L_800CCFBC:
    // 0x800CCFBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CCFC0: lw          $t8, -0x2D50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D50);
    // 0x800CCFC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCFC8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800CCFCC: addiu       $t6, $t6, -0x4C10
    ctx->r14 = ADD32(ctx->r14, -0X4C10);
    // 0x800CCFD0: ori         $t0, $zero, 0xFFC1
    ctx->r8 = 0 | 0XFFC1;
    // 0x800CCFD4: sw          $t8, -0x2D3C($at)
    MEM_W(-0X2D3C, ctx->r1) = ctx->r24;
    // 0x800CCFD8: b           L_800CD21C
    // 0x800CCFDC: sh          $t0, 0x1E($t6)
    MEM_H(0X1E, ctx->r14) = ctx->r8;
        goto L_800CD21C;
    // 0x800CCFDC: sh          $t0, 0x1E($t6)
    MEM_H(0X1E, ctx->r14) = ctx->r8;
L_800CCFE0:
    // 0x800CCFE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CCFE4: lw          $t9, -0x2D50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D50);
    // 0x800CCFE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CCFEC: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800CCFF0: addiu       $t1, $t1, -0x4C10
    ctx->r9 = ADD32(ctx->r9, -0X4C10);
    // 0x800CCFF4: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800CCFF8: sw          $t9, -0x2D3C($at)
    MEM_W(-0X2D3C, ctx->r1) = ctx->r25;
    // 0x800CCFFC: b           L_800CD21C
    // 0x800CD000: sh          $t2, 0x1E($t1)
    MEM_H(0X1E, ctx->r9) = ctx->r10;
        goto L_800CD21C;
    // 0x800CD000: sh          $t2, 0x1E($t1)
    MEM_H(0X1E, ctx->r9) = ctx->r10;
L_800CD004:
    // 0x800CD004: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CD008: lw          $t4, -0x2D50($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D50);
    // 0x800CD00C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CD010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD014: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x800CD018: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x800CD01C: lw          $t7, -0x5278($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5278);
    // 0x800CD020: b           L_800CD21C
    // 0x800CD024: sw          $t7, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r15;
        goto L_800CD21C;
    // 0x800CD024: sw          $t7, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r15;
L_800CD028:
    // 0x800CD028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD02C: sw          $zero, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = 0;
    // 0x800CD030: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CD034: lw          $t5, -0x2D64($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D64);
    // 0x800CD038: bne         $t5, $zero, L_800CD0BC
    if (ctx->r13 != 0) {
        // 0x800CD03C: nop
    
            goto L_800CD0BC;
    }
    // 0x800CD03C: nop

    // 0x800CD040: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CD044: lw          $t8, -0x2D5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D5C);
    // 0x800CD048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CD04C: bne         $t8, $at, L_800CD0A4
    if (ctx->r24 != ctx->r1) {
        // 0x800CD050: nop
    
            goto L_800CD0A4;
    }
    // 0x800CD050: nop

    // 0x800CD054: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800CD058:
    // 0x800CD058: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD05C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CD060: addiu       $t9, $t9, -0x2D68
    ctx->r25 = ADD32(ctx->r25, -0X2D68);
    // 0x800CD064: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x800CD068: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800CD06C: lhu         $t1, 0x3A($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X3A);
    // 0x800CD070: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD074: sh          $t1, 0x38($t2)
    MEM_H(0X38, ctx->r10) = ctx->r9;
    // 0x800CD078: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD07C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD080: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x800CD084: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800CD088: sh          $zero, -0x2D2E($at)
    MEM_H(-0X2D2E, ctx->r1) = 0;
    // 0x800CD08C: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x800CD090: sltiu       $at, $t5, 0x20
    ctx->r1 = ctx->r13 < 0X20 ? 1 : 0;
    // 0x800CD094: bne         $at, $zero, L_800CD058
    if (ctx->r1 != 0) {
        // 0x800CD098: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_800CD058;
    }
    // 0x800CD098: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800CD09C: b           L_800CD1E4
    // 0x800CD0A0: nop

        goto L_800CD1E4;
    // 0x800CD0A0: nop

L_800CD0A4:
    // 0x800CD0A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CD0A8: lw          $t8, -0x2D5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D5C);
    // 0x800CD0AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD0B0: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800CD0B4: b           L_800CD21C
    // 0x800CD0B8: sw          $t0, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r8;
        goto L_800CD21C;
    // 0x800CD0B8: sw          $t0, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r8;
L_800CD0BC:
    // 0x800CD0BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CD0C0: lw          $t6, -0x2D5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D5C);
    // 0x800CD0C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CD0C8: bne         $t6, $at, L_800CD158
    if (ctx->r14 != ctx->r1) {
        // 0x800CD0CC: nop
    
            goto L_800CD158;
    }
    // 0x800CD0CC: nop

    // 0x800CD0D0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800CD0D4:
    // 0x800CD0D4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD0D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CD0DC: addiu       $t2, $t2, -0x2D68
    ctx->r10 = ADD32(ctx->r10, -0X2D68);
    // 0x800CD0E0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800CD0E4: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800CD0E8: lhu         $t3, 0x3A($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X3A);
    // 0x800CD0EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CD0F0: addiu       $t8, $t8, -0x2D68
    ctx->r24 = ADD32(ctx->r24, -0X2D68);
    // 0x800CD0F4: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
    // 0x800CD0F8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD0FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CD100: addiu       $t2, $t2, -0x2D68
    ctx->r10 = ADD32(ctx->r10, -0X2D68);
    // 0x800CD104: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x800CD108: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x800CD10C: lhu         $t6, 0x3C($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X3C);
    // 0x800CD110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD114: sh          $t6, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r14;
    // 0x800CD118: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD11C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800CD120: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800CD124: lhu         $t4, 0x3E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X3E);
    // 0x800CD128: sh          $t4, 0x3C($t3)
    MEM_H(0X3C, ctx->r11) = ctx->r12;
    // 0x800CD12C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD130: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD134: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x800CD138: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800CD13C: sh          $zero, -0x2D2E($at)
    MEM_H(-0X2D2E, ctx->r1) = 0;
    // 0x800CD140: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800CD144: sltiu       $at, $t6, 0x20
    ctx->r1 = ctx->r14 < 0X20 ? 1 : 0;
    // 0x800CD148: bne         $at, $zero, L_800CD0D4
    if (ctx->r1 != 0) {
        // 0x800CD14C: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_800CD0D4;
    }
    // 0x800CD14C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CD150: b           L_800CD21C
    // 0x800CD154: nop

        goto L_800CD21C;
    // 0x800CD154: nop

L_800CD158:
    // 0x800CD158: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CD15C: lw          $t0, -0x2D5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D5C);
    // 0x800CD160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD164: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800CD168: b           L_800CD21C
    // 0x800CD16C: sw          $t9, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r25;
        goto L_800CD21C;
    // 0x800CD16C: sw          $t9, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r25;
L_800CD170:
    // 0x800CD170: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CD174: lw          $t1, -0x2D64($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D64);
    // 0x800CD178: bne         $t1, $zero, L_800CD190
    if (ctx->r9 != 0) {
        // 0x800CD17C: nop
    
            goto L_800CD190;
    }
    // 0x800CD17C: nop

    // 0x800CD180: jal         0x800CD438
    // 0x800CD184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_0;
    // 0x800CD184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CD188: b           L_800CD21C
    // 0x800CD18C: nop

        goto L_800CD21C;
    // 0x800CD18C: nop

L_800CD190:
    // 0x800CD190: jal         0x800CD438
    // 0x800CD194: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_1;
    // 0x800CD194: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800CD198: b           L_800CD21C
    // 0x800CD19C: nop

        goto L_800CD21C;
    // 0x800CD19C: nop

L_800CD1A0:
    // 0x800CD1A0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800CD1A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD1A8: sw          $t2, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r10;
    // 0x800CD1AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD1B0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800CD1B4: sw          $t4, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r12;
    // 0x800CD1B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD1BC: b           L_800CD21C
    // 0x800CD1C0: sw          $zero, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = 0;
        goto L_800CD21C;
    // 0x800CD1C0: sw          $zero, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = 0;
L_800CD1C4:
    // 0x800CD1C4: jal         0x800CD438
    // 0x800CD1C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_2;
    // 0x800CD1C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800CD1CC: b           L_800CD21C
    // 0x800CD1D0: nop

        goto L_800CD21C;
    // 0x800CD1D0: nop

L_800CD1D4:
    // 0x800CD1D4: jal         0x800CD438
    // 0x800CD1D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_3;
    // 0x800CD1D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800CD1DC: b           L_800CD21C
    // 0x800CD1E0: nop

        goto L_800CD21C;
    // 0x800CD1E0: nop

L_800CD1E4:
    // 0x800CD1E4: b           L_800CD21C
    // 0x800CD1E8: nop

        goto L_800CD21C;
    // 0x800CD1E8: nop

L_800CD1EC:
    // 0x800CD1EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800CD1F0: lw          $t3, -0x2D58($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D58);
    // 0x800CD1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD1F8: addiu       $t7, $t3, -0x16
    ctx->r15 = ADD32(ctx->r11, -0X16);
    // 0x800CD1FC: bne         $t7, $zero, L_800CD21C
    if (ctx->r15 != 0) {
        // 0x800CD200: sw          $t7, -0x2D58($at)
        MEM_W(-0X2D58, ctx->r1) = ctx->r15;
            goto L_800CD21C;
    }
    // 0x800CD200: sw          $t7, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = ctx->r15;
    // 0x800CD204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD208: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800CD20C: addiu       $t8, $t8, -0x4C10
    ctx->r24 = ADD32(ctx->r24, -0X4C10);
    // 0x800CD210: sw          $zero, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = 0;
    // 0x800CD214: ori         $t5, $zero, 0xFFFF
    ctx->r13 = 0 | 0XFFFF;
    // 0x800CD218: sh          $t5, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r13;
L_800CD21C:
    // 0x800CD21C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CD224: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CD228: jr          $ra
    // 0x800CD22C: nop

    return;
    // 0x800CD22C: nop

;}
RECOMP_FUNC void func_800CD230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD230: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CD234: lw          $t6, -0x2D68($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D68);
    // 0x800CD238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CD23C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD240: beq         $t6, $zero, L_800CD428
    if (ctx->r14 == 0) {
        // 0x800CD244: nop
    
            goto L_800CD428;
    }
    // 0x800CD244: nop

    // 0x800CD248: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800CD24C: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x800CD250: addiu       $t7, $zero, 0x58
    ctx->r15 = ADD32(0, 0X58);
    // 0x800CD254: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800CD258: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800CD25C: lw          $t9, -0x2D3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D3C);
    // 0x800CD260: ori         $at, $zero, 0x8081
    ctx->r1 = 0 | 0X8081;
    // 0x800CD264: bne         $t9, $at, L_800CD27C
    if (ctx->r25 != ctx->r1) {
        // 0x800CD268: nop
    
            goto L_800CD27C;
    }
    // 0x800CD268: nop

    // 0x800CD26C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CD270: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x800CD274: addiu       $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
    // 0x800CD278: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_800CD27C:
    // 0x800CD27C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800CD280: lw          $t2, -0x2D3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D3C);
    // 0x800CD284: ori         $at, $zero, 0x8082
    ctx->r1 = 0 | 0X8082;
    // 0x800CD288: bne         $t2, $at, L_800CD2A0
    if (ctx->r10 != ctx->r1) {
        // 0x800CD28C: nop
    
            goto L_800CD2A0;
    }
    // 0x800CD28C: nop

    // 0x800CD290: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CD294: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x800CD298: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800CD29C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800CD2A0:
    // 0x800CD2A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800CD2A4: lw          $t5, -0x2D64($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D64);
    // 0x800CD2A8: bne         $t5, $zero, L_800CD370
    if (ctx->r13 != 0) {
        // 0x800CD2AC: nop
    
            goto L_800CD370;
    }
    // 0x800CD2AC: nop

    // 0x800CD2B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800CD2B4: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_800CD2B8:
    // 0x800CD2B8: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
L_800CD2BC:
    // 0x800CD2BC: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x800CD2C0: lhu         $t8, 0x20($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X20);
    // 0x800CD2C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CD2C8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800CD2CC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800CD2D0: addiu       $t1, $t1, -0x2D68
    ctx->r9 = ADD32(ctx->r9, -0X2D68);
    // 0x800CD2D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800CD2D8: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800CD2DC: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x800CD2E0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800CD2E4: lhu         $a0, 0x38($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X38);
    // 0x800CD2E8: lhu         $a1, 0x40($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X40);
    // 0x800CD2EC: jal         0x800CD4B4
    // 0x800CD2F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800CD4B4(rdram, ctx);
        goto after_0;
    // 0x800CD2F0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x800CD2F4: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x800CD2F8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800CD2FC: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x800CD300: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x800CD304: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x800CD308: addiu       $t6, $t5, 0x80
    ctx->r14 = ADD32(ctx->r13, 0X80);
    // 0x800CD30C: sh          $t0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r8;
    // 0x800CD310: bne         $at, $zero, L_800CD2BC
    if (ctx->r1 != 0) {
        // 0x800CD314: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_800CD2BC;
    }
    // 0x800CD314: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800CD318: lhu         $t7, 0x20($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X20);
    // 0x800CD31C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800CD320: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x800CD324: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800CD328: bne         $at, $zero, L_800CD2B8
    if (ctx->r1 != 0) {
        // 0x800CD32C: sh          $t9, 0x20($sp)
        MEM_H(0X20, ctx->r29) = ctx->r25;
            goto L_800CD2B8;
    }
    // 0x800CD32C: sh          $t9, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r25;
    // 0x800CD330: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CD334: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CD338: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800CD33C: lw          $t4, -0x2D58($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D58);
    // 0x800CD340: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CD344: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x800CD348: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800CD34C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CD350: addiu       $a0, $a0, -0x4BF0
    ctx->r4 = ADD32(ctx->r4, -0X4BF0);
    // 0x800CD354: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x800CD358: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800CD35C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800CD360: jal         0x800C6C6C
    // 0x800CD364: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x800CD364: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800CD368: b           L_800CD428
    // 0x800CD36C: nop

        goto L_800CD428;
    // 0x800CD36C: nop

L_800CD370:
    // 0x800CD370: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800CD374: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_800CD378:
    // 0x800CD378: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
L_800CD37C:
    // 0x800CD37C: lhu         $t5, 0x22($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X22);
    // 0x800CD380: lhu         $t8, 0x20($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X20);
    // 0x800CD384: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CD388: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800CD38C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800CD390: addiu       $t7, $t7, -0x2D68
    ctx->r15 = ADD32(ctx->r15, -0X2D68);
    // 0x800CD394: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x800CD398: addu        $t3, $t6, $t0
    ctx->r11 = ADD32(ctx->r14, ctx->r8);
    // 0x800CD39C: addu        $t1, $t3, $t7
    ctx->r9 = ADD32(ctx->r11, ctx->r15);
    // 0x800CD3A0: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x800CD3A4: lhu         $a0, 0x38($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X38);
    // 0x800CD3A8: lhu         $a1, 0x40($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X40);
    // 0x800CD3AC: jal         0x800CD4B4
    // 0x800CD3B0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800CD4B4(rdram, ctx);
        goto after_2;
    // 0x800CD3B0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800CD3B4: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x800CD3B8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800CD3BC: addiu       $t2, $t8, 0x2
    ctx->r10 = ADD32(ctx->r24, 0X2);
    // 0x800CD3C0: andi        $t9, $t2, 0xFFFF
    ctx->r25 = ctx->r10 & 0XFFFF;
    // 0x800CD3C4: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x800CD3C8: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800CD3CC: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
    // 0x800CD3D0: bne         $at, $zero, L_800CD37C
    if (ctx->r1 != 0) {
        // 0x800CD3D4: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800CD37C;
    }
    // 0x800CD3D4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800CD3D8: lhu         $t6, 0x20($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X20);
    // 0x800CD3DC: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800CD3E0: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CD3E4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800CD3E8: bne         $at, $zero, L_800CD378
    if (ctx->r1 != 0) {
        // 0x800CD3EC: sh          $t0, 0x20($sp)
        MEM_H(0X20, ctx->r29) = ctx->r8;
            goto L_800CD378;
    }
    // 0x800CD3EC: sh          $t0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r8;
    // 0x800CD3F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CD3F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CD3F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800CD3FC: lw          $t1, -0x2D58($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D58);
    // 0x800CD400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CD404: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x800CD408: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x800CD40C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CD410: addiu       $a0, $a0, -0x4BAC
    ctx->r4 = ADD32(ctx->r4, -0X4BAC);
    // 0x800CD414: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x800CD418: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800CD41C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CD420: jal         0x800C6C6C
    // 0x800CD424: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x800CD424: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
L_800CD428:
    // 0x800CD428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD42C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CD430: jr          $ra
    // 0x800CD434: nop

    return;
    // 0x800CD434: nop

;}
