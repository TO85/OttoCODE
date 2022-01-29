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

Uid::Value Uid::value() const
{
    return mValues.oword;
}

QUuid Uid::toUuid() const
{
    QUuid result;
    memcpy((BYTE *)(&result), &mValues.oword, sizeof(result));
    return result;
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

Uid::Value Uid::set(const bool create)
{
    it() = create ? createVersion4() : Uid();
    return value();
}

Uid::Value Uid::set(const Half upper, const Half lower)
{
    mValues.qword[0] = upper, mValues.qword[1] = lower;
    return value();
}

/* --------------------------- static ------------------------ */

QRandomGenerator Uid::mGenerator;

void Uid::randomize(const Seed seed)
{
    mGenerator.seed(seed ? seed : QRandomGenerator::global()->generate());
}

Uid Uid::createVersion4(const DWORD type, const QWORD seq)
{
    Uid result;
    result.set(mGenerator.generate64(), mGenerator.generate64());
    if ($nullType != type)
    {
        const NIBBLE typeHi = (type & 0b11110000) >> 4, typeLo = type & 0b00001111;
        result.mValues.typeHi = typeHi, result.mValues.typeLo = typeLo;
    }
    if (seq) result.mValues.qword8 = seq;
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
