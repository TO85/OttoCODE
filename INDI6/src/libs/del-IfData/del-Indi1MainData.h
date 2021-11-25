#pragma once
#include "IfData.h"

#include <eirGui/Document.h>
#include <eirType/BasicName.h>
#include <eirType/QQSize.h>
#include <IfGeometry/EyeLine.h>

//#include "Indi1ResourceManager.h"

#include "MainResource.h"

class IFDATA_EXPORT Indi1MainData
{
public:
    explicit Indi1MainData() = default;
    Indi1MainData(const Indi1MainData &other) = default;
    ~Indi1MainData() = default;
    Indi1MainData &operator = (const Indi1MainData &other) = default;


private:
    MainResource mMainData;
};

Q_DECLARE_METATYPE(Indi1MainData);
