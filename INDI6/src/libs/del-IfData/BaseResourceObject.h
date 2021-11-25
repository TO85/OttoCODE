#pragma once
#include "IfData.h"

#include <QObject>
#include "ResourceInterface.h"


class BaseResourceObject : public QObject, public ResourceInterface
{
    Q_OBJECT
public:
    ~BaseResourceObject() {;}

protected:
    explicit BaseResourceObject(QObject *parent = nullptr);

signals:

private:

};

