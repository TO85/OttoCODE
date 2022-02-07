#pragma once

#include <QSharedDataPointer>
class VariablePackData;

class QByteArray;
class QVariant;

class Uid;
class Key;
class Variable;
class VariableList;
class VariableMap;

class VariablePack
{
public:
    VariablePack();
    VariablePack(const VariablePack &other);
    VariablePack &operator=(const VariablePack & rhs);
    ~VariablePack();

public:
    const Uid uid() const;
    const Key key() const;
    const QByteArray bytes() const;
    const QVariant variant() const;
    const QVariantList variants() const;
    const VariableList variables() const;
    const VariableMap variableMap() const;
    const Variable operator ()  (const int index) const;
    const Variable operator ()  (const Key & key) const;

public:
    Uid &uid();
    Key &key();
    QByteArray &bytes();
    QVariant &variant();
    QVariantList &variants();
    VariableList &variables();
    VariableMap &variableMap();
    Variable & operator [] (const int index);
    Variable & operator [] (const Key & key);

private:
    QSharedDataPointer<VariablePackData> data;
};


