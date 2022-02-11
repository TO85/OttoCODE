#pragma once
#include "ocqCore.h"

#include <QFileInfo>

#include <QMetaType>

class OCQCORE_EXPORT QQFileInfo : public QFileInfo
{
public:
    QQFileInfo() = default;
    ~QQFileInfo() = default;
    QQFileInfo(const QQFileInfo &other) = default;
    QQFileInfo &operator = (const QQFileInfo &other) = default;
};

Q_DECLARE_METATYPE(QQFileInfo);

