#pragma once
#include "eirBase.h"

#include <QSharedDataPointer>

#include <QString>

#include <eirType/DProperty.h>

#define VERSION(VER_MAJOR, VER_MINOR, VER_MINI, VER_MICRO, VER_BRANCH, VER_RELEASE, VER_STRING) \
    Version(VER_MAJOR, VER_MINOR, VER_MICRO, VER_BRANCH, VER_RELEASE, VER_STRING)

#define VERSION_DATAPROPS(TND) \
    TND(quint16, Major, 0) \
    TND(quint16, Minor, 0) \
    TND(quint16, Mini,  0) \
    TND(quint16, Micro, 0) \
    TND(quint16, Branch, 0) \
    TND(quint16, Release, 0) \
    TND(QString, String, QString()) \
    TND(QString, Copyright, QString()) \
    TND(QString, Legal, QString()) \

class VersionData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(VERSION_DATAPROPS)
public:
    VersionData(void)
    {
        DEFINE_DATAPROPS_CTORS(VERSION_DATAPROPS)
    }
};

class EIRBASE_EXPORT Version
{
    DECLARE_PARENT_DATAPROPS(VERSION_DATAPROPS)
    DECLARE_DATAPROPS(Version, VersionData)

public:
    Version(const quint16 major,
            const quint16 minor,
            const quint16 mini,
            const quint16 micro,
            const quint16 branch,
            const quint16 release,
            const QString string);
    Version version() const;
    QString toString() const;
};
