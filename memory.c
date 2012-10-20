#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "ROM.h"

u8 memory[0xffff];

u8 current_ROM_bank, current_EXRAM_bank, current_CHAR_bank, current_INRAM_bank;
u8 **ROM_banks, **EXRAM_banks, **CHAR_banks, **INRAM_banks;

void init_memory_map(u8* ROMbuffer, ROMheader theHeader)
{
    u8 temp;
    switch(theHeader.ROM_size)
    {
    case 0:
        temp = 2;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 1:
        temp = 4;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 2:
        temp = 8;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 3:
        temp = 16;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 4:
        temp = 32;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 5:
        temp = 64;
        ROM_banks = (u8**)malloc( temp* sizeof(u8*));
        for(int x = 0; x < temp; x++)
            ROM_banks[x] = (u8*)malloc(0x4000);
        break;

    case 6:
        temp = 128;
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
        EXRAM_banks = NULL;
        break;
    case 1:
    case 2:
        EXRAM_banks = malloc(sizeof(u8*));
        EXRAM_banks[0] = malloc(0x2000);
        break;
    case 3:
        EXRAM_banks = malloc(sizeof(u8*) * 4);
        for(int x = 0; x < 4; x++)
            EXRAM_banks[x] = malloc(0x2000);
        break;
    case 4:
        EXRAM_banks = malloc(sizeof(u8*) * 16);
        for(int x = 0; x < 16; x++)
            EXRAM_banks[x] = malloc(0x2000);
        break;
    }
    printf("ROM size: %d\n", theHeader.ROM_size);
    for(int x = 0; x < theHeader.ROM_size; x++)
    {
        memcpy(ROM_banks[x],ROMbuffer + x * 0x4000, 0x4000);
    }

    CHAR_banks = (u8 **) malloc(sizeof(u8 *) * 2);
    CHAR_banks[0] = (u8 *) malloc(sizeof(u8) * 0x2000);
    CHAR_banks[1] = (u8 *) malloc(sizeof(u8) * 0x2000);

    INRAM_banks = (u8 **) malloc(8 * sizeof(u8 *));
    for (int x = 0; x < 8; x++) {
        INRAM_banks[x] = (u8 *) malloc(0x1000);
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
    if (address < 0x4000) {
        return ROM_banks[0][address];
    }
    if (address < 0x8000) {
        return ROM_banks[current_ROM_bank][address - 0x4000];
    }
    if (address < 0xA000) {
        return CHAR_banks[current_CHAR_bank][address - 0x8000];
    }
    if (address < 0xC000) {
        return EXRAM_banks[current_EXRAM_bank][address - 0xA000];
    }
    if (address < 0xD000) {
        return INRAM_banks[0][address - 0xC000];
    }
    if (address < 0xE000) {
        return INRAM_banks[current_INRAM_bank][address - 0xD000];
    }
    if (address < 0xFE00) {
        printf("Attempt to access prohibited RAM: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    else if (address >= 0xFEA0 && address < 0xFF00) {
        printf("Attempt to access prohibited RAM 2: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    return memory[address];
    
}

void write8(u16 address, u8 what)
{

}
