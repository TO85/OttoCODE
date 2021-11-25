#include "ResourceBaseData.h"

#include <eirXfr/Debug.h>

ResourceBaseData::ResourceBaseData(const QQDomElement &aDE)
    : AbstractResource(ResourceType::BaseData, aDE)
{
    parse();
}

bool ResourceBaseData::isValid() const
{
    if (isNull()) return false;
    if (normalSize().notSquare()) return false;
    if (normalEyeLine().notFlat()) return false;
    if (normalEyeLine().center().x() != normalSize().center().x()) return false;
    NEEDDO(more);  // NEEDDO
    return true;
}

QQStringList ResourceBaseData::toInfoStrings(const int level) const
{
    QQStringList result = AbstractResource::toInfoStrings(level);
    result << QQString("Name: %1").formatMessage(name()());
    result << QQString("Desc: %1").formatMessage(description());
    result << QQString("Size: %1Wx%2H").formatMessage(normalSize().width(),
                                                      normalSize().height());
    result << QQString("Eyes: L=%1,R=%2,Y=%3,W=%4")
              .formatMessage(normalEyeLine().left(), normalEyeLine().right(),
                             normalEyeLine().top(), normalEyeLine().distance());
    return result;
}

bool ResourceBaseData::parse()
{
    TRACEQFI << element();
    const int tWidth = mAttributes.map().value("Width").toInt();
    const int tHeight = mAttributes.map().value("Height").toInt();
    const int tLeftEyeX = mAttributes.map().value("LeftEyeX").toInt();
    const int tLeftEyeY = mAttributes.map().value("LeftEyeY").toInt();
    const int tRightEyeX = mAttributes.map().value("RightEyeX").toInt();
    const int tRightEyeY = mAttributes.map().value("RightEyeY").toInt();
    mName = mAttributes.map().value("Name");
    mDescription = mAttributes.map().value("Description");
    mNormalSize = QQSize(tWidth, tHeight);
    mNormalEyeLine = QQLine(QQPoint(tLeftEyeX, tLeftEyeY), QQPoint(tRightEyeX, tRightEyeY));
    EXPECTNOT(mName.isEmpty());
    EXPECTNOT(mNormalSize.isEmpty());
    EXPECTNOT(mNormalEyeLine.isEmpty());
    if (mName.isEmpty()) return false;
    if (mNormalSize.isEmpty()) return false;
    if (mNormalEyeLine.isEmpty()) return false;
    return true;
}

const BasicName &ResourceBaseData::name() const
{
    return mName;
}

void ResourceBaseData::setName(const BasicName &newName)
{
    mName = newName;
}

void ResourceBaseData::resetName()
{
    mName.clear();
}

const QString &ResourceBaseData::description() const
{
    return mDescription;
}

void ResourceBaseData::setDescription(const QString &newDescription)
{
    mDescription = newDescription;
}

void ResourceBaseData::resetDescription()
{
    mDescription.clear();
}

const QQSize &ResourceBaseData::normalSize() const
{
    return mNormalSize;
}

void ResourceBaseData::setNormalSize(const QQSize &newNormalSize)
{
    mNormalSize = newNormalSize;
}

void ResourceBaseData::resetNormalSize()
{
    mNormalSize.empty();
}

const EyeLine &ResourceBaseData::normalEyeLine() const
{
    return mNormalEyeLine;
}

void ResourceBaseData::setNormalEyeLine(const QQLine &newNormalEyeLine)
{
    mNormalEyeLine = newNormalEyeLine;
}

void ResourceBaseData::resetNormalEyeLine()
{
    mNormalEyeLine.nullify();
}

bool ResourceBaseData::isNull() const
{
    if (AbstractResource::isNull()) return true;
    if (name().isEmpty()) return true;
    if (normalSize().isEmpty()) return true;
    if (normalEyeLine().isEmpty()) return true;
    return false;
}
