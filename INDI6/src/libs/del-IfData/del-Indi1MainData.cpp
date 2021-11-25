#include "Indi1MainData.h"

#include <eirXml/eirXml.h>
#include <eirXml/ElementAttributeMap.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>

#include "Indi1ResourceManager.h"

void Indi1MainData::clear()
{
    mDomStatus.clear(), mName.clear(), mClass.clear(), mDescription.clear(),
    mActivePixels = 0, mNormalSize.nullify(), mNormalEyeLine.nullify();
}

DomStatus Indi1MainData::load(const QQDomElement &de)
{
    QQDomDocument doc = de.ownerDocument();
    TRACEQFI << de.tagName() << doc.doctypeName();
    de.dump(true);
    DomStatus status = eirXml::checkDoctypeNodeName(doctypeExpected(),
            "INDI Resource Data", dataTagExpected(), de);
    if (status.type().isError()) return status;                               /* /====\ */

    ElementAttributeMap attribs(de);
    setName(attribs.tryExists(&status, "Name").toString());
    setClass(attribs.tryExists(&status, "Class").toString());
    setDescription(attribs.tryExists(&status, "Description").toString());
    setActivePixels(attribs.tryExists(&status, "Pixels").toInt());
    const int normalizedWidth = attribs.tryExists(&status, "Width").toInt();
    const int normalizedHeight = attribs.tryExists(&status, "Height").toInt();
    setNormalSize(QQSize(normalizedWidth, normalizedHeight));
    const int normalizedEyeLeftX = attribs.tryExists(&status, "LeftEyeX").toInt();
    const int normalizedEyeLeftY = attribs.tryExists(&status, "LeftEyeY").toInt();
    const int normalizedEyeRightX = attribs.tryExists(&status, "RightEyeX").toInt();
    const int normalizedEyeRightY = attribs.tryExists(&status, "RightEyeY").toInt();
    setNormalEyeLine(EyeLine(QQPoint(normalizedEyeLeftX, normalizedEyeLeftY),
                             QQPoint(normalizedEyeRightX, normalizedEyeRightY)));
    WANTDO(qualifyData);
    return status;
}

/* ----------------------- private ------------------------ */

void Indi1MainData::setName(const BasicName &newName)
{
    mName = newName;
}

void Indi1MainData::setClass(const BasicName &newClass)
{
    mClass = newClass;
}

void Indi1MainData::setDescription(const Document &newDescription)
{
    mDescription = newDescription;
}

void Indi1MainData::setActivePixels(int newActivePixels)
{
    mActivePixels = newActivePixels;
}

void Indi1MainData::setNormalSize(const QQSize &newNormalSize)
{
    mNormalSize = newNormalSize;
}

void Indi1MainData::setNormalEyeLine(const EyeLine &newNormalEyeLine)
{
    mNormalEyeLine = newNormalEyeLine;
}

/* ------------------------- debug --------------------------- */

QQStringList Indi1MainData::toDebugStrings() const
{
}

