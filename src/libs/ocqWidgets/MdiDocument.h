#pragma once
#include "ocqWidgets.h"

#include <QObject>

#include <QMap>

#include <QQFileInfo>
#include <QQString>

//#include "MdiMainWindow.h"
class MdiMainWindow;

class OCQWIDGETS_EXPORT MdiDocument : public QObject
{
    Q_OBJECT
public:
    explicit MdiDocument(MdiMainWindow * parent=nullptr);
    MdiDocument(const QQFileInfo & fi, MdiMainWindow * parent=nullptr);
    ~MdiDocument();

public:
    MdiMainWindow * mainWin() const { return mpMainWindow; }
    QQFileInfo fileInfo() const { return mFileInfo; }
    QByteArray bytes() const { return mBytes; }
    QQString filePathName() const { return mFileInfo.filePath(); }

public slots:
    virtual void load();

public:
    QQFileInfo fileInfo(const QQFileInfo fi);
    QByteArray & bytes() { return mBytes; }

public: // static
    static MdiDocument * document(const QQFileInfo &fi);

signals:
    void fileInfoChanged(const QQFileInfo &fi);
    void fileLoad(const QQFileInfo &fi, const bool success);

protected:
    MdiMainWindow * mpMainWindow=nullptr;
    QQFileInfo mFileInfo;
    QFile * mpFile=nullptr;
    QByteArray mBytes;
    static QMap<QQFileInfo, MdiDocument *> smFileInfoDocumentMap;
};

