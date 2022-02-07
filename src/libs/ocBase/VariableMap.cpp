#include "VariableMap.h"

#include "Variable.h"

const QVariant VariableMap::value(const Key &key, const QVariant &dVariant)
{
    return contains(key) ? at(key).value() : dVariant;
}

void VariableMap::add(const Variable &variable)
{
    insert(Sortable(variable.key()), variable);
}

void VariableMap::add(const Key &key, const QVariant &variant)
{
    add(Variable(key, variant));
}
