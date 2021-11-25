#include "ColorWheel.h"

#include <eirXfr/Debug.h>

ColorWheel::ColorWheel() {;}
ColorWheel::ColorWheel(const qreal baseOpacity) : mBaseOpacity(baseOpacity) {;}

void ColorWheel::set(const int count, const Hue begin, const Hue end)
{
    qreal beginHueF = begin.toReal();
    qreal endHueF = end.toReal();
    qreal deltaHueF = beginHueF < endHueF ? endHueF - beginHueF : beginHueF + 1.0 - endHueF;
    qreal incrementF = deltaHueF / qreal(count);
    TRACEQFI << count << beginHueF << endHueF << deltaHueF << incrementF;
    mColorVector = QQColor::Vector(count, QColor());
    for (int k = 0; k < count; ++k)
    {
        qreal hueF = beginHueF + k * incrementF;
        hueF = (hueF < 1.0) ? hueF : (hueF - 1.0);
        QQColor color(QQColor::Hsv, hueF, mBaseSaturation, mBaseValue, mBaseOpacity);
        TRACE << k << hueF << color << color.toRgb();
        mColorVector[k] = color;
    }
}

void ColorWheel::setQuality(const Hue begin, const Hue end)
{
    set(250, begin, end);
}

QQColor ColorWheel::at(const unsigned index, const unsigned count) const
{
    unsigned n = size();
    unsigned x = index % n;
    if (count && count < n) x *= n / count;
    TRACEQFI << index << size() << index % size() << x << n;
    Q_ASSERT(n > 0 && x < n);
    QQColor c;
    if (n > 0) c = mColorVector.at(x);
    TRACE << c << c.toRgb();
    return c;
}

QQColor ColorWheel::quality(const int q) const
{
    return at(q/4);
}

QRgb ColorWheel::rgba(const int index)
{
    return at(index).rgba();
}
