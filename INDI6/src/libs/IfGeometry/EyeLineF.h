#pragma once

#include <eirType/QQLineF.h>

#include <eirType/QQPointF.h>

class EyeLineF : public QQLineF
{
public:
    EyeLineF();
    EyeLineF(const QQLineF other) : QQLineF(other) {;}
    EyeLineF(const QQPointF leye, const QQPointF reye) : QQLineF(leye, reye) {;}
    QQPointF left() const { return p1();}
    QQPointF right() const { return p2();}
};

