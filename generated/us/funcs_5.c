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

RECOMP_FUNC void func_800D1454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1454: addiu       $sp, $sp, -0x830
    ctx->r29 = ADD32(ctx->r29, -0X830);
    // 0x800D1458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D145C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D1460: addiu       $a0, $a0, -0x4590
    ctx->r4 = ADD32(ctx->r4, -0X4590);
    // 0x800D1464: jal         0x800D2AB0
    // 0x800D1468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800D2AB0(rdram, ctx);
        goto after_0;
    // 0x800D1468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800D146C: lui         $t6, 0x802E
    ctx->r14 = S32(0X802E << 16);
    // 0x800D1470: ori         $t6, $t6, 0xA000
    ctx->r14 = ctx->r14 | 0XA000;
    // 0x800D1474: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1478: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D147C: sw          $t6, -0x3D58($at)
    MEM_W(-0X3D58, ctx->r1) = ctx->r14;
    // 0x800D1480: jal         0x800D2AE0
    // 0x800D1484: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    func_800D2AE0(rdram, ctx);
        goto after_1;
    // 0x800D1484: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    after_1:
    // 0x800D1488: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D148C: addiu       $t7, $t7, -0x45C0
    ctx->r15 = ADD32(ctx->r15, -0X45C0);
    // 0x800D1490: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1494: jal         0x800D18A0
    // 0x800D1498: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    func_800D18A0(rdram, ctx);
        goto after_2;
    // 0x800D1498: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    after_2:
    // 0x800D149C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D14A0: subu        $a1, $a0, $a0
    ctx->r5 = SUB32(ctx->r4, ctx->r4);
    // 0x800D14A4: lui         $t8, 0xF
    ctx->r24 = S32(0XF << 16);
    // 0x800D14A8: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800D14AC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800D14B0: lui         $v0, 0xDE00
    ctx->r2 = S32(0XDE00 << 16);
    // 0x800D14B4: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x800D14B8: addiu       $t9, $t9, -0x44B8
    ctx->r25 = ADD32(ctx->r25, -0X44B8);
    // 0x800D14BC: lui         $t0, 0xE900
    ctx->r8 = S32(0XE900 << 16);
    // 0x800D14C0: lui         $t1, 0xDF00
    ctx->r9 = S32(0XDF00 << 16);
    // 0x800D14C4: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D14C8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800D14CC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800D14D0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D14D4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D14D8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800D14DC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800D14E0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800D14E4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800D14E8: sll         $a1, $t2, 3
    ctx->r5 = S32(ctx->r10 << 3);
    // 0x800D14EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D14F0: jal         0x800D1BB4
    // 0x800D14F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D1BB4(rdram, ctx);
        goto after_3;
    // 0x800D14F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800D14F8: jal         0x800D2B40
    // 0x800D14FC: nop

    func_800D2B40(rdram, ctx);
        goto after_4;
    // 0x800D14FC: nop

    after_4:
    // 0x800D1500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1504: addiu       $sp, $sp, 0x830
    ctx->r29 = ADD32(ctx->r29, 0X830);
    // 0x800D1508: jr          $ra
    // 0x800D150C: nop

    return;
    // 0x800D150C: nop

;}
RECOMP_FUNC void func_800D1510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1510: addiu       $sp, $sp, -0x830
    ctx->r29 = ADD32(ctx->r29, -0X830);
    // 0x800D1514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1518: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D151C: addiu       $a0, $a0, -0x4584
    ctx->r4 = ADD32(ctx->r4, -0X4584);
    // 0x800D1520: jal         0x800D2AB0
    // 0x800D1524: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800D2AB0(rdram, ctx);
        goto after_0;
    // 0x800D1524: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800D1528: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800D152C: ori         $t6, $t6, 0xE000
    ctx->r14 = ctx->r14 | 0XE000;
    // 0x800D1530: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1534: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D1538: sw          $t6, -0x3D58($at)
    MEM_W(-0X3D58, ctx->r1) = ctx->r14;
    // 0x800D153C: jal         0x800D2AE0
    // 0x800D1540: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    func_800D2AE0(rdram, ctx);
        goto after_1;
    // 0x800D1540: addiu       $a0, $a0, 0x2B20
    ctx->r4 = ADD32(ctx->r4, 0X2B20);
    after_1:
    // 0x800D1544: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1548: addiu       $t7, $t7, -0x45C0
    ctx->r15 = ADD32(ctx->r15, -0X45C0);
    // 0x800D154C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1550: jal         0x800D18A0
    // 0x800D1554: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    func_800D18A0(rdram, ctx);
        goto after_2;
    // 0x800D1554: sw          $t7, -0x40F8($at)
    MEM_W(-0X40F8, ctx->r1) = ctx->r15;
    after_2:
    // 0x800D1558: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D155C: subu        $a1, $a0, $a0
    ctx->r5 = SUB32(ctx->r4, ctx->r4);
    // 0x800D1560: lui         $t8, 0xF
    ctx->r24 = S32(0XF << 16);
    // 0x800D1564: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800D1568: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800D156C: lui         $v0, 0xDE00
    ctx->r2 = S32(0XDE00 << 16);
    // 0x800D1570: addiu       $t8, $t8, -0x4518
    ctx->r24 = ADD32(ctx->r24, -0X4518);
    // 0x800D1574: addiu       $t9, $t9, -0x44B8
    ctx->r25 = ADD32(ctx->r25, -0X44B8);
    // 0x800D1578: lui         $t0, 0xE900
    ctx->r8 = S32(0XE900 << 16);
    // 0x800D157C: lui         $t1, 0xDF00
    ctx->r9 = S32(0XDF00 << 16);
    // 0x800D1580: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800D1584: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800D1588: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800D158C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D1590: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D1594: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800D1598: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800D159C: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800D15A0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800D15A4: sll         $a1, $t2, 3
    ctx->r5 = S32(ctx->r10 << 3);
    // 0x800D15A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D15AC: jal         0x800D1BB4
    // 0x800D15B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D1BB4(rdram, ctx);
        goto after_3;
    // 0x800D15B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800D15B4: jal         0x800D2B40
    // 0x800D15B8: nop

    func_800D2B40(rdram, ctx);
        goto after_4;
    // 0x800D15B8: nop

    after_4:
    // 0x800D15BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D15C0: addiu       $sp, $sp, 0x830
    ctx->r29 = ADD32(ctx->r29, 0X830);
    // 0x800D15C4: jr          $ra
    // 0x800D15C8: nop

    return;
    // 0x800D15C8: nop

    // 0x800D15CC: nop

;}
RECOMP_FUNC void func_800D15D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D15D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D15D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D15D8: jal         0x800D2B70
    // 0x800D15DC: nop

    func_800D2B70(rdram, ctx);
        goto after_0;
    // 0x800D15DC: nop

    after_0:
    // 0x800D15E0: jal         0x800D2CF0
    // 0x800D15E4: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    func_800D2CF0(rdram, ctx);
        goto after_1;
    // 0x800D15E4: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D15E8: jal         0x800D3130
    // 0x800D15EC: nop

    func_800D3130(rdram, ctx);
        goto after_2;
    // 0x800D15EC: nop

    after_2:
    // 0x800D15F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D15F4: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x800D15F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D15FC: jr          $ra
    // 0x800D1600: nop

    return;
    // 0x800D1600: nop

    // 0x800D1604: nop

    // 0x800D1608: nop

    // 0x800D160C: nop

;}
RECOMP_FUNC void func_800D1610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1618: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D161C: sw          $zero, -0x3D54($at)
    MEM_W(-0X3D54, ctx->r1) = 0;
    // 0x800D1620: jal         0x800D9E00
    // 0x800D1624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D1628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D162C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1630: jr          $ra
    // 0x800D1634: nop

    return;
    // 0x800D1634: nop

    // 0x800D1638: nop

    // 0x800D163C: nop

;}
RECOMP_FUNC void func_800D1640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1648: jal         0x800D2B40
    // 0x800D164C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D2B40(rdram, ctx);
        goto after_0;
    // 0x800D164C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D1650: jal         0x800D9740
    // 0x800D1654: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1654: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800D1658: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D165C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D1660: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1664: jal         0x800D9740
    // 0x800D1668: sw          $t6, -0x4400($at)
    MEM_W(-0X4400, ctx->r1) = ctx->r14;
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1668: sw          $t6, -0x4400($at)
    MEM_W(-0X4400, ctx->r1) = ctx->r14;
    after_2:
    // 0x800D166C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1674: jr          $ra
    // 0x800D1678: nop

    return;
    // 0x800D1678: nop

    // 0x800D167C: nop

;}
RECOMP_FUNC void func_800D1680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1680: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D1684: lw          $t6, 0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X708C);
    // 0x800D1688: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D168C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1690: beq         $t6, $zero, L_800D16D8
    if (ctx->r14 == 0) {
        // 0x800D1694: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800D16D8;
    }
    // 0x800D1694: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D1698: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800D169C: jal         0x800D8B80
    // 0x800D16A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D16A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D16A4: addiu       $t7, $zero, 0x3002
    ctx->r15 = ADD32(0, 0X3002);
    // 0x800D16A8: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x800D16AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D16B0: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x800D16B4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800D16B8: addiu       $a0, $a0, 0x6E18
    ctx->r4 = ADD32(ctx->r4, 0X6E18);
    // 0x800D16BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800D16C0: jal         0x800D95F0
    // 0x800D16C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D16C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D16C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D16CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D16D0: jal         0x800D8D00
    // 0x800D16D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D16D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800D16D8:
    // 0x800D16D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D16DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800D16E0: jr          $ra
    // 0x800D16E4: nop

    return;
    // 0x800D16E4: nop

    // 0x800D16E8: nop

    // 0x800D16EC: nop

;}
RECOMP_FUNC void func_800D16F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D16F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D16F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D16F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D16FC: jal         0x800D9740
    // 0x800D1700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1700: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D1704: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D1708: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D170C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1710: jal         0x800D9740
    // 0x800D1714: sw          $t6, -0x43FC($at)
    MEM_W(-0X43FC, ctx->r1) = ctx->r14;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1714: sw          $t6, -0x43FC($at)
    MEM_W(-0X43FC, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D1718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D171C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1720: jr          $ra
    // 0x800D1724: nop

    return;
    // 0x800D1724: nop

    // 0x800D1728: nop

    // 0x800D172C: nop

;}
RECOMP_FUNC void func_800D1730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1730: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D1734: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D1738: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800D173C: addiu       $fp, $fp, -0x3D78
    ctx->r30 = ADD32(ctx->r30, -0X3D78);
    // 0x800D1740: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D1744: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D1748: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D174C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D1750: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D1754: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D1758: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D175C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D1760: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D1764: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D1768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D176C: addiu       $a1, $a1, -0x4118
    ctx->r5 = ADD32(ctx->r5, -0X4118);
    // 0x800D1770: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1774: jal         0x800D8B80
    // 0x800D1778: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1778: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800D177C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x800D1780: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800D1784: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x800D1788: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D178C: addiu       $s0, $s0, -0x3D80
    ctx->r16 = ADD32(ctx->r16, -0X3D80);
    // 0x800D1790: addiu       $s4, $s4, -0x4418
    ctx->r20 = ADD32(ctx->r20, -0X4418);
    // 0x800D1794: addiu       $s5, $s5, -0x441C
    ctx->r21 = ADD32(ctx->r21, -0X441C);
    // 0x800D1798: addiu       $s7, $s7, -0x3D54
    ctx->r23 = ADD32(ctx->r23, -0X3D54);
    // 0x800D179C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800D17A0: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x800D17A4: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x800D17A8: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x800D17AC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_800D17B0:
    // 0x800D17B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D17B4: jal         0x800D8D00
    // 0x800D17B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D17B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D17BC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800D17C0: lw          $a0, 0x54($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X54);
    // 0x800D17C4: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800D17C8: beql        $v1, $s2, L_800D17E4
    if (ctx->r3 == ctx->r18) {
        // 0x800D17CC: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_800D17E4;
    }
    goto skip_0;
    // 0x800D17CC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x800D17D0: beql        $v1, $s3, L_800D1830
    if (ctx->r3 == ctx->r19) {
        // 0x800D17D4: lw          $v0, 0x0($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X0);
            goto L_800D1830;
    }
    goto skip_1;
    // 0x800D17D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    skip_1:
    // 0x800D17D8: b           L_800D17B0
    // 0x800D17DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_800D17B0;
    // 0x800D17DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D17E0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
L_800D17E4:
    // 0x800D17E4: beql        $v0, $zero, L_800D17F8
    if (ctx->r2 == 0) {
        // 0x800D17E8: lw          $t7, 0x0($s7)
        ctx->r15 = MEM_W(ctx->r23, 0X0);
            goto L_800D17F8;
    }
    goto skip_2;
    // 0x800D17E8: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    skip_2:
    // 0x800D17EC: jalr        $v0
    // 0x800D17F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800D17F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800D17F4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
L_800D17F8:
    // 0x800D17F8: bne         $s6, $t7, L_800D1808
    if (ctx->r22 != ctx->r15) {
        // 0x800D17FC: nop
    
            goto L_800D1808;
    }
    // 0x800D17FC: nop

    // 0x800D1800: jal         0x800D9E00
    // 0x800D1804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_3;
    // 0x800D1804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_800D1808:
    // 0x800D1808: jal         0x800D9740
    // 0x800D180C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800D180C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x800D1810: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800D1814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1818: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800D181C: jal         0x800D9740
    // 0x800D1820: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    osSetIntMask_recomp(rdram, ctx);
        goto after_5;
    // 0x800D1820: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_5:
    // 0x800D1824: b           L_800D17B0
    // 0x800D1828: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_800D17B0;
    // 0x800D1828: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D182C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
L_800D1830:
    // 0x800D1830: beq         $v0, $zero, L_800D1840
    if (ctx->r2 == 0) {
        // 0x800D1834: nop
    
            goto L_800D1840;
    }
    // 0x800D1834: nop

    // 0x800D1838: jalr        $v0
    // 0x800D183C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800D183C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
