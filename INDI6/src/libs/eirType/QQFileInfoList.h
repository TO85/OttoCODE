// file: {EIRC2 repo)./src/libs/eirType/QQFileInfoList.h
#pragma once
#include "eirType.h"

#include <QFileInfoList>
#include <QString>

#include "QQFileInfo.h"

class EIRTYPE_EXPORT QQFileInfoList : public QFileInfoList
{
public:
    QQFileInfoList();
    QQFileInfoList(const QFileInfoList &other);
    QQFileInfo at(const int index) const;
    void dump(const QString &title=QString()) const;
};

uint qHash(const QFileInfo &fileInfo);
