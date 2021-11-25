#include "QQFileInfoList.h"

#include <eirXfr/Debug.h>

#include "QQFileInfo.h"

QQFileInfoList::QQFileInfoList() {;}
QQFileInfoList::QQFileInfoList(const QFileInfoList &other)
    : QFileInfoList(other) {;}

QQFileInfo QQFileInfoList::at(const int index) const
{
    return QQFileInfo(QFileInfoList::at(index));
}

void QQFileInfoList::dump(const QString &title) const
{
    DUMP << (title.isEmpty() ? "QQFileInfoList" : title);
    foreach (QQFileInfo fileInfo, *this)
    {
        DUMP << fileInfo.absoluteFilePath() << fileInfo.attributes();
    }
}


uint qHash(const QFileInfo &fileInfo)
{
    return (uint)qHash(fileInfo.filePath());
}