L_800D1840:
    // 0x800D1840: jal         0x800D9740
    // 0x800D1844: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_7;
    // 0x800D1844: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_7:
    // 0x800D1848: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800D184C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1850: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x800D1854: jal         0x800D9740
    // 0x800D1858: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    osSetIntMask_recomp(rdram, ctx);
        goto after_8;
    // 0x800D1858: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    after_8:
    // 0x800D185C: b           L_800D17B0
    // 0x800D1860: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
        goto L_800D17B0;
    // 0x800D1860: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D1864: nop

    // 0x800D1868: nop

    // 0x800D186C: nop

    // 0x800D1870: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D1878: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D187C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D1880: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D1884: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D1888: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D188C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D1890: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D1894: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D1898: jr          $ra
    // 0x800D189C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800D189C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800D18A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D18A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D18A4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800D18A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D18AC: sh          $t6, -0x62CC($at)
    MEM_H(-0X62CC, ctx->r1) = ctx->r14;
    // 0x800D18B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D18B4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800D18B8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D18BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D18C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D18C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D18C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D18CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D18D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D18D4: sh          $t7, -0x62CA($at)
    MEM_H(-0X62CA, ctx->r1) = ctx->r15;
    // 0x800D18D8: addiu       $t8, $t8, -0x3D80
    ctx->r24 = ADD32(ctx->r24, -0X3D80);
    // 0x800D18DC: jal         0x800D1610
    // 0x800D18E0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    func_800D1610(rdram, ctx);
        goto after_0;
    // 0x800D18E0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_0:
    // 0x800D18E4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D18E8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800D18EC: addiu       $s0, $s0, -0x62C8
    ctx->r16 = ADD32(ctx->r16, -0X62C8);
    // 0x800D18F0: addiu       $t9, $t9, -0x4118
    ctx->r25 = ADD32(ctx->r25, -0X4118);
    // 0x800D18F4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D18F8: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x800D18FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800D1900: addiu       $a2, $a2, 0x1730
    ctx->r6 = ADD32(ctx->r6, 0X1730);
    // 0x800D1904: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800D1908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D190C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D1910: jal         0x800D76A0
    // 0x800D1914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800D1918: jal         0x800D77F0
    // 0x800D191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800D191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800D1920: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D1924: addiu       $t7, $t7, -0x4098
    ctx->r15 = ADD32(ctx->r15, -0X4098);
    // 0x800D1928: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D192C: sw          $t7, -0x40F0($at)
    MEM_W(-0X40F0, ctx->r1) = ctx->r15;
    // 0x800D1930: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1934: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D1938: sw          $t8, -0x40E0($at)
    MEM_W(-0X40E0, ctx->r1) = ctx->r24;
    // 0x800D193C: sw          $zero, -0x40DC($at)
    MEM_W(-0X40DC, ctx->r1) = 0;
    // 0x800D1940: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800D1944: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800D1948: addiu       $t9, $t9, 0x52C0
    ctx->r25 = ADD32(ctx->r25, 0X52C0);
    // 0x800D194C: addiu       $t1, $t1, 0x51F0
    ctx->r9 = ADD32(ctx->r9, 0X51F0);
    // 0x800D1950: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1954: subu        $t0, $t9, $t1
    ctx->r8 = SUB32(ctx->r25, ctx->r9);
    // 0x800D1958: sw          $t0, -0x40D4($at)
    MEM_W(-0X40D4, ctx->r1) = ctx->r8;
    // 0x800D195C: sw          $t1, -0x40D8($at)
    MEM_W(-0X40D8, ctx->r1) = ctx->r9;
    // 0x800D1960: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1964: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800D1968: sw          $t6, -0x40CC($at)
    MEM_W(-0X40CC, ctx->r1) = ctx->r14;
    // 0x800D196C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1970: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x800D1974: sw          $t7, -0x40C4($at)
    MEM_W(-0X40C4, ctx->r1) = ctx->r15;
    // 0x800D1978: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D197C: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800D1980: addiu       $t3, $t3, 0x7090
    ctx->r11 = ADD32(ctx->r11, 0X7090);
    // 0x800D1984: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800D1988: sw          $t8, -0x40BC($at)
    MEM_W(-0X40BC, ctx->r1) = ctx->r24;
    // 0x800D198C: sw          $t3, -0x40C0($at)
    MEM_W(-0X40C0, ctx->r1) = ctx->r11;
    // 0x800D1990: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1994: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x800D1998: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800D199C: addiu       $t5, $t5, 0x7490
    ctx->r13 = ADD32(ctx->r13, 0X7490);
    // 0x800D19A0: addiu       $t4, $t4, 0x7490
    ctx->r12 = ADD32(ctx->r12, 0X7490);
    // 0x800D19A4: sw          $t4, -0x40B8($at)
    MEM_W(-0X40B8, ctx->r1) = ctx->r12;
    // 0x800D19A8: sw          $t5, -0x40B4($at)
    MEM_W(-0X40B4, ctx->r1) = ctx->r13;
    // 0x800D19AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D19B0: lui         $ra, 0x8016
    ctx->r31 = S32(0X8016 << 16);
    // 0x800D19B4: addiu       $ra, $ra, 0x7490
    ctx->r31 = ADD32(ctx->r31, 0X7490);
    // 0x800D19B8: addiu       $t9, $zero, 0xC00
    ctx->r25 = ADD32(0, 0XC00);
    // 0x800D19BC: sw          $t9, -0x40A4($at)
    MEM_W(-0X40A4, ctx->r1) = ctx->r25;
    // 0x800D19C0: sw          $ra, -0x40A8($at)
    MEM_W(-0X40A8, ctx->r1) = ctx->r31;
    // 0x800D19C4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D19C8: addiu       $s0, $s0, -0x3D78
    ctx->r16 = ADD32(ctx->r16, -0X3D78);
    // 0x800D19CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D19D0: sw          $s0, -0x40A0($at)
    MEM_W(-0X40A0, ctx->r1) = ctx->r16;
    // 0x800D19D4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D19D8: addiu       $v0, $t6, -0x4040
    ctx->r2 = ADD32(ctx->r14, -0X4040);
    // 0x800D19DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D19E0: sw          $v0, -0x4098($at)
    MEM_W(-0X4098, ctx->r1) = ctx->r2;
    // 0x800D19E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D19E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D19EC: sw          $t7, -0x4088($at)
    MEM_W(-0X4088, ctx->r1) = ctx->r15;
    // 0x800D19F0: sw          $zero, -0x4084($at)
    MEM_W(-0X4084, ctx->r1) = 0;
    // 0x800D19F4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D19F8: sw          $t1, -0x4080($at)
    MEM_W(-0X4080, ctx->r1) = ctx->r9;
    // 0x800D19FC: sw          $t0, -0x407C($at)
    MEM_W(-0X407C, ctx->r1) = ctx->r8;
    // 0x800D1A00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A04: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x800D1A08: sw          $t8, -0x4074($at)
    MEM_W(-0X4074, ctx->r1) = ctx->r24;
    // 0x800D1A0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A10: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800D1A14: sw          $t9, -0x406C($at)
    MEM_W(-0X406C, ctx->r1) = ctx->r25;
    // 0x800D1A18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A1C: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800D1A20: sw          $t7, -0x4064($at)
    MEM_W(-0X4064, ctx->r1) = ctx->r15;
    // 0x800D1A24: sw          $t3, -0x4068($at)
    MEM_W(-0X4068, ctx->r1) = ctx->r11;
    // 0x800D1A28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A2C: sw          $t4, -0x4060($at)
    MEM_W(-0X4060, ctx->r1) = ctx->r12;
    // 0x800D1A30: sw          $t5, -0x405C($at)
    MEM_W(-0X405C, ctx->r1) = ctx->r13;
    // 0x800D1A34: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A38: addiu       $t8, $zero, 0xC00
    ctx->r24 = ADD32(0, 0XC00);
    // 0x800D1A3C: sw          $t8, -0x404C($at)
    MEM_W(-0X404C, ctx->r1) = ctx->r24;
    // 0x800D1A40: sw          $ra, -0x4050($at)
    MEM_W(-0X4050, ctx->r1) = ctx->r31;
    // 0x800D1A44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1A48: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800D1A4C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800D1A50: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800D1A54: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D1A58: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800D1A5C: addiu       $s4, $s4, -0x3C20
    ctx->r20 = ADD32(ctx->r20, -0X3C20);
    // 0x800D1A60: addiu       $t2, $t2, -0x3EE0
    ctx->r10 = ADD32(ctx->r10, -0X3EE0);
    // 0x800D1A64: addiu       $s3, $s3, -0x3F38
    ctx->r19 = ADD32(ctx->r19, -0X3F38);
    // 0x800D1A68: addiu       $s2, $s2, -0x3F90
    ctx->r18 = ADD32(ctx->r18, -0X3F90);
    // 0x800D1A6C: addiu       $s1, $s1, -0x3FE8
    ctx->r17 = ADD32(ctx->r17, -0X3FE8);
    // 0x800D1A70: sw          $s0, -0x4048($at)
    MEM_W(-0X4048, ctx->r1) = ctx->r16;
    // 0x800D1A74: addiu       $a3, $zero, 0xC00
    ctx->r7 = ADD32(0, 0XC00);
    // 0x800D1A78: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x800D1A7C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x800D1A80: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x800D1A84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D1A88:
    // 0x800D1A88: sw          $t2, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r10;
    // 0x800D1A8C: addiu       $t2, $t2, 0x160
    ctx->r10 = ADD32(ctx->r10, 0X160);
    // 0x800D1A90: sw          $s2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r18;
    // 0x800D1A94: sw          $s3, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->r19;
    // 0x800D1A98: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x800D1A9C: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, 0X160);
    // 0x800D1AA0: addiu       $s3, $s3, 0x160
    ctx->r19 = ADD32(ctx->r19, 0X160);
    // 0x800D1AA4: addiu       $s2, $s2, 0x160
    ctx->r18 = ADD32(ctx->r18, 0X160);
    // 0x800D1AA8: sw          $v1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r3;
    // 0x800D1AAC: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x800D1AB0: sw          $t1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r9;
    // 0x800D1AB4: sw          $t0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r8;
    // 0x800D1AB8: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    // 0x800D1ABC: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x800D1AC0: sw          $t3, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r11;
    // 0x800D1AC4: sw          $a2, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r6;
    // 0x800D1AC8: sw          $t4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r12;
    // 0x800D1ACC: sw          $t5, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r13;
    // 0x800D1AD0: sw          $ra, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r31;
    // 0x800D1AD4: sw          $a3, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r7;
    // 0x800D1AD8: sw          $s0, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r16;
    // 0x800D1ADC: sw          $v1, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->r3;
    // 0x800D1AE0: sw          $zero, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = 0;
    // 0x800D1AE4: sw          $t1, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->r9;
    // 0x800D1AE8: sw          $t0, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r8;
    // 0x800D1AEC: sw          $a0, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r4;
    // 0x800D1AF0: sw          $a1, 0xDC($v0)
    MEM_W(0XDC, ctx->r2) = ctx->r5;
    // 0x800D1AF4: sw          $t3, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = ctx->r11;
    // 0x800D1AF8: sw          $a2, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->r6;
    // 0x800D1AFC: sw          $t4, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->r12;
    // 0x800D1B00: sw          $t5, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r13;
    // 0x800D1B04: sw          $ra, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r31;
    // 0x800D1B08: sw          $a3, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r7;
    // 0x800D1B0C: sw          $s0, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r16;
    // 0x800D1B10: sw          $v1, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r3;
    // 0x800D1B14: sw          $zero, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = 0;
    // 0x800D1B18: sw          $t1, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->r9;
    // 0x800D1B1C: sw          $t0, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->r8;
    // 0x800D1B20: sw          $a0, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->r4;
    // 0x800D1B24: sw          $a1, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->r5;
    // 0x800D1B28: sw          $t3, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r11;
    // 0x800D1B2C: sw          $a2, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r6;
    // 0x800D1B30: sw          $t4, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->r12;
    // 0x800D1B34: sw          $t5, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r13;
    // 0x800D1B38: sw          $ra, 0x150($v0)
    MEM_W(0X150, ctx->r2) = ctx->r31;
    // 0x800D1B3C: sw          $a3, 0x154($v0)
    MEM_W(0X154, ctx->r2) = ctx->r7;
    // 0x800D1B40: sw          $s0, 0x158($v0)
    MEM_W(0X158, ctx->r2) = ctx->r16;
    // 0x800D1B44: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
    // 0x800D1B48: sw          $v1, -0x150($v0)
    MEM_W(-0X150, ctx->r2) = ctx->r3;
    // 0x800D1B4C: sw          $zero, -0x14C($v0)
    MEM_W(-0X14C, ctx->r2) = 0;
    // 0x800D1B50: sw          $t1, -0x148($v0)
    MEM_W(-0X148, ctx->r2) = ctx->r9;
    // 0x800D1B54: sw          $t0, -0x144($v0)
    MEM_W(-0X144, ctx->r2) = ctx->r8;
    // 0x800D1B58: sw          $a0, -0x13C($v0)
    MEM_W(-0X13C, ctx->r2) = ctx->r4;
    // 0x800D1B5C: sw          $a1, -0x134($v0)
    MEM_W(-0X134, ctx->r2) = ctx->r5;
    // 0x800D1B60: sw          $t3, -0x130($v0)
    MEM_W(-0X130, ctx->r2) = ctx->r11;
    // 0x800D1B64: sw          $a2, -0x12C($v0)
    MEM_W(-0X12C, ctx->r2) = ctx->r6;
    // 0x800D1B68: sw          $t4, -0x128($v0)
    MEM_W(-0X128, ctx->r2) = ctx->r12;
    // 0x800D1B6C: sw          $t5, -0x124($v0)
    MEM_W(-0X124, ctx->r2) = ctx->r13;
    // 0x800D1B70: sw          $ra, -0x118($v0)
    MEM_W(-0X118, ctx->r2) = ctx->r31;
    // 0x800D1B74: sw          $a3, -0x114($v0)
    MEM_W(-0X114, ctx->r2) = ctx->r7;
    // 0x800D1B78: bne         $t2, $s4, L_800D1A88
    if (ctx->r10 != ctx->r20) {
        // 0x800D1B7C: sw          $s0, -0x110($v0)
        MEM_W(-0X110, ctx->r2) = ctx->r16;
            goto L_800D1A88;
    }
    // 0x800D1B7C: sw          $s0, -0x110($v0)
    MEM_W(-0X110, ctx->r2) = ctx->r16;
    // 0x800D1B80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D1B84: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D1B88: addiu       $v0, $v0, -0x40F0
    ctx->r2 = ADD32(ctx->r2, -0X40F0);
    // 0x800D1B8C: sw          $v0, 0x318($v0)
    MEM_W(0X318, ctx->r2) = ctx->r2;
    // 0x800D1B90: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1B94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D1B98: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D1B9C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D1BA0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1BA4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D1BA8: sw          $v0, -0x62D0($at)
    MEM_W(-0X62D0, ctx->r1) = ctx->r2;
    // 0x800D1BAC: jr          $ra
    // 0x800D1BB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D1BB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800D1BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1BB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D1BBC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D1BC0: addiu       $s0, $s0, -0x62D0
    ctx->r16 = ADD32(ctx->r16, -0X62D0);
    // 0x800D1BC4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800D1BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1BCC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D1BD0: sw          $a0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r4;
    // 0x800D1BD4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800D1BD8: addiu       $v1, $v1, -0x40F8
    ctx->r3 = ADD32(ctx->r3, -0X40F8);
    // 0x800D1BDC: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800D1BE0: sw          $a1, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r5;
    // 0x800D1BE4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800D1BE8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800D1BEC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D1BF0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800D1BF4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800D1BF8: addiu       $t0, $t0, -0x3D5C
    ctx->r8 = ADD32(ctx->r8, -0X3D5C);
    // 0x800D1BFC: sw          $t1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r9;
    // 0x800D1C00: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800D1C04: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800D1C08: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D1C0C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800D1C10: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800D1C14: andi        $t1, $a3, 0x1
    ctx->r9 = ctx->r7 & 0X1;
    // 0x800D1C18: addiu       $v1, $v1, -0x3D50
    ctx->r3 = ADD32(ctx->r3, -0X3D50);
    // 0x800D1C1C: sw          $t5, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r13;
    // 0x800D1C20: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800D1C24: sw          $a3, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r7;
    // 0x800D1C28: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800D1C2C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800D1C30: beq         $t1, $zero, L_800D1C94
    if (ctx->r9 == 0) {
        // 0x800D1C34: sw          $t8, 0xC($t9)
        MEM_W(0XC, ctx->r25) = ctx->r24;
            goto L_800D1C94;
    }
    // 0x800D1C34: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x800D1C38: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800D1C3C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D1C40: addiu       $t2, $t2, -0x62CA
    ctx->r10 = ADD32(ctx->r10, -0X62CA);
    // 0x800D1C44: sw          $t2, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r10;
    // 0x800D1C48: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800D1C4C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D1C50: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D1C54: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800D1C58: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800D1C5C: lw          $t7, -0x4420($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4420);
    // 0x800D1C60: lw          $t8, -0x3D60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3D60);
    // 0x800D1C64: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x800D1C68: divu        $zero, $t5, $t7
    lo = S32(U32(ctx->r13) / U32(ctx->r15)); hi = S32(U32(ctx->r13) % U32(ctx->r15));
    // 0x800D1C6C: mfhi        $v0
    ctx->r2 = hi;
    // 0x800D1C70: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800D1C74: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800D1C78: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800D1C7C: bne         $t7, $zero, L_800D1C88
    if (ctx->r15 != 0) {
        // 0x800D1C80: nop
    
            goto L_800D1C88;
    }
    // 0x800D1C80: nop

    // 0x800D1C84: break       7
    do_break(2148342916);
