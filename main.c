#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "common.h"
#include "ROM.h"
#include "memory.h"
#include "interpreter.h"
#include "CPU.h"
#include "tables.h"

#define ROM_NAME "ROMfile.gbc"

u32 numCycles;
ROMheader theHeader;

void fatal(char* string, int line, char* file)
{
    printf("Program failed at line %d in file %s ", line, file);
    printf("%s",string);
    printf(" %s\n", strerror(errno));
    exit(1);
}

void run() {

    u8 nextop;
    u16 orig_pc;

    numCycles = 0;
    int counter = 0;
    while (counter++ < 10000) {

        orig_pc = REG_PC;
        // Get the next instruction
        u8 nextop = read8(REG_PC);
        printf("nextop 0x%02x instruction length %u cycles %u\n", nextop, getLength(nextop), getCycles(nextop));
        // Run it
        executeInstruction(nextop);
        // IF REG_PC didn't change, increment it by the instruction's length
        if (REG_PC == orig_pc) {
            REG_PC += getLength(nextop);
        }
        // Increment how many cycles we've added
        numCycles += getCycles(nextop);
        // Graphics stuff

        // If there was an interrupt, check if we should
        // respond to it. If so, respond
        u8 int_flag = read8(INTERRUPT_FLAG);
        if (int_flag) {
            // If handling of the appropriate interrupt is enabled
            if (read8(INTERRUPTS_ENABLED) & int_flag) {
                write8(INTERRUPT_FLAG, 0);
                // Store where REG_PC was pointing before the interrupt
                u16 old_pc = REG_PC;
                PUSH(&REG_PC);
                if (int_flag & INTERRUPT_VBLANK_BIT) {
                    REG_PC = INTERRUPT_VBLANK_ROUTINE;
                }
                else if (int_flag & INTERRUPT_LCD_BIT) {
                    REG_PC = INTERRUPT_LCD_ROUTINE;
                }
                else if (int_flag & INTERRUPT_TIMER_BIT) {
                    REG_PC = INTERRUPT_TIMER_ROUTINE;
                }
                else if (int_flag & INTERRUPT_JOYPAD_BIT) {
                    REG_PC = INTERRUPT_JOYPAD_ROUTINE;
                }
                // Run the interrupt routine until we return to
                // the original place in the program
                while (REG_PC != old_pc) {
                    u16 orig_pc2 = REG_PC;
                    u8 nextop2 = read8(REG_PC);
                    executeInstruction(nextop2);
                    if (REG_PC == orig_pc2) {
                        REG_PC += getLength(nextop2);
                    }
                    numCycles += getCycles(nextop2);
                }
                // If we interrupted while HALT was called,
                // we want to proceed to the next instruction
                if (read8(REG_PC) == 0x76) {
                    REG_PC++;
                }
            }
        }
        if (counter == 8000) {
            write8(0xff44, 0x91);
        }
    }

}

int main()
{

    FILE* fp = fopen(ROM_NAME,"r");
    if (fp == NULL) {
        fatal("Failed to open the ROM file",__LINE__,__FILE__);
    }
    u8* theRomFile;

    if (fseek (fp , 0 , SEEK_END) == -1) {
        fatal("Fseek() failed",__LINE__,__FILE__);
    }
    u32 lSize;
    if ((lSize = ftell (fp)) == -1) {
        fatal("ftell() failed",__LINE__,__FILE__);
    }
    rewind(fp);
    assert(lSize > 0);
    theRomFile = (u8*) malloc(lSize);
    assert(theRomFile != NULL);
    fread(theRomFile,1,lSize,fp);

    memcpy((void*)&theHeader,(const void*)theRomFile+0x100,sizeof(ROMheader));
    init_memory_map(theRomFile,theHeader);
    printf("Memory config value: %u\n", theHeader.cart_type);

    REG_PC = 0x100;
    REG_AF = 0x01B0;
    REG_BC = 0x0013;
    REG_DE = 0x00D8;
    REG_HL = 0x014D;
    REG_SP = 0xFFFE;

    run();

    return 0;

}
