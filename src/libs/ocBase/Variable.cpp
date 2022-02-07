#include "Variable.h"

Variable::Variable(const Key &key, const QVariant &variant) : mKey(key), mVariant(variant) {;}

Key Variable::key() const
{
    return mKey;
}

Key &Variable::key(const Key newKey)
{
    return mKey = newKey;
}

QVariant Variable::value() const
{
    return mVariant;

}

QVariant &Variable::value(const QVariant newValue)
{
    return mVariant = newValue;
}