L_800D1C88:
    // 0x800D1C88: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800D1C8C: b           L_800D1CA4
    // 0x800D1C90: nop

        goto L_800D1CA4;
    // 0x800D1C90: nop

L_800D1C94:
    // 0x800D1C94: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800D1C98: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800D1C9C: addiu       $t3, $t3, -0x62CC
    ctx->r11 = ADD32(ctx->r11, -0X62CC);
    // 0x800D1CA0: sw          $t3, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r11;
L_800D1CA4:
    // 0x800D1CA4: jal         0x800D9740
    // 0x800D1CA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1CA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D1CAC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D1CB0: addiu       $a1, $a1, -0x3D80
    ctx->r5 = ADD32(ctx->r5, -0X3D80);
    // 0x800D1CB4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800D1CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1CBC: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800D1CC0: jal         0x800D9740
    // 0x800D1CC4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1CC4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    after_1:
    // 0x800D1CC8: jal         0x800D9DD0
    // 0x800D1CCC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1CCC: nop

    after_2:
    // 0x800D1CD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D1CD4: addiu       $a0, $a0, 0x23EC
    ctx->r4 = ADD32(ctx->r4, 0X23EC);
    // 0x800D1CD8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D1CDC: jal         0x800D95F0
    // 0x800D1CE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D1CE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800D1CE4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800D1CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1CEC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800D1CF0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800D1CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D1CF8: jr          $ra
    // 0x800D1CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D1CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D1D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1D04: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1D08: jr          $ra
    // 0x800D1D0C: sw          $t6, -0x3D54($at)
    MEM_W(-0X3D54, ctx->r1) = ctx->r14;
    return;
    // 0x800D1D0C: sw          $t6, -0x3D54($at)
    MEM_W(-0X3D54, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800D1D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    unload_overlays((int32_t)ctx->r5, (uint32_t)ctx->r6); load_overlays(((uint32_t)ctx->r4) & 0x1FFFFFFF, (int32_t)ctx->r5, (uint32_t)ctx->r6);
    // 0x800D1D10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D1D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1D18: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D1D1C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D1D20: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D1D24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D1D28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800D1D2C: jal         0x800D8B80
    // 0x800D1D30: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1D30: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800D1D34: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800D1D38: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800D1D3C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800D1D40: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x800D1D44: sb          $zero, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = 0;
    // 0x800D1D48: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800D1D4C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800D1D50: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800D1D54: jal         0x800D6460
    // 0x800D1D58: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1D58: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    after_1:
    // 0x800D1D5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D1D60: lw          $a0, -0x3C60($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3C60);
    // 0x800D1D64: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D1D68: jal         0x800D8A00
    // 0x800D1D6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1D6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800D1D70: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D1D74: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800D1D78: jal         0x800D8D00
    // 0x800D1D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D1D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800D1D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1D84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D1D88: jr          $ra
    // 0x800D1D8C: nop

    return;
    // 0x800D1D8C: nop

;}
RECOMP_FUNC void func_800D1D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1D90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D1D94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D1D98: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D1D9C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D1DA0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D1DA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D1DA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D1DAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D1DB0: jal         0x800D2EAC
    // 0x800D1DB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800D2EAC(rdram, ctx);
        goto after_0;
    // 0x800D1DB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D1DB8: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800D1DBC: addiu       $s2, $s2, 0x6E90
    ctx->r18 = ADD32(ctx->r18, 0X6E90);
    // 0x800D1DC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D1DC4: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x800D1DC8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_800D1DCC:
    // 0x800D1DCC: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800D1DD0: lhu         $s3, 0x0($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X0);
    // 0x800D1DD4: addu        $a1, $t6, $s4
    ctx->r5 = ADD32(ctx->r14, ctx->r20);
    // 0x800D1DD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D1DDC: jal         0x800D9E70
    // 0x800D1DE0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _bcopy_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1DE0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x800D1DE4: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x800D1DE8: nor         $t8, $s3, $zero
    ctx->r24 = ~(ctx->r19 | 0);
    // 0x800D1DEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D1DF0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800D1DF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800D1DF8: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x800D1DFC: bne         $s0, $s5, L_800D1DCC
    if (ctx->r16 != ctx->r21) {
        // 0x800D1E00: sh          $t9, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = ctx->r25;
            goto L_800D1DCC;
    }
    // 0x800D1E00: sh          $t9, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r25;
    // 0x800D1E04: jal         0x800D2ED8
    // 0x800D1E08: nop

    func_800D2ED8(rdram, ctx);
        goto after_2;
    // 0x800D1E08: nop

    after_2:
    // 0x800D1E0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1E10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D1E14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D1E18: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1E1C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D1E20: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D1E24: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D1E28: jr          $ra
    // 0x800D1E2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D1E2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D1E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1E30: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D1E34: lw          $t6, 0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X708C);
    // 0x800D1E38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D1E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1E40: bne         $t6, $zero, L_800D1E50
    if (ctx->r14 != 0) {
        // 0x800D1E44: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_800D1E50;
    }
    // 0x800D1E44: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800D1E48: b           L_800D1EE8
    // 0x800D1E4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D1EE8;
    // 0x800D1E4C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D1E50:
    // 0x800D1E50: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D1E54: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800D1E58: jal         0x800D8B80
    // 0x800D1E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D1E60: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800D1E64: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x800D1E68: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x800D1E6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D1E70: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x800D1E74: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800D1E78: addiu       $a0, $a0, 0x6E18
    ctx->r4 = ADD32(ctx->r4, 0X6E18);
    // 0x800D1E7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800D1E80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D1E84: jal         0x800D95F0
    // 0x800D1E88: sb          $t8, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1E88: sb          $t8, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r24;
    after_1:
    // 0x800D1E8C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D1E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D1E94: jal         0x800D8D00
    // 0x800D1E98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1E98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800D1E9C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800D1EA0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800D1EA4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1EA8: bne         $v1, $zero, L_800D1ED4
    if (ctx->r3 != 0) {
        // 0x800D1EAC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800D1ED4;
    }
    // 0x800D1EAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D1EB0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800D1EB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1EB8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800D1EBC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800D1EC0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800D1EC4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800D1EC8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800D1ECC: b           L_800D1EE8
    // 0x800D1ED0: sb          $t0, 0x7069($at)
    MEM_B(0X7069, ctx->r1) = ctx->r8;
        goto L_800D1EE8;
    // 0x800D1ED0: sb          $t0, 0x7069($at)
    MEM_B(0X7069, ctx->r1) = ctx->r8;
L_800D1ED4:
    // 0x800D1ED4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800D1ED8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800D1EDC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800D1EE0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800D1EE4: sb          $zero, 0x7069($at)
    MEM_B(0X7069, ctx->r1) = 0;
L_800D1EE8:
    // 0x800D1EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1EEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800D1EF0: jr          $ra
    // 0x800D1EF4: nop

    return;
    // 0x800D1EF4: nop

    // 0x800D1EF8: nop

    // 0x800D1EFC: nop

;}
RECOMP_FUNC void func_800D1F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1F00: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D1F04: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800D1F08: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D1F0C: addiu       $t8, $t8, 0x7060
    ctx->r24 = ADD32(ctx->r24, 0X7060);
    // 0x800D1F10: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800D1F14: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800D1F18: lbu         $v0, 0x7($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X7);
    // 0x800D1F1C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D1F20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D1F24: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800D1F28: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800D1F2C: beq         $t6, $zero, L_800D1F50
    if (ctx->r14 == 0) {
        // 0x800D1F30: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_800D1F50;
    }
    // 0x800D1F30: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800D1F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1F38: beq         $t6, $at, L_800D1F5C
    if (ctx->r14 == ctx->r1) {
        // 0x800D1F3C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800D1F5C;
    }
    // 0x800D1F3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800D1F40: beql        $t6, $a0, L_800D1F7C
    if (ctx->r14 == ctx->r4) {
        // 0x800D1F44: lbu         $t4, 0x9($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X9);
            goto L_800D1F7C;
    }
    goto skip_0;
    // 0x800D1F44: lbu         $t4, 0x9($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X9);
    skip_0:
    // 0x800D1F48: jr          $ra
    // 0x800D1F4C: nop

    return;
    // 0x800D1F4C: nop

L_800D1F50:
    // 0x800D1F50: or          $t0, $a2, $v0
    ctx->r8 = ctx->r6 | ctx->r2;
    // 0x800D1F54: jr          $ra
    // 0x800D1F58: sb          $t0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r8;
    return;
    // 0x800D1F58: sb          $t0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r8;
L_800D1F5C:
    // 0x800D1F5C: lbu         $t1, 0x9($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X9);
    // 0x800D1F60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800D1F64: or          $t2, $a2, $v0
    ctx->r10 = ctx->r6 | ctx->r2;
    // 0x800D1F68: bne         $a0, $t1, L_800D1F98
    if (ctx->r4 != ctx->r9) {
        // 0x800D1F6C: nop
    
            goto L_800D1F98;
    }
    // 0x800D1F6C: nop

    // 0x800D1F70: jr          $ra
    // 0x800D1F74: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    return;
    // 0x800D1F74: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x800D1F78: lbu         $t4, 0x9($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X9);
L_800D1F7C:
    // 0x800D1F7C: or          $t3, $a2, $v0
    ctx->r11 = ctx->r6 | ctx->r2;
    // 0x800D1F80: sb          $t3, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r11;
    // 0x800D1F84: bne         $a0, $t4, L_800D1F94
    if (ctx->r4 != ctx->r12) {
        // 0x800D1F88: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800D1F94;
    }
    // 0x800D1F88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D1F8C: jr          $ra
    // 0x800D1F90: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    return;
    // 0x800D1F90: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
L_800D1F94:
    // 0x800D1F94: sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
L_800D1F98:
    // 0x800D1F98: jr          $ra
    // 0x800D1F9C: nop

    return;
    // 0x800D1F9C: nop

