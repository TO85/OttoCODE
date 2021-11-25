#include "Version.h"

void Version::ctor() {;}
void Version::dtor() {;}

Version::Version(const quint16 major, const quint16 minor, const quint16 mini, const quint16 micro,
                 const quint16 branch, const quint16 release, const QString string)
    : data(new VersionData)
{
    setMajor(major);
    setMinor(minor);
    setMini(mini);
    setMicro(micro);
    setBranch(branch);
    setRelease(release);
    setString(string);
}

QString Version::toString() const
{
    QString verString = QString("v%1.%2").arg(getMajor()).arg(getMinor(), 2, 10, QChar('0'));
    if (getMini()) verString += QString(".%1").arg(getMini());
    if (getMicro()) verString += QString(".%1").arg(getMicro());
    if (getRelease()) verString += (getRelease() < 26) ? QChar(getRelease()+'A') : QString("%1").arg(getRelease(), 2, 16);
    if (getBranch()) verString += QString("+%1").arg(getBranch());
    return verString;
}

DEFINE_DATAPROPS(Version, VersionData)
