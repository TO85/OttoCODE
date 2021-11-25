#include "MainData.h"

/* ---------------------- access ------------------------ */

const BasicName MainData::className() const
{
    return mClassName;
}

const BasicName MainData::name() const
{
    return mName;
}

const QQString MainData::description() const
{
    return mDescription;
}

int MainData::pixelCount() const
{
    return mPixelCount;
}

const QQSize MainData::normalSize() const
{
    return mNormalSize;
}

const EyeLine MainData::normalEyes() const
{
    return mNormalEyes;
}

/* --------------------- private ---------------------- */

void MainData::setClassName(const BasicName &newClassName)
{
    mClassName = newClassName;
}

void MainData::resetClassName()
{
    setClassName(BasicName());
}

void MainData::setName(const BasicName &newName)
{
    mName = newName;
}

void MainData::resetName()
{
    setName(BasicName());
}

void MainData::setDescription(const QQString &newDescription)
{
    mDescription = newDescription;
}

void MainData::resetDescription()
{
    setDescription(QQString());
}

void MainData::setPixelCount(int newPixelCount)
{
    mPixelCount = newPixelCount;
}

void MainData::resetPixelCount()
{
    setPixelCount(-1);
}

void MainData::setNormalSize(const QQSize &newNormalSize)
{
    mNormalSize = newNormalSize;
}

void MainData::resetNormalSize()
{
    setNormalSize(QQSize());
}

void MainData::setNormalEyes(const EyeLine &newNormalEyes)
{
    mNormalEyes = newNormalEyes;
}

void MainData::resetNormalEyes()
{
    setNormalEyes(EyeLine());
}