;}
RECOMP_FUNC void func_800D1FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1FA8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D1FAC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800D1FB0: addiu       $a2, $a2, -0x3D28
    ctx->r6 = ADD32(ctx->r6, -0X3D28);
    // 0x800D1FB4: addiu       $a1, $a1, -0x3D40
    ctx->r5 = ADD32(ctx->r5, -0X3D40);
    // 0x800D1FB8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800D1FBC: jal         0x800DA180
    // 0x800D1FC0: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_800DA180(rdram, ctx);
        goto after_0;
    // 0x800D1FC0: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_0:
    // 0x800D1FC4: jal         0x800D8900
    // 0x800D1FC8: nop

    osCartRomInit_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1FC8: nop

    after_1:
    // 0x800D1FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1FD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D1FD4: sw          $v0, -0x3C60($at)
    MEM_W(-0X3C60, ctx->r1) = ctx->r2;
    // 0x800D1FD8: jr          $ra
    // 0x800D1FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D1FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D1FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1FE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D1FE4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D1FE8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D1FEC: addiu       $s0, $s0, 0x23B0
    ctx->r16 = ADD32(ctx->r16, 0X23B0);
    // 0x800D1FF0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D1FF4: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x800D1FF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D1FFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D2000: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D2004: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800D2008: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D200C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2010: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    // 0x800D2014: sw          $zero, 0x670($s0)
    MEM_W(0X670, ctx->r16) = 0;
    // 0x800D2018: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
    // 0x800D201C: sw          $zero, 0x668($s0)
    MEM_W(0X668, ctx->r16) = 0;
    // 0x800D2020: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x800D2024: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x800D2028: addiu       $a1, $a1, 0x243C
    ctx->r5 = ADD32(ctx->r5, 0X243C);
    // 0x800D202C: addiu       $a0, $a0, 0x2424
    ctx->r4 = ADD32(ctx->r4, 0X2424);
    // 0x800D2030: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800D2034: jal         0x800D8B80
    // 0x800D2038: sw          $t8, 0x678($s0)
    MEM_W(0X678, ctx->r16) = ctx->r24;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2038: sw          $t8, 0x678($s0)
    MEM_W(0X678, ctx->r16) = ctx->r24;
    after_0:
    // 0x800D203C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2040: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2044: addiu       $a1, $a1, 0x2474
    ctx->r5 = ADD32(ctx->r5, 0X2474);
    // 0x800D2048: addiu       $a0, $a0, 0x245C
    ctx->r4 = ADD32(ctx->r4, 0X245C);
    // 0x800D204C: jal         0x800D8B80
    // 0x800D2050: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2050: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800D2054: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2058: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D205C: addiu       $a1, $a1, 0x24AC
    ctx->r5 = ADD32(ctx->r5, 0X24AC);
    // 0x800D2060: addiu       $a0, $a0, 0x2494
    ctx->r4 = ADD32(ctx->r4, 0X2494);
    // 0x800D2064: jal         0x800D8B80
    // 0x800D2068: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2068: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800D206C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2070: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2074: addiu       $a1, $a1, 0x2404
    ctx->r5 = ADD32(ctx->r5, 0X2404);
    // 0x800D2078: addiu       $a0, $a0, 0x23EC
    ctx->r4 = ADD32(ctx->r4, 0X23EC);
    // 0x800D207C: jal         0x800D8B80
    // 0x800D2080: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800D2080: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800D2084: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2088: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D208C: addiu       $a1, $a1, 0x23CC
    ctx->r5 = ADD32(ctx->r5, 0X23CC);
    // 0x800D2090: addiu       $a0, $a0, 0x23B4
    ctx->r4 = ADD32(ctx->r4, 0X23B4);
    // 0x800D2094: jal         0x800D8B80
    // 0x800D2098: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800D2098: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x800D209C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D20A0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D20A4: addiu       $a1, $a1, 0x24E4
    ctx->r5 = ADD32(ctx->r5, 0X24E4);
    // 0x800D20A8: addiu       $a0, $a0, 0x24CC
    ctx->r4 = ADD32(ctx->r4, 0X24CC);
    // 0x800D20AC: jal         0x800D8B80
    // 0x800D20B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800D20B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800D20B4: jal         0x800DA370
    // 0x800D20B8: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_6;
    // 0x800D20B8: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_6:
    // 0x800D20BC: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800D20C0: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800D20C4: addiu       $t1, $t1, -0x43D0
    ctx->r9 = ADD32(ctx->r9, -0X43D0);
    // 0x800D20C8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800D20CC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800D20D0: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800D20D4: jal         0x800D3B40
    // 0x800D20D8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x800D20D8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_7:
    // 0x800D20DC: jal         0x800D9E00
    // 0x800D20E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x800D20E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800D20E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D20E8: addiu       $a0, $a0, 0x2424
    ctx->r4 = ADD32(ctx->r4, 0X2424);
    // 0x800D20EC: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x800D20F0: jal         0x800DA680
    // 0x800D20F4: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    osViSetEvent_recomp(rdram, ctx);
        goto after_9;
    // 0x800D20F4: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    after_9:
    // 0x800D20F8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D20FC: addiu       $a1, $a1, 0x245C
    ctx->r5 = ADD32(ctx->r5, 0X245C);
    // 0x800D2100: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800D2104: jal         0x800DA6F0
    // 0x800D2108: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x800D2108: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_10:
    // 0x800D210C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2110: addiu       $a1, $a1, 0x2494
    ctx->r5 = ADD32(ctx->r5, 0X2494);
    // 0x800D2114: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800D2118: jal         0x800DA6F0
    // 0x800D211C: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x800D211C: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_11:
    // 0x800D2120: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2124: addiu       $a1, $a1, 0x2424
    ctx->r5 = ADD32(ctx->r5, 0X2424);
    // 0x800D2128: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800D212C: jal         0x800DA6F0
    // 0x800D2130: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x800D2130: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_12:
    // 0x800D2134: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D2138: addiu       $t2, $t2, -0x1C50
    ctx->r10 = ADD32(ctx->r10, -0X1C50);
    // 0x800D213C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2140: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D2144: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x800D2148: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800D214C: addiu       $a2, $a2, 0x2214
    ctx->r6 = ADD32(ctx->r6, 0X2214);
    // 0x800D2150: addiu       $a0, $a0, 0x2508
    ctx->r4 = ADD32(ctx->r4, 0X2508);
    // 0x800D2154: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D2158: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800D215C: jal         0x800D76A0
    // 0x800D2160: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_13;
    // 0x800D2160: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_13:
    // 0x800D2164: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2168: jal         0x800D77F0
    // 0x800D216C: addiu       $a0, $a0, 0x2508
    ctx->r4 = ADD32(ctx->r4, 0X2508);
    osStartThread_recomp(rdram, ctx);
        goto after_14;
    // 0x800D216C: addiu       $a0, $a0, 0x2508
    ctx->r4 = ADD32(ctx->r4, 0X2508);
    after_14:
    // 0x800D2170: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x800D2174: addiu       $t4, $t4, 0x3B0
    ctx->r12 = ADD32(ctx->r12, 0X3B0);
    // 0x800D2178: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D217C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D2180: addiu       $t5, $zero, 0x6E
    ctx->r13 = ADD32(0, 0X6E);
    // 0x800D2184: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800D2188: addiu       $a2, $a2, 0x2460
    ctx->r6 = ADD32(ctx->r6, 0X2460);
    // 0x800D218C: addiu       $a0, $a0, 0x26B8
    ctx->r4 = ADD32(ctx->r4, 0X26B8);
    // 0x800D2190: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800D2194: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800D2198: jal         0x800D76A0
    // 0x800D219C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_15;
    // 0x800D219C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
    // 0x800D21A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D21A4: jal         0x800D77F0
    // 0x800D21A8: addiu       $a0, $a0, 0x26B8
    ctx->r4 = ADD32(ctx->r4, 0X26B8);
    osStartThread_recomp(rdram, ctx);
        goto after_16;
    // 0x800D21A8: addiu       $a0, $a0, 0x26B8
    ctx->r4 = ADD32(ctx->r4, 0X26B8);
    after_16:
    // 0x800D21AC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D21B0: addiu       $t6, $t6, 0x23B0
    ctx->r14 = ADD32(ctx->r14, 0X23B0);
    // 0x800D21B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D21B8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D21BC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800D21C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D21C4: addiu       $a2, $a2, 0x25F0
    ctx->r6 = ADD32(ctx->r6, 0X25F0);
    // 0x800D21C8: addiu       $a0, $a0, 0x2868
    ctx->r4 = ADD32(ctx->r4, 0X2868);
    // 0x800D21CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D21D0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x800D21D4: jal         0x800D76A0
    // 0x800D21D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_17;
    // 0x800D21D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x800D21DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D21E0: jal         0x800D77F0
    // 0x800D21E4: addiu       $a0, $a0, 0x2868
    ctx->r4 = ADD32(ctx->r4, 0X2868);
    osStartThread_recomp(rdram, ctx);
        goto after_18;
    // 0x800D21E4: addiu       $a0, $a0, 0x2868
    ctx->r4 = ADD32(ctx->r4, 0X2868);
    after_18:
    // 0x800D21E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D21EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D21F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D21F4: jr          $ra
    // 0x800D21F8: nop

    return;
    // 0x800D21F8: nop

;}
RECOMP_FUNC void func_800D21FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D21FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D2200: jr          $ra
    // 0x800D2204: addiu       $v0, $v0, 0x23B4
    ctx->r2 = ADD32(ctx->r2, 0X23B4);
    return;
    // 0x800D2204: addiu       $v0, $v0, 0x23B4
    ctx->r2 = ADD32(ctx->r2, 0X23B4);
;}
RECOMP_FUNC void func_800D2208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2208: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D220C: jr          $ra
    // 0x800D2210: addiu       $v0, $v0, 0x23EC
    ctx->r2 = ADD32(ctx->r2, 0X23EC);
    return;
    // 0x800D2210: addiu       $v0, $v0, 0x23EC
    ctx->r2 = ADD32(ctx->r2, 0X23EC);
;}
RECOMP_FUNC void func_800D2214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2214: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D2218: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D221C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D2220: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D2224: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D2228: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D222C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2230: addiu       $s0, $s0, 0x2A30
    ctx->r16 = ADD32(ctx->r16, 0X2A30);
    // 0x800D2234: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D2238: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D223C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D2240: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800D2244: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800D2248: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800D224C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x800D2250: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D2254: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800D2258: addiu       $s7, $s7, 0x23B0
    ctx->r23 = ADD32(ctx->r23, 0X23B0);
    // 0x800D225C: addiu       $s6, $s6, -0x4410
    ctx->r22 = ADD32(ctx->r22, -0X4410);
    // 0x800D2260: addiu       $s5, $s5, 0x23B2
    ctx->r21 = ADD32(ctx->r21, 0X23B2);
    // 0x800D2264: addiu       $s1, $s1, 0x2424
    ctx->r17 = ADD32(ctx->r17, 0X2424);
    // 0x800D2268: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x800D226C: addiu       $s3, $zero, 0x29A
    ctx->r19 = ADD32(0, 0X29A);
    // 0x800D2270: addiu       $s4, $zero, 0x29D
    ctx->r20 = ADD32(0, 0X29D);
    // 0x800D2274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D2278:
    // 0x800D2278: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D227C: jal         0x800D8D00
    // 0x800D2280: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2280: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D2284: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800D2288: beql        $v0, $s3, L_800D22A4
    if (ctx->r2 == ctx->r19) {
        // 0x800D228C: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800D22A4;
    }
    goto skip_0;
    // 0x800D228C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800D2290: beq         $v0, $s4, L_800D22BC
    if (ctx->r2 == ctx->r20) {
        // 0x800D2294: nop
    
            goto L_800D22BC;
    }
    // 0x800D2294: nop

    // 0x800D2298: b           L_800D2278
    // 0x800D229C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800D2278;
    // 0x800D229C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D22A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800D22A4:
    // 0x800D22A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800D22A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D22AC: jal         0x800D23FC
    // 0x800D22B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    func_800D23FC(rdram, ctx);
        goto after_1;
    // 0x800D22B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_1:
    // 0x800D22B4: b           L_800D2278
    // 0x800D22B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800D2278;
    // 0x800D22B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D22BC:
    // 0x800D22BC: jal         0x800D23FC
    // 0x800D22C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800D23FC(rdram, ctx);
        goto after_2;
    // 0x800D22C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x800D22C4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800D22C8: beql        $v0, $zero, L_800D2278
    if (ctx->r2 == 0) {
        // 0x800D22CC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2278;
    }
    goto skip_1;
    // 0x800D22CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x800D22D0: jalr        $v0
    // 0x800D22D4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800D22D4: nop

    after_3:
    // 0x800D22D8: b           L_800D2278
    // 0x800D22DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800D2278;
    // 0x800D22DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D22E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D22E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D22E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D22EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D22F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D22F4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D22F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D22FC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2300: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800D2304: jr          $ra
    // 0x800D2308: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D2308: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800D230C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D230C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2314: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D2318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D231C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D2320: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800D2324: jal         0x800D9740
    // 0x800D2328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D232C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D2330: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2334: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D2338: addiu       $v1, $v1, 0x23B0
    ctx->r3 = ADD32(ctx->r3, 0X23B0);
    // 0x800D233C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800D2340: lw          $t7, 0x668($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X668);
    // 0x800D2344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2348: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800D234C: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x800D2350: sh          $t8, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r24;
    // 0x800D2354: jal         0x800D9740
    // 0x800D2358: sw          $a3, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r7;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2358: sw          $a3, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r7;
    after_1:
    // 0x800D235C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2364: jr          $ra
    // 0x800D2368: nop

    return;
    // 0x800D2368: nop

;}
RECOMP_FUNC void func_800D236C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D236C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D2370: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D2374: lw          $v1, 0x2A18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2A18);
    // 0x800D2378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D237C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D2380: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D2384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D2388: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800D238C: jal         0x800D9740
    // 0x800D2390: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2390: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800D2394: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2398: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D239C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D23A0: beq         $v1, $zero, L_800D23E4
    if (ctx->r3 == 0) {
        // 0x800D23A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D23E4;
    }
    // 0x800D23A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D23A8:
    // 0x800D23A8: bnel        $v1, $a2, L_800D23D8
    if (ctx->r3 != ctx->r6) {
        // 0x800D23AC: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800D23D8;
    }
    goto skip_0;
    // 0x800D23AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    skip_0:
    // 0x800D23B0: beql        $a1, $zero, L_800D23C8
    if (ctx->r5 == 0) {
        // 0x800D23B4: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D23C8;
    }
    goto skip_1;
    // 0x800D23B4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x800D23B8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D23BC: b           L_800D23E4
    // 0x800D23C0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800D23E4;
    // 0x800D23C0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D23C4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D23C8:
    // 0x800D23C8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D23CC: b           L_800D23E4
    // 0x800D23D0: sw          $t7, 0x2A18($at)
    MEM_W(0X2A18, ctx->r1) = ctx->r15;
        goto L_800D23E4;
    // 0x800D23D0: sw          $t7, 0x2A18($at)
    MEM_W(0X2A18, ctx->r1) = ctx->r15;
    // 0x800D23D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800D23D8:
    // 0x800D23D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800D23DC: bne         $v1, $zero, L_800D23A8
    if (ctx->r3 != 0) {
        // 0x800D23E0: nop
    
            goto L_800D23A8;
    }
    // 0x800D23E0: nop

L_800D23E4:
    // 0x800D23E4: jal         0x800D9740
    // 0x800D23E8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D23E8: nop

    after_1:
    // 0x800D23EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D23F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D23F4: jr          $ra
    // 0x800D23F8: nop

    return;
    // 0x800D23F8: nop

;}
RECOMP_FUNC void func_800D23FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D23FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D2400: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D2404: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D2408: lw          $s0, 0x2A18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2A18);
    // 0x800D240C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2410: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D2414: beq         $s0, $zero, L_800D244C
    if (ctx->r16 == 0) {
        // 0x800D2418: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800D244C;
    }
    // 0x800D2418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D241C: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
L_800D2420:
    // 0x800D2420: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800D2424: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2428: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D242C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800D2430: beql        $t8, $zero, L_800D2444
    if (ctx->r24 == 0) {
        // 0x800D2434: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2444;
    }
    goto skip_0;
    // 0x800D2434: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800D2438: jal         0x800D95F0
    // 0x800D243C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D243C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x800D2440: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2444:
    // 0x800D2444: bnel        $s0, $zero, L_800D2420
    if (ctx->r16 != 0) {
        // 0x800D2448: lh          $t6, 0x0($s1)
        ctx->r14 = MEM_H(ctx->r17, 0X0);
            goto L_800D2420;
    }
    goto skip_1;
    // 0x800D2448: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    skip_1:
L_800D244C:
    // 0x800D244C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2450: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D2454: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D2458: jr          $ra
    // 0x800D245C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D245C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D2460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2460: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D2464: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D2468: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D246C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D2470: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D2474: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D2478: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D247C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2480: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800D2484: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800D2488: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800D248C: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800D2490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D2494: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D2498: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D249C: addiu       $fp, $fp, 0x24CC
    ctx->r30 = ADD32(ctx->r30, 0X24CC);
    // 0x800D24A0: addiu       $s6, $s6, 0x23B4
    ctx->r22 = ADD32(ctx->r22, 0X23B4);
    // 0x800D24A4: addiu       $s5, $s5, 0x245C
    ctx->r21 = ADD32(ctx->r21, 0X245C);
    // 0x800D24A8: addiu       $s2, $s2, 0x23B0
    ctx->r18 = ADD32(ctx->r18, 0X23B0);
    // 0x800D24AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D24B0: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x800D24B4: addiu       $s7, $sp, 0x50
    ctx->r23 = ADD32(ctx->r29, 0X50);
    // 0x800D24B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_800D24BC:
    // 0x800D24BC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D24C0: jal         0x800D8D00
    // 0x800D24C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D24C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D24C8: jal         0x800D9DD0
    // 0x800D24CC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x800D24CC: nop

    after_1:
    // 0x800D24D0: lw          $s1, 0x66C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X66C);
    // 0x800D24D4: beql        $s1, $zero, L_800D2510
    if (ctx->r17 == 0) {
        // 0x800D24D8: lw          $s4, 0x50($sp)
        ctx->r20 = MEM_W(ctx->r29, 0X50);
            goto L_800D2510;
    }
    goto skip_0;
    // 0x800D24D8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x800D24DC: jal         0x800DA760
    // 0x800D24E0: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_2;
    // 0x800D24E0: nop

    after_2:
    // 0x800D24E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D24E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D24EC: jal         0x800D8D00
    // 0x800D24F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D24F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800D24F4: jal         0x800DA780
    // 0x800D24F8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_4;
    // 0x800D24F8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    after_4:
    // 0x800D24FC: beq         $v0, $zero, L_800D250C
    if (ctx->r2 == 0) {
        // 0x800D2500: addiu       $s0, $zero, 0x2
        ctx->r16 = ADD32(0, 0X2);
            goto L_800D250C;
    }
    // 0x800D2500: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800D2504: b           L_800D250C
    // 0x800D2508: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800D250C;
    // 0x800D2508: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800D250C:
    // 0x800D250C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
