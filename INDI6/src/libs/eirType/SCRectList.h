#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>

#include "SCRect.h"
#include "QQList.h"
#include "QQStringList.h"

class EIRTYPE_EXPORT SCRectList : public SCRect::List
{
public:
    typedef QMutableListIterator<SCRect> MutableIterator;

public:
    SCRectList() = default;
    SCRectList(const QList<SCRect> &other, const bool reversed)
        : QQList<SCRect>(other) { if (reversed) reverse();}
    SCRectList(const SCRectList &other) = default;
    ~SCRectList() = default;
    SCRectList &operator = (const SCRectList &other) = default;

public:
    SCRect at(const int ix) const;
    bool notEmpty() const { return ! isEmpty(); }
    bool isValidIndex(const int ix) const { return ix >= 0 && ix < count(); }
    QQStringList toStringList() const;
    QVector<QRect> toQRectVector() const;
    SCRect unified() const;

public:
    SCRect &at(const int ix);

private:
    SCRectList &it() { return *this; }
    SCRectList it() const { return *this; }

public:
};

Q_DECLARE_METATYPE(SCRectList);

extern EIRTYPE_EXPORT QDebug operator<<(QDebug dbg, const SCRectList &scrcs);
