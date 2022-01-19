#include "Sortable.h"

#include <QByteArray>
#include <QRandomGenerator>
#include <QVariant>

#include <Key>

QString Sortable::source()
{
    return mSource;
}

QVariant Sortable::variant()
{
    return mVariant;
}

void Sortable::set()
{
    const quint64 tRandom = QRandomGenerator::securelySeeded().generate64();
    QByteArray ba((char *)(&tRandom), sizeof(tRandom));
    set(ba.toBase64());
}

void Sortable::set(const QString &string)
{
    set(QVariant(string));
}

void Sortable::set(const QVariant &variant)
{
    mVariant = variant;
    mSource = mVariant.toString();
    clear();
    append(mSource.toCaseFolded());
}

void Sortable::set(const QByteArray &bytes)
{
    set(QVariant(bytes));
}

void Sortable::set(const Key &key)
{
    set(key.toString());
}
