#include "AbstractString.h"

const QChar AbstractString::csmDelimitChar = QChar('/');
const AbstractString::Flags AbstractString::csmFlags = AbstractString::$null;


AbstractString::AbstractString(const Flags f, const QString &string)
{

}

QChar AbstractString::firstChar() const
{
    QChar result = QChar(*data());
    return result;
}

QChar AbstractString::takeFirstChar()
{
    QChar result = firstChar();
    remove(0, 1);
    return result;
}

bool AbstractString::set(const QString &string)
{
    QString value;
    QString copy = string;
    QChar ch = copy.at(0);
    copy.remove(0, 1);
    if (isValidFirst(ch))
        value.append(ch);

    bool result = value == string;
    return result;
}

AbstractString::AbstractString(const Flags f, const QChar delim, const QString &string)
{

}

const QChar &AbstractString::getDelimitChar()
{
    return csmDelimitChar;
}

const AbstractString::Flags &AbstractString::getFlags()
{
    return csmFlags;
}

const QRegularExpression &AbstractString::getValidChars()
{
    return csmValidChars;
}

const QRegularExpression &AbstractString::getInvalidChars()
{
    return csmInvalidChars;
}

const QRegularExpression &AbstractString::getFirstChars()
{
    return csmFirstChars;
}

const QChar &AbstractString::getReplaceChar()
{
    return csmReplaceChar;
}

bool AbstractString::isValidFirst(const QChar &ch)
{
    if ( ! getFirstChars().isValid()) return true;
    QRegularExpressionMatch rem = getFirstChars().match(ch);
    if (QRegularExpression::NoMatch != rem.matchType()) return true;
    return false;
}
