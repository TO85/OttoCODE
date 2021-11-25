#include "BaseIndi1MaskedFloatVector.h"

#include <eirXml/ElementAttributeMap.h>

#include "ResourceManager.h"
#include "VectorLayerData.h"

void BaseIndi1MaskedFloatVector::clear()
{
    mId = 0, mCount = 0, mMinData = qQNaN(), mMaxData = qQNaN(), mData.clear();
}

// virtual
DomStatus BaseIndi1MaskedFloatVector::load(const QQDomElement &de)
{
    QQDomDocument doc = de.ownerDocument();
    TRACEQFI << de.tagName() << doc.doctypeName();
    DomStatus status = eirXml::checkDoctypeNodeName(doctypeExpected(),
            "INDI Resource Data", expectedElementTag(), de);
    if (status.type().isError()) return status;                               /* /====\ */

    ElementAttributeMap attribs(de);
    status.expect("Contains Id(%1)", attribs.contains("Id"), QtInfoMsg, QtWarningMsg);
    if (attribs.contains("Id"))
        mId = attribs.value("Id").toInt();
    status.expect("Contains Count(%1)", attribs.contains("Count"), QtInfoMsg, QtWarningMsg);
    if (attribs.contains("Count"))
        mCount = attribs.value("Count").toInt();
    status.expect("Contains MinData(%1)", attribs.contains("MinData"), QtInfoMsg, QtWarningMsg);
    if (attribs.contains("MinData"))
        mMinData = attribs.value("MinData").toDouble();
    status.expect("Contains MaxData(%1)", attribs.contains("MaxData"), QtInfoMsg, QtWarningMsg);
    if (attribs.contains("MaxData"))
        mMaxData = attribs.value("MaxData").toDouble();
    TRACE << mId << mCount << mMinData << mMaxData;
    status.dump();

    DomStatus parseStatus = parseFloatVector(de);
    status.append(parseStatus);
    return status;
}

QQString BaseIndi1MaskedFloatVector::doctypeExpected() const
{
    return ResourceManager::doctypeExpected();
}

// protected
DomStatus BaseIndi1MaskedFloatVector::parseFloatVector(const QQDomElement &de)
{
    DomStatus status;
    status.info("Starting BaseIndi1MaskedFloatVector::parseFloatVector(%1) Count=%2",
                de.nodeName(), mCount);

    QQString deText = de.text();
    status.info("Parsing %1-byte Element text", deText.count());
    QTextStream deStream(&deText);
    FloatVector pixelVector;
    FloatPixel pixel;
    pixelVector.reserve(mCount);

    while (pixelVector.count() < mCount)
    {
        if (deStream.atEnd())
        {
            status.warn("End of data after %1 pixels");
            pixelVector.resize(mCount);
            break;                                                      /* /----\ */
        }
        deStream >> pixel;
        pixelVector.append(pixel);
    }                                                                   /* \----/ */
    mData = pixelVector;
    status.dump();
    return status;
}

/* ------------------------ debug ------------------------ */

QStringList BaseIndi1MaskedFloatVector::toDebugStrings() const
{
    QStringList result;
    result << QQString("{%1:BaseIndi1MaskedFloatVector>").arg(className());
    result << QQString("Id = %1, Count = %2").arg(mId).arg(mCount);
    result << QQString("MinData = %1, MaxData = %2").arg(mMinData).arg(mMaxData);
    if (mData.count() > 8)
        result << QQString("Data: %1 %2 %3 %4 %5 %6 %7 %8 ...")
                .arg(mData[0], 7, 'f', 4).arg(mData[1], 7, 'f', 4)
                .arg(mData[2], 7, 'f', 4).arg(mData[3], 7, 'f', 4)
                .arg(mData[4], 7, 'f', 4).arg(mData[5], 7, 'f', 4)
                .arg(mData[6], 7, 'f', 4).arg(mData[7], 7, 'f', 4);
    result << "<BaseIndi1MaskedFloatVector}";
    return result;
}

void BaseIndi1MaskedFloatVector::dump() const
{
    for (auto s : toDebugStrings()) DUMP << s;
}
