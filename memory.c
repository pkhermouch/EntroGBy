#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "ROM.h"

u8 memory[0xffff];

u8 current_ROM_bank;
u8** ROM_banks;
u8** RAM_banks;


void init_memory_map(u8* ROMbuffer, ROMheader theHeader)
{
    u8 temp;
    switch(theHeader.ROM_size)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        temp = pow(2,theHeader.ROM_size + 1);
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;
    case 0x52:
        temp = 72;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;
    case 0x53:
        temp = 80;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;
    case 0x54:
        temp = 96;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    }


    switch(theHeader.RAM_size)
    {
    case 0:
        RAM_banks = NULL;
        break;
    case 1:
    case 2:
        RAM_banks = malloc(sizeof(u8*));
        RAM_banks[0] = malloc(0x2000);
        break;
    case 3:
        RAM_banks = malloc(sizeof(u8*) * 4);
        for(int x = 0; x < 4; x++)
            RAM_banks[x] = malloc(0x2000);
        break;
    case 4:
        RAM_banks = malloc(sizeof(u8*) * 16);
        for(int x = 0; x < 16; x++)
            RAM_banks[x] = malloc(0x2000);
        break;
    }
    printf("ROM size: %d\n", theHeader.ROM_size);
    for(int x = 0; x < theHeader.ROM_size; x++)
    {
        memcpy(ROM_banks[x],ROMbuffer + x * 0x4000, 0x4000);
    }


    memcpy((void*)memory,(void*)ROMbuffer,0x4000);
    memory[0xFF05] = 0x00 ;
    memory[0xFF06] = 0x00 ;
    memory[0xFF07] = 0x00 ;
    memory[0xFF10] = 0x80 ;
    memory[0xFF11] = 0xBF ;
    memory[0xFF12] = 0xF3 ;
    memory[0xFF14] = 0xBF ;
    memory[0xFF16] = 0x3F ;
    memory[0xFF17] = 0x00 ;
    memory[0xFF19] = 0xBF ;
    memory[0xFF1A] = 0x7F ;
    memory[0xFF1B] = 0xFF ;
    memory[0xFF1C] = 0x9F ;
    memory[0xFF1E] = 0xBF ;
    memory[0xFF20] = 0xFF ;
    memory[0xFF21] = 0x00 ;
    memory[0xFF22] = 0x00 ;
    memory[0xFF23] = 0xBF ;
    memory[0xFF24] = 0x77 ;
    memory[0xFF25] = 0xF3 ;
    memory[0xFF26] = 0xF1 ;
    memory[0xFF40] = 0x91 ;
    memory[0xFF42] = 0x00 ;
    memory[0xFF43] = 0x00 ;
    memory[0xFF45] = 0x00 ;
    memory[0xFF47] = 0xFC ;
    memory[0xFF48] = 0xFF ;
    memory[0xFF49] = 0xFF ;
    memory[0xFF4A] = 0x00 ;
    memory[0xFF4B] = 0x00 ;
    memory[0xFFFF] = 0x00 ;
}

u8 read8(u16 address)
{

}

void write8(u16 address, u8 what)
{

}
