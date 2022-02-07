#include "VariablePack.h"

#include <QByteArray>
#include <QVariant>
#include <QVariantList>

#include <Key.h>
#include <Uid.h>
#include <Variable.h>
#include <VariableList.h>
#include <VariableMap.h>

class VariablePackData : public QSharedData
{
public:
    Uid dmUid;
    Key dmKey;
    QByteArray dmBytes;
    QVariant dmData;
    QVariantList dmDataList;
    VariableList dmVariableList;
    VariableMap dmVariableMap;
};

VariablePack::VariablePack() : data(new VariablePackData)
{

}

VariablePack::VariablePack(const VariablePack &other)
    : data{other.data}
{

}

VariablePack &VariablePack::operator=(const VariablePack &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

VariablePack::~VariablePack()
{

}
