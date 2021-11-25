#include "cvMat.h"

#include <opencv2/imgcodecs.hpp>

#include <eirXfr/Debug.h>

#include "cvSize.h"
#include "cvString.h"

bool cvMat::isValid() const
{
    if (isNull()) return false;
    if (isEmpty()) return false;
//    NEEDDO(more);
    return true;
}

bool cvMat::isMatContinuous() const
{
    return isValid() ? mat().isContinuous() : false;
}

bool cvMat::isQImageContinuous() const
{
    return mQImage.bytesPerLine() == mQImage.width() * mQImage.depth() / 8;
}

quint8 *cvMat::bits() const
{
    AEXPECT(isValid());
    return mpCvMat->ptr();
}

quint8 *cvMat::scanLine(const int row) const
{
    AEXPECT(isValid());
    return mpCvMat->ptr(row);
}



bool cvMat::imwrite(const QFileInfo qfi)
{
    TRACEQFI << qfi;
    return cv::imwrite(cvString(qfi.absoluteFilePath()), cv::_InputArray(*mpCvMat));
}

qsizetype cvMat::sizeInBytes() const
{
    return isEmpty() ? 0 : (height() * bytesPerLine());
}

void cvMat::dump() const
{
    DUMP << cvMat::toMatDebugString(mpCvMat);
    DUMP << mType << mQImage;
}

void cvMat::release()
{
    TRACEQFI << Qt::hex << mpCvMat << Qt::dec;
    if (mpCvMat)
    {
        mpCvMat->release();
        delete mpCvMat;
        mpCvMat = nullptr;
    }
}

bool cvMat::set(const QImage &qi, cvMatType cvmt)
{
    TRACEQFI << qi << cvmt;
    if (cvmt.isNull()) cvmt = cvMatType::fromQImage(qi);
    clear();
    mType = cvmt;
    QImage::Format qfi = cvmt.toQImageFormat();
    mQImage = qi.convertToFormat(qfi);
    mpCvMat = new cv::Mat(cvSize(mQImage.size()), mType);
    return copyQImagePixelsToCvMat();
}


/* ------------------------------ private ---------------------------- */


bool cvMat::copyQImagePixelsToCvMat()
{
    TRACEFN; dump();
    if (isMatContinuous() && isQImageContinuous())
        return copyQImagePixelsToCvMatBuffer();
    else
        return copyQImagePixelsToCvMatByRows();
}

bool cvMat::copyQImagePixelsToCvMatBuffer()
{
    AEXPECTEQ(mQImage.sizeInBytes(), sizeInBytes());
    memcpy(bits(), mQImage.bits(), sizeInBytes());
    dump();
    return true;
}

bool cvMat::copyQImagePixelsToCvMatByRows()
{
    AEXPECTEQ(height(), mQImage.height());
    EXPECT(bytesPerLine() <= mQImage.bytesPerLine());
    for (int r = 0; r < height(); ++r)
        memcpy(scanLine(r), mQImage.constScanLine(r), bytesPerLine());
    dump();
    return true;
}


/* ------------------------------------- static  --------------------------------------- */

QString cvMat::toMatDebugString(cv::Mat *mat)
{
    return (nullptr == mat)
            ? "Null cv::Mat"
            : QString("cvMat size=%1x%2 type=%3 depth=%4 total=%5 step=%6 step1()=%7 data=%8")
                    .arg(mat->size().width).arg(mat->size().height)
                    .arg(mat->type()).arg(mat->elemSize())
                    .arg(mat->elemSize() * mat->total())
                    .arg(mat->step).arg(mat->step1())
                    .arg(PTRSTRING(mat->data));
}

/* ------------------------------------- non-member  --------------------------------------- */

QDebug operator<<(QDebug dbg, const cvMat &cvm)
{
    dbg << cvMat::toMatDebugString(&cvm());
    return dbg;
}
