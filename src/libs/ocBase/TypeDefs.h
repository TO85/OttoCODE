//! @file TypeDefs.h OttoCODE Base Library {OttoCODE}./src/libs/ocBase
#pragma once
#include <QtGlobal>

typedef bool BIT;
typedef quint8 DIBIT;
typedef quint8 TRIBIT;
typedef quint8 NIBBLE;
typedef quint8 BYTE;
typedef quint16 WORD;
typedef quint32 TRIBYTE;
typedef quint32 DWORD;
typedef quint64 QWORD;
typedef unsigned __int128 OWORD;

const DIBIT dibitMask = 0b00000011;
const DIBIT tribitMask = 0b00000111;
const DIBIT nibbleMask = 0b00001111;
const DWORD tribyteMask = 0x00111111;


