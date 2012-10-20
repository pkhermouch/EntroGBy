#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED
#include "ROM.h"

extern u8* memory;

void init_memory_map(u8* ROMbuffer, ROMheader theHeader);
u8 read8(u16 address);
void write8(u16 address, u8 what);

#endif // MEMORY_H_INCLUDED
