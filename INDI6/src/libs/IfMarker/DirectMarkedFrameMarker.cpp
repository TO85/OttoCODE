#include "DirectMarkedFrameMarker.h"

#include <QtGui/QBrush>
#include <QtGui/QColor>
#include <QtGui/QFont>
#include <QtGui/QPainter>
#include <QtGui/QPen>

#include <eirBase/QtTypes.h>
#include <eirType/Line.h>
#include <eirGui/QQColor.h>
#include <eirXfr/Debug.h>
#include <IfGeometry/FaceGeometry.h>
#include <IfGeometry/FaceTypeRect.h>
#include <IfObject/FaceData.h>
#include <IfObject/FrameData.h>
#include <IfObject/Quality.h>

void DirectMarkedFrameMarker::clear()
{
    TRACEFN;
    mMarkedImage = mInputImage = QImage();
}

bool DirectMarkedFrameMarker::setImage(const QImage &input, const bool forceGrey)
{
    TRACEQFI << input;
    if (forceGrey)
        mInputImage = input.convertToFormat(QImage::Format_Grayscale8)
                           .convertToFormat(QImage::Format_RGB32);
    else
        mInputImage = input.convertToFormat(QImage::Format_RGB32);

    return isInputValid();
}

QQImage DirectMarkedFrameMarker::markFaceResults(const FrameData frameData, const FaceData::Vector faces)
{
    TRACEQFI << inputImage();
    if ( ! isInputValid()) return QImage();
    ObjectResults faceOR = frameData.getFaceResults();
    mMarkedImage = inputImage().convertedToGrey().convertedToColor();

    QColor penColor(mConfig.value("Marked/Frame/MarkedFrame/Pen/Color", "#990000FF").toString());
    int penWidth(mConfig.value("Marked/Frame/MarkedFrame/Pen/Width", 5).toInt());

    QPainter painter(&mMarkedImage);
    QPen pen;

    painter.setPen(QPen(QBrush(penColor), 2, Qt::DashLine));
    drawRectangles(&painter, faceOR.orphans().list());


    for (ObjectResultItem ori : qAsConst(faceOR).itemList())
    {
        const SCRect resultRect = ori.resultRect().rect();
        const SCRect overRect = resultRect.resized(1.250);
        painter.drawImage(overRect, inputImage(), overRect);
    }
    int faceIndex = 0;
    for (ObjectResultItem ori : qAsConst(faceOR).itemList())
    {
        EyeROI eyeROI = faces[faceIndex].getEyeROI();
        QQRect leftROI  = eyeROI.left().toRect();
        QQRect rightROI  = eyeROI.right().toRect();
        drawEyeROI(&painter, leftROI,  Qt::BDiagPattern, Qt::red);
        drawEyeROI(&painter, rightROI, Qt::FDiagPattern, Qt::red);

        const QRectList rects = ori.includedQRectList();
        const SCRect resultRect = ori.resultRect().rect();
        const int fq = ori.quality();
        const int rank = ori.rank();

        // Included Detectors
        if (rects.count() > 1)
        {
            pen.setColor(penColor), pen.setWidth(1);
            painter.setPen(pen);
            painter.drawRects(rects.toVector());
        }

        // The Result
        QColor resultColor = (fq < 500)
                ? penColor.darker(50 * (fq - 500) / 500)
                : penColor.lighter(50 * (fq - 500) / 500);
        pen.setColor(resultColor), pen.setWidth(penWidth);
        painter.setPen(pen);
        painter.drawRect(resultRect);

        // Title Block
#if 0 // QtGui
        QFont titleFont("Helvetica", 10);
        QRect titleRect(resultQRect.topLeft()  - QPoint(0, 20 + penWidth / 2),
                        resultQRect.topRight() - QPoint(0, penWidth / 2));
        QString resultTitle = QString("FQ%1 #%2 W%3").arg(fq, 3, 10, QChar('0'))
                .arg(rank, 2, 10, QChar('0')).arg(resultQRect.width(), 3, 10, QChar('0'));
        QRect titleBound = painter.boundingRect(titleRect,
                Qt::AlignHCenter | Qt::AlignBottom | Qt::TextSingleLine, resultTitle);
        painter.fillRect(titleBound, penColor);
        painter.setFont(titleFont);
        pen.setColor((fq < 500) ? Qt::black : Qt::white);
        painter.setPen(pen);
        painter.drawText(titleBound, resultTitle);
#else
        UNUSED(rank);
        QRect titleRect(resultRect.topLeft()  - QPoint( + penWidth / 2, 7 + penWidth),
                        resultRect.topRight() + QPoint( + penWidth,       + penWidth));
        painter.fillRect(titleRect, penColor);
        QRect barRect = titleRect.adjusted(+1, +1, -1, -1);
        painter.fillRect(barRect, (fq > 500) ? Qt::white : Qt::black);
        int barWidth = barRect.width();
        int qualityWidth = qBound(1, barWidth * fq / 1000, barWidth - 1);
        QRect qualityRect = barRect.adjusted(0, 0, - barWidth + qualityWidth, 0);
        painter.fillRect(qualityRect, resultColor);
#endif
        // ------ eye crosses
        ObjectResults eyeOR = faces[faceIndex].getRawEyeResults();
        for (ObjectResultItem eyeORI : eyeOR.itemList())
        {
            QPen eyePen(eyeColorPen(eyeORI));
            SCRect eyeRect = eyeORI.resultRect().rect();
            painter.setPen(eyePen);
            drawCrossMark(&painter, eyeRect.center() + resultRect.topLeft());
        }
        painter.setPen(Qt::NoPen);

        ++faceIndex;
    }
    painter.end();
    return mMarkedImage;
}

