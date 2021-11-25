#include "MainDataParser.h"

#include <eirXml/ElementAttributeMap.h>

#include "ResourceManager.h"

void MainDataParser::clear()
{
    mMainData.clear();
}

DomStatus MainDataParser::load(const QQDomElement &de)
{
    TRACEQFI << de;
    DomStatus result;
    MainResource tMainData;

    result.info("Parsing MainData from %1", de.tagName());
    ElementAttributeMap attrMap(de);
    tMainData.setName(attrMap.tryExists(&result, "Name").toString());
    tMainData.setClassName(attrMap.tryExists(&result, "Class").toString());
    tMainData.setDescription(attrMap.tryExists(&result, "Description").toString());
    tMainData.setActivePixels(attrMap.tryExists(&result, "Pixels").toInt());
    const int tWidth = attrMap.tryExists(&result, "Width").toInt();
    const int tHeight = attrMap.tryExists(&result, "Height").toInt();
    const int tLEyeX = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tLEyeY = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tREyeX = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tREyeY = attrMap.tryExists(&result, "LeftEyeX").toInt();
    tMainData.setNormalSize(QQSize(tWidth, tHeight));
    tMainData.setNormalEyeLine(EyeLine(QQPoint(tLEyeX, tLEyeY), QQPoint(tREyeX, tREyeY)));

    mMainData = tMainData;
    result.dump();
    return result;
}


QQString MainDataParser::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

QQString MainDataParser::dataTagExpected() const
{
    return ResourceManager::dataTagExpected();
}
