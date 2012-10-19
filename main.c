#include <stdio.h>
#include <stdlib.h>

#include "common.h"


int main()
{
    FILE* fp = fopen("/home/forrest/theRom.gbc");
    u8* theRomFile;

    fseek (fp , 0 , SEEK_END);
    lSize = ftell (fp);
    rewind (fp);

    theRomFile = (u8*) malloc(lSize);
    fread(theRomFile,1,lSize,fp);

}
