#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#include "funcs.h"

RECOMP_FUNC void func_8017D288_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D288: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017D28C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D294: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017D298: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x8017D29C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8017D2A0: beq         $at, $zero, L_8017D7D0
    if (ctx->r1 == 0) {
        // 0x8017D2A4: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D2A4: nop

    // 0x8017D2A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D2AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D2B0: addu        $at, $at, $t7
    gpr jr_addend_8017D2B8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017D2B4: lw          $t7, -0x1D7C($at)
    ctx->r15 = ADD32(ctx->r1, -0X1D7C);
    // 0x8017D2B8: jr          $t7
    // 0x8017D2BC: nop

    switch (jr_addend_8017D2B8 >> 2) {
        case 0: goto L_8017D2C0; break;
        case 1: goto L_8017D3AC; break;
        case 2: goto L_8017D420; break;
        case 3: goto L_8017D500; break;
        case 4: goto L_8017D58C; break;
        case 5: goto L_8017D664; break;
        case 6: goto L_8017D6C4; break;
        default: switch_error(__func__, 0x8017D2B8, 0x8017E284);
    }
    // 0x8017D2BC: nop

L_8017D2C0:
    // 0x8017D2C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D2C4: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D2C8: lbu         $t9, 0xB($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB);
    // 0x8017D2CC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017D2D0: lbu         $t0, 0x1B($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1B);
    // 0x8017D2D4: addiu       $t2, $t9, -0x1E
    ctx->r10 = ADD32(ctx->r25, -0X1E);
    // 0x8017D2D8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8017D2DC: lbu         $t1, 0x1C($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1C);
    // 0x8017D2E0: addiu       $t3, $t0, -0x1E
    ctx->r11 = ADD32(ctx->r8, -0X1E);
    // 0x8017D2E4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017D2E8: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8017D2EC: addiu       $t4, $t1, -0x1E
    ctx->r12 = ADD32(ctx->r9, -0X1E);
    // 0x8017D2F0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8017D2F4: bgtz        $t2, L_8017D304
    if (SIGNED(ctx->r10) > 0) {
        // 0x8017D2F8: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_8017D304;
    }
    // 0x8017D2F8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8017D2FC: b           L_8017D314
    // 0x8017D300: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
        goto L_8017D314;
    // 0x8017D300: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
L_8017D304:
    // 0x8017D304: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D308: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D30C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D310: sb          $t5, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r13;
L_8017D314:
    // 0x8017D314: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8017D318: bgtz        $t7, L_8017D330
    if (SIGNED(ctx->r15) > 0) {
        // 0x8017D31C: nop
    
            goto L_8017D330;
    }
    // 0x8017D31C: nop

    // 0x8017D320: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D324: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017D328: b           L_8017D340
    // 0x8017D32C: sb          $zero, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = 0;
        goto L_8017D340;
    // 0x8017D32C: sb          $zero, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = 0;
L_8017D330:
    // 0x8017D330: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8017D334: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D338: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017D33C: sb          $t0, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r8;
L_8017D340:
    // 0x8017D340: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017D344: bgtz        $t1, L_8017D35C
    if (SIGNED(ctx->r9) > 0) {
        // 0x8017D348: nop
    
            goto L_8017D35C;
    }
    // 0x8017D348: nop

    // 0x8017D34C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D350: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017D354: b           L_8017D36C
    // 0x8017D358: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
        goto L_8017D36C;
    // 0x8017D358: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
L_8017D35C:
    // 0x8017D35C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8017D360: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D364: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D368: sb          $t2, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r10;
L_8017D36C:
    // 0x8017D36C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D370: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D374: lbu         $t6, 0xB($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XB);
    // 0x8017D378: bne         $t6, $zero, L_8017D7D0
    if (ctx->r14 != 0) {
        // 0x8017D37C: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D37C: nop

    // 0x8017D380: lbu         $t7, 0x1B($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X1B);
    // 0x8017D384: bne         $t7, $zero, L_8017D7D0
    if (ctx->r15 != 0) {
        // 0x8017D388: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D388: nop

    // 0x8017D38C: lbu         $t9, 0x1C($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X1C);
    // 0x8017D390: bne         $t9, $zero, L_8017D7D0
    if (ctx->r25 != 0) {
        // 0x8017D394: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D394: nop

    // 0x8017D398: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D39C: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017D3A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017D3A4: b           L_8017D7D0
    // 0x8017D3A8: sb          $t0, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r8;
        goto L_8017D7D0;
    // 0x8017D3A8: sb          $t0, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r8;
L_8017D3AC:
    // 0x8017D3AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D3B0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017D3B4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8017D3B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D3BC: lwc1        $f4, 0x44($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X44);
    // 0x8017D3C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D3C4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D3C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017D3CC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017D3D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D3D4: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
    // 0x8017D3D8: lwc1        $f10, 0x44($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8017D3DC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8017D3E0: nop

    // 0x8017D3E4: bc1f        L_8017D7D0
    if (!c1cs) {
        // 0x8017D3E8: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D3E8: nop

    // 0x8017D3EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D3F0: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x8017D3F4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8017D3F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D3FC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017D400: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D404: sb          $t2, 0x12($t8)
    MEM_B(0X12, ctx->r24) = ctx->r10;
    // 0x8017D408: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D40C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D410: sb          $zero, 0x30($t6)
    MEM_B(0X30, ctx->r14) = 0;
    // 0x8017D414: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017D418: b           L_8017D7D0
    // 0x8017D41C: swc1        $f18, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f18.u32l;
        goto L_8017D7D0;
    // 0x8017D41C: swc1        $f18, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f18.u32l;
L_8017D420:
    // 0x8017D420: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D424: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D428: lbu         $t9, 0x30($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X30);
    // 0x8017D42C: addiu       $t0, $t9, 0x1E
    ctx->r8 = ADD32(ctx->r25, 0X1E);
    // 0x8017D430: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8017D434: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017D438: bne         $at, $zero, L_8017D464
    if (ctx->r1 != 0) {
        // 0x8017D43C: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8017D464;
    }
    // 0x8017D43C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8017D440: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D444: addiu       $t1, $t1, 0x3B40
    ctx->r9 = ADD32(ctx->r9, 0X3B40);
    // 0x8017D448: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8017D44C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D450: sb          $t3, 0x12($t1)
    MEM_B(0X12, ctx->r9) = ctx->r11;
    // 0x8017D454: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017D458: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017D45C: b           L_8017D474
    // 0x8017D460: sb          $t4, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r12;
        goto L_8017D474;
    // 0x8017D460: sb          $t4, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r12;
L_8017D464:
    // 0x8017D464: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D468: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D46C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D470: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
L_8017D474:
    // 0x8017D474: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017D478: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017D47C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D480: lui         $t9, 0xFC32
    ctx->r25 = S32(0XFC32 << 16);
    // 0x8017D484: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8017D488: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017D48C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x8017D490: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8017D494: ori         $t9, $t9, 0x7E64
    ctx->r25 = ctx->r25 | 0X7E64;
    // 0x8017D498: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017D49C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8017D4A0: addiu       $t3, $zero, -0x805
    ctx->r11 = ADD32(0, -0X805);
    // 0x8017D4A4: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017D4A8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8017D4AC: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8017D4B0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x8017D4B4: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x8017D4B8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8017D4BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017D4C0: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8017D4C4: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017D4C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017D4CC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017D4D0: lui         $t7, 0x40
    ctx->r15 = S32(0X40 << 16);
    // 0x8017D4D4: ori         $t7, $t7, 0x49F8
    ctx->r15 = ctx->r15 | 0X49F8;
    // 0x8017D4D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D4DC: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8017D4E0: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8017D4E4: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017D4E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8017D4EC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8017D4F0: jal         0x8017D0BC
    // 0x8017D4F4: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017D4F4: nop

    after_0:
    // 0x8017D4F8: b           L_8017D7D0
    // 0x8017D4FC: nop

        goto L_8017D7D0;
    // 0x8017D4FC: nop

L_8017D500:
    // 0x8017D500: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017D504: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8017D508: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D50C: lui         $t4, 0xFC32
    ctx->r12 = S32(0XFC32 << 16);
    // 0x8017D510: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8017D514: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8017D518: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8017D51C: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8017D520: ori         $t4, $t4, 0x7E64
    ctx->r12 = ctx->r12 | 0X7E64;
    // 0x8017D524: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8017D528: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017D52C: addiu       $t8, $zero, -0x805
    ctx->r24 = ADD32(0, -0X805);
    // 0x8017D530: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017D534: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8017D538: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017D53C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8017D540: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8017D544: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8017D548: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017D54C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x8017D550: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8017D554: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017D558: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017D55C: lui         $t3, 0x44
    ctx->r11 = S32(0X44 << 16);
    // 0x8017D560: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x8017D564: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D568: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8017D56C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8017D570: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017D574: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8017D578: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8017D57C: jal         0x8017D0BC
    // 0x8017D580: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017D580: nop

    after_1:
    // 0x8017D584: b           L_8017D7D0
    // 0x8017D588: nop

        goto L_8017D7D0;
    // 0x8017D588: nop

L_8017D58C:
    // 0x8017D58C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D590: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D594: lbu         $t6, 0x30($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X30);
    // 0x8017D598: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017D59C: addiu       $t7, $t6, -0x1E
    ctx->r15 = ADD32(ctx->r14, -0X1E);
    // 0x8017D5A0: bgez        $t7, L_8017D5C8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017D5A4: sw          $t7, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r15;
            goto L_8017D5C8;
    }
    // 0x8017D5A4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8017D5A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D5AC: addiu       $t9, $t9, 0x3B40
    ctx->r25 = ADD32(ctx->r25, 0X3B40);
    // 0x8017D5B0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8017D5B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D5B8: sb          $t5, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r13;
    // 0x8017D5BC: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017D5C0: b           L_8017D5D8
    // 0x8017D5C4: sb          $zero, 0x30($t0)
    MEM_B(0X30, ctx->r8) = 0;
        goto L_8017D5D8;
    // 0x8017D5C4: sb          $zero, 0x30($t0)
    MEM_B(0X30, ctx->r8) = 0;
L_8017D5C8:
    // 0x8017D5C8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D5CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D5D0: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017D5D4: sb          $t3, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r11;
L_8017D5D8:
    // 0x8017D5D8: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017D5DC: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8017D5E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D5E4: lui         $t8, 0xFC32
    ctx->r24 = S32(0XFC32 << 16);
    // 0x8017D5E8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8017D5EC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017D5F0: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8017D5F4: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017D5F8: ori         $t8, $t8, 0x7E64
    ctx->r24 = ctx->r24 | 0X7E64;
    // 0x8017D5FC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017D600: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8017D604: addiu       $t7, $zero, -0x805
    ctx->r15 = ADD32(0, -0X805);
    // 0x8017D608: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8017D60C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8017D610: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8017D614: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8017D618: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8017D61C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8017D620: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D624: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8017D628: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8017D62C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8017D630: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D634: lui         $t4, 0x40
    ctx->r12 = S32(0X40 << 16);
    // 0x8017D638: ori         $t4, $t4, 0x49F8
    ctx->r12 = ctx->r12 | 0X49F8;
    // 0x8017D63C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D640: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8017D644: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8017D648: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017D64C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8017D650: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8017D654: jal         0x8017D0BC
    // 0x8017D658: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_2;
    // 0x8017D658: nop

    after_2:
    // 0x8017D65C: b           L_8017D7D0
    // 0x8017D660: nop

        goto L_8017D7D0;
    // 0x8017D660: nop

L_8017D664:
    // 0x8017D664: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D668: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017D66C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8017D670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D674: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8017D678: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D67C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017D680: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017D684: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D688: swc1        $f8, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f8.u32l;
    // 0x8017D68C: lwc1        $f10, 0x44($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8017D690: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x8017D694: nop

    // 0x8017D698: bc1f        L_8017D7D0
    if (!c1cs) {
        // 0x8017D69C: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D69C: nop

    // 0x8017D6A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D6A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D6A8: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017D6AC: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8017D6B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D6B4: sb          $t9, 0x12($t0)
    MEM_B(0X12, ctx->r8) = ctx->r25;
    // 0x8017D6B8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017D6BC: b           L_8017D7D0
    // 0x8017D6C0: swc1        $f18, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f18.u32l;
        goto L_8017D7D0;
    // 0x8017D6C0: swc1        $f18, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f18.u32l;
L_8017D6C4:
    // 0x8017D6C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D6C8: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017D6CC: lbu         $t4, 0xB($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0XB);
    // 0x8017D6D0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017D6D4: lbu         $t2, 0x1B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1B);
    // 0x8017D6D8: addiu       $t6, $t4, 0x1E
    ctx->r14 = ADD32(ctx->r12, 0X1E);
    // 0x8017D6DC: slti        $at, $t6, 0x92
    ctx->r1 = SIGNED(ctx->r14) < 0X92 ? 1 : 0;
    // 0x8017D6E0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8017D6E4: lbu         $t8, 0x1C($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1C);
    // 0x8017D6E8: addiu       $t7, $t2, 0x1E
    ctx->r15 = ADD32(ctx->r10, 0X1E);
    // 0x8017D6EC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017D6F0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8017D6F4: addiu       $t5, $t8, 0x1E
    ctx->r13 = ADD32(ctx->r24, 0X1E);
    // 0x8017D6F8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8017D6FC: bne         $at, $zero, L_8017D710
    if (ctx->r1 != 0) {
        // 0x8017D700: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_8017D710;
    }
    // 0x8017D700: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8017D704: addiu       $t9, $zero, 0x91
    ctx->r25 = ADD32(0, 0X91);
    // 0x8017D708: b           L_8017D720
    // 0x8017D70C: sb          $t9, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r25;
        goto L_8017D720;
    // 0x8017D70C: sb          $t9, 0xB($t1)
    MEM_B(0XB, ctx->r9) = ctx->r25;
L_8017D710:
    // 0x8017D710: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D714: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D718: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017D71C: sb          $t0, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r8;
L_8017D720:
    // 0x8017D720: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8017D724: slti        $at, $t4, 0x92
    ctx->r1 = SIGNED(ctx->r12) < 0X92 ? 1 : 0;
    // 0x8017D728: bne         $at, $zero, L_8017D744
    if (ctx->r1 != 0) {
        // 0x8017D72C: nop
    
            goto L_8017D744;
    }
    // 0x8017D72C: nop

    // 0x8017D730: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D734: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017D738: addiu       $t2, $zero, 0x91
    ctx->r10 = ADD32(0, 0X91);
    // 0x8017D73C: b           L_8017D754
    // 0x8017D740: sb          $t2, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r10;
        goto L_8017D754;
    // 0x8017D740: sb          $t2, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r10;
L_8017D744:
    // 0x8017D744: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8017D748: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D74C: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D750: sb          $t8, 0x1B($t5)
    MEM_B(0X1B, ctx->r13) = ctx->r24;
L_8017D754:
    // 0x8017D754: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017D758: slti        $at, $t6, 0x92
    ctx->r1 = SIGNED(ctx->r14) < 0X92 ? 1 : 0;
    // 0x8017D75C: bne         $at, $zero, L_8017D778
    if (ctx->r1 != 0) {
        // 0x8017D760: nop
    
            goto L_8017D778;
    }
    // 0x8017D760: nop

    // 0x8017D764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D768: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017D76C: addiu       $t9, $zero, 0x91
    ctx->r25 = ADD32(0, 0X91);
    // 0x8017D770: b           L_8017D788
    // 0x8017D774: sb          $t9, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r25;
        goto L_8017D788;
    // 0x8017D774: sb          $t9, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r25;
L_8017D778:
    // 0x8017D778: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8017D77C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D780: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017D784: sb          $t0, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = ctx->r8;
L_8017D788:
    // 0x8017D788: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D78C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017D790: lbu         $t2, 0xB($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0XB);
    // 0x8017D794: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D798: bne         $t2, $at, L_8017D7D0
    if (ctx->r10 != ctx->r1) {
        // 0x8017D79C: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D79C: nop

    // 0x8017D7A0: lbu         $t7, 0x1B($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1B);
    // 0x8017D7A4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D7A8: bne         $t7, $at, L_8017D7D0
    if (ctx->r15 != ctx->r1) {
        // 0x8017D7AC: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D7AC: nop

    // 0x8017D7B0: lbu         $t8, 0x1C($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X1C);
    // 0x8017D7B4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D7B8: bne         $t8, $at, L_8017D7D0
    if (ctx->r24 != ctx->r1) {
        // 0x8017D7BC: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D7BC: nop

    // 0x8017D7C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D7C4: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017D7C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017D7CC: sb          $t5, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r13;
L_8017D7D0:
    // 0x8017D7D0: jal         0x8017BFB4
    // 0x8017D7D4: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017D7D4: nop

    after_3:
    // 0x8017D7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D7DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017D7E0: jr          $ra
    // 0x8017D7E4: nop

    return;
    // 0x8017D7E4: nop

;}
RECOMP_FUNC void func_8017D7E8_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D7E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017D7EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D7F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D7F4: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017D7F8: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8017D7FC: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8017D800: beq         $at, $zero, L_8017DD20
    if (ctx->r1 == 0) {
        // 0x8017D804: nop
    
            goto L_8017DD20;
    }
    // 0x8017D804: nop

    // 0x8017D808: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D80C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D810: addu        $at, $at, $t7
    gpr jr_addend_8017D818 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017D814: lw          $t7, -0x1D60($at)
    ctx->r15 = ADD32(ctx->r1, -0X1D60);
    // 0x8017D818: jr          $t7
    // 0x8017D81C: nop

    switch (jr_addend_8017D818 >> 2) {
        case 0: goto L_8017D820; break;
        case 1: goto L_8017D90C; break;
        case 2: goto L_8017D968; break;
        case 3: goto L_8017DA48; break;
        case 4: goto L_8017DAD4; break;
        case 5: goto L_8017DBAC; break;
        case 6: goto L_8017DC14; break;
        default: switch_error(__func__, 0x8017D818, 0x8017E2A0);
    }
    // 0x8017D81C: nop

L_8017D820:
    // 0x8017D820: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D824: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D828: lbu         $t9, 0xB($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB);
    // 0x8017D82C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017D830: lbu         $t0, 0x13($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X13);
    // 0x8017D834: addiu       $t2, $t9, -0x1E
    ctx->r10 = ADD32(ctx->r25, -0X1E);
    // 0x8017D838: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8017D83C: lbu         $t1, 0x1C($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1C);
    // 0x8017D840: addiu       $t3, $t0, -0x1E
    ctx->r11 = ADD32(ctx->r8, -0X1E);
    // 0x8017D844: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017D848: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8017D84C: addiu       $t4, $t1, -0x1E
    ctx->r12 = ADD32(ctx->r9, -0X1E);
    // 0x8017D850: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8017D854: bgtz        $t2, L_8017D864
    if (SIGNED(ctx->r10) > 0) {
        // 0x8017D858: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_8017D864;
    }
    // 0x8017D858: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8017D85C: b           L_8017D874
    // 0x8017D860: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
        goto L_8017D874;
    // 0x8017D860: sb          $zero, 0xB($t8)
    MEM_B(0XB, ctx->r24) = 0;
L_8017D864:
    // 0x8017D864: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D868: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D86C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D870: sb          $t5, 0xB($t6)
    MEM_B(0XB, ctx->r14) = ctx->r13;
L_8017D874:
    // 0x8017D874: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8017D878: bgtz        $t7, L_8017D890
    if (SIGNED(ctx->r15) > 0) {
        // 0x8017D87C: nop
    
            goto L_8017D890;
    }
    // 0x8017D87C: nop

    // 0x8017D880: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D884: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017D888: b           L_8017D8A0
    // 0x8017D88C: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
        goto L_8017D8A0;
    // 0x8017D88C: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
L_8017D890:
    // 0x8017D890: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8017D894: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D898: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017D89C: sb          $t0, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r8;
L_8017D8A0:
    // 0x8017D8A0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017D8A4: bgtz        $t1, L_8017D8BC
    if (SIGNED(ctx->r9) > 0) {
        // 0x8017D8A8: nop
    
            goto L_8017D8BC;
    }
    // 0x8017D8A8: nop

    // 0x8017D8AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D8B0: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017D8B4: b           L_8017D8CC
    // 0x8017D8B8: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
        goto L_8017D8CC;
    // 0x8017D8B8: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
L_8017D8BC:
    // 0x8017D8BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8017D8C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D8C4: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D8C8: sb          $t2, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r10;
L_8017D8CC:
    // 0x8017D8CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D8D0: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D8D4: lbu         $t6, 0xB($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XB);
    // 0x8017D8D8: bne         $t6, $zero, L_8017DD20
    if (ctx->r14 != 0) {
        // 0x8017D8DC: nop
    
            goto L_8017DD20;
    }
    // 0x8017D8DC: nop

    // 0x8017D8E0: lbu         $t7, 0x13($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X13);
    // 0x8017D8E4: bne         $t7, $zero, L_8017DD20
    if (ctx->r15 != 0) {
        // 0x8017D8E8: nop
    
            goto L_8017DD20;
    }
    // 0x8017D8E8: nop

    // 0x8017D8EC: lbu         $t9, 0x1C($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X1C);
    // 0x8017D8F0: bne         $t9, $zero, L_8017DD20
    if (ctx->r25 != 0) {
        // 0x8017D8F4: nop
    
            goto L_8017DD20;
    }
    // 0x8017D8F4: nop

    // 0x8017D8F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D8FC: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017D900: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017D904: b           L_8017DD20
    // 0x8017D908: sb          $t0, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r8;
        goto L_8017DD20;
    // 0x8017D908: sb          $t0, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r8;
L_8017D90C:
    // 0x8017D90C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D910: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017D914: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8017D918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D91C: lwc1        $f4, 0x64($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8017D920: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D924: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D928: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017D92C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017D930: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D934: swc1        $f8, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->f8.u32l;
    // 0x8017D938: lwc1        $f10, 0x64($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X64);
    // 0x8017D93C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8017D940: nop

    // 0x8017D944: bc1f        L_8017DD20
    if (!c1cs) {
        // 0x8017D948: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_8017DD20;
    }
    // 0x8017D948: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017D94C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D950: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D954: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x8017D958: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8017D95C: swc1        $f18, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->f18.u32l;
    // 0x8017D960: b           L_8017DD20
    // 0x8017D964: sb          $t2, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r10;
        goto L_8017DD20;
    // 0x8017D964: sb          $t2, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r10;
L_8017D968:
    // 0x8017D968: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D96C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D970: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x8017D974: addiu       $t5, $t7, 0x1E
    ctx->r13 = ADD32(ctx->r15, 0X1E);
    // 0x8017D978: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x8017D97C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8017D980: bne         $at, $zero, L_8017D9AC
    if (ctx->r1 != 0) {
        // 0x8017D984: sw          $t5, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r13;
            goto L_8017D9AC;
    }
    // 0x8017D984: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8017D988: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D98C: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017D990: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017D994: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D998: sb          $t9, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r25;
    // 0x8017D99C: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017D9A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017D9A4: b           L_8017D9BC
    // 0x8017D9A8: sb          $t3, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r11;
        goto L_8017D9BC;
    // 0x8017D9A8: sb          $t3, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r11;
L_8017D9AC:
    // 0x8017D9AC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D9B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D9B4: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017D9B8: sb          $t4, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r12;
L_8017D9BC:
    // 0x8017D9BC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017D9C0: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x8017D9C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D9C8: lui         $t7, 0xFC32
    ctx->r15 = S32(0XFC32 << 16);
    // 0x8017D9CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8017D9D0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8017D9D4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8017D9D8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8017D9DC: ori         $t7, $t7, 0x7E64
    ctx->r15 = ctx->r15 | 0X7E64;
    // 0x8017D9E0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8017D9E4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017D9E8: addiu       $t9, $zero, -0x805
    ctx->r25 = ADD32(0, -0X805);
    // 0x8017D9EC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017D9F0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8017D9F4: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8017D9F8: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x8017D9FC: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x8017DA00: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8017DA04: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017DA08: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8017DA0C: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8017DA10: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8017DA14: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017DA18: lui         $t8, 0x40
    ctx->r24 = S32(0X40 << 16);
    // 0x8017DA1C: ori         $t8, $t8, 0x49F8
    ctx->r24 = ctx->r24 | 0X49F8;
    // 0x8017DA20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DA24: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017DA28: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8017DA2C: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8017DA30: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8017DA34: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8017DA38: jal         0x8017D0BC
    // 0x8017DA3C: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017DA3C: nop

    after_0:
    // 0x8017DA40: b           L_8017DD20
    // 0x8017DA44: nop

        goto L_8017DD20;
    // 0x8017DA44: nop

L_8017DA48:
    // 0x8017DA48: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8017DA4C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8017DA50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017DA54: lui         $t3, 0xFC32
    ctx->r11 = S32(0XFC32 << 16);
    // 0x8017DA58: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8017DA5C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017DA60: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8017DA64: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8017DA68: ori         $t3, $t3, 0x7E64
    ctx->r11 = ctx->r11 | 0X7E64;
    // 0x8017DA6C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8017DA70: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8017DA74: addiu       $t4, $zero, -0x805
    ctx->r12 = ADD32(0, -0X805);
    // 0x8017DA78: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017DA7C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8017DA80: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x8017DA84: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x8017DA88: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8017DA8C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8017DA90: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8017DA94: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8017DA98: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8017DA9C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8017DAA0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017DAA4: lui         $t9, 0x44
    ctx->r25 = S32(0X44 << 16);
    // 0x8017DAA8: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x8017DAAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DAB0: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8017DAB4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8017DAB8: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8017DABC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8017DAC0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8017DAC4: jal         0x8017D0BC
    // 0x8017DAC8: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017DAC8: nop

    after_1:
    // 0x8017DACC: b           L_8017DD20
    // 0x8017DAD0: nop

        goto L_8017DD20;
    // 0x8017DAD0: nop

L_8017DAD4:
    // 0x8017DAD4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DAD8: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017DADC: lbu         $t2, 0x30($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X30);
    // 0x8017DAE0: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017DAE4: addiu       $t8, $t2, -0x1E
    ctx->r24 = ADD32(ctx->r10, -0X1E);
    // 0x8017DAE8: bgez        $t8, L_8017DB10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8017DAEC: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_8017DB10;
    }
    // 0x8017DAEC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8017DAF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DAF4: addiu       $t7, $t7, 0x3B40
    ctx->r15 = ADD32(ctx->r15, 0X3B40);
    // 0x8017DAF8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8017DAFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017DB00: sb          $t6, 0x13($t7)
    MEM_B(0X13, ctx->r15) = ctx->r14;
    // 0x8017DB04: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017DB08: b           L_8017DB20
    // 0x8017DB0C: sb          $zero, 0x30($t5)
    MEM_B(0X30, ctx->r13) = 0;
        goto L_8017DB20;
    // 0x8017DB0C: sb          $zero, 0x30($t5)
    MEM_B(0X30, ctx->r13) = 0;
L_8017DB10:
    // 0x8017DB10: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8017DB14: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DB18: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017DB1C: sb          $t9, 0x30($t0)
    MEM_B(0X30, ctx->r8) = ctx->r25;
L_8017DB20:
    // 0x8017DB20: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017DB24: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8017DB28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017DB2C: lui         $t4, 0xFC32
    ctx->r12 = S32(0XFC32 << 16);
    // 0x8017DB30: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8017DB34: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8017DB38: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8017DB3C: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8017DB40: ori         $t4, $t4, 0x7E64
    ctx->r12 = ctx->r12 | 0X7E64;
    // 0x8017DB44: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8017DB48: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017DB4C: addiu       $t8, $zero, -0x805
    ctx->r24 = ADD32(0, -0X805);
    // 0x8017DB50: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017DB54: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8017DB58: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017DB5C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8017DB60: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8017DB64: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8017DB68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DB6C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x8017DB70: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8017DB74: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017DB78: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DB7C: lui         $t3, 0x40
    ctx->r11 = S32(0X40 << 16);
    // 0x8017DB80: ori         $t3, $t3, 0x49F8
    ctx->r11 = ctx->r11 | 0X49F8;
    // 0x8017DB84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DB88: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8017DB8C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8017DB90: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8017DB94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8017DB98: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8017DB9C: jal         0x8017D0BC
    // 0x8017DBA0: nop

    func_8017D0BC_111CC0(rdram, ctx);
        goto after_2;
    // 0x8017DBA0: nop

    after_2:
    // 0x8017DBA4: b           L_8017DD20
    // 0x8017DBA8: nop

        goto L_8017DD20;
    // 0x8017DBA8: nop

L_8017DBAC:
    // 0x8017DBAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DBB0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017DBB4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8017DBB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DBBC: lwc1        $f4, 0x64($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8017DBC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DBC4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017DBC8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017DBCC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8017DBD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017DBD4: swc1        $f8, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->f8.u32l;
    // 0x8017DBD8: lwc1        $f10, 0x64($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X64);
    // 0x8017DBDC: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x8017DBE0: nop

    // 0x8017DBE4: bc1f        L_8017DD20
    if (!c1cs) {
        // 0x8017DBE8: nop
    
            goto L_8017DD20;
    }
    // 0x8017DBE8: nop

    // 0x8017DBEC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017DBF0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8017DBF4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017DBF8: addiu       $t5, $t5, 0x3B40
    ctx->r13 = ADD32(ctx->r13, 0X3B40);
    // 0x8017DBFC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8017DC00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DC04: sb          $t7, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r15;
    // 0x8017DC08: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017DC0C: b           L_8017DD20
    // 0x8017DC10: swc1        $f18, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->f18.u32l;
        goto L_8017DD20;
    // 0x8017DC10: swc1        $f18, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->f18.u32l;
L_8017DC14:
    // 0x8017DC14: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DC18: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017DC1C: lbu         $t3, 0xB($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XB);
    // 0x8017DC20: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8017DC24: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x8017DC28: addiu       $t2, $t3, 0x1E
    ctx->r10 = ADD32(ctx->r11, 0X1E);
    // 0x8017DC2C: slti        $at, $t2, 0x92
    ctx->r1 = SIGNED(ctx->r10) < 0X92 ? 1 : 0;
    // 0x8017DC30: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8017DC34: lbu         $t4, 0x1C($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1C);
    // 0x8017DC38: addiu       $t8, $t1, 0x1E
    ctx->r24 = ADD32(ctx->r9, 0X1E);
    // 0x8017DC3C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017DC40: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8017DC44: addiu       $t6, $t4, 0x1E
    ctx->r14 = ADD32(ctx->r12, 0X1E);
    // 0x8017DC48: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8017DC4C: bne         $at, $zero, L_8017DC60
    if (ctx->r1 != 0) {
        // 0x8017DC50: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8017DC60;
    }
    // 0x8017DC50: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8017DC54: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8017DC58: b           L_8017DC70
    // 0x8017DC5C: sb          $t7, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r15;
        goto L_8017DC70;
    // 0x8017DC5C: sb          $t7, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r15;
L_8017DC60:
    // 0x8017DC60: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8017DC64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DC68: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017DC6C: sb          $t5, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r13;
L_8017DC70:
    // 0x8017DC70: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8017DC74: slti        $at, $t3, 0x92
    ctx->r1 = SIGNED(ctx->r11) < 0X92 ? 1 : 0;
    // 0x8017DC78: bne         $at, $zero, L_8017DC94
    if (ctx->r1 != 0) {
        // 0x8017DC7C: nop
    
            goto L_8017DC94;
    }
    // 0x8017DC7C: nop

    // 0x8017DC80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DC84: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017DC88: addiu       $t1, $zero, 0x91
    ctx->r9 = ADD32(0, 0X91);
    // 0x8017DC8C: b           L_8017DCA4
    // 0x8017DC90: sb          $t1, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r9;
        goto L_8017DCA4;
    // 0x8017DC90: sb          $t1, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r9;
L_8017DC94:
    // 0x8017DC94: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8017DC98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DC9C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017DCA0: sb          $t4, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r12;
L_8017DCA4:
    // 0x8017DCA4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8017DCA8: slti        $at, $t2, 0x92
    ctx->r1 = SIGNED(ctx->r10) < 0X92 ? 1 : 0;
    // 0x8017DCAC: bne         $at, $zero, L_8017DCC8
    if (ctx->r1 != 0) {
        // 0x8017DCB0: nop
    
            goto L_8017DCC8;
    }
    // 0x8017DCB0: nop

    // 0x8017DCB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DCB8: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017DCBC: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8017DCC0: b           L_8017DCD8
    // 0x8017DCC4: sb          $t7, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r15;
        goto L_8017DCD8;
    // 0x8017DCC4: sb          $t7, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r15;
L_8017DCC8:
    // 0x8017DCC8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8017DCCC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DCD0: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017DCD4: sb          $t5, 0x1C($t9)
    MEM_B(0X1C, ctx->r25) = ctx->r13;
L_8017DCD8:
    // 0x8017DCD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DCDC: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017DCE0: lbu         $t1, 0xB($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0XB);
    // 0x8017DCE4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017DCE8: bne         $t1, $at, L_8017DD20
    if (ctx->r9 != ctx->r1) {
        // 0x8017DCEC: nop
    
            goto L_8017DD20;
    }
    // 0x8017DCEC: nop

    // 0x8017DCF0: lbu         $t8, 0x13($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X13);
    // 0x8017DCF4: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017DCF8: bne         $t8, $at, L_8017DD20
    if (ctx->r24 != ctx->r1) {
        // 0x8017DCFC: nop
    
            goto L_8017DD20;
    }
    // 0x8017DCFC: nop

    // 0x8017DD00: lbu         $t4, 0x1C($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1C);
    // 0x8017DD04: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017DD08: bne         $t4, $at, L_8017DD20
    if (ctx->r12 != ctx->r1) {
        // 0x8017DD0C: nop
    
            goto L_8017DD20;
    }
    // 0x8017DD0C: nop

    // 0x8017DD10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DD14: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017DD18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017DD1C: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
L_8017DD20:
    // 0x8017DD20: jal         0x8017BFB4
    // 0x8017DD24: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017DD24: nop

    after_3:
    // 0x8017DD28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DD2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017DD30: jr          $ra
    // 0x8017DD34: nop

    return;
    // 0x8017DD34: nop

;}
RECOMP_FUNC void func_8017DD38_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DD38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017DD3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DD40: jal         0x8017BFB4
    // 0x8017DD44: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017DD44: nop

    after_0:
    // 0x8017DD48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DD4C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017DD50: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017DD54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DD58: lwc1        $f4, 0x80($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X80);
    // 0x8017DD5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DD60: addiu       $t7, $t7, 0x3B40
    ctx->r15 = ADD32(ctx->r15, 0X3B40);
    // 0x8017DD64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017DD68: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017DD6C: swc1        $f8, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->f8.u32l;
    // 0x8017DD70: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8017DD74: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x8017DD78: andi        $t9, $t8, 0x2000
    ctx->r25 = ctx->r24 & 0X2000;
    // 0x8017DD7C: bne         $t9, $zero, L_8017DD8C
    if (ctx->r25 != 0) {
        // 0x8017DD80: nop
    
            goto L_8017DD8C;
    }
    // 0x8017DD80: nop

    // 0x8017DD84: jal         0x800C6DD4
    // 0x8017DD88: nop

    func_800C6DD4(rdram, ctx);
        goto after_1;
    // 0x8017DD88: nop

    after_1:
L_8017DD8C:
    // 0x8017DD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DD90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017DD94: jr          $ra
    // 0x8017DD98: nop

    return;
    // 0x8017DD98: nop

;}
RECOMP_FUNC void func_8017DD9C_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017DDA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DDA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DDA8: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x8017DDAC: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017DDB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017DDB4: nop

    // 0x8017DDB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017DDBC: nop

    // 0x8017DDC0: bc1t        L_8017DDF4
    if (c1cs) {
        // 0x8017DDC4: lui         $at, 0x4580
        ctx->r1 = S32(0X4580 << 16);
            goto L_8017DDF4;
    }
    // 0x8017DDC4: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8017DDC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017DDCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017DDD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017DDD4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017DDD8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017DDDC: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8017DDE0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8017DDE4: jal         0x800CB7A4
    // 0x8017DDE8: nop

    func_800CB7A4(rdram, ctx);
        goto after_0;
    // 0x8017DDE8: nop

    after_0:
    // 0x8017DDEC: b           L_8017DDFC
    // 0x8017DDF0: nop

        goto L_8017DDFC;
    // 0x8017DDF0: nop

L_8017DDF4:
    // 0x8017DDF4: jal         0x800CB7A4
    // 0x8017DDF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB7A4(rdram, ctx);
        goto after_1;
    // 0x8017DDF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_8017DDFC:
    // 0x8017DDFC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DE00: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8017DE04: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017DE08: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017DE0C: nop

    // 0x8017DE10: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x8017DE14: nop

    // 0x8017DE18: bc1t        L_8017DE4C
    if (c1cs) {
        // 0x8017DE1C: lui         $at, 0x4580
        ctx->r1 = S32(0X4580 << 16);
            goto L_8017DE4C;
    }
    // 0x8017DE1C: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8017DE20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017DE24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017DE28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017DE2C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8017DE30: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8017DE34: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8017DE38: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8017DE3C: jal         0x800CB83C
    // 0x8017DE40: nop

    func_800CB83C(rdram, ctx);
        goto after_2;
    // 0x8017DE40: nop

    after_2:
    // 0x8017DE44: b           L_8017DE54
    // 0x8017DE48: nop

        goto L_8017DE54;
    // 0x8017DE48: nop

L_8017DE4C:
    // 0x8017DE4C: jal         0x800CB83C
    // 0x8017DE50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB83C(rdram, ctx);
        goto after_3;
    // 0x8017DE50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_8017DE54:
    // 0x8017DE54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DE58: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8017DE5C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017DE60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017DE64: nop

    // 0x8017DE68: c.eq.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl == ctx->f10.fl;
    // 0x8017DE6C: nop

    // 0x8017DE70: bc1t        L_8017DE88
    if (c1cs) {
        // 0x8017DE74: nop
    
            goto L_8017DE88;
    }
    // 0x8017DE74: nop

    // 0x8017DE78: jal         0x800CB8AC
    // 0x8017DE7C: nop

    func_800CB8AC(rdram, ctx);
        goto after_4;
    // 0x8017DE7C: nop

    after_4:
    // 0x8017DE80: b           L_8017DE90
    // 0x8017DE84: nop

        goto L_8017DE90;
    // 0x8017DE84: nop

L_8017DE88:
    // 0x8017DE88: jal         0x800CB8A0
    // 0x8017DE8C: nop

    func_800CB8A0(rdram, ctx);
        goto after_5;
    // 0x8017DE8C: nop

    after_5:
L_8017DE90:
    // 0x8017DE90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017DE98: jr          $ra
    // 0x8017DE9C: nop

    return;
    // 0x8017DE9C: nop

;}
RECOMP_FUNC void func_8017DEA0_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DEA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DEA4: jr          $ra
    // 0x8017DEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8017DEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8017DEAC_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DEAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017DEB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017DEB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017DEB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017DEBC: bgtz        $t6, L_8017E06C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017DEC0: nop
    
            goto L_8017E06C;
    }
    // 0x8017DEC0: nop

    // 0x8017DEC4: jal         0x800C3704
    // 0x8017DEC8: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017DEC8: nop

    after_0:
    // 0x8017DECC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017DED0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017DED4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017DED8: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017DEDC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8017DEE0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017DEE4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017DEE8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017DEEC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017DEF0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8017DEF4: jal         0x800C7458
    // 0x8017DEF8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017DEF8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017DEFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017DF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017DF04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DF08: jal         0x800C25FC
    // 0x8017DF0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017DF0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017DF10: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017DF14: jal         0x800D54C8
    // 0x8017DF18: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_3;
    // 0x8017DF18: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_3:
    // 0x8017DF1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017DF20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017DF24: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017DF28: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x8017DF2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017DF30: addiu       $a0, $a0, -0x1B70
    ctx->r4 = ADD32(ctx->r4, -0X1B70);
    // 0x8017DF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017DF38: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8017DF3C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8017DF40: jal         0x800C6C6C
    // 0x8017DF44: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x8017DF44: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8017DF48: jal         0x800C6D5C
    // 0x8017DF4C: nop

    func_800C6D5C(rdram, ctx);
        goto after_5;
    // 0x8017DF4C: nop

    after_5:
    // 0x8017DF50: jal         0x800C3578
    // 0x8017DF54: nop

    func_800C3578(rdram, ctx);
        goto after_6;
    // 0x8017DF54: nop

    after_6:
    // 0x8017DF58: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DF5C: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017DF60: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8017DF64: sltiu       $at, $t4, 0x7
    ctx->r1 = ctx->r12 < 0X7 ? 1 : 0;
    // 0x8017DF68: beq         $at, $zero, L_8017E018
    if (ctx->r1 == 0) {
        // 0x8017DF6C: nop
    
            goto L_8017E018;
    }
    // 0x8017DF6C: nop

    // 0x8017DF70: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017DF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017DF78: addu        $at, $at, $t4
    gpr jr_addend_8017DF80 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017DF7C: lw          $t4, -0x1D44($at)
    ctx->r12 = ADD32(ctx->r1, -0X1D44);
    // 0x8017DF80: jr          $t4
    // 0x8017DF84: nop

    switch (jr_addend_8017DF80 >> 2) {
        case 0: goto L_8017DF88; break;
        case 1: goto L_8017DF98; break;
        case 2: goto L_8017DFB0; break;
        case 3: goto L_8017DFC8; break;
        case 4: goto L_8017DFE0; break;
        case 5: goto L_8017E010; break;
        case 6: goto L_8017DFF8; break;
        default: switch_error(__func__, 0x8017DF80, 0x8017E2BC);
    }
    // 0x8017DF84: nop

L_8017DF88:
    // 0x8017DF88: jal         0x8017C5B8
    // 0x8017DF8C: nop

    func_8017C5B8_111CC0(rdram, ctx);
        goto after_7;
    // 0x8017DF8C: nop

    after_7:
    // 0x8017DF90: b           L_8017E018
    // 0x8017DF94: nop

        goto L_8017E018;
    // 0x8017DF94: nop

L_8017DF98:
    // 0x8017DF98: jal         0x8017B0C0
    // 0x8017DF9C: nop

    func_8017B0C0_111CC0(rdram, ctx);
        goto after_8;
    // 0x8017DF9C: nop

    after_8:
    // 0x8017DFA0: jal         0x8017C664
    // 0x8017DFA4: nop

    func_8017C664_111CC0(rdram, ctx);
        goto after_9;
    // 0x8017DFA4: nop

    after_9:
    // 0x8017DFA8: b           L_8017E018
    // 0x8017DFAC: nop

        goto L_8017E018;
    // 0x8017DFAC: nop

L_8017DFB0:
    // 0x8017DFB0: jal         0x8017B340
    // 0x8017DFB4: nop

    func_8017B340_111CC0(rdram, ctx);
        goto after_10;
    // 0x8017DFB4: nop

    after_10:
    // 0x8017DFB8: jal         0x8017C7D8
    // 0x8017DFBC: nop

    func_8017C7D8_111CC0(rdram, ctx);
        goto after_11;
    // 0x8017DFBC: nop

    after_11:
    // 0x8017DFC0: b           L_8017E018
    // 0x8017DFC4: nop

        goto L_8017E018;
    // 0x8017DFC4: nop

L_8017DFC8:
    // 0x8017DFC8: jal         0x8017B51C
    // 0x8017DFCC: nop

    func_8017B51C_111CC0(rdram, ctx);
        goto after_12;
    // 0x8017DFCC: nop

    after_12:
    // 0x8017DFD0: jal         0x8017D288
    // 0x8017DFD4: nop

    func_8017D288_111CC0(rdram, ctx);
        goto after_13;
    // 0x8017DFD4: nop

    after_13:
    // 0x8017DFD8: b           L_8017E018
    // 0x8017DFDC: nop

        goto L_8017E018;
    // 0x8017DFDC: nop

L_8017DFE0:
    // 0x8017DFE0: jal         0x8017B74C
    // 0x8017DFE4: nop

    func_8017B74C_111CC0(rdram, ctx);
        goto after_14;
    // 0x8017DFE4: nop

    after_14:
    // 0x8017DFE8: jal         0x8017D7E8
    // 0x8017DFEC: nop

    func_8017D7E8_111CC0(rdram, ctx);
        goto after_15;
    // 0x8017DFEC: nop

    after_15:
    // 0x8017DFF0: b           L_8017E018
    // 0x8017DFF4: nop

        goto L_8017E018;
    // 0x8017DFF4: nop

L_8017DFF8:
    // 0x8017DFF8: jal         0x8017C664
    // 0x8017DFFC: nop

    func_8017C664_111CC0(rdram, ctx);
        goto after_16;
    // 0x8017DFFC: nop

    after_16:
    // 0x8017E000: jal         0x8017B97C
    // 0x8017E004: nop

    func_8017B97C_111CC0(rdram, ctx);
        goto after_17;
    // 0x8017E004: nop

    after_17:
    // 0x8017E008: b           L_8017E018
    // 0x8017E00C: nop

        goto L_8017E018;
    // 0x8017E00C: nop

L_8017E010:
    // 0x8017E010: jal         0x8017DD38
    // 0x8017E014: nop

    func_8017DD38_111CC0(rdram, ctx);
        goto after_18;
    // 0x8017E014: nop

    after_18:
L_8017E018:
    // 0x8017E018: jal         0x800C3FD0
    // 0x8017E01C: nop

    func_800C3FD0(rdram, ctx);
        goto after_19;
    // 0x8017E01C: nop

    after_19:
    // 0x8017E020: jal         0x800C3760
    // 0x8017E024: nop

    func_800C3760(rdram, ctx);
        goto after_20;
    // 0x8017E024: nop

    after_20:
    // 0x8017E028: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E02C: lhu         $t5, -0x2E4C($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E4C);
    // 0x8017E030: beq         $t5, $zero, L_8017E06C
    if (ctx->r13 == 0) {
        // 0x8017E034: nop
    
            goto L_8017E06C;
    }
    // 0x8017E034: nop

    // 0x8017E038: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8017E03C: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x8017E040: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8017E044: bne         $t7, $zero, L_8017E06C
    if (ctx->r15 != 0) {
        // 0x8017E048: nop
    
            goto L_8017E06C;
    }
    // 0x8017E048: nop

    // 0x8017E04C: jal         0x800CB720
    // 0x8017E050: nop

    func_800CB720(rdram, ctx);
        goto after_21;
    // 0x8017E050: nop

    after_21:
    // 0x8017E054: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017E058: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8017E05C: bne         $t8, $zero, L_8017E06C
    if (ctx->r24 != 0) {
        // 0x8017E060: nop
    
            goto L_8017E06C;
    }
    // 0x8017E060: nop

    // 0x8017E064: jal         0x800D1640
    // 0x8017E068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_22;
    // 0x8017E068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
L_8017E06C:
    // 0x8017E06C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017E074: jr          $ra
    // 0x8017E078: nop

    return;
    // 0x8017E078: nop

;}
RECOMP_FUNC void func_8017E07C_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E07C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8017E080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E084: sh          $t6, -0x2E50($at)
    MEM_H(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017E088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E08C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E090: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E098: sh          $zero, -0x2E4C($at)
    MEM_H(-0X2E4C, ctx->r1) = 0;
    // 0x8017E09C: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017E0A0: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017E0A4: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017E0A8: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x8017E0AC: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8017E0B0: jal         0x800C30F4
    // 0x8017E0B4: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017E0B4: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x8017E0B8: jal         0x8017BD18
    // 0x8017E0BC: nop

    func_8017BD18_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017E0BC: nop

    after_1:
    // 0x8017E0C0: jal         0x800C328C
    // 0x8017E0C4: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017E0C4: nop

    after_2:
    // 0x8017E0C8: jal         0x800C7FA4
    // 0x8017E0CC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017E0CC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x8017E0D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017E0D4: jal         0x800D1640
    // 0x8017E0D8: addiu       $a0, $a0, -0x2154
    ctx->r4 = ADD32(ctx->r4, -0X2154);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017E0D8: addiu       $a0, $a0, -0x2154
    ctx->r4 = ADD32(ctx->r4, -0X2154);
    after_4:
L_8017E0DC:
    // 0x8017E0DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E0E0: lhu         $t0, -0x2E4C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2E4C);
    // 0x8017E0E4: beq         $t0, $zero, L_8017E0DC
    if (ctx->r8 == 0) {
        // 0x8017E0E8: nop
    
            goto L_8017E0DC;
    }
    // 0x8017E0E8: nop

    // 0x8017E0EC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017E0F0: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017E0F4: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8017E0F8: bne         $t2, $zero, L_8017E0DC
    if (ctx->r10 != 0) {
        // 0x8017E0FC: nop
    
            goto L_8017E0DC;
    }
    // 0x8017E0FC: nop

    // 0x8017E100: jal         0x800CB720
    // 0x8017E104: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x8017E104: nop

    after_5:
    // 0x8017E108: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017E10C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E110: bne         $t3, $zero, L_8017E0DC
    if (ctx->r11 != 0) {
        // 0x8017E114: nop
    
            goto L_8017E0DC;
    }
    // 0x8017E114: nop

    // 0x8017E118: jal         0x8017DD9C
    // 0x8017E11C: nop

    func_8017DD9C_111CC0(rdram, ctx);
        goto after_6;
    // 0x8017E11C: nop

    after_6:
    // 0x8017E120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E128: jr          $ra
    // 0x8017E12C: nop

    return;
    // 0x8017E12C: nop

;}
RECOMP_FUNC void func_8017B0C0_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8017B0C4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8017B0C8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8017B0CC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B0D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8017B0D4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x8017B0D8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8017B0DC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8017B0E0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8017B0E4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8017B0E8: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x8017B0EC: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x8017B0F0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8017B0F4: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8017B0F8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8017B0FC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8017B100: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8017B104: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017B108: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x8017B10C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8017B110: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8017B114: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8017B118: addiu       $t5, $t5, -0x51D0
    ctx->r13 = ADD32(ctx->r13, -0X51D0);
    // 0x8017B11C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8017B120: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8017B124: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8017B128: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017B12C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8017B130: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8017B134: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B138: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x8017B13C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8017B140: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B144: ori         $t9, $t9, 0x7E24
    ctx->r25 = ctx->r25 | 0X7E24;
    // 0x8017B148: addiu       $t1, $zero, -0x805
    ctx->r9 = ADD32(0, -0X805);
    // 0x8017B14C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8017B150: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8017B154: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B158: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B15C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B160: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8017B164: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8017B168: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8017B16C: beq         $t3, $zero, L_8017B200
    if (ctx->r11 == 0) {
        // 0x8017B170: nop
    
            goto L_8017B200;
    }
    // 0x8017B170: nop

    // 0x8017B174: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017B178: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8017B17C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B180: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8017B184: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8017B188: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8017B18C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8017B190: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8017B194: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8017B198: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8017B19C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8017B1A0: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8017B1A4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8017B1A8: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8017B1AC: lui         $t3, 0x3030
    ctx->r11 = S32(0X3030 << 16);
    // 0x8017B1B0: ori         $t3, $t3, 0x3080
    ctx->r11 = ctx->r11 | 0X3080;
    // 0x8017B1B4: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8017B1B8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8017B1BC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8017B1C0: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8017B1C4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8017B1C8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8017B1CC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8017B1D0: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x8017B1D4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8017B1D8: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x8017B1DC: ori         $t7, $t7, 0xFE23
    ctx->r15 = ctx->r15 | 0XFE23;
    // 0x8017B1E0: addiu       $t9, $zero, -0x805
    ctx->r25 = ADD32(0, -0X805);
    // 0x8017B1E4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8017B1E8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8017B1EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8017B1F0: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8017B1F4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8017B1F8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8017B1FC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8017B200:
    // 0x8017B200: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017B204: lw          $s0, -0x2E44($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E44);
    // 0x8017B208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B20C: beq         $s0, $at, L_8017B234
    if (ctx->r16 == ctx->r1) {
        // 0x8017B210: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B234;
    }
    // 0x8017B210: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B214: beq         $s0, $at, L_8017B338
    if (ctx->r16 == ctx->r1) {
        // 0x8017B218: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017B338;
    }
    // 0x8017B218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B21C: beq         $s0, $at, L_8017B43C
    if (ctx->r16 == ctx->r1) {
        // 0x8017B220: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017B43C;
    }
    // 0x8017B220: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017B224: beq         $s0, $at, L_8017B540
    if (ctx->r16 == ctx->r1) {
        // 0x8017B228: nop
    
            goto L_8017B540;
    }
    // 0x8017B228: nop

    // 0x8017B22C: b           L_8017B63C
    // 0x8017B230: nop

        goto L_8017B63C;
    // 0x8017B230: nop

L_8017B234:
    // 0x8017B234: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8017B238:
    // 0x8017B238: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B23C: lw          $t1, -0x2E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E38);
    // 0x8017B240: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B244: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017B248: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8017B24C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8017B250: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B254: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B258: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B25C: lhu         $t6, -0x2680($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2680);
    // 0x8017B260: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B264: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017B268: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017B26C: sh          $t6, -0x1DFC($at)
    MEM_H(-0X1DFC, ctx->r1) = ctx->r14;
    // 0x8017B270: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x8017B274: bne         $at, $zero, L_8017B238
    if (ctx->r1 != 0) {
        // 0x8017B278: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_8017B238;
    }
    // 0x8017B278: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8017B27C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B280: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B284: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B288: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B28C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B290: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B294: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017B298: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B29C: addiu       $a0, $a0, -0x29E8
    ctx->r4 = ADD32(ctx->r4, -0X29E8);
    // 0x8017B2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B2A4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B2A8: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8017B2AC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017B2B0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017B2B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017B2B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017B2BC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017B2C0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017B2C4: jal         0x800C58E8
    // 0x8017B2C8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x8017B2C8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8017B2CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8017B2D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B2D4: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017B2D8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B2DC: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B2E0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8017B2E4: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B2E8: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B2EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B2F0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017B2F4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B2F8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B2FC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8017B300: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017B304: addiu       $a0, $a0, -0x29D0
    ctx->r4 = ADD32(ctx->r4, -0X29D0);
    // 0x8017B308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B30C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B310: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8017B314: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017B318: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8017B31C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017B320: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017B324: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017B328: jal         0x800C5B94
    // 0x8017B32C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_800C5B94(rdram, ctx);
        goto after_1;
    // 0x8017B32C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017B330: b           L_8017B63C
    // 0x8017B334: nop

        goto L_8017B63C;
    // 0x8017B334: nop

L_8017B338:
    // 0x8017B338: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8017B33C:
    // 0x8017B33C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B340: lw          $t1, -0x2E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E38);
    // 0x8017B344: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B348: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8017B34C: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x8017B350: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8017B354: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8017B358: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8017B35C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B360: lhu         $t4, -0x2560($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2560);
    // 0x8017B364: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B368: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017B36C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017B370: sh          $t4, -0x1DFC($at)
    MEM_H(-0X1DFC, ctx->r1) = ctx->r12;
    // 0x8017B374: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x8017B378: bne         $at, $zero, L_8017B33C
    if (ctx->r1 != 0) {
        // 0x8017B37C: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_8017B33C;
    }
    // 0x8017B37C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8017B380: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B384: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B388: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B38C: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B390: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B394: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B398: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017B39C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B3A0: addiu       $a0, $a0, -0x2928
    ctx->r4 = ADD32(ctx->r4, -0X2928);
    // 0x8017B3A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B3A8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B3AC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8017B3B0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017B3B4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017B3B8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017B3BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8017B3C0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017B3C4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017B3C8: jal         0x800C58E8
    // 0x8017B3CC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800C58E8(rdram, ctx);
        goto after_2;
    // 0x8017B3CC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8017B3D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8017B3D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B3D8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017B3DC: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B3E0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B3E4: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8017B3E8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B3EC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B3F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B3F4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8017B3F8: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B3FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B400: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8017B404: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017B408: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    // 0x8017B40C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B410: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B414: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8017B418: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017B41C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017B420: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017B424: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017B428: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017B42C: jal         0x800C5B94
    // 0x8017B430: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800C5B94(rdram, ctx);
        goto after_3;
    // 0x8017B430: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8017B434: b           L_8017B63C
    // 0x8017B438: nop

        goto L_8017B63C;
    // 0x8017B438: nop

L_8017B43C:
    // 0x8017B43C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8017B440:
    // 0x8017B440: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B444: lw          $t1, -0x2E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E38);
    // 0x8017B448: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B44C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017B450: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8017B454: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x8017B458: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B45C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017B460: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B464: lhu         $t5, -0x2320($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2320);
    // 0x8017B468: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B46C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017B470: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017B474: sh          $t5, -0x1DFC($at)
    MEM_H(-0X1DFC, ctx->r1) = ctx->r13;
    // 0x8017B478: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x8017B47C: bne         $at, $zero, L_8017B440
    if (ctx->r1 != 0) {
        // 0x8017B480: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_8017B440;
    }
    // 0x8017B480: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8017B484: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B488: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B48C: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B490: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B494: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B498: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B49C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017B4A0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B4A4: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    // 0x8017B4A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B4AC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B4B0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8017B4B4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017B4B8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017B4BC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017B4C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017B4C4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017B4C8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017B4CC: jal         0x800C58E8
    // 0x8017B4D0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_800C58E8(rdram, ctx);
        goto after_4;
    // 0x8017B4D0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8017B4D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8017B4D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B4DC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017B4E0: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B4E4: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B4E8: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8017B4EC: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B4F0: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B4F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B4F8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8017B4FC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B500: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B504: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8017B508: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017B50C: addiu       $a0, $a0, -0x2848
    ctx->r4 = ADD32(ctx->r4, -0X2848);
    // 0x8017B510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B514: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B518: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017B51C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017B520: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8017B524: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017B528: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017B52C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017B530: jal         0x800C5B94
    // 0x8017B534: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800C5B94(rdram, ctx);
        goto after_5;
    // 0x8017B534: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8017B538: b           L_8017B63C
    // 0x8017B53C: nop

        goto L_8017B63C;
    // 0x8017B53C: nop

L_8017B540:
    // 0x8017B540: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_8017B544:
    // 0x8017B544: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B548: lw          $t1, -0x2E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E38);
    // 0x8017B54C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B550: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017B554: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x8017B558: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8017B55C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017B560: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B564: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8017B568: lhu         $t6, -0x2200($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2200);
    // 0x8017B56C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B570: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017B574: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017B578: sh          $t6, -0x1DFC($at)
    MEM_H(-0X1DFC, ctx->r1) = ctx->r14;
    // 0x8017B57C: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x8017B580: bne         $at, $zero, L_8017B544
    if (ctx->r1 != 0) {
        // 0x8017B584: sw          $t8, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r24;
            goto L_8017B544;
    }
    // 0x8017B584: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8017B588: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B58C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B590: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B594: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B598: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B59C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B5A0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017B5A4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B5A8: addiu       $a0, $a0, -0x27B0
    ctx->r4 = ADD32(ctx->r4, -0X27B0);
    // 0x8017B5AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B5B0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B5B4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x8017B5B8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017B5BC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017B5C0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017B5C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8017B5C8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017B5CC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017B5D0: jal         0x800C58E8
    // 0x8017B5D4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_800C58E8(rdram, ctx);
        goto after_6;
    // 0x8017B5D4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8017B5D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8017B5DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B5E0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017B5E4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017B5E8: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017B5EC: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8017B5F0: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017B5F4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017B5F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B5FC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8017B600: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017B604: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017B608: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8017B60C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017B610: addiu       $a0, $a0, -0x2798
    ctx->r4 = ADD32(ctx->r4, -0X2798);
    // 0x8017B614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B618: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8017B61C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017B620: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017B624: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8017B628: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017B62C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017B630: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017B634: jal         0x800C5B94
    // 0x8017B638: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_800C5B94(rdram, ctx);
        goto after_7;
    // 0x8017B638: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_7:
L_8017B63C:
    // 0x8017B63C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8017B640: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8017B644: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8017B648: jr          $ra
    // 0x8017B64C: nop

    return;
    // 0x8017B64C: nop

;}
RECOMP_FUNC void func_8017B650_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B650: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8017B654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B658: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017B65C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B664: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B66C: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017B670: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017B674: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017B678: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8017B67C: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017B680: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8017B684: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    // 0x8017B688: jal         0x800C30F4
    // 0x8017B68C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017B68C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    after_0:
    // 0x8017B690: jal         0x8017B7E8
    // 0x8017B694: nop

    func_8017B7E8_1199D0(rdram, ctx);
        goto after_1;
    // 0x8017B694: nop

    after_1:
    // 0x8017B698: jal         0x800C328C
    // 0x8017B69C: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017B69C: nop

    after_2:
    // 0x8017B6A0: jal         0x800C7FA4
    // 0x8017B6A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017B6A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8017B6A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B6AC: jal         0x800D1640
    // 0x8017B6B0: addiu       $a0, $a0, -0x4900
    ctx->r4 = ADD32(ctx->r4, -0X4900);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017B6B0: addiu       $a0, $a0, -0x4900
    ctx->r4 = ADD32(ctx->r4, -0X4900);
    after_4:
L_8017B6B4:
    // 0x8017B6B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B6B8: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8017B6BC: beq         $t0, $zero, L_8017B6B4
    if (ctx->r8 == 0) {
        // 0x8017B6C0: nop
    
            goto L_8017B6B4;
    }
    // 0x8017B6C0: nop

    // 0x8017B6C4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017B6C8: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017B6CC: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8017B6D0: bne         $t2, $zero, L_8017B6B4
    if (ctx->r10 != 0) {
        // 0x8017B6D4: nop
    
            goto L_8017B6B4;
    }
    // 0x8017B6D4: nop

    // 0x8017B6D8: jal         0x800CB720
    // 0x8017B6DC: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x8017B6DC: nop

    after_5:
    // 0x8017B6E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B6E4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B6E8: bne         $t3, $zero, L_8017B6B4
    if (ctx->r11 != 0) {
        // 0x8017B6EC: nop
    
            goto L_8017B6B4;
    }
    // 0x8017B6EC: nop

    // 0x8017B6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B6F8: jr          $ra
    // 0x8017B6FC: nop

    return;
    // 0x8017B6FC: nop

;}
RECOMP_FUNC void func_8017B700_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B708: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B70C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B710: bgtz        $t6, L_8017B7D8
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017B714: nop
    
            goto L_8017B7D8;
    }
    // 0x8017B714: nop

    // 0x8017B718: jal         0x800C3704
    // 0x8017B71C: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017B71C: nop

    after_0:
    // 0x8017B720: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B724: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B728: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B72C: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017B730: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017B734: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017B738: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B73C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B740: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B744: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017B748: jal         0x800C7458
    // 0x8017B74C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017B74C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017B750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B75C: jal         0x800C25FC
    // 0x8017B760: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017B760: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017B764: jal         0x8017D438
    // 0x8017B768: nop

    func_8017D438_1199D0(rdram, ctx);
        goto after_3;
    // 0x8017B768: nop

    after_3:
    // 0x8017B76C: jal         0x800C3578
    // 0x8017B770: nop

    func_800C3578(rdram, ctx);
        goto after_4;
    // 0x8017B770: nop

    after_4:
    // 0x8017B774: jal         0x8017B9D0
    // 0x8017B778: nop

    func_8017B9D0_1199D0(rdram, ctx);
        goto after_5;
    // 0x8017B778: nop

    after_5:
    // 0x8017B77C: jal         0x8017CCF4
    // 0x8017B780: nop

    func_8017CCF4_1199D0(rdram, ctx);
        goto after_6;
    // 0x8017B780: nop

    after_6:
    // 0x8017B784: jal         0x800C3FD0
    // 0x8017B788: nop

    func_800C3FD0(rdram, ctx);
        goto after_7;
    // 0x8017B788: nop

    after_7:
    // 0x8017B78C: jal         0x800C3760
    // 0x8017B790: nop

    func_800C3760(rdram, ctx);
        goto after_8;
    // 0x8017B790: nop

    after_8:
    // 0x8017B794: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B798: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017B79C: beq         $t2, $zero, L_8017B7D8
    if (ctx->r10 == 0) {
        // 0x8017B7A0: nop
    
            goto L_8017B7D8;
    }
    // 0x8017B7A0: nop

    // 0x8017B7A4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017B7A8: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017B7AC: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017B7B0: bne         $t4, $zero, L_8017B7D8
    if (ctx->r12 != 0) {
        // 0x8017B7B4: nop
    
            goto L_8017B7D8;
    }
    // 0x8017B7B4: nop

    // 0x8017B7B8: jal         0x800CB720
    // 0x8017B7BC: nop

    func_800CB720(rdram, ctx);
        goto after_9;
    // 0x8017B7BC: nop

    after_9:
    // 0x8017B7C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B7C4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B7C8: bne         $t5, $zero, L_8017B7D8
    if (ctx->r13 != 0) {
        // 0x8017B7CC: nop
    
            goto L_8017B7D8;
    }
    // 0x8017B7CC: nop

    // 0x8017B7D0: jal         0x800D1640
    // 0x8017B7D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_10;
    // 0x8017B7D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
L_8017B7D8:
    // 0x8017B7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B7DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B7E0: jr          $ra
    // 0x8017B7E4: nop

    return;
    // 0x8017B7E4: nop

;}
RECOMP_FUNC void func_8017B7E8_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B7E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B7EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B7F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B7F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B7F8: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
    // 0x8017B7FC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B800: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B804: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8017B808: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B80C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017B810: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B814: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8017B818: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B81C: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
    // 0x8017B820: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B824: lw          $t0, -0x2E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E44);
    // 0x8017B828: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B82C: beq         $t0, $at, L_8017B848
    if (ctx->r8 == ctx->r1) {
        // 0x8017B830: nop
    
            goto L_8017B848;
    }
    // 0x8017B830: nop

    // 0x8017B834: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B838: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B83C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017B840: b           L_8017B854
    // 0x8017B844: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
        goto L_8017B854;
    // 0x8017B844: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
L_8017B848:
    // 0x8017B848: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B84C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B850: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
L_8017B854:
    // 0x8017B854: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B858: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017B85C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B860: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x8017B864: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B868: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B86C: sw          $zero, 0x14($t5)
    MEM_W(0X14, ctx->r13) = 0;
    // 0x8017B870: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B874: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B878: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8017B87C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B880: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
    // 0x8017B884: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B888: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B88C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B890: sw          $zero, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = 0;
    // 0x8017B894: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B898: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B89C: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
    // 0x8017B8A0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017B8A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B8A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B8AC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017B8B0: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x8017B8B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B8B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B8BC: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8017B8C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B8C4: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017B8C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B8CC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017B8D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B8D4: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017B8D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B8DC: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x8017B8E0: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017B8E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B8E8: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8017B8EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B8F0: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017B8F4: swc1        $f16, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f16.u32l;
    // 0x8017B8F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B8FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B900: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x8017B904: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B908: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017B90C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B910: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B914: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017B918: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B91C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B920: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x8017B924: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B928: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017B92C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B930: swc1        $f6, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f6.u32l;
    // 0x8017B934: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B938: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B93C: swc1        $f8, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f8.u32l;
    // 0x8017B940: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B944: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017B948: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B94C: swc1        $f10, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f10.u32l;
    // 0x8017B950: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017B954: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x8017B958: jal         0x800C3FD0
    // 0x8017B95C: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B95C: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    after_0:
    // 0x8017B960: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017B964: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017B968: jal         0x800C6E0C
    // 0x8017B96C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x8017B96C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8017B970: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8017B974: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8017B978: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017B97C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017B980: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017B984: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017B988: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017B98C: jal         0x800C6E68
    // 0x8017B990: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x8017B990: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_2:
    // 0x8017B994: addiu       $t3, $zero, 0x3E3
    ctx->r11 = ADD32(0, 0X3E3);
    // 0x8017B998: addiu       $t4, $zero, 0x3E8
    ctx->r12 = ADD32(0, 0X3E8);
    // 0x8017B99C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017B9A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017B9A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B9A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B9AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B9B0: jal         0x800C70C0
    // 0x8017B9B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C70C0(rdram, ctx);
        goto after_3;
    // 0x8017B9B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8017B9B8: jal         0x800C6DBC
    // 0x8017B9BC: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x8017B9BC: nop

    after_4:
    // 0x8017B9C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B9C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B9C8: jr          $ra
    // 0x8017B9CC: nop

    return;
    // 0x8017B9CC: nop

;}
RECOMP_FUNC void func_8017B9D0_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B9D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B9D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B9D8: jal         0x800D8790
    // 0x8017B9DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    guRandom_recomp(rdram, ctx);
        goto after_0;
    // 0x8017B9DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8017B9E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B9E4: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8017B9E8: beq         $t6, $zero, L_8017B9F8
    if (ctx->r14 == 0) {
        // 0x8017B9EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B9F8;
    }
    // 0x8017B9EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B9F0: bne         $t6, $at, L_8017BD2C
    if (ctx->r14 != ctx->r1) {
        // 0x8017B9F4: nop
    
            goto L_8017BD2C;
    }
    // 0x8017B9F4: nop

L_8017B9F8:
    // 0x8017B9F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B9FC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017BA00: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017BA04: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8017BA08: beq         $at, $zero, L_8017BD2C
    if (ctx->r1 == 0) {
        // 0x8017BA0C: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BA0C: nop

    // 0x8017BA10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BA14: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017BA18: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8017BA1C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8017BA20: andi        $t1, $t0, 0x1F
    ctx->r9 = ctx->r8 & 0X1F;
    // 0x8017BA24: bne         $t1, $at, L_8017BD10
    if (ctx->r9 != ctx->r1) {
        // 0x8017BA28: nop
    
            goto L_8017BD10;
    }
    // 0x8017BA28: nop

    // 0x8017BA2C: lw          $s0, 0x1C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X1C);
    // 0x8017BA30: beq         $s0, $zero, L_8017BA58
    if (ctx->r16 == 0) {
        // 0x8017BA34: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017BA58;
    }
    // 0x8017BA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BA38: beq         $s0, $at, L_8017BAF4
    if (ctx->r16 == ctx->r1) {
        // 0x8017BA3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017BAF4;
    }
    // 0x8017BA3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BA40: beq         $s0, $at, L_8017BB90
    if (ctx->r16 == ctx->r1) {
        // 0x8017BA44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017BB90;
    }
    // 0x8017BA44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017BA48: beq         $s0, $at, L_8017BC2C
    if (ctx->r16 == ctx->r1) {
        // 0x8017BA4C: nop
    
            goto L_8017BC2C;
    }
    // 0x8017BA4C: nop

    // 0x8017BA50: b           L_8017BD2C
    // 0x8017BA54: nop

        goto L_8017BD2C;
    // 0x8017BA54: nop

L_8017BA58:
    // 0x8017BA58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BA5C: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017BA60: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8017BA64: andi        $t4, $t3, 0x100
    ctx->r12 = ctx->r11 & 0X100;
    // 0x8017BA68: beq         $t4, $zero, L_8017BA84
    if (ctx->r12 == 0) {
        // 0x8017BA6C: nop
    
            goto L_8017BA84;
    }
    // 0x8017BA6C: nop

    // 0x8017BA70: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BA74: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017BA78: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x8017BA7C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8017BA80: sw          $t8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r24;
L_8017BA84:
    // 0x8017BA84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BA88: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017BA8C: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017BA90: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x8017BA94: beq         $t1, $zero, L_8017BAA8
    if (ctx->r9 == 0) {
        // 0x8017BA98: nop
    
            goto L_8017BAA8;
    }
    // 0x8017BA98: nop

    // 0x8017BA9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BAA0: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017BAA4: sw          $zero, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = 0;
L_8017BAA8:
    // 0x8017BAA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BAAC: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017BAB0: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8017BAB4: andi        $t4, $t3, 0x200
    ctx->r12 = ctx->r11 & 0X200;
    // 0x8017BAB8: beq         $t4, $zero, L_8017BACC
    if (ctx->r12 == 0) {
        // 0x8017BABC: nop
    
            goto L_8017BACC;
    }
    // 0x8017BABC: nop

    // 0x8017BAC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BAC4: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BAC8: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
L_8017BACC:
    // 0x8017BACC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BAD0: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017BAD4: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x8017BAD8: andi        $t9, $t5, 0x400
    ctx->r25 = ctx->r13 & 0X400;
    // 0x8017BADC: beq         $t9, $zero, L_8017BD2C
    if (ctx->r25 == 0) {
        // 0x8017BAE0: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BAE0: nop

    // 0x8017BAE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BAE8: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017BAEC: b           L_8017BD2C
    // 0x8017BAF0: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
        goto L_8017BD2C;
    // 0x8017BAF0: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
L_8017BAF4:
    // 0x8017BAF4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BAF8: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017BAFC: lhu         $t7, 0x2($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X2);
    // 0x8017BB00: andi        $t2, $t7, 0x800
    ctx->r10 = ctx->r15 & 0X800;
    // 0x8017BB04: beq         $t2, $zero, L_8017BB20
    if (ctx->r10 == 0) {
        // 0x8017BB08: nop
    
            goto L_8017BB20;
    }
    // 0x8017BB08: nop

    // 0x8017BB0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BB10: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017BB14: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x8017BB18: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8017BB1C: sw          $t6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r14;
L_8017BB20:
    // 0x8017BB20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BB24: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017BB28: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x8017BB2C: andi        $t9, $t5, 0x100
    ctx->r25 = ctx->r13 & 0X100;
    // 0x8017BB30: beq         $t9, $zero, L_8017BB44
    if (ctx->r25 == 0) {
        // 0x8017BB34: nop
    
            goto L_8017BB44;
    }
    // 0x8017BB34: nop

    // 0x8017BB38: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BB3C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017BB40: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
L_8017BB44:
    // 0x8017BB44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BB48: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017BB4C: lhu         $t7, 0x2($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X2);
    // 0x8017BB50: andi        $t2, $t7, 0x200
    ctx->r10 = ctx->r15 & 0X200;
    // 0x8017BB54: beq         $t2, $zero, L_8017BB68
    if (ctx->r10 == 0) {
        // 0x8017BB58: nop
    
            goto L_8017BB68;
    }
    // 0x8017BB58: nop

    // 0x8017BB5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BB60: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017BB64: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
L_8017BB68:
    // 0x8017BB68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BB6C: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017BB70: lhu         $t3, 0x2($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X2);
    // 0x8017BB74: andi        $t8, $t3, 0x400
    ctx->r24 = ctx->r11 & 0X400;
    // 0x8017BB78: beq         $t8, $zero, L_8017BD2C
    if (ctx->r24 == 0) {
        // 0x8017BB7C: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BB7C: nop

    // 0x8017BB80: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BB84: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017BB88: b           L_8017BD2C
    // 0x8017BB8C: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
        goto L_8017BD2C;
    // 0x8017BB8C: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
L_8017BB90:
    // 0x8017BB90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BB94: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017BB98: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017BB9C: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x8017BBA0: beq         $t1, $zero, L_8017BBBC
    if (ctx->r9 == 0) {
        // 0x8017BBA4: nop
    
            goto L_8017BBBC;
    }
    // 0x8017BBA4: nop

    // 0x8017BBA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BBAC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017BBB0: lw          $t2, 0x1C($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X1C);
    // 0x8017BBB4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8017BBB8: sw          $t4, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r12;
L_8017BBBC:
    // 0x8017BBBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BBC0: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017BBC4: lhu         $t3, 0x2($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X2);
    // 0x8017BBC8: andi        $t8, $t3, 0x100
    ctx->r24 = ctx->r11 & 0X100;
    // 0x8017BBCC: beq         $t8, $zero, L_8017BBE0
    if (ctx->r24 == 0) {
        // 0x8017BBD0: nop
    
            goto L_8017BBE0;
    }
    // 0x8017BBD0: nop

    // 0x8017BBD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BBD8: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017BBDC: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
L_8017BBE0:
    // 0x8017BBE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BBE4: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017BBE8: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017BBEC: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x8017BBF0: beq         $t1, $zero, L_8017BC04
    if (ctx->r9 == 0) {
        // 0x8017BBF4: nop
    
            goto L_8017BC04;
    }
    // 0x8017BBF4: nop

    // 0x8017BBF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BBFC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017BC00: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
L_8017BC04:
    // 0x8017BC04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BC08: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017BC0C: lhu         $t7, 0x2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X2);
    // 0x8017BC10: andi        $t6, $t7, 0x400
    ctx->r14 = ctx->r15 & 0X400;
    // 0x8017BC14: beq         $t6, $zero, L_8017BD2C
    if (ctx->r14 == 0) {
        // 0x8017BC18: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BC18: nop

    // 0x8017BC1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BC20: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017BC24: b           L_8017BD2C
    // 0x8017BC28: sw          $zero, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = 0;
        goto L_8017BD2C;
    // 0x8017BC28: sw          $zero, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = 0;
L_8017BC2C:
    // 0x8017BC2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BC30: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017BC34: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x8017BC38: andi        $t9, $t5, 0x400
    ctx->r25 = ctx->r13 & 0X400;
    // 0x8017BC3C: beq         $t9, $zero, L_8017BC54
    if (ctx->r25 == 0) {
        // 0x8017BC40: nop
    
            goto L_8017BC54;
    }
    // 0x8017BC40: nop

    // 0x8017BC44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BC48: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017BC4C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8017BC50: sw          $t0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r8;
L_8017BC54:
    // 0x8017BC54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BC58: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017BC5C: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x8017BC60: andi        $t7, $t4, 0x100
    ctx->r15 = ctx->r12 & 0X100;
    // 0x8017BC64: beq         $t7, $zero, L_8017BC78
    if (ctx->r15 == 0) {
        // 0x8017BC68: nop
    
            goto L_8017BC78;
    }
    // 0x8017BC68: nop

    // 0x8017BC6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BC70: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BC74: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
L_8017BC78:
    // 0x8017BC78: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BC7C: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x8017BC80: lhu         $t8, 0x2($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X2);
    // 0x8017BC84: andi        $t5, $t8, 0x800
    ctx->r13 = ctx->r24 & 0X800;
    // 0x8017BC88: beq         $t5, $zero, L_8017BC9C
    if (ctx->r13 == 0) {
        // 0x8017BC8C: nop
    
            goto L_8017BC9C;
    }
    // 0x8017BC8C: nop

    // 0x8017BC90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BC94: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017BC98: sw          $zero, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = 0;
L_8017BC9C:
    // 0x8017BC9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BCA0: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017BCA4: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x8017BCA8: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x8017BCAC: beq         $t2, $zero, L_8017BCC0
    if (ctx->r10 == 0) {
        // 0x8017BCB0: nop
    
            goto L_8017BCC0;
    }
    // 0x8017BCB0: nop

    // 0x8017BCB4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BCB8: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017BCBC: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
L_8017BCC0:
    // 0x8017BCC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BCC4: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017BCC8: lw          $t6, 0x1C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1C);
    // 0x8017BCCC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017BCD0: bne         $t6, $at, L_8017BD2C
    if (ctx->r14 != ctx->r1) {
        // 0x8017BCD4: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BCD4: nop

    // 0x8017BCD8: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x8017BCDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017BCE0: beq         $t3, $at, L_8017BCF0
    if (ctx->r11 == ctx->r1) {
        // 0x8017BCE4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8017BCF0;
    }
    // 0x8017BCE4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017BCE8: bne         $t3, $at, L_8017BD00
    if (ctx->r11 != ctx->r1) {
        // 0x8017BCEC: nop
    
            goto L_8017BD00;
    }
    // 0x8017BCEC: nop

L_8017BCF0:
    // 0x8017BCF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BCF4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017BCF8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8017BCFC: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_8017BD00:
    // 0x8017BD00: jal         0x800C8544
    // 0x8017BD04: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017BD04: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_1:
    // 0x8017BD08: b           L_8017BD2C
    // 0x8017BD0C: nop

        goto L_8017BD2C;
    // 0x8017BD0C: nop

L_8017BD10:
    // 0x8017BD10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BD14: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017BD18: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x8017BD1C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017BD20: beq         $t0, $at, L_8017BD2C
    if (ctx->r8 == ctx->r1) {
        // 0x8017BD24: nop
    
            goto L_8017BD2C;
    }
    // 0x8017BD24: nop

    // 0x8017BD28: sw          $zero, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = 0;
L_8017BD2C:
    // 0x8017BD2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BD30: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017BD34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017BD38: sltiu       $at, $t2, 0xB
    ctx->r1 = ctx->r10 < 0XB ? 1 : 0;
    // 0x8017BD3C: beq         $at, $zero, L_8017C678
    if (ctx->r1 == 0) {
        // 0x8017BD40: nop
    
            goto L_8017C678;
    }
    // 0x8017BD40: nop

    // 0x8017BD44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BD48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BD4C: addu        $at, $at, $t2
    gpr jr_addend_8017BD54 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017BD50: lw          $t2, -0x1F4C($at)
    ctx->r10 = ADD32(ctx->r1, -0X1F4C);
    // 0x8017BD54: jr          $t2
    // 0x8017BD58: nop

    switch (jr_addend_8017BD54 >> 2) {
        case 0: goto L_8017BD5C; break;
        case 1: goto L_8017BD5C; break;
        case 2: goto L_8017BE84; break;
        case 3: goto L_8017C01C; break;
        case 4: goto L_8017C1EC; break;
        case 5: goto L_8017C2F4; break;
        case 6: goto L_8017C418; break;
        case 7: goto L_8017C5C4; break;
        case 8: goto L_8017C620; break;
        case 9: goto L_8017C678; break;
        case 10: goto L_8017C678; break;
        default: switch_error(__func__, 0x8017BD54, 0x8017E0B4);
    }
    // 0x8017BD58: nop

L_8017BD5C:
    // 0x8017BD5C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017BD60: lhu         $t4, -0x4530($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4530);
    // 0x8017BD64: andi        $t6, $t4, 0x10
    ctx->r14 = ctx->r12 & 0X10;
    // 0x8017BD68: bne         $t6, $zero, L_8017BDBC
    if (ctx->r14 != 0) {
        // 0x8017BD6C: nop
    
            goto L_8017BDBC;
    }
    // 0x8017BD6C: nop

    // 0x8017BD70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BD74: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017BD78: lhu         $t3, 0x2($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X2);
    // 0x8017BD7C: andi        $t8, $t3, 0xB000
    ctx->r24 = ctx->r11 & 0XB000;
    // 0x8017BD80: beq         $t8, $zero, L_8017BDBC
    if (ctx->r24 == 0) {
        // 0x8017BD84: nop
    
            goto L_8017BDBC;
    }
    // 0x8017BD84: nop

    // 0x8017BD88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BD8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BD90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BD94: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017BD98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BD9C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017BDA0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BDA4: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x8017BDA8: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017BDAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017BDB0: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8017BDB4: b           L_8017C678
    // 0x8017BDB8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_8017C678;
    // 0x8017BDB8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8017BDBC:
    // 0x8017BDBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BDC0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017BDC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BDC8: lwc1        $f10, -0x1F20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1F20);
    // 0x8017BDCC: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8017BDD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BDD4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017BDD8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017BDDC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8017BDE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BDE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BDE8: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8017BDEC: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017BDF0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017BDF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BDF8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017BDFC: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x8017BE00: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017BE04: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8017BE08: nop

    // 0x8017BE0C: bc1f        L_8017C678
    if (!c1cs) {
        // 0x8017BE10: nop
    
            goto L_8017C678;
    }
    // 0x8017BE10: nop

    // 0x8017BE14: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017BE18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017BE1C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BE20: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017BE24: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8017BE28: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017BE2C: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x8017BE30: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017BE34: beq         $s0, $zero, L_8017BE5C
    if (ctx->r16 == 0) {
        // 0x8017BE38: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017BE5C;
    }
    // 0x8017BE38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BE3C: beq         $s0, $at, L_8017BE5C
    if (ctx->r16 == ctx->r1) {
        // 0x8017BE40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017BE5C;
    }
    // 0x8017BE40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BE44: beq         $s0, $at, L_8017BE70
    if (ctx->r16 == ctx->r1) {
        // 0x8017BE48: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017BE70;
    }
    // 0x8017BE48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017BE4C: beq         $s0, $at, L_8017BE70
    if (ctx->r16 == ctx->r1) {
        // 0x8017BE50: nop
    
            goto L_8017BE70;
    }
    // 0x8017BE50: nop

    // 0x8017BE54: b           L_8017C678
    // 0x8017BE58: nop

        goto L_8017C678;
    // 0x8017BE58: nop

L_8017BE5C:
    // 0x8017BE5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BE60: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017BE64: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8017BE68: b           L_8017C678
    // 0x8017BE6C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
        goto L_8017C678;
    // 0x8017BE6C: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_8017BE70:
    // 0x8017BE70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BE74: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017BE78: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8017BE7C: b           L_8017C678
    // 0x8017BE80: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_8017C678;
    // 0x8017BE80: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_8017BE84:
    // 0x8017BE84: jal         0x8017C68C
    // 0x8017BE88: nop

    func_8017C68C_1199D0(rdram, ctx);
        goto after_2;
    // 0x8017BE88: nop

    after_2:
    // 0x8017BE8C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BE90: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017BE94: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8017BE98: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x8017BE9C: beq         $t2, $zero, L_8017BFAC
    if (ctx->r10 == 0) {
        // 0x8017BEA0: nop
    
            goto L_8017BFAC;
    }
    // 0x8017BEA0: nop

    // 0x8017BEA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BEA8: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x8017BEAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BEB0: bne         $t4, $at, L_8017BEE0
    if (ctx->r12 != ctx->r1) {
        // 0x8017BEB4: nop
    
            goto L_8017BEE0;
    }
    // 0x8017BEB4: nop

    // 0x8017BEB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BEBC: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8017BEC0: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8017BEC4: beq         $at, $zero, L_8017BEE0
    if (ctx->r1 == 0) {
        // 0x8017BEC8: nop
    
            goto L_8017BEE0;
    }
    // 0x8017BEC8: nop

    // 0x8017BECC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BED0: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017BED4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017BED8: b           L_8017BFAC
    // 0x8017BEDC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
        goto L_8017BFAC;
    // 0x8017BEDC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
L_8017BEE0:
    // 0x8017BEE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BEE4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017BEE8: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8017BEEC: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8017BEF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BEF4: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x8017BEF8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8017BEFC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8017BF00: beq         $t0, $zero, L_8017BF64
    if (ctx->r8 == 0) {
        // 0x8017BF04: nop
    
            goto L_8017BF64;
    }
    // 0x8017BF04: nop

L_8017BF08:
    // 0x8017BF08: jal         0x800D1E30
    // 0x8017BF0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800D1E30(rdram, ctx);
        goto after_3;
    // 0x8017BF0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8017BF10: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017BF14: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BF18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BF1C: beq         $t9, $at, L_8017BF34
    if (ctx->r25 == ctx->r1) {
        // 0x8017BF20: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8017BF34;
    }
    // 0x8017BF20: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017BF24: beq         $t9, $at, L_8017BF34
    if (ctx->r25 == ctx->r1) {
        // 0x8017BF28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017BF34;
    }
    // 0x8017BF28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017BF2C: bne         $t9, $at, L_8017BF44
    if (ctx->r25 != ctx->r1) {
        // 0x8017BF30: nop
    
            goto L_8017BF44;
    }
    // 0x8017BF30: nop

L_8017BF34:
    // 0x8017BF34: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BF38: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017BF3C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8017BF40: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8017BF44:
    // 0x8017BF44: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8017BF48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BF4C: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x8017BF50: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8017BF54: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8017BF58: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x8017BF5C: bne         $at, $zero, L_8017BF08
    if (ctx->r1 != 0) {
        // 0x8017BF60: nop
    
            goto L_8017BF08;
    }
    // 0x8017BF60: nop

L_8017BF64:
    // 0x8017BF64: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BF68: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017BF6C: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8017BF70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017BF74: bne         $t8, $at, L_8017BFAC
    if (ctx->r24 != ctx->r1) {
        // 0x8017BF78: nop
    
            goto L_8017BFAC;
    }
    // 0x8017BF78: nop

    // 0x8017BF7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BF80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BF84: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BF88: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017BF8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BF90: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017BF94: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x8017BF98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017BF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BFA0: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8017BFA4: jal         0x800C32CC
    // 0x8017BFA8: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    func_800C32CC(rdram, ctx);
        goto after_4;
    // 0x8017BFA8: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    after_4:
L_8017BFAC:
    // 0x8017BFAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BFB0: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017BFB4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8017BFB8: bne         $t2, $zero, L_8017C678
    if (ctx->r10 != 0) {
        // 0x8017BFBC: nop
    
            goto L_8017C678;
    }
    // 0x8017BFBC: nop

    // 0x8017BFC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BFC4: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017BFC8: lhu         $t6, 0x2($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X2);
    // 0x8017BFCC: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8017BFD0: beq         $t7, $zero, L_8017C678
    if (ctx->r15 == 0) {
        // 0x8017BFD4: nop
    
            goto L_8017C678;
    }
    // 0x8017BFD4: nop

    // 0x8017BFD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BFDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BFE0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BFE4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BFE8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BFEC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BFF0: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8017BFF4: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8017BFF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BFFC: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x8017C000: jal         0x800C32CC
    // 0x8017C004: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    func_800C32CC(rdram, ctx);
        goto after_5;
    // 0x8017C004: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    after_5:
    // 0x8017C008: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C00C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017C010: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8017C014: b           L_8017C678
    // 0x8017C018: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
        goto L_8017C678;
    // 0x8017C018: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8017C01C:
    // 0x8017C01C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C020: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C024: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8017C028: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017C02C: bne         $t2, $at, L_8017C044
    if (ctx->r10 != ctx->r1) {
        // 0x8017C030: nop
    
            goto L_8017C044;
    }
    // 0x8017C030: nop

    // 0x8017C034: jal         0x8017CA14
    // 0x8017C038: nop

    func_8017CA14_1199D0(rdram, ctx);
        goto after_6;
    // 0x8017C038: nop

    after_6:
    // 0x8017C03C: b           L_8017C058
    // 0x8017C040: nop

        goto L_8017C058;
    // 0x8017C040: nop

L_8017C044:
    // 0x8017C044: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C048: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C04C: lw          $t6, 0x18($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X18);
    // 0x8017C050: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8017C054: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
L_8017C058:
    // 0x8017C058: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C05C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C060: lw          $t8, 0x18($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X18);
    // 0x8017C064: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x8017C068: beq         $at, $zero, L_8017C088
    if (ctx->r1 == 0) {
        // 0x8017C06C: nop
    
            goto L_8017C088;
    }
    // 0x8017C06C: nop

    // 0x8017C070: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C074: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8017C078: lhu         $t0, 0x2($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X2);
    // 0x8017C07C: andi        $t9, $t0, 0xB000
    ctx->r25 = ctx->r8 & 0XB000;
    // 0x8017C080: beq         $t9, $zero, L_8017C17C
    if (ctx->r25 == 0) {
        // 0x8017C084: nop
    
            goto L_8017C17C;
    }
    // 0x8017C084: nop

L_8017C088:
    // 0x8017C088: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C08C: lw          $t1, -0x2E44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E44);
    // 0x8017C090: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x8017C094: beq         $at, $zero, L_8017C0B0
    if (ctx->r1 == 0) {
        // 0x8017C098: nop
    
            goto L_8017C0B0;
    }
    // 0x8017C098: nop

    // 0x8017C09C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C0A0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C0A4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8017C0A8: b           L_8017C17C
    // 0x8017C0AC: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
        goto L_8017C17C;
    // 0x8017C0AC: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_8017C0B0:
    // 0x8017C0B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C0B4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C0B8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8017C0BC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8017C0C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C0C4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x8017C0C8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8017C0CC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8017C0D0: beq         $t3, $zero, L_8017C134
    if (ctx->r11 == 0) {
        // 0x8017C0D4: nop
    
            goto L_8017C134;
    }
    // 0x8017C0D4: nop

L_8017C0D8:
    // 0x8017C0D8: jal         0x800D1E30
    // 0x8017C0DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800D1E30(rdram, ctx);
        goto after_7;
    // 0x8017C0DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x8017C0E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017C0E4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C0E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C0EC: beq         $t8, $at, L_8017C104
    if (ctx->r24 == ctx->r1) {
        // 0x8017C0F0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8017C104;
    }
    // 0x8017C0F0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017C0F4: beq         $t8, $at, L_8017C104
    if (ctx->r24 == ctx->r1) {
        // 0x8017C0F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017C104;
    }
    // 0x8017C0F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017C0FC: bne         $t8, $at, L_8017C114
    if (ctx->r24 != ctx->r1) {
        // 0x8017C100: nop
    
            goto L_8017C114;
    }
    // 0x8017C100: nop

L_8017C104:
    // 0x8017C104: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C108: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C10C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8017C110: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_8017C114:
    // 0x8017C114: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017C118: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C11C: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x8017C120: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8017C124: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8017C128: sltu        $at, $t1, $t2
    ctx->r1 = ctx->r9 < ctx->r10 ? 1 : 0;
    // 0x8017C12C: bne         $at, $zero, L_8017C0D8
    if (ctx->r1 != 0) {
        // 0x8017C130: nop
    
            goto L_8017C0D8;
    }
    // 0x8017C130: nop

L_8017C134:
    // 0x8017C134: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C138: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C13C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017C140: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017C144: bne         $t7, $at, L_8017C17C
    if (ctx->r15 != ctx->r1) {
        // 0x8017C148: nop
    
            goto L_8017C17C;
    }
    // 0x8017C148: nop

    // 0x8017C14C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C150: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C154: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C158: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C15C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C160: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017C164: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
    // 0x8017C168: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017C16C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C170: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
    // 0x8017C174: jal         0x800C32CC
    // 0x8017C178: sw          $t8, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r24;
    func_800C32CC(rdram, ctx);
        goto after_8;
    // 0x8017C178: sw          $t8, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r24;
    after_8:
L_8017C17C:
    // 0x8017C17C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C180: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017C184: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x8017C188: bne         $t0, $zero, L_8017C678
    if (ctx->r8 != 0) {
        // 0x8017C18C: nop
    
            goto L_8017C678;
    }
    // 0x8017C18C: nop

    // 0x8017C190: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C194: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017C198: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8017C19C: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017C1A0: beq         $t2, $zero, L_8017C678
    if (ctx->r10 == 0) {
        // 0x8017C1A4: nop
    
            goto L_8017C678;
    }
    // 0x8017C1A4: nop

    // 0x8017C1A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C1AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C1B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C1B4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C1B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C1BC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C1C0: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8017C1C4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8017C1C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C1CC: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x8017C1D0: jal         0x800C32CC
    // 0x8017C1D4: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    func_800C32CC(rdram, ctx);
        goto after_9;
    // 0x8017C1D4: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    after_9:
    // 0x8017C1D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C1DC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C1E0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8017C1E4: b           L_8017C678
    // 0x8017C1E8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
        goto L_8017C678;
    // 0x8017C1E8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_8017C1EC:
    // 0x8017C1EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C1F0: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017C1F4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017C1F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C1FC: lwc1        $f8, 0x8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8017C200: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C204: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017C208: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017C20C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017C210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C214: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C218: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x8017C21C: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017C220: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017C224: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C228: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8017C22C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C230: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017C234: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8017C238: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8017C23C: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8017C240: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C244: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017C248: swc1        $f16, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f16.u32l;
    // 0x8017C24C: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8017C250: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x8017C254: nop

    // 0x8017C258: bc1f        L_8017C270
    if (!c1cs) {
        // 0x8017C25C: nop
    
            goto L_8017C270;
    }
    // 0x8017C25C: nop

    // 0x8017C260: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C264: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C268: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8017C26C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_8017C270:
    // 0x8017C270: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C274: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017C278: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8017C27C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C280: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017C284: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x8017C288: nop

    // 0x8017C28C: bc1t        L_8017C2A8
    if (c1cs) {
        // 0x8017C290: nop
    
            goto L_8017C2A8;
    }
    // 0x8017C290: nop

    // 0x8017C294: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C298: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017C29C: lhu         $t3, 0x2($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X2);
    // 0x8017C2A0: andi        $t8, $t3, 0xB000
    ctx->r24 = ctx->r11 & 0XB000;
    // 0x8017C2A4: beq         $t8, $zero, L_8017C678
    if (ctx->r24 == 0) {
        // 0x8017C2A8: lui         $at, 0x4352
        ctx->r1 = S32(0X4352 << 16);
            goto L_8017C678;
    }
L_8017C2A8:
    // 0x8017C2A8: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8017C2AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C2B0: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8017C2B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C2B8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C2BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C2C0: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017C2C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C2C8: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017C2CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C2D0: swc1        $f10, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f10.u32l;
    // 0x8017C2D4: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017C2D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C2DC: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8017C2E0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C2E4: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8017C2E8: swc1        $f18, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f18.u32l;
    // 0x8017C2EC: b           L_8017C678
    // 0x8017C2F0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_8017C678;
    // 0x8017C2F0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8017C2F4:
    // 0x8017C2F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C2F8: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017C2FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017C300: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C304: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8017C308: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C30C: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017C310: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017C314: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017C318: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C31C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C320: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x8017C324: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017C328: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017C32C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C330: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017C334: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C338: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017C33C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C340: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x8017C344: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8017C348: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C34C: swc1        $f8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f8.u32l;
    // 0x8017C350: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017C354: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8017C358: nop

    // 0x8017C35C: bc1t        L_8017C378
    if (c1cs) {
        // 0x8017C360: nop
    
            goto L_8017C378;
    }
    // 0x8017C360: nop

    // 0x8017C364: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C368: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017C36C: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x8017C370: andi        $t0, $t5, 0xB000
    ctx->r8 = ctx->r13 & 0XB000;
    // 0x8017C374: beq         $t0, $zero, L_8017C678
    if (ctx->r8 == 0) {
        // 0x8017C378: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8017C678;
    }
L_8017C378:
    // 0x8017C378: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C37C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C380: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C384: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C388: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C38C: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017C390: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C394: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017C398: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C39C: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x8017C3A0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017C3A4: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x8017C3A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C3AC: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8017C3B0: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8017C3B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C3B8: bne         $t6, $at, L_8017C3D4
    if (ctx->r14 != ctx->r1) {
        // 0x8017C3BC: nop
    
            goto L_8017C3D4;
    }
    // 0x8017C3BC: nop

    // 0x8017C3C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C3C4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C3C8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8017C3CC: b           L_8017C678
    // 0x8017C3D0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_8017C678;
    // 0x8017C3D0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_8017C3D4:
    // 0x8017C3D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C3D8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C3DC: lw          $t8, 0x1C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X1C);
    // 0x8017C3E0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017C3E4: beq         $t8, $at, L_8017C3F8
    if (ctx->r24 == ctx->r1) {
        // 0x8017C3E8: nop
    
            goto L_8017C3F8;
    }
    // 0x8017C3E8: nop

    // 0x8017C3EC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8017C3F0: b           L_8017C678
    // 0x8017C3F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
        goto L_8017C678;
    // 0x8017C3F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
L_8017C3F8:
    // 0x8017C3F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C3FC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C400: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C404: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
    // 0x8017C408: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C40C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017C410: b           L_8017C678
    // 0x8017C414: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_8017C678;
    // 0x8017C414: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8017C418:
    // 0x8017C418: jal         0x8017C840
    // 0x8017C41C: nop

    func_8017C840_1199D0(rdram, ctx);
        goto after_10;
    // 0x8017C41C: nop

    after_10:
    // 0x8017C420: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C424: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017C428: lhu         $t6, 0x2($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X2);
    // 0x8017C42C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8017C430: beq         $t7, $zero, L_8017C4D8
    if (ctx->r15 == 0) {
        // 0x8017C434: nop
    
            goto L_8017C4D8;
    }
    // 0x8017C434: nop

    // 0x8017C438: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C43C: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x8017C440: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C444: bne         $t4, $at, L_8017C460
    if (ctx->r12 != ctx->r1) {
        // 0x8017C448: nop
    
            goto L_8017C460;
    }
    // 0x8017C448: nop

    // 0x8017C44C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C450: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017C454: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8017C458: b           L_8017C4D8
    // 0x8017C45C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
        goto L_8017C4D8;
    // 0x8017C45C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_8017C460:
    // 0x8017C460: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C464: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C468: lw          $t0, 0x1C($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X1C);
    // 0x8017C46C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017C470: bne         $t0, $at, L_8017C484
    if (ctx->r8 != ctx->r1) {
        // 0x8017C474: nop
    
            goto L_8017C484;
    }
    // 0x8017C474: nop

    // 0x8017C478: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8017C47C: b           L_8017C4D8
    // 0x8017C480: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
        goto L_8017C4D8;
    // 0x8017C480: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
L_8017C484:
    // 0x8017C484: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C488: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C48C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8017C490: bne         $t2, $zero, L_8017C4D8
    if (ctx->r10 != 0) {
        // 0x8017C494: nop
    
            goto L_8017C4D8;
    }
    // 0x8017C494: nop

    // 0x8017C498: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017C49C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C4A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C4A4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C4A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C4AC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C4B0: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x8017C4B4: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8017C4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C4BC: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x8017C4C0: jal         0x800C32CC
    // 0x8017C4C4: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    func_800C32CC(rdram, ctx);
        goto after_11;
    // 0x8017C4C4: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    after_11:
    // 0x8017C4C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C4CC: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017C4D0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8017C4D4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_8017C4D8:
    // 0x8017C4D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C4DC: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017C4E0: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x8017C4E4: andi        $t3, $t9, 0xB000
    ctx->r11 = ctx->r25 & 0XB000;
    // 0x8017C4E8: beq         $t3, $zero, L_8017C678
    if (ctx->r11 == 0) {
        // 0x8017C4EC: nop
    
            goto L_8017C678;
    }
    // 0x8017C4EC: nop

    // 0x8017C4F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C4F4: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C4F8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8017C4FC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8017C500: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C504: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8017C508: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8017C50C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8017C510: beq         $t6, $zero, L_8017C574
    if (ctx->r14 == 0) {
        // 0x8017C514: nop
    
            goto L_8017C574;
    }
    // 0x8017C514: nop

L_8017C518:
    // 0x8017C518: jal         0x800D1E30
    // 0x8017C51C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800D1E30(rdram, ctx);
        goto after_12;
    // 0x8017C51C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x8017C520: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017C524: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C52C: beq         $t7, $at, L_8017C544
    if (ctx->r15 == ctx->r1) {
        // 0x8017C530: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8017C544;
    }
    // 0x8017C530: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017C534: beq         $t7, $at, L_8017C544
    if (ctx->r15 == ctx->r1) {
        // 0x8017C538: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017C544;
    }
    // 0x8017C538: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017C53C: bne         $t7, $at, L_8017C554
    if (ctx->r15 != ctx->r1) {
        // 0x8017C540: nop
    
            goto L_8017C554;
    }
    // 0x8017C540: nop

L_8017C544:
    // 0x8017C544: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C548: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C54C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8017C550: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_8017C554:
    // 0x8017C554: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8017C558: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C55C: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x8017C560: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x8017C564: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8017C568: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x8017C56C: bne         $at, $zero, L_8017C518
    if (ctx->r1 != 0) {
        // 0x8017C570: nop
    
            goto L_8017C518;
    }
    // 0x8017C570: nop

L_8017C574:
    // 0x8017C574: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C578: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C57C: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8017C580: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8017C584: bne         $t1, $at, L_8017C678
    if (ctx->r9 != ctx->r1) {
        // 0x8017C588: nop
    
            goto L_8017C678;
    }
    // 0x8017C588: nop

    // 0x8017C58C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C590: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C594: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C598: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C59C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C5A0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C5A4: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8017C5A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017C5AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C5B0: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
    // 0x8017C5B4: jal         0x800C32CC
    // 0x8017C5B8: sw          $t7, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r15;
    func_800C32CC(rdram, ctx);
        goto after_13;
    // 0x8017C5B8: sw          $t7, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r15;
    after_13:
    // 0x8017C5BC: b           L_8017C678
    // 0x8017C5C0: nop

        goto L_8017C678;
    // 0x8017C5C0: nop

L_8017C5C4:
    // 0x8017C5C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C5C8: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017C5CC: lhu         $t8, 0x2($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X2);
    // 0x8017C5D0: andi        $t5, $t8, 0xB000
    ctx->r13 = ctx->r24 & 0XB000;
    // 0x8017C5D4: beq         $t5, $zero, L_8017C678
    if (ctx->r13 == 0) {
        // 0x8017C5D8: nop
    
            goto L_8017C678;
    }
    // 0x8017C5D8: nop

    // 0x8017C5DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C5E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C5E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C5E8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017C5EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C5F0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017C5F4: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8017C5F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8017C5FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C600: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8017C604: jal         0x800C32CC
    // 0x8017C608: sw          $t3, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r11;
    func_800C32CC(rdram, ctx);
        goto after_14;
    // 0x8017C608: sw          $t3, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r11;
    after_14:
    // 0x8017C60C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C610: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C614: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8017C618: b           L_8017C678
    // 0x8017C61C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_8017C678;
    // 0x8017C61C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8017C620:
    // 0x8017C620: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C624: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017C628: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x8017C62C: andi        $t4, $t7, 0xB000
    ctx->r12 = ctx->r15 & 0XB000;
    // 0x8017C630: beq         $t4, $zero, L_8017C678
    if (ctx->r12 == 0) {
        // 0x8017C634: nop
    
            goto L_8017C678;
    }
    // 0x8017C634: nop

    // 0x8017C638: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017C63C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C640: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C644: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017C648: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C64C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017C650: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8017C654: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017C658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C65C: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x8017C660: jal         0x800C32CC
    // 0x8017C664: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    func_800C32CC(rdram, ctx);
        goto after_15;
    // 0x8017C664: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    after_15:
    // 0x8017C668: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C66C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C670: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8017C674: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
L_8017C678:
    // 0x8017C678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C67C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017C680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017C684: jr          $ra
    // 0x8017C688: nop

    return;
    // 0x8017C688: nop

;}
RECOMP_FUNC void func_8017C68C_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C68C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C690: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C698: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C69C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017C6A0: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8017C6A4: bne         $at, $zero, L_8017C6B0
    if (ctx->r1 != 0) {
        // 0x8017C6A8: nop
    
            goto L_8017C6B0;
    }
    // 0x8017C6A8: nop

    // 0x8017C6AC: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
L_8017C6B0:
    // 0x8017C6B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C6B4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C6B8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8017C6BC: beq         $t9, $zero, L_8017C6CC
    if (ctx->r25 == 0) {
        // 0x8017C6C0: nop
    
            goto L_8017C6CC;
    }
    // 0x8017C6C0: nop

    // 0x8017C6C4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017C6C8: sw          $t0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r8;
L_8017C6CC:
    // 0x8017C6CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C6D0: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017C6D4: lb          $t2, 0x6($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X6);
    // 0x8017C6D8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8017C6DC: jal         0x800E4D10
    // 0x8017C6E0: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    fabs_recomp(rdram, ctx);
        goto after_0;
    // 0x8017C6E0: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    after_0:
    // 0x8017C6E4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8017C6E8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8017C6EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C6F0: nop

    // 0x8017C6F4: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8017C6F8: nop

    // 0x8017C6FC: bc1f        L_8017C710
    if (!c1cs) {
        // 0x8017C700: nop
    
            goto L_8017C710;
    }
    // 0x8017C700: nop

    // 0x8017C704: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C708: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C70C: sw          $zero, 0x10($t3)
    MEM_W(0X10, ctx->r11) = 0;
L_8017C710:
    // 0x8017C710: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C714: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C718: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8017C71C: bne         $t5, $zero, L_8017C73C
    if (ctx->r13 != 0) {
        // 0x8017C720: nop
    
            goto L_8017C73C;
    }
    // 0x8017C720: nop

    // 0x8017C724: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C728: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017C72C: lb          $t6, 0x6($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X6);
    // 0x8017C730: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8017C734: beq         $at, $zero, L_8017C754
    if (ctx->r1 == 0) {
        // 0x8017C738: nop
    
            goto L_8017C754;
    }
    // 0x8017C738: nop

L_8017C73C:
    // 0x8017C73C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C740: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017C744: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017C748: andi        $t8, $t0, 0x100
    ctx->r24 = ctx->r8 & 0X100;
    // 0x8017C74C: beq         $t8, $zero, L_8017C7A8
    if (ctx->r24 == 0) {
        // 0x8017C750: nop
    
            goto L_8017C7A8;
    }
    // 0x8017C750: nop

L_8017C754:
    // 0x8017C754: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C758: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C75C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017C760: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x8017C764: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C768: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x8017C76C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C770: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8017C774: sw          $t4, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r12;
    // 0x8017C778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C77C: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
    // 0x8017C780: sltiu       $at, $t4, 0x4
    ctx->r1 = ctx->r12 < 0X4 ? 1 : 0;
    // 0x8017C784: bne         $at, $zero, L_8017C798
    if (ctx->r1 != 0) {
        // 0x8017C788: nop
    
            goto L_8017C798;
    }
    // 0x8017C788: nop

    // 0x8017C78C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017C790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C794: sw          $t5, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r13;
L_8017C798:
    // 0x8017C798: jal         0x800C8544
    // 0x8017C79C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017C79C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x8017C7A0: b           L_8017C830
    // 0x8017C7A4: nop

        goto L_8017C830;
    // 0x8017C7A4: nop

L_8017C7A8:
    // 0x8017C7A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C7AC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017C7B0: lw          $t6, 0x10($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X10);
    // 0x8017C7B4: bne         $t6, $zero, L_8017C7D4
    if (ctx->r14 != 0) {
        // 0x8017C7B8: nop
    
            goto L_8017C7D4;
    }
    // 0x8017C7B8: nop

    // 0x8017C7BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C7C0: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017C7C4: lb          $t0, 0x6($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X6);
    // 0x8017C7C8: slti        $at, $t0, -0xF
    ctx->r1 = SIGNED(ctx->r8) < -0XF ? 1 : 0;
    // 0x8017C7CC: bne         $at, $zero, L_8017C7EC
    if (ctx->r1 != 0) {
        // 0x8017C7D0: nop
    
            goto L_8017C7EC;
    }
    // 0x8017C7D0: nop

L_8017C7D4:
    // 0x8017C7D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C7D8: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017C7DC: lhu         $t1, 0x2($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X2);
    // 0x8017C7E0: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x8017C7E4: beq         $t2, $zero, L_8017C830
    if (ctx->r10 == 0) {
        // 0x8017C7E8: nop
    
            goto L_8017C830;
    }
    // 0x8017C7E8: nop

L_8017C7EC:
    // 0x8017C7EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C7F0: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C7F4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8017C7F8: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8017C7FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C800: lw          $t5, -0x2E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E44);
    // 0x8017C804: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C808: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8017C80C: sw          $t7, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r15;
    // 0x8017C810: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C814: bne         $t7, $zero, L_8017C828
    if (ctx->r15 != 0) {
        // 0x8017C818: sw          $zero, -0x2E38($at)
        MEM_W(-0X2E38, ctx->r1) = 0;
            goto L_8017C828;
    }
    // 0x8017C818: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
    // 0x8017C81C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8017C820: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C824: sw          $t6, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r14;
L_8017C828:
    // 0x8017C828: jal         0x800C8544
    // 0x8017C82C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017C82C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
L_8017C830:
    // 0x8017C830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C838: jr          $ra
    // 0x8017C83C: nop

    return;
    // 0x8017C83C: nop

;}
RECOMP_FUNC void func_8017C840_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C844: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C84C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C850: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8017C854: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8017C858: bne         $at, $zero, L_8017C864
    if (ctx->r1 != 0) {
        // 0x8017C85C: nop
    
            goto L_8017C864;
    }
    // 0x8017C85C: nop

    // 0x8017C860: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
L_8017C864:
    // 0x8017C864: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C868: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C86C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8017C870: beq         $t9, $zero, L_8017C880
    if (ctx->r25 == 0) {
        // 0x8017C874: nop
    
            goto L_8017C880;
    }
    // 0x8017C874: nop

    // 0x8017C878: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017C87C: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
L_8017C880:
    // 0x8017C880: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C884: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017C888: lb          $t2, 0x6($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X6);
    // 0x8017C88C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8017C890: jal         0x800E4D10
    // 0x8017C894: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    fabs_recomp(rdram, ctx);
        goto after_0;
    // 0x8017C894: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    after_0:
    // 0x8017C898: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8017C89C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8017C8A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C8A4: nop

    // 0x8017C8A8: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8017C8AC: nop

    // 0x8017C8B0: bc1f        L_8017C8C4
    if (!c1cs) {
        // 0x8017C8B4: nop
    
            goto L_8017C8C4;
    }
    // 0x8017C8B4: nop

    // 0x8017C8B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C8BC: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C8C0: sw          $zero, 0x10($t3)
    MEM_W(0X10, ctx->r11) = 0;
L_8017C8C4:
    // 0x8017C8C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C8C8: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C8CC: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8017C8D0: bne         $t5, $zero, L_8017C8F0
    if (ctx->r13 != 0) {
        // 0x8017C8D4: nop
    
            goto L_8017C8F0;
    }
    // 0x8017C8D4: nop

    // 0x8017C8D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C8DC: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017C8E0: lb          $t6, 0x6($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X6);
    // 0x8017C8E4: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8017C8E8: beq         $at, $zero, L_8017C908
    if (ctx->r1 == 0) {
        // 0x8017C8EC: nop
    
            goto L_8017C908;
    }
    // 0x8017C8EC: nop

L_8017C8F0:
    // 0x8017C8F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C8F4: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017C8F8: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017C8FC: andi        $t8, $t0, 0x100
    ctx->r24 = ctx->r8 & 0X100;
    // 0x8017C900: beq         $t8, $zero, L_8017C960
    if (ctx->r24 == 0) {
        // 0x8017C904: nop
    
            goto L_8017C960;
    }
    // 0x8017C904: nop

L_8017C908:
    // 0x8017C908: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C90C: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C910: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017C914: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    // 0x8017C918: jal         0x800C8544
    // 0x8017C91C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017C91C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x8017C920: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C924: lw          $t5, -0x2E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E44);
    // 0x8017C928: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C92C: lw          $t3, -0x2E38($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E38);
    // 0x8017C930: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017C934: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8017C938: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8017C93C: lw          $t6, -0x2080($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2080);
    // 0x8017C940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C944: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8017C948: sw          $t4, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = ctx->r12;
    // 0x8017C94C: sltu        $at, $t6, $t4
    ctx->r1 = ctx->r14 < ctx->r12 ? 1 : 0;
    // 0x8017C950: beq         $at, $zero, L_8017CA04
    if (ctx->r1 == 0) {
        // 0x8017C954: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017CA04;
    }
    // 0x8017C954: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C958: b           L_8017CA04
    // 0x8017C95C: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
        goto L_8017CA04;
    // 0x8017C95C: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
L_8017C960:
    // 0x8017C960: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C964: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017C968: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8017C96C: bne         $t0, $zero, L_8017C98C
    if (ctx->r8 != 0) {
        // 0x8017C970: nop
    
            goto L_8017C98C;
    }
    // 0x8017C970: nop

    // 0x8017C974: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C978: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017C97C: lb          $t1, 0x6($t8)
    ctx->r9 = MEM_B(ctx->r24, 0X6);
    // 0x8017C980: slti        $at, $t1, -0xF
    ctx->r1 = SIGNED(ctx->r9) < -0XF ? 1 : 0;
    // 0x8017C984: bne         $at, $zero, L_8017C9A4
    if (ctx->r1 != 0) {
        // 0x8017C988: nop
    
            goto L_8017C9A4;
    }
    // 0x8017C988: nop

L_8017C98C:
    // 0x8017C98C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C990: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017C994: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8017C998: andi        $t5, $t3, 0x200
    ctx->r13 = ctx->r11 & 0X200;
    // 0x8017C99C: beq         $t5, $zero, L_8017CA04
    if (ctx->r13 == 0) {
        // 0x8017C9A0: nop
    
            goto L_8017CA04;
    }
    // 0x8017C9A0: nop

L_8017C9A4:
    // 0x8017C9A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C9A8: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C9AC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8017C9B0: sw          $t7, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r15;
    // 0x8017C9B4: jal         0x800C8544
    // 0x8017C9B8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017C9B8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
    // 0x8017C9BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C9C0: lw          $t6, -0x2E38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E38);
    // 0x8017C9C4: bne         $t6, $zero, L_8017C9F0
    if (ctx->r14 != 0) {
        // 0x8017C9C8: nop
    
            goto L_8017C9F0;
    }
    // 0x8017C9C8: nop

    // 0x8017C9CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C9D0: lw          $t9, -0x2E44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E44);
    // 0x8017C9D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8017C9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C9DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017C9E0: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8017C9E4: lw          $t8, -0x2080($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2080);
    // 0x8017C9E8: b           L_8017CA04
    // 0x8017C9EC: sw          $t8, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = ctx->r24;
        goto L_8017CA04;
    // 0x8017C9EC: sw          $t8, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = ctx->r24;
L_8017C9F0:
    // 0x8017C9F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C9F4: lw          $t1, -0x2E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E38);
    // 0x8017C9F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C9FC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8017CA00: sw          $t2, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = ctx->r10;
L_8017CA04:
    // 0x8017CA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CA0C: jr          $ra
    // 0x8017CA10: nop

    return;
    // 0x8017CA10: nop

;}
RECOMP_FUNC void func_8017CA14_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CA18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CA20: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CA24: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017CA28: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8017CA2C: bne         $at, $zero, L_8017CA38
    if (ctx->r1 != 0) {
        // 0x8017CA30: nop
    
            goto L_8017CA38;
    }
    // 0x8017CA30: nop

    // 0x8017CA34: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
L_8017CA38:
    // 0x8017CA38: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CA3C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017CA40: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8017CA44: beq         $t9, $zero, L_8017CA54
    if (ctx->r25 == 0) {
        // 0x8017CA48: nop
    
            goto L_8017CA54;
    }
    // 0x8017CA48: nop

    // 0x8017CA4C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017CA50: sw          $t0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r8;
L_8017CA54:
    // 0x8017CA54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CA58: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017CA5C: lb          $t2, 0x6($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X6);
    // 0x8017CA60: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8017CA64: jal         0x800E4D10
    // 0x8017CA68: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    fabs_recomp(rdram, ctx);
        goto after_0;
    // 0x8017CA68: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    after_0:
    // 0x8017CA6C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8017CA70: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8017CA74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CA78: nop

    // 0x8017CA7C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8017CA80: nop

    // 0x8017CA84: bc1f        L_8017CA98
    if (!c1cs) {
        // 0x8017CA88: nop
    
            goto L_8017CA98;
    }
    // 0x8017CA88: nop

    // 0x8017CA8C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CA90: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017CA94: sw          $zero, 0x10($t3)
    MEM_W(0X10, ctx->r11) = 0;
L_8017CA98:
    // 0x8017CA98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CA9C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017CAA0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8017CAA4: bne         $t5, $zero, L_8017CAC4
    if (ctx->r13 != 0) {
        // 0x8017CAA8: nop
    
            goto L_8017CAC4;
    }
    // 0x8017CAA8: nop

    // 0x8017CAAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CAB0: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017CAB4: lb          $t6, 0x6($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X6);
    // 0x8017CAB8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8017CABC: beq         $at, $zero, L_8017CADC
    if (ctx->r1 == 0) {
        // 0x8017CAC0: nop
    
            goto L_8017CADC;
    }
    // 0x8017CAC0: nop

L_8017CAC4:
    // 0x8017CAC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CAC8: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017CACC: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8017CAD0: andi        $t8, $t0, 0x100
    ctx->r24 = ctx->r8 & 0X100;
    // 0x8017CAD4: beq         $t8, $zero, L_8017CBC0
    if (ctx->r24 == 0) {
        // 0x8017CAD8: nop
    
            goto L_8017CBC0;
    }
    // 0x8017CAD8: nop

L_8017CADC:
    // 0x8017CADC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CAE0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017CAE4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017CAE8: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x8017CAEC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CAF0: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x8017CAF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CAF8: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
    // 0x8017CAFC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8017CB00: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8017CB04: beq         $at, $zero, L_8017CBB0
    if (ctx->r1 == 0) {
        // 0x8017CB08: nop
    
            goto L_8017CBB0;
    }
    // 0x8017CB08: nop

    // 0x8017CB0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017CB10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB14: addu        $at, $at, $t4
    gpr jr_addend_8017CB1C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017CB18: lw          $t4, -0x1F1C($at)
    ctx->r12 = ADD32(ctx->r1, -0X1F1C);
    // 0x8017CB1C: jr          $t4
    // 0x8017CB20: nop

    switch (jr_addend_8017CB1C >> 2) {
        case 0: goto L_8017CB24; break;
        case 1: goto L_8017CB40; break;
        case 2: goto L_8017CB5C; break;
        case 3: goto L_8017CB78; break;
        case 4: goto L_8017CB94; break;
        default: switch_error(__func__, 0x8017CB1C, 0x8017E0E4);
    }
    // 0x8017CB20: nop

L_8017CB24:
    // 0x8017CB24: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8017CB28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB2C: sw          $t5, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r13;
    // 0x8017CB30: jal         0x800C8544
    // 0x8017CB34: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017CB34: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x8017CB38: b           L_8017CCE4
    // 0x8017CB3C: nop

        goto L_8017CCE4;
    // 0x8017CB3C: nop

L_8017CB40:
    // 0x8017CB40: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8017CB44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB48: sw          $t7, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r15;
    // 0x8017CB4C: jal         0x800C8544
    // 0x8017CB50: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017CB50: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
    // 0x8017CB54: b           L_8017CCE4
    // 0x8017CB58: nop

        goto L_8017CCE4;
    // 0x8017CB58: nop

L_8017CB5C:
    // 0x8017CB5C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017CB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB64: sw          $t6, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r14;
    // 0x8017CB68: jal         0x800C8544
    // 0x8017CB6C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017CB6C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x8017CB70: b           L_8017CCE4
    // 0x8017CB74: nop

        goto L_8017CCE4;
    // 0x8017CB74: nop

L_8017CB78:
    // 0x8017CB78: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8017CB7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB80: sw          $t9, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r25;
    // 0x8017CB84: jal         0x800C8544
    // 0x8017CB88: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017CB88: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
    // 0x8017CB8C: b           L_8017CCE4
    // 0x8017CB90: nop

        goto L_8017CCE4;
    // 0x8017CB90: nop

L_8017CB94:
    // 0x8017CB94: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8017CB98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB9C: sw          $t0, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r8;
    // 0x8017CBA0: jal         0x800C8544
    // 0x8017CBA4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017CBA4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_5:
    // 0x8017CBA8: b           L_8017CCE4
    // 0x8017CBAC: nop

        goto L_8017CCE4;
    // 0x8017CBAC: nop

L_8017CBB0:
    // 0x8017CBB0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8017CBB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CBB8: b           L_8017CCE4
    // 0x8017CBBC: sw          $t8, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r24;
        goto L_8017CCE4;
    // 0x8017CBBC: sw          $t8, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r24;
L_8017CBC0:
    // 0x8017CBC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CBC4: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017CBC8: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8017CBCC: bne         $t2, $zero, L_8017CBEC
    if (ctx->r10 != 0) {
        // 0x8017CBD0: nop
    
            goto L_8017CBEC;
    }
    // 0x8017CBD0: nop

    // 0x8017CBD4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CBD8: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x8017CBDC: lb          $t4, 0x6($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X6);
    // 0x8017CBE0: slti        $at, $t4, -0xF
    ctx->r1 = SIGNED(ctx->r12) < -0XF ? 1 : 0;
    // 0x8017CBE4: bne         $at, $zero, L_8017CC04
    if (ctx->r1 != 0) {
        // 0x8017CBE8: nop
    
            goto L_8017CC04;
    }
    // 0x8017CBE8: nop

L_8017CBEC:
    // 0x8017CBEC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CBF0: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8017CBF4: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8017CBF8: andi        $t6, $t7, 0x200
    ctx->r14 = ctx->r15 & 0X200;
    // 0x8017CBFC: beq         $t6, $zero, L_8017CCE4
    if (ctx->r14 == 0) {
        // 0x8017CC00: nop
    
            goto L_8017CCE4;
    }
    // 0x8017CC00: nop

L_8017CC04:
    // 0x8017CC04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CC08: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017CC0C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8017CC10: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x8017CC14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CC18: lw          $t8, -0x2E44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E44);
    // 0x8017CC1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CC20: sw          $zero, -0x2E38($at)
    MEM_W(-0X2E38, ctx->r1) = 0;
    // 0x8017CC24: addiu       $t1, $t8, -0x2
    ctx->r9 = ADD32(ctx->r24, -0X2);
    // 0x8017CC28: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x8017CC2C: beq         $at, $zero, L_8017CCD8
    if (ctx->r1 == 0) {
        // 0x8017CC30: nop
    
            goto L_8017CCD8;
    }
    // 0x8017CC30: nop

    // 0x8017CC34: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017CC38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CC3C: addu        $at, $at, $t1
    gpr jr_addend_8017CC44 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017CC40: lw          $t1, -0x1F08($at)
    ctx->r9 = ADD32(ctx->r1, -0X1F08);
    // 0x8017CC44: jr          $t1
    // 0x8017CC48: nop

    switch (jr_addend_8017CC44 >> 2) {
        case 0: goto L_8017CCBC; break;
        case 1: goto L_8017CCA0; break;
        case 2: goto L_8017CC84; break;
        case 3: goto L_8017CC68; break;
        case 4: goto L_8017CC4C; break;
        default: switch_error(__func__, 0x8017CC44, 0x8017E0F8);
    }
    // 0x8017CC48: nop

L_8017CC4C:
    // 0x8017CC4C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8017CC50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CC54: sw          $t2, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r10;
    // 0x8017CC58: jal         0x800C8544
    // 0x8017CC5C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x8017CC5C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_6:
    // 0x8017CC60: b           L_8017CCE4
    // 0x8017CC64: nop

        goto L_8017CCE4;
    // 0x8017CC64: nop

L_8017CC68:
    // 0x8017CC68: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8017CC6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CC70: sw          $t3, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r11;
    // 0x8017CC74: jal         0x800C8544
    // 0x8017CC78: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_7;
    // 0x8017CC78: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_7:
    // 0x8017CC7C: b           L_8017CCE4
    // 0x8017CC80: nop

        goto L_8017CCE4;
    // 0x8017CC80: nop

L_8017CC84:
    // 0x8017CC84: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8017CC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CC8C: sw          $t4, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r12;
    // 0x8017CC90: jal         0x800C8544
    // 0x8017CC94: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_8;
    // 0x8017CC94: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_8:
    // 0x8017CC98: b           L_8017CCE4
    // 0x8017CC9C: nop

        goto L_8017CCE4;
    // 0x8017CC9C: nop

L_8017CCA0:
    // 0x8017CCA0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8017CCA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CCA8: sw          $t5, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r13;
    // 0x8017CCAC: jal         0x800C8544
    // 0x8017CCB0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_9;
    // 0x8017CCB0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_9:
    // 0x8017CCB4: b           L_8017CCE4
    // 0x8017CCB8: nop

        goto L_8017CCE4;
    // 0x8017CCB8: nop

L_8017CCBC:
    // 0x8017CCBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017CCC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CCC4: sw          $t7, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r15;
    // 0x8017CCC8: jal         0x800C8544
    // 0x8017CCCC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_10;
    // 0x8017CCCC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_10:
    // 0x8017CCD0: b           L_8017CCE4
    // 0x8017CCD4: nop

        goto L_8017CCE4;
    // 0x8017CCD4: nop

L_8017CCD8:
    // 0x8017CCD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017CCDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CCE0: sw          $t6, -0x2E44($at)
    MEM_W(-0X2E44, ctx->r1) = ctx->r14;
L_8017CCE4:
    // 0x8017CCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CCE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CCEC: jr          $ra
    // 0x8017CCF0: nop

    return;
    // 0x8017CCF0: nop

;}
RECOMP_FUNC void func_8017CCF4_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CCF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017CCF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017CCFC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CD00: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CD04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8017CD08: addiu       $a1, $a1, -0x2040
    ctx->r5 = ADD32(ctx->r5, -0X2040);
    // 0x8017CD0C: jal         0x800D87E4
    // 0x8017CD10: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017CD10: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x8017CD14: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x8017CD18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017CD1C: jal         0x8017CEEC
    // 0x8017CD20: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_1;
    // 0x8017CD20: nop

    after_1:
    // 0x8017CD24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CD28: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CD2C: addiu       $a1, $a1, -0x203C
    ctx->r5 = ADD32(ctx->r5, -0X203C);
    // 0x8017CD30: jal         0x800D87E4
    // 0x8017CD34: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017CD34: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x8017CD38: lui         $at, 0xC1A8
    ctx->r1 = S32(0XC1A8 << 16);
    // 0x8017CD3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017CD40: jal         0x8017CEEC
    // 0x8017CD44: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_3;
    // 0x8017CD44: nop

    after_3:
    // 0x8017CD48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CD4C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CD50: addiu       $a1, $a1, -0x2038
    ctx->r5 = ADD32(ctx->r5, -0X2038);
    // 0x8017CD54: jal         0x800D87E4
    // 0x8017CD58: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8017CD58: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
    // 0x8017CD5C: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x8017CD60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017CD64: jal         0x8017CEEC
    // 0x8017CD68: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_5;
    // 0x8017CD68: nop

    after_5:
    // 0x8017CD6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CD70: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CD74: addiu       $a1, $a1, -0x2034
    ctx->r5 = ADD32(ctx->r5, -0X2034);
    // 0x8017CD78: jal         0x800D87E4
    // 0x8017CD7C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8017CD7C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_6:
    // 0x8017CD80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017CD84: jal         0x8017CEEC
    // 0x8017CD88: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_7;
    // 0x8017CD88: nop

    after_7:
    // 0x8017CD8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CD90: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CD94: addiu       $a1, $a1, -0x2030
    ctx->r5 = ADD32(ctx->r5, -0X2030);
    // 0x8017CD98: jal         0x800D87E4
    // 0x8017CD9C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8017CD9C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_8:
    // 0x8017CDA0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8017CDA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017CDA8: jal         0x8017CEEC
    // 0x8017CDAC: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_9;
    // 0x8017CDAC: nop

    after_9:
    // 0x8017CDB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CDB4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017CDB8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8017CDBC: lw          $a2, -0x2E44($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2E44);
    // 0x8017CDC0: addiu       $a1, $a1, -0x202C
    ctx->r5 = ADD32(ctx->r5, -0X202C);
    // 0x8017CDC4: jal         0x800D87E4
    // 0x8017CDC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x8017CDC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_10:
    // 0x8017CDCC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8017CDD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017CDD4: jal         0x8017CEEC
    // 0x8017CDD8: nop

    func_8017CEEC_1199D0(rdram, ctx);
        goto after_11;
    // 0x8017CDD8: nop

    after_11:
    // 0x8017CDDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CDE0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CDE4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8017CDE8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017CDEC: beq         $s0, $at, L_8017CE0C
    if (ctx->r16 == ctx->r1) {
        // 0x8017CDF0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8017CE0C;
    }
    // 0x8017CDF0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8017CDF4: beq         $s0, $at, L_8017CE74
    if (ctx->r16 == ctx->r1) {
        // 0x8017CDF8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8017CE74;
    }
    // 0x8017CDF8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8017CDFC: beq         $s0, $at, L_8017CE74
    if (ctx->r16 == ctx->r1) {
        // 0x8017CE00: nop
    
            goto L_8017CE74;
    }
    // 0x8017CE00: nop

    // 0x8017CE04: b           L_8017CED8
    // 0x8017CE08: nop

        goto L_8017CED8;
    // 0x8017CE08: nop

L_8017CE0C:
    // 0x8017CE0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CE10: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CE14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017CE18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CE1C: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8017CE20: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8017CE24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8017CE28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017CE2C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8017CE30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CE34: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CE38: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x8017CE3C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CE40: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017CE44: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017CE48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CE4C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017CE50: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8017CE54: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8017CE58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8017CE5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017CE60: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017CE64: jal         0x8017B0C0
    // 0x8017CE68: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    func_8017B0C0_1199D0(rdram, ctx);
        goto after_12;
    // 0x8017CE68: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x8017CE6C: b           L_8017CED8
    // 0x8017CE70: nop

        goto L_8017CED8;
    // 0x8017CE70: nop

L_8017CE74:
    // 0x8017CE74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CE78: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017CE7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017CE80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CE84: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8017CE88: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8017CE8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8017CE90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017CE94: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8017CE98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CE9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CEA0: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x8017CEA4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017CEA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017CEAC: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017CEB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CEB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017CEB8: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8017CEBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017CEC0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8017CEC4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8017CEC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017CECC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017CED0: jal         0x8017B0C0
    // 0x8017CED4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    func_8017B0C0_1199D0(rdram, ctx);
        goto after_13;
    // 0x8017CED4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_13:
L_8017CED8:
    // 0x8017CED8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CEDC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8017CEE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017CEE4: jr          $ra
    // 0x8017CEE8: nop

    return;
    // 0x8017CEE8: nop

;}
RECOMP_FUNC void func_8017CEEC_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CEEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017CEF0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CEF4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8017CEF8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8017CEFC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CF00: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8017CF04: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017CF08: beq         $t7, $at, L_8017D150
    if (ctx->r15 == ctx->r1) {
        // 0x8017CF0C: nop
    
            goto L_8017D150;
    }
    // 0x8017CF0C: nop

    // 0x8017CF10: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017CF14: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8017CF18: beq         $at, $zero, L_8017D038
    if (ctx->r1 == 0) {
        // 0x8017CF1C: nop
    
            goto L_8017D038;
    }
    // 0x8017CF1C: nop

    // 0x8017CF20: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017CF24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CF28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017CF2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CF30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CF34: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017CF38: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017CF3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CF40: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017CF44: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017CF48: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017CF4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CF50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CF54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CF58: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017CF5C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017CF60: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017CF64: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017CF68: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017CF6C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017CF70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CF74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CF78: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017CF7C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017CF80: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017CF84: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017CF88: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017CF8C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x8017CF90: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017CF94: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017CF98: jal         0x801716C8
    // 0x8017CF9C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017CF9C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8017CFA0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017CFA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CFA8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017CFAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CFB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CFB4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017CFB8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017CFBC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CFC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CFC4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017CFC8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017CFCC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CFD0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017CFD4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017CFD8: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8017CFDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CFE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CFE4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017CFE8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017CFEC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017CFF0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CFF4: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017CFF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CFFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D000: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8017D004: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D008: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8017D00C: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017D010: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D014: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017D018: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x8017D01C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // 0x8017D020: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x8017D024: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017D028: jal         0x801716C8
    // 0x8017D02C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017D02C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8017D030: b           L_8017D390
    // 0x8017D034: nop

        goto L_8017D390;
    // 0x8017D034: nop

L_8017D038:
    // 0x8017D038: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D03C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D040: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D044: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D048: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D04C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017D050: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017D054: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D058: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017D05C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017D060: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8017D064: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D06C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D070: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017D074: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017D078: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017D07C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8017D080: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017D084: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D088: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D08C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D090: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017D094: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017D098: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D09C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017D0A0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8017D0A4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8017D0A8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017D0AC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8017D0B0: jal         0x801716C8
    // 0x8017D0B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017D0B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8017D0B8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017D0BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D0C0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D0C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D0C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D0CC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017D0D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D0D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D0D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D0DC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017D0E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017D0E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D0E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017D0EC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017D0F0: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8017D0F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D0F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D0FC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017D100: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017D104: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017D108: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8017D10C: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017D110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D114: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D118: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8017D11C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D120: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8017D124: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8017D128: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D12C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017D130: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8017D134: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8017D138: addiu       $a3, $zero, 0x21
    ctx->r7 = ADD32(0, 0X21);
    // 0x8017D13C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017D140: jal         0x801716C8
    // 0x8017D144: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_3;
    // 0x8017D144: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8017D148: b           L_8017D390
    // 0x8017D14C: nop

        goto L_8017D390;
    // 0x8017D14C: nop

L_8017D150:
    // 0x8017D150: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D154: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017D158: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017D15C: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x8017D160: beq         $at, $zero, L_8017D280
    if (ctx->r1 == 0) {
        // 0x8017D164: nop
    
            goto L_8017D280;
    }
    // 0x8017D164: nop

    // 0x8017D168: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D16C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D170: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017D174: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D178: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D17C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D180: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017D184: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D188: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D18C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017D190: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017D194: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D19C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D1A0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017D1A4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017D1A8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017D1AC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8017D1B0: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017D1B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D1B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D1BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D1C0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017D1C4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8017D1C8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D1CC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017D1D0: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017D1D4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8017D1D8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017D1DC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8017D1E0: jal         0x801716C8
    // 0x8017D1E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_4;
    // 0x8017D1E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8017D1E8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017D1EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D1F0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D1F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D1F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D1FC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017D200: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017D204: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D208: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D20C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017D210: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017D214: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D218: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017D21C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017D220: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017D224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D228: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D22C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017D230: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017D234: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017D238: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8017D23C: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017D240: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D244: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D248: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8017D24C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D250: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8017D254: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8017D258: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D25C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017D260: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x8017D264: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // 0x8017D268: addiu       $a3, $zero, 0x21
    ctx->r7 = ADD32(0, 0X21);
    // 0x8017D26C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017D270: jal         0x801716C8
    // 0x8017D274: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_5;
    // 0x8017D274: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8017D278: b           L_8017D390
    // 0x8017D27C: nop

        goto L_8017D390;
    // 0x8017D27C: nop

L_8017D280:
    // 0x8017D280: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D284: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D288: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D28C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D294: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D298: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017D29C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D2A0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017D2A4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017D2A8: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017D2AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D2B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D2B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D2B8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017D2BC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017D2C0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017D2C4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017D2C8: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017D2CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D2D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D2D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D2D8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017D2DC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017D2E0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D2E4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017D2E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8017D2EC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x8017D2F0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8017D2F4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8017D2F8: jal         0x801716C8
    // 0x8017D2FC: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_6;
    // 0x8017D2FC: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8017D300: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017D304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D308: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017D30C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D310: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D314: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017D318: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017D31C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D320: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D324: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017D328: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017D32C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D330: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017D334: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017D338: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8017D33C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D340: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D344: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017D348: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017D34C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017D350: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017D354: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017D358: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D35C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D360: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8017D364: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D368: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8017D36C: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017D370: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017D374: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017D378: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x8017D37C: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8017D380: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8017D384: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8017D388: jal         0x801716C8
    // 0x8017D38C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_7;
    // 0x8017D38C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_7:
L_8017D390:
    // 0x8017D390: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017D394: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017D398: jr          $ra
    // 0x8017D39C: nop

    return;
    // 0x8017D39C: nop

;}
RECOMP_FUNC void func_8017D3A0_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D3A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017D3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D3A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017D3AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017D3B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8017D3B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8017D3B8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D3BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D3C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D3C4: jal         0x800C7A9C
    // 0x8017D3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C7A9C(rdram, ctx);
        goto after_0;
    // 0x8017D3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8017D3CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017D3D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D3D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8017D3D8: jal         0x800C7A74
    // 0x8017D3DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800C7A74(rdram, ctx);
        goto after_1;
    // 0x8017D3DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_1:
    // 0x8017D3E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D3E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D3E8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D3EC: jal         0x800C767C
    // 0x8017D3F0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_2;
    // 0x8017D3F0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_2:
    // 0x8017D3F4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8017D3F8: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8017D3FC: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x8017D400: jal         0x800C7A9C
    // 0x8017D404: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
    func_800C7A9C(rdram, ctx);
        goto after_3;
    // 0x8017D404: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
    after_3:
    // 0x8017D408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017D40C: jal         0x800C7A74
    // 0x8017D410: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C7A74(rdram, ctx);
        goto after_4;
    // 0x8017D410: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8017D414: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D418: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D41C: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D420: jal         0x800C767C
    // 0x8017D424: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_5;
    // 0x8017D424: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_5:
    // 0x8017D428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017D430: jr          $ra
    // 0x8017D434: nop

    return;
    // 0x8017D434: nop

;}
RECOMP_FUNC void func_8017D438_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D43C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D440: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D444: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D448: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017D44C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8017D450: bne         $at, $zero, L_8017D464
    if (ctx->r1 != 0) {
        // 0x8017D454: nop
    
            goto L_8017D464;
    }
    // 0x8017D454: nop

    // 0x8017D458: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8017D45C: b           L_8017D474
    // 0x8017D460: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
        goto L_8017D474;
    // 0x8017D460: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
L_8017D464:
    // 0x8017D464: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D468: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D46C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D470: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8017D474:
    // 0x8017D474: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D478: jal         0x800D54C8
    // 0x8017D47C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x8017D47C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x8017D480: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017D484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D488: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D48C: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017D490: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017D494: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017D498: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D49C: addiu       $a0, $a0, -0x1E40
    ctx->r4 = ADD32(ctx->r4, -0X1E40);
    // 0x8017D4A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D4A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D4A8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8017D4AC: jal         0x800C6C6C
    // 0x8017D4B0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017D4B0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x8017D4B4: jal         0x800C6D5C
    // 0x8017D4B8: nop

    func_800C6D5C(rdram, ctx);
        goto after_2;
    // 0x8017D4B8: nop

    after_2:
    // 0x8017D4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D4C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D4C4: jr          $ra
    // 0x8017D4C8: nop

    return;
    // 0x8017D4C8: nop

;}
RECOMP_FUNC void func_8017D4CC_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D4CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D4D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D4D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D4D8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D4DC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017D4E0: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8017D4E4: beq         $at, $zero, L_8017D7D0
    if (ctx->r1 == 0) {
        // 0x8017D4E8: nop
    
            goto L_8017D7D0;
    }
    // 0x8017D4E8: nop

    // 0x8017D4EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D4F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D4F4: addu        $at, $at, $t7
    gpr jr_addend_8017D4FC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017D4F8: lw          $t7, -0x1EF4($at)
    ctx->r15 = ADD32(ctx->r1, -0X1EF4);
    // 0x8017D4FC: jr          $t7
    // 0x8017D500: nop

    switch (jr_addend_8017D4FC >> 2) {
        case 0: goto L_8017D7D0; break;
        case 1: goto L_8017D7D0; break;
        case 2: goto L_8017D504; break;
        case 3: goto L_8017D584; break;
        case 4: goto L_8017D654; break;
        case 5: goto L_8017D654; break;
        case 6: goto L_8017D664; break;
        case 7: goto L_8017D704; break;
        case 8: goto L_8017D704; break;
        default: switch_error(__func__, 0x8017D4FC, 0x8017E10C);
    }
    // 0x8017D500: nop

L_8017D504:
    // 0x8017D504: jal         0x800C7AD0
    // 0x8017D508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017D508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017D50C: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8017D510: jal         0x800C7A60
    // 0x8017D514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017D514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017D518: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017D51C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D520: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D524: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D528: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D52C: jal         0x800C7A88
    // 0x8017D530: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017D530: nop

    after_2:
    // 0x8017D534: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D538: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D53C: addiu       $a1, $a1, -0x2028
    ctx->r5 = ADD32(ctx->r5, -0X2028);
    // 0x8017D540: jal         0x800D87E4
    // 0x8017D544: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017D544: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017D548: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D54C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D550: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017D554: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017D558: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8017D55C: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x8017D560: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    // 0x8017D564: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x8017D568: addiu       $a3, $zero, 0xBF
    ctx->r7 = ADD32(0, 0XBF);
    // 0x8017D56C: jal         0x8017D3A0
    // 0x8017D570: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_4;
    // 0x8017D570: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_4:
    // 0x8017D574: jal         0x8017D7E0
    // 0x8017D578: nop

    func_8017D7E0_1199D0(rdram, ctx);
        goto after_5;
    // 0x8017D578: nop

    after_5:
    // 0x8017D57C: b           L_8017D7D0
    // 0x8017D580: nop

        goto L_8017D7D0;
    // 0x8017D580: nop

L_8017D584:
    // 0x8017D584: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D588: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017D58C: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8017D590: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017D594: bne         $t2, $at, L_8017D654
    if (ctx->r10 != ctx->r1) {
        // 0x8017D598: nop
    
            goto L_8017D654;
    }
    // 0x8017D598: nop

    // 0x8017D59C: jal         0x800C7AD0
    // 0x8017D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_6;
    // 0x8017D5A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8017D5A4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8017D5A8: jal         0x800C7A60
    // 0x8017D5AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_7;
    // 0x8017D5AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8017D5B0: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017D5B4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D5B8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D5BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D5C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D5C4: jal         0x800C7A88
    // 0x8017D5C8: nop

    func_800C7A88(rdram, ctx);
        goto after_8;
    // 0x8017D5C8: nop

    after_8:
    // 0x8017D5CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D5D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D5D4: addiu       $a1, $a1, -0x2014
    ctx->r5 = ADD32(ctx->r5, -0X2014);
    // 0x8017D5D8: jal         0x800D87E4
    // 0x8017D5DC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017D5DC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_9:
    // 0x8017D5E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D5E4: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x8017D5E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017D5EC: bne         $t3, $at, L_8017D604
    if (ctx->r11 != ctx->r1) {
        // 0x8017D5F0: nop
    
            goto L_8017D604;
    }
    // 0x8017D5F0: nop

    // 0x8017D5F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D5F8: addiu       $t5, $t5, 0x3B40
    ctx->r13 = ADD32(ctx->r13, 0X3B40);
    // 0x8017D5FC: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8017D600: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_8017D604:
    // 0x8017D604: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D608: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8017D60C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017D610: bne         $t6, $at, L_8017D628
    if (ctx->r14 != ctx->r1) {
        // 0x8017D614: nop
    
            goto L_8017D628;
    }
    // 0x8017D614: nop

    // 0x8017D618: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D61C: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x8017D620: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8017D624: sb          $t7, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r15;
L_8017D628:
    // 0x8017D628: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D62C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D630: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D634: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017D638: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8017D63C: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x8017D640: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    // 0x8017D644: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x8017D648: addiu       $a3, $zero, 0xBF
    ctx->r7 = ADD32(0, 0XBF);
    // 0x8017D64C: jal         0x8017D3A0
    // 0x8017D650: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_10;
    // 0x8017D650: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_10:
L_8017D654:
    // 0x8017D654: jal         0x8017D7E0
    // 0x8017D658: nop

    func_8017D7E0_1199D0(rdram, ctx);
        goto after_11;
    // 0x8017D658: nop

    after_11:
    // 0x8017D65C: b           L_8017D7D0
    // 0x8017D660: nop

        goto L_8017D7D0;
    // 0x8017D660: nop

L_8017D664:
    // 0x8017D664: jal         0x800C7AD0
    // 0x8017D668: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_12;
    // 0x8017D668: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x8017D66C: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8017D670: jal         0x800C7A60
    // 0x8017D674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_13;
    // 0x8017D674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8017D678: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017D67C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D680: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D684: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D688: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D68C: jal         0x800C7A88
    // 0x8017D690: nop

    func_800C7A88(rdram, ctx);
        goto after_14;
    // 0x8017D690: nop

    after_14:
    // 0x8017D694: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D698: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D69C: addiu       $a1, $a1, -0x2000
    ctx->r5 = ADD32(ctx->r5, -0X2000);
    // 0x8017D6A0: jal         0x800D87E4
    // 0x8017D6A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_15;
    // 0x8017D6A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_15:
    // 0x8017D6A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D6AC: lw          $t2, -0x2E38($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E38);
    // 0x8017D6B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017D6B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D6B8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017D6BC: lb          $t3, -0x2064($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2064);
    // 0x8017D6C0: addiu       $t4, $t4, 0x3B40
    ctx->r12 = ADD32(ctx->r12, 0X3B40);
    // 0x8017D6C4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D6C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D6CC: sb          $t3, 0x7($t4)
    MEM_B(0X7, ctx->r12) = ctx->r11;
    // 0x8017D6D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017D6D4: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D6D8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017D6DC: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    // 0x8017D6E0: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x8017D6E4: addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    // 0x8017D6E8: addiu       $a3, $zero, 0xBF
    ctx->r7 = ADD32(0, 0XBF);
    // 0x8017D6EC: jal         0x8017D3A0
    // 0x8017D6F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_16;
    // 0x8017D6F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_16:
    // 0x8017D6F4: jal         0x8017D7E0
    // 0x8017D6F8: nop

    func_8017D7E0_1199D0(rdram, ctx);
        goto after_17;
    // 0x8017D6F8: nop

    after_17:
    // 0x8017D6FC: b           L_8017D7D0
    // 0x8017D700: nop

        goto L_8017D7D0;
    // 0x8017D700: nop

L_8017D704:
    // 0x8017D704: jal         0x800C7AD0
    // 0x8017D708: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_18;
    // 0x8017D708: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x8017D70C: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8017D710: jal         0x800C7A60
    // 0x8017D714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_19;
    // 0x8017D714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8017D718: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017D71C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D720: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D724: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D728: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D72C: jal         0x800C7A88
    // 0x8017D730: nop

    func_800C7A88(rdram, ctx);
        goto after_20;
    // 0x8017D730: nop

    after_20:
    // 0x8017D734: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D738: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D73C: addiu       $a1, $a1, -0x1FF4
    ctx->r5 = ADD32(ctx->r5, -0X1FF4);
    // 0x8017D740: jal         0x800D87E4
    // 0x8017D744: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_21;
    // 0x8017D744: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_21:
    // 0x8017D748: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D74C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D750: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8017D754: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8017D758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D75C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D760: jal         0x8017D3A0
    // 0x8017D764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_22;
    // 0x8017D764: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x8017D768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D76C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D770: addiu       $a1, $a1, -0x1FD0
    ctx->r5 = ADD32(ctx->r5, -0X1FD0);
    // 0x8017D774: jal         0x800D87E4
    // 0x8017D778: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8017D778: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_23:
    // 0x8017D77C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D780: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8017D784: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8017D788: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x8017D78C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D790: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D794: jal         0x8017D3A0
    // 0x8017D798: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_24;
    // 0x8017D798: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_24:
    // 0x8017D79C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D7A0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D7A4: addiu       $a1, $a1, -0x1FAC
    ctx->r5 = ADD32(ctx->r5, -0X1FAC);
    // 0x8017D7A8: jal         0x800D87E4
    // 0x8017D7AC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_25;
    // 0x8017D7AC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_25:
    // 0x8017D7B0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017D7B4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017D7B8: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8017D7BC: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    // 0x8017D7C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D7C4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D7C8: jal         0x8017D3A0
    // 0x8017D7CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_26;
    // 0x8017D7CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
L_8017D7D0:
    // 0x8017D7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D7D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D7D8: jr          $ra
    // 0x8017D7DC: nop

    return;
    // 0x8017D7DC: nop

;}
RECOMP_FUNC void func_8017D7E0_1199D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D7E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017D7E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017D7E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017D7EC: jal         0x800C7AD0
    // 0x8017D7F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017D7F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017D7F4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8017D7F8: jal         0x800C7A60
    // 0x8017D7FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017D7FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8017D800: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D804: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D808: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D80C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D810: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D814: jal         0x800C7A88
    // 0x8017D818: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017D818: nop

    after_2:
    // 0x8017D81C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017D820: lw          $s0, -0x2E44($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E44);
    // 0x8017D824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017D828: beq         $s0, $at, L_8017D850
    if (ctx->r16 == ctx->r1) {
        // 0x8017D82C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017D850;
    }
    // 0x8017D82C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017D830: beq         $s0, $at, L_8017D898
    if (ctx->r16 == ctx->r1) {
        // 0x8017D834: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017D898;
    }
    // 0x8017D834: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017D838: beq         $s0, $at, L_8017D8E0
    if (ctx->r16 == ctx->r1) {
        // 0x8017D83C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017D8E0;
    }
    // 0x8017D83C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017D840: beq         $s0, $at, L_8017D928
    if (ctx->r16 == ctx->r1) {
        // 0x8017D844: nop
    
            goto L_8017D928;
    }
    // 0x8017D844: nop

    // 0x8017D848: b           L_8017D968
    // 0x8017D84C: nop

        goto L_8017D968;
    // 0x8017D84C: nop

L_8017D850:
    // 0x8017D850: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D854: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D858: addiu       $a1, $a1, -0x1F88
    ctx->r5 = ADD32(ctx->r5, -0X1F88);
    // 0x8017D85C: jal         0x800D87E4
    // 0x8017D860: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017D860: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017D864: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D868: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D86C: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017D870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017D874: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017D878: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017D87C: addiu       $a1, $zero, 0x186
    ctx->r5 = ADD32(0, 0X186);
    // 0x8017D880: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8017D884: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8017D888: jal         0x8017D3A0
    // 0x8017D88C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_4;
    // 0x8017D88C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x8017D890: b           L_8017D968
    // 0x8017D894: nop

        goto L_8017D968;
    // 0x8017D894: nop

L_8017D898:
    // 0x8017D898: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D89C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D8A0: addiu       $a1, $a1, -0x1F78
    ctx->r5 = ADD32(ctx->r5, -0X1F78);
    // 0x8017D8A4: jal         0x800D87E4
    // 0x8017D8A8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8017D8A8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_5:
    // 0x8017D8AC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D8B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D8B4: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D8B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017D8BC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8017D8C0: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x8017D8C4: addiu       $a1, $zero, 0x186
    ctx->r5 = ADD32(0, 0X186);
    // 0x8017D8C8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8017D8CC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8017D8D0: jal         0x8017D3A0
    // 0x8017D8D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_6;
    // 0x8017D8D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_6:
    // 0x8017D8D8: b           L_8017D968
    // 0x8017D8DC: nop

        goto L_8017D968;
    // 0x8017D8DC: nop

L_8017D8E0:
    // 0x8017D8E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D8E4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D8E8: addiu       $a1, $a1, -0x1F6C
    ctx->r5 = ADD32(ctx->r5, -0X1F6C);
    // 0x8017D8EC: jal         0x800D87E4
    // 0x8017D8F0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017D8F0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_7:
    // 0x8017D8F4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017D8F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D8FC: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017D900: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017D904: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8017D908: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x8017D90C: addiu       $a1, $zero, 0x186
    ctx->r5 = ADD32(0, 0X186);
    // 0x8017D910: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8017D914: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8017D918: jal         0x8017D3A0
    // 0x8017D91C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_8;
    // 0x8017D91C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_8:
    // 0x8017D920: b           L_8017D968
    // 0x8017D924: nop

        goto L_8017D968;
    // 0x8017D924: nop

L_8017D928:
    // 0x8017D928: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D92C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D930: addiu       $a1, $a1, -0x1F5C
    ctx->r5 = ADD32(ctx->r5, -0X1F5C);
    // 0x8017D934: jal         0x800D87E4
    // 0x8017D938: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017D938: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_9:
    // 0x8017D93C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D940: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D944: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D948: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017D94C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017D950: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x8017D954: addiu       $a1, $zero, 0x186
    ctx->r5 = ADD32(0, 0X186);
    // 0x8017D958: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8017D95C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8017D960: jal         0x8017D3A0
    // 0x8017D964: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_8017D3A0_1199D0(rdram, ctx);
        goto after_10;
    // 0x8017D964: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_10:
L_8017D968:
    // 0x8017D968: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017D96C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017D970: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017D974: jr          $ra
    // 0x8017D978: nop

    return;
    // 0x8017D978: nop

    // 0x8017D97C: nop

;}
RECOMP_FUNC void func_8017B0C0_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B0C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B0C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B0CC: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8017B0D0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B0D4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8017B0D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017B0E0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017B0E4: sw          $t9, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r25;
    // 0x8017B0E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B0F0: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8017B0F4: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017B0F8: lbu         $t1, 0xA($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XA);
    // 0x8017B0FC: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017B100: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x8017B104: andi        $t2, $t1, 0xFD
    ctx->r10 = ctx->r9 & 0XFD;
    // 0x8017B108: jal         0x800C30F4
    // 0x8017B10C: sb          $t2, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r10;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017B10C: sb          $t2, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r10;
    after_0:
    // 0x8017B110: jal         0x8017B270
    // 0x8017B114: nop

    func_8017B270_12C2F0(rdram, ctx);
        goto after_1;
    // 0x8017B114: nop

    after_1:
    // 0x8017B118: jal         0x800C328C
    // 0x8017B11C: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017B11C: nop

    after_2:
    // 0x8017B120: jal         0x800C7FA4
    // 0x8017B124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017B124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8017B128: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B12C: jal         0x800D1640
    // 0x8017B130: addiu       $a0, $a0, -0x4E78
    ctx->r4 = ADD32(ctx->r4, -0X4E78);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017B130: addiu       $a0, $a0, -0x4E78
    ctx->r4 = ADD32(ctx->r4, -0X4E78);
    after_4:
L_8017B134:
    // 0x8017B134: jal         0x800E4CDC
    // 0x8017B138: nop

    func_800E4CDC(rdram, ctx);
        goto after_5;
    // 0x8017B138: nop

    after_5:
    // 0x8017B13C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B140: lw          $t3, -0x2E4C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E4C);
    // 0x8017B144: beq         $t3, $zero, L_8017B134
    if (ctx->r11 == 0) {
        // 0x8017B148: nop
    
            goto L_8017B134;
    }
    // 0x8017B148: nop

    // 0x8017B14C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017B150: lhu         $t4, -0x4530($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4530);
    // 0x8017B154: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x8017B158: bne         $t5, $zero, L_8017B134
    if (ctx->r13 != 0) {
        // 0x8017B15C: nop
    
            goto L_8017B134;
    }
    // 0x8017B15C: nop

    // 0x8017B160: jal         0x800CB720
    // 0x8017B164: nop

    func_800CB720(rdram, ctx);
        goto after_6;
    // 0x8017B164: nop

    after_6:
    // 0x8017B168: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B16C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B170: bne         $t7, $zero, L_8017B134
    if (ctx->r15 != 0) {
        // 0x8017B174: nop
    
            goto L_8017B134;
    }
    // 0x8017B174: nop

    // 0x8017B178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B17C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B180: jr          $ra
    // 0x8017B184: nop

    return;
    // 0x8017B184: nop

;}
RECOMP_FUNC void func_8017B188_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B18C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B190: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B198: bgtz        $t6, L_8017B260
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017B19C: nop
    
            goto L_8017B260;
    }
    // 0x8017B19C: nop

    // 0x8017B1A0: jal         0x800C3704
    // 0x8017B1A4: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017B1A4: nop

    after_0:
    // 0x8017B1A8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B1AC: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B1B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B1B4: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017B1B8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017B1BC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1C0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B1C4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B1C8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B1CC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1D0: jal         0x800C7458
    // 0x8017B1D4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017B1D4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017B1D8: jal         0x800C3FD0
    // 0x8017B1DC: nop

    func_800C3FD0(rdram, ctx);
        goto after_2;
    // 0x8017B1DC: nop

    after_2:
    // 0x8017B1E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B1E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B1E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B1EC: jal         0x800C25FC
    // 0x8017B1F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_3;
    // 0x8017B1F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8017B1F4: jal         0x8017BAE8
    // 0x8017B1F8: nop

    func_8017BAE8_12C2F0(rdram, ctx);
        goto after_4;
    // 0x8017B1F8: nop

    after_4:
    // 0x8017B1FC: jal         0x800C3578
    // 0x8017B200: nop

    func_800C3578(rdram, ctx);
        goto after_5;
    // 0x8017B200: nop

    after_5:
    // 0x8017B204: jal         0x8017B9F8
    // 0x8017B208: nop

    func_8017B9F8_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017B208: nop

    after_6:
    // 0x8017B20C: jal         0x800C3760
    // 0x8017B210: nop

    func_800C3760(rdram, ctx);
        goto after_7;
    // 0x8017B210: nop

    after_7:
    // 0x8017B214: jal         0x8017B8E4
    // 0x8017B218: nop

    func_8017B8E4_12C2F0(rdram, ctx);
        goto after_8;
    // 0x8017B218: nop

    after_8:
    // 0x8017B21C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B220: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017B224: beq         $t2, $zero, L_8017B260
    if (ctx->r10 == 0) {
        // 0x8017B228: nop
    
            goto L_8017B260;
    }
    // 0x8017B228: nop

    // 0x8017B22C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017B230: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017B234: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017B238: bne         $t4, $zero, L_8017B260
    if (ctx->r12 != 0) {
        // 0x8017B23C: nop
    
            goto L_8017B260;
    }
    // 0x8017B23C: nop

    // 0x8017B240: jal         0x800CB720
    // 0x8017B244: nop

    func_800CB720(rdram, ctx);
        goto after_9;
    // 0x8017B244: nop

    after_9:
    // 0x8017B248: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B24C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B250: bne         $t5, $zero, L_8017B260
    if (ctx->r13 != 0) {
        // 0x8017B254: nop
    
            goto L_8017B260;
    }
    // 0x8017B254: nop

    // 0x8017B258: jal         0x800D1640
    // 0x8017B25C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_10;
    // 0x8017B25C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
L_8017B260:
    // 0x8017B260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B268: jr          $ra
    // 0x8017B26C: nop

    return;
    // 0x8017B26C: nop

;}
RECOMP_FUNC void func_8017B270_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B274: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B278: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017B27C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017B280: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B284: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8017B288: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8017B28C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B294: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B298: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B29C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B2A0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8017B2A4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B2A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B2AC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8017B2B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B2B4: sw          $zero, 0x30($t9)
    MEM_W(0X30, ctx->r25) = 0;
    // 0x8017B2B8: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017B2BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B2C0: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017B2C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B2C8: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8017B2CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B2D0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017B2D4: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x8017B2D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B2DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B2E0: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x8017B2E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B2E8: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017B2EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B2F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B2F4: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017B2F8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B2FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B300: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x8017B304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B308: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017B30C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B310: swc1        $f16, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f16.u32l;
    // 0x8017B314: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017B318: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B31C: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x8017B320: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B324: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017B328: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B32C: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x8017B330: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B334: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    // 0x8017B338: jal         0x800C3FD0
    // 0x8017B33C: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B33C: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    after_0:
    // 0x8017B340: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017B344: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017B348: jal         0x800C6E0C
    // 0x8017B34C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x8017B34C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8017B350: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8017B354: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x8017B358: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017B35C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017B360: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017B364: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017B368: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017B36C: jal         0x800C6E68
    // 0x8017B370: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x8017B370: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_2:
    // 0x8017B374: jal         0x800C6DBC
    // 0x8017B378: nop

    func_800C6DBC(rdram, ctx);
        goto after_3;
    // 0x8017B378: nop

    after_3:
    // 0x8017B37C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017B380:
    // 0x8017B380: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B384: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B38C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B390: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017B394: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017B398: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B39C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017B3A0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8017B3A4: sw          $zero, 0x3C64($at)
    MEM_W(0X3C64, ctx->r1) = 0;
    // 0x8017B3A8: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x8017B3AC: sw          $t7, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r15;
    // 0x8017B3B0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B3B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8017B3B8: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8017B3BC: bne         $at, $zero, L_8017B380
    if (ctx->r1 != 0) {
        // 0x8017B3C0: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8017B380;
    }
    // 0x8017B3C0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B3C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017B3C8: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017B3CC: beq         $s0, $zero, L_8017B3EC
    if (ctx->r16 == 0) {
        // 0x8017B3D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B3EC;
    }
    // 0x8017B3D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B3D4: beq         $s0, $at, L_8017B41C
    if (ctx->r16 == ctx->r1) {
        // 0x8017B3D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B41C;
    }
    // 0x8017B3D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B3DC: beq         $s0, $at, L_8017B44C
    if (ctx->r16 == ctx->r1) {
        // 0x8017B3E0: nop
    
            goto L_8017B44C;
    }
    // 0x8017B3E0: nop

    // 0x8017B3E4: b           L_8017B508
    // 0x8017B3E8: nop

        goto L_8017B508;
    // 0x8017B3E8: nop

L_8017B3EC:
    // 0x8017B3EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B3F0: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x8017B3F4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8017B3F8: jal         0x8017B51C
    // 0x8017B3FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_4;
    // 0x8017B3FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8017B400: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B404: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8017B408: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8017B40C: jal         0x8017B690
    // 0x8017B410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8017B690_12C2F0(rdram, ctx);
        goto after_5;
    // 0x8017B410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8017B414: b           L_8017B508
    // 0x8017B418: nop

        goto L_8017B508;
    // 0x8017B418: nop

L_8017B41C:
    // 0x8017B41C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B420: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x8017B424: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8017B428: jal         0x8017B51C
    // 0x8017B42C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017B42C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8017B430: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B434: addiu       $t3, $t3, 0x3988
    ctx->r11 = ADD32(ctx->r11, 0X3988);
    // 0x8017B438: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8017B43C: jal         0x8017B690
    // 0x8017B440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8017B690_12C2F0(rdram, ctx);
        goto after_7;
    // 0x8017B440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8017B444: b           L_8017B508
    // 0x8017B448: nop

        goto L_8017B508;
    // 0x8017B448: nop

L_8017B44C:
    // 0x8017B44C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B450: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x8017B454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B458: bne         $t4, $at, L_8017B4B8
    if (ctx->r12 != ctx->r1) {
        // 0x8017B45C: nop
    
            goto L_8017B4B8;
    }
    // 0x8017B45C: nop

    // 0x8017B460: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B464: addiu       $t5, $t5, 0x3988
    ctx->r13 = ADD32(ctx->r13, 0X3988);
    // 0x8017B468: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8017B46C: jal         0x8017B51C
    // 0x8017B470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_8;
    // 0x8017B470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8017B474: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B478: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017B47C: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x8017B480: jal         0x8017B51C
    // 0x8017B484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_9;
    // 0x8017B484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8017B488: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B48C: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x8017B490: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8017B494: jal         0x8017B690
    // 0x8017B498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8017B690_12C2F0(rdram, ctx);
        goto after_10;
    // 0x8017B498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8017B49C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B4A0: addiu       $t8, $t8, 0x3988
    ctx->r24 = ADD32(ctx->r24, 0X3988);
    // 0x8017B4A4: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x8017B4A8: jal         0x8017B690
    // 0x8017B4AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8017B690_12C2F0(rdram, ctx);
        goto after_11;
    // 0x8017B4AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8017B4B0: b           L_8017B508
    // 0x8017B4B4: nop

        goto L_8017B508;
    // 0x8017B4B4: nop

L_8017B4B8:
    // 0x8017B4B8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B4BC: addiu       $t9, $t9, 0x3988
    ctx->r25 = ADD32(ctx->r25, 0X3988);
    // 0x8017B4C0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8017B4C4: jal         0x8017B51C
    // 0x8017B4C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_12;
    // 0x8017B4C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x8017B4CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B4D0: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x8017B4D4: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x8017B4D8: jal         0x8017B51C
    // 0x8017B4DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8017B51C_12C2F0(rdram, ctx);
        goto after_13;
    // 0x8017B4DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8017B4E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B4E4: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8017B4E8: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    // 0x8017B4EC: jal         0x8017B690
    // 0x8017B4F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8017B690_12C2F0(rdram, ctx);
        goto after_14;
    // 0x8017B4F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x8017B4F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B4F8: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x8017B4FC: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x8017B500: jal         0x8017B690
    // 0x8017B504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8017B690_12C2F0(rdram, ctx);
        goto after_15;
    // 0x8017B504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_8017B508:
    // 0x8017B508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017B50C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017B510: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017B514: jr          $ra
    // 0x8017B518: nop

    return;
    // 0x8017B518: nop

;}
RECOMP_FUNC void func_8017B51C_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B51C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B528: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017B52C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8017B530:
    // 0x8017B530: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B534: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B538: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8017B53C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8017B540: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017B544: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B548: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B54C: lw          $t8, 0x3A38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3A38);
    // 0x8017B550: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8017B554: bne         $at, $zero, L_8017B66C
    if (ctx->r1 != 0) {
        // 0x8017B558: nop
    
            goto L_8017B66C;
    }
    // 0x8017B558: nop

    // 0x8017B55C: xori        $t0, $t6, 0x4
    ctx->r8 = ctx->r14 ^ 0X4;
    // 0x8017B560: sltu        $t0, $zero, $t0
    ctx->r8 = 0 < ctx->r8 ? 1 : 0;
    // 0x8017B564: beq         $t0, $zero, L_8017B5F4
    if (ctx->r8 == 0) {
        // 0x8017B568: nop
    
            goto L_8017B5F4;
    }
    // 0x8017B568: nop

    // 0x8017B56C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017B570: beq         $t0, $zero, L_8017B5F4
    if (ctx->r8 == 0) {
        // 0x8017B574: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_8017B5F4;
    }
    // 0x8017B574: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8017B578:
    // 0x8017B578: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8017B57C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B580: addiu       $t4, $t4, 0x3A20
    ctx->r12 = ADD32(ctx->r12, 0X3A20);
    // 0x8017B584: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8017B588: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017B58C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B590: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017B594: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8017B598: jal         0x800E4C90
    // 0x8017B59C: addiu       $a1, $t5, -0x24
    ctx->r5 = ADD32(ctx->r13, -0X24);
    func_800E4C90(rdram, ctx);
        goto after_0;
    // 0x8017B59C: addiu       $a1, $t5, -0x24
    ctx->r5 = ADD32(ctx->r13, -0X24);
    after_0:
    // 0x8017B5A0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017B5A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B5A8: addiu       $t9, $t9, 0x3A20
    ctx->r25 = ADD32(ctx->r25, 0X3A20);
    // 0x8017B5AC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8017B5B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B5B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B5B8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8017B5BC: lw          $t1, -0xC($t6)
    ctx->r9 = MEM_W(ctx->r14, -0XC);
    // 0x8017B5C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B5C4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B5C8: sw          $t1, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r9;
    // 0x8017B5CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017B5D0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8017B5D4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017B5D8: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8017B5DC: sw          $t5, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r13;
    // 0x8017B5E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017B5E4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B5E8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8017B5EC: bne         $t8, $t9, L_8017B578
    if (ctx->r24 != ctx->r25) {
        // 0x8017B5F0: sw          $t8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r24;
            goto L_8017B578;
    }
    // 0x8017B5F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8017B5F4:
    // 0x8017B5F4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B5F8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8017B5FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B600: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x8017B604: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017B608: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017B60C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8017B610: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017B614: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B618: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B61C: addiu       $t5, $t5, -0x2AA0
    ctx->r13 = ADD32(ctx->r13, -0X2AA0);
    // 0x8017B620: addiu       $t0, $t0, 0x3A20
    ctx->r8 = ADD32(ctx->r8, 0X3A20);
    // 0x8017B624: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    // 0x8017B628: jal         0x800E4C90
    // 0x8017B62C: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    func_800E4C90(rdram, ctx);
        goto after_1;
    // 0x8017B62C: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    after_1:
    // 0x8017B630: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B634: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8017B638: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B63C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8017B640: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B644: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B648: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B64C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017B650: sw          $t4, 0x3A38($at)
    MEM_W(0X3A38, ctx->r1) = ctx->r12;
    // 0x8017B654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B658: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8017B65C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017B660: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017B664: b           L_8017B680
    // 0x8017B668: sw          $t9, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r25;
        goto L_8017B680;
    // 0x8017B668: sw          $t9, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r25;
L_8017B66C:
    // 0x8017B66C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B670: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8017B674: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8017B678: bne         $at, $zero, L_8017B530
    if (ctx->r1 != 0) {
        // 0x8017B67C: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8017B530;
    }
    // 0x8017B67C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_8017B680:
    // 0x8017B680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B688: jr          $ra
    // 0x8017B68C: nop

    return;
    // 0x8017B68C: nop

;}
RECOMP_FUNC void func_8017B690_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017B694: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017B698: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017B69C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B6A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017B6A4: beq         $t6, $zero, L_8017B8D4
    if (ctx->r14 == 0) {
        // 0x8017B6A8: nop
    
            goto L_8017B8D4;
    }
    // 0x8017B6A8: nop

    // 0x8017B6AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B6B0: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017B6B4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017B6B8: beq         $t8, $zero, L_8017B8D4
    if (ctx->r24 == 0) {
        // 0x8017B6BC: nop
    
            goto L_8017B8D4;
    }
    // 0x8017B6BC: nop

    // 0x8017B6C0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017B6C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B6C8: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8017B6CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B6D0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017B6D4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017B6D8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8017B6DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B6E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B6E4: divu        $zero, $t0, $t2
    lo = S32(U32(ctx->r8) / U32(ctx->r10)); hi = S32(U32(ctx->r8) % U32(ctx->r10));
    // 0x8017B6E8: mflo        $t3
    ctx->r11 = lo;
    // 0x8017B6EC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8017B6F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8017B6F4: bne         $t2, $zero, L_8017B700
    if (ctx->r10 != 0) {
        // 0x8017B6F8: nop
    
            goto L_8017B700;
    }
    // 0x8017B6F8: nop

    // 0x8017B6FC: break       7
    do_break(2149037820);
L_8017B700:
    // 0x8017B700: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017B704: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B708: addiu       $t6, $t6, 0x3A20
    ctx->r14 = ADD32(ctx->r14, 0X3A20);
    // 0x8017B70C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8017B710: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017B714: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B718: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B71C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8017B720: lw          $t1, 0x1C($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X1C);
    // 0x8017B724: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B728: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017B72C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017B730: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8017B734: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017B738: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B73C: divu        $zero, $t9, $t1
    lo = S32(U32(ctx->r25) / U32(ctx->r9)); hi = S32(U32(ctx->r25) % U32(ctx->r9));
    // 0x8017B740: mflo        $t0
    ctx->r8 = lo;
    // 0x8017B744: sltu        $at, $t2, $t0
    ctx->r1 = ctx->r10 < ctx->r8 ? 1 : 0;
    // 0x8017B748: bne         $t1, $zero, L_8017B754
    if (ctx->r9 != 0) {
        // 0x8017B74C: nop
    
            goto L_8017B754;
    }
    // 0x8017B74C: nop

    // 0x8017B750: break       7
    do_break(2149037904);
L_8017B754:
    // 0x8017B754: bne         $at, $zero, L_8017B8C0
    if (ctx->r1 != 0) {
        // 0x8017B758: nop
    
            goto L_8017B8C0;
    }
    // 0x8017B758: nop

    // 0x8017B75C: xori        $t3, $t4, 0x4
    ctx->r11 = ctx->r12 ^ 0X4;
    // 0x8017B760: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x8017B764: beq         $t3, $zero, L_8017B81C
    if (ctx->r11 == 0) {
        // 0x8017B768: nop
    
            goto L_8017B81C;
    }
    // 0x8017B768: nop

    // 0x8017B76C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017B770: beq         $t3, $zero, L_8017B81C
    if (ctx->r11 == 0) {
        // 0x8017B774: sw          $t5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r13;
            goto L_8017B81C;
    }
    // 0x8017B774: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_8017B778:
    // 0x8017B778: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B77C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B780: addiu       $t9, $t9, 0x3A20
    ctx->r25 = ADD32(ctx->r25, 0X3A20);
    // 0x8017B784: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8017B788: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017B78C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B790: addiu       $t7, $t8, 0xC
    ctx->r15 = ADD32(ctx->r24, 0XC);
    // 0x8017B794: addiu       $t1, $t8, -0x18
    ctx->r9 = ADD32(ctx->r24, -0X18);
    // 0x8017B798: addu        $a1, $t1, $t9
    ctx->r5 = ADD32(ctx->r9, ctx->r25);
    // 0x8017B79C: jal         0x800E4C90
    // 0x8017B7A0: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    func_800E4C90(rdram, ctx);
        goto after_0;
    // 0x8017B7A0: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x8017B7A4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017B7A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B7AC: addiu       $t4, $t4, 0x3A20
    ctx->r12 = ADD32(ctx->r12, 0X3A20);
    // 0x8017B7B0: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8017B7B4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8017B7B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B7BC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B7C0: lw          $t3, -0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, -0X8);
    // 0x8017B7C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B7C8: addiu       $t8, $t8, 0x3A20
    ctx->r24 = ADD32(ctx->r24, 0X3A20);
    // 0x8017B7CC: sw          $t3, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r11;
    // 0x8017B7D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B7D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B7D8: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017B7DC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8017B7E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017B7E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B7E8: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8017B7EC: lw          $t9, -0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X4);
    // 0x8017B7F0: sw          $t9, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r25;
    // 0x8017B7F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017B7F8: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8017B7FC: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B800: lw          $t5, 0x60($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X60);
    // 0x8017B804: sw          $t5, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r13;
    // 0x8017B808: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B80C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8017B810: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017B814: bne         $t7, $t8, L_8017B778
    if (ctx->r15 != ctx->r24) {
        // 0x8017B818: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_8017B778;
    }
    // 0x8017B818: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8017B81C:
    // 0x8017B81C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017B820: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B824: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B828: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8017B82C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8017B830: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017B834: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B838: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017B83C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017B840: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B844: addiu       $t3, $t3, -0x2AA0
    ctx->r11 = ADD32(ctx->r11, -0X2AA0);
    // 0x8017B848: addiu       $t0, $t1, 0xC
    ctx->r8 = ADD32(ctx->r9, 0XC);
    // 0x8017B84C: addiu       $t2, $t2, 0x3A20
    ctx->r10 = ADD32(ctx->r10, 0X3A20);
    // 0x8017B850: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    // 0x8017B854: jal         0x800E4C90
    // 0x8017B858: addu        $a1, $t5, $t3
    ctx->r5 = ADD32(ctx->r13, ctx->r11);
    func_800E4C90(rdram, ctx);
        goto after_1;
    // 0x8017B858: addu        $a1, $t5, $t3
    ctx->r5 = ADD32(ctx->r13, ctx->r11);
    after_1:
    // 0x8017B85C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8017B860: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B864: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017B868: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x8017B86C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8017B870: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017B874: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017B878: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B87C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B880: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017B884: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8017B888: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017B88C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8017B890: sw          $t7, 0x3A3C($at)
    MEM_W(0X3A3C, ctx->r1) = ctx->r15;
    // 0x8017B894: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8017B898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B89C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B8A0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017B8A4: sw          $t1, 0x3A40($at)
    MEM_W(0X3A40, ctx->r1) = ctx->r9;
    // 0x8017B8A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B8AC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8017B8B0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017B8B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017B8B8: b           L_8017B8D4
    // 0x8017B8BC: sw          $t4, 0x3C64($at)
    MEM_W(0X3C64, ctx->r1) = ctx->r12;
        goto L_8017B8D4;
    // 0x8017B8BC: sw          $t4, 0x3C64($at)
    MEM_W(0X3C64, ctx->r1) = ctx->r12;
L_8017B8C0:
    // 0x8017B8C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8017B8C4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8017B8C8: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8017B8CC: bne         $at, $zero, L_8017B700
    if (ctx->r1 != 0) {
        // 0x8017B8D0: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_8017B700;
    }
    // 0x8017B8D0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8017B8D4:
    // 0x8017B8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B8D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017B8DC: jr          $ra
    // 0x8017B8E0: nop

    return;
    // 0x8017B8E0: nop

;}
RECOMP_FUNC void func_8017B8E4_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B8E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B8EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B8F0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B8F4: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8017B8F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B8FC: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x8017B900: sw          $t8, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r24;
    // 0x8017B904: lw          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E4C);
    // 0x8017B908: bne         $t9, $zero, L_8017B9E8
    if (ctx->r25 != 0) {
        // 0x8017B90C: nop
    
            goto L_8017B9E8;
    }
    // 0x8017B90C: nop

    // 0x8017B910: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8017B914: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x8017B918: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8017B91C: bne         $t1, $zero, L_8017B9E8
    if (ctx->r9 != 0) {
        // 0x8017B920: nop
    
            goto L_8017B9E8;
    }
    // 0x8017B920: nop

    // 0x8017B924: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B928: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B92C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017B930: bne         $t3, $zero, L_8017B960
    if (ctx->r11 != 0) {
        // 0x8017B934: nop
    
            goto L_8017B960;
    }
    // 0x8017B934: nop

    // 0x8017B938: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8017B93C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8017B940: bne         $t4, $at, L_8017B960
    if (ctx->r12 != ctx->r1) {
        // 0x8017B944: nop
    
            goto L_8017B960;
    }
    // 0x8017B944: nop

    // 0x8017B948: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8017B94C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B950: jal         0x800C32CC
    // 0x8017B954: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x8017B954: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    after_0:
    // 0x8017B958: b           L_8017B9E8
    // 0x8017B95C: nop

        goto L_8017B9E8;
    // 0x8017B95C: nop

L_8017B960:
    // 0x8017B960: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B964: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B968: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017B96C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B970: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B974: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8017B978: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8017B97C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8017B980: beq         $t0, $zero, L_8017B9C0
    if (ctx->r8 == 0) {
        // 0x8017B984: nop
    
            goto L_8017B9C0;
    }
    // 0x8017B984: nop

    // 0x8017B988: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8017B98C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8017B990: bne         $t1, $at, L_8017B9C0
    if (ctx->r9 != ctx->r1) {
        // 0x8017B994: nop
    
            goto L_8017B9C0;
    }
    // 0x8017B994: nop

    // 0x8017B998: jal         0x800C8544
    // 0x8017B99C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017B99C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x8017B9A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B9A4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B9A8: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x8017B9AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B9B0: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B9B4: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8017B9B8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8017B9BC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_8017B9C0:
    // 0x8017B9C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B9C4: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B9C8: lhu         $t6, 0x2($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X2);
    // 0x8017B9CC: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x8017B9D0: beq         $t7, $zero, L_8017B9E8
    if (ctx->r15 == 0) {
        // 0x8017B9D4: nop
    
            goto L_8017B9E8;
    }
    // 0x8017B9D4: nop

    // 0x8017B9D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017B9DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B9E0: jal         0x800C32CC
    // 0x8017B9E4: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    func_800C32CC(rdram, ctx);
        goto after_2;
    // 0x8017B9E4: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    after_2:
L_8017B9E8:
    // 0x8017B9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B9F0: jr          $ra
    // 0x8017B9F4: nop

    return;
    // 0x8017B9F4: nop

;}
RECOMP_FUNC void func_8017B9F8_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B9F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8017B9FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA00: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8017BA04: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BA08: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BA0C: addiu       $a1, $a1, -0x2A30
    ctx->r5 = ADD32(ctx->r5, -0X2A30);
    // 0x8017BA10: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8017BA14: jal         0x800D87E4
    // 0x8017BA18: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017BA18: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8017BA1C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8017BA20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BA24: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017BA28: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8017BA2C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017BA30: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BA34: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8017BA38: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8017BA3C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017BA40: addiu       $t3, $t2, 0x13EC
    ctx->r11 = ADD32(ctx->r10, 0X13EC);
    // 0x8017BA44: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x8017BA48: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8017BA4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BA50: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8017BA54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BA58: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8017BA5C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017BA60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BA64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017BA68: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017BA6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017BA70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017BA74: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017BA78: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017BA7C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017BA80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BA84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BA88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BA8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017BA90: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017BA94: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8017BA98: mflo        $t4
    ctx->r12 = lo;
    // 0x8017BA9C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017BAA0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8017BAA4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8017BAA8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8017BAAC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8017BAB0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017BAB4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8017BAB8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017BABC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017BAC0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017BAC4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017BAC8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017BACC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017BAD0: jal         0x801716C8
    // 0x8017BAD4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017BAD4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8017BAD8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017BADC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8017BAE0: jr          $ra
    // 0x8017BAE4: nop

    return;
    // 0x8017BAE4: nop

;}
RECOMP_FUNC void func_8017BAE8_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BAE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BAEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017BAF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BAF4: jal         0x800D54C8
    // 0x8017BAF8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x8017BAF8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x8017BAFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BB00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BB04: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BB08: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x8017BB0C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017BB10: addiu       $a0, $a0, -0x16A0
    ctx->r4 = ADD32(ctx->r4, -0X16A0);
    // 0x8017BB14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8017BB18: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8017BB1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BB20: jal         0x800C6C6C
    // 0x8017BB24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017BB24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8017BB28: jal         0x800C6D5C
    // 0x8017BB2C: nop

    func_800C6D5C(rdram, ctx);
        goto after_2;
    // 0x8017BB2C: nop

    after_2:
    // 0x8017BB30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BB34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BB38: jr          $ra
    // 0x8017BB3C: nop

    return;
    // 0x8017BB3C: nop

;}
RECOMP_FUNC void func_8017BB40_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BB40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017BB44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017BB48: jal         0x800C7AD0
    // 0x8017BB4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017BB4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017BB50: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8017BB54: jal         0x800C7A60
    // 0x8017BB58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017BB58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017BB5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017BB60: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BB64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BB68: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BB6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BB70: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BB74: jal         0x800C7A88
    // 0x8017BB78: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017BB78: nop

    after_2:
    // 0x8017BB7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BB80: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BB84: addiu       $a1, $a1, -0x2A2C
    ctx->r5 = ADD32(ctx->r5, -0X2A2C);
    // 0x8017BB88: jal         0x800D87E4
    // 0x8017BB8C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017BB8C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017BB90: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017BB94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017BB98: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x8017BB9C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8017BBA0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017BBA4: addiu       $a3, $zero, 0x49
    ctx->r7 = ADD32(0, 0X49);
    // 0x8017BBA8: jal         0x8017BE28
    // 0x8017BBAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_4;
    // 0x8017BBAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8017BBB0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017BBB4:
    // 0x8017BBB4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BBB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BBBC: addiu       $t9, $t9, 0x3A20
    ctx->r25 = ADD32(ctx->r25, 0X3A20);
    // 0x8017BBC0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8017BBC4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017BBC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BBCC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017BBD0: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8017BBD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BBD8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BBDC: addiu       $a1, $a1, -0x2A1C
    ctx->r5 = ADD32(ctx->r5, -0X2A1C);
    // 0x8017BBE0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017BBE4: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8017BBE8: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8017BBEC: jal         0x800D87E4
    // 0x8017BBF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8017BBF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_5:
    // 0x8017BBF4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BBF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BBFC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017BC00: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017BC04: lw          $t4, 0x3C50($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3C50);
    // 0x8017BC08: bne         $t4, $zero, L_8017BC4C
    if (ctx->r12 != 0) {
        // 0x8017BC0C: nop
    
            goto L_8017BC4C;
    }
    // 0x8017BC0C: nop

    // 0x8017BC10: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017BC14: addiu       $t5, $t5, -0x2A64
    ctx->r13 = ADD32(ctx->r13, -0X2A64);
    // 0x8017BC18: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8017BC1C: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x8017BC20: lbu         $a2, 0x0($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X0);
    // 0x8017BC24: lbu         $a3, 0x1($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X1);
    // 0x8017BC28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017BC2C: lbu         $t8, 0x3($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X3);
    // 0x8017BC30: sll         $a1, $t2, 5
    ctx->r5 = S32(ctx->r10 << 5);
    // 0x8017BC34: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8017BC38: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8017BC3C: jal         0x8017BE28
    // 0x8017BC40: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017BC40: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x8017BC44: b           L_8017BC94
    // 0x8017BC48: nop

        goto L_8017BC94;
    // 0x8017BC48: nop

L_8017BC4C:
    // 0x8017BC4C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BC50: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8017BC54: addiu       $t1, $t1, -0x2A64
    ctx->r9 = ADD32(ctx->r9, -0X2A64);
    // 0x8017BC58: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017BC5C: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8017BC60: lbu         $t2, 0x2($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X2);
    // 0x8017BC64: lbu         $a2, 0x0($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X0);
    // 0x8017BC68: lbu         $a3, 0x1($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X1);
    // 0x8017BC6C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BC70: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017BC74: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017BC78: lw          $t5, 0x30($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X30);
    // 0x8017BC7C: sll         $a1, $t9, 5
    ctx->r5 = S32(ctx->r25 << 5);
    // 0x8017BC80: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8017BC84: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x8017BC88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017BC8C: jal         0x8017BE28
    // 0x8017BC90: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_7;
    // 0x8017BC90: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_7:
L_8017BC94:
    // 0x8017BC94: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BC98: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8017BC9C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8017BCA0: bne         $at, $zero, L_8017BBB4
    if (ctx->r1 != 0) {
        // 0x8017BCA4: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_8017BBB4;
    }
    // 0x8017BCA4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8017BCA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BCAC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BCB0: addiu       $a1, $a1, -0x2A0C
    ctx->r5 = ADD32(ctx->r5, -0X2A0C);
    // 0x8017BCB4: jal         0x800D87E4
    // 0x8017BCB8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8017BCB8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_8:
    // 0x8017BCBC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017BCC0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017BCC4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017BCC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017BCCC: addiu       $a0, $zero, 0x188
    ctx->r4 = ADD32(0, 0X188);
    // 0x8017BCD0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8017BCD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BCD8: jal         0x8017BE28
    // 0x8017BCDC: addiu       $a3, $zero, 0x6D
    ctx->r7 = ADD32(0, 0X6D);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_9;
    // 0x8017BCDC: addiu       $a3, $zero, 0x6D
    ctx->r7 = ADD32(0, 0X6D);
    after_9:
    // 0x8017BCE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017BCE4:
    // 0x8017BCE4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BCE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BCEC: addiu       $t3, $t3, 0x3A20
    ctx->r11 = ADD32(ctx->r11, 0X3A20);
    // 0x8017BCF0: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x8017BCF4: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017BCF8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017BCFC: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x8017BD00: lw          $t7, 0x20($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20);
    // 0x8017BD04: lw          $t8, 0x1C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1C);
    // 0x8017BD08: addiu       $t2, $t4, 0xC
    ctx->r10 = ADD32(ctx->r12, 0XC);
    // 0x8017BD0C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8017BD10: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8017BD14: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8017BD18: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BD1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD20: divu        $zero, $t6, $t8
    lo = S32(U32(ctx->r14) / U32(ctx->r24)); hi = S32(U32(ctx->r14) % U32(ctx->r24));
    // 0x8017BD24: mflo        $t9
    ctx->r25 = lo;
    // 0x8017BD28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017BD2C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017BD30: lw          $t0, 0x1C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X1C);
    // 0x8017BD34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BD38: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BD3C: addiu       $a1, $a1, -0x29F4
    ctx->r5 = ADD32(ctx->r5, -0X29F4);
    // 0x8017BD40: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017BD44: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x8017BD48: addiu       $a2, $t1, 0x1
    ctx->r6 = ADD32(ctx->r9, 0X1);
    // 0x8017BD4C: bne         $t8, $zero, L_8017BD58
    if (ctx->r24 != 0) {
        // 0x8017BD50: nop
    
            goto L_8017BD58;
    }
    // 0x8017BD50: nop

    // 0x8017BD54: break       7
    do_break(2149039444);
L_8017BD58:
    // 0x8017BD58: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8017BD5C: jal         0x800D87E4
    // 0x8017BD60: nop

    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x8017BD60: nop

    after_10:
    // 0x8017BD64: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BD68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BD6C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017BD70: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8017BD74: lw          $t4, 0x3C64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3C64);
    // 0x8017BD78: bne         $t4, $zero, L_8017BDBC
    if (ctx->r12 != 0) {
        // 0x8017BD7C: nop
    
            goto L_8017BDBC;
    }
    // 0x8017BD7C: nop

    // 0x8017BD80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017BD84: addiu       $t3, $t3, -0x2A50
    ctx->r11 = ADD32(ctx->r11, -0X2A50);
    // 0x8017BD88: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8017BD8C: lbu         $t8, 0x2($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X2);
    // 0x8017BD90: lbu         $a2, 0x0($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X0);
    // 0x8017BD94: lbu         $a3, 0x1($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X1);
    // 0x8017BD98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017BD9C: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x8017BDA0: sll         $a1, $t1, 5
    ctx->r5 = S32(ctx->r9 << 5);
    // 0x8017BDA4: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8017BDA8: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    // 0x8017BDAC: jal         0x8017BE28
    // 0x8017BDB0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_11;
    // 0x8017BDB0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_11:
    // 0x8017BDB4: b           L_8017BE04
    // 0x8017BDB8: nop

        goto L_8017BE04;
    // 0x8017BDB8: nop

L_8017BDBC:
    // 0x8017BDBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BDC0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8017BDC4: addiu       $t0, $t0, -0x2A50
    ctx->r8 = ADD32(ctx->r8, -0X2A50);
    // 0x8017BDC8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8017BDCC: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x8017BDD0: lbu         $t1, 0x2($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X2);
    // 0x8017BDD4: lbu         $a2, 0x0($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X0);
    // 0x8017BDD8: lbu         $a3, 0x1($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X1);
    // 0x8017BDDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BDE0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017BDE4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017BDE8: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x8017BDEC: sll         $a1, $t7, 5
    ctx->r5 = S32(ctx->r15 << 5);
    // 0x8017BDF0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8017BDF4: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x8017BDF8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017BDFC: jal         0x8017BE28
    // 0x8017BE00: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_12;
    // 0x8017BE00: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    after_12:
L_8017BE04:
    // 0x8017BE04: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BE08: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8017BE0C: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8017BE10: bne         $at, $zero, L_8017BCE4
    if (ctx->r1 != 0) {
        // 0x8017BE14: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8017BCE4;
    }
    // 0x8017BE14: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017BE18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017BE1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017BE20: jr          $ra
    // 0x8017BE24: nop

    return;
    // 0x8017BE24: nop

;}
RECOMP_FUNC void func_8017BE28_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BE28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017BE2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BE30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017BE34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017BE38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8017BE3C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8017BE40: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8017BE44: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017BE48: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8017BE4C: jal         0x800C7A9C
    // 0x8017BE50: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    func_800C7A9C(rdram, ctx);
        goto after_0;
    // 0x8017BE50: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x8017BE54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017BE58: jal         0x800C7A74
    // 0x8017BE5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C7A74(rdram, ctx);
        goto after_1;
    // 0x8017BE5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8017BE60: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BE64: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017BE68: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017BE6C: jal         0x800C767C
    // 0x8017BE70: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_2;
    // 0x8017BE70: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_2:
    // 0x8017BE74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BE78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BE7C: jr          $ra
    // 0x8017BE80: nop

    return;
    // 0x8017BE80: nop

    // 0x8017BE84: nop

    // 0x8017BE88: nop

    // 0x8017BE8C: nop

;}
RECOMP_FUNC void func_8017BE90_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BE90: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8017BE94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE98: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017BE9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BEA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BEA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BEA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BEAC: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017BEB0: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017BEB4: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017BEB8: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017BEBC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x8017BEC0: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8017BEC4: jal         0x800C30F4
    // 0x8017BEC8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017BEC8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x8017BECC: jal         0x8017C014
    // 0x8017BED0: nop

    func_8017C014_12C2F0(rdram, ctx);
        goto after_1;
    // 0x8017BED0: nop

    after_1:
    // 0x8017BED4: jal         0x800C328C
    // 0x8017BED8: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017BED8: nop

    after_2:
    // 0x8017BEDC: jal         0x800C7FA4
    // 0x8017BEE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017BEE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8017BEE4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BEE8: jal         0x800D1640
    // 0x8017BEEC: addiu       $a0, $a0, -0x40C4
    ctx->r4 = ADD32(ctx->r4, -0X40C4);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017BEEC: addiu       $a0, $a0, -0x40C4
    ctx->r4 = ADD32(ctx->r4, -0X40C4);
    after_4:
L_8017BEF0:
    // 0x8017BEF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BEF4: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8017BEF8: beq         $t0, $zero, L_8017BEF0
    if (ctx->r8 == 0) {
        // 0x8017BEFC: nop
    
            goto L_8017BEF0;
    }
    // 0x8017BEFC: nop

    // 0x8017BF00: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017BF04: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017BF08: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8017BF0C: bne         $t2, $zero, L_8017BEF0
    if (ctx->r10 != 0) {
        // 0x8017BF10: nop
    
            goto L_8017BEF0;
    }
    // 0x8017BF10: nop

    // 0x8017BF14: jal         0x800CB720
    // 0x8017BF18: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x8017BF18: nop

    after_5:
    // 0x8017BF1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017BF20: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BF24: bne         $t3, $zero, L_8017BEF0
    if (ctx->r11 != 0) {
        // 0x8017BF28: nop
    
            goto L_8017BEF0;
    }
    // 0x8017BF28: nop

    // 0x8017BF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BF34: jr          $ra
    // 0x8017BF38: nop

    return;
    // 0x8017BF38: nop

;}
RECOMP_FUNC void func_8017BF3C_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BF3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BF40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017BF44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017BF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BF4C: bgtz        $t6, L_8017C004
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017BF50: nop
    
            goto L_8017C004;
    }
    // 0x8017BF50: nop

    // 0x8017BF54: jal         0x800C3704
    // 0x8017BF58: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017BF58: nop

    after_0:
    // 0x8017BF5C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017BF60: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017BF64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017BF68: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017BF6C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017BF70: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017BF74: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017BF78: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017BF7C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017BF80: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017BF84: jal         0x800C7458
    // 0x8017BF88: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017BF88: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017BF8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017BF90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017BF94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BF98: jal         0x800C25FC
    // 0x8017BF9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017BF9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017BFA0: jal         0x8017BAE8
    // 0x8017BFA4: nop

    func_8017BAE8_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017BFA4: nop

    after_3:
    // 0x8017BFA8: jal         0x800C3578
    // 0x8017BFAC: nop

    func_800C3578(rdram, ctx);
        goto after_4;
    // 0x8017BFAC: nop

    after_4:
    // 0x8017BFB0: jal         0x800C3760
    // 0x8017BFB4: nop

    func_800C3760(rdram, ctx);
        goto after_5;
    // 0x8017BFB4: nop

    after_5:
    // 0x8017BFB8: jal         0x8017C718
    // 0x8017BFBC: nop

    func_8017C718_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017BFBC: nop

    after_6:
    // 0x8017BFC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BFC4: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017BFC8: beq         $t2, $zero, L_8017C004
    if (ctx->r10 == 0) {
        // 0x8017BFCC: nop
    
            goto L_8017C004;
    }
    // 0x8017BFCC: nop

    // 0x8017BFD0: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017BFD4: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017BFD8: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017BFDC: bne         $t4, $zero, L_8017C004
    if (ctx->r12 != 0) {
        // 0x8017BFE0: nop
    
            goto L_8017C004;
    }
    // 0x8017BFE0: nop

    // 0x8017BFE4: jal         0x800CB720
    // 0x8017BFE8: nop

    func_800CB720(rdram, ctx);
        goto after_7;
    // 0x8017BFE8: nop

    after_7:
    // 0x8017BFEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017BFF0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BFF4: bne         $t5, $zero, L_8017C004
    if (ctx->r13 != 0) {
        // 0x8017BFF8: nop
    
            goto L_8017C004;
    }
    // 0x8017BFF8: nop

    // 0x8017BFFC: jal         0x800D1640
    // 0x8017C000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_8;
    // 0x8017C000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_8017C004:
    // 0x8017C004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C00C: jr          $ra
    // 0x8017C010: nop

    return;
    // 0x8017C010: nop

;}
RECOMP_FUNC void func_8017C014_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C014: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017C018: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C01C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017C020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017C024: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8017C028: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017C02C: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8017C030: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C034: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8017C038: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C03C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C040: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8017C044: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C048: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017C04C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C050: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C054: sw          $t9, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->r25;
    // 0x8017C058: lw          $t2, 0xC8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC8);
    // 0x8017C05C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C060: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C064: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8017C068: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C06C: sw          $t2, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->r10;
    // 0x8017C070: sw          $t3, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->r11;
    // 0x8017C074: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017C078: lw          $t6, 0xCC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XCC);
    // 0x8017C07C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C080: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017C084: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C088: sw          $t6, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->r14;
    // 0x8017C08C: sw          $zero, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = 0;
    // 0x8017C090: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C094: lw          $t9, 0xD0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD0);
    // 0x8017C098: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C09C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C0A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C0A4: sw          $t9, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->r25;
    // 0x8017C0A8: sw          $zero, 0xAC($t0)
    MEM_W(0XAC, ctx->r8) = 0;
    // 0x8017C0AC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C0B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8017C0B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C0B8: sw          $t2, 0xD4($t1)
    MEM_W(0XD4, ctx->r9) = ctx->r10;
    // 0x8017C0BC: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C0C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C0C4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C0C8: sw          $zero, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = 0;
    // 0x8017C0CC: lw          $t6, 0xEC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XEC);
    // 0x8017C0D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C0D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C0D8: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017C0DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C0E0: sw          $t6, 0xC4($t4)
    MEM_W(0XC4, ctx->r12) = ctx->r14;
    // 0x8017C0E4: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017C0E8: swc1        $f4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f4.u32l;
    // 0x8017C0EC: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017C0F0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8017C0F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C0F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C0FC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C100: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017C104: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C108: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x8017C10C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017C110: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C114: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x8017C118: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017C11C: swc1        $f10, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f10.u32l;
    // 0x8017C120: lwc1        $f20, 0x14($t0)
    ctx->f20.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8017C124: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C128: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C12C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C130: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C134: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017C138: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C13C: swc1        $f20, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f20.u32l;
    // 0x8017C140: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017C144: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C148: swc1        $f20, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f20.u32l;
    // 0x8017C14C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C150: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017C154: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C158: swc1        $f16, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f16.u32l;
    // 0x8017C15C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017C160: swc1        $f18, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f18.u32l;
    // 0x8017C164: jal         0x800C3FD0
    // 0x8017C168: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017C168: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x8017C16C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8017C170:
    // 0x8017C170: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8017C174: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8017C178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C17C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C180: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017C184: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017C188: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C18C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8017C190: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x8017C194: sw          $zero, 0x3C78($at)
    MEM_W(0X3C78, ctx->r1) = 0;
    // 0x8017C198: lw          $t2, 0x78($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X78);
    // 0x8017C19C: sw          $t2, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r10;
    // 0x8017C1A0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017C1A4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8017C1A8: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x8017C1AC: bne         $at, $zero, L_8017C170
    if (ctx->r1 != 0) {
        // 0x8017C1B0: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_8017C170;
    }
    // 0x8017C1B0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8017C1B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C1B8: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017C1BC: beq         $s0, $zero, L_8017C1DC
    if (ctx->r16 == 0) {
        // 0x8017C1C0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017C1DC;
    }
    // 0x8017C1C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C1C4: beq         $s0, $at, L_8017C20C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C1C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C20C;
    }
    // 0x8017C1C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C1CC: beq         $s0, $at, L_8017C23C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C1D0: nop
    
            goto L_8017C23C;
    }
    // 0x8017C1D0: nop

    // 0x8017C1D4: b           L_8017C28C
    // 0x8017C1D8: nop

        goto L_8017C28C;
    // 0x8017C1D8: nop

L_8017C1DC:
    // 0x8017C1DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C1E0: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x8017C1E4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8017C1E8: jal         0x8017C378
    // 0x8017C1EC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C378_12C2F0(rdram, ctx);
        goto after_1;
    // 0x8017C1EC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_1:
    // 0x8017C1F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C1F4: addiu       $t4, $t4, 0x3988
    ctx->r12 = ADD32(ctx->r12, 0X3988);
    // 0x8017C1F8: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8017C1FC: jal         0x8017C4D8
    // 0x8017C200: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C4D8_12C2F0(rdram, ctx);
        goto after_2;
    // 0x8017C200: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x8017C204: b           L_8017C28C
    // 0x8017C208: nop

        goto L_8017C28C;
    // 0x8017C208: nop

L_8017C20C:
    // 0x8017C20C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C210: addiu       $t5, $t5, 0x3988
    ctx->r13 = ADD32(ctx->r13, 0X3988);
    // 0x8017C214: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8017C218: jal         0x8017C378
    // 0x8017C21C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C378_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017C21C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_3:
    // 0x8017C220: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C224: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017C228: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8017C22C: jal         0x8017C4D8
    // 0x8017C230: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C4D8_12C2F0(rdram, ctx);
        goto after_4;
    // 0x8017C230: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_4:
    // 0x8017C234: b           L_8017C28C
    // 0x8017C238: nop

        goto L_8017C28C;
    // 0x8017C238: nop

L_8017C23C:
    // 0x8017C23C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C240: addiu       $t9, $t9, 0x3988
    ctx->r25 = ADD32(ctx->r25, 0X3988);
    // 0x8017C244: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8017C248: jal         0x8017C378
    // 0x8017C24C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C378_12C2F0(rdram, ctx);
        goto after_5;
    // 0x8017C24C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_5:
    // 0x8017C250: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C254: addiu       $t8, $t8, 0x3988
    ctx->r24 = ADD32(ctx->r24, 0X3988);
    // 0x8017C258: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x8017C25C: jal         0x8017C378
    // 0x8017C260: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_8017C378_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017C260: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_6:
    // 0x8017C264: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C268: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x8017C26C: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8017C270: jal         0x8017C4D8
    // 0x8017C274: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C4D8_12C2F0(rdram, ctx);
        goto after_7;
    // 0x8017C274: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_7:
    // 0x8017C278: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C27C: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x8017C280: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8017C284: jal         0x8017C4D8
    // 0x8017C288: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_8017C4D8_12C2F0(rdram, ctx);
        goto after_8;
    // 0x8017C288: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_8:
L_8017C28C:
    // 0x8017C28C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8017C290:
    // 0x8017C290: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017C294: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C298: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C29C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8017C2A0: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x8017C2A4: lw          $t5, 0x50($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X50);
    // 0x8017C2A8: beq         $t5, $zero, L_8017C2CC
    if (ctx->r13 == 0) {
        // 0x8017C2AC: nop
    
            goto L_8017C2CC;
    }
    // 0x8017C2AC: nop

    // 0x8017C2B0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8017C2B4: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C2B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C2BC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017C2C0: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8017C2C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017C2C8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
L_8017C2CC:
    // 0x8017C2CC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8017C2D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C2D4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C2D8: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8017C2DC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017C2E0: lw          $t7, 0x78($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X78);
    // 0x8017C2E4: beq         $t7, $zero, L_8017C308
    if (ctx->r15 == 0) {
        // 0x8017C2E8: nop
    
            goto L_8017C308;
    }
    // 0x8017C2E8: nop

    // 0x8017C2EC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8017C2F0: addu        $t1, $t6, $t4
    ctx->r9 = ADD32(ctx->r14, ctx->r12);
    // 0x8017C2F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C2F8: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C2FC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8017C300: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017C304: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_8017C308:
    // 0x8017C308: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8017C30C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017C310: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x8017C314: bne         $at, $zero, L_8017C290
    if (ctx->r1 != 0) {
        // 0x8017C318: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_8017C290;
    }
    // 0x8017C318: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8017C31C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8017C320:
    // 0x8017C320: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8017C324: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017C328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C32C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C330: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8017C334: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017C338: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C33C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8017C340: addu        $t1, $t4, $t0
    ctx->r9 = ADD32(ctx->r12, ctx->r8);
    // 0x8017C344: sw          $zero, 0x3C78($at)
    MEM_W(0X3C78, ctx->r1) = 0;
    // 0x8017C348: lw          $t9, 0x78($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X78);
    // 0x8017C34C: sw          $t9, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->r25;
    // 0x8017C350: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8017C354: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8017C358: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x8017C35C: bne         $at, $zero, L_8017C320
    if (ctx->r1 != 0) {
        // 0x8017C360: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_8017C320;
    }
    // 0x8017C360: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8017C364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017C368: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8017C36C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017C370: jr          $ra
    // 0x8017C374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8017C374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8017C378_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C37C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017C384: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017C388: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8017C38C:
    // 0x8017C38C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C390: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C394: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8017C398: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8017C39C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C3A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C3A4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017C3A8: lw          $t8, 0x3A38($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3A38);
    // 0x8017C3AC: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x8017C3B0: bne         $at, $zero, L_8017C4B4
    if (ctx->r1 != 0) {
        // 0x8017C3B4: nop
    
            goto L_8017C4B4;
    }
    // 0x8017C3B4: nop

    // 0x8017C3B8: xori        $t0, $t6, 0x4
    ctx->r8 = ctx->r14 ^ 0X4;
    // 0x8017C3BC: sltu        $t0, $zero, $t0
    ctx->r8 = 0 < ctx->r8 ? 1 : 0;
    // 0x8017C3C0: beq         $t0, $zero, L_8017C450
    if (ctx->r8 == 0) {
        // 0x8017C3C4: nop
    
            goto L_8017C450;
    }
    // 0x8017C3C4: nop

    // 0x8017C3C8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017C3CC: beq         $t0, $zero, L_8017C450
    if (ctx->r8 == 0) {
        // 0x8017C3D0: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_8017C450;
    }
    // 0x8017C3D0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_8017C3D4:
    // 0x8017C3D4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8017C3D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C3DC: addiu       $t4, $t4, 0x3A20
    ctx->r12 = ADD32(ctx->r12, 0X3A20);
    // 0x8017C3E0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8017C3E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017C3E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C3EC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017C3F0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8017C3F4: jal         0x800E4C90
    // 0x8017C3F8: addiu       $a1, $t5, -0x24
    ctx->r5 = ADD32(ctx->r13, -0X24);
    func_800E4C90(rdram, ctx);
        goto after_0;
    // 0x8017C3F8: addiu       $a1, $t5, -0x24
    ctx->r5 = ADD32(ctx->r13, -0X24);
    after_0:
    // 0x8017C3FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017C400: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C404: addiu       $t9, $t9, 0x3A20
    ctx->r25 = ADD32(ctx->r25, 0X3A20);
    // 0x8017C408: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8017C40C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017C410: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017C414: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8017C418: lw          $t1, -0xC($t6)
    ctx->r9 = MEM_W(ctx->r14, -0XC);
    // 0x8017C41C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C420: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017C424: sw          $t1, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r9;
    // 0x8017C428: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017C42C: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8017C430: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017C434: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x8017C438: sw          $t5, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r13;
    // 0x8017C43C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017C440: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C444: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8017C448: bne         $t8, $t9, L_8017C3D4
    if (ctx->r24 != ctx->r25) {
        // 0x8017C44C: sw          $t8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r24;
            goto L_8017C3D4;
    }
    // 0x8017C44C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8017C450:
    // 0x8017C450: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C454: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C458: addiu       $t0, $t0, 0x3A20
    ctx->r8 = ADD32(ctx->r8, 0X3A20);
    // 0x8017C45C: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x8017C460: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8017C464: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C468: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017C46C: addiu       $a1, $a1, -0x2990
    ctx->r5 = ADD32(ctx->r5, -0X2990);
    // 0x8017C470: jal         0x800E4C90
    // 0x8017C474: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    func_800E4C90(rdram, ctx);
        goto after_1;
    // 0x8017C474: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    after_1:
    // 0x8017C478: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C47C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8017C480: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C484: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8017C488: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017C48C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C494: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017C498: sw          $t2, 0x3A38($at)
    MEM_W(0X3A38, ctx->r1) = ctx->r10;
    // 0x8017C49C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017C4A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C4A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017C4A8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017C4AC: b           L_8017C4C8
    // 0x8017C4B0: sw          $t4, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r12;
        goto L_8017C4C8;
    // 0x8017C4B0: sw          $t4, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = ctx->r12;
L_8017C4B4:
    // 0x8017C4B4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C4B8: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8017C4BC: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x8017C4C0: bne         $at, $zero, L_8017C38C
    if (ctx->r1 != 0) {
        // 0x8017C4C4: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8017C38C;
    }
    // 0x8017C4C4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_8017C4C8:
    // 0x8017C4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C4CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C4D0: jr          $ra
    // 0x8017C4D4: nop

    return;
    // 0x8017C4D4: nop

;}
RECOMP_FUNC void func_8017C4D8_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C4D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017C4DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017C4E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017C4E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C4E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017C4EC: beq         $t6, $zero, L_8017C708
    if (ctx->r14 == 0) {
        // 0x8017C4F0: nop
    
            goto L_8017C708;
    }
    // 0x8017C4F0: nop

    // 0x8017C4F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C4F8: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017C4FC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017C500: beq         $t8, $zero, L_8017C708
    if (ctx->r24 == 0) {
        // 0x8017C504: nop
    
            goto L_8017C708;
    }
    // 0x8017C504: nop

    // 0x8017C508: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017C50C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C510: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8017C514: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017C518: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017C51C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017C520: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8017C524: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017C528: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C52C: divu        $zero, $t0, $t2
    lo = S32(U32(ctx->r8) / U32(ctx->r10)); hi = S32(U32(ctx->r8) % U32(ctx->r10));
    // 0x8017C530: mflo        $t3
    ctx->r11 = lo;
    // 0x8017C534: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8017C538: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8017C53C: bne         $t2, $zero, L_8017C548
    if (ctx->r10 != 0) {
        // 0x8017C540: nop
    
            goto L_8017C548;
    }
    // 0x8017C540: nop

    // 0x8017C544: break       7
    do_break(2149041476);
L_8017C548:
    // 0x8017C548: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017C54C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C550: addiu       $t6, $t6, 0x3A20
    ctx->r14 = ADD32(ctx->r14, 0X3A20);
    // 0x8017C554: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8017C558: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017C55C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C560: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017C564: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8017C568: lw          $t1, 0x1C($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X1C);
    // 0x8017C56C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C570: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017C574: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017C578: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8017C57C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017C580: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C584: divu        $zero, $t9, $t1
    lo = S32(U32(ctx->r25) / U32(ctx->r9)); hi = S32(U32(ctx->r25) % U32(ctx->r9));
    // 0x8017C588: mflo        $t0
    ctx->r8 = lo;
    // 0x8017C58C: sltu        $at, $t2, $t0
    ctx->r1 = ctx->r10 < ctx->r8 ? 1 : 0;
    // 0x8017C590: bne         $t1, $zero, L_8017C59C
    if (ctx->r9 != 0) {
        // 0x8017C594: nop
    
            goto L_8017C59C;
    }
    // 0x8017C594: nop

    // 0x8017C598: break       7
    do_break(2149041560);
L_8017C59C:
    // 0x8017C59C: bne         $at, $zero, L_8017C6F4
    if (ctx->r1 != 0) {
        // 0x8017C5A0: nop
    
            goto L_8017C6F4;
    }
    // 0x8017C5A0: nop

    // 0x8017C5A4: xori        $t3, $t4, 0x4
    ctx->r11 = ctx->r12 ^ 0X4;
    // 0x8017C5A8: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x8017C5AC: beq         $t3, $zero, L_8017C664
    if (ctx->r11 == 0) {
        // 0x8017C5B0: nop
    
            goto L_8017C664;
    }
    // 0x8017C5B0: nop

    // 0x8017C5B4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017C5B8: beq         $t3, $zero, L_8017C664
    if (ctx->r11 == 0) {
        // 0x8017C5BC: sw          $t5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r13;
            goto L_8017C664;
    }
    // 0x8017C5BC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_8017C5C0:
    // 0x8017C5C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017C5C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C5C8: addiu       $t9, $t9, 0x3A20
    ctx->r25 = ADD32(ctx->r25, 0X3A20);
    // 0x8017C5CC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8017C5D0: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017C5D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017C5D8: addiu       $t7, $t8, 0xC
    ctx->r15 = ADD32(ctx->r24, 0XC);
    // 0x8017C5DC: addiu       $t1, $t8, -0x18
    ctx->r9 = ADD32(ctx->r24, -0X18);
    // 0x8017C5E0: addu        $a1, $t1, $t9
    ctx->r5 = ADD32(ctx->r9, ctx->r25);
    // 0x8017C5E4: jal         0x800E4C90
    // 0x8017C5E8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    func_800E4C90(rdram, ctx);
        goto after_0;
    // 0x8017C5E8: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x8017C5EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017C5F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C5F4: addiu       $t4, $t4, 0x3A20
    ctx->r12 = ADD32(ctx->r12, 0X3A20);
    // 0x8017C5F8: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8017C5FC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8017C600: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017C604: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8017C608: lw          $t3, -0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, -0X8);
    // 0x8017C60C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C610: addiu       $t8, $t8, 0x3A20
    ctx->r24 = ADD32(ctx->r24, 0X3A20);
    // 0x8017C614: sw          $t3, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r11;
    // 0x8017C618: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017C61C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C620: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C624: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8017C628: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C62C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C630: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C634: lw          $t9, -0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X4);
    // 0x8017C638: sw          $t9, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r25;
    // 0x8017C63C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017C640: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8017C644: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8017C648: lw          $t5, 0x74($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X74);
    // 0x8017C64C: sw          $t5, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r13;
    // 0x8017C650: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017C654: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8017C658: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017C65C: bne         $t7, $t8, L_8017C5C0
    if (ctx->r15 != ctx->r24) {
        // 0x8017C660: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_8017C5C0;
    }
    // 0x8017C660: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8017C664:
    // 0x8017C664: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017C668: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C66C: addiu       $t2, $t2, 0x3A20
    ctx->r10 = ADD32(ctx->r10, 0X3A20);
    // 0x8017C670: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8017C674: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8017C678: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C67C: addiu       $t0, $t1, 0xC
    ctx->r8 = ADD32(ctx->r9, 0XC);
    // 0x8017C680: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017C684: addiu       $a1, $a1, -0x2984
    ctx->r5 = ADD32(ctx->r5, -0X2984);
    // 0x8017C688: jal         0x800E4C90
    // 0x8017C68C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    func_800E4C90(rdram, ctx);
        goto after_1;
    // 0x8017C68C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    after_1:
    // 0x8017C690: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017C694: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C698: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8017C69C: addiu       $t4, $t4, 0x3988
    ctx->r12 = ADD32(ctx->r12, 0X3988);
    // 0x8017C6A0: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x8017C6A4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8017C6A8: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x8017C6AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C6B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C6B4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017C6B8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8017C6BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8017C6C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017C6C4: sw          $t5, 0x3A3C($at)
    MEM_W(0X3A3C, ctx->r1) = ctx->r13;
    // 0x8017C6C8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017C6CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C6D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C6D4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017C6D8: sw          $t7, 0x3A40($at)
    MEM_W(0X3A40, ctx->r1) = ctx->r15;
    // 0x8017C6DC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C6E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C6E4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8017C6E8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017C6EC: b           L_8017C708
    // 0x8017C6F0: sw          $t1, 0x3C78($at)
    MEM_W(0X3C78, ctx->r1) = ctx->r9;
        goto L_8017C708;
    // 0x8017C6F0: sw          $t1, 0x3C78($at)
    MEM_W(0X3C78, ctx->r1) = ctx->r9;
L_8017C6F4:
    // 0x8017C6F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017C6F8: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8017C6FC: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x8017C700: bne         $at, $zero, L_8017C548
    if (ctx->r1 != 0) {
        // 0x8017C704: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8017C548;
    }
    // 0x8017C704: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8017C708:
    // 0x8017C708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C70C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017C710: jr          $ra
    // 0x8017C714: nop

    return;
    // 0x8017C714: nop

;}
RECOMP_FUNC void func_8017C718_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C718: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C71C: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017C720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C728: bne         $t6, $zero, L_8017C864
    if (ctx->r14 != 0) {
        // 0x8017C72C: nop
    
            goto L_8017C864;
    }
    // 0x8017C72C: nop

    // 0x8017C730: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017C734: lhu         $t7, -0x4530($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X4530);
    // 0x8017C738: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8017C73C: bne         $t8, $zero, L_8017C864
    if (ctx->r24 != 0) {
        // 0x8017C740: nop
    
            goto L_8017C864;
    }
    // 0x8017C740: nop

    // 0x8017C744: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C748: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017C74C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8017C750: bne         $t0, $zero, L_8017C7C8
    if (ctx->r8 != 0) {
        // 0x8017C754: nop
    
            goto L_8017C7C8;
    }
    // 0x8017C754: nop

    // 0x8017C758: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C75C: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017C760: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8017C764: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x8017C768: beq         $t3, $zero, L_8017C788
    if (ctx->r11 == 0) {
        // 0x8017C76C: nop
    
            goto L_8017C788;
    }
    // 0x8017C76C: nop

    // 0x8017C770: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8017C774: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C778: jal         0x800C32CC
    // 0x8017C77C: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x8017C77C: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    after_0:
    // 0x8017C780: b           L_8017C864
    // 0x8017C784: nop

        goto L_8017C864;
    // 0x8017C784: nop

L_8017C788:
    // 0x8017C788: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C78C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017C790: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8017C794: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C798: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C79C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017C7A0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8017C7A4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8017C7A8: bne         $t9, $zero, L_8017C864
    if (ctx->r25 != 0) {
        // 0x8017C7AC: nop
    
            goto L_8017C864;
    }
    // 0x8017C7AC: nop

    // 0x8017C7B0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8017C7B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C7B8: jal         0x800C32CC
    // 0x8017C7BC: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    func_800C32CC(rdram, ctx);
        goto after_1;
    // 0x8017C7BC: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    after_1:
    // 0x8017C7C0: b           L_8017C864
    // 0x8017C7C4: nop

        goto L_8017C864;
    // 0x8017C7C4: nop

L_8017C7C8:
    // 0x8017C7C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C7CC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017C7D0: lw          $t2, 0xA4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XA4);
    // 0x8017C7D4: lw          $t3, 0xA0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XA0);
    // 0x8017C7D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017C7DC: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8017C7E0: beq         $t4, $at, L_8017C7F4
    if (ctx->r12 == ctx->r1) {
        // 0x8017C7E4: nop
    
            goto L_8017C7F4;
    }
    // 0x8017C7E4: nop

    // 0x8017C7E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C7EC: jal         0x8017C874
    // 0x8017C7F0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8017C874_12C2F0(rdram, ctx);
        goto after_2;
    // 0x8017C7F0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
L_8017C7F4:
    // 0x8017C7F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C7F8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C7FC: lw          $t7, 0xCC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XCC);
    // 0x8017C800: lw          $t5, 0xC8($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC8);
    // 0x8017C804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017C808: and         $t8, $t7, $t5
    ctx->r24 = ctx->r15 & ctx->r13;
    // 0x8017C80C: beq         $t8, $at, L_8017C820
    if (ctx->r24 == ctx->r1) {
        // 0x8017C810: nop
    
            goto L_8017C820;
    }
    // 0x8017C810: nop

    // 0x8017C814: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017C818: jal         0x8017C874
    // 0x8017C81C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_8017C874_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017C81C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_3:
L_8017C820:
    // 0x8017C820: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C824: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017C828: lw          $t0, 0xA0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XA0);
    // 0x8017C82C: lw          $t1, 0xA4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XA4);
    // 0x8017C830: lw          $t3, 0xC8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC8);
    // 0x8017C834: lw          $t6, 0xCC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XCC);
    // 0x8017C838: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8017C83C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8017C840: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017C844: and         $t7, $t6, $t4
    ctx->r15 = ctx->r14 & ctx->r12;
    // 0x8017C848: bne         $t7, $at, L_8017C864
    if (ctx->r15 != ctx->r1) {
        // 0x8017C84C: nop
    
            goto L_8017C864;
    }
    // 0x8017C84C: nop

    // 0x8017C850: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8017C854: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C858: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017C85C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8017C860: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_8017C864:
    // 0x8017C864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C86C: jr          $ra
    // 0x8017C870: nop

    return;
    // 0x8017C870: nop

;}
RECOMP_FUNC void func_8017C874_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017C878: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017C87C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017C880: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C888: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017C88C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C890: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8017C894: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017C898: lhu         $t8, -0x41DE($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X41DE);
    // 0x8017C89C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017C8A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017C8A4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8017C8A8: beq         $t9, $zero, L_8017CA84
    if (ctx->r25 == 0) {
        // 0x8017C8AC: nop
    
            goto L_8017CA84;
    }
    // 0x8017C8AC: nop

    // 0x8017C8B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C8B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C8B8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8017C8BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017C8C0: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x8017C8C4: lw          $s0, 0x3C0C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3C0C);
    // 0x8017C8C8: beq         $s0, $at, L_8017C8E8
    if (ctx->r16 == ctx->r1) {
        // 0x8017C8CC: addiu       $at, $zero, 0x3A
        ctx->r1 = ADD32(0, 0X3A);
            goto L_8017C8E8;
    }
    // 0x8017C8CC: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x8017C8D0: beq         $s0, $at, L_8017C920
    if (ctx->r16 == ctx->r1) {
        // 0x8017C8D4: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_8017C920;
    }
    // 0x8017C8D4: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x8017C8D8: beq         $s0, $at, L_8017C95C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C8DC: nop
    
            goto L_8017C95C;
    }
    // 0x8017C8DC: nop

    // 0x8017C8E0: b           L_8017C9A0
    // 0x8017C8E4: nop

        goto L_8017C9A0;
    // 0x8017C8E4: nop

L_8017C8E8:
    // 0x8017C8E8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C8EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C8F0: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017C8F4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017C8F8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017C8FC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8017C900: beq         $t6, $zero, L_8017C910
    if (ctx->r14 == 0) {
        // 0x8017C904: nop
    
            goto L_8017C910;
    }
    // 0x8017C904: nop

    // 0x8017C908: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017C90C: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
L_8017C910:
    // 0x8017C910: jal         0x800C8544
    // 0x8017C914: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017C914: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
    // 0x8017C918: b           L_8017CFD8
    // 0x8017C91C: nop

        goto L_8017CFD8;
    // 0x8017C91C: nop

L_8017C920:
    // 0x8017C920: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C924: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C928: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017C92C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017C930: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017C934: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8017C938: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017C93C: beq         $t2, $at, L_8017C94C
    if (ctx->r10 == ctx->r1) {
        // 0x8017C940: nop
    
            goto L_8017C94C;
    }
    // 0x8017C940: nop

    // 0x8017C944: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017C948: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
L_8017C94C:
    // 0x8017C94C: jal         0x800C8544
    // 0x8017C950: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017C950: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x8017C954: b           L_8017CFD8
    // 0x8017C958: nop

        goto L_8017CFD8;
    // 0x8017C958: nop

L_8017C95C:
    // 0x8017C95C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C960: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C964: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C968: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C96C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017C970: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017C974: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017C978: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8017C97C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8017C980: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017C984: sw          $t4, 0x3C04($at)
    MEM_W(0X3C04, ctx->r1) = ctx->r12;
    // 0x8017C988: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8017C98C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8017C990: jal         0x800C8544
    // 0x8017C994: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017C994: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    after_2:
    // 0x8017C998: b           L_8017CFD8
    // 0x8017C99C: nop

        goto L_8017CFD8;
    // 0x8017C99C: nop

L_8017C9A0:
    // 0x8017C9A0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C9A8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017C9AC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8017C9B0: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8017C9B4: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8017C9B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017C9BC: beq         $t7, $at, L_8017C9F4
    if (ctx->r15 == ctx->r1) {
        // 0x8017C9C0: nop
    
            goto L_8017C9F4;
    }
    // 0x8017C9C0: nop

    // 0x8017C9C4: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8017C9C8: lw          $t2, 0x8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X8);
    // 0x8017C9CC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8017C9D0: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8017C9D4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8017C9D8: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8017C9DC: lbu         $t8, -0x29D0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X29D0);
    // 0x8017C9E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C9E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C9E8: addu        $t0, $t9, $t2
    ctx->r8 = ADD32(ctx->r25, ctx->r10);
    // 0x8017C9EC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017C9F0: sb          $t8, 0x3A20($at)
    MEM_B(0X3A20, ctx->r1) = ctx->r24;
L_8017C9F4:
    // 0x8017C9F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C9FC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CA00: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8017CA04: addu        $t5, $t1, $t6
    ctx->r13 = ADD32(ctx->r9, ctx->r14);
    // 0x8017CA08: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x8017CA0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017CA10: beq         $t7, $at, L_8017CA48
    if (ctx->r15 == ctx->r1) {
        // 0x8017CA14: nop
    
            goto L_8017CA48;
    }
    // 0x8017CA14: nop

    // 0x8017CA18: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x8017CA1C: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8017CA20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8017CA24: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x8017CA28: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8017CA2C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8017CA30: lbu         $t9, -0x29D0($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X29D0);
    // 0x8017CA34: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017CA38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CA3C: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x8017CA40: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017CA44: sb          $t9, 0x3A2C($at)
    MEM_B(0X3A2C, ctx->r1) = ctx->r25;
L_8017CA48:
    // 0x8017CA48: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CA4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CA50: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CA54: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8017CA58: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8017CA5C: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x8017CA60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017CA64: beq         $t7, $at, L_8017CA74
    if (ctx->r15 == ctx->r1) {
        // 0x8017CA68: nop
    
            goto L_8017CA74;
    }
    // 0x8017CA68: nop

    // 0x8017CA6C: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8017CA70: sw          $t5, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r13;
L_8017CA74:
    // 0x8017CA74: jal         0x800C8544
    // 0x8017CA78: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017CA78: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x8017CA7C: b           L_8017CFD8
    // 0x8017CA80: nop

        goto L_8017CFD8;
    // 0x8017CA80: nop

L_8017CA84:
    // 0x8017CA84: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8017CA88: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CA8C: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8017CA90: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8017CA94: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8017CA98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017CA9C: lhu         $t9, -0x41DE($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41DE);
    // 0x8017CAA0: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x8017CAA4: beq         $t0, $zero, L_8017CAE4
    if (ctx->r8 == 0) {
        // 0x8017CAA8: nop
    
            goto L_8017CAE4;
    }
    // 0x8017CAA8: nop

    // 0x8017CAAC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CAB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CAB4: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CAB8: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x8017CABC: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8017CAC0: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x8017CAC4: beq         $t5, $zero, L_8017CAD4
    if (ctx->r13 == 0) {
        // 0x8017CAC8: nop
    
            goto L_8017CAD4;
    }
    // 0x8017CAC8: nop

    // 0x8017CACC: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x8017CAD0: sw          $t4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r12;
L_8017CAD4:
    // 0x8017CAD4: jal         0x800C8544
    // 0x8017CAD8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017CAD8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
    // 0x8017CADC: b           L_8017CFD8
    // 0x8017CAE0: nop

        goto L_8017CFD8;
    // 0x8017CAE0: nop

L_8017CAE4:
    // 0x8017CAE4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CAE8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CAEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017CAF0: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8017CAF4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017CAF8: lw          $t9, 0x3C24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3C24);
    // 0x8017CAFC: bne         $t9, $at, L_8017CB74
    if (ctx->r25 != ctx->r1) {
        // 0x8017CB00: nop
    
            goto L_8017CB74;
    }
    // 0x8017CB00: nop

    // 0x8017CB04: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8017CB08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CB0C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8017CB10: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8017CB14: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8017CB18: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8017CB1C: jal         0x800E4D30
    // 0x8017CB20: lb          $a0, -0x41DA($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41DA);
    func_800E4D30(rdram, ctx);
        goto after_5;
    // 0x8017CB20: lb          $a0, -0x41DA($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41DA);
    after_5:
    // 0x8017CB24: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8017CB28: beq         $at, $zero, L_8017CFD8
    if (ctx->r1 == 0) {
        // 0x8017CB2C: nop
    
            goto L_8017CFD8;
    }
    // 0x8017CB2C: nop

    // 0x8017CB30: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017CB34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017CB38: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8017CB3C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8017CB40: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8017CB44: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8017CB48: jal         0x800E4D30
    // 0x8017CB4C: lb          $a0, -0x41D9($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41D9);
    func_800E4D30(rdram, ctx);
        goto after_6;
    // 0x8017CB4C: lb          $a0, -0x41D9($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41D9);
    after_6:
    // 0x8017CB50: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8017CB54: beq         $at, $zero, L_8017CFD8
    if (ctx->r1 == 0) {
        // 0x8017CB58: nop
    
            goto L_8017CFD8;
    }
    // 0x8017CB58: nop

    // 0x8017CB5C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CB64: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8017CB68: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017CB6C: b           L_8017CFD8
    // 0x8017CB70: sw          $zero, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = 0;
        goto L_8017CFD8;
    // 0x8017CB70: sw          $zero, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = 0;
L_8017CB74:
    // 0x8017CB74: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8017CB78: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CB7C: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8017CB80: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8017CB84: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8017CB88: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8017CB8C: lb          $t8, -0x41DA($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X41DA);
    // 0x8017CB90: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x8017CB94: bne         $at, $zero, L_8017CC14
    if (ctx->r1 != 0) {
        // 0x8017CB98: nop
    
            goto L_8017CC14;
    }
    // 0x8017CB98: nop

    // 0x8017CB9C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CBA0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CBA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CBA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CBAC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8017CBB0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017CBB4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017CBB8: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017CBBC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8017CBC0: sw          $t9, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = ctx->r25;
    // 0x8017CBC4: addu        $t4, $t6, $t5
    ctx->r12 = ADD32(ctx->r14, ctx->r13);
    // 0x8017CBC8: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x8017CBCC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017CBD0: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x8017CBD4: mfhi        $t2
    ctx->r10 = hi;
    // 0x8017CBD8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017CBDC: bne         $t2, $at, L_8017CBF0
    if (ctx->r10 != ctx->r1) {
        // 0x8017CBE0: nop
    
            goto L_8017CBF0;
    }
    // 0x8017CBE0: nop

    // 0x8017CBE4: addiu       $t8, $t7, -0xB
    ctx->r24 = ADD32(ctx->r15, -0XB);
    // 0x8017CBE8: b           L_8017CFD8
    // 0x8017CBEC: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
        goto L_8017CFD8;
    // 0x8017CBEC: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
L_8017CBF0:
    // 0x8017CBF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CBF4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CBF8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017CBFC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8017CC00: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8017CC04: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x8017CC08: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8017CC0C: b           L_8017CFD8
    // 0x8017CC10: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
        goto L_8017CFD8;
    // 0x8017CC10: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
L_8017CC14:
    // 0x8017CC14: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8017CC18: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CC1C: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8017CC20: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x8017CC24: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8017CC28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017CC2C: lhu         $t8, -0x41DC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X41DC);
    // 0x8017CC30: andi        $t4, $t8, 0x100
    ctx->r12 = ctx->r24 & 0X100;
    // 0x8017CC34: beq         $t4, $zero, L_8017CC9C
    if (ctx->r12 == 0) {
        // 0x8017CC38: nop
    
            goto L_8017CC9C;
    }
    // 0x8017CC38: nop

    // 0x8017CC3C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CC40: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CC44: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017CC48: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8017CC4C: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x8017CC50: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x8017CC54: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017CC58: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x8017CC5C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8017CC60: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017CC64: bne         $t1, $at, L_8017CC78
    if (ctx->r9 != ctx->r1) {
        // 0x8017CC68: nop
    
            goto L_8017CC78;
    }
    // 0x8017CC68: nop

    // 0x8017CC6C: addiu       $t2, $t5, -0xB
    ctx->r10 = ADD32(ctx->r13, -0XB);
    // 0x8017CC70: b           L_8017CFD8
    // 0x8017CC74: sw          $t2, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r10;
        goto L_8017CFD8;
    // 0x8017CC74: sw          $t2, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r10;
L_8017CC78:
    // 0x8017CC78: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CC7C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CC80: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017CC84: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017CC88: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x8017CC8C: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8017CC90: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x8017CC94: b           L_8017CFD8
    // 0x8017CC98: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
        goto L_8017CFD8;
    // 0x8017CC98: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
L_8017CC9C:
    // 0x8017CC9C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017CCA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CCA4: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x8017CCA8: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x8017CCAC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8017CCB0: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8017CCB4: lb          $t2, -0x41DA($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X41DA);
    // 0x8017CCB8: slti        $at, $t2, -0xE
    ctx->r1 = SIGNED(ctx->r10) < -0XE ? 1 : 0;
    // 0x8017CCBC: beq         $at, $zero, L_8017CD38
    if (ctx->r1 == 0) {
        // 0x8017CCC0: nop
    
            goto L_8017CD38;
    }
    // 0x8017CCC0: nop

    // 0x8017CCC4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CCC8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CCCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CCD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CCD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017CCD8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017CCDC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8017CCE0: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017CCE4: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8017CCE8: sw          $t6, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = ctx->r14;
    // 0x8017CCEC: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x8017CCF0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8017CCF4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017CCF8: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x8017CCFC: mfhi        $t5
    ctx->r13 = hi;
    // 0x8017CD00: bne         $t5, $zero, L_8017CD14
    if (ctx->r13 != 0) {
        // 0x8017CD04: nop
    
            goto L_8017CD14;
    }
    // 0x8017CD04: nop

    // 0x8017CD08: addiu       $t2, $t1, 0xB
    ctx->r10 = ADD32(ctx->r9, 0XB);
    // 0x8017CD0C: b           L_8017CFD8
    // 0x8017CD10: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
        goto L_8017CFD8;
    // 0x8017CD10: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
L_8017CD14:
    // 0x8017CD14: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CD18: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CD1C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017CD20: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8017CD24: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8017CD28: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x8017CD2C: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8017CD30: b           L_8017CFD8
    // 0x8017CD34: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
        goto L_8017CFD8;
    // 0x8017CD34: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
L_8017CD38:
    // 0x8017CD38: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8017CD3C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CD40: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8017CD44: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8017CD48: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8017CD4C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017CD50: lhu         $t2, -0x41DC($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41DC);
    // 0x8017CD54: andi        $t0, $t2, 0x200
    ctx->r8 = ctx->r10 & 0X200;
    // 0x8017CD58: beq         $t0, $zero, L_8017CDBC
    if (ctx->r8 == 0) {
        // 0x8017CD5C: nop
    
            goto L_8017CDBC;
    }
    // 0x8017CD5C: nop

    // 0x8017CD60: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CD64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CD68: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017CD6C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8017CD70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8017CD74: lw          $t3, 0xC($t9)
    ctx->r11 = MEM_W(ctx->r25, 0XC);
    // 0x8017CD78: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017CD7C: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x8017CD80: mfhi        $t4
    ctx->r12 = hi;
    // 0x8017CD84: bne         $t4, $zero, L_8017CD98
    if (ctx->r12 != 0) {
        // 0x8017CD88: nop
    
            goto L_8017CD98;
    }
    // 0x8017CD88: nop

    // 0x8017CD8C: addiu       $t5, $t3, 0xB
    ctx->r13 = ADD32(ctx->r11, 0XB);
    // 0x8017CD90: b           L_8017CFD8
    // 0x8017CD94: sw          $t5, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r13;
        goto L_8017CFD8;
    // 0x8017CD94: sw          $t5, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r13;
L_8017CD98:
    // 0x8017CD98: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CD9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CDA0: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017CDA4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017CDA8: addu        $t7, $t2, $t0
    ctx->r15 = ADD32(ctx->r10, ctx->r8);
    // 0x8017CDAC: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x8017CDB0: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8017CDB4: b           L_8017CFD8
    // 0x8017CDB8: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
        goto L_8017CFD8;
    // 0x8017CDB8: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
L_8017CDBC:
    // 0x8017CDBC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8017CDC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CDC4: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8017CDC8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8017CDCC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8017CDD0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017CDD4: lb          $t5, -0x41D9($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41D9);
    // 0x8017CDD8: slti        $at, $t5, -0xE
    ctx->r1 = SIGNED(ctx->r13) < -0XE ? 1 : 0;
    // 0x8017CDDC: beq         $at, $zero, L_8017CE50
    if (ctx->r1 == 0) {
        // 0x8017CDE0: nop
    
            goto L_8017CE50;
    }
    // 0x8017CDE0: nop

    // 0x8017CDE4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CDE8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CDEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CDF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CDF4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017CDF8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017CDFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017CE00: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017CE04: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8017CE08: sw          $t9, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = ctx->r25;
    // 0x8017CE0C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8017CE10: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x8017CE14: sltiu       $at, $t4, 0x30
    ctx->r1 = ctx->r12 < 0X30 ? 1 : 0;
    // 0x8017CE18: bne         $at, $zero, L_8017CE2C
    if (ctx->r1 != 0) {
        // 0x8017CE1C: nop
    
            goto L_8017CE2C;
    }
    // 0x8017CE1C: nop

    // 0x8017CE20: addiu       $t3, $t4, -0x30
    ctx->r11 = ADD32(ctx->r12, -0X30);
    // 0x8017CE24: b           L_8017CFD8
    // 0x8017CE28: sw          $t3, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r11;
        goto L_8017CFD8;
    // 0x8017CE28: sw          $t3, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r11;
L_8017CE2C:
    // 0x8017CE2C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CE30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CE34: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017CE38: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8017CE3C: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8017CE40: lw          $t0, 0xC($t2)
    ctx->r8 = MEM_W(ctx->r10, 0XC);
    // 0x8017CE44: addiu       $t6, $t0, 0xC
    ctx->r14 = ADD32(ctx->r8, 0XC);
    // 0x8017CE48: b           L_8017CFD8
    // 0x8017CE4C: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
        goto L_8017CFD8;
    // 0x8017CE4C: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
L_8017CE50:
    // 0x8017CE50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8017CE54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CE58: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8017CE5C: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8017CE60: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8017CE64: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8017CE68: lhu         $t3, -0x41DC($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X41DC);
    // 0x8017CE6C: andi        $t7, $t3, 0x400
    ctx->r15 = ctx->r11 & 0X400;
    // 0x8017CE70: beq         $t7, $zero, L_8017CECC
    if (ctx->r15 == 0) {
        // 0x8017CE74: nop
    
            goto L_8017CECC;
    }
    // 0x8017CE74: nop

    // 0x8017CE78: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CE7C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CE80: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017CE84: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8017CE88: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x8017CE8C: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8017CE90: sltiu       $at, $t6, 0x30
    ctx->r1 = ctx->r14 < 0X30 ? 1 : 0;
    // 0x8017CE94: bne         $at, $zero, L_8017CEA8
    if (ctx->r1 != 0) {
        // 0x8017CE98: nop
    
            goto L_8017CEA8;
    }
    // 0x8017CE98: nop

    // 0x8017CE9C: addiu       $t2, $t6, -0x30
    ctx->r10 = ADD32(ctx->r14, -0X30);
    // 0x8017CEA0: b           L_8017CFD8
    // 0x8017CEA4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
        goto L_8017CFD8;
    // 0x8017CEA4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
L_8017CEA8:
    // 0x8017CEA8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CEAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CEB0: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017CEB4: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8017CEB8: addu        $t7, $t4, $t3
    ctx->r15 = ADD32(ctx->r12, ctx->r11);
    // 0x8017CEBC: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8017CEC0: addiu       $t1, $t5, 0xC
    ctx->r9 = ADD32(ctx->r13, 0XC);
    // 0x8017CEC4: b           L_8017CFD8
    // 0x8017CEC8: sw          $t1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r9;
        goto L_8017CFD8;
    // 0x8017CEC8: sw          $t1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r9;
L_8017CECC:
    // 0x8017CECC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017CED0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CED4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8017CED8: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8017CEDC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8017CEE0: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017CEE4: lb          $t2, -0x41D9($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X41D9);
    // 0x8017CEE8: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x8017CEEC: bne         $at, $zero, L_8017CF60
    if (ctx->r1 != 0) {
        // 0x8017CEF0: nop
    
            goto L_8017CF60;
    }
    // 0x8017CEF0: nop

    // 0x8017CEF4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CEF8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CEFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017CF00: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CF04: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8017CF08: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017CF0C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8017CF10: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017CF14: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8017CF18: sw          $t0, 0x3C24($at)
    MEM_W(0X3C24, ctx->r1) = ctx->r8;
    // 0x8017CF1C: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x8017CF20: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8017CF24: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x8017CF28: beq         $at, $zero, L_8017CF3C
    if (ctx->r1 == 0) {
        // 0x8017CF2C: nop
    
            goto L_8017CF3C;
    }
    // 0x8017CF2C: nop

    // 0x8017CF30: addiu       $t6, $t9, 0x30
    ctx->r14 = ADD32(ctx->r25, 0X30);
    // 0x8017CF34: b           L_8017CFD8
    // 0x8017CF38: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
        goto L_8017CFD8;
    // 0x8017CF38: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
L_8017CF3C:
    // 0x8017CF3C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CF40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CF44: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017CF48: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8017CF4C: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x8017CF50: lw          $t3, 0xC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0XC);
    // 0x8017CF54: addiu       $t5, $t3, -0xC
    ctx->r13 = ADD32(ctx->r11, -0XC);
    // 0x8017CF58: b           L_8017CFD8
    // 0x8017CF5C: sw          $t5, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r13;
        goto L_8017CFD8;
    // 0x8017CF5C: sw          $t5, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r13;
L_8017CF60:
    // 0x8017CF60: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017CF64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CF68: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8017CF6C: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8017CF70: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8017CF74: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8017CF78: lhu         $t6, -0x41DC($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X41DC);
    // 0x8017CF7C: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8017CF80: beq         $t7, $zero, L_8017CFD8
    if (ctx->r15 == 0) {
        // 0x8017CF84: nop
    
            goto L_8017CFD8;
    }
    // 0x8017CF84: nop

    // 0x8017CF88: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CF8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CF90: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017CF94: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8017CF98: addu        $t3, $t8, $t0
    ctx->r11 = ADD32(ctx->r24, ctx->r8);
    // 0x8017CF9C: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x8017CFA0: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x8017CFA4: beq         $at, $zero, L_8017CFB8
    if (ctx->r1 == 0) {
        // 0x8017CFA8: nop
    
            goto L_8017CFB8;
    }
    // 0x8017CFA8: nop

    // 0x8017CFAC: addiu       $t4, $t5, 0x30
    ctx->r12 = ADD32(ctx->r13, 0X30);
    // 0x8017CFB0: b           L_8017CFD8
    // 0x8017CFB4: sw          $t4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r12;
        goto L_8017CFD8;
    // 0x8017CFB4: sw          $t4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r12;
L_8017CFB8:
    // 0x8017CFB8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CFBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CFC0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017CFC4: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8017CFC8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8017CFCC: lw          $t2, 0xC($t7)
    ctx->r10 = MEM_W(ctx->r15, 0XC);
    // 0x8017CFD0: addiu       $t8, $t2, -0xC
    ctx->r24 = ADD32(ctx->r10, -0XC);
    // 0x8017CFD4: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
L_8017CFD8:
    // 0x8017CFD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CFDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017CFE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017CFE4: jr          $ra
    // 0x8017CFE8: nop

    return;
    // 0x8017CFE8: nop

;}
RECOMP_FUNC void func_8017CFEC_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CFEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017CFF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017CFF4: jal         0x8017BB40
    // 0x8017CFF8: nop

    func_8017BB40_12C2F0(rdram, ctx);
        goto after_0;
    // 0x8017CFF8: nop

    after_0:
    // 0x8017CFFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D000: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D004: lw          $t7, 0xA0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA0);
    // 0x8017D008: lw          $t8, 0xA4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XA4);
    // 0x8017D00C: lw          $t0, 0xC8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC8);
    // 0x8017D010: lw          $t2, 0xCC($t6)
    ctx->r10 = MEM_W(ctx->r14, 0XCC);
    // 0x8017D014: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8017D018: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8017D01C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D020: and         $t3, $t2, $t1
    ctx->r11 = ctx->r10 & ctx->r9;
    // 0x8017D024: beq         $t3, $at, L_8017D228
    if (ctx->r11 == ctx->r1) {
        // 0x8017D028: nop
    
            goto L_8017D228;
    }
    // 0x8017D028: nop

    // 0x8017D02C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8017D030:
    // 0x8017D030: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8017D034:
    // 0x8017D034: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8017D038: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017D03C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8017D040: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8017D044: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8017D048: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D04C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8017D050: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017D054: lbu         $t9, -0x29D0($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X29D0);
    // 0x8017D058: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8017D05C: beq         $t9, $at, L_8017D0C0
    if (ctx->r25 == ctx->r1) {
        // 0x8017D060: nop
    
            goto L_8017D0C0;
    }
    // 0x8017D060: nop

    // 0x8017D064: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D068: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017D06C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D070: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8017D074: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017D078: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8017D07C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017D080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D084: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8017D088: sll         $t1, $a1, 4
    ctx->r9 = S32(ctx->r5 << 4);
    // 0x8017D08C: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x8017D090: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8017D094: sll         $t2, $a0, 5
    ctx->r10 = S32(ctx->r4 << 5);
    // 0x8017D098: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8017D09C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8017D0A0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D0A4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017D0A8: addiu       $a1, $a1, 0x10E
    ctx->r5 = ADD32(ctx->r5, 0X10E);
    // 0x8017D0AC: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    // 0x8017D0B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017D0B4: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D0B8: jal         0x8017BE28
    // 0x8017D0BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_1;
    // 0x8017D0BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
L_8017D0C0:
    // 0x8017D0C0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017D0C4: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8017D0C8: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8017D0CC: bne         $at, $zero, L_8017D034
    if (ctx->r1 != 0) {
        // 0x8017D0D0: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8017D034;
    }
    // 0x8017D0D0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8017D0D4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8017D0D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8017D0DC: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8017D0E0: bne         $at, $zero, L_8017D030
    if (ctx->r1 != 0) {
        // 0x8017D0E4: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_8017D030;
    }
    // 0x8017D0E4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8017D0E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D0EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D0F0: addiu       $a1, $a1, -0x2978
    ctx->r5 = ADD32(ctx->r5, -0X2978);
    // 0x8017D0F4: jal         0x800D87E4
    // 0x8017D0F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017D0F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x8017D0FC: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x8017D100: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D104: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017D108: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8017D10C: addiu       $a0, $zero, 0x184
    ctx->r4 = ADD32(0, 0X184);
    // 0x8017D110: addiu       $a1, $zero, 0x196
    ctx->r5 = ADD32(0, 0X196);
    // 0x8017D114: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D118: jal         0x8017BE28
    // 0x8017D11C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017D11C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8017D120: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D124: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D128: addiu       $a1, $a1, -0x2974
    ctx->r5 = ADD32(ctx->r5, -0X2974);
    // 0x8017D12C: jal         0x800D87E4
    // 0x8017D130: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8017D130: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
    // 0x8017D134: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8017D138: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017D13C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8017D140: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017D144: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x8017D148: addiu       $a1, $zero, 0x196
    ctx->r5 = ADD32(0, 0X196);
    // 0x8017D14C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017D150: jal         0x8017BE28
    // 0x8017D154: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_5;
    // 0x8017D154: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    after_5:
    // 0x8017D158: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D15C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017D160: lw          $t5, 0xA4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XA4);
    // 0x8017D164: lw          $t4, 0xA0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XA0);
    // 0x8017D168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D16C: and         $t7, $t5, $t4
    ctx->r15 = ctx->r13 & ctx->r12;
    // 0x8017D170: beq         $t7, $at, L_8017D1C0
    if (ctx->r15 == ctx->r1) {
        // 0x8017D174: nop
    
            goto L_8017D1C0;
    }
    // 0x8017D174: nop

    // 0x8017D178: jal         0x8017D238
    // 0x8017D17C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8017D238_12C2F0(rdram, ctx);
        goto after_6;
    // 0x8017D17C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
    // 0x8017D180: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D184: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017D188: lw          $t9, 0xA0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XA0);
    // 0x8017D18C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D190: beq         $t9, $at, L_8017D1A0
    if (ctx->r25 == ctx->r1) {
        // 0x8017D194: nop
    
            goto L_8017D1A0;
    }
    // 0x8017D194: nop

    // 0x8017D198: jal         0x8017D3A8
    // 0x8017D19C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8017D3A8_12C2F0(rdram, ctx);
        goto after_7;
    // 0x8017D19C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
L_8017D1A0:
    // 0x8017D1A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D1A4: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D1A8: lw          $t6, 0xA4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XA4);
    // 0x8017D1AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D1B0: beq         $t6, $at, L_8017D1C0
    if (ctx->r14 == ctx->r1) {
        // 0x8017D1B4: nop
    
            goto L_8017D1C0;
    }
    // 0x8017D1B4: nop

    // 0x8017D1B8: jal         0x8017D480
    // 0x8017D1BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_8017D480_12C2F0(rdram, ctx);
        goto after_8;
    // 0x8017D1BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_8:
L_8017D1C0:
    // 0x8017D1C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D1C4: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017D1C8: lw          $t1, 0xCC($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XCC);
    // 0x8017D1CC: lw          $t3, 0xC8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC8);
    // 0x8017D1D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D1D4: and         $t5, $t1, $t3
    ctx->r13 = ctx->r9 & ctx->r11;
    // 0x8017D1D8: beq         $t5, $at, L_8017D228
    if (ctx->r13 == ctx->r1) {
        // 0x8017D1DC: nop
    
            goto L_8017D228;
    }
    // 0x8017D1DC: nop

    // 0x8017D1E0: jal         0x8017D238
    // 0x8017D1E4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_8017D238_12C2F0(rdram, ctx);
        goto after_9;
    // 0x8017D1E4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_9:
    // 0x8017D1E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D1EC: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017D1F0: lw          $t7, 0xC8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC8);
    // 0x8017D1F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D1F8: beq         $t7, $at, L_8017D208
    if (ctx->r15 == ctx->r1) {
        // 0x8017D1FC: nop
    
            goto L_8017D208;
    }
    // 0x8017D1FC: nop

    // 0x8017D200: jal         0x8017D3A8
    // 0x8017D204: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_8017D3A8_12C2F0(rdram, ctx);
        goto after_10;
    // 0x8017D204: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_10:
L_8017D208:
    // 0x8017D208: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D20C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017D210: lw          $t9, 0xCC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XCC);
    // 0x8017D214: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017D218: beq         $t9, $at, L_8017D228
    if (ctx->r25 == ctx->r1) {
        // 0x8017D21C: nop
    
            goto L_8017D228;
    }
    // 0x8017D21C: nop

    // 0x8017D220: jal         0x8017D480
    // 0x8017D224: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_8017D480_12C2F0(rdram, ctx);
        goto after_11;
    // 0x8017D224: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_11:
L_8017D228:
    // 0x8017D228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D22C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D230: jr          $ra
    // 0x8017D234: nop

    return;
    // 0x8017D234: nop

;}
RECOMP_FUNC void func_8017D238_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D238: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017D23C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8017D240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017D244: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D248: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D24C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017D250: addiu       $a1, $a1, -0x2970
    ctx->r5 = ADD32(ctx->r5, -0X2970);
    // 0x8017D254: jal         0x800D87E4
    // 0x8017D258: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017D258: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x8017D25C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8017D260: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D264: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017D268: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017D26C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D270: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8017D274: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8017D278: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D27C: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8017D280: mfhi        $t1
    ctx->r9 = hi;
    // 0x8017D284: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8017D288: addiu       $t3, $t2, 0x82
    ctx->r11 = ADD32(ctx->r10, 0X82);
    // 0x8017D28C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8017D290: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x8017D294: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D298: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x8017D29C: mflo        $t5
    ctx->r13 = lo;
    // 0x8017D2A0: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8017D2A4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8017D2A8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017D2AC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D2B0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8017D2B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D2B8: addiu       $t7, $t6, 0x10E
    ctx->r15 = ADD32(ctx->r14, 0X10E);
    // 0x8017D2BC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D2C0: jal         0x800C7A88
    // 0x8017D2C4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_800C7A88(rdram, ctx);
        goto after_1;
    // 0x8017D2C4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_1:
    // 0x8017D2C8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8017D2CC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017D2D0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8017D2D4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8017D2D8: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8017D2DC: lw          $s0, 0x3C0C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3C0C);
    // 0x8017D2E0: beq         $s0, $at, L_8017D2F8
    if (ctx->r16 == ctx->r1) {
        // 0x8017D2E4: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_8017D2F8;
    }
    // 0x8017D2E4: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x8017D2E8: beq         $s0, $at, L_8017D31C
    if (ctx->r16 == ctx->r1) {
        // 0x8017D2EC: nop
    
            goto L_8017D31C;
    }
    // 0x8017D2EC: nop

    // 0x8017D2F0: b           L_8017D33C
    // 0x8017D2F4: nop

        goto L_8017D33C;
    // 0x8017D2F4: nop

L_8017D2F8:
    // 0x8017D2F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D2FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D300: addiu       $a1, $a1, -0x2968
    ctx->r5 = ADD32(ctx->r5, -0X2968);
    // 0x8017D304: jal         0x800D87E4
    // 0x8017D308: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017D308: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x8017D30C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017D310: addiu       $t2, $t1, -0x5
    ctx->r10 = ADD32(ctx->r9, -0X5);
    // 0x8017D314: b           L_8017D33C
    // 0x8017D318: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
        goto L_8017D33C;
    // 0x8017D318: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_8017D31C:
    // 0x8017D31C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D320: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D324: addiu       $a1, $a1, -0x2960
    ctx->r5 = ADD32(ctx->r5, -0X2960);
    // 0x8017D328: jal         0x800D87E4
    // 0x8017D32C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017D32C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017D330: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8017D334: addiu       $t9, $t3, -0x9
    ctx->r25 = ADD32(ctx->r11, -0X9);
    // 0x8017D338: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8017D33C:
    // 0x8017D33C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8017D340: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8017D344: bne         $t4, $at, L_8017D374
    if (ctx->r12 != ctx->r1) {
        // 0x8017D348: nop
    
            goto L_8017D374;
    }
    // 0x8017D348: nop

    // 0x8017D34C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D350: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017D354: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8017D358: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8017D35C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D360: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D364: jal         0x8017BE28
    // 0x8017D368: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_4;
    // 0x8017D368: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8017D36C: b           L_8017D394
    // 0x8017D370: nop

        goto L_8017D394;
    // 0x8017D370: nop

L_8017D374:
    // 0x8017D374: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D378: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017D37C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8017D380: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8017D384: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017D388: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017D38C: jal         0x8017BE28
    // 0x8017D390: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_5;
    // 0x8017D390: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_8017D394:
    // 0x8017D394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017D398: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017D39C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017D3A0: jr          $ra
    // 0x8017D3A4: nop

    return;
    // 0x8017D3A4: nop

;}
RECOMP_FUNC void func_8017D3A8_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D3A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D3AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017D3B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017D3B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D3B8: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017D3BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017D3C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D3C4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D3C8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8017D3CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017D3D0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D3D4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8017D3D8: addiu       $t2, $t1, 0x58
    ctx->r10 = ADD32(ctx->r9, 0X58);
    // 0x8017D3DC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017D3E0: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8017D3E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D3E8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D3EC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8017D3F0: addiu       $t5, $t4, 0x50
    ctx->r13 = ADD32(ctx->r12, 0X50);
    // 0x8017D3F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D3F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D3FC: jal         0x800C7A88
    // 0x8017D400: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_800C7A88(rdram, ctx);
        goto after_0;
    // 0x8017D400: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x8017D404: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D408: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D40C: addiu       $a1, $a1, -0x2954
    ctx->r5 = ADD32(ctx->r5, -0X2954);
    // 0x8017D410: jal         0x800D87E4
    // 0x8017D414: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017D414: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_1:
    // 0x8017D418: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017D41C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8017D420: bne         $t6, $at, L_8017D450
    if (ctx->r14 != ctx->r1) {
        // 0x8017D424: nop
    
            goto L_8017D450;
    }
    // 0x8017D424: nop

    // 0x8017D428: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017D42C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017D430: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D434: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017D438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D43C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D440: jal         0x8017BE28
    // 0x8017D444: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_2;
    // 0x8017D444: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8017D448: b           L_8017D470
    // 0x8017D44C: nop

        goto L_8017D470;
    // 0x8017D44C: nop

L_8017D450:
    // 0x8017D450: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D454: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D458: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D45C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017D460: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017D464: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017D468: jal         0x8017BE28
    // 0x8017D46C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017D46C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
L_8017D470:
    // 0x8017D470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D478: jr          $ra
    // 0x8017D47C: nop

    return;
    // 0x8017D47C: nop

;}
RECOMP_FUNC void func_8017D480_12C2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D480: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D484: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017D488: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017D48C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D490: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017D494: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017D498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D49C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D4A0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8017D4A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017D4A8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D4AC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8017D4B0: addiu       $t2, $t1, 0x178
    ctx->r10 = ADD32(ctx->r9, 0X178);
    // 0x8017D4B4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017D4B8: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8017D4BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D4C0: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D4C4: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8017D4C8: addiu       $t5, $t4, 0x50
    ctx->r13 = ADD32(ctx->r12, 0X50);
    // 0x8017D4CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D4D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D4D4: jal         0x800C7A88
    // 0x8017D4D8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_800C7A88(rdram, ctx);
        goto after_0;
    // 0x8017D4D8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_0:
    // 0x8017D4DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D4E0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D4E4: addiu       $a1, $a1, -0x2950
    ctx->r5 = ADD32(ctx->r5, -0X2950);
    // 0x8017D4E8: jal         0x800D87E4
    // 0x8017D4EC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017D4EC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_1:
    // 0x8017D4F0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017D4F4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8017D4F8: bne         $t6, $at, L_8017D528
    if (ctx->r14 != ctx->r1) {
        // 0x8017D4FC: nop
    
            goto L_8017D528;
    }
    // 0x8017D4FC: nop

    // 0x8017D500: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017D504: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017D508: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D50C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017D510: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D514: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017D518: jal         0x8017BE28
    // 0x8017D51C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_2;
    // 0x8017D51C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8017D520: b           L_8017D548
    // 0x8017D524: nop

        goto L_8017D548;
    // 0x8017D524: nop

L_8017D528:
    // 0x8017D528: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D52C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D530: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D534: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017D538: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017D53C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017D540: jal         0x8017BE28
    // 0x8017D544: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017BE28_12C2F0(rdram, ctx);
        goto after_3;
    // 0x8017D544: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
L_8017D548:
    // 0x8017D548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D54C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D550: jr          $ra
    // 0x8017D554: nop

    return;
    // 0x8017D554: nop

    // 0x8017D558: nop

    // 0x8017D55C: nop

;}
RECOMP_FUNC void func_8016D6F0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016D6F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D6FC: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016D700: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D704: sw          $zero, 0x38($t6)
    MEM_W(0X38, ctx->r14) = 0;
    // 0x8016D708: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8016D70C: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
    // 0x8016D710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D714: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D718: sw          $zero, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = 0;
    // 0x8016D71C: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x8016D720: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D724: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8016D728: sb          $zero, 0x9($t8)
    MEM_B(0X9, ctx->r24) = 0;
    // 0x8016D72C: lbu         $t0, 0x9($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X9);
    // 0x8016D730: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D734: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8016D738: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016D73C: sb          $t0, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r8;
    // 0x8016D740: sb          $zero, 0x7($t1)
    MEM_B(0X7, ctx->r9) = 0;
    // 0x8016D744: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8016D748: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016D74C: sb          $zero, 0xA($t2)
    MEM_B(0XA, ctx->r10) = 0;
    // 0x8016D750: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x8016D754: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D758: sb          $zero, 0xC($t3)
    MEM_B(0XC, ctx->r11) = 0;
    // 0x8016D75C: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x8016D760: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016D764: sb          $zero, 0xE($t4)
    MEM_B(0XE, ctx->r12) = 0;
    // 0x8016D768: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8016D76C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D770: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8016D774: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016D778: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D77C: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x8016D780: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8016D784: jal         0x800E4CDC
    // 0x8016D788: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x8016D788: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    after_0:
    // 0x8016D78C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D790: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016D794: andi        $t8, $v0, 0x7FFF
    ctx->r24 = ctx->r2 & 0X7FFF;
    // 0x8016D798: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x8016D79C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D7A0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8016D7A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D7A8: sw          $zero, 0x14($t9)
    MEM_W(0X14, ctx->r25) = 0;
    // 0x8016D7AC: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8016D7B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016D7B4: sw          $zero, 0x18($t1)
    MEM_W(0X18, ctx->r9) = 0;
    // 0x8016D7B8: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8016D7BC: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
    // 0x8016D7C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016D7C4: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8016D7C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D7CC: sw          $zero, 0x20($t3)
    MEM_W(0X20, ctx->r11) = 0;
    // 0x8016D7D0: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8016D7D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016D7D8: sw          $zero, 0x28($t4)
    MEM_W(0X28, ctx->r12) = 0;
    // 0x8016D7DC: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8016D7E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D7E4: sw          $zero, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = 0;
    // 0x8016D7E8: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016D7EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D7F0: sw          $zero, 0x40($t6)
    MEM_W(0X40, ctx->r14) = 0;
    // 0x8016D7F4: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8016D7F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D7FC: sw          $zero, 0x50($t7)
    MEM_W(0X50, ctx->r15) = 0;
    // 0x8016D800: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8016D804: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D808: sw          $zero, 0x54($t8)
    MEM_W(0X54, ctx->r24) = 0;
    // 0x8016D80C: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016D810: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D814: sw          $zero, 0x58($t0)
    MEM_W(0X58, ctx->r8) = 0;
    // 0x8016D818: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8016D81C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D820: sw          $zero, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = 0;
    // 0x8016D824: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8016D828: sw          $zero, 0x60($t1)
    MEM_W(0X60, ctx->r9) = 0;
    // 0x8016D82C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016D830: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8016D834: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D838: sw          $zero, 0x64($t2)
    MEM_W(0X64, ctx->r10) = 0;
    // 0x8016D83C: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8016D840: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8016D844: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D848: sw          $t3, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r11;
    // 0x8016D84C: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016D850: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8016D854: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D858: sw          $t5, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r13;
    // 0x8016D85C: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8016D860: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D864: sw          $zero, 0x70($t7)
    MEM_W(0X70, ctx->r15) = 0;
    // 0x8016D868: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8016D86C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D870: sw          $zero, 0x74($t8)
    MEM_W(0X74, ctx->r24) = 0;
    // 0x8016D874: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016D878: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D87C: sw          $zero, 0x78($t0)
    MEM_W(0X78, ctx->r8) = 0;
    // 0x8016D880: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8016D884: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8016D888: sw          $t9, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = ctx->r25;
    // 0x8016D88C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D890: sw          $zero, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = 0;
    // 0x8016D894: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016D898:
    // 0x8016D898: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D89C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D8A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D8A4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8016D8A8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016D8AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016D8B0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8016D8B4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016D8B8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016D8BC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016D8C0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8016D8C4: sh          $zero, -0x2A28($at)
    MEM_H(-0X2A28, ctx->r1) = 0;
    // 0x8016D8C8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8016D8CC: sltiu       $at, $t5, 0x30
    ctx->r1 = ctx->r13 < 0X30 ? 1 : 0;
    // 0x8016D8D0: bne         $at, $zero, L_8016D898
    if (ctx->r1 != 0) {
        // 0x8016D8D4: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_8016D898;
    }
    // 0x8016D8D4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8016D8D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016D8DC:
    // 0x8016D8DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D8E0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D8E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016D8EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016D8F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016D8F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016D8F8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8016D8FC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016D900: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
    // 0x8016D904: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8016D908: sltiu       $at, $t0, 0x30
    ctx->r1 = ctx->r8 < 0X30 ? 1 : 0;
    // 0x8016D90C: bne         $at, $zero, L_8016D8DC
    if (ctx->r1 != 0) {
        // 0x8016D910: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_8016D8DC;
    }
    // 0x8016D910: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8016D914: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016D918:
    // 0x8016D918: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D91C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D920: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D924: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8016D928: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8016D92C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016D930: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016D934: sw          $zero, 0x2318($at)
    MEM_W(0X2318, ctx->r1) = 0;
    // 0x8016D938: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8016D93C: sltiu       $at, $t3, 0x80
    ctx->r1 = ctx->r11 < 0X80 ? 1 : 0;
    // 0x8016D940: bne         $at, $zero, L_8016D918
    if (ctx->r1 != 0) {
        // 0x8016D944: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_8016D918;
    }
    // 0x8016D944: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8016D948: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D94C: lw          $t4, -0x2E44($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E44);
    // 0x8016D950: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8016D954: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x8016D958: beq         $at, $zero, L_8016DC84
    if (ctx->r1 == 0) {
        // 0x8016D95C: nop
    
            goto L_8016DC84;
    }
    // 0x8016D95C: nop

    // 0x8016D960: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016D964: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8016D968: addu        $at, $at, $t5
    gpr jr_addend_8016D970 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8016D96C: lw          $t5, -0x544($at)
    ctx->r13 = ADD32(ctx->r1, -0X544);
    // 0x8016D970: jr          $t5
    // 0x8016D974: nop

    switch (jr_addend_8016D970 >> 2) {
        case 0: goto L_8016D978; break;
        case 1: goto L_8016D9F4; break;
        case 2: goto L_8016DA70; break;
        case 3: goto L_8016DAEC; break;
        case 4: goto L_8016DB68; break;
        case 5: goto L_8016DBE4; break;
        default: switch_error(__func__, 0x8016D970, 0x8019FABC);
    }
    // 0x8016D974: nop

L_8016D978:
    // 0x8016D978: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016D97C: jal         0x800C38C8
    // 0x8016D980: addiu       $a0, $a0, -0x48F0
    ctx->r4 = ADD32(ctx->r4, -0X48F0);
    func_800C38C8(rdram, ctx);
        goto after_1;
    // 0x8016D980: addiu       $a0, $a0, -0x48F0
    ctx->r4 = ADD32(ctx->r4, -0X48F0);
    after_1:
    // 0x8016D984: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016D988: jal         0x800C3930
    // 0x8016D98C: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    func_800C3930(rdram, ctx);
        goto after_2;
    // 0x8016D98C: addiu       $a0, $a0, -0x48D0
    ctx->r4 = ADD32(ctx->r4, -0X48D0);
    after_2:
    // 0x8016D990: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016D994: jal         0x800C3968
    // 0x8016D998: addiu       $a0, $a0, -0x48C0
    ctx->r4 = ADD32(ctx->r4, -0X48C0);
    func_800C3968(rdram, ctx);
        goto after_3;
    // 0x8016D998: addiu       $a0, $a0, -0x48C0
    ctx->r4 = ADD32(ctx->r4, -0X48C0);
    after_3:
    // 0x8016D99C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016D9A0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016D9A4: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016D9A8: jal         0x800C39A0
    // 0x8016D9AC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_4;
    // 0x8016D9AC: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_4:
    // 0x8016D9B0: jal         0x800CCB88
    // 0x8016D9B4: nop

    func_800CCB88(rdram, ctx);
        goto after_5;
    // 0x8016D9B4: nop

    after_5:
    // 0x8016D9B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016D9BC: jal         0x800C3968
    // 0x8016D9C0: addiu       $a0, $a0, -0x48A8
    ctx->r4 = ADD32(ctx->r4, -0X48A8);
    func_800C3968(rdram, ctx);
        goto after_6;
    // 0x8016D9C0: addiu       $a0, $a0, -0x48A8
    ctx->r4 = ADD32(ctx->r4, -0X48A8);
    after_6:
    // 0x8016D9C4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8016D9C8: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, 0X400);
    // 0x8016D9CC: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016D9D0: addu        $a0, $t6, $at
    ctx->r4 = ADD32(ctx->r14, ctx->r1);
    // 0x8016D9D4: jal         0x800C39A0
    // 0x8016D9D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_800C39A0(rdram, ctx);
        goto after_7;
    // 0x8016D9D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_7:
    // 0x8016D9DC: jal         0x801D21F0
    // 0x8016D9E0: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_8;
    // 0x8016D9E0: nop

    after_8:
    // 0x8016D9E4: jal         0x800C7FA4
    // 0x8016D9E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C7FA4(rdram, ctx);
        goto after_9;
    // 0x8016D9E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8016D9EC: b           L_8016DC84
    // 0x8016D9F0: nop

        goto L_8016DC84;
    // 0x8016D9F0: nop

L_8016D9F4:
    // 0x8016D9F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016D9F8: jal         0x800C38C8
    // 0x8016D9FC: addiu       $a0, $a0, -0x489C
    ctx->r4 = ADD32(ctx->r4, -0X489C);
    func_800C38C8(rdram, ctx);
        goto after_10;
    // 0x8016D9FC: addiu       $a0, $a0, -0x489C
    ctx->r4 = ADD32(ctx->r4, -0X489C);
    after_10:
    // 0x8016DA00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA04: jal         0x800C3930
    // 0x8016DA08: addiu       $a0, $a0, -0x487C
    ctx->r4 = ADD32(ctx->r4, -0X487C);
    func_800C3930(rdram, ctx);
        goto after_11;
    // 0x8016DA08: addiu       $a0, $a0, -0x487C
    ctx->r4 = ADD32(ctx->r4, -0X487C);
    after_11:
    // 0x8016DA0C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA10: jal         0x800C3968
    // 0x8016DA14: addiu       $a0, $a0, -0x486C
    ctx->r4 = ADD32(ctx->r4, -0X486C);
    func_800C3968(rdram, ctx);
        goto after_12;
    // 0x8016DA14: addiu       $a0, $a0, -0x486C
    ctx->r4 = ADD32(ctx->r4, -0X486C);
    after_12:
    // 0x8016DA18: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DA1C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016DA20: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016DA24: jal         0x800C39A0
    // 0x8016DA28: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_13;
    // 0x8016DA28: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_13:
    // 0x8016DA2C: jal         0x800CCB88
    // 0x8016DA30: nop

    func_800CCB88(rdram, ctx);
        goto after_14;
    // 0x8016DA30: nop

    after_14:
    // 0x8016DA34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA38: jal         0x800C3968
    // 0x8016DA3C: addiu       $a0, $a0, -0x4854
    ctx->r4 = ADD32(ctx->r4, -0X4854);
    func_800C3968(rdram, ctx);
        goto after_15;
    // 0x8016DA3C: addiu       $a0, $a0, -0x4854
    ctx->r4 = ADD32(ctx->r4, -0X4854);
    after_15:
    // 0x8016DA40: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8016DA44: addiu       $t7, $t7, 0x400
    ctx->r15 = ADD32(ctx->r15, 0X400);
    // 0x8016DA48: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016DA4C: addu        $a0, $t7, $at
    ctx->r4 = ADD32(ctx->r15, ctx->r1);
    // 0x8016DA50: jal         0x800C39A0
    // 0x8016DA54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800C39A0(rdram, ctx);
        goto after_16;
    // 0x8016DA54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_16:
    // 0x8016DA58: jal         0x801D21F0
    // 0x8016DA5C: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_17;
    // 0x8016DA5C: nop

    after_17:
    // 0x8016DA60: jal         0x800C7FA4
    // 0x8016DA64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C7FA4(rdram, ctx);
        goto after_18;
    // 0x8016DA64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_18:
    // 0x8016DA68: b           L_8016DC84
    // 0x8016DA6C: nop

        goto L_8016DC84;
    // 0x8016DA6C: nop

L_8016DA70:
    // 0x8016DA70: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA74: jal         0x800C38C8
    // 0x8016DA78: addiu       $a0, $a0, -0x482C
    ctx->r4 = ADD32(ctx->r4, -0X482C);
    func_800C38C8(rdram, ctx);
        goto after_19;
    // 0x8016DA78: addiu       $a0, $a0, -0x482C
    ctx->r4 = ADD32(ctx->r4, -0X482C);
    after_19:
    // 0x8016DA7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA80: jal         0x800C3930
    // 0x8016DA84: addiu       $a0, $a0, -0x480C
    ctx->r4 = ADD32(ctx->r4, -0X480C);
    func_800C3930(rdram, ctx);
        goto after_20;
    // 0x8016DA84: addiu       $a0, $a0, -0x480C
    ctx->r4 = ADD32(ctx->r4, -0X480C);
    after_20:
    // 0x8016DA88: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DA8C: jal         0x800C3968
    // 0x8016DA90: addiu       $a0, $a0, -0x47FC
    ctx->r4 = ADD32(ctx->r4, -0X47FC);
    func_800C3968(rdram, ctx);
        goto after_21;
    // 0x8016DA90: addiu       $a0, $a0, -0x47FC
    ctx->r4 = ADD32(ctx->r4, -0X47FC);
    after_21:
    // 0x8016DA94: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DA98: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016DA9C: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016DAA0: jal         0x800C39A0
    // 0x8016DAA4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_22;
    // 0x8016DAA4: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_22:
    // 0x8016DAA8: jal         0x800CCB88
    // 0x8016DAAC: nop

    func_800CCB88(rdram, ctx);
        goto after_23;
    // 0x8016DAAC: nop

    after_23:
    // 0x8016DAB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DAB4: jal         0x800C3968
    // 0x8016DAB8: addiu       $a0, $a0, -0x47E4
    ctx->r4 = ADD32(ctx->r4, -0X47E4);
    func_800C3968(rdram, ctx);
        goto after_24;
    // 0x8016DAB8: addiu       $a0, $a0, -0x47E4
    ctx->r4 = ADD32(ctx->r4, -0X47E4);
    after_24:
    // 0x8016DABC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8016DAC0: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x8016DAC4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016DAC8: addu        $a0, $t8, $at
    ctx->r4 = ADD32(ctx->r24, ctx->r1);
    // 0x8016DACC: jal         0x800C39A0
    // 0x8016DAD0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_800C39A0(rdram, ctx);
        goto after_25;
    // 0x8016DAD0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_25:
    // 0x8016DAD4: jal         0x801D21F0
    // 0x8016DAD8: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_26;
    // 0x8016DAD8: nop

    after_26:
    // 0x8016DADC: jal         0x800C7FA4
    // 0x8016DAE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C7FA4(rdram, ctx);
        goto after_27;
    // 0x8016DAE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_27:
    // 0x8016DAE4: b           L_8016DC84
    // 0x8016DAE8: nop

        goto L_8016DC84;
    // 0x8016DAE8: nop

L_8016DAEC:
    // 0x8016DAEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DAF0: jal         0x800C38C8
    // 0x8016DAF4: addiu       $a0, $a0, -0x47D8
    ctx->r4 = ADD32(ctx->r4, -0X47D8);
    func_800C38C8(rdram, ctx);
        goto after_28;
    // 0x8016DAF4: addiu       $a0, $a0, -0x47D8
    ctx->r4 = ADD32(ctx->r4, -0X47D8);
    after_28:
    // 0x8016DAF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DAFC: jal         0x800C3930
    // 0x8016DB00: addiu       $a0, $a0, -0x47B8
    ctx->r4 = ADD32(ctx->r4, -0X47B8);
    func_800C3930(rdram, ctx);
        goto after_29;
    // 0x8016DB00: addiu       $a0, $a0, -0x47B8
    ctx->r4 = ADD32(ctx->r4, -0X47B8);
    after_29:
    // 0x8016DB04: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DB08: jal         0x800C3968
    // 0x8016DB0C: addiu       $a0, $a0, -0x47A8
    ctx->r4 = ADD32(ctx->r4, -0X47A8);
    func_800C3968(rdram, ctx);
        goto after_30;
    // 0x8016DB0C: addiu       $a0, $a0, -0x47A8
    ctx->r4 = ADD32(ctx->r4, -0X47A8);
    after_30:
    // 0x8016DB10: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DB14: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016DB18: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016DB1C: jal         0x800C39A0
    // 0x8016DB20: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_31;
    // 0x8016DB20: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_31:
    // 0x8016DB24: jal         0x800CCB88
    // 0x8016DB28: nop

    func_800CCB88(rdram, ctx);
        goto after_32;
    // 0x8016DB28: nop

    after_32:
    // 0x8016DB2C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DB30: jal         0x800C3968
    // 0x8016DB34: addiu       $a0, $a0, -0x4790
    ctx->r4 = ADD32(ctx->r4, -0X4790);
    func_800C3968(rdram, ctx);
        goto after_33;
    // 0x8016DB34: addiu       $a0, $a0, -0x4790
    ctx->r4 = ADD32(ctx->r4, -0X4790);
    after_33:
    // 0x8016DB38: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8016DB3C: addiu       $t0, $t0, 0x400
    ctx->r8 = ADD32(ctx->r8, 0X400);
    // 0x8016DB40: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016DB44: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    // 0x8016DB48: jal         0x800C39A0
    // 0x8016DB4C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800C39A0(rdram, ctx);
        goto after_34;
    // 0x8016DB4C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_34:
    // 0x8016DB50: jal         0x801D21F0
    // 0x8016DB54: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_35;
    // 0x8016DB54: nop

    after_35:
    // 0x8016DB58: jal         0x800C7FA4
    // 0x8016DB5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800C7FA4(rdram, ctx);
        goto after_36;
    // 0x8016DB5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_36:
    // 0x8016DB60: b           L_8016DC84
    // 0x8016DB64: nop

        goto L_8016DC84;
    // 0x8016DB64: nop

L_8016DB68:
    // 0x8016DB68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DB6C: jal         0x800C38C8
    // 0x8016DB70: addiu       $a0, $a0, -0x4784
    ctx->r4 = ADD32(ctx->r4, -0X4784);
    func_800C38C8(rdram, ctx);
        goto after_37;
    // 0x8016DB70: addiu       $a0, $a0, -0x4784
    ctx->r4 = ADD32(ctx->r4, -0X4784);
    after_37:
    // 0x8016DB74: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DB78: jal         0x800C3930
    // 0x8016DB7C: addiu       $a0, $a0, -0x4764
    ctx->r4 = ADD32(ctx->r4, -0X4764);
    func_800C3930(rdram, ctx);
        goto after_38;
    // 0x8016DB7C: addiu       $a0, $a0, -0x4764
    ctx->r4 = ADD32(ctx->r4, -0X4764);
    after_38:
    // 0x8016DB80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DB84: jal         0x800C3968
    // 0x8016DB88: addiu       $a0, $a0, -0x4754
    ctx->r4 = ADD32(ctx->r4, -0X4754);
    func_800C3968(rdram, ctx);
        goto after_39;
    // 0x8016DB88: addiu       $a0, $a0, -0x4754
    ctx->r4 = ADD32(ctx->r4, -0X4754);
    after_39:
    // 0x8016DB8C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DB90: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016DB94: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016DB98: jal         0x800C39A0
    // 0x8016DB9C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_40;
    // 0x8016DB9C: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_40:
    // 0x8016DBA0: jal         0x800CCB88
    // 0x8016DBA4: nop

    func_800CCB88(rdram, ctx);
        goto after_41;
    // 0x8016DBA4: nop

    after_41:
    // 0x8016DBA8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DBAC: jal         0x800C3968
    // 0x8016DBB0: addiu       $a0, $a0, -0x473C
    ctx->r4 = ADD32(ctx->r4, -0X473C);
    func_800C3968(rdram, ctx);
        goto after_42;
    // 0x8016DBB0: addiu       $a0, $a0, -0x473C
    ctx->r4 = ADD32(ctx->r4, -0X473C);
    after_42:
    // 0x8016DBB4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8016DBB8: addiu       $t9, $t9, 0x400
    ctx->r25 = ADD32(ctx->r25, 0X400);
    // 0x8016DBBC: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016DBC0: addu        $a0, $t9, $at
    ctx->r4 = ADD32(ctx->r25, ctx->r1);
    // 0x8016DBC4: jal         0x800C39A0
    // 0x8016DBC8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800C39A0(rdram, ctx);
        goto after_43;
    // 0x8016DBC8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_43:
    // 0x8016DBCC: jal         0x801D21F0
    // 0x8016DBD0: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_44;
    // 0x8016DBD0: nop

    after_44:
    // 0x8016DBD4: jal         0x800C7FA4
    // 0x8016DBD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C7FA4(rdram, ctx);
        goto after_45;
    // 0x8016DBD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_45:
    // 0x8016DBDC: b           L_8016DC84
    // 0x8016DBE0: nop

        goto L_8016DC84;
    // 0x8016DBE0: nop

L_8016DBE4:
    // 0x8016DBE4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DBE8: jal         0x800C38C8
    // 0x8016DBEC: addiu       $a0, $a0, -0x4704
    ctx->r4 = ADD32(ctx->r4, -0X4704);
    func_800C38C8(rdram, ctx);
        goto after_46;
    // 0x8016DBEC: addiu       $a0, $a0, -0x4704
    ctx->r4 = ADD32(ctx->r4, -0X4704);
    after_46:
    // 0x8016DBF0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DBF4: jal         0x800C3930
    // 0x8016DBF8: addiu       $a0, $a0, -0x46E4
    ctx->r4 = ADD32(ctx->r4, -0X46E4);
    func_800C3930(rdram, ctx);
        goto after_47;
    // 0x8016DBF8: addiu       $a0, $a0, -0x46E4
    ctx->r4 = ADD32(ctx->r4, -0X46E4);
    after_47:
    // 0x8016DBFC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DC00: jal         0x800C3930
    // 0x8016DC04: addiu       $a0, $a0, -0x46D4
    ctx->r4 = ADD32(ctx->r4, -0X46D4);
    func_800C3930(rdram, ctx);
        goto after_48;
    // 0x8016DC04: addiu       $a0, $a0, -0x46D4
    ctx->r4 = ADD32(ctx->r4, -0X46D4);
    after_48:
    // 0x8016DC08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DC0C: jal         0x800C3968
    // 0x8016DC10: addiu       $a0, $a0, -0x46C4
    ctx->r4 = ADD32(ctx->r4, -0X46C4);
    func_800C3968(rdram, ctx);
        goto after_49;
    // 0x8016DC10: addiu       $a0, $a0, -0x46C4
    ctx->r4 = ADD32(ctx->r4, -0X46C4);
    after_49:
    // 0x8016DC14: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DC18: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8016DC1C: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8016DC20: jal         0x800C39A0
    // 0x8016DC24: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_50;
    // 0x8016DC24: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_50:
    // 0x8016DC28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DC2C: jal         0x800C3968
    // 0x8016DC30: addiu       $a0, $a0, -0x46B8
    ctx->r4 = ADD32(ctx->r4, -0X46B8);
    func_800C3968(rdram, ctx);
        goto after_51;
    // 0x8016DC30: addiu       $a0, $a0, -0x46B8
    ctx->r4 = ADD32(ctx->r4, -0X46B8);
    after_51:
    // 0x8016DC34: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8016DC38: lui         $a1, 0x802D
    ctx->r5 = S32(0X802D << 16);
    // 0x8016DC3C: addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    // 0x8016DC40: jal         0x800C39A0
    // 0x8016DC44: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    func_800C39A0(rdram, ctx);
        goto after_52;
    // 0x8016DC44: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_52:
    // 0x8016DC48: jal         0x800CCB88
    // 0x8016DC4C: nop

    func_800CCB88(rdram, ctx);
        goto after_53;
    // 0x8016DC4C: nop

    after_53:
    // 0x8016DC50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8016DC54: jal         0x800C3968
    // 0x8016DC58: addiu       $a0, $a0, -0x46A0
    ctx->r4 = ADD32(ctx->r4, -0X46A0);
    func_800C3968(rdram, ctx);
        goto after_54;
    // 0x8016DC58: addiu       $a0, $a0, -0x46A0
    ctx->r4 = ADD32(ctx->r4, -0X46A0);
    after_54:
    // 0x8016DC5C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8016DC60: addiu       $t1, $t1, 0x400
    ctx->r9 = ADD32(ctx->r9, 0X400);
    // 0x8016DC64: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8016DC68: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    // 0x8016DC6C: jal         0x800C39A0
    // 0x8016DC70: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_800C39A0(rdram, ctx);
        goto after_55;
    // 0x8016DC70: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_55:
    // 0x8016DC74: jal         0x801D21F0
    // 0x8016DC78: nop

    LOOKUP_FUNC(0x801D21F0)(rdram, ctx);
        goto after_56;
    // 0x8016DC78: nop

    after_56:
    // 0x8016DC7C: jal         0x800C7FA4
    // 0x8016DC80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C7FA4(rdram, ctx);
        goto after_57;
    // 0x8016DC80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_57:
L_8016DC84:
    // 0x8016DC84: jal         0x80192968
    // 0x8016DC88: nop

    func_80192968_1501A0(rdram, ctx);
        goto after_58;
    // 0x8016DC88: nop

    after_58:
    // 0x8016DC8C: jal         0x8017189C
    // 0x8016DC90: nop

    func_8017189C_1501A0(rdram, ctx);
        goto after_59;
    // 0x8016DC90: nop

    after_59:
    // 0x8016DC94: jal         0x801736A0
    // 0x8016DC98: nop

    func_801736A0_1501A0(rdram, ctx);
        goto after_60;
    // 0x8016DC98: nop

    after_60:
    // 0x8016DC9C: jal         0x80176EB0
    // 0x8016DCA0: nop

    func_80176EB0_1501A0(rdram, ctx);
        goto after_61;
    // 0x8016DCA0: nop

    after_61:
    // 0x8016DCA4: jal         0x801933C4
    // 0x8016DCA8: nop

    func_801933C4_1501A0(rdram, ctx);
        goto after_62;
    // 0x8016DCA8: nop

    after_62:
    // 0x8016DCAC: jal         0x801971F0
    // 0x8016DCB0: nop

    func_801971F0_1501A0(rdram, ctx);
        goto after_63;
    // 0x8016DCB0: nop

    after_63:
    // 0x8016DCB4: jal         0x8016DCD4
    // 0x8016DCB8: nop

    func_8016DCD4_1501A0(rdram, ctx);
        goto after_64;
    // 0x8016DCB8: nop

    after_64:
    // 0x8016DCBC: jal         0x8016DD14
    // 0x8016DCC0: nop

    func_8016DD14_1501A0(rdram, ctx);
        goto after_65;
    // 0x8016DCC0: nop

    after_65:
    // 0x8016DCC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DCC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016DCCC: jr          $ra
    // 0x8016DCD0: nop

    return;
    // 0x8016DCD0: nop

;}
RECOMP_FUNC void func_8016DCD4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DCD4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016DCD8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8016DCDC:
    // 0x8016DCDC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8016DCE0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8016DCE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DCE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016DCEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016DCF0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8016DCF4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016DCF8: sw          $zero, 0x3958($at)
    MEM_W(0X3958, ctx->r1) = 0;
    // 0x8016DCFC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8016DD00: sltiu       $at, $t9, 0x2
    ctx->r1 = ctx->r25 < 0X2 ? 1 : 0;
    // 0x8016DD04: bne         $at, $zero, L_8016DCDC
    if (ctx->r1 != 0) {
        // 0x8016DD08: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_8016DCDC;
    }
    // 0x8016DD08: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8016DD0C: jr          $ra
    // 0x8016DD10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016DD10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016DD14_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DD14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DD18: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8016DD1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016DD20: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8016DD24: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8016DD28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8016DD2C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016DD30: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8016DD34: addiu       $t9, $t9, -0xE40
    ctx->r25 = ADD32(ctx->r25, -0XE40);
    // 0x8016DD38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016DD3C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8016DD40: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8016DD44: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8016DD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD4C: sb          $t1, -0x2C30($at)
    MEM_B(-0X2C30, ctx->r1) = ctx->r9;
    // 0x8016DD50: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x8016DD54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD58: sb          $t2, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r10;
    // 0x8016DD5C: lbu         $t3, 0x2($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X2);
    // 0x8016DD60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD64: sb          $t3, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r11;
    // 0x8016DD68: lbu         $t4, 0x3($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X3);
    // 0x8016DD6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD70: sb          $t4, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = ctx->r12;
    // 0x8016DD74: lbu         $t5, 0xD($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XD);
    // 0x8016DD78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD7C: sb          $t5, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r13;
    // 0x8016DD80: lbu         $t6, 0xE($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XE);
    // 0x8016DD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD88: sb          $t6, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r14;
    // 0x8016DD8C: lbu         $t7, 0xF($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XF);
    // 0x8016DD90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DD94: sb          $t7, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = ctx->r15;
    // 0x8016DD98: lhu         $t8, 0x10($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X10);
    // 0x8016DD9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDA0: sh          $t8, -0x2C20($at)
    MEM_H(-0X2C20, ctx->r1) = ctx->r24;
    // 0x8016DDA4: lhu         $t9, 0x12($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X12);
    // 0x8016DDA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDAC: sh          $t9, -0x2C1E($at)
    MEM_H(-0X2C1E, ctx->r1) = ctx->r25;
    // 0x8016DDB0: lbu         $t2, 0x4($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X4);
    // 0x8016DDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDB8: sb          $t2, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r10;
    // 0x8016DDBC: lbu         $t3, 0x5($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X5);
    // 0x8016DDC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDC4: sb          $t3, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r11;
    // 0x8016DDC8: lbu         $t4, 0x6($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X6);
    // 0x8016DDCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDD0: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x8016DDD4: sb          $t4, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r12;
    // 0x8016DDD8: lbu         $t5, 0x7($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X7);
    // 0x8016DDDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDE0: sb          $t5, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r13;
    // 0x8016DDE4: lbu         $t6, 0x8($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X8);
    // 0x8016DDE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDEC: sb          $t6, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r14;
    // 0x8016DDF0: lbu         $t7, 0x9($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X9);
    // 0x8016DDF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DDF8: sb          $t7, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r15;
    // 0x8016DDFC: lb          $t8, 0xA($t0)
    ctx->r24 = MEM_B(ctx->r8, 0XA);
    // 0x8016DE00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE04: sb          $t8, -0x2C23($at)
    MEM_B(-0X2C23, ctx->r1) = ctx->r24;
    // 0x8016DE08: lb          $t9, 0xB($t0)
    ctx->r25 = MEM_B(ctx->r8, 0XB);
    // 0x8016DE0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE10: sb          $t9, -0x2C22($at)
    MEM_B(-0X2C22, ctx->r1) = ctx->r25;
    // 0x8016DE14: lb          $t2, 0xC($t0)
    ctx->r10 = MEM_B(ctx->r8, 0XC);
    // 0x8016DE18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE1C: sb          $t2, -0x2C21($at)
    MEM_B(-0X2C21, ctx->r1) = ctx->r10;
    // 0x8016DE20: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8016DE24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE28: swc1        $f4, -0x2C1C($at)
    MEM_W(-0X2C1C, ctx->r1) = ctx->f4.u32l;
    // 0x8016DE2C: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8016DE30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE34: swc1        $f6, -0x2C18($at)
    MEM_W(-0X2C18, ctx->r1) = ctx->f6.u32l;
    // 0x8016DE38: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8016DE3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE40: swc1        $f8, -0x2C14($at)
    MEM_W(-0X2C14, ctx->r1) = ctx->f8.u32l;
    // 0x8016DE44: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8016DE48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE4C: swc1        $f10, -0x41A8($at)
    MEM_W(-0X41A8, ctx->r1) = ctx->f10.u32l;
    // 0x8016DE50: lwc1        $f16, -0x41A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X41A8);
    // 0x8016DE54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE58: swc1        $f16, -0x2C10($at)
    MEM_W(-0X2C10, ctx->r1) = ctx->f16.u32l;
    // 0x8016DE5C: lwc1        $f18, 0x18($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8016DE60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE64: swc1        $f18, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f18.u32l;
    // 0x8016DE68: lwc1        $f4, -0x41A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x8016DE6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE70: beq         $t3, $zero, L_8016DE94
    if (ctx->r11 == 0) {
        // 0x8016DE74: swc1        $f4, -0x2C0C($at)
        MEM_W(-0X2C0C, ctx->r1) = ctx->f4.u32l;
            goto L_8016DE94;
    }
    // 0x8016DE74: swc1        $f4, -0x2C0C($at)
    MEM_W(-0X2C0C, ctx->r1) = ctx->f4.u32l;
    // 0x8016DE78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8016DE7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8016DE80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8016DE84: lbu         $a2, -0x2C27($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C27);
    // 0x8016DE88: lbu         $a1, -0x2C28($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C28);
    // 0x8016DE8C: jal         0x800C6E0C
    // 0x8016DE90: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    func_800C6E0C(rdram, ctx);
        goto after_0;
    // 0x8016DE90: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    after_0:
L_8016DE94:
    // 0x8016DE94: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DE98: lbu         $t4, -0x2C30($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2C30);
    // 0x8016DE9C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8016DEA0: beq         $t5, $zero, L_8016DEE4
    if (ctx->r13 == 0) {
        // 0x8016DEA4: nop
    
            goto L_8016DEE4;
    }
    // 0x8016DEA4: nop

    // 0x8016DEA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DEAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DEB0: lb          $t7, -0x2C21($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2C21);
    // 0x8016DEB4: lb          $t6, -0x2C22($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2C22);
    // 0x8016DEB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8016DEBC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8016DEC0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8016DEC4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8016DEC8: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x8016DECC: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x8016DED0: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x8016DED4: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x8016DED8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8016DEDC: jal         0x800C6E68
    // 0x8016DEE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800C6E68(rdram, ctx);
        goto after_1;
    // 0x8016DEE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
L_8016DEE4:
    // 0x8016DEE4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DEE8: lbu         $t8, -0x2C30($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C30);
    // 0x8016DEEC: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8016DEF0: beq         $t9, $zero, L_8016DF00
    if (ctx->r25 == 0) {
        // 0x8016DEF4: nop
    
            goto L_8016DF00;
    }
    // 0x8016DEF4: nop

    // 0x8016DEF8: jal         0x800C6DBC
    // 0x8016DEFC: nop

    func_800C6DBC(rdram, ctx);
        goto after_2;
    // 0x8016DEFC: nop

    after_2:
L_8016DF00:
    // 0x8016DF00: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DF04: lbu         $t2, -0x2C30($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C30);
    // 0x8016DF08: andi        $t0, $t2, 0x4
    ctx->r8 = ctx->r10 & 0X4;
    // 0x8016DF0C: beq         $t0, $zero, L_8016DF4C
    if (ctx->r8 == 0) {
        // 0x8016DF10: nop
    
            goto L_8016DF4C;
    }
    // 0x8016DF10: nop

    // 0x8016DF14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DF18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DF1C: lhu         $t3, -0x2C1E($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2C1E);
    // 0x8016DF20: lhu         $t1, -0x2C20($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2C20);
    // 0x8016DF24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8016DF28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8016DF2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8016DF30: lbu         $a2, -0x2C2A($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2A);
    // 0x8016DF34: lbu         $a1, -0x2C2B($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2B);
    // 0x8016DF38: lbu         $a0, -0x2C2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2C);
    // 0x8016DF3C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8016DF40: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8016DF44: jal         0x800C70C0
    // 0x8016DF48: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800C70C0(rdram, ctx);
        goto after_3;
    // 0x8016DF48: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
L_8016DF4C:
    // 0x8016DF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016DF50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016DF54: jr          $ra
    // 0x8016DF58: nop

    return;
    // 0x8016DF58: nop

;}
RECOMP_FUNC void func_8016DF5C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DF5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016DF60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016DF64: jal         0x8016E454
    // 0x8016DF68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8016E454_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016DF68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8016DF6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DF70: lhu         $t6, -0x2BA8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2BA8);
    // 0x8016DF74: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8016DF78: bne         $t7, $zero, L_8016DFBC
    if (ctx->r15 != 0) {
        // 0x8016DF7C: nop
    
            goto L_8016DFBC;
    }
    // 0x8016DF7C: nop

    // 0x8016DF80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DF84: lw          $t8, -0x2D68($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D68);
    // 0x8016DF88: bne         $t8, $zero, L_8016DFBC
    if (ctx->r24 != 0) {
        // 0x8016DF8C: nop
    
            goto L_8016DFBC;
    }
    // 0x8016DF8C: nop

    // 0x8016DF90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DF94: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8016DF98: lbu         $t0, 0xA($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XA);
    // 0x8016DF9C: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8016DFA0: beq         $t1, $zero, L_8016DFCC
    if (ctx->r9 == 0) {
        // 0x8016DFA4: nop
    
            goto L_8016DFCC;
    }
    // 0x8016DFA4: nop

    // 0x8016DFA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DFAC: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8016DFB0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8016DFB4: bne         $t3, $zero, L_8016DFCC
    if (ctx->r11 != 0) {
        // 0x8016DFB8: nop
    
            goto L_8016DFCC;
    }
    // 0x8016DFB8: nop

L_8016DFBC:
    // 0x8016DFBC: jal         0x80171158
    // 0x8016DFC0: nop

    func_80171158_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016DFC0: nop

    after_1:
    // 0x8016DFC4: b           L_8016E27C
    // 0x8016DFC8: nop

        goto L_8016E27C;
    // 0x8016DFC8: nop

L_8016DFCC:
    // 0x8016DFCC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8016DFD0: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8016DFD4: beq         $s0, $zero, L_8016DFF4
    if (ctx->r16 == 0) {
        // 0x8016DFD8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8016DFF4;
    }
    // 0x8016DFD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016DFDC: beq         $s0, $at, L_8016E058
    if (ctx->r16 == ctx->r1) {
        // 0x8016DFE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016E058;
    }
    // 0x8016DFE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016DFE4: beq         $s0, $at, L_8016E0F0
    if (ctx->r16 == ctx->r1) {
        // 0x8016DFE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016E0F0;
    }
    // 0x8016DFE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016DFEC: bne         $s0, $at, L_8016E27C
    if (ctx->r16 != ctx->r1) {
        // 0x8016DFF0: nop
    
            goto L_8016E27C;
    }
    // 0x8016DFF0: nop

L_8016DFF4:
    // 0x8016DFF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DFF8: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8016DFFC: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8016E000: bne         $t5, $zero, L_8016E018
    if (ctx->r13 != 0) {
        // 0x8016E004: nop
    
            goto L_8016E018;
    }
    // 0x8016E004: nop

    // 0x8016E008: jal         0x80171158
    // 0x8016E00C: nop

    func_80171158_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016E00C: nop

    after_2:
    // 0x8016E010: b           L_8016E27C
    // 0x8016E014: nop

        goto L_8016E27C;
    // 0x8016E014: nop

L_8016E018:
    // 0x8016E018: jal         0x8017091C
    // 0x8016E01C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8017091C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8016E01C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8016E020: jal         0x8017059C
    // 0x8016E024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8017059C_1501A0(rdram, ctx);
        goto after_4;
    // 0x8016E024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8016E028: jal         0x8016ECF8
    // 0x8016E02C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_5;
    // 0x8016E02C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8016E030: jal         0x8016E520
    // 0x8016E034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016E520_1501A0(rdram, ctx);
        goto after_6;
    // 0x8016E034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8016E038: jal         0x80170E6C
    // 0x8016E03C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80170E6C_1501A0(rdram, ctx);
        goto after_7;
    // 0x8016E03C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8016E040: jal         0x8016ED94
    // 0x8016E044: nop

    func_8016ED94_1501A0(rdram, ctx);
        goto after_8;
    // 0x8016E044: nop

    after_8:
    // 0x8016E048: jal         0x8016E290
    // 0x8016E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016E290_1501A0(rdram, ctx);
        goto after_9;
    // 0x8016E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8016E050: b           L_8016E27C
    // 0x8016E054: nop

        goto L_8016E27C;
    // 0x8016E054: nop

L_8016E058:
    // 0x8016E058: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E05C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E060: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8016E064: bne         $t7, $zero, L_8016E07C
    if (ctx->r15 != 0) {
        // 0x8016E068: nop
    
            goto L_8016E07C;
    }
    // 0x8016E068: nop

    // 0x8016E06C: jal         0x80171158
    // 0x8016E070: nop

    func_80171158_1501A0(rdram, ctx);
        goto after_10;
    // 0x8016E070: nop

    after_10:
    // 0x8016E074: b           L_8016E27C
    // 0x8016E078: nop

        goto L_8016E27C;
    // 0x8016E078: nop

L_8016E07C:
    // 0x8016E07C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E080: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x8016E084: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8016E088: beq         $t8, $zero, L_8016E27C
    if (ctx->r24 == 0) {
        // 0x8016E08C: nop
    
            goto L_8016E27C;
    }
    // 0x8016E08C: nop

L_8016E090:
    // 0x8016E090: jal         0x8017091C
    // 0x8016E094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8017091C_1501A0(rdram, ctx);
        goto after_11;
    // 0x8016E094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x8016E098: jal         0x8017059C
    // 0x8016E09C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8017059C_1501A0(rdram, ctx);
        goto after_12;
    // 0x8016E09C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x8016E0A0: jal         0x8016ECF8
    // 0x8016E0A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_13;
    // 0x8016E0A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x8016E0A8: jal         0x8016E520
    // 0x8016E0AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8016E520_1501A0(rdram, ctx);
        goto after_14;
    // 0x8016E0AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x8016E0B0: jal         0x80170E6C
    // 0x8016E0B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80170E6C_1501A0(rdram, ctx);
        goto after_15;
    // 0x8016E0B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x8016E0B8: jal         0x8016EED8
    // 0x8016E0BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8016EED8_1501A0(rdram, ctx);
        goto after_16;
    // 0x8016E0BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x8016E0C0: jal         0x8016E290
    // 0x8016E0C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8016E290_1501A0(rdram, ctx);
        goto after_17;
    // 0x8016E0C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x8016E0C8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8016E0CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E0D0: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8016E0D4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8016E0D8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8016E0DC: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8016E0E0: bne         $at, $zero, L_8016E090
    if (ctx->r1 != 0) {
        // 0x8016E0E4: nop
    
            goto L_8016E090;
    }
    // 0x8016E0E4: nop

    // 0x8016E0E8: b           L_8016E27C
    // 0x8016E0EC: nop

        goto L_8016E27C;
    // 0x8016E0EC: nop

L_8016E0F0:
    // 0x8016E0F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E0F4: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8016E0F8: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8016E0FC: bne         $t3, $zero, L_8016E130
    if (ctx->r11 != 0) {
        // 0x8016E100: nop
    
            goto L_8016E130;
    }
    // 0x8016E100: nop

    // 0x8016E104: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E108: lw          $t4, -0x2BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BA0);
    // 0x8016E10C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8016E110: beq         $t5, $zero, L_8016E120
    if (ctx->r13 == 0) {
        // 0x8016E114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016E120;
    }
    // 0x8016E114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E118: bne         $t5, $at, L_8016E1B4
    if (ctx->r13 != ctx->r1) {
        // 0x8016E11C: nop
    
            goto L_8016E1B4;
    }
    // 0x8016E11C: nop

L_8016E120:
    // 0x8016E120: jal         0x80171158
    // 0x8016E124: nop

    func_80171158_1501A0(rdram, ctx);
        goto after_18;
    // 0x8016E124: nop

    after_18:
    // 0x8016E128: b           L_8016E1B4
    // 0x8016E12C: nop

        goto L_8016E1B4;
    // 0x8016E12C: nop

L_8016E130:
    // 0x8016E130: jal         0x8017091C
    // 0x8016E134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8017091C_1501A0(rdram, ctx);
        goto after_19;
    // 0x8016E134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x8016E138: jal         0x8017059C
    // 0x8016E13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8017059C_1501A0(rdram, ctx);
        goto after_20;
    // 0x8016E13C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8016E140: jal         0x8016ECF8
    // 0x8016E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_21;
    // 0x8016E144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x8016E148: jal         0x8016E520
    // 0x8016E14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016E520_1501A0(rdram, ctx);
        goto after_22;
    // 0x8016E14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8016E150: jal         0x80170E6C
    // 0x8016E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80170E6C_1501A0(rdram, ctx);
        goto after_23;
    // 0x8016E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x8016E158: jal         0x8016F118
    // 0x8016E15C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016F118_1501A0(rdram, ctx);
        goto after_24;
    // 0x8016E15C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8016E160: jal         0x8016E290
    // 0x8016E164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8016E290_1501A0(rdram, ctx);
        goto after_25;
    // 0x8016E164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8016E168: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E16C: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8016E170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E174: beq         $t6, $at, L_8016E1B4
    if (ctx->r14 == ctx->r1) {
        // 0x8016E178: nop
    
            goto L_8016E1B4;
    }
    // 0x8016E178: nop

    // 0x8016E17C: jal         0x8017091C
    // 0x8016E180: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8017091C_1501A0(rdram, ctx);
        goto after_26;
    // 0x8016E180: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_26:
    // 0x8016E184: jal         0x8017059C
    // 0x8016E188: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8017059C_1501A0(rdram, ctx);
        goto after_27;
    // 0x8016E188: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_27:
    // 0x8016E18C: jal         0x8016ECF8
    // 0x8016E190: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_28;
    // 0x8016E190: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_28:
    // 0x8016E194: jal         0x8016E520
    // 0x8016E198: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8016E520_1501A0(rdram, ctx);
        goto after_29;
    // 0x8016E198: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_29:
    // 0x8016E19C: jal         0x80170E6C
    // 0x8016E1A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80170E6C_1501A0(rdram, ctx);
        goto after_30;
    // 0x8016E1A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_30:
    // 0x8016E1A4: jal         0x8016F118
    // 0x8016E1A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8016F118_1501A0(rdram, ctx);
        goto after_31;
    // 0x8016E1A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_31:
    // 0x8016E1AC: jal         0x8016E290
    // 0x8016E1B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8016E290_1501A0(rdram, ctx);
        goto after_32;
    // 0x8016E1B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_32:
L_8016E1B4:
    // 0x8016E1B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E1B8: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8016E1BC: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8016E1C0: bne         $t8, $zero, L_8016E1F8
    if (ctx->r24 != 0) {
        // 0x8016E1C4: nop
    
            goto L_8016E1F8;
    }
    // 0x8016E1C4: nop

    // 0x8016E1C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E1CC: lw          $t9, -0x2BA0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BA0);
    // 0x8016E1D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016E1D4: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8016E1D8: beq         $t0, $at, L_8016E1E8
    if (ctx->r8 == ctx->r1) {
        // 0x8016E1DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016E1E8;
    }
    // 0x8016E1DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016E1E0: bne         $t0, $at, L_8016E27C
    if (ctx->r8 != ctx->r1) {
        // 0x8016E1E4: nop
    
            goto L_8016E27C;
    }
    // 0x8016E1E4: nop

L_8016E1E8:
    // 0x8016E1E8: jal         0x80171158
    // 0x8016E1EC: nop

    func_80171158_1501A0(rdram, ctx);
        goto after_33;
    // 0x8016E1EC: nop

    after_33:
    // 0x8016E1F0: b           L_8016E27C
    // 0x8016E1F4: nop

        goto L_8016E27C;
    // 0x8016E1F4: nop

L_8016E1F8:
    // 0x8016E1F8: jal         0x8017091C
    // 0x8016E1FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8017091C_1501A0(rdram, ctx);
        goto after_34;
    // 0x8016E1FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x8016E200: jal         0x8017059C
    // 0x8016E204: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8017059C_1501A0(rdram, ctx);
        goto after_35;
    // 0x8016E204: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x8016E208: jal         0x8016ECF8
    // 0x8016E20C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_36;
    // 0x8016E20C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x8016E210: jal         0x8016E520
    // 0x8016E214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8016E520_1501A0(rdram, ctx);
        goto after_37;
    // 0x8016E214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_37:
    // 0x8016E218: jal         0x80170E6C
    // 0x8016E21C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80170E6C_1501A0(rdram, ctx);
        goto after_38;
    // 0x8016E21C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_38:
    // 0x8016E220: jal         0x8016F118
    // 0x8016E224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8016F118_1501A0(rdram, ctx);
        goto after_39;
    // 0x8016E224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_39:
    // 0x8016E228: jal         0x8016E290
    // 0x8016E22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8016E290_1501A0(rdram, ctx);
        goto after_40;
    // 0x8016E22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_40:
    // 0x8016E230: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E234: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8016E238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E23C: beq         $t1, $at, L_8016E27C
    if (ctx->r9 == ctx->r1) {
        // 0x8016E240: nop
    
            goto L_8016E27C;
    }
    // 0x8016E240: nop

    // 0x8016E244: jal         0x8017091C
    // 0x8016E248: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8017091C_1501A0(rdram, ctx);
        goto after_41;
    // 0x8016E248: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_41:
    // 0x8016E24C: jal         0x8017059C
    // 0x8016E250: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8017059C_1501A0(rdram, ctx);
        goto after_42;
    // 0x8016E250: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_42:
    // 0x8016E254: jal         0x8016ECF8
    // 0x8016E258: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8016ECF8_1501A0(rdram, ctx);
        goto after_43;
    // 0x8016E258: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_43:
    // 0x8016E25C: jal         0x8016E520
    // 0x8016E260: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8016E520_1501A0(rdram, ctx);
        goto after_44;
    // 0x8016E260: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_44:
    // 0x8016E264: jal         0x80170E6C
    // 0x8016E268: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80170E6C_1501A0(rdram, ctx);
        goto after_45;
    // 0x8016E268: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_45:
    // 0x8016E26C: jal         0x8016F118
    // 0x8016E270: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8016F118_1501A0(rdram, ctx);
        goto after_46;
    // 0x8016E270: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_46:
    // 0x8016E274: jal         0x8016E290
    // 0x8016E278: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8016E290_1501A0(rdram, ctx);
        goto after_47;
    // 0x8016E278: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_47:
L_8016E27C:
    // 0x8016E27C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016E280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016E284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016E288: jr          $ra
    // 0x8016E28C: nop

    return;
    // 0x8016E28C: nop

;}
RECOMP_FUNC void func_8016E290_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E290: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016E294: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8016E298: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8016E29C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E2A0: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8016E2A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016E2A8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E2AC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8016E2B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016E2B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8016E2B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8016E2BC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016E2C0: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x8016E2C4: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x8016E2C8: beq         $t1, $zero, L_8016E440
    if (ctx->r9 == 0) {
        // 0x8016E2CC: nop
    
            goto L_8016E440;
    }
    // 0x8016E2CC: nop

    // 0x8016E2D0: andi        $t2, $t0, 0xEFFF
    ctx->r10 = ctx->r8 & 0XEFFF;
    // 0x8016E2D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E2D8: sh          $t2, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r10;
    // 0x8016E2DC: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x8016E2E0: lbu         $t4, 0xA($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XA);
    // 0x8016E2E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E2E8: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8016E2EC: andi        $t5, $t4, 0xFD
    ctx->r13 = ctx->r12 & 0XFD;
    // 0x8016E2F0: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8016E2F4: sb          $t6, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r14;
    // 0x8016E2F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E2FC: sb          $zero, 0xD($t7)
    MEM_B(0XD, ctx->r15) = 0;
    // 0x8016E300: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8016E304: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E308: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8016E30C: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
    // 0x8016E310: lw          $s1, 0x20($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X20);
    // 0x8016E314: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E318: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016E31C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E320: sw          $s1, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r17;
    // 0x8016E324: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8016E328: sw          $s0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r16;
    // 0x8016E32C: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8016E330: sw          $s0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r16;
    // 0x8016E334: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8016E338: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E33C: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8016E340: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8016E344: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8016E348: sll         $t4, $t4, 6
    ctx->r12 = S32(ctx->r12 << 6);
    // 0x8016E34C: sw          $t4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r12;
    // 0x8016E350: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8016E354: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8016E358: beq         $s0, $zero, L_8016E378
    if (ctx->r16 == 0) {
        // 0x8016E35C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8016E378;
    }
    // 0x8016E35C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016E360: beq         $s0, $at, L_8016E388
    if (ctx->r16 == ctx->r1) {
        // 0x8016E364: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016E388;
    }
    // 0x8016E364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E368: beq         $s0, $at, L_8016E3A8
    if (ctx->r16 == ctx->r1) {
        // 0x8016E36C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016E3A8;
    }
    // 0x8016E36C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016E370: bne         $s0, $at, L_8016E3DC
    if (ctx->r16 != ctx->r1) {
        // 0x8016E374: nop
    
            goto L_8016E3DC;
    }
    // 0x8016E374: nop

L_8016E378:
    // 0x8016E378: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E37C: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016E380: b           L_8016E3DC
    // 0x8016E384: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
        goto L_8016E3DC;
    // 0x8016E384: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
L_8016E388:
    // 0x8016E388: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8016E38C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E390: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8016E394: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8016E398: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016E39C: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x8016E3A0: b           L_8016E3DC
    // 0x8016E3A4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
        goto L_8016E3DC;
    // 0x8016E3A4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
L_8016E3A8:
    // 0x8016E3A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8016E3AC: beq         $t1, $zero, L_8016E3BC
    if (ctx->r9 == 0) {
        // 0x8016E3B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016E3BC;
    }
    // 0x8016E3B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E3B4: bne         $t1, $at, L_8016E3CC
    if (ctx->r9 != ctx->r1) {
        // 0x8016E3B8: nop
    
            goto L_8016E3CC;
    }
    // 0x8016E3B8: nop

L_8016E3BC:
    // 0x8016E3BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E3C0: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016E3C4: b           L_8016E3DC
    // 0x8016E3C8: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
        goto L_8016E3DC;
    // 0x8016E3C8: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
L_8016E3CC:
    // 0x8016E3CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E3D0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8016E3D4: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x8016E3D8: sw          $t2, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r10;
L_8016E3DC:
    // 0x8016E3DC: jal         0x800C3204
    // 0x8016E3E0: nop

    func_800C3204(rdram, ctx);
        goto after_0;
    // 0x8016E3E0: nop

    after_0:
    // 0x8016E3E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E3E8: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x8016E3EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8016E3F0: beq         $t4, $zero, L_8016E430
    if (ctx->r12 == 0) {
        // 0x8016E3F4: nop
    
            goto L_8016E430;
    }
    // 0x8016E3F4: nop

L_8016E3F8:
    // 0x8016E3F8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8016E3FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E400: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8016E404: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8016E408: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8016E40C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8016E410: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E414: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    // 0x8016E418: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8016E41C: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x8016E420: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8016E424: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x8016E428: bne         $at, $zero, L_8016E3F8
    if (ctx->r1 != 0) {
        // 0x8016E42C: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_8016E3F8;
    }
    // 0x8016E42C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_8016E430:
    // 0x8016E430: jal         0x800CB8C8
    // 0x8016E434: nop

    func_800CB8C8(rdram, ctx);
        goto after_1;
    // 0x8016E434: nop

    after_1:
    // 0x8016E438: jal         0x800D1680
    // 0x8016E43C: nop

    func_800D1680(rdram, ctx);
        goto after_2;
    // 0x8016E43C: nop

    after_2:
L_8016E440:
    // 0x8016E440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016E444: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8016E448: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8016E44C: jr          $ra
    // 0x8016E450: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8016E450: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8016E454_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E454: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8016E458: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x8016E45C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016E460: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8016E464: bne         $t7, $zero, L_8016E518
    if (ctx->r15 != 0) {
        // 0x8016E468: nop
    
            goto L_8016E518;
    }
    // 0x8016E468: nop

    // 0x8016E46C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E470: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x8016E474: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x8016E478: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8016E47C: bne         $t0, $zero, L_8016E518
    if (ctx->r8 != 0) {
        // 0x8016E480: nop
    
            goto L_8016E518;
    }
    // 0x8016E480: nop

    // 0x8016E484: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E488: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8016E48C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8016E490: beq         $t1, $zero, L_8016E518
    if (ctx->r9 == 0) {
        // 0x8016E494: nop
    
            goto L_8016E518;
    }
    // 0x8016E494: nop

L_8016E498:
    // 0x8016E498: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8016E49C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E4A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8016E4A4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016E4A8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8016E4AC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016E4B0: lhu         $t4, -0x41DE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41DE);
    // 0x8016E4B4: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x8016E4B8: beq         $t5, $zero, L_8016E4F8
    if (ctx->r13 == 0) {
        // 0x8016E4BC: nop
    
            goto L_8016E4F8;
    }
    // 0x8016E4BC: nop

    // 0x8016E4C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E4C4: lhu         $t6, -0x2BA8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2BA8);
    // 0x8016E4C8: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8016E4CC: bne         $t7, $zero, L_8016E4E4
    if (ctx->r15 != 0) {
        // 0x8016E4D0: nop
    
            goto L_8016E4E4;
    }
    // 0x8016E4D0: nop

    // 0x8016E4D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E4D8: lw          $t8, -0x2D68($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D68);
    // 0x8016E4DC: beq         $t8, $zero, L_8016E4F8
    if (ctx->r24 == 0) {
        // 0x8016E4E0: nop
    
            goto L_8016E4F8;
    }
    // 0x8016E4E0: nop

L_8016E4E4:
    // 0x8016E4E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E4E8: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8016E4EC: lbu         $t0, 0xE($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XE);
    // 0x8016E4F0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8016E4F4: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
L_8016E4F8:
    // 0x8016E4F8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8016E4FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E500: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x8016E504: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8016E508: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8016E50C: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x8016E510: bne         $at, $zero, L_8016E498
    if (ctx->r1 != 0) {
        // 0x8016E514: nop
    
            goto L_8016E498;
    }
    // 0x8016E514: nop

L_8016E518:
    // 0x8016E518: jr          $ra
    // 0x8016E51C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016E51C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016E520_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E520: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x8016E524: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E528: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8016E52C: lw          $t9, 0x39A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X39A0);
    // 0x8016E530: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016E534: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016E538: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8016E53C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8016E540: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8016E544: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8016E548: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E54C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016E550: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8016E554: lhu         $t2, -0xD4A($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0XD4A);
    // 0x8016E558: lhu         $t4, -0x41DE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41DE);
    // 0x8016E55C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8016E560: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016E564: sllv        $t7, $t6, $a0
    ctx->r15 = S32(ctx->r14 << (ctx->r4 & 31));
    // 0x8016E568: and         $t5, $t2, $t4
    ctx->r13 = ctx->r10 & ctx->r12;
    // 0x8016E56C: beq         $t5, $zero, L_8016E590
    if (ctx->r13 == 0) {
        // 0x8016E570: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_8016E590;
    }
    // 0x8016E570: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8016E574: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E578: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8016E57C: lbu         $t8, 0xA($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XA);
    // 0x8016E580: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E584: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8016E588: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8016E58C: sb          $t9, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r25;
L_8016E590:
    // 0x8016E590: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E594: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8016E598: lbu         $t3, 0xA($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0XA);
    // 0x8016E59C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8016E5A0: and         $t4, $t3, $t2
    ctx->r12 = ctx->r11 & ctx->r10;
    // 0x8016E5A4: beq         $t4, $zero, L_8016E75C
    if (ctx->r12 == 0) {
        // 0x8016E5A8: nop
    
            goto L_8016E75C;
    }
    // 0x8016E5A8: nop

    // 0x8016E5AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E5B0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E5B4: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016E5B8: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x8016E5BC: lw          $t7, 0x64($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X64);
    // 0x8016E5C0: blez        $t7, L_8016E610
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8016E5C4: nop
    
            goto L_8016E610;
    }
    // 0x8016E5C4: nop

    // 0x8016E5C8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016E5CC: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x8016E5D0: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x8016E5D4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8016E5D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E5DC: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E5E0: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8016E5E4: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016E5E8: addiu       $t3, $t1, -0x1E
    ctx->r11 = ADD32(ctx->r9, -0X1E);
    // 0x8016E5EC: sw          $t3, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->r11;
    // 0x8016E5F0: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8016E5F4: lw          $t9, 0x64($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X64);
    // 0x8016E5F8: bgez        $t9, L_8016E65C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8016E5FC: nop
    
            goto L_8016E65C;
    }
    // 0x8016E5FC: nop

    // 0x8016E600: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016E604: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8016E608: b           L_8016E65C
    // 0x8016E60C: sw          $zero, 0x64($t1)
    MEM_W(0X64, ctx->r9) = 0;
        goto L_8016E65C;
    // 0x8016E60C: sw          $zero, 0x64($t1)
    MEM_W(0X64, ctx->r9) = 0;
L_8016E610:
    // 0x8016E610: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E614: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E618: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8016E61C: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E620: lw          $t4, 0x64($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X64);
    // 0x8016E624: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8016E628: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E62C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E630: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8016E634: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016E638: addiu       $t5, $t4, 0x1E
    ctx->r13 = ADD32(ctx->r12, 0X1E);
    // 0x8016E63C: sw          $t5, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->r13;
    // 0x8016E640: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8016E644: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x8016E648: blez        $t2, L_8016E65C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8016E64C: nop
    
            goto L_8016E65C;
    }
    // 0x8016E64C: nop

    // 0x8016E650: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016E654: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x8016E658: sw          $zero, 0x64($t4)
    MEM_W(0X64, ctx->r12) = 0;
L_8016E65C:
    // 0x8016E65C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E660: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E664: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8016E668: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E66C: lw          $t9, 0x74($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X74);
    // 0x8016E670: blez        $t9, L_8016E6C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8016E674: nop
    
            goto L_8016E6C0;
    }
    // 0x8016E674: nop

    // 0x8016E678: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016E67C: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x8016E680: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x8016E684: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016E688: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E68C: addu        $t4, $t8, $t6
    ctx->r12 = ADD32(ctx->r24, ctx->r14);
    // 0x8016E690: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8016E694: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8016E698: addiu       $t3, $t2, -0x1E
    ctx->r11 = ADD32(ctx->r10, -0X1E);
    // 0x8016E69C: sw          $t3, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->r11;
    // 0x8016E6A0: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8016E6A4: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8016E6A8: bgez        $t0, L_8016E70C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8016E6AC: nop
    
            goto L_8016E70C;
    }
    // 0x8016E6AC: nop

    // 0x8016E6B0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016E6B4: addu        $t2, $t1, $t5
    ctx->r10 = ADD32(ctx->r9, ctx->r13);
    // 0x8016E6B8: b           L_8016E70C
    // 0x8016E6BC: sw          $zero, 0x74($t2)
    MEM_W(0X74, ctx->r10) = 0;
        goto L_8016E70C;
    // 0x8016E6BC: sw          $zero, 0x74($t2)
    MEM_W(0X74, ctx->r10) = 0;
L_8016E6C0:
    // 0x8016E6C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E6C4: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E6C8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016E6CC: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8016E6D0: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x8016E6D4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016E6D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E6DC: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x8016E6E0: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8016E6E4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016E6E8: addiu       $t7, $t4, 0x1E
    ctx->r15 = ADD32(ctx->r12, 0X1E);
    // 0x8016E6EC: sw          $t7, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r15;
    // 0x8016E6F0: addu        $t2, $t1, $t5
    ctx->r10 = ADD32(ctx->r9, ctx->r13);
    // 0x8016E6F4: lw          $t8, 0x74($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X74);
    // 0x8016E6F8: blez        $t8, L_8016E70C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8016E6FC: nop
    
            goto L_8016E70C;
    }
    // 0x8016E6FC: nop

    // 0x8016E700: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016E704: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8016E708: sw          $zero, 0x74($t4)
    MEM_W(0X74, ctx->r12) = 0;
L_8016E70C:
    // 0x8016E70C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E710: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8016E714: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016E718: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8016E71C: lw          $t0, 0x64($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X64);
    // 0x8016E720: bne         $t0, $zero, L_8016ECF0
    if (ctx->r8 != 0) {
        // 0x8016E724: nop
    
            goto L_8016ECF0;
    }
    // 0x8016E724: nop

    // 0x8016E728: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016E72C: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8016E730: lw          $t8, 0x74($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X74);
    // 0x8016E734: bne         $t8, $zero, L_8016ECF0
    if (ctx->r24 != 0) {
        // 0x8016E738: nop
    
            goto L_8016ECF0;
    }
    // 0x8016E738: nop

    // 0x8016E73C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E740: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8016E744: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x8016E748: lbu         $t5, 0xA($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XA);
    // 0x8016E74C: xori        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 ^ 0XFF;
    // 0x8016E750: and         $t7, $t5, $t9
    ctx->r15 = ctx->r13 & ctx->r25;
    // 0x8016E754: b           L_8016ECF0
    // 0x8016E758: sb          $t7, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r15;
        goto L_8016ECF0;
    // 0x8016E758: sb          $t7, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r15;
L_8016E75C:
    // 0x8016E75C: sll         $t0, $a0, 5
    ctx->r8 = S32(ctx->r4 << 5);
    // 0x8016E760: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E764: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8016E768: lw          $t1, 0x39A4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X39A4);
    // 0x8016E76C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8016E770: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E774: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8016E778: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E77C: lw          $t2, -0xD30($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XD30);
    // 0x8016E780: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8016E784: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x8016E788: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8016E78C: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x8016E790: sw          $t2, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r10;
    // 0x8016E794: lw          $a1, 0x39A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39A0);
    // 0x8016E798: beq         $a1, $zero, L_8016E7C0
    if (ctx->r5 == 0) {
        // 0x8016E79C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8016E7C0;
    }
    // 0x8016E79C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016E7A0: beq         $a1, $at, L_8016E80C
    if (ctx->r5 == ctx->r1) {
        // 0x8016E7A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016E80C;
    }
    // 0x8016E7A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016E7A8: beq         $a1, $at, L_8016E85C
    if (ctx->r5 == ctx->r1) {
        // 0x8016E7AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016E85C;
    }
    // 0x8016E7AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016E7B0: beq         $a1, $at, L_8016E94C
    if (ctx->r5 == ctx->r1) {
        // 0x8016E7B4: nop
    
            goto L_8016E94C;
    }
    // 0x8016E7B4: nop

    // 0x8016E7B8: b           L_8016EA38
    // 0x8016E7BC: nop

        goto L_8016EA38;
    // 0x8016E7BC: nop

L_8016E7C0:
    // 0x8016E7C0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016E7C4: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8016E7C8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8016E7CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E7D0: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8016E7D4: lb          $t9, -0x41DA($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X41DA);
    // 0x8016E7D8: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016E7DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E7E0: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016E7E4: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8016E7E8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8016E7EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E7F0: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8016E7F4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8016E7F8: lb          $t0, -0x41D9($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X41D9);
    // 0x8016E7FC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E800: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8016E804: b           L_8016EA38
    // 0x8016E808: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
        goto L_8016EA38;
    // 0x8016E808: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
L_8016E80C:
    // 0x8016E80C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016E810: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016E814: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8016E818: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E81C: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E820: lb          $t2, -0x41DA($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X41DA);
    // 0x8016E824: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016E828: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E82C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016E830: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8016E834: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8016E838: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E83C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8016E840: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8016E844: lb          $t5, -0x41D9($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41D9);
    // 0x8016E848: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E84C: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8016E850: negu        $t9, $t5
    ctx->r25 = SUB32(0, ctx->r13);
    // 0x8016E854: b           L_8016EA38
    // 0x8016E858: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
        goto L_8016EA38;
    // 0x8016E858: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_8016E85C:
    // 0x8016E85C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E860: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8016E864: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E868: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8016E86C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8016E870: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8016E874: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016E878: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016E87C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8016E880: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E884: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E888: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8016E88C: lhu         $t2, -0x41E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41E0);
    // 0x8016E890: andi        $t8, $t2, 0x100
    ctx->r24 = ctx->r10 & 0X100;
    // 0x8016E894: beq         $t8, $zero, L_8016E8AC
    if (ctx->r24 == 0) {
        // 0x8016E898: nop
    
            goto L_8016E8AC;
    }
    // 0x8016E898: nop

    // 0x8016E89C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E8A0: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8016E8A4: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x8016E8A8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_8016E8AC:
    // 0x8016E8AC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016E8B0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016E8B4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8016E8B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E8BC: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x8016E8C0: lhu         $t7, -0x41E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X41E0);
    // 0x8016E8C4: andi        $t3, $t7, 0x200
    ctx->r11 = ctx->r15 & 0X200;
    // 0x8016E8C8: beq         $t3, $zero, L_8016E8E0
    if (ctx->r11 == 0) {
        // 0x8016E8CC: nop
    
            goto L_8016E8E0;
    }
    // 0x8016E8CC: nop

    // 0x8016E8D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E8D4: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8016E8D8: addiu       $t1, $zero, -0x28
    ctx->r9 = ADD32(0, -0X28);
    // 0x8016E8DC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_8016E8E0:
    // 0x8016E8E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016E8E4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016E8E8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8016E8EC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E8F0: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016E8F4: lhu         $t2, -0x41E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41E0);
    // 0x8016E8F8: andi        $t8, $t2, 0x400
    ctx->r24 = ctx->r10 & 0X400;
    // 0x8016E8FC: beq         $t8, $zero, L_8016E914
    if (ctx->r24 == 0) {
        // 0x8016E900: nop
    
            goto L_8016E914;
    }
    // 0x8016E900: nop

    // 0x8016E904: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E908: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8016E90C: addiu       $t4, $zero, -0x28
    ctx->r12 = ADD32(0, -0X28);
    // 0x8016E910: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_8016E914:
    // 0x8016E914: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016E918: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016E91C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8016E920: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E924: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x8016E928: lhu         $t7, -0x41E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X41E0);
    // 0x8016E92C: andi        $t3, $t7, 0x800
    ctx->r11 = ctx->r15 & 0X800;
    // 0x8016E930: beq         $t3, $zero, L_8016EA38
    if (ctx->r11 == 0) {
        // 0x8016E934: nop
    
            goto L_8016EA38;
    }
    // 0x8016E934: nop

    // 0x8016E938: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E93C: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8016E940: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8016E944: b           L_8016EA38
    // 0x8016E948: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
        goto L_8016EA38;
    // 0x8016E948: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
L_8016E94C:
    // 0x8016E94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E950: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x8016E954: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E958: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8016E95C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8016E960: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8016E964: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016E968: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016E96C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8016E970: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E974: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8016E978: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8016E97C: lhu         $t5, -0x41E0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41E0);
    // 0x8016E980: andi        $t9, $t5, 0x100
    ctx->r25 = ctx->r13 & 0X100;
    // 0x8016E984: beq         $t9, $zero, L_8016E99C
    if (ctx->r25 == 0) {
        // 0x8016E988: nop
    
            goto L_8016E99C;
    }
    // 0x8016E988: nop

    // 0x8016E98C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E990: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8016E994: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8016E998: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
L_8016E99C:
    // 0x8016E99C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016E9A0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016E9A4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8016E9A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E9AC: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x8016E9B0: lhu         $t0, -0x41E0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X41E0);
    // 0x8016E9B4: andi        $t6, $t0, 0x200
    ctx->r14 = ctx->r8 & 0X200;
    // 0x8016E9B8: beq         $t6, $zero, L_8016E9D0
    if (ctx->r14 == 0) {
        // 0x8016E9BC: nop
    
            goto L_8016E9D0;
    }
    // 0x8016E9BC: nop

    // 0x8016E9C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E9C4: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8016E9C8: addiu       $t8, $zero, -0x28
    ctx->r24 = ADD32(0, -0X28);
    // 0x8016E9CC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8016E9D0:
    // 0x8016E9D0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016E9D4: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016E9D8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8016E9DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E9E0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8016E9E4: lhu         $t5, -0x41E0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41E0);
    // 0x8016E9E8: andi        $t9, $t5, 0x400
    ctx->r25 = ctx->r13 & 0X400;
    // 0x8016E9EC: beq         $t9, $zero, L_8016EA04
    if (ctx->r25 == 0) {
        // 0x8016E9F0: nop
    
            goto L_8016EA04;
    }
    // 0x8016E9F0: nop

    // 0x8016E9F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E9F8: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8016E9FC: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8016EA00: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
L_8016EA04:
    // 0x8016EA04: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016EA08: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016EA0C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8016EA10: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EA14: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x8016EA18: lhu         $t0, -0x41E0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X41E0);
    // 0x8016EA1C: andi        $t6, $t0, 0x800
    ctx->r14 = ctx->r8 & 0X800;
    // 0x8016EA20: beq         $t6, $zero, L_8016EA38
    if (ctx->r14 == 0) {
        // 0x8016EA24: nop
    
            goto L_8016EA38;
    }
    // 0x8016EA24: nop

    // 0x8016EA28: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EA2C: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8016EA30: addiu       $t8, $zero, -0x28
    ctx->r24 = ADD32(0, -0X28);
    // 0x8016EA34: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
L_8016EA38:
    // 0x8016EA38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EA3C: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8016EA40: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8016EA44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EA48: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8016EA4C: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8016EA50: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x8016EA54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EA58: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8016EA5C: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x8016EA60: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8016EA64: bgez        $t1, L_8016EA84
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8016EA68: nop
    
            goto L_8016EA84;
    }
    // 0x8016EA68: nop

    // 0x8016EA6C: negu        $t0, $t1
    ctx->r8 = SUB32(0, ctx->r9);
    // 0x8016EA70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016EA74: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8016EA78: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x8016EA7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8016EA80: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
L_8016EA84:
    // 0x8016EA84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EA88: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8016EA8C: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8016EA90: bgez        $t4, L_8016EAB0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8016EA94: nop
    
            goto L_8016EAB0;
    }
    // 0x8016EA94: nop

    // 0x8016EA98: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8016EA9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EAA0: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8016EAA4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8016EAA8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8016EAAC: sw          $t7, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r15;
L_8016EAB0:
    // 0x8016EAB0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EAB4: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8016EAB8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8016EABC: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x8016EAC0: bne         $at, $zero, L_8016EAFC
    if (ctx->r1 != 0) {
        // 0x8016EAC4: nop
    
            goto L_8016EAFC;
    }
    // 0x8016EAC4: nop

    // 0x8016EAC8: lw          $t3, 0x28($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X28);
    // 0x8016EACC: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x8016EAD0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EAD4: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8016EAD8: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EADC: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016EAE0: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x8016EAE4: lw          $t7, 0x64($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X64);
    // 0x8016EAE8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016EAEC: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x8016EAF0: mflo        $t8
    ctx->r24 = lo;
    // 0x8016EAF4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016EAF8: sw          $t9, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->r25;
L_8016EAFC:
    // 0x8016EAFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EB00: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8016EB04: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x8016EB08: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8016EB0C: bne         $at, $zero, L_8016EB48
    if (ctx->r1 != 0) {
        // 0x8016EB10: nop
    
            goto L_8016EB48;
    }
    // 0x8016EB10: nop

    // 0x8016EB14: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x8016EB18: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x8016EB1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EB20: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8016EB24: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EB28: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016EB2C: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x8016EB30: lw          $t9, 0x74($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X74);
    // 0x8016EB34: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016EB38: addu        $t3, $t6, $t0
    ctx->r11 = ADD32(ctx->r14, ctx->r8);
    // 0x8016EB3C: mflo        $t7
    ctx->r15 = lo;
    // 0x8016EB40: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x8016EB44: sw          $t1, 0x74($t3)
    MEM_W(0X74, ctx->r11) = ctx->r9;
L_8016EB48:
    // 0x8016EB48: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EB4C: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8016EB50: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8016EB54: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x8016EB58: bne         $at, $zero, L_8016EBBC
    if (ctx->r1 != 0) {
        // 0x8016EB5C: slti        $at, $t2, 0x40
        ctx->r1 = SIGNED(ctx->r10) < 0X40 ? 1 : 0;
            goto L_8016EBBC;
    }
    // 0x8016EB5C: slti        $at, $t2, 0x40
    ctx->r1 = SIGNED(ctx->r10) < 0X40 ? 1 : 0;
    // 0x8016EB60: beq         $at, $zero, L_8016EBBC
    if (ctx->r1 == 0) {
        // 0x8016EB64: nop
    
            goto L_8016EBBC;
    }
    // 0x8016EB64: nop

    // 0x8016EB68: lw          $t5, 0x28($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X28);
    // 0x8016EB6C: addiu       $t8, $t2, -0x5
    ctx->r24 = ADD32(ctx->r10, -0X5);
    // 0x8016EB70: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x8016EB74: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EB78: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x8016EB7C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EB80: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8016EB84: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016EB88: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x8016EB8C: lw          $t8, 0x64($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X64);
    // 0x8016EB90: mflo        $t9
    ctx->r25 = lo;
    // 0x8016EB94: nop

    // 0x8016EB98: nop

    // 0x8016EB9C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8016EBA0: mflo        $t7
    ctx->r15 = lo;
    // 0x8016EBA4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016EBA8: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8016EBAC: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EBB0: mflo        $t0
    ctx->r8 = lo;
    // 0x8016EBB4: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x8016EBB8: sw          $t5, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->r13;
L_8016EBBC:
    // 0x8016EBBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016EBC0: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8016EBC4: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8016EBC8: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8016EBCC: bne         $at, $zero, L_8016EC30
    if (ctx->r1 != 0) {
        // 0x8016EBD0: slti        $at, $t6, 0x40
        ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
            goto L_8016EC30;
    }
    // 0x8016EBD0: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8016EBD4: beq         $at, $zero, L_8016EC30
    if (ctx->r1 == 0) {
        // 0x8016EBD8: nop
    
            goto L_8016EC30;
    }
    // 0x8016EBD8: nop

    // 0x8016EBDC: lw          $t2, 0x28($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X28);
    // 0x8016EBE0: addiu       $t1, $t6, -0x5
    ctx->r9 = ADD32(ctx->r14, -0X5);
    // 0x8016EBE4: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x8016EBE8: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EBEC: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8016EBF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EBF4: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8016EBF8: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016EBFC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x8016EC00: lw          $t1, 0x74($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X74);
    // 0x8016EC04: mflo        $t8
    ctx->r24 = lo;
    // 0x8016EC08: nop

    // 0x8016EC0C: nop

    // 0x8016EC10: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8016EC14: mflo        $t0
    ctx->r8 = lo;
    // 0x8016EC18: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016EC1C: addu        $t7, $t8, $t4
    ctx->r15 = ADD32(ctx->r24, ctx->r12);
    // 0x8016EC20: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016EC24: mflo        $t3
    ctx->r11 = lo;
    // 0x8016EC28: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x8016EC2C: sw          $t2, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->r10;
L_8016EC30:
    // 0x8016EC30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EC34: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8016EC38: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016EC3C: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8016EC40: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x8016EC44: slti        $at, $t6, 0x81
    ctx->r1 = SIGNED(ctx->r14) < 0X81 ? 1 : 0;
    // 0x8016EC48: bne         $at, $zero, L_8016EC60
    if (ctx->r1 != 0) {
        // 0x8016EC4C: nop
    
            goto L_8016EC60;
    }
    // 0x8016EC4C: nop

    // 0x8016EC50: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016EC54: addu        $t8, $t3, $t9
    ctx->r24 = ADD32(ctx->r11, ctx->r25);
    // 0x8016EC58: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8016EC5C: sw          $t1, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->r9;
L_8016EC60:
    // 0x8016EC60: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EC64: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8016EC68: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016EC6C: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x8016EC70: lw          $t0, 0x64($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X64);
    // 0x8016EC74: slti        $at, $t0, -0x80
    ctx->r1 = SIGNED(ctx->r8) < -0X80 ? 1 : 0;
    // 0x8016EC78: beq         $at, $zero, L_8016EC90
    if (ctx->r1 == 0) {
        // 0x8016EC7C: nop
    
            goto L_8016EC90;
    }
    // 0x8016EC7C: nop

    // 0x8016EC80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016EC84: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x8016EC88: addiu       $t5, $zero, -0x80
    ctx->r13 = ADD32(0, -0X80);
    // 0x8016EC8C: sw          $t5, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r13;
L_8016EC90:
    // 0x8016EC90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EC94: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8016EC98: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016EC9C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8016ECA0: lw          $t4, 0x74($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X74);
    // 0x8016ECA4: slti        $at, $t4, 0x55
    ctx->r1 = SIGNED(ctx->r12) < 0X55 ? 1 : 0;
    // 0x8016ECA8: bne         $at, $zero, L_8016ECC0
    if (ctx->r1 != 0) {
        // 0x8016ECAC: nop
    
            goto L_8016ECC0;
    }
    // 0x8016ECAC: nop

    // 0x8016ECB0: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016ECB4: addu        $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
    // 0x8016ECB8: addiu       $t7, $zero, 0x54
    ctx->r15 = ADD32(0, 0X54);
    // 0x8016ECBC: sw          $t7, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r15;
L_8016ECC0:
    // 0x8016ECC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016ECC4: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8016ECC8: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8016ECCC: addu        $t3, $t2, $t5
    ctx->r11 = ADD32(ctx->r10, ctx->r13);
    // 0x8016ECD0: lw          $t9, 0x74($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X74);
    // 0x8016ECD4: slti        $at, $t9, -0x54
    ctx->r1 = SIGNED(ctx->r25) < -0X54 ? 1 : 0;
    // 0x8016ECD8: beq         $at, $zero, L_8016ECF0
    if (ctx->r1 == 0) {
        // 0x8016ECDC: nop
    
            goto L_8016ECF0;
    }
    // 0x8016ECDC: nop

    // 0x8016ECE0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016ECE4: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x8016ECE8: addiu       $t8, $zero, -0x54
    ctx->r24 = ADD32(0, -0X54);
    // 0x8016ECEC: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
L_8016ECF0:
    // 0x8016ECF0: jr          $ra
    // 0x8016ECF4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016ECF4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016ECF8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016ECF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016ECFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016ED00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016ED04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016ED08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016ED0C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016ED10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016ED14: lw          $t8, 0x39A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39A8);
    // 0x8016ED18: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8016ED1C: beq         $at, $zero, L_8016ED84
    if (ctx->r1 == 0) {
        // 0x8016ED20: nop
    
            goto L_8016ED84;
    }
    // 0x8016ED20: nop

    // 0x8016ED24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016ED28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8016ED2C: addu        $at, $at, $t8
    gpr jr_addend_8016ED34 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8016ED30: lw          $t8, -0x52C($at)
    ctx->r24 = ADD32(ctx->r1, -0X52C);
    // 0x8016ED34: jr          $t8
    // 0x8016ED38: nop

    switch (jr_addend_8016ED34 >> 2) {
        case 0: goto L_8016ED3C; break;
        case 1: goto L_8016ED4C; break;
        case 2: goto L_8016ED5C; break;
        case 3: goto L_8016ED6C; break;
        case 4: goto L_8016ED7C; break;
        default: switch_error(__func__, 0x8016ED34, 0x8019FAD4);
    }
    // 0x8016ED38: nop

L_8016ED3C:
    // 0x8016ED3C: jal         0x8016F618
    // 0x8016ED40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8016F618_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016ED40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8016ED44: b           L_8016ED84
    // 0x8016ED48: nop

        goto L_8016ED84;
    // 0x8016ED48: nop

L_8016ED4C:
    // 0x8016ED4C: jal         0x8016F9A4
    // 0x8016ED50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8016F9A4_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016ED50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016ED54: b           L_8016ED84
    // 0x8016ED58: nop

        goto L_8016ED84;
    // 0x8016ED58: nop

L_8016ED5C:
    // 0x8016ED5C: jal         0x8016FBCC
    // 0x8016ED60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8016FBCC_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016ED60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8016ED64: b           L_8016ED84
    // 0x8016ED68: nop

        goto L_8016ED84;
    // 0x8016ED68: nop

L_8016ED6C:
    // 0x8016ED6C: jal         0x8016FCD0
    // 0x8016ED70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8016FCD0_1501A0(rdram, ctx);
        goto after_3;
    // 0x8016ED70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8016ED74: b           L_8016ED84
    // 0x8016ED78: nop

        goto L_8016ED84;
    // 0x8016ED78: nop

L_8016ED7C:
    // 0x8016ED7C: jal         0x80170058
    // 0x8016ED80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80170058_1501A0(rdram, ctx);
        goto after_4;
    // 0x8016ED80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
L_8016ED84:
    // 0x8016ED84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016ED88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016ED8C: jr          $ra
    // 0x8016ED90: nop

    return;
    // 0x8016ED90: nop

;}
