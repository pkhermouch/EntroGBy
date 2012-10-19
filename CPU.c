#include "common.h"

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
void ADC(u8* source)
{
    setHflag(((REG_A & 0xf)+(*source&0xf)) & 0x10);
    REG_A += *source + (REG_F & C_FLAG ? 1 : 0);
    setZflag(REG_A);
    setNflag(0);
    setCflag(REG_A  & 0x80);
}

// ADC HL,ss
void ADC(u16 *source)
{
    HL += *source;
    //flags
}

// ADD A,(HL)
// ADD A,n
// ADD A,r
void ADD(u8* source)
{
    setHflag(((REG_A & 0xf)+(*source&0xf)) & 0x10);
    REG_A += *source;
    setZflag(REG_A);
    setNflag(0);
    setCflag(REG_A  & 0x80);
}

// ADD HL,ss
void ADD(u16* source)
{
    REG_HL += source;
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
            PUSH(REG_PC);
            REG_PC = address;
        }
        break;
    case 1:
        if((REG_F & Z_FLAG))
        {
            PUSH(REG_PC);
            REG_PC = address;
        }
        break;
    case 2:
        if(!(REG_F & C_FLAG))
        {
            PUSH(REG_PC);
            REG_PC = address;
        }
        break;
    case 3:
        if((REG_F & C_FLAG))
        {
            PUSH(REG_PC);
            REG_PC = address;
        }
        break;

    }
}

// CALL pq
void CALL (u16 address)
{
    PUSH(REG_PC);
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

void DEC (u8* source)
{
    setHflag(*source &0xf == 0);
    *source--;
    setZflag(*source);
    setNflag(1);
}

void DEC(u16* source)
{
    *source--;
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

void INC(u8* source)
{

}

void INC(u16* source)
{

}

// IND
// INDR
// INI
// INIR

void JP(u8 cc, u16 address)
{

}

void JP(u16 address)
{

}

void JR(u8 cc, s8 offset)
{

}

void JR (s8 offset)
{

}

void LD(u16* dest, u16* source)
{

}

void LD(u8* dest, u8* source)
{

}

// LD (C), A -- must add using reset vector or something. Need go way to call it

// block load instructions... whatever

void NEG()
{

}

void NOP()
{

}

void OR(u8* source)
{

}



// OUT ...

// NOTE this accepts a reg16*, not a u16*. Should change
void POP(reg16* source)
{

}

// same as aboce
void PUSH(reg16* source)
{

}

void RES(u8 bit, u8* source)
{

}

void RET()
{

}

// CHANGE!!!  No cc passing. Determined within function
void RET(u8 cc)
{

}

// book says return from interrupt
// pandocs say return from subroutine then enable interrupts
void RETI()
{

}

// RETN

void RL(u8* source)
{

}

void RLA()
{

}


void RLC(u8* source)
{

}


void RLCA()
{

}


void RR(u8* source)
{

}

void RRA()
{

}

void RRC(u8* source)
{

}

void RRCA()
{
}


void RST(u8 source)
{

}

void SBC(u8* source)
{

}

void SBC(u16* source)
{

}

void SCF()
{

}

void SET(u8 bit, u8* source)
{

}

void SLA(u8* source)
{
}

void SRA(u8* source)
{
}

void SRL(u8* source)
{
}

void SUB(u8* source)
{
}

void SWAP(u8* source)
{

}

void XOR(u8* source)
{
}
