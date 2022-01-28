/*! @file Uid.cpp Declare Uid class based upon QUuid
 *  @ingroup toBase
 *  @sa QtCore/QUuid
 */

#include "Uid.h"

#include <QtDebug>

/*! Creates a nil or random unique identification token
 */
Uid::Uid(const bool create)
{
    set(create);
    qDebug() << Q_FUNC_INFO << trace();
}

Uid::Value Uid::set(const bool create)
{
    mUuid = create ? QUuid::createUuid() : QUuid();
    return setValue();
}

QString Uid::toString() const
{
    return mUuid.toString(QUuid::WithBraces);
}


/*! Returns last 14 characters showing last portion of unique idenfifier
 *  @returns Fourteen character string in format "-XXXXXXXXXXXX}"
 */
QString Uid::tail() const
{
    return toString().right(14);
}

Uid::Value Uid::setValue()
{
    memcpy(mValues.byte, mUuid.toRfc4122(), sizeof(mValues));
    return mValues.oword;
}
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
