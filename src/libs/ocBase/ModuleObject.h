#pragma once

#include <QObject>

class ModuleObject : public QObject
{
    Q_OBJECT
public:
    enum Type
    {
        $null = 0,
        Library,
        Plugin,
        Console,
        Desktop,
        Service,
        $count
    };
    Q_ENUM(Type);

public:
    explicit ModuleObject(const Type aType=$null, QObject *parent = nullptr);

signals:

};

