#pragma once
#include "eirType.h"

#include "QQVariant.h"

#include <QtCore/QMetaType>

class EIRTYPE_EXPORT QQVariantList : public QQVariant::List
{
public:
    QQVariantList() = default;
    QQVariantList(const QQVariantList &other) = default;
    ~QQVariantList() = default;
    QQVariantList &operator = (const QQVariantList &other) = default;

public: // commands
    int resize(const int index);
};


Q_DECLARE_METATYPE(QQVariantList);
