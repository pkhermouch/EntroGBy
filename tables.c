#include "common.h"

#define NO_INST (-2)
#define PREFEX_CB (-1)

u32 getCycles(u8 opcode)
{
    if(cycles[opcode] > 0)
        return (u32)cycles[opcode];
    if(cycles[opcode] == -2)
        //holy shit this should never happen
        return 0;
    if(cycles[opcode] == -1)
        return prefixCycles[opcode];
}

u32 getLength(u8 opcode)
{
    if(lengths[opcode] > 0)
        return lengths[opcode];
    if(lengths[opcode] == -1)
        return 1 + prefixLengths[opcode];
    if(lengths[opcode] == -2)
        return -0xdeadbeef;
}

s32 cycles [256] =
{
    4,  12, 8,  8,  4,  4,  8,  4,  20, 8,  8,  8,  4,  4,  8,  4,
    4,  12, 8,  8,  4,  4,  8,  4,  12, 8,  8,  8,  4,  4,  8,  4,
    12, 12, 8,  8,  4,  4,  8,  4,  12, 8,  8,  8,  4,  4,  8,  4,
    12, 12, 8,  8,  12, 12, 12, 4,  12, 8,  8,  8,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    8,  8,  8,  8,  8,  8,  4,  8,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    4,  4,  4,  4,  4,  4,  8,  4,  4,  4,  4,  4,  4,  4,  8,  4,
    20, 12, 16, 16, 24, 16, 8,  16, 20, 16, 16, -1, 24, 24, 8,  16,
    20, 12, 16, -2, 24, 16, 8,  16, 20, 16, 16, -2, 24, -2, 8,  16,
    12, 12, 8,  -2, -2, 16, 8,  16, 16, 4,  16, -2, -2, -2, 8,  16,
    12, 12, 8,  4,  -2, 16, 8,  16, 12, 8,  16, 4,  -2, -2, 8,  16
};

s32 lengths [256] =
{
    1,3,1,1,1,1,2,1,3,1,1,1,1,1,2,1,
    2,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
    2,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
    2,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,3,3,3,1,2,1,1,1,3,-1,3,3,2,1,
    1,1,3,-2,3,1,2,1,1,1,3,-2,3,-2,2,1,
    2,1,2,-2,-2,1,2,1,2,1,3,-2,-2,-2,2,1,
    2,1,2,1,-2,1,2,1,2,1,3,1,-2,-2,2,1
};

u32 prefixCycles [256] =
{
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,16,8
};

u32 prefixLengths [256] =
{
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};