#include "VariablePak.h"

#include <QByteArray>
#include <QVariant>
#include <QVariantList>

#include <Key>
#include <Uid>

#include "Variable.h"
#include "VariableList.h"
#include "VariableMap.h"

class VariablePakData : public QSharedData
{
public:
    Key dmKey;
    QByteArray dmBytes;
    QVariant dmData;
    QVariantList dmDataList;
    VariableList dmVariableList;
    VariableMap dmVariableMap;
};

VariablePak::VariablePak() : data(new VariablePakData)
{

}

VariablePak::VariablePak(const VariablePak &other)
    : data{other.data}
{

}

VariablePak &VariablePak::operator=(const VariablePak &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

VariablePak::~VariablePak()
{

}

const QByteArray VariablePak::bytes() const
{
    Q_ASSERT(data);
    return data->dmBytes;
}

const QVariant VariablePak::variant(const int index) const
{
    QVariant result;
    Q_ASSERT(data);
    const Variable tVar = isValidIndex(index) ? data->dmVariableList.at(index) : Variable();
    if (tVar.notNull())
        result = tVar.vari();
    return result;
}

bool VariablePak::isValidIndex(const int index) const
{
    Q_ASSERT(data);
    return index >= 0 && index < data->dmVariableList.count();
}

const Variable VariablePak::get(const int index) const
{
    Q_ASSERT(data);
    return isValidIndex(index) ? data->dmVariableList.at(index) : Variable();
}

void VariablePak::set(const QByteArray &bytes)
{
    Q_ASSERT(data);
    data->dmBytes = bytes;
}

const Variable VariablePak::get(const Key &key) const
{
    Q_ASSERT(data);
    return data->dmVariableMap.at(key);
}

QByteArray &VariablePak::bytes()
{
    Q_ASSERT(data);
    return data->dmBytes;
}

void VariablePak::set(const Key &key, const QVariant &vari)
{
    Variable tVar(key, vari);
    set(tVar);
}

void VariablePak::set(const Variable &var)
{
    Q_ASSERT(data);
    data->dmVariableMap.add(var);
}

void VariablePak::set(const int index, const QVariant &vari, const Key &key)
{
    const Variable tVar(key, vari);
    Q_ASSERT(data);
    data->dmVariableList[index] = tVar;
}
