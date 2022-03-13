#pragma once
#include "ocType.h"

#include <QByteArray>
#include <QMetaType>
#include <QString>

class OCTYPE_EXPORT AsciiString : public QByteArray
{
public:
    AsciiString(const QByteArray & other) : QByteArray(other) {;}
    AsciiString(const QString & aString) : QByteArray(aString.toLocal8Bit()) {;}
    AsciiString(const char * pch) : QByteArray(pch) {;}
    AsciiString() = default;
    ~AsciiString() = default;
    AsciiString(const AsciiString & other) = default;
    AsciiString &operator = (const AsciiString & other) = default;

    QByteArray toQByteArray() const;

private:
    AsciiString it() const { return *this; }
    AsciiString & it() { return *this; }


};

Q_DECLARE_METATYPE(AsciiString);
