#pragma once
#include "IfMarker.h"


class IFMARKER_EXPORT MarkedImageEntry
{
public:
    MarkedImageEntry(const MultiName aImageName=MultiName()) {;}
    MarkedImageEntry(const QQImage& aImage, const MultiName aImageName=MultiName()) {;}
    MarkedImageEntry(const DataMap& aData, const QQImage& aImage,
        const MultiName aImageName = MultiName()) {;}

public: // getters
    DataMap data() const { return mCurrentData; }
    QQImage image() const { return mCurrentImage;  }
    QQFileInfo fileInfo() const { return mFileInfo; }
    QQByteArray embededBytes() const { return mEmbededBytes; }
    QQByteArray encodedBytes() const { return mEncodedBytes; }

public: // setters
    void clear();
    void set(const DataMap& aData, const QQImage& aImage);
    void set(const DataMap& aData);
    void set(const QQImage& aImage);
    void set(const QQFileInfo& aFileInfo);
    void embed(const QQByteArray& aBytes);
    void encode(const QQByteArray& aBytes);


private:
    const MultiName cmImageName;
    DataMap mCurrentData;
    QQImage mCurrentImage;
    QQByteArray mEmbededBytes;
    QQByteArray mEncodedBytes;
    QQFileInfo mFileInfo;
    QUrl mDestinationUrl;  // future
};

