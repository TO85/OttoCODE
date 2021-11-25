#pragma once
#include "eirType.h"

#include "DetectRect.h"

#include <QtCore/QMetaType>

#include "SCRectList.h"


class EIRTYPE_EXPORT DetectRectList : public DetectRect::List
{
public:
    DetectRectList() = default;
    DetectRectList(const QList<DetectRect> &other) : DetectRect::List(other) {;}
    DetectRectList(const DetectRectList &other) = default;
    ~DetectRectList() = default;
    DetectRectList &operator = (const DetectRectList &other) = default;

    DetectRectList it() const { return *this; }
    DetectRectList &it() { return *this; }

    SCRectList rectList() const;
    QVector<QRect> toQRectVector();
};

Q_DECLARE_METATYPE(DetectRectList);

