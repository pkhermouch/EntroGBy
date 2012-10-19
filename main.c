#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "common.h"
#include "ROM.h"
#include "memory.h"

#define ROM_NAME "/home/forrest/ROMfile.gbc"

void fatal(char* string, int line, char* file)
{
    printf("Program failed at line %d in file %s ", line, file);
    printf("%s",string);
    printf(" %s\n", strerror(errno));
    exit(1);
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

    for (int x = 0; x < 0x30; x++)
        printf("0x%x ",theHeader.nintendo[x]);

    return 0;

}
