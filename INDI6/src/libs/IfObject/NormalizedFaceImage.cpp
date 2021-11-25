#include "NormalizedFaceImage.h"

#include <QtGui/QPainter>
#include <QtGui/QPixmap>

#include <eirGui/QQColor.h>
#include <eirGui/QQTransform.h>
#include <eirType/Angle.h>
#include <eirXfr/Debug.h>


QQSize NormalizedFaceImage::smNormalSize(128, 128);
EyeLine NormalizedFaceImage::smNormalEyeLine(QQPoint(47,50), QQPoint(81,50));

QQImage NormalizedFaceImage::masked(const QQBitArray &mask,
                                    const bool toGrey,
                                    const QQColor &maskColor,
                                    const QQColor &markColor)
{
    TRACEQFI << mask << toGrey << maskColor << markColor;
    AEXPECT(notNull());
    AEXPECTNOT(mask.isEmpty());
    AEXPECTNOT(mask.isZero());
    QQImage result = it();
    for (int y = 0, ix = 0; y < result.height() && ix < mask.count(); ++y, ++ix)
        for (int x = 0; y < result.width(); ++x)
        {
            if (mask.value(ix))
                result.setPixel(x, y, maskColor.rgba());
            else if (toGrey)
                result.setPixel(x, y, qGray(pixel(x, y)));

        }
    WANTUSE(markColor); // WANTDO(markEyes)
    return result;
}

QQImage NormalizedFaceImage::set(const QQImage &aFrameImage,
                                 const SCRect aFaceRect,
                                 const EyeLine aEline)
{
    mFrameImage = aFrameImage.convertedToColor();
    mFaceRect = aFaceRect;
    mEyeLine = aEline;
    calculate();
    return it();
}

// static
void NormalizedFaceImage::setNormalGeometry(const QQSize aSize, const EyeLine aLine)
{
    TRACEQFI << "was:" << smNormalSize << smNormalEyeLine
             << "new:" << aSize << aLine;
    smNormalSize = aSize;
    smNormalEyeLine = aLine;
}

void NormalizedFaceImage::calculate() // private
{
    TRACEQFI << "mFrameImage" << mFrameImage << "mFaceRect" << mFaceRect << "mEyeLine" << mEyeLine;
    TRACEQFI << "smNormalSize" << smNormalSize << "smNormalEyeLine" << smNormalEyeLine;

/* 1. OverCrop 50% from frame */
    const qreal overFactor = 1.500;
    const SCRect cropRect(mFaceRect.size() * overFactor, mFaceRect.center());
    const QQImage cropFaceImage = mFrameImage.crop(cropRect);
    TRACEQFI << "overFactor" << overFactor << "cropRect" << cropRect << "cropFaceImage" << cropFaceImage;

/* 2. Rotate for flat eyes (detected EyeLine) */
    const qreal radians = mEyeLine.slope().screenArcTangentRadians();
    mTransform.reset();
    mTransform.rotateRadians(radians);

/* 2.5. around EyeLine center */
    mTransform.translate(cropFaceImage.center().negated());
    const QQImage rotatedFaceImage = cropFaceImage.transformed(mTransform);
    TRACEQFI << "radians" << radians << "cropFaceImage.center().negated()" << cropFaceImage.center().negated()
             << "rotatedFaceImage" << rotatedFaceImage;
    mTransform.dump();

/* 3. Scale to match Normal eyewidth */
    const Rational eyeScale(smNormalEyeLine.distance(), mEyeLine.distance());
    const qreal scale = eyeScale.toReal();
    const QQImage scaledFaceImage = rotatedFaceImage.scaledBy(scale);
    TRACEQFI << "eyeScale" << eyeScale << "scale" << scale << "scaledFaceImage" << scaledFaceImage;

/* 4. Translate Vertically to match EyeLines */
    SCRect normalFaceRect(smNormalSize, scaledFaceImage.center());
//    normalFaceRect.center() -= QQPoint(0, csmNormalEyeLineF.left().y() * csmNormalSize.height());

/* 5. Final crop to Normal Size */
    const QQImage normalFaceImage = scaledFaceImage.crop(normalFaceRect);
    TRACEQFI << "normalFaceRect" << normalFaceRect << "normalFaceImage" << normalFaceImage;

//    it() = markCenterLines(normalFaceImage, smNormalEyeLine);
    it() = normalFaceImage;
}

QQImage NormalizedFaceImage::markCenterLines(const QQImage &aImage, const QQLine aLine) const
{
    const QQImage markImage = aImage.convertedToColor();
    QPainter painter;
    QPen centerPen(Qt::red); centerPen.setWidth(1);
    centerPen.setStyle(Qt::PenStyle::DashDotLine);
    painter.begin((QPaintDevice *)(&markImage));
    painter.setPen(centerPen);
    const QQRect markRect = aImage.rect().toRect();
    painter.drawLine(markRect.centerLine());
    painter.drawLine(markRect.middleLine());
    if (aLine.notNull())
    {
        QPen linePen(Qt::blue);
        linePen.setWidth(1);
        linePen.setStyle(Qt::DotLine);
        painter.setPen(linePen);
        QQLine markLine = aLine + aImage.rect().center();
        painter.drawLine(markLine);
        painter.setPen(Qt::NoPen);
    }
    painter.end();
    return markImage;
}
