#include "ResourceBitMask.h"

ResourceBitMask::ResourceBitMask(const ResourceType aType, const QQDomElement &aDE)
    : AbstractResource(aType, aDE)
{
    TRACEQFI << aDE;
    if (aDE.notNull()) parse();
}

QQStringList ResourceBitMask::toDebugStrings() const
{
    QQStringList result;
    result << QQString("{ResourceBitMask:>");
    result << AbstractResource::toDebugStrings();
    result << QQString("Size=%1 EyeLine=%2")
              .formatMessage(mSize.toDebugString(), mEyeLine.toDebugString());
    if (mSize.isEmpty() || mEyeLine.isEmpty() || mEyeLine.isEitherNull())
        return result;                                                  /* /====\ */
    result << mBits.toStrings(4);
    result << QQString("<ResourceBitMask}");
    return result;
}

/* -------------------------- getters/[re]setters -------------------------- */

void ResourceBitMask::resetSize()
{
    setSize(QQSize());
}

const EyeLine &ResourceBitMask::eyeLine() const
{
    return mEyeLine;
}

void ResourceBitMask::setEyeLine(const EyeLine &newEyeLine)
{
    mEyeLine = newEyeLine;
}

void ResourceBitMask::resetEyeLine()
{
    setEyeLine(EyeLine());
}

const BooleanString &ResourceBitMask::booleanString() const
{
    return mBooleanString;
}

void ResourceBitMask::resetBooleanString()
{
    mBooleanString = BooleanString(QQString());
}

void ResourceBitMask::resetBits()
{
    mBits = QBitArray();
}

const QQSize &ResourceBitMask::size() const
{
    return mSize;
}

void ResourceBitMask::setSize(const QQSize &newSize)
{
    mSize = newSize;
}

/* ----------------------- AbstractResource interface ----------------------- */

bool ResourceBitMask::isNull() const
{
    if (AbstractResource::isNull()) return true;
    if (mBits.isNull() || mBits.isEmpty()) return true;
    return false;
}

bool ResourceBitMask::isValid() const
{
    if (isNull()) return false;
    NEEDDO(others); // NEEDDO(others)
    return true;
}

bool ResourceBitMask::parse()
{
    // Preconditions
    EXPECT(contains("BitCount"));
    EXPECT(contains("Width"));
    EXPECT(contains("Height"));
    const int tBitCount = attributeInt("BitCount");
    const int tWidth = attributeInt("Width");
    const int tHeight = attributeInt("Height");
    const QQSize tSize(tWidth, tHeight);
    const QQString tString(text(), QQString::Squeeze);
    TRACEQFI << tBitCount << tWidth << tHeight << tSize;
    DUMPVAL(tString.split(tWidth));
    // Sanity
    EXPECTEQ(AbstractResource::pixelCount(), tBitCount);
    EXPECTEQ(AbstractResource::normalSize(), tSize);
    EXPECTEQ(AbstractResource::normalSize().area(), tString.count());

    mBooleanString = BooleanString(tString);

    // Postconditions
    EXPECT(notEmpty());
    TRACE << AbstractResource::normalSize() << tString.count() << mBooleanString.bits().count();
    EXPECTEQ(AbstractResource::normalSize().area(), tString.count());
    EXPECTEQ(AbstractResource::normalSize().area(), mBooleanString.bits().count());
    TRACE << tBitCount << mBooleanString.count(true);
    EXPECTEQ(tBitCount, mBooleanString.count(true));
    if (AbstractResource::normalSize().area() != tString.count()) return false;
    if (AbstractResource::normalSize().area() != mBooleanString.bits().count()) return false;
    if (tBitCount != mBooleanString.count(true)) return false;
    mBits = mBooleanString.bits();
    return true;
}

#if 0
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
#endif

QQStringList ResourceBitMask::toInfoStrings(const int level) const
{
    QQStringList result = AbstractResource::toInfoStrings(level);
    result << QQString("Size: %1").formatMessage(size().toString());
    result << QQString("Line: %1").formatMessage(eyeLine().toDebugString());
    result << QQString("Bits: %1").formatMessage(bits().count(true));
    return result;
}


QDebug operator << (QDebug dbg, const ResourceBitMask rbm)
{
    foreach ( QQString s, rbm.toDebugStrings()() )
        dbg << s << Qt::endl;
    return dbg;
}
