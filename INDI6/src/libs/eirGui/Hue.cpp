#include "Hue.h"

Hue Hue::white;
Hue Hue::black;
Hue Hue::red(0);
Hue Hue::yellow(60);
Hue Hue::green(120);
Hue Hue::cyan(180);
Hue Hue::blue(240);
Hue Hue::magenta(300);

Hue::Hue(const int threesixty) : Rational(threesixty, 360) {;}
Hue::Hue(const int n, const int d) : Rational(n, d) {;}
Hue::Hue(const qreal tworadians) : Rational(tworadians / (2.0 * M_PI), 360) {;}
Hue::Hue(const quint8 twofiftyfive) : Rational(qreal(twofiftyfive) / 255.0 * 360.0, 360) {;}

void Hue::normalize()
{
    Rational::set(normalized());
}

Hue Hue::normalized() const
{
    return Hue(numerator() % denominator(), denominator());
}

