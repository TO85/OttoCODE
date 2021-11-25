#pragma once
#include "eirOpenCV.h"

// http://ninghang.blogspot.com/2012/11/list-of-mat-type-in-opencv.html

#include <QtGui/QImage>

class EIROPENCV_EXPORT cvMatType
{
private:
    enum Types
    {
        $nullType = -1,
        Grey8Type = 0,
        BGRA32Type = 24,
    };

public:
    cvMatType() : mType($nullType) {;}
    cvMatType(const int itype) { set(itype); }
    bool isNull() const { return Null() == mType; }
    bool isGrey8() const { return Grey8() == mType; }
    bool isBGRA32() const { return BGRA32() == mType; }
    operator int () const { return mType; }
    QImage::Format toQImageFormat() const;

    bool nullify() { return set(Null()); }
    bool setGrey8() { return set(Grey8()); }
    bool setBGRA32() { return set(BGRA32()); }

private:
    bool set(const int itype);

public: // static
    static int Null() { return $nullType; }
    static int Grey8() { return Grey8Type; }
    static int BGRA32() { return BGRA32Type; }
    static cvMatType fromQImage(const QImage &qi);

private:
    int mType=$nullType;
};