QQImage DirectMarkedFrameMarker::markRectangles(const SCRectList &rects, const QString &defaultColorName)
{
    TRACEQFI << rects << inputImage();
    mMarkedImage = inputImage();
    if ( ! isInputValid()) return QImage();

    QColor penColor(mConfig.value("Marked/Frame/MarkedFrame/Pen/Color", defaultColorName).toString());
    int penWidth(mConfig.value("Marked/Frame/MarkedFrame/Pen/Width", 3).toInt());
    QPen pen(QBrush(penColor), penWidth);
    DUMPVAL(pen);

    QPainter painter(&mMarkedImage);
    painter.setPen(pen);
    foreach (SCRect scrc, rects)
    {
        QRect qrc = scrc.toRect();
        DUMPVAL(scrc);
        DUMPVAL(qrc);
        painter.drawRect(qrc);
    }
    painter.end();

    return mMarkedImage;
}

QQImage DirectMarkedFrameMarker::markEyeResults(const FrameData frame, const FaceData face)
{
    TRACEQFI << inputImage();
    if ( ! isInputValid()) return QImage();                             /* /=======\ */

    mMarkedImage = inputImage();
    ObjectResultItem faceORI = face.getFaceResultItem();
    DetectRect faceDR = faceORI.resultRect();
    SCRect scaledRect = faceDR.rect();
    ObjectResults rawEyeOR = face.getRawEyeResults();

    EyeROI eyeROI = face.getEyeROI();
    SCRect leyeROI = eyeROI.left().translated(mMarkedImage.rect().center() - scaledRect.center());
    SCRect reyeROI = eyeROI.right().translated(mMarkedImage.rect().center() - scaledRect.center());

    QPainter painter(&mMarkedImage);
    drawEyeROI(&painter, leyeROI, Qt::BDiagPattern);
    drawEyeROI(&painter, reyeROI, Qt::FDiagPattern);

    QPen facePen(Qt::blue); facePen.setWidth(3);
    painter.setPen(facePen);
    EyeLine exel = FaceGeometry::expectedEyeLine(FaceTypeRect(faceDR.rect()));
//    painter.drawRect(scaledRect.translated(mMarkedImage.rect().center() - scaledRect.center()));
    exel.translate(mMarkedImage.rect().center() - faceDR.rect().center());
    painter.drawLine(exel);
    painter.setPen(Qt::NoPen);

    QPen centerPen(Qt::yellow); centerPen.setWidth(1); centerPen.setStyle(Qt::PenStyle::DashDotLine);
    painter.setPen(centerPen);
    QQRect markRect = inputImage().rect().toRect();
    painter.drawLine(markRect.centerLine());
    painter.drawLine(markRect.middleLine());
    painter.setPen(Qt::NoPen);

    foreach (ObjectResults::Item ori, rawEyeOR.itemList()) // + leyeOR.items() + reyeOR.items())
    {
        const QPen eyePen = eyeColorPen(ori);
        QPen includedPen = eyePen;
        QQColor includedPenColor = includedPen.color();
        includedPenColor.setAlphaF(0.5);
        includedPen.setColor(includedPenColor);
        includedPen.setWidth(1), includedPen.setStyle(Qt::DotLine);
        painter.setPen(includedPen);
        painter.drawRects(ori.includedResults().list().toQRectVector()); // ?? offset
        painter.setPen(Qt::NoPen);

        const unsigned qual = ori.quality();
        const SCRect resultRect = ori.resultRect().rect();
        TRACE << ori << qual << eyePen << QString::number(eyePen.color().rgba(), 16) << eyePen.width();
        painter.setPen(eyePen);
        painter.drawEllipse(resultRect.center(), resultRect.width() / 2, resultRect.height() / 4);


        QQColor qualColor = eyePen.color();
        int penWidth = eyePen.width();
        QRect qualRect(resultRect.topLeft()  - QQPoint( + penWidth / 2, 3 + penWidth),
                       resultRect.topRight() + QQPoint( + penWidth,       + penWidth / 2));
        painter.fillRect(qualRect, qualColor);
        QRect barRect = qualRect.adjusted(+1, +1, -1, -1);
        painter.fillRect(barRect, (qual > 500) ? Qt::white : Qt::black);
        int barWidth = barRect.width();
        int qualityWidth = qBound(1U, barWidth * qual / 1000, barWidth - 1U);
        TRACE << barRect << qual << qualityWidth << ori.type().name();
        QRect qualityRect = barRect.adjusted(0, 0, - barWidth + qualityWidth, 0);
        painter.fillRect(qualityRect,qualColor);
    }

    QPen orphanPen(Qt::black); orphanPen.setStyle(Qt::PenStyle::DotLine);
    painter.setPen(orphanPen);
    painter.drawRects(rawEyeOR.orphans().toQRectVector());
    painter.end();
    return mMarkedImage;
}

