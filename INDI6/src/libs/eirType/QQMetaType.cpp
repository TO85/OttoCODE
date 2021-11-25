#include "QQMetaType.h"

#include <eirXfr/Debug.h>

const QMetaType QQMetaType::csmUnknown = QMetaType(QMetaType::UnknownType);

QMetaType &QQMetaType::set(const int aType)
{
    if (nullptr == mpMetaType)
        mpMetaType = new QMetaType(aType);
    return *mpMetaType;
}
