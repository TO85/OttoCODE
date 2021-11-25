#pragma once
#include "eirType.h"

#include "DetectRect.h"

#include <QtCore/QMetaType>

#include <eirBase/QtTypes.h>

#include "DetectRectList.h"
#include "QQStringList.h"

class EIRTYPE_EXPORT DetectRectMap : public DetectRect::Map
{
public:
    DetectRectMap() = default;
    DetectRectMap(const DetectRectMap &other) = default;
    ~DetectRectMap() = default;
    DetectRectMap &operator = (const DetectRectMap &other) = default;

    DetectRectMap it() const { return *this; }
    DetectRectMap &it() { return *this; }

    bool notEmpty() const { return ! isEmpty(); }
    int maxScore() const { return mMaxScore; }
    DetectRectList list(const bool reversed=false) const;
    DetectRect united() const;
    QRectVector toQRectVector() const;

    void setMaxScore(int aScore) { mMaxScore = aScore; }
    void append(const DetectRect aDRect) { insert(aDRect.score(), aDRect); }
    void append(const DetectRectList &aDRectList);
    void operator << (const DetectRect aDRect) { append(aDRect); }

    QQStringList toDebugStrings() const;

private:
    int mMaxScore;
};

