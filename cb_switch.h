case 0x00:
        RLC(&REG_B);
        break;
    case 0x01:
        RLC(&REG_C);
        break;
    case 0x02:
        RLC(&REG_D);
        break;
    case 0x03:
        RLC(&REG_E);
        break;
    case 0x04:
        RLC(&REG_H);
        break;
    case 0x05:
        RLC(&REG_L);
        break;
    case 0x06:
        RLC(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x07:
        RLC(&REG_A);
        break;
    case 0x08:
        RRC(&REG_B);
        break;
    case 0x09:
        RRC(&REG_C);
        break;
    case 0x0A:
        RRC(&REG_D);
        break;
    case 0x0B:
        RRC(&REG_E);
        break;
    case 0x0C:
        RRC(&REG_H);
        break;
    case 0x0D:
        RRC(&REG_L);
        break;
    case 0x0E:
        RRC(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x0F:
        RLC(&REG_A);
        break;
    case 0x10:
        RL(&REG_B);
        break;
    case 0x11:
        RL(&REG_C);
        break;
    case 0x12:
        RL(&REG_D);
        break;
    case 0x13:
        RL(&REG_E);
        break;
    case 0x14:
        RL(&REG_H);
        break;
    case 0x15:
        RL(&REG_L);
        break;
    case 0x16:
        RL(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x17:
        RL(&REG_A);
        break;
    case 0x18:
        RR(&REG_B);
        break;
    case 0x19:
        RR(&REG_C);
        break;
    case 0x1A:
        RR(&REG_D);
        break;
    case 0x1B:
        RR(&REG_E);
        break;
    case 0x1C:
        RR(&REG_H);
        break;
    case 0x1D:
        RR(&REG_L);
        break;
    case 0x1E:
        RR(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x1F:
        RL(&REG_A);
        break;
    case 0x20:
        SLA(&REG_B);
        break;
    case 0x21:
        SLA(&REG_C);
        break;
    case 0x22:
        SLA(&REG_D);
        break;
    case 0x23:
        SLA(&REG_E);
        break;
    case 0x24:
        SLA(&REG_H);
        break;
    case 0x25:
        SLA(&REG_L);
        break;
    case 0x26:
        SLA(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x27:
        SLA(&REG_A);
        break;
    case 0x28:
        SRA(&REG_B);
        break;
    case 0x29:
        SRA(&REG_C);
        break;
    case 0x2A:
        SRA(&REG_D);
        break;
    case 0x2B:
        SRA(&REG_E);
        break;
    case 0x2C:
        SRA(&REG_H);
        break;
    case 0x2D:
        SRA(&REG_L);
        break;
    case 0x2E:
        SRA(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x2F:
        SRA(&REG_A);
        break;
    case 0x30:
        SWAP(&REG_B);
        break;
    case 0x31:
        SWAP(&REG_C);
        break;
    case 0x32:
        SWAP(&REG_D);
        break;
    case 0x33:
        SWAP(&REG_E);
        break;
    case 0x34:
        SWAP(&REG_H);
        break;
    case 0x35:
        SWAP(&REG_L);
        break;
    case 0x36:
        SWAP(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x37:
        SWAP(&REG_A);
        break;
    case 0x38:
        SRL(&REG_B);
        break;
    case 0x39:
        SRL(&REG_C);
        break;
    case 0x3A:
        SRL(&REG_D);
        break;
    case 0x3B:
        SRL(&REG_E);
        break;
    case 0x3C:
        SRL(&REG_H);
        break;
    case 0x3D:
        SRL(&REG_L);
        break;
    case 0x3E:
        SRL(getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x3F:
        SRL(&REG_A);
        break;
    case 0x40:
        BIT(0,&REG_B);
        break;
    case 0x41:
        BIT(0,&REG_C);
        break;
    case 0x42:
        BIT(0,&REG_D);
        break;
    case 0x43:
        BIT(0,&REG_E);
        break;
    case 0x44:
        BIT(0,&REG_H);
        break;
    case 0x45:
        BIT(0,&REG_L);
        break;
    case 0x46:
        BIT(0,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x47:
        BIT(0,&REG_A);
        break;
    case 0x48:
        BIT(1,&REG_B);
        break;
    case 0x49:
        BIT(1,&REG_C);
        break;
    case 0x4A:
        BIT(1,&REG_D);
        break;
    case 0x4B:
        BIT(1,&REG_E);
        break;
    case 0x4C:
        BIT(1,&REG_H);
        break;
    case 0x4D:
        BIT(1,&REG_L);
        break;
    case 0x4E:
        BIT(1,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x4F:
        BIT(1,&REG_A);
        break;
    case 0x50:
        BIT(2,&REG_B);
        break;
    case 0x51:
        BIT(2,&REG_C);
        break;
    case 0x52:
        BIT(2,&REG_D);
        break;
    case 0x53:
        BIT(2,&REG_E);
        break;
    case 0x54:
        BIT(2,&REG_H);
        break;
    case 0x55:
        BIT(2,&REG_L);
        break;
    case 0x56:
        BIT(2,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x57:
        BIT(2,&REG_A);
        break;
    case 0x58:
        BIT(3,&REG_B);
        break;
    case 0x59:
        BIT(3,&REG_C);
        break;
    case 0x5A:
        BIT(3,&REG_D);
        break;
    case 0x5B:
        BIT(3,&REG_E);
        break;
    case 0x5C:
        BIT(3,&REG_H);
        break;
    case 0x5D:
        BIT(3,&REG_L);
        break;
    case 0x5E:
        BIT(3,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x5F:
        BIT(3,&REG_A);
        break;
    case 0x60:
        BIT(4,&REG_B);
        break;
    case 0x61:
        BIT(4,&REG_C);
        break;
    case 0x62:
        BIT(4,&REG_D);
        break;
    case 0x63:
        BIT(4,&REG_E);
        break;
    case 0x64:
        BIT(4,&REG_H);
        break;
    case 0x65:
        BIT(4,&REG_L);
        break;
    case 0x66:
        BIT(4,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x67:
        BIT(4,&REG_A);
        break;
    case 0x68:
        BIT(5,&REG_B);
        break;
    case 0x69:
        BIT(5,&REG_C);
        break;
    case 0x6A:
        BIT(5,&REG_D);
        break;
    case 0x6B:
        BIT(5,&REG_E);
        break;
    case 0x6C:
        BIT(5,&REG_H);
        break;
    case 0x6D:
        BIT(5,&REG_L);
        break;
    case 0x6E:
        BIT(5,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x6F:
        BIT(5,&REG_A);
        break;
    case 0x70:
        BIT(6,&REG_B);
        break;
    case 0x71:
        BIT(6,&REG_C);
        break;
    case 0x72:
        BIT(6,&REG_D);
        break;
    case 0x73:
        BIT(6,&REG_E);
        break;
    case 0x74:
        BIT(6,&REG_H);
        break;
    case 0x75:
        BIT(6,&REG_L);
        break;
    case 0x76:
        BIT(6,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x77:
        BIT(6,&REG_A);
        break;
    case 0x78:
        BIT(7,&REG_B);
        break;
    case 0x79:
        BIT(7,&REG_C);
        break;
    case 0x7A:
        BIT(7,&REG_D);
        break;
    case 0x7B:
        BIT(7,&REG_E);
        break;
    case 0x7C:
        BIT(7,&REG_H);
        break;
    case 0x7D:
        BIT(7,&REG_L);
        break;
    case 0x7E:
        BIT(7,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x7F:
        BIT(7,&REG_A);
        break;
    case 0x80:
        RES(0,&REG_B);
        break;
    case 0x81:
        RES(0,&REG_C);
        break;
    case 0x82:
        RES(0,&REG_D);
        break;
    case 0x83:
        RES(0,&REG_E);
        break;
    case 0x84:
        RES(0,&REG_H);
        break;
    case 0x85:
        RES(0,&REG_L);
        break;
    case 0x86:
        RES(0,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x87:
        RES(0,&REG_A);
        break;
    case 0x88:
        RES(1,&REG_B);
        break;
    case 0x89:
        RES(1,&REG_C);
        break;
    case 0x8A:
        RES(1,&REG_D);
        break;
    case 0x8B:
        RES(1,&REG_E);
        break;
    case 0x8C:
        RES(1,&REG_H);
        break;
    case 0x8D:
        RES(1,&REG_L);
        break;
    case 0x8E:
        RES(1,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x8F:
        RES(1,&REG_A);
        break;
    case 0x90:
        RES(2,&REG_B);
        break;
    case 0x91:
        RES(2,&REG_C);
        break;
    case 0x92:
        RES(2,&REG_D);
        break;
    case 0x93:
        RES(2,&REG_E);
        break;
    case 0x94:
        RES(2,&REG_H);
        break;
    case 0x95:
        RES(2,&REG_L);
        break;
    case 0x96:
        RES(2,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x97:
        RES(2,&REG_A);
        break;
    case 0x98:
        RES(3,&REG_B);
        break;
    case 0x99:
        RES(3,&REG_C);
        break;
    case 0x9A:
        RES(3,&REG_D);
        break;
    case 0x9B:
        RES(3,&REG_E);
        break;
    case 0x9C:
        RES(3,&REG_H);
        break;
    case 0x9D:
        RES(3,&REG_L);
        break;
    case 0x9E:
        RES(3,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0x9F:
        RES(3,&REG_A);
        break;
    case 0xA0:
        RES(4,&REG_B);
        break;
    case 0xA1:
        RES(4,&REG_C);
        break;
    case 0xA2:
        RES(4,&REG_D);
        break;
    case 0xA3:
        RES(4,&REG_E);
        break;
    case 0xA4:
        RES(4,&REG_H);
        break;
    case 0xA5:
        RES(4,&REG_L);
        break;
    case 0xA6:
        RES(4,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xA7:
        RES(4,&REG_A);
        break;
    case 0xA8:
        RES(5,&REG_B);
        break;
    case 0xA9:
        RES(5,&REG_C);
        break;
    case 0xAA:
        RES(5,&REG_D);
        break;
    case 0xAB:
        RES(5,&REG_E);
        break;
    case 0xAC:
        RES(5,&REG_H);
        break;
    case 0xAD:
        RES(5,&REG_L);
        break;
    case 0xAE:
        RES(5,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xAF:
        RES(5,&REG_A);
        break;
    case 0xB0:
        RES(6,&REG_B);
        break;
    case 0xB1:
        RES(6,&REG_C);
        break;
    case 0xB2:
        RES(6,&REG_D);
        break;
    case 0xB3:
        RES(6,&REG_E);
        break;
    case 0xB4:
        RES(6,&REG_H);
        break;
    case 0xB5:
        RES(6,&REG_L);
        break;
    case 0xB6:
        RES(6,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xB7:
        RES(6,&REG_A);
        break;
    case 0xB8:
        RES(7,&REG_B);
        break;
    case 0xB9:
        RES(7,&REG_C);
        break;
    case 0xBA:
        RES(7,&REG_D);
        break;
    case 0xBB:
        RES(7,&REG_E);
        break;
    case 0xBC:
        RES(7,&REG_H);
        break;
    case 0xBD:
        RES(7,&REG_L);
        break;
    case 0xBE:
        RES(7,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xBF:
        RES(7,&REG_A);
        break;
    case 0xC0:
        SET(0,&REG_B);
        break;
    case 0xC1:
        SET(0,&REG_C);
        break;
    case 0xC2:
        SET(0,&REG_D);
        break;
    case 0xC3:
        SET(0,&REG_E);
        break;
    case 0xC4:
        SET(0,&REG_H);
        break;
    case 0xC5:
        SET(0,&REG_L);
        break;
    case 0xC6:
        SET(0,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xC7:
        SET(0,&REG_A);
        break;
    case 0xC8:
        SET(1,&REG_B);
        break;
    case 0xC9:
        SET(1,&REG_C);
        break;
    case 0xCA:
        SET(1,&REG_D);
        break;
    case 0xCB:
        SET(1,&REG_E);
        break;
    case 0xCC:
        SET(1,&REG_H);
        break;
    case 0xCD:
        SET(1,&REG_L);
        break;
    case 0xCE:
        SET(1,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xCF:
        SET(1,&REG_A);
        break;
    case 0xD0:
        SET(2,&REG_B);
        break;
    case 0xD1:
        SET(2,&REG_C);
        break;
    case 0xD2:
        SET(2,&REG_D);
        break;
    case 0xD3:
        SET(2,&REG_E);
        break;
    case 0xD4:
        SET(2,&REG_H);
        break;
    case 0xD5:
        SET(2,&REG_L);
        break;
    case 0xD6:
        SET(2,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xD7:
        SET(2,&REG_A);
        break;
    case 0xD8:
        SET(3,&REG_B);
        break;
    case 0xD9:
        SET(3,&REG_C);
        break;
    case 0xDA:
        SET(3,&REG_D);
        break;
    case 0xDB:
        SET(3,&REG_E);
        break;
    case 0xDC:
        SET(3,&REG_H);
        break;
    case 0xDD:
        SET(3,&REG_L);
        break;
    case 0xDE:
        SET(3,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xDF:
        SET(3,&REG_A);
        break;
    case 0xE0:
        SET(4,&REG_B);
        break;
    case 0xE1:
        SET(4,&REG_C);
        break;
    case 0xE2:
        SET(4,&REG_D);
        break;
    case 0xE3:
        SET(4,&REG_E);
        break;
    case 0xE4:
        SET(4,&REG_H);
        break;
    case 0xE5:
        SET(4,&REG_L);
        break;
    case 0xE6:
        SET(4,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xE7:
        SET(4,&REG_A);
        break;
    case 0xE8:
        SET(5,&REG_B);
        break;
    case 0xE9:
        SET(5,&REG_C);
        break;
    case 0xEA:
        SET(5,&REG_D);
        break;
    case 0xEB:
        SET(5,&REG_E);
        break;
    case 0xEC:
        SET(5,&REG_H);
        break;
    case 0xED:
        SET(5,&REG_L);
        break;
    case 0xEE:
        SET(5,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xEF:
        SET(5,&REG_A);
        break;
    case 0xF0:
        SET(6,&REG_B);
        break;
    case 0xF1:
        SET(6,&REG_C);
        break;
    case 0xF2:
        SET(6,&REG_D);
        break;
    case 0xF3:
        SET(6,&REG_E);
        break;
    case 0xF4:
        SET(6,&REG_H);
        break;
    case 0xF5:
        SET(6,&REG_L);
        break;
    case 0xF6:
        SET(6,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xF7:
        SET(6,&REG_A);
        break;
    case 0xF8:
        SET(7,&REG_B);
        break;
    case 0xF9:
        SET(7,&REG_C);
        break;
    case 0xFA:
        SET(7,&REG_D);
        break;
    case 0xFB:
        SET(7,&REG_E);
        break;
    case 0xFC:
        SET(7,&REG_H);
        break;
    case 0xFD:
        SET(7,&REG_L);
        break;
    case 0xFE:
        SET(7,getUnsignedIndirectAddress(REG_HL));
        break;
    case 0xFF:
        SET(7,&REG_A);
        break;
