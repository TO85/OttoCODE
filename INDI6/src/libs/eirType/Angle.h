#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>

#include "Rational.h"

class EIRTYPE_EXPORT Angle : public Rational
{
public:
    Angle() = default;
    Angle(const Term rise, const Term run) : Rational(rise, run) {;}
    Angle(const qreal inRadians) : Rational(inRadians) {;}
    Angle(const signed inDegrees) : Rational(inDegrees) {;}
    Angle(const Angle &other) = default;
    ~Angle() = default;
    Angle &operator = (const Angle &other) = default;

    qreal screenArcTangentRadians() const;
    bool isPositiveVertical() const { return isNaN() && numerator() > 0.0; }
    bool isNegativeVertical() const { return isNaN() && numerator() < 0.0; }
    bool isVertical() const { return isNaN(); }
    bool isFlat() const { return isZero(); }

private:
    Angle(const qreal nf, const Rational::Term du) : Rational(nf, du) { normalizeSign(); }
    void initComments();

public: // static
    static Angle fullCircle() { return Angle(scmFullCircleRadians, 1000000000000000LL); }
    static Angle halfCircle() { return Angle(scmHalfCircleRadians, 1000000000000000LL); }
    static Angle quarterCircle() { return Angle(scmQuarterCircleRadians, 1000000000000000LL); }
    static Angle eighthCircle() { return Angle(scmEighthCircleRadians, 1000000000000000LL); }

    static int degreesFromRadians(const qreal aRadians) { return qRound(degreesFromRadiansF(aRadians)); }
    static qreal degreesFromRadiansF(const qreal aRadians);

private:
    static const qreal scmFullCircleRadians;
    static const qreal scmHalfCircleRadians;
    static const qreal scmQuarterCircleRadians;
    static const qreal scmEighthCircleRadians;
};

Q_DECLARE_METATYPE(Angle);



