#pragma once

#include <QObject>
#include "ocqWidgets.h"

#include <QQFileInfo>

class OCQWIDGETS_EXPORT MdiDocument : public QObject
{
    Q_OBJECT
public:
    explicit MdiDocument(const QQFileInfo fileInfo, QObject *parent = nullptr);
    ~MdiDocument();

public:
    QQFileInfo fileInfo() const { return mFileInfo; }

public:
    QQFileInfo &fileInfo() { return mFileInfo; }
    static MdiDocument * document(const QQFileInfo &fi);

signals:

protected:
    QQFileInfo mFileInfo;
    static QMap<QQFileInfo, MdiDocument *> mFileInfoDocumentMap;
};

