#pragma once

#include <QMap>
#include "Sortable.h"
#include "Variable.h"

#include <QMetaType>

#include "Key.h"

class VariableMap : public QMap<Sortable, Variable>
{
public:
    VariableMap() = default;
    ~VariableMap() = default;
    VariableMap(const VariableMap &other) = default;
    VariableMap &operator = (const VariableMap &other) = default;

public:
    bool contains(const Key & key) const;
    const QVariant value(const Key & key, const QVariant & dVariant);
    const Variable at(const Key & key) const;
    const Variable operator () (const Key & key) const { return at(key); }

public:
    Variable & at(const Key & key);
    Variable & operator [] (const Key & key) { return at(key); }
    void add(const Variable & variable);
    void add(const Key & key, const QVariant & variant);
    VariableMap operator << (const Variable & variable);

private:
    VariableMap it() const { return *this; }
    VariableMap & it() { return *this; }
};

Q_DECLARE_METATYPE(VariableMap);

