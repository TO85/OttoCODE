#pragma once
#include "eirGui.h"

#include <eirBase/Uid.h>
#include <eirType/MultiName.h>
#include <eirType/Null.h>
#include <eirType/QQFileInfo.h>
#include <eirType/QQSize.h>
#include <eirType/QQString.h>
#include <eirType/SCRect.h>

class EIRGUI_EXPORT QQImage : public QImage
{
public:
    QQImage(const QQString &fileName);
    QQImage(const QQFileInfo &fileInfo);
    QQImage(const QImage &other);
    QQImage(const QQSize size, const Format format) : QImage(size, format) {;}
    QQImage(const QVariant &vari);
    QQImage() = default;
    QQImage(const QQImage &other) = default;
    ~QQImage() = default;
    QQImage &operator = (const QQImage &other) = default;

    bool isNull() const { return QImage::isNull(); }
    bool notNull() const { return ! isNull(); }
    bool isValid() const { return notNull(); }
    bool isValid(const QQPoint pt);
    bool notValid() const { return ! isValid(); }
    QQSize size() const { return QImage::size(); }
    qreal widthF() const { return qreal(width()) ;}
    SCRect rect() const { return size();}
    QQPoint center() const { return rect().center(); }
    bool isContinuous() const { return bytesPerLine() == width() * depth() / 8; }

    QQImage convertedToColor() const { return it().convertToFormat(Format_ARGB32); }
    QQImage convertedToGrey() const { return it().convertToFormat(Format_Grayscale8); }
    QQImage crop(const SCRect &rect) const  { return it().copy(rect.toQRect()); }
    QQImage resized(const QQSize aSize) const
    { return it().scaled(aSize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation); }
    QQImage scaledBy(const qreal f)const  { return scaledToWidth(qRound(widthF() * f)); }
    QQString baseName(const QQString &ifEmpty=QQString()) const;
    QQString cacheKeyString() const;
    QQString cacheKeyFileName() const;
    void clear();
    void nullify() { clear(); }
    void set(QQImage other) { swap(other); }
    void set(QQFileInfo fi) { mFileInfo = fi; }
    void resize(const QQSize aSize) { QImage resizedImage = resized(aSize); swap(resizedImage); }
    void convertToColor() { it().convertTo(colorFormat()); }
    void convertToGrey()  { it().convertTo(greyFormat()); }

    QImage toQImage() const { return static_cast<QImage>(it()); }
    QVariant toVariant() const;
    operator QVariant () const { return toVariant(); }
    operator QString () const { return toDebugString(); }

public: // static
    static Format colorFormat() { return Format_ARGB32; }
    static Format greyFormat() { return Format_Grayscale8; }

public: // debug
    QQString toDebugString() const;


public: // get/set
    const MultiName &name() const;
    void setName(const MultiName &newName);

    const QQFileInfo &fileInfo() const;
    void setFileInfo(const QQFileInfo &newFileInfo);

    const Uid &uid() const;
    void setUid(const Uid &newUid);

private:
    QQImage &it() { return *this; }
    QQImage it() const { return *this; }

private:
    QQFileInfo mFileInfo;
    MultiName mName;
    Uid mUid;
};

Q_DECLARE_METATYPE(QQImage);

