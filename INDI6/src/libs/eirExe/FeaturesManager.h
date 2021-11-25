#pragma once

#include <QObject>

#include <eirType/BasicName.h>
#include <eirXfr/Debug.h>

class FeaturesManager : public QObject
{
    Q_OBJECT

public:
    class Item
    {
    public:
        Item()  { NEEDDO(it); }
        bool isNull()  { NEEDDO(it); return true; }
        bool canDo() const  { NEEDDO(it); return true; }

    private:
    };

public:
    explicit FeaturesManager(QObject *parent = nullptr);
    Item feature(const BasicName fname)  { NEEDDO(it); NEEDUSE(fname); return Item(); }
    bool canDo(const BasicName fname) { return feature(fname).canDo(); }

signals:

};

