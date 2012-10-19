#ifndef ROM_H_INCLUDED
#define ROM_H_INCLUDED

#include "common.h"

typedef struct _ROMheader
{

    u8 start_address[4];
    u8 nintendo[0x30];
    u8 name[0xf];
    u8 is_CGB;
    u8 License_hi;
    u8 License_lo;
    u8 GB_SGB_indicator;
    u8 cart_type;
    u8 ROM_size;
    u8 RAM_size;
    u8 dest;
    u8 license_old;
    u8 mask_ROM;
    u8 compliment;
    u8 checksum[2];

}ROMheader;

#endif // ROM_H_INCLUDED
