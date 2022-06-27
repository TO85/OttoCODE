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
    return 0 == mSortableString.compare(other.mSortableString);
}

bool Sortable::less(const Sortable &other) const
{
    return mSortableString.compare(other.mSortableString) < 0;
//    return mSortableString < other.mSortableString;
}

bool Sortable::operator ==(const Sortable &other) const
{
    return 0 == mSortableString.compare(other.mSortableString);
//    return mSortableString == other.mSortableString;
//    return equal(other);
}

bool Sortable::operator<(const Sortable &other) const
{
    return mSortableString.compare(other.mSortableString) < 0;
//    return mSortableString < other.mSortableString;
//    return less(other);
}

void Sortable::clear()
{
    mSortableString.clear();
}

void Sortable::set(const QString &string)
{
    mSortableString = string.toCaseFolded();
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
