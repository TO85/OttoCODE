#include "QQImage.h"

#include <eirType/Success.h>
#include <eirXfr/Debug.h>


QQImage::QQImage(const QQString &fileName)
     : QImage(fileName)
     , mFileInfo(fileName)
     , mName(mFileInfo.completeBaseName())
{;}

QQImage::QQImage(const QQFileInfo &fileInfo)
    : QImage(fileInfo.absoluteFilePath())
    , mFileInfo(fileInfo)
    , mName(mFileInfo.completeBaseName())
{;}

QQImage::QQImage(const QImage &other)
    : QImage(other)
    , mName()
{;}
QQImage::QQImage(const QVariant &vari): QImage(qvariant_cast<QImage>(vari))
{
    TRACEQFI << toDebugString();
    EXPECT(notNull());
}

bool QQImage::isValid(const QQPoint pt)
{
    Success success;
    SCRect scrc = rect();
    int ty = scrc.top(), lx = scrc.left(), by = scrc.bottom(), rx = scrc.right();
    int px = pt.x(), py = pt.y();
    success.expect(lx <= px);
    success.expect(px <  rx);
    success.expect(ty <= py);
    success.expect(py <  by);
    success.validate();
    return success;
}

QQString QQImage::baseName(const QQString &ifEmpty) const
{
    QQString result = mFileInfo.baseName();
    if (result.isEmpty()) result = ifEmpty;
    return result;
}

QQString QQImage::cacheKeyString() const
{
    qint64 tKey = cacheKey();
    QByteArray tBA((const char *)(&tKey), sizeof (tKey));
    QQString result = QQString("QImage#") + tBA.toHex().toUpper();
    return result;
}

QQString QQImage::cacheKeyFileName() const
{
    QQString result = cacheKeyString();
    QQString tSuffix = fileInfo().suffix();
    if (tSuffix.notEmpty()) result += "." + tSuffix.toLower();
    return result;
}

void QQImage::clear()
{
    TRACEQFI << toDebugString();
    QImage nullImage;
    EXPECT(nullImage.isNull());
    swap(nullImage);
    mFileInfo.nullify();
    mName.clear();
    mUid.nullify();
    AEXPECT(isNull());
    AEXPECT(mFileInfo.isNull());
    AEXPECT(mName.isEmpty());
    AEXPECT(mUid.isNull());
}

QVariant QQImage::toVariant() const
{
    QVariant result;
    result.setValue(QImage(it()));
    return result;
}

/* ----------------------- private --------------------------- */

/* ----------------------- debug --------------------------- */

QQString QQImage::toDebugString() const
{
    return QString("{QQImage: %1x%2 format=%3 depth=%4}")
            .arg(size().width()).arg(size().height())
            .arg(format()).arg(depth());
}

/* ----------------------- getters/setters --------------------------- */

const MultiName &QQImage::name() const
{
    return mName;
}

void QQImage::setName(const MultiName &newName)
{
    mName = newName;
}

const QQFileInfo &QQImage::fileInfo() const
{
    return mFileInfo;
}

void QQImage::setFileInfo(const QQFileInfo &newFileInfo)
{
    mFileInfo = newFileInfo;
}

const Uid &QQImage::uid() const
{
    return mUid;
}

void QQImage::setUid(const Uid &newUid)
{
    mUid = newUid;
}
