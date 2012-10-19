#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED




void executeInstruction(u8 opcode);
u8* getUnsignedImmediate8();
u16* getUnsignedImmediate16();
u8* getUnsignedIndirectAddress(u16 address);
s8* getSignedImmediate8();
s16* getSignedImmediate16();
s8* getSignedIndirectAddress(u16 address);




#endif // INTERPRETER_H_INCLUDED