L_800D2510:
    // 0x800D2510: sw          $s4, 0x670($s2)
    MEM_W(0X670, ctx->r18) = ctx->r20;
    // 0x800D2514: jal         0x800DA91C
    // 0x800D2518: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_5;
    // 0x800D2518: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    after_5:
    // 0x800D251C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800D2520: jal         0x800DAAAC
    // 0x800D2524: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_6;
    // 0x800D2524: addiu       $a0, $s4, 0x10
    ctx->r4 = ADD32(ctx->r20, 0X10);
    after_6:
    // 0x800D2528: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D252C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D2530: jal         0x800D8D00
    // 0x800D2534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800D2534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800D2538: lw          $t6, 0x674($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X674);
    // 0x800D253C: sw          $zero, 0x670($s2)
    MEM_W(0X670, ctx->r18) = 0;
    // 0x800D2540: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D2544: beq         $t6, $zero, L_800D2554
    if (ctx->r14 == 0) {
        // 0x800D2548: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_800D2554;
    }
    // 0x800D2548: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D254C: jal         0x800D95F0
    // 0x800D2550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800D2550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
L_800D2554:
    // 0x800D2554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2558: bnel        $s0, $at, L_800D2580
    if (ctx->r16 != ctx->r1) {
        // 0x800D255C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D2580;
    }
    goto skip_1;
    // 0x800D255C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x800D2560: addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // 0x800D2564: jal         0x800DA91C
    // 0x800D2568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_9;
    // 0x800D2568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800D256C: jal         0x800DAAAC
    // 0x800D2570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_10;
    // 0x800D2570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800D2574: b           L_800D2598
    // 0x800D2578: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
        goto L_800D2598;
    // 0x800D2578: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800D257C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800D2580:
    // 0x800D2580: bne         $s0, $at, L_800D2594
    if (ctx->r16 != ctx->r1) {
        // 0x800D2584: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D2594;
    }
    // 0x800D2584: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2588: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D258C: jal         0x800D95F0
    // 0x800D2590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x800D2590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
L_800D2594:
    // 0x800D2594: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_800D2598:
    // 0x800D2598: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D259C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D25A0: lw          $a0, 0x50($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X50);
    // 0x800D25A4: jal         0x800D95F0
    // 0x800D25A8: lw          $a1, 0x54($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X54);
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x800D25A8: lw          $a1, 0x54($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X54);
    after_12:
    // 0x800D25AC: b           L_800D24BC
    // 0x800D25B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_800D24BC;
    // 0x800D25B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D25B4: nop

    // 0x800D25B8: nop

    // 0x800D25BC: nop

    // 0x800D25C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D25C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D25C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D25CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D25D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D25D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D25D8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D25DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D25E0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D25E4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D25E8: jr          $ra
    // 0x800D25EC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800D25EC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800D25F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D25F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D25F4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D25F8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D25FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D2600: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D2604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2608: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D260C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D2610: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D2614: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800D2618: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800D261C: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800D2620: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800D2624: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D2628: addiu       $s6, $s6, 0x2494
    ctx->r22 = ADD32(ctx->r22, 0X2494);
    // 0x800D262C: addiu       $s5, $s5, 0x245C
    ctx->r21 = ADD32(ctx->r21, 0X245C);
    // 0x800D2630: addiu       $s4, $s4, 0x24CC
    ctx->r20 = ADD32(ctx->r20, 0X24CC);
    // 0x800D2634: addiu       $s2, $s2, 0x23EC
    ctx->r18 = ADD32(ctx->r18, 0X23EC);
    // 0x800D2638: addiu       $s0, $s0, 0x23B0
    ctx->r16 = ADD32(ctx->r16, 0X23B0);
    // 0x800D263C: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x800D2640: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800D2644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D2648:
    // 0x800D2648: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D264C: jal         0x800D8D00
    // 0x800D2650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D2654: jal         0x800D2768
    // 0x800D2658: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800D2768(rdram, ctx);
        goto after_1;
    // 0x800D2658: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800D265C: jal         0x800D9740
    // 0x800D2660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800D2664: lw          $t6, 0x670($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X670);
    // 0x800D2668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D266C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800D2670: beq         $t6, $zero, L_800D26A0
    if (ctx->r14 == 0) {
        // 0x800D2674: nop
    
            goto L_800D26A0;
    }
    // 0x800D2674: nop

    // 0x800D2678: jal         0x800D9740
    // 0x800D267C: sw          $t7, 0x674($s0)
    MEM_W(0X674, ctx->r16) = ctx->r15;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800D267C: sw          $t7, 0x674($s0)
    MEM_W(0X674, ctx->r16) = ctx->r15;
    after_3:
    // 0x800D2680: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2688: jal         0x800D8D00
    // 0x800D268C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800D268C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800D2690: jal         0x800D9740
    // 0x800D2694: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_5;
    // 0x800D2694: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800D2698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D269C: sw          $zero, 0x674($s0)
    MEM_W(0X674, ctx->r16) = 0;
L_800D26A0:
    // 0x800D26A0: jal         0x800D9740
    // 0x800D26A4: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800D26A4: nop

    after_6:
    // 0x800D26A8: jal         0x800D9740
    // 0x800D26AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_7;
    // 0x800D26AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800D26B0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800D26B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D26B8: jal         0x800D9740
    // 0x800D26BC: sw          $t8, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = ctx->r24;
    osSetIntMask_recomp(rdram, ctx);
        goto after_8;
    // 0x800D26BC: sw          $t8, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = ctx->r24;
    after_8:
    // 0x800D26C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D26C4: jal         0x800DA91C
    // 0x800D26C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_9;
    // 0x800D26C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_9:
    // 0x800D26CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D26D0: jal         0x800DAAAC
    // 0x800D26D4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_10;
    // 0x800D26D4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x800D26D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D26DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D26E0: jal         0x800D8D00
    // 0x800D26E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x800D26E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800D26E8: jal         0x800D9740
    // 0x800D26EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_12;
    // 0x800D26EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x800D26F0: sw          $zero, 0x66C($s0)
    MEM_W(0X66C, ctx->r16) = 0;
    // 0x800D26F4: jal         0x800D9740
    // 0x800D26F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_13;
    // 0x800D26F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x800D26FC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800D2700: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D2704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2708: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800D270C: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800D2710: bnel        $t1, $zero, L_800D2724
    if (ctx->r9 != 0) {
        // 0x800D2714: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800D2724;
    }
    goto skip_0;
    // 0x800D2714: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800D2718: jal         0x800D8D00
    // 0x800D271C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x800D271C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x800D2720: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800D2724:
    // 0x800D2724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D2728: jal         0x800D95F0
    // 0x800D272C: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    osSendMesg_recomp(rdram, ctx);
        goto after_15;
    // 0x800D272C: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    after_15:
    // 0x800D2730: b           L_800D2648
    // 0x800D2734: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_800D2648;
    // 0x800D2734: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D2738: nop

    // 0x800D273C: nop

    // 0x800D2740: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D2744: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2748: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D274C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2750: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D2754: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D2758: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D275C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D2760: jr          $ra
    // 0x800D2764: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D2764: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800D2768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2768: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D276C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2770: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800D2774: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D2778: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D277C: addiu       $s1, $s1, 0x24CC
    ctx->r17 = ADD32(ctx->r17, 0X24CC);
    // 0x800D2780: lw          $s0, 0xC($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC);
    // 0x800D2784: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800D2788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D278C: jal         0x800D230C
    // 0x800D2790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D230C(rdram, ctx);
        goto after_0;
    // 0x800D2790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D2794: jal         0x800DAAF0
    // 0x800D2798: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2798: nop

    after_1:
    // 0x800D279C: beql        $v0, $s0, L_800D27B4
    if (ctx->r2 == ctx->r16) {
        // 0x800D27A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D27B4;
    }
    goto skip_0;
    // 0x800D27A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800D27A4: jal         0x800DAB30
    // 0x800D27A8: nop

    func_800DAB30(rdram, ctx);
        goto after_2;
    // 0x800D27A8: nop

    after_2:
    // 0x800D27AC: bne         $v0, $s0, L_800D27E0
    if (ctx->r2 != ctx->r16) {
        // 0x800D27B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D27E0;
    }
    // 0x800D27B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D27B4:
    // 0x800D27B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D27B8: jal         0x800D8D00
    // 0x800D27BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D27BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800D27C0: jal         0x800DAAF0
    // 0x800D27C4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x800D27C4: nop

    after_4:
    // 0x800D27C8: beql        $v0, $s0, L_800D27B4
    if (ctx->r2 == ctx->r16) {
        // 0x800D27CC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D27B4;
    }
    goto skip_1;
    // 0x800D27CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x800D27D0: jal         0x800DAB30
    // 0x800D27D4: nop

    func_800DAB30(rdram, ctx);
        goto after_5;
    // 0x800D27D4: nop

    after_5:
    // 0x800D27D8: beql        $v0, $s0, L_800D27B4
    if (ctx->r2 == ctx->r16) {
        // 0x800D27DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D27B4;
    }
    goto skip_2;
    // 0x800D27DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
L_800D27E0:
    // 0x800D27E0: jal         0x800D236C
    // 0x800D27E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800D236C(rdram, ctx);
        goto after_6;
    // 0x800D27E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x800D27E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D27EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D27F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D27F4: jr          $ra
    // 0x800D27F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D27F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D27FC: nop

;}
RECOMP_FUNC void func_800D2800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2800: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D2804: lw          $t6, 0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X708C);
    // 0x800D2808: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D280C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2810: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800D2814: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800D2818: beq         $t6, $zero, L_800D28B0
    if (ctx->r14 == 0) {
        // 0x800D281C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D28B0;
    }
    // 0x800D281C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D2820: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D2824: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800D2828: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800D282C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D2830: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D2834: lbu         $t8, 0x7067($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7067);
    // 0x800D2838: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D283C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800D2840: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800D2844: bne         $t9, $zero, L_800D28B0
    if (ctx->r25 != 0) {
        // 0x800D2848: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800D28B0;
    }
    // 0x800D2848: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D284C: jal         0x800D8B80
    // 0x800D2850: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2850: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D2854: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800D2858: lhu         $t0, 0x5E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X5E);
    // 0x800D285C: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x800D2860: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800D2864: addiu       $t3, $zero, 0x3001
    ctx->r11 = ADD32(0, 0X3001);
    // 0x800D2868: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x800D286C: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800D2870: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2874: sb          $t2, 0x52($sp)
    MEM_B(0X52, ctx->r29) = ctx->r10;
    // 0x800D2878: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x800D287C: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x800D2880: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800D2884: addiu       $a0, $a0, 0x6E18
    ctx->r4 = ADD32(ctx->r4, 0X6E18);
    // 0x800D2888: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D288C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D2890: sb          $a3, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r7;
    // 0x800D2894: sh          $t0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r8;
    // 0x800D2898: jal         0x800D95F0
    // 0x800D289C: sh          $t1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r9;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D289C: sh          $t1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r9;
    after_1:
    // 0x800D28A0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D28A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D28A8: jal         0x800D8D00
    // 0x800D28AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D28AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800D28B0:
    // 0x800D28B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D28B4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D28B8: jr          $ra
    // 0x800D28BC: nop

    return;
    // 0x800D28BC: nop

;}
RECOMP_FUNC void func_800D28C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D28C0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D28C4: lw          $t6, 0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X708C);
    // 0x800D28C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D28CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D28D0: beq         $t6, $zero, L_800D2918
    if (ctx->r14 == 0) {
        // 0x800D28D4: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800D2918;
    }
    // 0x800D28D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D28D8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800D28DC: jal         0x800D8B80
    // 0x800D28E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D28E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D28E4: addiu       $t7, $zero, 0x3003
    ctx->r15 = ADD32(0, 0X3003);
    // 0x800D28E8: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x800D28EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D28F0: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x800D28F4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800D28F8: addiu       $a0, $a0, 0x6E18
    ctx->r4 = ADD32(ctx->r4, 0X6E18);
    // 0x800D28FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800D2900: jal         0x800D95F0
    // 0x800D2904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D2908: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2910: jal         0x800D8D00
    // 0x800D2914: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2914: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800D2918:
    // 0x800D2918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D291C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800D2920: jr          $ra
    // 0x800D2924: nop

    return;
    // 0x800D2924: nop

    // 0x800D2928: nop

    // 0x800D292C: nop

;}
RECOMP_FUNC void func_800D2930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2930: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D2934: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D2938: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D293C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D2940: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800D2944: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800D2948: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800D294C: addiu       $s6, $s6, -0x43FC
    ctx->r22 = ADD32(ctx->r22, -0X43FC);
    // 0x800D2950: addiu       $s5, $s5, -0x4400
    ctx->r21 = ADD32(ctx->r21, -0X4400);
    // 0x800D2954: addiu       $s4, $s4, 0x2A40
    ctx->r20 = ADD32(ctx->r20, 0X2A40);
    // 0x800D2958: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D295C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D2960: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2964: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D2968: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D296C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D2970: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D2974: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800D2978: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x800D297C: addiu       $a1, $a1, 0x2A58
    ctx->r5 = ADD32(ctx->r5, 0X2A58);
    // 0x800D2980: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2984: jal         0x800D8B80
    // 0x800D2988: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2988: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800D298C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D2990: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2994: jal         0x800D230C
    // 0x800D2998: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D230C(rdram, ctx);
        goto after_1;
    // 0x800D2998: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x800D299C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800D29A0: addiu       $s3, $s3, -0x3D80
    ctx->r19 = ADD32(ctx->r19, -0X3D80);
    // 0x800D29A4: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800D29A8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800D29AC: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800D29B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800D29B4:
    // 0x800D29B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D29B8: jal         0x800D8D00
    // 0x800D29BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D29BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800D29C0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800D29C4: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x800D29C8: beql        $v0, $s1, L_800D29E4
    if (ctx->r2 == ctx->r17) {
        // 0x800D29CC: lw          $v0, 0x0($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X0);
            goto L_800D29E4;
    }
    goto skip_0;
    // 0x800D29CC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x800D29D0: beql        $v0, $s2, L_800D2A00
    if (ctx->r2 == ctx->r18) {
        // 0x800D29D4: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_800D2A00;
    }
    goto skip_1;
    // 0x800D29D4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800D29D8: b           L_800D29B4
    // 0x800D29DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_800D29B4;
    // 0x800D29DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D29E0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
