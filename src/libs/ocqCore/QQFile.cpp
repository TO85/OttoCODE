#include "QQFile.h"

QQFile::QQFile(QObject *parent) : QFile{parent} {;}

QByteArray QQFile::readFile(const QQFileInfo &fileInfo)
{
    QByteArray result;
    QFile tFile(fileInfo.filePath());
    if (tFile.open(QIODevice::ReadOnly | QIODevice::ExistingOnly))
    {
        result = tFile.readAll();
        tFile.close();
    }
    return result;
}

