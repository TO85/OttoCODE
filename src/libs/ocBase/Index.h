#pragma once
#include "ocBase.h"


class OCBASE_EXPORT Index
{
public:
    Index() {;}
    Index(const int nItems) : mMinIndex(0), mMaxIndex(nItems - 1) {;}

public:
    int origin() const { return mMinIndex; }
    int count() const { return mMaxIndex - mMinIndex; }
    bool isValid(const int ix) const { return ix >= mMinIndex && ix <= mMaxIndex; }

public:
    void set(const int nItems, const int origin=0) { mMinIndex = origin, mMaxIndex = nItems - 1; }

private:
    int mMinIndex=0;
    int mMaxIndex=0;
};

