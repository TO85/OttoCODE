#pragma once
#include "ocBase.h"

#include <QSharedDataPointer>
class VariablePakData;

class QByteArray;
class QVariant;

#include <Key>
#include <Uid>
class Variable;
class VariableList;
class VariableMap;

class OCBASE_EXPORT VariablePak
{
public:

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
    void set(const QByteArray &bytes);
    void set(const QVariant &bytes);
    void set(const int index, const QVariant &vari, const Key &key=Key());
    void set(const Key &key, const QVariant &vari);
    void set(const int index, const Variable &var);
    void set(const Key &key, const Variable &var);
    Variable & operator [] (const int index);
    Variable & operator [] (const Key & key);

private:
    Uid mUid;
    QSharedDataPointer<VariablePakData> data;

};



