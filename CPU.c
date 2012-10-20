#include "common.h"
#include "memory.h"
#include "CPU.h"
reg16 AF, BC, DE, HL, SP, PC;

void setZflag(u8 whatever)
{
    if (whatever)
        REG_F &= (~Z_FLAG);
    else
        REG_F |= Z_FLAG;
}

void setNflag(u8 whatever)
{
    if (!whatever)
        REG_F &= (~N_FLAG);
    else
        REG_F |= N_FLAG;
}

void setHflag(u8 whatever)
{
    if (!whatever)
        REG_F &= (~H_FLAG);
    else
        REG_F |= H_FLAG;
}

void setCflag(u8 whatever)
{
    if (!whatever)
        REG_F &= (~C_FLAG);
    else
        REG_F |= C_FLAG;
}

// ADC A,s
void ADC8(u8* source)
{
    setHflag(((REG_A & 0xf)+(*source&0xf)) & 0x10);
    REG_A += *source + (REG_F & C_FLAG ? 1 : 0);
    setZflag(REG_A);
    setNflag(0);
    setCflag(REG_A  & 0x80);
}

// ADC HL,ss
void ADC16(u16 *source)
{
    REG_HL += *source;
    //flags
}

// ADD A,(HL)
// ADD A,n
// ADD A,r
void ADD8(u8* source)
{
    setHflag(((REG_A & 0xf)+(*source&0xf)) & 0x10);
    REG_A += *source;
    setZflag(REG_A);
    setNflag(0);
    setCflag(REG_A  & 0x80);
}

// ADD HL,ss
void ADD16(u16* source)
{
    REG_HL += *source;
}

// AND s
void AND(u8* source)
{
    REG_A &= *source;
    setZflag(REG_A);
    setHflag(1);
    setCflag(0);
    setNflag(0);
}

// BIT b,(HL)
void BIT(u8 bit, u8* source)
{
    setZflag(*source & (1 << bit));
    setHflag(1);
    setNflag(0);
}


// CALL cc,pq
//cc = 0 -> NZ
//cc = 1 -> Z
//cc = 2 -> NC
//cc = 3 -> C

void CALL(u8 cc, u16 address)
{
    switch(cc)
    {
    case 0:
        if(!(REG_F & Z_FLAG))
        {
            PUSH(&REG_PC);
            REG_PC = address;
        }
        break;
    case 1:
        if((REG_F & Z_FLAG))
        {
            PUSH(&REG_PC);
            REG_PC = address;
        }
        break;
    case 2:
        if(!(REG_F & C_FLAG))
        {
            PUSH(&REG_PC);
            REG_PC = address;
        }
        break;
    case 3:
        if((REG_F & C_FLAG))
        {
            PUSH(&REG_PC);
            REG_PC = address;
        }
        break;

    }
}

// CALL pq
void CALL16 (u16 address)
{
    PUSH(&REG_PC);
    REG_PC = address;
}

// CCF
void CCF()
{
    setCflag(~(REG_F & C_FLAG));
    setNflag(0);
    setHflag(0);
}

// CP s
void CP(u8* source)
{
    setZflag(REG_A - *source);
    setNflag(1);
    setHflag((REG_A&0xf) < (*source&0xf));
    setHflag((REG_A) < (*source));
}


void CPL()
{
    REG_A = ~REG_A;
    setNflag(1);
    setHflag(1);
}

void DAA()
{
    // sad face
}

void DEC8 (u8* source)
{
    setHflag((*source &0xf) == 0);
    (*source)--;
    setZflag(*source);
    setNflag(1);
}

void DEC16(u16* source)
{
    (*source)--;
}

// DEC IX
// DEC IY

void DI()
{

}

// DJNZ e

void EI()
{

}

// EX ...

void HALT()
{
    // ...
}

// IM 0
// IM 1
// IM 2
// IN ...

void INC8(u8* source)
{

    setHflag((*source & 0xf) == 0xf);
    (*source)++;
    setZflag(*source);
    setNflag(0);

}

void INC16(u16* source)
{

    (*source)++;

}

// IND
// INDR
// INI
// INIR

void JP(u8 cc, u16 address)
{
    switch(cc)
    {
    case 0:
        if(!(REG_F & Z_FLAG))
        {
            REG_PC = address;
        }
        break;
    case 1:
        if((REG_F & Z_FLAG))
        {
            REG_PC = address;
        }
        break;
    case 2:
    if(!(REG_F & C_FLAG))
        {20
            REG_PC = address;
        }
        break;
    case 3:
        if((REG_F & C_FLAG))
        {
            REG_PC = address;
        }
        break;

    }

}

void JP8(u16 address)
{
    REG_PC = address;
}

