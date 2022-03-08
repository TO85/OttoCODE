#pragma once
#include "ocqCore.h"

#include <QList>
#include "QQFileInfo.h"

#include <QMetaType>

class OCQCORE_EXPORT QQFileInfoList : public QList<QQFileInfo>
{
public:
    QQFileInfoList() = default;
    ~QQFileInfoList() = default;
    QQFileInfoList(const QQFileInfoList &other) = default;
    QQFileInfoList &operator = (const QQFileInfoList &other) = default;
};

Q_DECLARE_METATYPE(QQFileInfoList);

