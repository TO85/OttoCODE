#pragma once

#include <QObject>

class Error : public QObject
{
    Q_OBJECT
public:
    explicit Error(QObject *parent = nullptr) : QObject(parent) {;}
    explicit Error(const char * pchFuncInfo, QObject *parent = nullptr) : QObject(parent) {;}

signals:

private:


};

