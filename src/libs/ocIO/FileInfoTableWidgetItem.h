#pragma once

#include <QTableWidgetItem>

#include <QFileInfo>

class FileInfoTableWidgetItem : public QTableWidgetItem
{
public:
    FileInfoTableWidgetItem();

private:
    QFileInfo mFileInfo;
};

