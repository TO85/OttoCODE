#pragma once

#include <QtCore/QList>

#include <eirType/SCRect.h>
#include <eirType/SCRectList.h>

#include "EyeLine.h"
#include "EyeLineF.h"

class EyeLineResults
{
public:
    class Item
    {
    public:
        typedef QList<Item> List;
    public:
        Item() {;}
        Item(const EyeLine eline, const SCRect facerect) { set(eline, facerect); }
        Item(const SCRect leye, const SCRect reye, const SCRect facerect) { set(leye, reye, facerect); }
        void set(const EyeLine eline, const SCRect frect);
        void set(const SCRect leye, const SCRect reye, const SCRect frect);

    private:
        EyeLine mEyeLine;
        SCRect mFaceRect;
        EyeLineF mRelativeEyeLine;
        SCRect mLeftEyeRect;
        SCRect mRightEyeRect;
    };

public:
    EyeLineResults() {;}
    EyeLineResults(const SCRect &faceRect) : mFaceRect(faceRect) {;}

    SCRect faceRect() const { return mFaceRect; }

    void clear() { mFaceRect.nullify(), mItemList.clear(); }
    void setFaceRect(const SCRect &faceRect) { mFaceRect = faceRect; }
    void append(const SCRectList detectedEyes);
    void append(const EyeLine eline);
    void append(const EyeLine::List elines);

private:
    SCRect mFaceRect;
    Item::List mItemList;
};

