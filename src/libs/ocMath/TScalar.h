#pragma once
/*! \file TScalar.h Declaration for UnitFloat template
 */

template<typename T> class Scalar
{
    Scalar() : mT(0) {;}
    Scalar(const T &aT) : mT(aT) {;}

private:
    T mT;
};
