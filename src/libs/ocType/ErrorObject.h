#pragma once

#include <QObject>

class ErrorObject : public QObject
{
    Q_OBJECT
public:
    explicit ErrorObject(QObject *parent = nullptr) : QObject(parent) {;}
    explicit ErrorObject(const char * pchFuncInfo, QObject *parent = nullptr) : QObject(parent) {;}

signals:

private:


};