void JR(u8 cc, s8 offset)
{
    switch(cc)
    {
    case 0:
        if(!(REG_F & Z_FLAG))
        {
            REG_PC += offset;
        }
        break;
    case 1:
        if((REG_F & Z_FLAG))
        {
            REG_PC = offset;
        }
        break;
    case 2:
    if(!(REG_F & C_FLAG))
        {
            REG_PC = offset;
        }
        break;
    case 3:
        if((REG_F & C_FLAG))
        {
            REG_PC = offset;
        }
        break;

    }
}

void JR8 (s8 offset)
{
    REG_PC += offset;
}

void LD16(u16* dest, u16* source)
{
    *dest = *source;
}

void LD8(u8* dest, u8* source)
{
    *dest = *source;
}

// LD (C), A -- must add using reset vector or something. Need go way to call it

// block load instructions... whatever

void NOP()
{

}

void OR(u8* source)
{
    REG_A |= *source;
    setZflag(REG_A);
    setNflag(0);
    setCflag(0);
    setHflag(0);
}



// OUT ...

// NOTE this accepts a reg16*, not a u16*. Should change
void POP(u16* source)
{
    *source = memory[REG_SP++] << 8;
    *source |= memory[REG_SP++];
}

// same as above
void PUSH(u16* source)
{
    memory[REG_SP--] = *source & 0xff;
    memory[REG_SP--] = (*source >> 8);
}

void RES(u8 bit, u8* source)
{
    *source &= ~(1 << bit);
}

void RET()
{
    POP(&REG_PC);
}

void RET8(u8 cc)
{
    switch(cc)
    {
    case 0:
        if(!(REG_F & Z_FLAG))
        {
            RET();
        }
        break;
    case 1:
        if((REG_F & Z_FLAG))
        {
            RET();
        }
        break;
    case 2:
    if(!(REG_F & C_FLAG))
        {
            RET();
        }
        break;
    case 3:
        if((REG_F & C_FLAG))
        {
            RET();
        }
        break;

    }
}

// book says return from interrupt
// pandocs say return from subroutine then enable interrupts
void RETI()
{

}

// RETN

void RL(u8* source)
{
    u8 tmp = REG_F & C_FLAG ? 1 : 0;
    setCflag(*source & 0x80);
    *source = *source << 1;
    *source |= tmp;
    setZflag(*source);
    setHflag(0);
    setNflag(0);
}

void RLA()
{
    RL(&REG_A);
}


void RLC(u8* source)
{
    setCflag(*source & 0x80);
    *source <<= 1;
    *source |= (REG_F & C_FLAG ? 1 : 0);
    setZflag(*source);
    setHflag(0);
    setNflag(0);
}


void RLCA()
{
    RLC(&REG_A);
}


void RR(u8* source)
{
    u8 tmp = REG_F & C_FLAG ? 1 : 0;
    setCflag(*source & 0x1);
    *source >>= 1;
    *source |= (tmp << 7);
    setZflag(*source);
    setHflag(0);
    setNflag(0);

}

void RRA()
{
    RR(&REG_A);
}

void RRC(u8* source)
{
    setCflag(*source & 0x1);
    *source >>= 1;
    *source |= (REG_F & C_FLAG ? 0x80 : 0);
    setZflag(*source);
    setHflag(0);
    setNflag(0);

}

void RRCA()
{
    RRC(&REG_A);
}


void RST(u8 source)
{
    PUSH(&REG_PC);
    REG_PC = source;
}

void SBC8(u8* source)
{
    u8 tmp = ~(*source);
    ADC8(&tmp);
}

void SBC16(u16* source)
{
    u16 tmp = ~(*source);
    ADC16(&tmp);
}

void SCF()
{
    setCflag(1);
    setNflag(0);
    setHflag(0);
}

void SET(u8 bit, u8* source)
{
    *source |= (1 << bit);
}

void SLA(u8* source)
{
    setCflag(*source & 0x80);
    *source <<= 1;
    setZflag(*source);
    setNflag(0);
    setHflag(0);
}

void SRA(u8* source)
{
    u8 tmp = *source & 0x80;
    setCflag(*source & 0x1);
    *source >>= 1;
    *source |= tmp;
    setZflag(*source);
    setHflag(0);
    setNflag(0);
}

void SRL(u8* source)
{
    SRA(source);
    *source &= ~0x80;
    setZflag(*source);
}

void SUB(u8* source)
{
    u8 tmp = ~(*source);
    ADD8(&tmp);
}

void SWAP(u8* source)
{
    u8 tmp = *source & 0xf;
    *source <<= 4;
    *source |= tmp;
    setNflag(0);
    setHflag(0);
    setCflag(0);
    setZflag(*source);
}

void XOR(u8* source)
{
    REG_A ^= *source;
    setZflag(REG_A);
    setNflag(0);
    setCflag(0);
    setHflag(0);
}
