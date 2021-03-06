#pragma once
#include "ocType.h"

#include <QSharedDataPointer>
class VariablePakData;

class QByteArray;
class QVariant;

#include <Key>
#include <Uid>

#include "Variable.h"
class VariableList;
class VariableMap;

class OCTYPE_EXPORT VariablePak
{
public:
    VariablePak(const int variantReserve, const int variableReserve);

public:
    const Uid uid() const;
    const Key key() const;
    const QByteArray bytes() const;
    const QVariant variant() const;
    const QVariant variant(const int index) const;
    const QVariantList variants() const;
    const VariableList variables() const;
    const VariableMap variableMap() const;
    bool isValidIndex(const int index) const;
    bool notValidIndex(const int index) const { return ! isValidIndex(index); }
    const Variable get(const int index) const;
    const Variable get(const Key & key) const;
    const Variable operator ()  (const int index) const { return get(index); }
    const Variable operator ()  (const Key & key) const { return get(key); }

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
    void set(const Variable &var);
    Variable & operator [] (const int index);
    Variable & operator [] (const Key & key);

private:
    Uid mUid;
    QSharedDataPointer<VariablePakData> data;

public: // QMetaType
    VariablePak();
    VariablePak(const VariablePak &);
    VariablePak &operator=(const VariablePak &);
    ~VariablePak();
};



