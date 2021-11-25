#include "AppSettings.h"

#include <QCoreApplication>

#include <eirXfr/Debug.h>

AppSettings::AppSettings()
    : QSettings(nullptr)
{
    setObjectName("AppSettings");
    TRACEQFI << QOBJNAME(this);
}

QVariantMap AppSettings::configuration(const QString groupKey)
{
    TRACEQFI << groupKey;
    WANTDO(it); return QVariantMap();
}
