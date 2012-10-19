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

void fatal(char* string, int line, char* file)
{
    printf("Program failed at line %d in file %s ", line, file);
    printf("%s",string);
    printf(" %s\n", strerror(errno));
    exit(1);
}

void run() {

    u8 nextop;
    u8 orig_pc;

    numCycles = 0;

    while (1) {

        orig_pc = REG_PC;
        // Get the next instruction
        u8 nextop = memory[REG_PC];
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
    ROMheader theHeader;
    memcpy((void*)&theHeader,(const void*)theRomFile+0x100,sizeof(ROMheader));
    init_memory_map(theRomFile,theHeader);


    //run();

    return 0;

}
