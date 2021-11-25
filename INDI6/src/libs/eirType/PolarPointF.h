#pragma once
#include "eirType.h"

#include <QtCore/QPair>
#include "Angle.h"

#include <QtCore/QMetaType>

#include "QQPoint.h"
#include "QQPointF.h"

class EIRTYPE_EXPORT PolarPointF
{
public:
    typedef qreal Radius;
    typedef QPair<Radius, Angle> RadiusAnglePair;

public:
    PolarPointF() = default;
    PolarPointF(const Radius aRadius, const Angle aAngle) : mRadius(aRadius), mAngle(aAngle) {;}
    PolarPointF(const QQPointF aCartesianPointF) { set(aCartesianPointF); }
    PolarPointF(const QQPoint aCartesianPoint) { set(aCartesianPoint); }
    PolarPointF(const PolarPointF &other) = default;
    PolarPointF &operator = (const PolarPointF &other) = default;
    ~PolarPointF() = default;

    Radius radius() const { return mRadius; }
    Angle angle() const { return mAngle; }
    PolarPointF &it() { return *this; }
    PolarPointF it() const { return *this; }

    RadiusAnglePair pair() const { return RadiusAnglePair(radius(), angle()); }
    QQPointF toPointF() const;
    QQPoint toPoint() const { return toPointF().toPoint(); }

    void set(const QQPointF aCartesianPointF);
    void set(const QQPoint aCartesianPoint) { set(aCartesianPoint.toPointF()); }
    void set(const Radius aRadius) { mRadius = aRadius; }
    void set(const Angle aAngle) { mAngle = aAngle; }
    void set(const RadiusAnglePair aPair) { mRadius = aPair.first, mAngle = aPair.second; }

private:
    Radius mRadius;
    Angle mAngle;
};

Q_DECLARE_METATYPE(PolarPointF);


