#pragma once

#include <QObject>

class ImageFileFormatManager : public QObject
{
    Q_OBJECT
public:
    explicit ImageFileFormatManager();

signals:

};

Q_GLOBAL_STATIC(ImageFileFormatManager, gpImageFileFormatManager);

