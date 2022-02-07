#pragma once

#include <QMetaEnum>
#include <QMetaObject>

#include <KeySeg>

template <class QOBJ> KeySeg enumName(const QOBJ value)
{
    return KeySeg(QMetaEnum::fromType<QOBJ>().valueToKey(value));
}

template <class QOBJ> int enumValue(const char * name)
{
    return QMetaEnum::fromType<QOBJ>().keyToValue(name);
}


class ObjectHelper
{
public:
    ObjectHelper();
};

