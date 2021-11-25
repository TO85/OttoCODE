#include "QQColor.h"

#include <eirXfr/Debug.h>

QQColor::QQColor(const QColor::Spec aSpec, const qreal aHue,
                 const qreal aSaturation, const qreal aValue, const qreal aOpacity)
{
    setHsvF(aHue, aSaturation, aValue, aOpacity);
    if (spec() != aSpec) it() = convertTo(aSpec);
}

QQColor QQColor::overlayed(const QQColor &aOverlay, const bool useBaseOpacity) const
{
    QQColor result;
    result.setOpacityF(1.0);
    qreal overOpacity = aOverlay.opacityF();
    qreal baseOpacity = 1.0 - overOpacity;
    if (useBaseOpacity)
    {
        baseOpacity = opacityF();
        qreal totalOpacity = baseOpacity + overOpacity;
        baseOpacity = baseOpacity  / totalOpacity;
        overOpacity = overOpacity  / totalOpacity;
    }
    result.setRedF(  baseOpacity * redF()   + overOpacity * aOverlay.redF());
    result.setGreenF(baseOpacity * greenF() + overOpacity * aOverlay.greenF());
    result.setBlueF( baseOpacity * blueF()  + overOpacity * aOverlay.blueF());
    return result;
}

QQColor QQColor::divided(const int aDivisor) const
{
    QQColor result;
    result.setAlpha(alpha()),
    result.setRed(red() / aDivisor),
    result.setBlue(blue() / aDivisor),
    result.setGreen(green() / aDivisor);
    return result;
}
