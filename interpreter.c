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
    return (memory + PC.word + 1);
}

u16* getUnsignedImmediate16()
{
    return (u16*)(memory + PC.word + 1);
}

u8* getUnsignedIndirectAddress(u16 address)
{
    return (u8*)(memory + address);
}

s8* getSignedImmediate8()
{
    return (s8*)(memory + PC.word + 1);
}

s16* getSignedImmediate16()
{
    return (s16*)(memory + PC.word + 1);
}

s8* getSignedIndirectAddress(u16 address)
{
    return (s8*)(memory + address);
}

void executeInstruction(u8 opcode)
{
    //cycles_to_add = cycles[opcode];
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

