#include "MainDocument.h"

MainDocument::MainDocument(QObject *parent) : BaseDocument(parent)
{

}

const MainData &MainDocument::data() const
{
    return mData;
}

void MainDocument::setData(const MainData &newData)
{
    mData = newData;
}

DomStatus MainDocument::parseElements()
{
    QQDomElement de = rootElement();
    TRACEQFI << de;
    DomStatus result;
    MainData tMainData;

    result.info("Parsing MainData from %1", de.tagName());
    ElementAttributeMap attrMap(de);
    tMainData.setName(attrMap.tryExists(&result, "Name").toString());
    tMainData.setClassName(attrMap.tryExists(&result, "Class").toString());
    tMainData.setDescription(attrMap.tryExists(&result, "Description").toString());
    tMainData.setPixelCount(attrMap.tryExists(&result, "Pixels").toInt());
    const int tWidth = attrMap.tryExists(&result, "Width").toInt();
    const int tHeight = attrMap.tryExists(&result, "Height").toInt();
    const int tLEyeX = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tLEyeY = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tREyeX = attrMap.tryExists(&result, "LeftEyeX").toInt();
    const int tREyeY = attrMap.tryExists(&result, "LeftEyeX").toInt();
    tMainData.setNormalSize(QQSize(tWidth, tHeight));
    tMainData.setNormalEyes(EyeLine(QQPoint(tLEyeX, tLEyeY), QQPoint(tREyeX, tREyeY)));

    setData(tMainData);
    result.dump();
    return result;
}
