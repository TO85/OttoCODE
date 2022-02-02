#pragma once
#include "ocBase.h"

#include <QByteArray>
#include <QMetaType>
#include <QString>

class OCBASE_EXPORT AsciiString : public QByteArray
{
public:
    AsciiString(const QString &aString) : QByteArray(aString.toLocal8Bit()) {;}
    AsciiString(const char *pch) : QByteArray(pch) {;}
    AsciiString() = default;
    ~AsciiString() = default;
    AsciiString(const AsciiString &other) = default;
    AsciiString &operator = (const AsciiString &other) = default;

};

Q_DECLARE_METATYPE(AsciiString);
