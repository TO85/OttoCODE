#pragma once
#include "ocBase.h"

#include <QChar>

#include <QMetaType>

class TOBASE_EXPORT AsciiChar : public QChar
{
public:
    AsciiChar(const QChar &aChar) : QChar(aChar) {;}
    AsciiChar(const char *psz) : QChar(*psz) {;}
    AsciiChar(const char ch) : QChar(ch) {;}
    AsciiChar() = default;
    ~AsciiChar() = default;
    AsciiChar(const AsciiChar &other) = default;
    AsciiChar &operator = (const AsciiChar &other) = default;

};


Q_DECLARE_METATYPE(AsciiChar);
