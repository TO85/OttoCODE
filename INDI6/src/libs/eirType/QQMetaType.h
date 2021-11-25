#pragma once
#include "eirType.h"

#include <QtCore/QMetaType>

class EIRTYPE_EXPORT QQMetaType
{
public:
    QQMetaType() = default;
    QQMetaType(const QMetaType::Type aType);
    QQMetaType(const QQMetaType &other) = default;
    ~QQMetaType() = default;
    QQMetaType &operator = (const QQMetaType &other) = default;

public:
    QMetaType &metaType() { return set(QMetaType::UnknownType); }

public:
    QMetaType &set(const int aType);

private:
    QMetaType *mpMetaType=nullptr;
    const static QMetaType csmUnknown;
};

Q_DECLARE_METATYPE(QQMetaType);
