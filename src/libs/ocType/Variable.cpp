#include "Variable.h"

Variable::Variable(const Key &key, const QVariant &variant) : mKey(key), mVariant(variant) {;}

bool Variable::isNull() const
{
    return mKey.isEmpty() || mVariant.isNull();
}

Key Variable::key() const
{
    return mKey;
}

Key &Variable::key()
{
    return mKey;
}

QVariant Variable::vari() const
{
    return mVariant;
}

QVariant &Variable::vari()
{
    return mVariant;
}
