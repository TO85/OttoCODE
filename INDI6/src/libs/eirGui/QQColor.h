#pragma once
#include "eirGui.h"

#include <eirType/QQString.h>

class EIRGUI_EXPORT QQColor : public QColor
{
public:
    typedef QVector<QQColor> Vector;
public:
    QQColor() = default;
    QQColor(const QColor &other) : QColor(other) {;}
    QQColor(const QRgb &orgb) : QColor(orgb) {;}
    QQColor(const Qt::GlobalColor qtgc) : QColor(qtgc) {;}
    QQColor(const QQString &name) : QColor(name) {;}
    QQColor(const char *psz) : QColor(QQString(psz)) {;}
    QQColor(const QColor::Spec aSpec, const qreal aHue, const qreal aSaturation,
                                      const qreal aValue, const qreal aOpacity);
    QQColor(const QQColor &other) = default;
    ~QQColor() = default;
    QQColor &operator = (const QQColor &other) = default;

    qreal opacityF() const { return alphaF(); }
    void setOpacityF(const qreal aOpacity) { setAlphaF(aOpacity); }

    QQColor overlayed(const QQColor &aOverlay, const bool useBaseOpacity=false) const;

    QQColor divided(const int aDivisor) const;
    QQColor operator / (const int aDivisor) const { return divided(aDivisor); }


private:
    QQColor it() const { return *this; }
    QQColor &it() { return *this; }
};


Q_DECLARE_METATYPE(QQColor);
