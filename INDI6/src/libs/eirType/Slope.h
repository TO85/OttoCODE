#pragma once
#include "eirType.h"

#include "Angle.h"

#include <QtCore/QMetaType>

class EIRTYPE_EXPORT Slope : public Angle
{
public:
    Slope() = default;
    Slope(const Term rise, const Term run) : Angle(rise, run) {;}
    Slope(const Slope &other) = default;
    ~Slope() = default;
    Slope &operator = (const Slope &other) = default;

    int rise() const { return numerator(); }
    int run() const { return denominator(); }
};

Q_DECLARE_METATYPE(Slope);

