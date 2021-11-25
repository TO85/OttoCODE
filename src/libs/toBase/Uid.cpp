/*! @file Uid.cpp Declare Uid class based upon QUuid
 *  @ingroup toBase
 *  @sa QtCore/QUuid
 */

#include "Uid.h"

#include <QtDebug>

/*! Creates a null or random unique identification token
 */
Uid::Uid(const bool create)
    : QUuid(create ? QUuid::createUuid() : QUuid())
{
    qDebug() << Q_FUNC_INFO << trace();
}

/*! Creates a new unique identification token based upon text
 *  @param name Seeds generator
 */
Uid::Uid(const QByteArray name)
    : QUuid(name)
{
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

/*! Returns last 14 characters showing last portion of unique idenfifier
 *  @returns Fourteen character string in format "-XXXXXXXXXXXX}"
 */
QString Uid::tail()
{
    return toString(StringFormat::WithBraces).right(14);
}
