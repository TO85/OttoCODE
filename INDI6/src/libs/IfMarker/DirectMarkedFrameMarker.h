#pragma once
#include "IfMarker.h"

#include <QtCore/QVariantMap>

#include <eirGui/QQImage.h>
#include <eirType/QQLine.h>
#include <eirType/SCRect.h>
#include <eirType/SCRectList.h>
#include <IfObject/FaceData.h>
#include <IfObject/FrameData.h>
#include <IfGeometry/EyeLine.h>
#include <IfObject/ObjectResults.h>

class IFMARKER_EXPORT DirectMarkedFrameMarker
{
public:
    DirectMarkedFrameMarker() {;}
    DirectMarkedFrameMarker(const QQImage &input) { setImage(input); }

    bool isInputValid() const { return mInputImage.isValid(); }
    bool isMarkedValid() const { return mMarkedImage.isValid(); }
    bool isValid() const { return isInputValid() && isMarkedValid(); }
    QQImage inputImage() const { return mInputImage; }
    QQImage markedImage() const { return mMarkedImage; }

    void clear();
    bool setImage(const QImage &input, const bool forceGrey=false);
    void configure(const QVariantMap &config);
    QQImage markFaceResults(const FrameData frameData, const FaceData::Vector faces);
    QQImage markRectangles(const SCRectList &rects, const QString &defaultColorName="#990000FF");
    QQImage markEyeResults(const FrameData frame, const FaceData face);
    QQImage markEyeLine(const EyeLine eline, const QString &defaultColorName="#99FFFF00");

private:
    static QPen eyeColorPen(const ObjectResults::Item ori);
    void drawPlusMark(QPainter *painter, const QQPoint pt);
    void drawCrossMark(QPainter *painter, const QQPoint pt);
    void drawRectangles(QPainter *painter, const DetectRectList &drs);
    void drawEyeLineCenter(QPainter *painter, const EyeLine el);
    void drawEyeROI(QPainter *painter, const SCRect scrc, const Qt::BrushStyle style, const QColor &color=Qt::red);

private:
    QQImage mInputImage;
    QQImage mMarkedImage;
    QVariantMap mConfig;
};

