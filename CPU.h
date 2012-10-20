#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#define INTERRUPTS_ENABLED ((u16) 0xffff)
#define INTERRUPT_FLAG ((u16) 0xff0f)
#define INTERRUPT_VBLANK_BIT 0x1
#define INTERRUPT_LCD_BIT 0x2
#define INTERRUPT_TIMER_BIT 0x4
#define INTERRUPT_JOYPAD_BIT 0x8
#define INTERRUPT_VBLANK_ROUTINE ((u16) 0x40)
#define INTERRUPT_LCD_ROUTINE ((u16) 0x48)
#define INTERRUPT_TIMER_ROUTINE ((u16) 0x50)
#define INTERRUPT_JOYPAD_ROUTINE ((u16) 0x60)

#define REG_P1 ((u16) 0xff00)
#define REG_DIV ((u16) 0xff04)
#define REG_TIMA ((u16) 0xff05)
#define REG_TMA ((u16) 0xff06)
#define REG_TAC ((u16) 0xff07)
#define REG_LCDC ((u16) 0xff40)
#define REG_STAT ((u16) 0xff41)
#define REG_SCY ((u16) 0xff42)
#define REG_SCX ((u16) 0xff43)
#define REG_LY ((u16) 0xff44)
#define REG_LYC ((u16) 0xff45)
#define REG_DMA ((u16) 0xff46)
#define REG_BGP ((u16) 0xff47)
#define REG_OBP0 ((u16) 0xff48)
#define REG_OBP1 ((u16) 0xff49)
#define REG_WY ((u16) 0xff4a)
#define REG_WX ((u16) 0xff4b)
#define REG_VBK ((u16) 0xff4f)

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
