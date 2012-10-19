#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

extern reg16 AF, BC, DE, HL, SP, PC;

void setZflag(u8 whatever);

void setNflag(u8 whatever);

void setHflag(u8 whatever);

void setCflag(u8 whatever);

void ADC8(u8* source);
void ADC16(u16 *source);
void ADD8(u8* source);
void ADD16(u16* source);
void AND(u8* source);
void BIT(u8 bit, u8* source);
void CALL(u8 cc, u16 address);
void CALL16 (u16 address);
void CCF();
void CP(u8* source);
void CPL();
void DAA();

void DEC8 (u8* source);

void DEC16(u16* source);
void DI();
void EI();
void HALT();
void INC8(u8* source);
void INC16(u16* source);
void JP(u8 cc, u16 address);
void JP8(u16 address);

void JR(u8 cc, s8 offset);

void JR8(s8 offset);

void LD16(u16* dest, u16* source);

void LD8(u8* dest, u8* source);

void NOP();

void OR(u8* source);
void POP(u16* source);
// same as above
void PUSH(u16* source);

void RES(u8 bit, u8* source);
void RET();

void RET8(u8 cc);
void RETI();

void RL(u8* source);

void RLA();


void RLC(u8* source);


void RLCA();


void RR(u8* source);

void RRA();

void RRC(u8* source);

void RRCA();

void RST(u8 source);

void SBC8(u8* source);

void SBC16(u16* source);

void SCF();

void SET(u8 bit, u8* source);

void SLA(u8* source);

void SRA(u8* source);

void SRL(u8* source);

void SUB(u8* source);

void SWAP(u8* source);

void XOR(u8* source);


#endif // CPU_H_INCLUDED
