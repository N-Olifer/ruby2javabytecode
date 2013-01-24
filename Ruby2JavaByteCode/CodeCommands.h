#ifndef CODECOMMANDS_H
#define CODECOMMANDS_H

#define ICONST_0		(quint8)0x03
#define ICONST_1		(quint8)0x04
#define BIPUSH			(quint8)0x10
#define SIPUSH			(quint8)0x11
#define LDC				(quint8)0x12
#define ILOAD			(quint8)0x15
#define ALOAD			(quint8)0x19
#define ISTORE			(quint8)0x36
#define ASTORE			(quint8)0x3A
#define DUP				(quint8)0x59
#define IADD			(quint8)0x60
#define NEW				(quint8)0xBB
#define INVOKEVIRTUAL	(quint8)0xB6
#define INVOKESPECIAL	(quint8)0xB7
#define INVOKESTATIC	(quint8)0xB8
#define IRETURN			(quint8)0xAC
#define ARETURN			(quint8)0xB0
#define RETURN			(quint8)0xB1
#define PUTFIELD		(quint8)0xB5
#define GETFIELD		(quint8)0xB4
#define GOTO			(quint8)0xA7
#define GOTO_W			(quint8)0xC8
#define IFNE			(quint8)0x9A
#define IFEQ			(quint8)0x99
#define POP				(quint8)0x57
#define GETSTATIC		(quint8)0xB2
#define PUTSTATIC		(quint8)0xB3
#define ATHROW          (quint8)0xBF
#endif // CODECOMMANDS_H
