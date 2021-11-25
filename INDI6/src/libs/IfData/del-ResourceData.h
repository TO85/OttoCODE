#pragma once
#include "IfData.h"

#include <QtCore/QSharedDataPointer>
#include <eirType/DProperty.h>

#include <QtCore/QString>

#include <eirType/BasicName.h>
#include <eirType/QQLine.h>
#include <eirType/QQSize.h>

#define RESOURCEDATA_DATAPROPS(TND) \
    TND(int, Type, 0) \
    TND(BasicName, Name, BasicName()) \
    TND(QString, Description, QString()) \
    TND(QQSize, NormalSize, QQSize()) \
    TND(QQLine, NormalEyeLine, QQLine()) \

class ResourceDataData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(RESOURCEDATA_DATAPROPS)
public:
    ResourceDataData(void)
    {
        DEFINE_DATAPROPS_CTORS(RESOURCEDATA_DATAPROPS)
    }
};

class IFDATA_EXPORT ResourceData
{
    DECLARE_PARENT_DATAPROPS(RESOURCEDATA_DATAPROPS)
    DECLARE_DATAPROPS(ResourceData, ResourceDataData)
public:
};
