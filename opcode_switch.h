// NOP
    case 0:
        NOP();
        break;
    // LD BC,d16
    case 1:
        LD16(&REG_BC, getUnsignedImmediate16());
        break;
    // LD (BC), A
    case 2:
        LD8(getUnsignedIndirectAddress(REG_BC), &AF.hi);
        break;
    //INC BC
    case 3:
        INC16(&REG_BC);
        break;
    // INC B
    case 4:
        INC8(&REG_B);
        break;
    case 5:
        DEC8(&REG_B);
        break;
    case 6:
        LD8(&REG_B, getUnsignedImmediate8());
        break;
    case 7:
        RLCA();
    case 8:
        LD16((u16*)getUnsignedIndirectAddress(*getUnsignedImmediate16()),&REG_SP);
        break;
    case 9:
        ADD16(&REG_BC);
        break;
    case 0xA:
        LD8(&REG_A,getUnsignedIndirectAddress(REG_BC));
        break;
    case 0xB:
        DEC16(&REG_BC);
        break;
    case 0xC:
        INC8(&REG_C);
        break;
    case 0xD:
        DEC8(&REG_C);
        break;
    case 0xE:
        LD8(&REG_C,getUnsignedImmediate8());
        break;
    case 0xF:
        RRCA();
        break;
    case 0x10:
        // STOP();
        break;
    case 0x11:
        LD16(&REG_DE,getUnsignedImmediate16());
        break;
    case 0x12:
        LD8(getUnsignedIndirectAddress(REG_DE),&REG_A);
        break;
    case 0x13:
        INC16(&REG_DE);
        break;
    case 0x14:
        INC8(&REG_D);
        break;
    case 0x15:
        DEC8(&REG_D);
        break;
    case 0x16:
        LD8(&REG_D,getUnsignedImmediate8());
        break;
    case 0x17:
        RLA();
        break;
    case 0x18:
        JR8(*getSignedImmediate8());
        break;
    case 0x19:
        ADD16(&REG_DE);
        break;
    case 0x1A:
        LD8(&REG_A,getUnsignedIndirectAddress(REG_DE));
        break;
    case 0x1B:
        DEC16(&REG_DE);
        break;
    case 0x1C:
        INC8(&REG_E);
        break;
    case 0x1D:
        DEC8(&REG_E);
        break;
    case 0x1E:
        LD8(&REG_E,getUnsignedImmediate8());
        break;
    case 0x1f:
        RRA();
        break;
    case 0x20:
        JR(_NOT_ZERO, *getSignedImmediate8());
        break;
    case 0x21:
        LD16(&REG_HL, getUnsignedImmediate16());
        break;
    case 0x22:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_A);
        INC16(&REG_HL);
        break;
    case 0x23:
        INC16(&REG_HL);
        break;
    case 0x24:
        INC8(&REG_H);
        break;
    case 0x25:
        DEC8(&REG_H);
        break;
    case 0x26:
        LD8(&REG_H, getUnsignedImmediate8());
        break;
    case 0x27:
        DAA();
        break;
    case 0x28:
        JR(_ZERO , *getSignedImmediate8());
        break;
    case 0x29:
        ADD16(&REG_HL);
        break;
    case 0x2A:
        LD8(&REG_A,getUnsignedIndirectAddress(REG_HL));
        INC16(&REG_HL);
        break;
    case 0x2B:
        DEC16(&REG_HL);
        break;
    case 0x2C:
        INC8(&REG_L);
        break;
    case 0x2D:
        DEC8(&REG_L);
        break;
    case 0x2E:
        LD8(&REG_L, getUnsignedImmediate8());
        break;
    case 0x2F:
        CPL();
        break;
    case 0x30:
        JR(_NOT_CARRY,*getSignedImmediate8());
       break;
    case 0x31:
        LD16(&REG_SP,getUnsignedImmediate16());
        break;
    case 0x32:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_A);
        DEC16(&REG_HL);
        break;
    case 0x33:
        INC16(&REG_SP);
        break;
    case 0x34:
        INC8(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x35:
        DEC8(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x36:
        LD8(getUnsignedIndirectAddress(REG_HL), getUnsignedImmediate8());
        break;
    case 0x37:
        SCF();
        break;
    case 0x38:
        JR(_CARRY,*getSignedImmediate8());
        break;
    case 0x39:
        ADD16(&REG_SP);
        break;
    case 0x3A:
        LD8(&REG_A,getUnsignedIndirectAddress(REG_HL));
        DEC16(&REG_HL);
        break;
    case 0x3B:
        DEC16(&REG_SP);
        break;
    case 0x3C:
        INC8(&REG_A);
        break;
    case 0x3D:
        DEC8(&REG_A);
        break;
    case 0x3E:
        LD8(&REG_A,getUnsignedImmediate8());
        break;
    case 0x3F:
        CCF();
        break;
    case 0x40:
        LD8(&REG_B,&REG_B);
        break;
    case 0x41:
        LD8(&REG_B,&REG_C);
        break;
    case 0x42:
        LD8(&REG_B,&REG_D);
        break;
    case 0x43:
        LD8(&REG_B,&REG_E);
        break;
    case 0x44:
        LD8(&REG_B,&REG_H);
        break;
    case 0x45:
        LD8(&REG_B,&REG_L);
        break;
    case 0x46:
        LD8(&REG_B,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x47:
        LD8(&REG_B,&REG_A);
        break;
    case 0x48:
        LD8(&REG_C,&REG_B);
        break;
    case 0x49:
        LD8(&REG_C,&REG_C);
        break;
    case 0x4A:
        LD8(&REG_C,&REG_D);
        break;
    case 0x4B:
        LD8(&REG_C,&REG_E);
        break;
    case 0x4C:
        LD8(&REG_C,&REG_H);
        break;
    case 0x4D:
        LD8(&REG_C,&REG_L);
        break;
    case 0x4E: //different
        LD8(&REG_C,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x4F:
        LD8(&REG_C,&REG_A);
        break;
    case 0x50:
        LD8(&REG_D,&REG_B);
        break;
    case 0x51:
        LD8(&REG_D,&REG_C);
        break;
    case 0x52:
        LD8(&REG_D,&REG_D);
        break;
    case 0x53:
        LD8(&REG_D,&REG_E);
        break;
    case 0x54:
        LD8(&REG_D,&REG_H);
        break;
    case 0x55:
        LD8(&REG_D,&REG_L);
        break;
    case 0x56:
        LD8(&REG_D,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x57:
        LD8(&REG_D,&REG_A);
        break;
    case 0x58:
        LD8(&REG_E,&REG_B);
        break;
    case 0x59:
        LD8(&REG_E,&REG_C);
        break;
    case 0x5A:
        LD8(&REG_E,&REG_D);
        break;
    case 0x5B:
        LD8(&REG_E,&REG_E);
        break;
    case 0x5C:
        LD8(&REG_E,&REG_H);
        break;
    case 0x5D:
        LD8(&REG_E,&REG_L);
        break;
    case 0x5E:
        LD8(&REG_E,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x5F:
        LD8(&REG_E,&REG_A);
        break;
    case 0x60:
        LD8(&REG_H,&REG_B);
        break;
    case 0x61:
        LD8(&REG_H,&REG_C);
        break;
    case 0x62:
        LD8(&REG_H,&REG_D);
        break;
    case 0x63:
        LD8(&REG_H,&REG_E);
        break;
    case 0x64:
        LD8(&REG_H,&REG_H);
        break;
    case 0x65:
        LD8(&REG_H,&REG_L);
        break;
    case 0x66:
        LD8(&REG_H,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x67:
        LD8(&REG_H,&REG_A);
        break;
    case 0x68:
        LD8(&REG_L,&REG_B);
        break;
    case 0x69:
        LD8(&REG_L,&REG_C);
        break;
    case 0x6A:
        LD8(&REG_L,&REG_D);
        break;
    case 0x6B:
        LD8(&REG_L,&REG_E);
        break;
    case 0x6C:
        LD8(&REG_L,&REG_H);
        break;
    case 0x6D:
        LD8(&REG_L,&REG_L);
        break;
    case 0x6E: //different
        LD8(&REG_L,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x6F:
        LD8(&REG_L,&REG_A);
        break;
    // change from here on
    case 0x70:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_B);
        break;
    case 0x71:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_C);
        break;
    case 0x72:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_D);
        break;
    case 0x73:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_E);
        break;
    case 0x74:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_H);
        break;
    case 0x75:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_L);
        break;
    case 0x76:
        HALT();
        break;
    case 0x77:
        LD8(getUnsignedIndirectAddress(REG_HL),&REG_A);
        break;
    case 0x78:
        LD8(&REG_A,&REG_B);
        break;
    case 0x79:
        LD8(&REG_A,&REG_C);
        break;
    case 0x7A:
        LD8(&REG_A,&REG_D);
        break;
    case 0x7B:
        LD8(&REG_A,&REG_E);
        break;
    case 0x7C:
        LD8(&REG_A,&REG_H);
        break;
    case 0x7D:
        LD8(&REG_A,&REG_L);
        break;
    case 0x7E: //different
        LD8(&REG_A,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x7F:
        LD8(&REG_A,&REG_A);
        break;
    case 0x80:
        ADD8(&REG_B);
        break;
    case 0x81:
        ADD8(&REG_C);
        break;
    case 0x82:
        ADD8(&REG_D);
        break;
    case 0x83:
        ADD8(&REG_E);
        break;
    case 0x84:
        ADD8(&REG_H);
        break;
    case 0x85:
        ADD8(&REG_L);
        break;
    case 0x86:
        ADD8(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x87:
        ADD8(&REG_A);
        break;
    case 0x88:
        ADC8(&REG_B);
        break;
    case 0x89:
        ADC8(&REG_C);
        break;
    case 0x8A:
        ADC8(&REG_D);
        break;
    case 0x8B:
        ADC8(&REG_E);
        break;
    case 0x8C:
        ADC8(&REG_H);
        break;
    case 0x8D:
        ADC8(&REG_L);
        break;
    case 0x8E:
        ADC8(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x8F:
        ADC8(&REG_A);
        break;
    case 0x90:
        SUB(&REG_B);
        break;
    case 0x91:
        SUB(&REG_C);
        break;
    case 0x92:
        SUB(&REG_D);
        break;
    case 0x93:
        SUB(&REG_E);
        break;
    case 0x94:
        SUB(&REG_H);
        break;
    case 0x95:
        SUB(&REG_L);
        break;
    case 0x96:
        SUB(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x97:
        SUB(&REG_A);
        break;
    case 0x98:
        SBC8(&REG_B);
        break;
    case 0x99:
        SBC8(&REG_C);
        break;
    case 0x9A:
        SBC8(&REG_D);
        break;
    case 0x9B:
        SBC8(&REG_E);
        break;
    case 0x9C:
        SBC8(&REG_H);
        break;
    case 0x9D:
        SBC8(&REG_L);
        break;
    case 0x9E:
        SBC8(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x9F:
        SBC8(&REG_A);
        break;
    case 0xA0:
        AND(&REG_B);
        break;
    case 0xA1:
        AND(&REG_C);
        break;
    case 0xA2:
        AND(&REG_D);
        break;
    case 0xA3:
        AND(&REG_E);
        break;
    case 0xA4:
        AND(&REG_H);
        break;
    case 0xA5:
        AND(&REG_L);
        break;
    case 0xA6:
        AND(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xA7:
        AND(&REG_A);
        break;
    case 0xA8:
        XOR(&REG_B);
        break;
    case 0xA9:
        XOR(&REG_C);
        break;
    case 0xAA:
        XOR(&REG_D);
        break;
    case 0xAB:
        XOR(&REG_E);
        break;
    case 0xAC:
        XOR(&REG_H);
        break;
    case 0xAD:
        XOR(&REG_L);
        break;
    case 0xAE:
        XOR(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xAF:
        XOR(&REG_A);
        break;
    case 0xB0:
        OR(&REG_B);
        break;
    case 0xB1:
        OR(&REG_C);
        break;
    case 0xB2:
        OR(&REG_D);
        break;
    case 0xB3:
        OR(&REG_E);
        break;
    case 0xB4:
        OR(&REG_H);
        break;
    case 0xB5:
        OR(&REG_L);
        break;
    case 0xB6:
        OR(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xB7:
        OR(&REG_A);
        break;
    case 0xB8:
        CP(&REG_B);
        break;
    case 0xB9:
        CP(&REG_C);
        break;
    case 0xBA:
        CP(&REG_D);
        break;
    case 0xBB:
        CP(&REG_E);
        break;
    case 0xBC:
        CP(&REG_H);
        break;
    case 0xBD:
        CP(&REG_L);
        break;
    case 0xBE:
        CP(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xBF:
        CP(&REG_A);
        break;
    case 0xC0:
        RET(_NOT_ZERO);
        break;
    case 0xC1:
        POP(&REG_BC);
        break;
    case 0xC2:
        JP(_NOT_ZERO,*getUnsignedImmediate16());
        break;
    case 0xC3:
        JP8(*getUnsignedImmediate16());
        break;
    case 0xC4:
        CALL(_NOT_ZERO, *getUnsignedImmediate16());
        break;
    case 0xC5:
        PUSH(&REG_BC);
        break;
    case 0xC6:
        ADD8(getUnsignedImmediate8());
        break;
    case 0xC7:
        RST(0x00);
        break;
    case 0xC8:
        RET(_ZERO);
        break;
    case 0xC9:
        RET();
        break;
    case 0xCA:
        JP(_ZERO,*getUnsignedImmediate16());
        break;
    case 0xCB:
        doCBprefix(opcode);
        break;
    case 0xCC:
        CALL(_ZERO, *getUnsignedImmediate16());
        break;
    case 0xCD:
        CALL16(*getUnsignedImmediate16());
        break;
    case 0xCE:
        ADC8(getUnsignedImmediate8());
        break;
    case 0xCF:
        RST(0x08);
        break;
    case 0xD0:
        RET(_NOT_CARRY);
        break;
    case 0xD1:
        POP(&REG_DE);
        break;
    case 0xD2:
        JP(_NOT_CARRY,*getUnsignedImmediate16());
        break;
    case 0xD3:
        INVALID(opcode); // teehee?
        // break and stuff here maybe
        break;
    case 0xD4:
        CALL (_NOT_ZERO, *getUnsignedImmediate16());
        break;
    case 0xD5:
        PUSH(&REG_DE);
        break;
    case 0xD6:
        SUB(getUnsignedImmediate8());
        break;
    case 0xD7:
        RST(0x10);
        break;
    case 0xD8:
        RET(_CARRY);
        break;
    case 0xD9:
        RETI();
        break;
    case 0xDA:
        JP(_CARRY,*getUnsignedImmediate16());
        break;
    case 0xDB:
        INVALID(opcode);
        break;
    case 0xDC:
        CALL(_CARRY,*getUnsignedImmediate16());
        break;
    case 0xDD:
        INVALID(opcode);
        break;
    case 0xDE:
        SBC8(getUnsignedImmediate8());
        break;
    case 0xDF:
        RST(0x18);
        break;
    case 0xE0:
        printf("reg a: 0x%02X\n",REG_A);
        write8(0xff00 + *getUnsignedImmediate8(), REG_A);
        break;
    case 0xE1:
        POP(&REG_HL);
        break;
    case 0xE2:
        write8(0xff00 + REG_C, REG_A);
        break;
    case 0xE3:
        INVALID(opcode);
        break;
    case 0xE4:
        INVALID(opcode);
        break;
    case 0xE5:
        PUSH(&REG_HL);
        break;
    case 0xE6:
        AND(getUnsignedImmediate8());
        break;
    case 0xE7:
        RST(0x20);
        break;
    case 0xE8:
        REG_SP += *getUnsignedImmediate8();
        break;
    case 0xE9:
        JP8(REG_HL);
        break;
    case 0xEA:
        LD8(getUnsignedIndirectAddress(*getUnsignedImmediate16()), &REG_A);
        break;
    case 0xEB:
        INVALID(opcode);
        break;
    case 0xEC:
        INVALID(opcode);
        break;
    case 0xED:
        INVALID(opcode);
        break;
    case 0xEE:
        XOR(getUnsignedImmediate8());
        break;
    case 0xEF:
        RST(0x28);
        break;
    case 0xF0:
        REG_A = read8(0xff00 + *getUnsignedImmediate8());
        break;
    case 0xF1:
        POP(&REG_AF);
        break;
    case 0xF2:
        REG_A = read8(0xff00 + REG_C);
        break;
    case 0xF3:
        DI();
        break;
    case 0xF4:
        INVALID(opcode);
        break;
    case 0xF5:
        PUSH(&REG_AF);
        break;
    case 0xF6:
        OR(getUnsignedImmediate8());
        break;
    case 0xF7:
        RST(0x30);
        break;
    case 0xF8:
        REG_HL = REG_SP + *getUnsignedImmediate8();
        break;
    case 0xF9:
        LD16(&REG_SP,&REG_HL);
        break;
    case 0xFA:
        LD8(&REG_A,getUnsignedIndirectAddress(*getUnsignedImmediate16()));
        break;
    case 0xFB:
        EI();
        break;
    case 0xFC:
        INVALID(opcode);
        break;
    case 0xFD:
        INVALID(opcode);
        break;
    case 0xFE:
        CP(getUnsignedImmediate8());
        break;
    case 0xFF:
        RST(0x38);
        break;
