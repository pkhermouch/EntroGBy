#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

union reg16
{
    u16 word;
    struct
    {
        u8 lo,hi;
    };
};

#define C_FLAG 0x10
#define H_FLAG 0x20
#define N_FLAG 0x40
#define Z_FLAG 0x80

#define REG_A (AF.hi)
#define REG_B (BC.hi)
#define REG_C (BC.lo)
#define REG_D (DE.hi)
#define REG_E (DE.lo)
#define REG_F (AF.lo)
#define REG_H (HL.hi)
#define REG_L (HL.lo)


#define REG_AF (AF.word)
#define REG_BC (BC.word)
#define REG_DE (DE.word)
#define REG_SP (SP.word)
#define REG_HL (HL.word)
#define REG_PC (PC.word)

#endif // COMMON_H_INCLUDED
