#pragma once
#include "IfObject.h"

#include <eirType/PerMille.h>

#include <QtCore/QMetaType>

#include <IfGeometry/EyeLine.h>

class IFOBJECT_EXPORT Quality
{
public:
    Quality() {;}
    Quality(const qreal r) : mDistance(r), mQuality(qualityForDistance(mDistance)) {;}
    Quality(const Rational r) : mDistance(r.toReal()), mQuality(qualityForDistance(mDistance)) {;}
    Quality(const unsigned u) { setQuality(u); }

    qreal distance() const { return mDistance; }
    unsigned quality() const { return mQuality; }
    void setDistance(const qreal aDistance);
    void setQuality(const unsigned aQuality);

    bool isNull() const { return 0 == mQuality || qIsNull(mDistance); }
    bool less(const unsigned u) const { return quality() < u; }
    operator unsigned () const { return quality(); }
    unsigned operator () () const { return qBound(1U, quality(), 999U); }
    bool operator < (const unsigned u) const { return less(u); }

    void nullify() { mDistance = 0.0, mQuality = 0; }

public: // static
    static unsigned qualityForDistance(const qreal distance);
    static qreal distanceForQuality(const unsigned aMille);

private:
    qreal mDistance=0.0;
    unsigned mQuality=0U;
};

Q_DECLARE_METATYPE(Quality);

