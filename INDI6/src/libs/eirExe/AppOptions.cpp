#include "AppOptions.h"

#include<eirXfr/Debug.h>

AppOptions::AppOptions(QObject *parent)
    : QObject(parent)
{
    setObjectName("AppOptions");
    TRACEQFI << QOBJNAME(this);
}
