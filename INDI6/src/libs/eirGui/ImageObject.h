#pragma once

#include <QtCore/QObject>
#include "QQImage.h"

#include <QtCore/QHash>

#include <eirBase/Uid.h>


class ImageObject : public QObject, public QQImage
{
    Q_OBJECT
public:
    typedef QHash<Uid, ImageObject *> Hash;

public:
    explicit ImageObject(QObject *parent = nullptr);
    explicit ImageObject(const QQImage aImage, QObject *parent = nullptr);

signals:

private:

};

