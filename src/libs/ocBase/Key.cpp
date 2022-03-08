#include "Key.h"

#include "Sortable.h"

Key::Key(const KeySeg &ki) { set(ki); }
Key::Key(const QList<KeySeg> &kql) : mSegments(kql) {;}
Key::Key(const QString &qs) { set(qs); }
Key::Key(const QStringList &qsl) { set(qsl); }
Key::Key(const char *pch) { set(pch); }

void Key::set(const KeySeg &ki)
{
    clear();
    mSegments.append(ki);
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
}

void Key::set(const char *pch)
{
    set(QString(pch));
}

Key Key::append(const KeySeg &seg)
{
    mSegments.append(seg);
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

QList<KeySeg> Key::list() const
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
    return toQString() == other.toQString();
}

bool Key::less(const Key &other) const
{
    return toQString() < other.toQString();
}

void Key::clear()
{
    mSegments.clear();
}

QString Key::toQString() const
{
    QString result;
    if (notEmpty())
    {
        result = mSegments.first().toQString();
        if (count() > 1)
            for (KeySeg seg : mSegments.mid(1))
                result.append(separator() + seg.toQString());
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


