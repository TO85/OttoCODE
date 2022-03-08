#include "KeySeg.h"

#include "Key.h"
#include "Sortable.h"

KeySeg::KeySeg() {;}
KeySeg::KeySeg(const QString &qs) { set(qs); }
#if 0
bool KeySeg::equal(const KeySeg &other)
{
    return Sortable(it()).equal(Sortable(other));
}
#endif
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

QList<KeySeg> KeySeg::split(const String segNames)
{
    const String tSimplified = segNames.simplified();
    const Key tKey = tSimplified.replaced(' ', '/');
    return tKey.list();
}

/* ---------------------- extern ---------------------- */

