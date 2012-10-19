#ifndef TABLES_H_INCLUDED
#define TABLES_H_INCLUDED

extern u32* cycles;

extern u32* lengths;

extern u32* prefixCycles;

extern u32* prefixLengths;


#define _BIT(bit) ((bit >> 3) & 0x7)
#define _CC(bit) (_BIT(bit))
#define _REG(reg) (reg & 0x7)

#endif // TABLES_H_INCLUDED
