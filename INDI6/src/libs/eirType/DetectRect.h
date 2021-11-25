#pragma once
#include "eirType.h"

#include <QtDebug>
#include <QtCore/QMetaType>
#include <QtCore/QMultiMap>

#include "ObjectType.h"
#include "QQList.h"
#include "QQRect.h"
#include "QQRectF.h"
#include "Rational.h"
#include "SCRect.h"

class EIRTYPE_EXPORT DetectRect
{
public:
    typedef SCRect Rect;
    typedef int Score;
    typedef QQList<DetectRect> List;
    typedef QMultiMap<Score, DetectRect> Map;

public:
    DetectRect() = default;
    DetectRect(const DetectRect &other) = default;
    DetectRect(const ObjectType &aType,  const Rect aRect=Rect(),
               const Score aScore=0) :  mType(aType), mRect(aRect), mScore(aScore) {;}
    DetectRect(const ObjectType &aType,  const Rect aBaseRect, const Rect aRect,
               const Score aScore=0) :  mType(aType), mBaseRect(aBaseRect), mRect(aRect), mScore(aScore) {;}
    ~DetectRect() = default;
    DetectRect &operator = (const DetectRect &other) = default;

    Rect rect() const { return mRect; }
    Rect &rect() { return mRect; }
    Rect base() const { return mBaseRect; }
    Score score() const { return mScore; }
    Score &score() { return mScore; }
    ObjectType type() const { return mType; }
    DetectRect it() const { return *this; }
    DetectRect &it() { return *this; }

    bool isNull() const { return rect().isNull(); }
    QQPoint topLeft() const { return toRect().topLeft(); }
    QQRect toRect() const { return rect().toRect(); }
    operator QQRect () const { return toRect(); }

    void setRect(const Rect aRect) { mRect = aRect; }
    DetectRect &setScore(const Score aScore) { mScore = aScore; return it(); }
    void setType(const ObjectType aType) { mType = aType; }
    void nullify() { setRect(Rect()); }
    void unite(const DetectRect other);

    QString toDebugString() const;

private:
    ObjectType mType=ObjectType::$null;
    Rect mBaseRect;
    Rect mRect;
    Score mScore=0;
};

Q_DECLARE_METATYPE(DetectRect);

template class QQList<DetectRect>;

extern EIRTYPE_EXPORT bool operator == (const DetectRect &lhs, const DetectRect &rhs);
extern EIRTYPE_EXPORT uint qHash(const DetectRect &dr, uint seed);
extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const DetectRect &dr);
