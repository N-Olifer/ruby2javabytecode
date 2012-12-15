#ifndef CODECOMMANDS_H
#define CODECOMMANDS_H

#define ICONST_0 (quint8)0x3
#define ICONST_1 (quint8)0x4
#define BIPUSH (quint8)0x10
#define SIPUSH (quint8)0x11
#define LDC (quint8)0x12
#define ILOAD (quint8)0x15
#define ALOAD (quint8)0x19
#define ISTORE (quint8)0x36
#define ASTORE (quint8)0x3a
#define DUP (quint8)0x59
#define IADD (quint8)0x60
#define NEW (quint8)0xbb
#define INVOKEVIRTUAL (quint8)0xb6
#define INVOKESPECIAL (quint8)0xb7
#define INVOKESTATIC (quint8)0xb8
#define IRETURN (quint8)0xac
#define ARETURN (quint8)0xb0
#define RETURN (quint8)0xb1

#endif // CODECOMMANDS_H
