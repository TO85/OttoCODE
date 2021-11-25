#include "BaseIndi1BitMask.h"

#include <eirType/BooleanString.h>
#include <eirType/Success.h>
#include <eirXml/QQDomDocument.h>
#include <eirXml/QQDomElement.h>
#include <eirXml/ElementAttributeMap.h>

#include "ResourceManager.h"

bool BaseIndi1BitMask::isNull() const
{
    Success success;
    success.expect(bits().isNull());
    success.expect(bits().isEmpty());
    success.expect(size().isNull());
    success.expect(size().isEmpty());
    success.expectNot(0 == mActivePixels);
    success.expect(mEyeLine.isNull());
    return ! success;
}

QQImage BaseIndi1BitMask::maskNormalImage(const QQImage &aImage,
                                          const QColor maskColor) const
{
    TRACEQFI << aImage << maskColor;
    AEXPECTNOT(isNull());
    AEXPECTNOT(aImage.isNull());
    WEXPECT(maskColor.isValid());
//    AEXPECTEQ(32, aImage.depth());
  //  AEXPECT(aImage.isContinuous());
    QQImage result(aImage);
    for (int row = 0; row < result.height(); ++row)
        for (int col = 0; col < result.width(); ++col)
            if ( ! mBits.value(QQPoint(col, row)))
                result.setPixelColor(col, row, maskColor);
    return result;
    /*
    if (aImage.isContinuous())
    {
        if (32 == aImage.depth())
            result = maskContinous32bit(aImage, maskColor);
    }
    DUMPVAL(result);
    AEXPECT(result.notNull());
    return result;
    */
}

// virtual
DomStatus BaseIndi1BitMask::load(const QQDomElement &de)
{
    QQDomDocument doc = de.ownerDocument();
    TRACEQFI << de.tagName() << doc.doctypeName();
    de.dump();
    DomStatus status = eirXml::checkDoctypeNodeName(doctypeExpected(),
            "INDI BitMasks Data", expectedBitMaskTag(), de);
    if (status.type().isError()) return status;                               /* /====\ */

    ElementAttributeMap attribs(de);
    status.expect("Contains BitCount(%1)", attribs.contains("BitCount"), QtInfoMsg, QtWarningMsg);
    int tBitCount = attribs.value("BitCount").toInt();
    status.expect("Contains Width(%1)", attribs.contains("Width"), QtInfoMsg, QtWarningMsg);
    const int tWidth = attribs.value("Width").toInt();
    status.expect("Contains Height(%1)", attribs.contains("Height"), QtInfoMsg, QtWarningMsg);
    const int tHeight = attribs.value("Height").toInt();

    const QQSize maskSize(tWidth, tHeight);
    TRACE << tBitCount << maskSize;

    BooleanString bs(de.text());
    mBits = bs.bits();
    mSize = maskSize;
    mActivePixels = mBits.count(true);
    if (maskSize.area() != bs.count())
    {
        status.warn("Size Mismatch: Expected=%1x%2 (%3), Actual=%%4 (using Expected)",
                    maskSize.width(), maskSize.height(), maskSize.area(), bs.count());
        mBits.resize(mSize.area());
        mActivePixels = mBits.count(true);
    }
    if (mActivePixels != tBitCount)
    {
        status.warn("BitCount Mismatch: Expected=%1, Actual=%2 (using Actual)", tBitCount, mActivePixels);
    }

    TRACE << mBits.count() << mBits.size() << mBits.size().area() << mSize
          << mBits.count(true) << mBits.count(false) << mBits.count(true) + mBits.count(false);
    status.dump();
    return status;
}

void BaseIndi1BitMask::clear()
{
    mBits.clear();
    mActivePixels = 0;
    mSize.nullify();
    mEyeLine.nullify();
}

QQString BaseIndi1BitMask::doctypeExpected() const
{
     return ResourceManager::doctypeExpected();
}

/* --------------------------- private --------------------------- */

