#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "ROM.h"
#include "CPU.h"

u8 memory[0xffff];

u8 current_ROM_bank, current_EXRAM_bank, current_VIDEO_bank, current_INRAM_bank;
u8 **ROM_banks, **EXRAM_banks, **VIDEO_banks, **INRAM_banks;
u16 OBJ_ON, OBJ_BLOCK_COMPOSITION, BG_CODE_AREA, BG_CHAR_DATA, WINDOWING_ON, WINDOW_CODE_AREA, LCD_ON;
extern ROMheader theHeader;

u8 read8(u16 address);

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

    VIDEO_banks = (u8 **) malloc(sizeof(u8 *) * 2);
    VIDEO_banks[0] = (u8 *) malloc(sizeof(u8) * 0x4000);
    VIDEO_banks[1] = (u8 *) malloc(sizeof(u8) * 0x4000);

    // Set up video RAM parameters
    u8 lcd_flags = read8(REG_LCDC);
    OBJ_ON = lcd_flags & 0x2 ? 1 : 0;
    OBJ_BLOCK_COMPOSITION = lcd_flags & 0x4 ? 0x10 : 0x8;
    BG_CODE_AREA = lcd_flags & 0x8 ? 0x9c00 : 0x9800;
    BG_CHAR_DATA = lcd_flags & 0x10 ? 0x8000 : 0x8800;
    WINDOWING_ON = lcd_flags & 0x20 ? 1 : 0;
    WINDOW_CODE_AREA = lcd_flags & 0x40 ? 0x9c00 : 0x9800;
    LCD_ON = lcd_flags & 0x80 ? 1 : 0;

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
        return VIDEO_banks[current_VIDEO_bank][address - 0x8000];
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

u8 MBCregisters[4];
u8 enable_external_EXRAM;

void write8(u16 address, u8 what)
{
    if(address < 0x8000)
    {
        //MBC1
        if(theHeader.cart_type >= 1 && theHeader.cart_type <= 3)
        {
            if (address < 0x2000)
                enable_external_EXRAM = what == 0xa ? 1 : 0;
            if (address < 0x4000)
            {
                MBCregisters[1] = what;
                current_ROM_bank = MBCregisters[1] & 0x1f;
            }
            if (address < 0x6000)
            {
                MBCregisters[2] = what;
                if(MBCregisters[3] == 0)
                    current_ROM_bank |= (MBCregisters[2] & 0x3) << 5;
                else if(MBCregisters[3] == 1)
                    current_EXRAM_bank = MBCregisters[2];
            }
            if(address < 0x8000)
            {
                MBCregisters[3] = what;
            }
        }

        //MBC2
        else if(theHeader.cart_type >= 5 && theHeader.cart_type <= 6)
        {
            if (address < 0x0fff)
                enable_external_EXRAM = what == 0xa ? 1 : 0;
            else if (address >= 0x2100 && address <= 0x21ff)
            {
                MBCregisters[1] = what;
                current_ROM_bank = what;
            }
        }

        else if(theHeader.cart_type >= 0xf && theHeader.cart_type <= 0x13)
        {
            if(address < 0x2000)
                enable_external_EXRAM = what == 0xa ? 1 : 0;
            else if(address < 0x4000)
            {
                MBCregisters[1] = what;
                current_ROM_bank = what;
            }
            else if(address < 0x6000)
            {
                MBCregisters[2] = what;
                if (MBCregisters[2] <=3)
                    current_EXRAM_bank = what;
                else if(MBCregisters[2] >=8 && MBCregisters[2] <= 0xc)
                {

                }
            }
            if(address < 0x8000)
            {
                MBCregisters[3] = what;
                //do timer things
            }

        }
        else if(theHeader.cart_type >= 0x19 && theHeader.cart_type <= 0x1e)
        {
            if(address < 0x2000)
                enable_external_EXRAM = what == 0xa ? 1 : 0;
            else if(address < 0x3000)
                MBCregisters[1] = what;
            else if(address < 0x4000)
                MBCregisters[2] = what & 1;
            else if(address < 0x6000)
                MBCregisters[3] = what & 0xf;
            current_ROM_bank = MBCregisters[1] | MBCregisters[2] << 8;
            current_EXRAM_bank = MBCregisters[3];
        }
    }

    if (address >= 0xa000 && address < 0xc000)
        EXRAM_banks[current_EXRAM_bank][address - 0xa000] = what;
    if(address >= 0xc000 && address < 0xe000)
        INRAM_banks[current_INRAM_bank][address - 0xc000] = what;
    if(address >= 0xe000 && address <=0xfdff)
    {
        printf("you fucked up in writing to memory\n");
        exit(1);
    }
    memory[address] = what;
}

u8* read8address(u16 address)
{
    if (address < 0x4000) {
        return &ROM_banks[0][address];
    }
    if (address < 0x8000) {
        return &ROM_banks[current_ROM_bank][address - 0x4000];
    }
    if (address < 0xA000) {
        return &VIDEO_banks[current_VIDEO_bank][address - 0x8000];
    }
    if (address < 0xC000) {
        return &EXRAM_banks[current_EXRAM_bank][address - 0xA000];
    }
    if (address < 0xD000) {
        return &INRAM_banks[0][address - 0xC000];
    }
    if (address < 0xE000) {
        return &INRAM_banks[current_INRAM_bank][address - 0xD000];
    }
    if (address < 0xFE00) {
        printf("Attempt to access prohibited RAM: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    else if (address >= 0xFEA0 && address < 0xFF00) {
        printf("Attempt to access prohibited RAM 2: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    return &memory[address];
}

u16* read16address(u16 address)
{
    if (address < 0x4000) {
        return (u16*)&ROM_banks[0][address];
    }
    if (address < 0x8000) {
        return (u16*)&ROM_banks[current_ROM_bank][address - 0x4000];
    }
    if (address < 0xA000) {
        return (u16*)&VIDEO_banks[current_VIDEO_bank][address - 0x8000];
    }
    if (address < 0xC000) {
        return (u16*)&EXRAM_banks[current_EXRAM_bank][address - 0xA000];
    }
    if (address < 0xD000) {
        return (u16*)&INRAM_banks[0][address - 0xC000];
    }
    if (address < 0xE000) {
        return (u16*)&INRAM_banks[current_INRAM_bank][address - 0xD000];
    }
    if (address < 0xFE00) {
        printf("Attempt to access prohibited RAM: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    else if (address >= 0xFEA0 && address < 0xFF00) {
        printf("Attempt to access prohibited RAM 2: 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
    return (u16*)&memory[address];
}
