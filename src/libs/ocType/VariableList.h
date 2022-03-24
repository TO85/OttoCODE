#pragma once

#include <QList>
#include "Variable.h"

#include <QMetaType>

class VariableList : public QList<Variable>
{
public:
    VariableList() = default;
    ~VariableList() = default;
    VariableList(const VariableList &other) = default;
    VariableList &operator = (const VariableList &other) = default;

public:
    bool isValidIndex(const int index) const;
    const Variable at(const int index) const;
    const Variable operator () (const int index) const { return at(index); }

public:
    void add(const Variable & variable);
    void add(const Key & key, const QVariant & variant);
    VariableList operator << (const Variable & variable);

private:
    VariableList it() const { return *this; }
    VariableList & it() { return *this; }
};

Q_DECLARE_METATYPE(VariableList);

