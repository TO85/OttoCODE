/*! @file Uid.cpp Declare Uid class based upon QUuid
 *  @ingroup toBase
 *  @sa QtCore/QUuid
 */

#include "Uid.h"

#include <QtDebug>

/*! Creates a nil or random unique identification token
 */
Uid::Uid()
{
    mValues.oword = 0;
}

Uid::Uid(const bool create)
{
    set(create);
    qDebug() << Q_FUNC_INFO << trace();
}

Uid::Uid(const Type type, const Value value)
{
    Q_ASSERT(!"Done"); Q_UNUSED(type); Q_UNUSED(value);
}

bool Uid::isNull() const
{
    return 0 == mValues.oword;
}

bool Uid::isValid() const
{
    return mValues.valid;
}

OWORD Uid::whole() const
{
    return mValues.oword;
}

Uid::Half Uid::upper() const
{
    return mValues.qword[0];
}

Uid::Half Uid::lower() const
{
    return mValues.qword[1];
}

QUuid Uid::toUuid() const
{
    QUuid result;
    memcpy((BYTE *)(&result), &mValues.oword, sizeof(result));
    return result;
}

Uid::Id Uid::id() const
{
    return mValues.qword8;
}

Uid::Type Uid::type() const
{
    return Types((mValues.typeHi << 4) | mValues.typeLo);
}

Uid::Value Uid::value() const
{
    return mValues.dword0;
}

QString Uid::toString() const
{
    return toUuid().toString(QUuid::WithBraces).toUpper();
}

/*! Returns last 14 characters showing last portion of unique idenfifier
 *  @returns Fourteen character string in format "-XXXXXXXXXXXX}"
 */
QString Uid::tail() const
{
    return toString().right(14);
}

bool Uid::equal(const Uid &other) const
{
    return whole() == other.whole();
}

bool Uid::less(const Uid &other) const
{
    return whole() < other.whole();
}

Uid::Whole Uid::set(const bool create)
{
    it() = create ? createVersion4() : Uid();
    return whole();
}

Uid::Whole Uid::id(const Id aId)
{
    mValues.qword8 = aId;
    return whole();
}

Uid::Whole Uid::variant(const Variant aVariant)
{
    mValues.variant = aVariant;
    return whole();
}

Uid::Whole Uid::set(const Half upper, const Half lower)
{
    mValues.qword[0] = upper, mValues.qword[1] = lower;
    return whole();
}

Uid::Whole Uid::set(const Type type, const Value value)
{
    if (type)
        mValues.typeHi = (type & 0x00F0) << 4, mValues.typeLo = type & 0x000F;
    if (value)
        mValues.dword0 = value;
    return whole();
}

Uid::Whole Uid::create(const Type type, const Value value)
{
    set(true);
    return set(type, value);
}

/* --------------------------- static ------------------------ */

QRandomGenerator Uid::mGenerator;

void Uid::randomize(const Seed seed)
{
    mGenerator.seed(seed ? seed : QRandomGenerator::global()->generate());
}

Uid Uid::createVersion4(const Type type, const Value value)
{
    Uid result;
    result.set(mGenerator.generate64(), mGenerator.generate64());
    if ($nullType != type)
    {
        result.set(type, value);
    }
    result.mValues.valid = true;
    result.mValues.variant = VariantOttoCODE;
    result.mValues.version = 4;
    return result;
}

/* --------------------------- protected ------------------------ */

/* --------------------------- debug ------------------------ */


#if 0
/*! Creates a new unique identification token based upon text
 *  @param name Seeds generator
 */
Uid::Uid(const QByteArray &other)
{
    set(other);
    qDebug() << Q_FUNC_INFO << trace();
}

/*! Creates a new unique identification token based upon text
 *  @param name Seeds generator
 */
Uid::Uid(const QString name)
    : QUuid(name)
{
    qDebug() << Q_FUNC_INFO << trace();
}

Uid::Value Uid::set(const bool create)
{
    mUuid =  create ? QUuid::createUuid() : QUuid();
    memcpy(mValues.byte, )
}

Uid::Value Uid::set(const QByteArray &other)
{

}

Uid::Value Uid::set(const QString &fromString)
{

}

Uid::Value Uid::set(const Variant variant, const QByteArray name)
{

}

/*! Creates a new unique identification token based upon previous @a Uid and text
 *  @param base, name Seeds generator
 */
Uid::Uid(const Uid base, const QByteArray name)
    : QUuid(QUuid::createUuidV3(base, name))
{
    qDebug() << Q_FUNC_INFO << trace();

}

/*! Creates a new unique identification token based upon previous @a Uid and text
 *  @param base, name Seeds generator
 */
Uid::Uid(const Uid base, const QString name)
    : QUuid(QUuid::createUuidV3(base, name))
{
    qDebug() << Q_FUNC_INFO << trace();

}
#endif
