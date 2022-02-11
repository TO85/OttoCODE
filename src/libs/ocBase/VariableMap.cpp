#include "VariableMap.h"

#include "Variable.h"

bool VariableMap::contains(const Key &key) const
{
    return QMap<Key, Variable>::contains(key);
}

const QVariant VariableMap::value(const Key &key, const QVariant &dVariant)
{
    return contains(key) ? at(key).value() : dVariant;
}

Variable &VariableMap::at(const Key &key)
{
    return QMap<Key, Variable>::operator [] (key);
}

void VariableMap::add(const Variable &variable)
{
    insert(variable.key(), variable);
}

void VariableMap::add(const Key &key, const QVariant &variant)
{
    add(Variable(key, variant));
}
