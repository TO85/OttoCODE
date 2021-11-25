#pragma once
#include "eirGui.h"

#include <eirType/Rational.h>

class EIRGUI_EXPORT Hue : public Rational
{
public:
    Hue() = default;
    Hue(const Hue &other) = default;
    Hue(const int threesixty);
    Hue(const int n, const int d);
    Hue(const qreal tworadians);
    Hue(const quint8 twofiftyfive);
    ~Hue() = default;
    Hue &operator = (const Hue &other) = default;

    Hue normalized() const;

    void normalize();

private:
    Hue &it() { return *this; }
    Hue it() const  { return *this; }


public: // static
    static Hue white;
    static Hue black;
    static Hue red;
    static Hue blue;
    static Hue green;
    static Hue magenta;
    static Hue cyan;
    static Hue yellow;

};


Q_DECLARE_METATYPE(Hue)
