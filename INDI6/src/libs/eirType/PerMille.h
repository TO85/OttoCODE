#pragma once

#include "Rational.h"

#include <QtCore/QMetaType>


class EIRTYPE_EXPORT PerMille : public Rational
{
public:
    PerMille() = default;
    PerMille(const Rational::Term i1000) : Rational(i1000, 1000) {;}
    PerMille(const qreal f) : Rational(f, 1000) {;}
    PerMille(const PerMille &other) = default;
    ~PerMille() = default;
    PerMille &operator=(const PerMille &other) = default;

    qreal toReal() const { return Rational::toReal(0.0) ;}
    int toMille() const { return qRound(toReal() * 1000.0);}
    operator qreal () const { return toReal(); }
    operator int () const { return toMille(); }

    void set(const int i1000) { Rational::set(i1000, 1000); }
};

Q_DECLARE_METATYPE(PerMille);