L_800D29E4:
    // 0x800D29E4: beql        $v0, $zero, L_800D29B4
    if (ctx->r2 == 0) {
        // 0x800D29E8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D29B4;
    }
    goto skip_2;
    // 0x800D29E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_2:
    // 0x800D29EC: jalr        $v0
    // 0x800D29F0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800D29F0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_3:
    // 0x800D29F4: b           L_800D29B4
    // 0x800D29F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_800D29B4;
    // 0x800D29F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D29FC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_800D2A00:
    // 0x800D2A00: beql        $v0, $zero, L_800D29B4
    if (ctx->r2 == 0) {
        // 0x800D2A04: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D29B4;
    }
    goto skip_3;
    // 0x800D2A04: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
    // 0x800D2A08: jalr        $v0
    // 0x800D2A0C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800D2A0C: nop

    after_4:
    // 0x800D2A10: b           L_800D29B4
    // 0x800D2A14: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_800D29B4;
    // 0x800D2A14: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2A18: nop

    // 0x800D2A1C: nop

    // 0x800D2A20: nop

    // 0x800D2A24: nop

    // 0x800D2A28: nop

    // 0x800D2A2C: nop

    // 0x800D2A30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D2A34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D2A38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2A3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D2A40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D2A44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D2A48: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2A4C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D2A50: jr          $ra
    // 0x800D2A54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D2A54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800D2A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2A58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D2A5C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D2A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D2A64: addiu       $t6, $t6, 0x4C28
    ctx->r14 = ADD32(ctx->r14, 0X4C28);
    // 0x800D2A68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2A6C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D2A70: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800D2A74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D2A78: addiu       $a2, $a2, 0x2930
    ctx->r6 = ADD32(ctx->r6, 0X2930);
    // 0x800D2A7C: addiu       $a0, $a0, 0x2A78
    ctx->r4 = ADD32(ctx->r4, 0X2A78);
    // 0x800D2A80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D2A84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800D2A88: jal         0x800D76A0
    // 0x800D2A8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2A8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800D2A90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2A94: jal         0x800D77F0
    // 0x800D2A98: addiu       $a0, $a0, 0x2A78
    ctx->r4 = ADD32(ctx->r4, 0X2A78);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2A98: addiu       $a0, $a0, 0x2A78
    ctx->r4 = ADD32(ctx->r4, 0X2A78);
    after_1:
    // 0x800D2A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D2AA4: jr          $ra
    // 0x800D2AA8: nop

    return;
    // 0x800D2AA8: nop

    // 0x800D2AAC: nop

;}
RECOMP_FUNC void func_800D2AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2AB0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D2AB4: addiu       $v0, $v0, -0x3D60
    ctx->r2 = ADD32(ctx->r2, -0X3D60);
    // 0x800D2AB8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800D2ABC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2AC0: sw          $a1, -0x4420($at)
    MEM_W(-0X4420, ctx->r1) = ctx->r5;
    // 0x800D2AC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D2AC8: sw          $zero, -0x3D50($at)
    MEM_W(-0X3D50, ctx->r1) = 0;
    // 0x800D2ACC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D2AD0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D2AD4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800D2AD8: jr          $ra
    // 0x800D2ADC: sw          $t7, -0x3D5C($at)
    MEM_W(-0X3D5C, ctx->r1) = ctx->r15;
    return;
    // 0x800D2ADC: sw          $t7, -0x3D5C($at)
    MEM_W(-0X3D5C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800D2AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D2AEC: jal         0x800D9740
    // 0x800D2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D2AF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D2AF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D2AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2B00: jal         0x800D9740
    // 0x800D2B04: sw          $t6, -0x441C($at)
    MEM_W(-0X441C, ctx->r1) = ctx->r14;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2B04: sw          $t6, -0x441C($at)
    MEM_W(-0X441C, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D2B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2B10: jr          $ra
    // 0x800D2B14: nop

    return;
    // 0x800D2B14: nop

    // 0x800D2B18: nop

    // 0x800D2B1C: nop

;}
RECOMP_FUNC void func_800D2B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2B28: jal         0x800DAB70
    // 0x800D2B2C: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2B2C: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    after_0:
    // 0x800D2B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2B38: jr          $ra
    // 0x800D2B3C: nop

    return;
    // 0x800D2B3C: nop

;}
RECOMP_FUNC void func_800D2B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2B40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D2B44: addiu       $v0, $v0, -0x3D80
    ctx->r2 = ADD32(ctx->r2, -0X3D80);
    // 0x800D2B48: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D2B4C: beq         $t6, $zero, L_800D2B60
    if (ctx->r14 == 0) {
        // 0x800D2B50: nop
    
            goto L_800D2B60;
    }
    // 0x800D2B50: nop

    // 0x800D2B54: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_800D2B58:
    // 0x800D2B58: bnel        $t7, $zero, L_800D2B58
    if (ctx->r15 != 0) {
        // 0x800D2B5C: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_800D2B58;
    }
    goto skip_0;
    // 0x800D2B5C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_0:
L_800D2B60:
    // 0x800D2B60: jr          $ra
    // 0x800D2B64: nop

    return;
    // 0x800D2B64: nop

    // 0x800D2B68: nop

    // 0x800D2B6C: nop

;}
RECOMP_FUNC void func_800D2B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2B70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D2B74: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800D2B78: addiu       $v0, $v0, 0x6E30
    ctx->r2 = ADD32(ctx->r2, 0X6E30);
    // 0x800D2B7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D2B80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2B84: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2B88: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D2B8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D2B90: addiu       $a1, $a1, 0x4C48
    ctx->r5 = ADD32(ctx->r5, 0X4C48);
    // 0x800D2B94: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D2B98: jal         0x800D8B80
    // 0x800D2B9C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2B9C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800D2BA0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2BA4: addiu       $a1, $a1, 0x4C30
    ctx->r5 = ADD32(ctx->r5, 0X4C30);
    // 0x800D2BA8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800D2BAC: jal         0x800DA6F0
    // 0x800D2BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800D2BB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2BB8: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D2BBC: addiu       $a1, $sp, 0x37
    ctx->r5 = ADD32(ctx->r29, 0X37);
    // 0x800D2BC0: jal         0x800DABC0
    // 0x800D2BC4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2BC4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800D2BC8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D2BCC: addiu       $t6, $t6, 0x6E18
    ctx->r14 = ADD32(ctx->r14, 0X6E18);
    // 0x800D2BD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2BD4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D2BD8: addiu       $t7, $zero, 0x73
    ctx->r15 = ADD32(0, 0X73);
    // 0x800D2BDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D2BE0: addiu       $a2, $a2, 0x2C18
    ctx->r6 = ADD32(ctx->r6, 0X2C18);
    // 0x800D2BE4: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x800D2BE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D2BEC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D2BF0: jal         0x800D76A0
    // 0x800D2BF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800D2BF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800D2BF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2BFC: jal         0x800D77F0
    // 0x800D2C00: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x800D2C00: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    after_4:
    // 0x800D2C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2C08: lbu         $v0, 0x37($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X37);
    // 0x800D2C0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D2C10: jr          $ra
    // 0x800D2C14: nop

    return;
    // 0x800D2C14: nop

;}
RECOMP_FUNC void func_800D2C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2C18: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800D2C1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D2C20: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800D2C24: addiu       $s1, $s1, 0x6E18
    ctx->r17 = ADD32(ctx->r17, 0X6E18);
    // 0x800D2C28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D2C2C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800D2C30: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D2C34: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D2C38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D2C3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2C40: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800D2C44: jal         0x800D8B80
    // 0x800D2C48: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2C48: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800D2C4C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800D2C50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D2C54: jal         0x800D230C
    // 0x800D2C58: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D230C(rdram, ctx);
        goto after_1;
    // 0x800D2C58: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x800D2C5C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800D2C60: addiu       $s3, $s3, 0x6E30
    ctx->r19 = ADD32(ctx->r19, 0X6E30);
    // 0x800D2C64: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x800D2C68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800D2C6C:
    // 0x800D2C6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D2C70: jal         0x800D8D00
    // 0x800D2C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2C74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800D2C78: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800D2C7C: beql        $s0, $zero, L_800D2C6C
    if (ctx->r16 == 0) {
        // 0x800D2C80: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2C6C;
    }
    goto skip_0;
    // 0x800D2C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800D2C84: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800D2C88:
    // 0x800D2C88: beql        $v0, $zero, L_800D2CA4
    if (ctx->r2 == 0) {
        // 0x800D2C8C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800D2CA4;
    }
    goto skip_1;
    // 0x800D2C8C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800D2C90: jalr        $v0
    // 0x800D2C94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800D2C94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x800D2C98: bnel        $v0, $zero, L_800D2C6C
    if (ctx->r2 != 0) {
        // 0x800D2C9C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D2C6C;
    }
    goto skip_2;
    // 0x800D2C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x800D2CA0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800D2CA4:
    // 0x800D2CA4: bnel        $s0, $zero, L_800D2C88
    if (ctx->r16 != 0) {
        // 0x800D2CA8: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_800D2C88;
    }
    goto skip_3;
    // 0x800D2CA8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x800D2CAC: b           L_800D2C6C
    // 0x800D2CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800D2C6C;
    // 0x800D2CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D2CB4: nop

    // 0x800D2CB8: nop

    // 0x800D2CBC: nop

    // 0x800D2CC0: nop

    // 0x800D2CC4: nop

    // 0x800D2CC8: nop

    // 0x800D2CCC: nop

    // 0x800D2CD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D2CD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D2CD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D2CDC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2CE0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D2CE4: jr          $ra
    // 0x800D2CE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800D2CE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800D2CEC: nop

;}
RECOMP_FUNC void func_800D2CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2CF0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D2CF4: lw          $t6, 0x7054($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7054);
    // 0x800D2CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2D00: beq         $t6, $zero, L_800D2D10
    if (ctx->r14 == 0) {
        // 0x800D2D04: nop
    
            goto L_800D2D10;
    }
    // 0x800D2D04: nop

    // 0x800D2D08: b           L_800D2E78
    // 0x800D2D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D2E78;
    // 0x800D2D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D2D10:
    // 0x800D2D10: jal         0x800D38C4
    // 0x800D2D14: nop

    func_800D38C4(rdram, ctx);
        goto after_0;
    // 0x800D2D14: nop

    after_0:
    // 0x800D2D18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2D1C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2D20: addiu       $a1, $a1, 0x6E58
    ctx->r5 = ADD32(ctx->r5, 0X6E58);
    // 0x800D2D24: addiu       $a0, $a0, 0x6E40
    ctx->r4 = ADD32(ctx->r4, 0X6E40);
    // 0x800D2D28: jal         0x800D8B80
    // 0x800D2D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D2D30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2D34: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D2D38: addiu       $a1, $a1, 0x6E78
    ctx->r5 = ADD32(ctx->r5, 0X6E78);
    // 0x800D2D3C: addiu       $a0, $a0, 0x6E60
    ctx->r4 = ADD32(ctx->r4, 0X6E60);
    // 0x800D2D40: jal         0x800D8B80
    // 0x800D2D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800D2D48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2D4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D2D50: addiu       $a1, $a1, 0x2FD0
    ctx->r5 = ADD32(ctx->r5, 0X2FD0);
    // 0x800D2D54: jal         0x800D3900
    // 0x800D2D58: addiu       $a0, $a0, 0x7050
    ctx->r4 = ADD32(ctx->r4, 0X7050);
    func_800D3900(rdram, ctx);
        goto after_3;
    // 0x800D2D58: addiu       $a0, $a0, 0x7050
    ctx->r4 = ADD32(ctx->r4, 0X7050);
    after_3:
    // 0x800D2D5C: jal         0x800D3980
    // 0x800D2D60: nop

    func_800D3980(rdram, ctx);
        goto after_4;
    // 0x800D2D60: nop

    after_4:
    // 0x800D2D64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D2D68: addiu       $v1, $v1, 0x6EA8
    ctx->r3 = ADD32(ctx->r3, 0X6EA8);
    // 0x800D2D6C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800D2D70: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D2D74: lbu         $t7, 0x6E83($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6E83);
    // 0x800D2D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D2D7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D2D80: beq         $t7, $zero, L_800D2D90
    if (ctx->r15 == 0) {
        // 0x800D2D84: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_800D2D90;
    }
    // 0x800D2D84: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D2D88: b           L_800D2DBC
    // 0x800D2D8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_800D2DBC;
    // 0x800D2D8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_800D2D90:
    // 0x800D2D90: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D2D94: lhu         $t8, 0x6E80($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X6E80);
    // 0x800D2D98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800D2D9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800D2DA0: andi        $t9, $t8, 0x5
    ctx->r25 = ctx->r24 & 0X5;
    // 0x800D2DA4: bne         $a1, $t9, L_800D2DBC
    if (ctx->r5 != ctx->r25) {
        // 0x800D2DA8: nop
    
            goto L_800D2DBC;
    }
    // 0x800D2DA8: nop

    // 0x800D2DAC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800D2DB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D2DB4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800D2DB8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800D2DBC:
    // 0x800D2DBC: lbu         $t2, 0x6E87($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X6E87);
    // 0x800D2DC0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D2DC4: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800D2DC8: bne         $t2, $zero, L_800D2DFC
    if (ctx->r10 != 0) {
        // 0x800D2DCC: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_800D2DFC;
    }
    // 0x800D2DCC: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800D2DD0: lhu         $t3, 0x6E84($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X6E84);
    // 0x800D2DD4: andi        $t4, $t3, 0x5
    ctx->r12 = ctx->r11 & 0X5;
    // 0x800D2DD8: bnel        $a1, $t4, L_800D2DFC
    if (ctx->r5 != ctx->r12) {
        // 0x800D2DDC: andi        $v0, $t8, 0xFF
        ctx->r2 = ctx->r24 & 0XFF;
            goto L_800D2DFC;
    }
    goto skip_0;
    // 0x800D2DDC: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    skip_0:
    // 0x800D2DE0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800D2DE4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800D2DE8: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800D2DEC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800D2DF0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D2DF4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800D2DF8: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
L_800D2DFC:
    // 0x800D2DFC: lbu         $t0, 0x6E8B($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X6E8B);
    // 0x800D2E00: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D2E04: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800D2E08: bne         $t0, $zero, L_800D2E3C
    if (ctx->r8 != 0) {
        // 0x800D2E0C: sll         $t6, $v0, 1
        ctx->r14 = S32(ctx->r2 << 1);
            goto L_800D2E3C;
    }
    // 0x800D2E0C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800D2E10: lhu         $t1, 0x6E88($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X6E88);
    // 0x800D2E14: andi        $t2, $t1, 0x5
    ctx->r10 = ctx->r9 & 0X5;
    // 0x800D2E18: bnel        $a1, $t2, L_800D2E3C
    if (ctx->r5 != ctx->r10) {
        // 0x800D2E1C: andi        $v0, $t6, 0xFF
        ctx->r2 = ctx->r14 & 0XFF;
            goto L_800D2E3C;
    }
    goto skip_1;
    // 0x800D2E1C: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    skip_1:
    // 0x800D2E20: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800D2E24: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800D2E28: andi        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 & 0XFF;
    // 0x800D2E2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D2E30: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800D2E34: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800D2E38: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
