
#pragma once
#include "eirGui.h"

#include <eirType/QQSize.h>

class EIRGUI_EXPORT QQPixmap : public QPixmap
{
public:
    QQPixmap() = default;
    QQPixmap(const QQSize aSize, const bool aBool=false) : QPixmap(aSize) { set(aBool); }
    QQPixmap(const QQPixmap &other) = default;
    ~QQPixmap() = default;
    QQPixmap &operator = (const QQPixmap &other) = default;

    void set(const bool aBool) { if (aBool) fill(); else fill(Qt::transparent); }

};

Q_DECLARE_METATYPE(QQPixmap);
