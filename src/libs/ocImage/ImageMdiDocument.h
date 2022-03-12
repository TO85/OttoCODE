#pragma once

#include <MdiDocument>

#include <QQFileInfo>

class ImageMdiDocument : public MdiDocument
{
    Q_OBJECT
public:
    explicit ImageMdiDocument(const QQFileInfo &fileInfo, QObject *parent = nullptr);

public:
    bool load(const QQFileInfo &fi);
    bool load();

signals:
    void fileInfoChanged(const QQFileInfo &FileInfo);

private:

};

