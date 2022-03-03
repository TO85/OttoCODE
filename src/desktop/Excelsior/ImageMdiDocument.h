#pragma once

#include <QObject>

#include <QQFileInfo>
#include <ImageViewWidget>

class ImageMdiDocument : public QObject
{
    Q_OBJECT
public:
    explicit ImageMdiDocument(QObject *parent = nullptr);
    explicit ImageMdiDocument(const QQFileInfo &fileInfo, QObject *parent = nullptr);

public:
    bool load(const QQFileInfo &fi);
    bool load();

private:
    ImageViewWidget * mpViewWidget=nullptr;

    /* ------- generated -------- */
    Q_PROPERTY(QString mName READ name WRITE name NOTIFY nameChanged);
    Q_PROPERTY(QQFileInfo FileInfo READ fileInfo WRITE fileInfo NOTIFY fileInfoChanged);
    QString mName;
    QQFileInfo mFileInfo;
public:
    QString name() const;
    const QQFileInfo &fileInfo() const;
public slots:
    void fileInfo(const QQFileInfo &newFileInfo);
private slots:
    void name(const QString &newName);
signals:
    void nameChanged(const QString &name);
    void fileInfoChanged(const QQFileInfo &FileInfo);
};

