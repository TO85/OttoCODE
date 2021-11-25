#pragma once
#include "IfGeometry.h"

#include <eirType/QQLine.h>

class IFGEOMETRY_EXPORT EyeLine : public QQLine
{
public:
    typedef QList<EyeLine> List;

public:
    EyeLine() {;}
    EyeLine(const QQLine ln) : QQLine(ln) {;}
    EyeLine(const QPoint lpt, const QPoint rpt) : QQLine(lpt, rpt) {;}
    QPoint left() const { return p1(); }
    QPoint right() const { return p2(); }

};

