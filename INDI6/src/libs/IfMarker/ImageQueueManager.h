#pragma once

#include <QObject>

class ImageQueueManager : public QObject
{
    Q_OBJECT
public:
    explicit ImageQueueManager(QObject *parent = nullptr);

signals:

};

