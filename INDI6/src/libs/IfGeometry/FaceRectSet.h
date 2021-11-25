#pragma once

#include <QtCore/QVector>
#include <QtGui/QTransform>

#include <eirType/SCRect.h>

class FaceRectSet
{
public:
    FaceRectSet() { staticCtor(); }
    FaceRectSet(const Type faceType, const SCRect rc) { staticCtor(); set(faceType, rc); }
    void set(const Type faceType, const SCRect rc);

private:
    static void staticCtor();
    static void setFullToTight();
    static void setFullToHead();
    static void setTightToFull();
    static void setTightToHead();

private:
    QVector<SCRect> mTypeRects;

    static QTransform smFullToTightXf;
    static QTransform smFullToHeadXf;
    static QTransform smTightToFullXf;
    static QTransform smTightToHeadXf;
};

