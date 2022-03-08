#pragma once
#include "ocExe.h"

#include <QObject>

class OCEXE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = nullptr);

signals:

};