L_800D2E3C:
    // 0x800D2E3C: lbu         $t8, 0x6E8F($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6E8F);
    // 0x800D2E40: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800D2E44: bnel        $t8, $zero, L_800D2E78
    if (ctx->r24 != 0) {
        // 0x800D2E48: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800D2E78;
    }
    goto skip_2;
    // 0x800D2E48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_2:
    // 0x800D2E4C: lhu         $t9, 0x6E8C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X6E8C);
    // 0x800D2E50: andi        $t0, $t9, 0x5
    ctx->r8 = ctx->r25 & 0X5;
    // 0x800D2E54: bnel        $a1, $t0, L_800D2E78
    if (ctx->r5 != ctx->r8) {
        // 0x800D2E58: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800D2E78;
    }
    goto skip_3;
    // 0x800D2E58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_3:
    // 0x800D2E5C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800D2E60: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800D2E64: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x800D2E68: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D2E6C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800D2E70: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800D2E74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D2E78:
    // 0x800D2E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2E80: jr          $ra
    // 0x800D2E84: nop

    return;
    // 0x800D2E84: nop

;}
RECOMP_FUNC void func_800D2E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2E90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2E94: jal         0x800D39F0
    // 0x800D2E98: addiu       $a0, $a0, 0x7050
    ctx->r4 = ADD32(ctx->r4, 0X7050);
    func_800D39F0(rdram, ctx);
        goto after_0;
    // 0x800D2E98: addiu       $a0, $a0, 0x7050
    ctx->r4 = ADD32(ctx->r4, 0X7050);
    after_0:
    // 0x800D2E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2EA4: jr          $ra
    // 0x800D2EA8: nop

    return;
    // 0x800D2EA8: nop

;}
RECOMP_FUNC void func_800D2EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2EB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2EB8: addiu       $a0, $a0, 0x6E60
    ctx->r4 = ADD32(ctx->r4, 0X6E60);
    // 0x800D2EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2EC0: jal         0x800D95F0
    // 0x800D2EC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2EC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D2EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2ED0: jr          $ra
    // 0x800D2ED4: nop

    return;
    // 0x800D2ED4: nop

;}
RECOMP_FUNC void func_800D2ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2EE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2EE4: addiu       $a0, $a0, 0x6E60
    ctx->r4 = ADD32(ctx->r4, 0X6E60);
    // 0x800D2EE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2EEC: jal         0x800D8D00
    // 0x800D2EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D2EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2EFC: jr          $ra
    // 0x800D2F00: nop

    return;
    // 0x800D2F00: nop

;}
RECOMP_FUNC void func_800D2F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2F08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D2F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2F10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2F14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D2F18: jal         0x800DAF00
    // 0x800D2F1C: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2F1C: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    after_0:
    // 0x800D2F20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2F24: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D2F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2F2C: jal         0x800D8D00
    // 0x800D2F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D2F34: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D2F38: lw          $t7, 0x6EAC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6EAC);
    // 0x800D2F3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2F40: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800D2F44: bnel        $t8, $zero, L_800D2F68
    if (ctx->r24 != 0) {
        // 0x800D2F48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D2F68;
    }
    goto skip_0;
    // 0x800D2F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D2F4C: jal         0x800D2EAC
    // 0x800D2F50: nop

    func_800D2EAC(rdram, ctx);
        goto after_2;
    // 0x800D2F50: nop

    after_2:
    // 0x800D2F54: jal         0x800DAF84
    // 0x800D2F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osContGetReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x800D2F58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800D2F5C: jal         0x800D2ED8
    // 0x800D2F60: nop

    func_800D2ED8(rdram, ctx);
        goto after_4;
    // 0x800D2F60: nop

    after_4:
    // 0x800D2F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D2F68:
    // 0x800D2F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2F6C: jr          $ra
    // 0x800D2F70: nop

    return;
    // 0x800D2F70: nop

;}
RECOMP_FUNC void func_800D2F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D2F7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2F80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2F84: jal         0x800DB0E0
    // 0x800D2F88: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    osContStartQuery_recomp(rdram, ctx);
        goto after_0;
    // 0x800D2F88: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    after_0:
    // 0x800D2F8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2F90: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D2F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2F98: jal         0x800D8D00
    // 0x800D2F9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D2F9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D2FA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D2FA4: jal         0x800DB164
    // 0x800D2FA8: addiu       $a0, $a0, 0x6E80
    ctx->r4 = ADD32(ctx->r4, 0X6E80);
    osContGetQuery_recomp(rdram, ctx);
        goto after_2;
    // 0x800D2FA8: addiu       $a0, $a0, 0x6E80
    ctx->r4 = ADD32(ctx->r4, 0X6E80);
    after_2:
    // 0x800D2FAC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D2FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D2FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D2FB8: jal         0x800D95F0
    // 0x800D2FBC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D2FBC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_3:
    // 0x800D2FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2FC8: jr          $ra
    // 0x800D2FCC: nop

    return;
    // 0x800D2FCC: nop

;}
RECOMP_FUNC void func_800D2FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2FD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D2FDC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800D2FE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2FE4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D2FE8: beq         $v0, $at, L_800D3018
    if (ctx->r2 == ctx->r1) {
        // 0x800D2FEC: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_800D3018;
    }
    // 0x800D2FEC: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x800D2FF0: beq         $v0, $at, L_800D307C
    if (ctx->r2 == ctx->r1) {
        // 0x800D2FF4: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_800D307C;
    }
    // 0x800D2FF4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800D2FF8: addiu       $at, $zero, 0x1001
    ctx->r1 = ADD32(0, 0X1001);
    // 0x800D2FFC: beq         $v0, $at, L_800D30A4
    if (ctx->r2 == ctx->r1) {
        // 0x800D3000: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800D30A4;
    }
    // 0x800D3000: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3004: addiu       $at, $zero, 0x1002
    ctx->r1 = ADD32(0, 0X1002);
    // 0x800D3008: beq         $v0, $at, L_800D30FC
    if (ctx->r2 == ctx->r1) {
        // 0x800D300C: nop
    
            goto L_800D30FC;
    }
    // 0x800D300C: nop

    // 0x800D3010: b           L_800D3118
    // 0x800D3014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3118;
    // 0x800D3014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3018:
    // 0x800D3018: lw          $t7, 0x6EAC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6EAC);
    // 0x800D301C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3020: addiu       $a0, $a0, 0x6E40
    ctx->r4 = ADD32(ctx->r4, 0X6E40);
    // 0x800D3024: bne         $t7, $zero, L_800D3114
    if (ctx->r15 != 0) {
        // 0x800D3028: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800D3114;
    }
    // 0x800D3028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D302C: jal         0x800D8D00
    // 0x800D3030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3030: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800D3034: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3038: addiu       $a0, $a0, 0x6E90
    ctx->r4 = ADD32(ctx->r4, 0X6E90);
    // 0x800D303C: jal         0x800D2F04
    // 0x800D3040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D2F04(rdram, ctx);
        goto after_1;
    // 0x800D3040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800D3044: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800D3048: lw          $v0, -0x43F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X43F0);
    // 0x800D304C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800D3050: beq         $v0, $zero, L_800D3060
    if (ctx->r2 == 0) {
        // 0x800D3054: nop
    
            goto L_800D3060;
    }
    // 0x800D3054: nop

    // 0x800D3058: jalr        $v0
    // 0x800D305C: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800D305C: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    after_2:
L_800D3060:
    // 0x800D3060: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3064: addiu       $a0, $a0, 0x6E40
    ctx->r4 = ADD32(ctx->r4, 0X6E40);
    // 0x800D3068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D306C: jal         0x800D95F0
    // 0x800D3070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800D3070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800D3074: b           L_800D3118
    // 0x800D3078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3118;
    // 0x800D3078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D307C:
    // 0x800D307C: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800D3080: jal         0x800D2F04
    // 0x800D3084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2F04(rdram, ctx);
        goto after_4;
    // 0x800D3084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800D3088: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D308C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D3094: jal         0x800D95F0
    // 0x800D3098: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800D3098: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_5:
    // 0x800D309C: b           L_800D3118
    // 0x800D30A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3118;
    // 0x800D30A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D30A4:
    // 0x800D30A4: addiu       $a0, $a0, 0x6E40
    ctx->r4 = ADD32(ctx->r4, 0X6E40);
    // 0x800D30A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D30AC: jal         0x800D8D00
    // 0x800D30B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800D30B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x800D30B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D30B8: addiu       $a0, $a0, 0x6E90
    ctx->r4 = ADD32(ctx->r4, 0X6E90);
    // 0x800D30BC: jal         0x800D2F04
    // 0x800D30C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2F04(rdram, ctx);
        goto after_7;
    // 0x800D30C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800D30C4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800D30C8: lw          $v0, -0x43F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X43F0);
    // 0x800D30CC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800D30D0: beq         $v0, $zero, L_800D30E0
    if (ctx->r2 == 0) {
        // 0x800D30D4: nop
    
            goto L_800D30E0;
    }
    // 0x800D30D4: nop

    // 0x800D30D8: jalr        $v0
    // 0x800D30DC: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x800D30DC: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    after_8:
L_800D30E0:
    // 0x800D30E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D30E4: addiu       $a0, $a0, 0x6E40
    ctx->r4 = ADD32(ctx->r4, 0X6E40);
    // 0x800D30E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D30EC: jal         0x800D95F0
    // 0x800D30F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800D30F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800D30F4: b           L_800D3118
    // 0x800D30F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3118;
    // 0x800D30F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D30FC:
    // 0x800D30FC: jal         0x800D2F74
    // 0x800D3100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D2F74(rdram, ctx);
        goto after_10;
    // 0x800D3100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x800D3104: b           L_800D3118
    // 0x800D3108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3118;
    // 0x800D3108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D310C: b           L_800D3118
    // 0x800D3110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3118;
    // 0x800D3110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3114:
    // 0x800D3114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3118:
    // 0x800D3118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D311C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3120: jr          $ra
    // 0x800D3124: nop

    return;
    // 0x800D3124: nop

    // 0x800D3128: nop

    // 0x800D312C: nop

;}
RECOMP_FUNC void func_800D3130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3130: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3134: addiu       $a0, $a0, 0x7088
    ctx->r4 = ADD32(ctx->r4, 0X7088);
    // 0x800D3138: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800D313C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3144: bne         $t6, $zero, L_800D31B4
    if (ctx->r14 != 0) {
        // 0x800D3148: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800D31B4;
    }
    // 0x800D3148: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800D314C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3150: sb          $t7, 0x7066($at)
    MEM_B(0X7066, ctx->r1) = ctx->r15;
    // 0x800D3154: sb          $zero, 0x7067($at)
    MEM_B(0X7067, ctx->r1) = 0;
    // 0x800D3158: sh          $zero, 0x7064($at)
    MEM_H(0X7064, ctx->r1) = 0;
    // 0x800D315C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3160: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D3164: sb          $t8, 0x7070($at)
    MEM_B(0X7070, ctx->r1) = ctx->r24;
    // 0x800D3168: sb          $zero, 0x7071($at)
    MEM_B(0X7071, ctx->r1) = 0;
    // 0x800D316C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3170: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D3174: sh          $t9, 0x706E($at)
    MEM_H(0X706E, ctx->r1) = ctx->r25;
    // 0x800D3178: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D317C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800D3180: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800D3184: sh          $t1, 0x7078($at)
    MEM_H(0X7078, ctx->r1) = ctx->r9;
    // 0x800D3188: sb          $t0, 0x707A($at)
    MEM_B(0X707A, ctx->r1) = ctx->r8;
    // 0x800D318C: sb          $zero, 0x707B($at)
    MEM_B(0X707B, ctx->r1) = 0;
    // 0x800D3190: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3194: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800D3198: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D319C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D31A0: sh          $t3, 0x7082($at)
    MEM_H(0X7082, ctx->r1) = ctx->r11;
    // 0x800D31A4: sb          $t2, 0x7084($at)
    MEM_B(0X7084, ctx->r1) = ctx->r10;
    // 0x800D31A8: sb          $zero, 0x7085($at)
    MEM_B(0X7085, ctx->r1) = 0;
    // 0x800D31AC: jal         0x800D3900
    // 0x800D31B0: addiu       $a1, $a1, 0x37C0
    ctx->r5 = ADD32(ctx->r5, 0X37C0);
    func_800D3900(rdram, ctx);
        goto after_0;
    // 0x800D31B0: addiu       $a1, $a1, 0x37C0
    ctx->r5 = ADD32(ctx->r5, 0X37C0);
    after_0:
L_800D31B4:
    // 0x800D31B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D31B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D31BC: jr          $ra
    // 0x800D31C0: nop

    return;
    // 0x800D31C0: nop

;}
RECOMP_FUNC void func_800D31C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D31C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D31C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D31CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D31D0: jal         0x800D39F0
    // 0x800D31D4: addiu       $a0, $a0, 0x7088
    ctx->r4 = ADD32(ctx->r4, 0X7088);
    func_800D39F0(rdram, ctx);
        goto after_0;
    // 0x800D31D4: addiu       $a0, $a0, 0x7088
    ctx->r4 = ADD32(ctx->r4, 0X7088);
    after_0:
    // 0x800D31D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D31DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D31E0: jr          $ra
    // 0x800D31E4: nop

    return;
    // 0x800D31E4: nop

;}
RECOMP_FUNC void func_800D31E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D31E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D31EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D31F0: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x800D31F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D31F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D31FC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800D3200: beq         $v0, $at, L_800D322C
    if (ctx->r2 == ctx->r1) {
        // 0x800D3204: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D322C;
    }
    // 0x800D3204: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D3208: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D320C: beq         $v0, $at, L_800D33DC
    if (ctx->r2 == ctx->r1) {
        // 0x800D3210: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800D33DC;
    }
    // 0x800D3210: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D3214: beq         $v0, $at, L_800D3284
    if (ctx->r2 == ctx->r1) {
        // 0x800D3218: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D3284;
    }
    // 0x800D3218: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D321C: beq         $v0, $at, L_800D3374
    if (ctx->r2 == ctx->r1) {
        // 0x800D3220: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_800D3374;
    }
    // 0x800D3220: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D3224: b           L_800D33E0
    // 0x800D3228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D33E0;
    // 0x800D3228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D322C:
    // 0x800D322C: lhu         $t6, 0x4($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X4);
    // 0x800D3230: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800D3234: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800D3238: blez        $t6, L_800D3270
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D323C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800D3270;
    }
    // 0x800D323C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800D3240: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D3244: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x800D3248: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D324C: addiu       $t8, $t8, 0x6EB0
    ctx->r24 = ADD32(ctx->r24, 0X6EB0);
    // 0x800D3250: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D3254: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800D3258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D325C: jal         0x800DB190
    // 0x800D3260: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3260: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D3264: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D3268: b           L_800D3274
    // 0x800D326C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D3274;
    // 0x800D326C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D3270:
    // 0x800D3270: sb          $t9, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r25;
