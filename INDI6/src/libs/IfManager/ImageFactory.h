#pragma once

#include <QObject>

#include <IfData/ResourceValues.h>

class ImageFactory : public QObject
{
    Q_OBJECT
public:
    explicit ImageFactory(QObject *parent = nullptr);
    explicit ImageFactory(const ResourceValues aValues, QObject *parent = nullptr);
    void set(const ResourceValues &aValues);

signals:


private:
    ResourceValues mValues;
};

