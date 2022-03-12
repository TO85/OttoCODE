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

extern OCQCORE_EXPORT bool operator == (const QQFileInfo &lfi, const QQFileInfo &rfi);
extern OCQCORE_EXPORT bool operator <  (const QQFileInfo &lfi, const QQFileInfo &rfi);

Q_DECLARE_METATYPE(QQFileInfo);