QQImage DirectMarkedFrameMarker::markEyeLine(const EyeLine eline, const QString &defaultColorName)
{
    TRACEQFI << eline << inputImage();
    mMarkedImage = inputImage();
    if ( ! isInputValid()) return QImage();

    QColor penColor(mConfig.value("Marked/Frame/MarkedFrame/Pen/Color", defaultColorName).toString());
    QPen pen(QBrush(penColor), 3);
    QPainter painter(&mMarkedImage);
    painter.setPen(pen);

    drawPlusMark(&painter, eline.leftPoint());
    drawPlusMark(&painter, eline.rightPoint());
    drawEyeLineCenter(&painter, eline);

    if ( ! eline.isVertical())
    {
        Line ln(eline);
        QQLine ll = ln.segment(eline.leftPoint().x() + 9, eline.center().x() - 9);
        QQLine rl = ln.segment(eline.center().x() + 9, eline.rightPoint().x() - 9);
        pen.setWidth(1);
        pen.setStyle(Qt::PenStyle::DashLine);
        painter.setPen(pen);
        painter.drawLine(ll);
        painter.drawLine(rl);
    }
    painter.end();

    return mMarkedImage;
}

/* ----------------------------------- private ------------------------------------ */

// static
QPen DirectMarkedFrameMarker::eyeColorPen(const ObjectResults::Item ori)
{
    const int qual = ori.quality();
    QPen result = Qt::NoPen;
    QQColor baseColor = Qt::yellow;
    QQColor penColor  = baseColor;

    switch (ori.type().value())
    {
    case ObjectType::EyeLeft:       baseColor = QQColor(0xFFFF0066);     break;
    case ObjectType::EyeRight:      baseColor = QQColor(0xFFFF6600);     break;
    case ObjectType::EyeNeither:    baseColor = QQColor(0xFF66FF00);     break;
    case ObjectType::EyeEither:     baseColor = QQColor(0xFF00FF66);     break;
    default:                        /* DO NOTHING */                    break;
    }

#if 1
    penColor = baseColor;
#else
    if (qual < 1)
        penColor = baseColor / 4;
    else if (qual > 999)
        penColor = baseColor / 2;
    else if (qual < 500)
        penColor = baseColor.darker( 50 * (500 - qual) / 500);
    else /* (qual >= 500) */
        penColor = baseColor.lighter(50 * (qual - 500) / 500);
#endif

    result.setColor(penColor);
    result.setWidth(3);
    result.setStyle(Qt::SolidLine);
    TRACEQFI << ori << baseColor << result;
    return result;
}


void DirectMarkedFrameMarker::drawPlusMark(QPainter *painter, const QQPoint pt)
{
    painter->drawLine(QLine(QPoint(pt.x()-5, pt.y()-5), QPoint(pt.x()+5, pt.y()+5)));
    painter->drawLine(QLine(QPoint(pt.x()-5, pt.y()+5), QPoint(pt.x()+5, pt.y()-5)));
}

void DirectMarkedFrameMarker::drawCrossMark(QPainter *painter, const QQPoint pt)
{
    painter->drawLine(QLine(QPoint(pt.x()-5, pt.y()), QPoint(pt.x()+5, pt.y())));
    painter->drawLine(QLine(QPoint(pt.x(), pt.y()-5), QPoint(pt.x(), pt.y()+5)));
}

void DirectMarkedFrameMarker::drawRectangles(QPainter *painter, const DetectRectList &drs)
{
    for (DetectRect dr : drs)
         painter->drawRect(dr);
}

void DirectMarkedFrameMarker::drawEyeLineCenter(QPainter *painter, const EyeLine el)
{
    drawCrossMark(painter, el.center());
}

void DirectMarkedFrameMarker::drawEyeROI(QPainter *painter, const SCRect ROIRect, const Qt::BrushStyle style, const QColor &color)
{
    QPen pen(color, 1);
    QBrush brush(color, style);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(ROIRect);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::NoBrush);
}
