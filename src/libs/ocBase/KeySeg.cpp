#include "KeySeg.h"

#include "Key.h"

KeySeg::KeySeg() {;}
KeySeg::KeySeg(const QString &qs) { set(qs); }

bool KeySeg::startsWith(const KeySeg &stub) const
{
    return mString.startsWith(stub.toQString());
}

QString KeySeg::toQString() const
{
    return mString;
}

void KeySeg::clear()
{
    mString.clear();
}

void KeySeg::set(const QString &string)
{
    mString.clear();
    for (QChar c : string)
        mString.append(smValidCharRx.match(c).hasMatch() ? c : smInvalidReplaceString);
}

/* ---------------------- static ---------------------- */

QRegularExpression KeySeg::smValidCharRx = QRegularExpression("[a-zA-Z0-9_$#]");
QString KeySeg::smInvalidReplaceString; // empty default

QList<KeySeg> KeySeg::split(const QString segNames)
{
    QString tSimplified = segNames.simplified();
    tSimplified.replace(' ', '/');
    const Key tKey = tSimplified;
    return tKey.list();
}

/* ---------------------- extern ---------------------- */

bool operator == (const KeySeg &lhs, const KeySeg &rhs)
{
    return lhs.toQString().toCaseFolded() == rhs.toQString().toCaseFolded();
}

bool operator <  (const KeySeg &lhs, const KeySeg &rhs)
{
    return lhs.toQString().toCaseFolded() <  rhs.toQString().toCaseFolded();
}


