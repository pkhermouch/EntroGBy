#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "CPU.h"
#include "memory.h"
#include "tables.h"

// TODO: make immediate values pass by value.
// passing by pointer doesn't really make sense


u8* memory;

void doCBprefix(u8 opcode);

void INVALID(u8 opcode)
{
    printf("oh noes! opcode %x at PC: %x",opcode, PC.word);
}


u8* getUnsignedImmediate8()
{
    return read8address(REG_PC + 1);
}

u16* getUnsignedImmediate16()
{
    return read16address(REG_PC + 1);
}

u8* getUnsignedIndirectAddress(u16 address)
{
    return read8address(address);
}

s8* getSignedImmediate8()
{
    return (s8*)read8address(REG_PC + 1);
}

s16* getSignedImmediate16()
{
    return (s16*)read16address(REG_PC + 1);
}

s8* getSignedIndirectAddress(u16 address)
{
    return (s8*)read16address(address);
}

void executeInstruction(u8 opcode)
{
    //cycles_to_add = cycles[opcode];

    printf("0x%04X: 0x%02X ", REG_PC,opcode);

    switch (opcode)
    {
        #include "opcode_switch.h"
    }
}

void doCBprefix(u8 opcode)
{
    switch(opcode)
    {
        #include "cb_switch.h"
    }
}

