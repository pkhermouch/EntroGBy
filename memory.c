#include "common.h"

u8 memory[0xffff];

void init_memory_map(u8* ROMbuffer, u32 size)
{
    memcpy((void*)memory,(void*)ROMbuffer,sizeof(ROMbuffer) + 0x100);

}
