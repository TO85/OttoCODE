#include "Sortable.h"

#include <QByteArray>
#include <QRandomGenerator>
#include <QVariant>

#include <QQDir>

#include <Key>
#include <KeySeg>
#include <Uid>

bool Sortable::equal(const Sortable &other) const
{
    return mString == other.mString;
}

bool Sortable::less(const Sortable &other) const
{
    return mString < other.mString;
}

void Sortable::clear()
{
    mString.clear();
}

void Sortable::set(const QString &string)
{
    mString = string.toCaseFolded();
}

void Sortable::set(const QVariant &variant)
{
    set(variant.toString());
}

void Sortable::set(const QByteArray &bytes)
{
    set(QString(bytes));
}

void Sortable::set(const Key &key)
{
    set(key.toQString());
}

void Sortable::set(const KeySeg &seg)
{
    set(seg.toQString());
}

void Sortable::set(const QQDir &dir)
{
    set(dir.absolutePath());
}

void Sortable::set(const Uid &uid)
{
    set(uid.toString());
}

/* --------------------- static ----------------------- */

QByteArray Sortable::random()
{
    const quint64 tRandom = QRandomGenerator::securelySeeded().generate64();
    const QByteArray ba((char *)(&tRandom), sizeof(tRandom));
    return ba.toBase64();
}

/* -------------------- extern ---------------------- */

bool operator == (const Sortable & lhs, const Sortable & rhs)
{
    return lhs.equal(rhs);
}

bool operator < (const Sortable & lhs, const Sortable & rhs)
{
    return lhs.less(rhs);
}
