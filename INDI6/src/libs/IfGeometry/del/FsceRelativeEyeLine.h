#pragma once
#include "IfGeometry.h"

#include <eirType/QQLineF.h>

#include <eirType/SCRect.h>

#include "EyeLine.h"

class IFGEOMETRY_EXPORT FsceRelativeEyeLine : public QQLineF
{
public:
    FsceRelativeEyeLine() {;}
    FsceRelativeEyeLine(const EyeLine el, const SCRect relface);
    FsceRelativeEyeLine(const QPoint le, const QPoint re, const SCRect relface)
        : FsceRelativeEyeLine(EyeLine(le, re), relface) {;}
    QPointF left() const { return p1(); }
    QPointF right() const { return p2(); }
    int faceWidth() const { return mRelativeFace.width(); }

private:
    SCRect mRelativeFace;
};

