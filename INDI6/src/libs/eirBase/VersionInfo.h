#pragma once
#include "eirBase.h"

#include <QVersionNumber>

class EIRBASE_EXPORT VersionInfo
{
public:
    enum Segmemt
    {
        Major = 0,
        Minor = 1,
        Micro = 2,
        Branch = Micro,
        Release = 3,
        Build = 4,
        TrunkDevelop = 0x00000000,
        TrunkCurrent = 0x40000000,
        TrunkRelease = 0x80000000,
        TrunkMain    = 0xC0000000,
    };
public:
    VersionInfo();
    VersionInfo(const QString &str, const int maj, const int min=0, const int mic=0, const int mni=0);

    QString string() const;
    QString dottedString() const;
    QString toString(const bool withDotted=true) const;

    void set(const QString &str);
    void set(const int maj, const int min=0, const int mic=0, const int mni=0);

private:
    QString releaseString(const quint8 aRelease) const;

private:
    QVersionNumber mVersionNumber;
    QString mVersionString;
};

