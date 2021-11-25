#include "VersionInfo.h"

#include <eirXfr/Debug.h>

VersionInfo::VersionInfo() {;}

VersionInfo::VersionInfo(const QString &str, const int maj, const int min, const int mic, const int mni)
{
    set(str);
    set(maj, min, mic, mni);
}

QString VersionInfo::string() const
{
    return mVersionString;
}

QString VersionInfo::dottedString() const
{
    return mVersionNumber.toString();
}

QString VersionInfo::toString(const bool withDotted) const
{
    QString result = dottedString();
    QVersionNumber tVerNumber = mVersionNumber.normalized();
    if (4 == tVerNumber.segmentCount())
        result = QString("v%1.%2%3+%4")
                .arg(tVerNumber.majorVersion()) // 1
                .arg(tVerNumber.minorVersion(), 2, 10, QLatin1Char('0')) // 2
                .arg(releaseString(tVerNumber.segmentAt(Release))) // 3
                .arg(tVerNumber.microVersion(), 4, 10, QLatin1Char('0')); // 4
    else if (3 == tVerNumber.segmentCount())
        result = QString("v%1.%2%3")
                .arg(tVerNumber.majorVersion()) // 1
                .arg(tVerNumber.minorVersion(), 2, 10, QLatin1Char('0')) // 2
                .arg(releaseString(tVerNumber.microVersion())); // 3
    else if (3 == tVerNumber.segmentCount())
        result = QString("v%1.%2")
                .arg(tVerNumber.majorVersion()) // 1
                .arg(tVerNumber.minorVersion(), 2, 10, QLatin1Char('0')); // 2
    else if (3 == tVerNumber.segmentCount())
        result = QString("v%1")
                .arg(tVerNumber.majorVersion()); // 1
    if (withDotted)
        result += " [" + dottedString() +"]";
    return result;
}

void VersionInfo::set(const QString &str)
{
    mVersionString = str;

}

void VersionInfo::set(const int maj, const int min, const int mic, const int mni)
{
    QVector<int> segs;
    segs << maj << min << mic << mni;
    mVersionNumber = QVersionNumber(segs);

}

/* -------------------------- private ------------------------ */

QString VersionInfo::releaseString(const quint8 aRelease) const
{
    QString result = "#" + QString::number(aRelease);
    if (aRelease == 0)                          result.clear();
    else if (aRelease <= 26)                    result = QChar('A'+aRelease-1);
    else if (aRelease <= 52)                    result.fill(QChar('A'+aRelease-1), 2);
    else if (aRelease < 0xA0)                   result = QString::number(aRelease);
    else if (aRelease == 0xA0)                  result = "Alpha";
    else if (aRelease <= 0xAF)                  result = "Alpha" + QString::number(aRelease-0xA0);
    else if (aRelease == 0xB0)                  result = "Beta";
    else if (aRelease <= 0xBF)                  result = "Beta" + QString::number(aRelease-0xB0);
    else if (aRelease == 0xC0)                  result = "RC";
    else if (aRelease <= 0xCF)                  result = "RC" + QString::number(aRelease-0xC0);
    else if (aRelease == 0xD0)                  result = "Delta";
    else if (aRelease <= 0xDF)                  result = "Delta" + QString::number(aRelease-0xD0);
    else if (aRelease == 0xE0)                  result = "Echo";
    else if (aRelease <= 0xEF)                  result = "Echo" + QString::number(aRelease-0xE0);
    else if (aRelease == 0xF0)                  result = "Final";
    else                                        result = "Final" + QString::number(aRelease-0xF0);
    return result;
}
