#include "VariablePak.h"

#include <QByteArray>
#include <QVariant>
#include <QVariantList>

#include <Key.h>
#include <Uid.h>
#include <Variable.h>
#include <VariableList.h>
#include <VariableMap.h>

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
