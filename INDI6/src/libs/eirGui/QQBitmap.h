#pragma once
#include "eirGui.h"


#include <eirType/QQSize.h>

class EIRGUI_EXPORT QQBitmap : public QBitmap
{
public:
    QQBitmap() = default;
    QQBitmap(const QQSize aSize, const bool aBool=false) : QBitmap(aSize) { set(aBool); }
    QQBitmap(const QQBitmap &other) = default;
    ~QQBitmap() = default;
    QQBitmap &operator = (const QQBitmap &other) = default;

    void set(const bool aBool) { if (aBool) fill(Qt::color1); else clear(); }

};

Q_DECLARE_METATYPE(QQBitmap);
