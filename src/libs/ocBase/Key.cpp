#include "Key.h"

//#include "Sortable.h"

Key::Key(const KeySeg &first) { set(first); }
Key::Key(const QList<KeySeg> &segments) : mSegments(segments) {;}
Key::Key(const QString &qs) { set(qs); }
Key::Key(const QStringList &qsl) { set(qsl); }
Key::Key(const char *pch) { set(pch); }

void Key::set(const KeySeg &first)
{
    clear();
    mSegments.append(first);
#ifdef QT_DEBUG
    mdString = toQString();
#endif
}

void Key::set(const QString &qs)
{
    set(qs.split(separator()));
}

void Key::set(const QStringList &qsl)
{
    clear();
    for (QString qs : qsl)
        mSegments.append(qs);
#ifdef QT_DEBUG
    mdString = toQString();
#endif
}

void Key::set(const char *pch)
{
    set(QString(pch));
}

Key Key::append(const KeySeg &seg)
{
    mSegments.append(seg);
#ifdef QT_DEBUG
    mdString = toQString();
#endif
    return it();
}

int Key::count() const
{
    return mSegments.count();
}

bool Key::isEmpty() const
{
    return mSegments.isEmpty();
}

KeySeg Key::first() const
{
    return mSegments.first();
}

Key Key::first(const int k) const
{
    if (k > 0 && k < count())
        return mSegments.first(k);
    if (k < 0)
    {
        const int n = count() + k;
        if (n > 0)
            return mSegments.first(n);
    }
    return Key();
}

KeySeg Key::last() const
{
    return mSegments.isEmpty() ? KeySeg() : mSegments.last();
}

KeySeg::List Key::list() const
{
    return mSegments;
}

Key Key::appended(const KeySeg &seg) const
{
    Key result = it();
    return result.append(seg);
}

bool Key::equal(const Key &other) const
{
    return toQString().compare(other.toQString()) == 0;
//    return Sortable(it()).equal(Sortable(other));
}

bool Key::less(const Key &other) const
{
    return toQString().compare(other.toQString()) < 0;
//    return Sortable(it()).less(Sortable(other));
}

void Key::clear()
{
    mSegments.clear();
#ifdef QT_DEBUG
    mdString.clear();
#endif
}

QString Key::toQString(const QChar &sep) const
{
    QString result;
    const QString tSeperator = sep.isNull() ? separator() : sep;
     if (notEmpty())
    {
        result = mSegments.first().toQString();
        if (count() > 1)
            for (KeySeg seg : mSegments.mid(1))
                result.append(tSeperator + seg.toQString());
    }
    return result;
}

/* ----------------------- static --------------------------- */

QChar Key::smSeparator('/');

QChar Key::separator()
{
    return smSeparator;
}

void Key::setSeparator(const QChar &c)
{
    smSeparator = c;
}

/* ----------------------- extern --------------------------- */


