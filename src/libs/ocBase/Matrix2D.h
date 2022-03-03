#pragma once
#include "ocBase.h"

#include <QRect>

template <typename T> class OCBASE_EXPORT Matrix2D
{
public:
    Matrix2D() {;}

public:
    bool isEmpty() const { return mKeyTMap.isEmpty(); }

private:

    QList<T> mList;
};

