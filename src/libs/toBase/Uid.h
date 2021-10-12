#pragma once
/*! @file Uid.h Declare Uid class based upon QUuid
 *  @ingroup toBase
 *  @sa QtCore/QUuid
 */

#include <QtCore/QUuid>

#include <QtCore/QMetaType>

class Uid : public QUuid
{
public:
    Uid(const bool create);
    Uid(const QByteArray name);
    Uid(const QString name);
    Uid(const Uid base, const QByteArray name);
    Uid(const Uid base, const QString name);
    Uid() = default;
    Uid(const Uid &other) = default;
    Uid &operator = (const Uid &other) = default;
    ~Uid() = default;

public:
    QString tail();

public:
    QString trace() { return tail(); }
};

Q_DECLARE_METATYPE(Uid);



