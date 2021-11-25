#include "AbstractResource.h"

#include <eirType/QQPoint.h>
#include <eirXfr/Debug.h>

AbstractResource::AbstractResource() : mType(ResourceType::$null) {;}

AbstractResource::AbstractResource(const ResourceType &aType) : mType(aType) {;}

AbstractResource::AbstractResource(const ResourceType &aType, const QQDomElement &aDE)
    : mType(aType) , mAttributes(aDE) , mElement(aDE) {;}

bool AbstractResource::contains(const BasicName &aKey) const
{
    bool result = mAttributes.map().contains(aKey);
    TRACEQFI << aKey() << result;
    return result;
}

QQString AbstractResource::attribute(const BasicName &aKey) const
{
    QQString result = mAttributes.map().value(aKey);
    TRACEQFI << aKey() << result;
    return result;
}

QQVariant AbstractResource::attribute(const BasicName &aKey, const QVariant::Type &variType) const
{
    QQString tString = attribute(aKey);
    QQVariant result(tString);
    result.convert(variType);
    TRACEQFI << aKey << variType << result.toString();
    return result;
}

int AbstractResource::attributeInt(const BasicName &aKey) const
{
    return attribute(aKey, QQVariant::Int).toInt();
}

int AbstractResource::pixelCount() const
{
    // WANTDO: move math to set()
    TRACEFN;
    return attribute("Pixels").toInt();
}

QQSize AbstractResource::normalSize() const
{
    // WANTDO: move math to set()
    TRACEFN;
    const int tWidth = attribute("Width").toInt();
    const int tHeight = attribute("Height").toInt();
    return QQSize(tWidth, tHeight);
}

QQLine AbstractResource::normalEyeLine() const
{
    // WANTDO: move math to set()
    TRACEFN;
    const int tLX = attribute("LeftEyeX").toInt();
    const int tLY = attribute("LeftEyeY").toInt();
    const int tRX = attribute("RightEyeX").toInt();
    const int tRY = attribute("RightEyeY").toInt();
    return QQLine(QQPoint(tLX, tLY), QQPoint(tRX, tRY));
}

bool AbstractResource::isNull() const
{
    return mType.isNull() || mType.isTypeNull();
}

void AbstractResource::set(const QQDomElement &aDE)
{
    mElement = aDE,
            mAttributes.parse(aDE);
}

QQStringList AbstractResource::toInfoStrings(const int level) const
{
    QQStringList result;
    result << QQString("Key: %1").formatMessage(mType.toInfoString());
    if (level >= 1)
        result << mAttributes.toInfoStrings();
    if (level >= 2)
        result << mElement.toInfoStrings();
    return result;
}

QQStringList AbstractResource::toDebugStrings() const
{
    QQStringList result;
    result << QQString("{AbstractResource: Type=%1>").formatMessage(type().toInfoString());
    result << QQString("{ResourceAttributes:>");
    result << mAttributes.toInfoStrings();
    result << mElement.toDebugStrings();
    result << QQString("<ResourceAttributes}");
    result << QQString("<AbstractResource}");
    return result;
}
