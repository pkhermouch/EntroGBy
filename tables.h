#ifndef TABLES_H_INCLUDED
#define TABLES_H_INCLUDED

#define _BIT(bit) ((bit >> 3) & 0x7)
#define _CC(bit) (_BIT(bit))
#define _REG(reg) (reg & 0x7)

u32 getCycles(u8);
u32 getLength(u8);

#endif // TABLES_H_INCLUDED
