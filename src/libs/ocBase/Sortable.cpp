#include "Sortable.h"

#include <QByteArray>
#include <QRandomGenerator>
#include <QVariant>

#include "Key.h"
#include "KeySeg.h"

QString Sortable::source()
{
    return mSource;
}

QVariant Sortable::variant()
{
    return mVariant;
}

void Sortable::clear()
{
    mSource.clear();
    mVariant.clear();
    QString::clear();
    append(random());
}

void Sortable::set(const QString &string)
{
    mSource = string;
    set(QVariant(string));
    mVariant = QVariant(string);
}

void Sortable::set(const QVariant &variant)
{
    mSource = mVariant.toString();
    clear();
    append(mSource.toCaseFolded());
    mVariant = variant;
}

void Sortable::set(const QByteArray &bytes)
{
    set(QVariant(bytes));
    mSource = bytes;
    mVariant = QVariant(bytes);
}

void Sortable::set(const Key &key)
{
    set(key.toQString());
    mSource = key;
    mVariant = QVariant(key);
}

void Sortable::set(const KeySeg &seg)
{
    set(seg.toQString());
    mSource = seg;
    mVariant = QVariant(seg);
}

/* --------------------- static ----------------------- */

QByteArray Sortable::random()
{
    const quint64 tRandom = QRandomGenerator::securelySeeded().generate64();
    const QByteArray ba((char *)(&tRandom), sizeof(tRandom));
    return ba.toBase64();
}
