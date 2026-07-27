| rom_start | rom_end | vram_start | vram_end | kind | loaded by / how discovered |
|---|---|---|---|---|---|
| 0x001000 | 0x02DB50 | 0x800C2400 | 0x800EEF50 | code+data | IPL3 (CIC-6102) |
| - | - | 0x800EEF50 | 0x8016ABF0 | bss | cleared by entry stub 0x800C2400 |
| 0x02DB50 | 0x02FC30 | 0x8016ABF0 | 0x8016D6F0 | data | func_800C3930, desc@0x800E8600 |
| 0x02FC30 | 0x034BE0 | 0x8016D6F0 | 0x801726A0 | code+data | func_800C38C8, desc@0x800EB4A0 |
| 0x034BE0 | 0x03D600 | 0x801726A0 | 0x8017B0C0 | data | func_800C3930, desc@0x800EB4C0 |
| 0x03D600 | 0x03DF80 | 0x8017B0C0 | 0x8017BA40 | code+data | func_800C38C8, desc@0x800EB4D0 |
| 0x03DF80 | 0x041630 | 0x8017BA40 | 0x8017F0F0 | data | func_800C3930, desc@0x800EB4F0 |
| 0x041630 | 0x041650 | 0x80000400 | 0x80000420 | data(staging buffer) | func_800C3968, desc@0x800EB500 |
| 0x041650 | 0x042E70 | 0x8017B0C0 | 0x8017C8E0 | code+data | func_800C38C8, desc@0x800EB50C |
| 0x042E70 | 0x04C7D0 | 0x8017C8E0 | 0x8018CB40 | data | func_800C3930, desc@0x800EB52C |
| 0x04C7D0 | 0x079B90 | 0x80000400 | 0x8002D7C0 | data(staging buffer) | func_800C3968, desc@0x800EB53C |
| 0x079B90 | 0x0BA450 | 0x8017B0C0 | 0x801DC320 | data | func_800C3930, desc@0x800EB664 |
| 0x0BA450 | 0x0CCB00 | 0x801DC320 | 0x801EE9D0 | code+data | func_800C38C8, desc@0x800EB644 |
| 0x0CCB00 | 0x0EC0B0 | 0x80000400 | 0x8001F9B0 | data(staging buffer) | func_800C3968, desc@0x800EB674 |
| 0x0EC0B0 | 0x0EF7C0 | 0x80000400 | 0x80003B10 | data(staging buffer) | func_800C3968, desc@0x800EB680 |
| 0x0EF7C0 | 0x0F3A80 | 0x8017B0C0 | 0x8017F380 | code+data | func_800C38C8, desc@0x800EB548 |
| 0x0F3A80 | 0x0F3F00 | 0x8017F380 | 0x8017F800 | data | func_800C3930, desc@0x800EB568 |
| 0x0F3F00 | 0x0F4810 | 0x80000400 | 0x80000D10 | data(staging buffer) | func_800C3968, desc@0x800EB578 |
| 0x0F4810 | 0x0F5440 | 0x8017B0C0 | 0x8017BCF0 | code+data | func_800C38C8, desc@0x800EB584 |
| 0x0F5440 | 0x0FDFF0 | 0x8017BCF0 | 0x8018B020 | data | func_800C3930, desc@0x800EB5A4 |
| 0x0FDFF0 | 0x10ACC0 | 0x80000400 | 0x8000D0D0 | data(staging buffer) | func_800C3968, desc@0x800EB5B4 |
| 0x10ACC0 | 0x111CC0 | 0x80000400 | 0x80007400 | data(staging buffer) | func_800C3968, desc@0x800EB5C0 |
| 0x111CC0 | 0x114EE0 | 0x8017B0C0 | 0x8017E2E0 | code+data | func_800C38C8, desc@0x800EB5CC |
| 0x114EE0 | 0x1150E0 | 0x8017E2E0 | 0x8017EF00 | data | func_800C3930, desc@0x800EB5EC |
| 0x1150E0 | 0x1199D0 | 0x80000400 | 0x80004CF0 | data(staging buffer) | func_800C3968, desc@0x800EB5FC |
| 0x1199D0 | 0x11CA40 | 0x8017B0C0 | 0x8017E130 | code+data | func_800C38C8, desc@0x800EB608 |
| 0x11CA40 | 0x12C1A0 | 0x8017E130 | 0x8018DBF0 | data | func_800C3930, desc@0x800EB628 |
| 0x12C1A0 | 0x12C2F0 | 0x80000400 | 0x80000550 | data(staging buffer) | func_800C3968, desc@0x800EB638 |
| 0x12C2F0 | 0x12E8F0 | 0x8017B0C0 | 0x8017D6C0 | code+data | func_800C38C8, desc@0x800EB68C |
| 0x12E8F0 | 0x12FBE0 | 0x8017D6C0 | 0x80184E30 | data | func_800C3930, desc@0x800EB6AC |
| 0x12FBE0 | 0x1501A0 | 0x80000400 | 0x800209C0 | data(staging buffer) | func_800C3968, desc@0x800EB6BC |
| 0x1501A0 | 0x183700 | 0x8016D6F0 | 0x801A0C50 | code+data | func_800C38C8, desc@0x800EB6C8 |
| 0x183700 | 0x199640 | 0x801A0C50 | 0x801D21F0 | data | func_800C3930, desc@0x800EB6E8 |
| 0x199640 | 0x1B6400 | 0x80000400 | 0x8001D1C0 | data(staging buffer) | func_800C3968, desc@0x800EB6F8 |
| 0x1B6400 | 0x1B66F0 | 0x80000400 | 0x800006F0 | data(staging buffer) | func_800C3968, desc@0x800EB704 |
| 0x1B66F0 | 0x1E6420 | 0x801D21F0 | 0x80201F20 | code+data | func_800C38C8, desc@0x800EB710 |
| 0x1E6420 | 0x22C680 | 0x80201F20 | 0x80248180 | data | func_800C3930, desc@0x800EB730 |
| 0x22C680 | 0x250360 | 0x80000400 | 0x800240E0 | data(staging buffer) | func_800C3968, desc@0x800EB740 |
| 0x250360 | 0x250D50 | 0x800BE400 | 0x800BEDF0 | data(staging buffer) | func_800C3968, desc@0x800EB74C |
| 0x250D50 | 0x255660 | 0x80020400 | 0x80024D10 | data(staging buffer) | func_800C3968, desc@0x800EB758 |
| 0x255660 | 0x2A75B0 | 0x801D21F0 | 0x80224140 | code+data | func_800C38C8, desc@0x800EB764 |
| 0x2A75B0 | 0x30B090 | 0x80224140 | 0x80287C20 | data | func_800C3930, desc@0x800EB784 |
| 0x30B090 | 0x333FF0 | 0x80000400 | 0x80029360 | data(staging buffer) | func_800C3968, desc@0x800EB794 |
| 0x333FF0 | 0x334A90 | 0x800BE400 | 0x800BEEA0 | data(staging buffer) | func_800C3968, desc@0x800EB7A0 |
| 0x334A90 | 0x336A10 | 0x80020400 | 0x80022380 | data(staging buffer) | func_800C3968, desc@0x800EB7AC |
| 0x336A10 | 0x345300 | 0x80224140 | 0x80232A30 | data | func_800C3930, desc@0x800EB7B8 |
| 0x345300 | 0x34B590 | 0x80000400 | 0x80006690 | data(staging buffer) | func_800C3968, desc@0x800EB7C8 |
| 0x34B590 | 0x378CC0 | 0x801D21F0 | 0x801FF920 | code+data | func_800C38C8, desc@0x800EB7D4 |
| 0x378CC0 | 0x3C3DD0 | 0x801FF920 | 0x8024FBF0 | data | func_800C3930, desc@0x800EB7F4 |
| 0x3C3DD0 | 0x3EAF80 | 0x80000400 | 0x800275B0 | data(staging buffer) | func_800C3968, desc@0x800EB804 |
| 0x3EAF80 | 0x3EBA30 | 0x800BE400 | 0x800BEEB0 | data(staging buffer) | func_800C3968, desc@0x800EB810 |
| 0x3EBA30 | 0x3EFDD0 | 0x80020400 | 0x800247A0 | data(staging buffer) | func_800C3968, desc@0x800EB81C |
| 0x3EFDD0 | 0x42B310 | 0x801D21F0 | 0x8020D730 | code+data | func_800C38C8, desc@0x800EB828 |
| 0x42B310 | 0x473E60 | 0x8020D730 | 0x80256280 | data | func_800C3930, desc@0x800EB848 |
| 0x473E60 | 0x494E50 | 0x80000400 | 0x800213F0 | data(staging buffer) | func_800C3968, desc@0x800EB858 |
| 0x494E50 | 0x495540 | 0x800BE400 | 0x800BEAF0 | data(staging buffer) | func_800C3968, desc@0x800EB864 |
| 0x495540 | 0x497140 | 0x80020400 | 0x80022000 | data(staging buffer) | func_800C3968, desc@0x800EB870 |
| 0x497140 | 0x4A30E0 | 0x801D21F0 | 0x801DE190 | code+data | func_800C38C8, desc@0x800EB87C |
| 0x4A30E0 | 0x4C0300 | 0x801DE190 | 0x801FB3B0 | data | func_800C3930, desc@0x800EB89C |
| 0x4C0300 | 0x4D5E10 | 0x80000400 | 0x80015F10 | data(staging buffer) | func_800C3968, desc@0x800EB8AC |
| 0x4D5E10 | 0x4D5ED0 | 0x800BE400 | 0x800BE4C0 | data(staging buffer) | func_800C3968, desc@0x800EB8B8 |
| 0x4D5ED0 | 0x4D5FC0 | 0x80020400 | 0x800204F0 | data(staging buffer) | func_800C3968, desc@0x800EB8C4 |
| 0x4D5FC0 | 0x4DC330 | 0x801DC320 | 0x801E2690 | code+data | func_800C38C8, desc@0x800EB8D0 |
| 0x4DC330 | 0x4DC6D0 | 0x800BE400 | 0x800BE7A0 | data(staging buffer) | func_800C3968, desc@0x800EB8F0 |
| 0x4DC6D0 | 0x514B40 | 0x801D21F0 | 0x8020A660 | code+data | func_800C38C8, desc@0x800EB8FC |
| 0x514B40 | 0x5571B0 | 0x8020A660 | 0x8024CCD0 | data | func_800C3930, desc@0x800EB91C |
| 0x5571B0 | 0x580480 | 0x8024CCD0 | 0x80275FA0 | data | func_800C3930, desc@0x800EB92C |
| 0x580480 | 0x5A3930 | 0x80000400 | 0x800238B0 | data(staging buffer) | func_800C3968, desc@0x800EB93C |
| 0x5A3930 | 0x5B3F40 | 0x80000400 | 0x80010A10 | data(staging buffer) | func_800C3968, desc@0x800EB948 |
| 0x5B3F40 | 0x5B4520 | 0x800BE400 | 0x800BE9E0 | data(staging buffer) | func_800C3968, desc@0x800EB954 |
| 0x5B4520 | 0x5B6F20 | 0x80020400 | 0x80022E00 | data(staging buffer) | func_800C3968, desc@0x800EB960 |
| 0x5B6F20 | 0x5BF280 | (heap) | - | data | func_800CE290 (malloc + func_800D1D10) @0x800CB4C4 |
| 0x5BF280 | 0x78C860 | (heap) | - | data | streamed by func_800CD8C0 -> osEPiStartDma(0x800D8A00) |
| 0x78C860 | 0x7C1AF0 | (heap) | - | data | func_800CD800 @0x800C801C, table at 0x800EAB50, desc@0x800EAB50 |
| 0x7C1AF0 | 0x800000 | (heap) | - | pad | (none) |