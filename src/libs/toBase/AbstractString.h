#pragma once

#include <QtCore/QString>

#include <QtCore/QFlags>
#include <QtCore/QMetaType>
#include <QtCore/QRegularExpression>

class AbstractString : public QString
{
public:
    enum Flag
    {
        $null = 0,
        Delimited       = 0x00000001,
        Sectioned       = 0x00000002,
    };
    Q_DECLARE_FLAGS(Flags, Flag);


protected:
    AbstractString(const AbstractString::Flags f, const QString &string);
    AbstractString(const AbstractString::Flags f, const QChar delim, const QString &string);

public:
    AbstractString() = default;
    AbstractString(const AbstractString &other) = default;
    ~AbstractString() = default;
    AbstractString &operator = (const AbstractString &other) = default;

public:
    QChar firstChar() const;
    QChar takeFirstChar();
    bool set(const QString &string);

public: // static
    static const QChar &getDelimitChar();
    static const AbstractString::Flags &getFlags();
    static const QRegularExpression &getValidChars();
    static const QRegularExpression &getInvalidChars();
    static const QRegularExpression &getFirstChars();
    static const QChar &getReplaceChar();
    static  bool isValidFirst(const QChar &ch);

protected:

protected:
    const static QChar csmDelimitChar;
    const static Flags csmFlags;
    const static QRegularExpression csmValidChars;
    const static QRegularExpression csmInvalidChars;
    const static QRegularExpression csmFirstChars;
    const static QChar csmReplaceChar;
};

Q_DECLARE_METATYPE(AbstractString);