L_800D3274:
    // 0x800D3274: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x800D3278: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800D327C: b           L_800D33DC
    // 0x800D3280: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
        goto L_800D33DC;
    // 0x800D3280: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
L_800D3284:
    // 0x800D3284: lhu         $t2, 0x2($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X2);
    // 0x800D3288: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x800D328C: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x800D3290: blez        $t2, L_800D332C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800D3294: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_800D332C;
    }
    // 0x800D3294: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D3298: lhu         $t3, 0x4($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X4);
    // 0x800D329C: lhu         $t4, 0x0($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X0);
    // 0x800D32A0: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800D32A4: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x800D32A8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800D32AC: andi        $v0, $t5, 0xFFFF
    ctx->r2 = ctx->r13 & 0XFFFF;
    // 0x800D32B0: sh          $t5, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r13;
    // 0x800D32B4: sra         $v1, $v0, 8
    ctx->r3 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800D32B8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800D32BC: beq         $v1, $zero, L_800D32FC
    if (ctx->r3 == 0) {
        // 0x800D32C0: sh          $t6, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r14;
            goto L_800D32FC;
    }
    // 0x800D32C0: sh          $t6, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r14;
    // 0x800D32C4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800D32C8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800D32CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D32D0: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x800D32D4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D32D8: addiu       $t8, $t8, 0x6EB0
    ctx->r24 = ADD32(ctx->r24, 0X6EB0);
    // 0x800D32DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D32E0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800D32E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D32E8: jal         0x800DB190
    // 0x800D32EC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_1;
    // 0x800D32EC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x800D32F0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D32F4: b           L_800D3364
    // 0x800D32F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D3364;
    // 0x800D32F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D32FC:
    // 0x800D32FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D3300: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x800D3304: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D3308: addiu       $t0, $t0, 0x6EB0
    ctx->r8 = ADD32(ctx->r8, 0X6EB0);
    // 0x800D330C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800D3310: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800D3314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3318: jal         0x800DB190
    // 0x800D331C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x800D331C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x800D3320: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D3324: b           L_800D3364
    // 0x800D3328: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D3364;
    // 0x800D3328: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D332C:
    // 0x800D332C: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x800D3330: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D3334: addiu       $t2, $t2, 0x6EB0
    ctx->r10 = ADD32(ctx->r10, 0X6EB0);
    // 0x800D3338: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800D333C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x800D3340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3344: jal         0x800DB190
    // 0x800D3348: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_3;
    // 0x800D3348: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_3:
    // 0x800D334C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D3350: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D3354: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800D3358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D335C: sb          $t3, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r11;
    // 0x800D3360: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
L_800D3364:
    // 0x800D3364: lhu         $t5, 0x2($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X2);
    // 0x800D3368: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800D336C: b           L_800D33DC
    // 0x800D3370: sh          $t6, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r14;
        goto L_800D33DC;
    // 0x800D3370: sh          $t6, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r14;
L_800D3374:
    // 0x800D3374: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800D3378: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800D337C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D3380: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x800D3384: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D3388: addiu       $t8, $t8, 0x6EB0
    ctx->r24 = ADD32(ctx->r24, 0X6EB0);
    // 0x800D338C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800D3390: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800D3394: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800D3398: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D339C: jal         0x800DB404
    // 0x800D33A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x800D33A0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_4:
    // 0x800D33A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800D33A8: bne         $v0, $zero, L_800D33CC
    if (ctx->r2 != 0) {
        // 0x800D33AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D33CC;
    }
    // 0x800D33AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D33B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D33B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D33B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800D33BC: jal         0x800DB190
    // 0x800D33C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_5;
    // 0x800D33C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_5:
    // 0x800D33C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800D33C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_800D33CC:
    // 0x800D33CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D33D0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800D33D4: sb          $t9, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r25;
    // 0x800D33D8: sh          $t0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r8;
L_800D33DC:
    // 0x800D33DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D33E0:
    // 0x800D33E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D33E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D33E8: jr          $ra
    // 0x800D33EC: nop

    return;
    // 0x800D33EC: nop

;}
RECOMP_FUNC void func_800D33F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D33F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D33F4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D33F8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D33FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3400: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D3404: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D3408: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D340C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D3410: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D3414: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D3418: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800D341C: lui         $s7, 0x800F
    ctx->r23 = S32(0X800F << 16);
    // 0x800D3420: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800D3424: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D3428: addiu       $fp, $fp, 0x4C30
    ctx->r30 = ADD32(ctx->r30, 0X4C30);
    // 0x800D342C: addiu       $s7, $s7, -0x43E0
    ctx->r23 = ADD32(ctx->r23, -0X43E0);
    // 0x800D3430: addiu       $s0, $s0, 0x7060
    ctx->r16 = ADD32(ctx->r16, 0X7060);
    // 0x800D3434: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D3438: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800D343C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800D3440: addiu       $s4, $zero, 0x81
    ctx->r20 = ADD32(0, 0X81);
    // 0x800D3444: addiu       $s5, $zero, 0x82
    ctx->r21 = ADD32(0, 0X82);
    // 0x800D3448: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_800D344C:
    // 0x800D344C: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x800D3450: beql        $v0, $zero, L_800D3560
    if (ctx->r2 == 0) {
        // 0x800D3454: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D3560;
    }
    goto skip_0;
    // 0x800D3454: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800D3458: beql        $v0, $s3, L_800D3484
    if (ctx->r2 == ctx->r19) {
        // 0x800D345C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D3484;
    }
    goto skip_1;
    // 0x800D345C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800D3460: beql        $v0, $s2, L_800D34A0
    if (ctx->r2 == ctx->r18) {
        // 0x800D3464: lbu         $t6, 0x8($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X8);
            goto L_800D34A0;
    }
    goto skip_2;
    // 0x800D3464: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    skip_2:
    // 0x800D3468: beql        $v0, $s4, L_800D3548
    if (ctx->r2 == ctx->r20) {
        // 0x800D346C: lbu         $t5, 0x9($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X9);
            goto L_800D3548;
    }
    goto skip_3;
    // 0x800D346C: lbu         $t5, 0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9);
    skip_3:
    // 0x800D3470: beql        $v0, $s5, L_800D3548
    if (ctx->r2 == ctx->r21) {
        // 0x800D3474: lbu         $t5, 0x9($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X9);
            goto L_800D3548;
    }
    goto skip_4;
    // 0x800D3474: lbu         $t5, 0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9);
    skip_4:
    // 0x800D3478: b           L_800D3560
    // 0x800D347C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800D3560;
    // 0x800D347C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D3480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D3484:
    // 0x800D3484: jal         0x800D31E8
    // 0x800D3488: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D31E8(rdram, ctx);
        goto after_0;
    // 0x800D3488: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800D348C: beql        $v0, $zero, L_800D3560
    if (ctx->r2 == 0) {
        // 0x800D3490: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D3560;
    }
    goto skip_5;
    // 0x800D3490: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x800D3494: b           L_800D355C
    // 0x800D3498: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
        goto L_800D355C;
    // 0x800D3498: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x800D349C: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
L_800D34A0:
    // 0x800D34A0: bnel        $t6, $zero, L_800D3524
    if (ctx->r14 != 0) {
        // 0x800D34A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D3524;
    }
    goto skip_6;
    // 0x800D34A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x800D34A8: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    // 0x800D34AC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800D34B0: divu        $zero, $t7, $t8
    lo = S32(U32(ctx->r15) / U32(ctx->r24)); hi = S32(U32(ctx->r15) % U32(ctx->r24));
    // 0x800D34B4: mfhi        $v0
    ctx->r2 = hi;
    // 0x800D34B8: bne         $t8, $zero, L_800D34C4
    if (ctx->r24 != 0) {
        // 0x800D34BC: nop
    
            goto L_800D34C4;
    }
    // 0x800D34BC: nop

    // 0x800D34C0: break       7
    do_break(2148349120);
L_800D34C4:
    // 0x800D34C4: bnel        $v0, $zero, L_800D3514
    if (ctx->r2 != 0) {
        // 0x800D34C8: lhu         $t3, 0x4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X4);
            goto L_800D3514;
    }
    goto skip_7;
    // 0x800D34C8: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    skip_7:
    // 0x800D34CC: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800D34D0: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800D34D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D34D8: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x800D34DC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D34E0: addiu       $t0, $t0, 0x6EB0
    ctx->r8 = ADD32(ctx->r8, 0X6EB0);
    // 0x800D34E4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800D34E8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x800D34EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D34F0: jal         0x800DB404
    // 0x800D34F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x800D34F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x800D34F8: bnel        $v0, $zero, L_800D3514
    if (ctx->r2 != 0) {
        // 0x800D34FC: lhu         $t3, 0x4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X4);
            goto L_800D3514;
    }
    goto skip_8;
    // 0x800D34FC: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
    skip_8:
    // 0x800D3500: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D3504: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800D3508: sb          $t1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r9;
    // 0x800D350C: sb          $t2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r10;
    // 0x800D3510: lhu         $t3, 0x4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X4);
L_800D3514:
    // 0x800D3514: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D3518: b           L_800D355C
    // 0x800D351C: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
        goto L_800D355C;
    // 0x800D351C: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x800D3520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D3524:
    // 0x800D3524: jal         0x800D31E8
    // 0x800D3528: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D31E8(rdram, ctx);
        goto after_2;
    // 0x800D3528: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D352C: beql        $v0, $zero, L_800D3560
    if (ctx->r2 == 0) {
        // 0x800D3530: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D3560;
    }
    goto skip_9;
    // 0x800D3530: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800D3534: sh          $s1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r17;
    // 0x800D3538: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x800D353C: b           L_800D355C
    // 0x800D3540: sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
        goto L_800D355C;
    // 0x800D3540: sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
    // 0x800D3544: lbu         $t5, 0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9);
L_800D3548:
    // 0x800D3548: bnel        $s2, $t5, L_800D3560
    if (ctx->r18 != ctx->r13) {
        // 0x800D354C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800D3560;
    }
    goto skip_10;
    // 0x800D354C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_10:
    // 0x800D3550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3554: jal         0x800D31E8
    // 0x800D3558: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D31E8(rdram, ctx);
        goto after_3;
    // 0x800D3558: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_800D355C:
    // 0x800D355C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D3560:
    // 0x800D3560: bne         $s1, $s6, L_800D344C
    if (ctx->r17 != ctx->r22) {
        // 0x800D3564: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_800D344C;
    }
    // 0x800D3564: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800D3568: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D356C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3570: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3574: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D3578: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D357C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D3580: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3584: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D3588: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D358C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D3590: jr          $ra
    // 0x800D3594: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800D3594: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800D3598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D359C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D35A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D35A4: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800D35A8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D35AC: addiu       $t7, $t7, 0x6EB0
    ctx->r15 = ADD32(ctx->r15, 0X6EB0);
    // 0x800D35B0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D35B4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D35B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D35BC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800D35C0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800D35C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D35C8: addiu       $a0, $a0, 0x4C30
    ctx->r4 = ADD32(ctx->r4, 0X4C30);
    // 0x800D35CC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800D35D0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800D35D4: jal         0x800DB404
    // 0x800D35D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x800D35D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x800D35DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D35E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D35E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D35E8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800D35EC: jal         0x800D95F0
    // 0x800D35F0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D35F0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_1:
    // 0x800D35F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D35F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D35FC: jr          $ra
    // 0x800D3600: nop

    return;
    // 0x800D3600: nop

;}
RECOMP_FUNC void func_800D3604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3604: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800D3608: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D360C: sb          $t6, 0x7066($at)
    MEM_B(0X7066, ctx->r1) = ctx->r14;
    // 0x800D3610: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800D3614: lbu         $t7, 0x7067($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7067);
    // 0x800D3618: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800D361C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D3620: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x800D3624: sb          $t8, 0x7067($at)
    MEM_B(0X7067, ctx->r1) = ctx->r24;
    // 0x800D3628: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D362C: sb          $t9, 0x7070($at)
    MEM_B(0X7070, ctx->r1) = ctx->r25;
    // 0x800D3630: lbu         $t0, 0x7071($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7071);
    // 0x800D3634: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800D3638: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800D363C: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x800D3640: sb          $t1, 0x7071($at)
    MEM_B(0X7071, ctx->r1) = ctx->r9;
    // 0x800D3644: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3648: sb          $t2, 0x707A($at)
    MEM_B(0X707A, ctx->r1) = ctx->r10;
    // 0x800D364C: lbu         $t3, 0x707B($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X707B);
    // 0x800D3650: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800D3654: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D3658: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x800D365C: sb          $t4, 0x707B($at)
    MEM_B(0X707B, ctx->r1) = ctx->r12;
    // 0x800D3660: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D3664: sb          $t5, 0x7084($at)
    MEM_B(0X7084, ctx->r1) = ctx->r13;
    // 0x800D3668: lbu         $t6, 0x7085($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7085);
    // 0x800D366C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3674: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800D3678: sb          $t7, 0x7085($at)
    MEM_B(0X7085, ctx->r1) = ctx->r15;
    // 0x800D367C: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800D3680: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D3684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3688: beq         $t8, $at, L_800D3698
    if (ctx->r24 == ctx->r1) {
        // 0x800D368C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800D3698;
    }
    // 0x800D368C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D3690: jal         0x800D95F0
    // 0x800D3694: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3694: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
L_800D3698:
    // 0x800D3698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D369C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D36A0: jr          $ra
    // 0x800D36A4: nop

    return;
    // 0x800D36A4: nop

;}
RECOMP_FUNC void func_800D36A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D36A8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D36AC: lbu         $t6, 0x7067($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7067);
    // 0x800D36B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D36B4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800D36B8: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800D36BC: sb          $t7, 0x7067($at)
    MEM_B(0X7067, ctx->r1) = ctx->r15;
    // 0x800D36C0: lbu         $t8, 0x7071($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7071);
    // 0x800D36C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D36C8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800D36CC: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x800D36D0: sb          $t9, 0x7071($at)
    MEM_B(0X7071, ctx->r1) = ctx->r25;
    // 0x800D36D4: lbu         $t0, 0x707B($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X707B);
    // 0x800D36D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D36DC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800D36E0: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x800D36E4: sb          $t1, 0x707B($at)
    MEM_B(0X707B, ctx->r1) = ctx->r9;
    // 0x800D36E8: lbu         $t2, 0x7085($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7085);
    // 0x800D36EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D36F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D36F4: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x800D36F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D36FC: sb          $t3, 0x7085($at)
    MEM_B(0X7085, ctx->r1) = ctx->r11;
    // 0x800D3700: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x800D3704: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D3708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D370C: beq         $t4, $at, L_800D371C
    if (ctx->r12 == ctx->r1) {
        // 0x800D3710: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800D371C;
    }
    // 0x800D3710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D3714: jal         0x800D95F0
    // 0x800D3718: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3718: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
L_800D371C:
    // 0x800D371C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3724: jr          $ra
    // 0x800D3728: nop

    return;
    // 0x800D3728: nop

;}
