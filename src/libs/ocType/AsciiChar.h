#pragma once
#include "ocType.h"

#include <QChar>
#include <QMetaType>

#include <TypeDefs>

class OCTYPE_EXPORT AsciiChar
{
public:
    AsciiChar(const QChar &aChar) : mChar(aChar.cell()) {;}
    AsciiChar(const char *psz) : mChar(*psz) {;}
    AsciiChar(const char ch) : mChar(ch) {;}
    AsciiChar() = default;
    ~AsciiChar() = default;
    AsciiChar(const AsciiChar &other) = default;
    AsciiChar &operator = (const AsciiChar &other) = default;

private:
    CHAR mChar;
};

Q_DECLARE_METATYPE(AsciiChar);
