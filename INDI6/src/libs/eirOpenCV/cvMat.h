#pragma once
#include "eirOpenCV.h"

#include <QFileInfo>

#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>

#include <QtGui/QImage>

#include <eirGui/QQImage.h>
#include <eirType/SCRect.h>

#include "cvMatType.h"

namespace cv { class Mat; };

class EIROPENCV_EXPORT cvMat
{
public:
    cvMat() : mpCvMat(nullptr) {;}
    cvMat(const QImage &qi, cvMatType cvmt=cvMatType()) { set(qi, cvmt); }
    cv::Mat &mat() const { return *mpCvMat; }
    cv::Mat &operator () () const { return mat(); }
    bool notNull() const { return nullptr != mpCvMat; }
    bool isNull() const { return ! notNull(); }
    bool isEmpty() const { return isNull() || mat().empty(); }
    bool notEmpty() const { return ! isEmpty(); }
    bool isValid() const;
    bool isMatContinuous() const;
    bool isQImageContinuous() const;
    int height() const { return isValid() ? mat().rows : 0 ; }
    int width() const { return isValid() ? mat().cols : 0 ; }
    QSize size() const { return QSize(width(), height()); }
    int depthBytes() const { return isValid() ? int(mat().elemSize()) : 0; }
    int bytesPerLine() const { return isValid() ? int(mat().step) : 0; }
    quint8 *bits() const;
    quint8 *scanLine(const int row) const;
    bool imwrite(const QFileInfo qfi);
    qsizetype sizeInBytes() const;
    void dump() const;

    cv::Mat *mat() { return mpCvMat; }

    void clear() { release(); mQImage = QImage(); mType.nullify(); }
    void release();
    bool set(const QImage &qi, cvMatType cvmt=cvMatType());

    static QString toMatDebugString(cv::Mat *cvm);

private:
    bool copyQImagePixelsToCvMat();
    bool copyQImagePixelsToCvMatBuffer();
    bool copyQImagePixelsToCvMatByRows();



private:
    cv::Mat *mpCvMat=nullptr;
    QQImage mQImage;
    cvMatType mType;
};

extern EIROPENCV_EXPORT QDebug operator<<(QDebug dbg, const cvMat &cvm);


