#pragma once
#include "ocqWidgets.h"

#include <QObject>

#include <QMap>

#include <KeyMap>
#include <QQFileInfo>
#include <QQString>

class MdiMainWindow;
class MdiGridWidget;
class QQMdiArea;

class OCQWIDGETS_EXPORT MdiDocument : public QObject
{
    Q_OBJECT
public:
    explicit MdiDocument(MdiMainWindow * parent=nullptr);
    MdiDocument(const QQFileInfo & fi, MdiMainWindow * parent=nullptr);
    ~MdiDocument();

public:
    MdiMainWindow * mainWin() const { return mpMainWindow; }
    QQMdiArea *mdiArea() const;
    QQFileInfo fileInfo() const { return mFileInfo; }
    QByteArray bytes() const { return mBytes; }
    QQString filePathName() const { return mFileInfo.filePath(); }

public slots:
    virtual void load();

public:
    QQFileInfo fileInfo(const QQFileInfo fi);
    QByteArray & bytes() { return mBytes; }

signals:
    void fileInfoChanged(const QQFileInfo &fi);
    void fileLoad(const QQFileInfo & fileInfo, const bool success);

public: // static
    static MdiDocument * document(const QQFileInfo &fi);

protected:
    MdiMainWindow * mpMainWindow=nullptr;
    QQFileInfo mFileInfo;
    QFile * mpFile=nullptr;
    QByteArray mBytes;
    KeyMap<MdiGridWidget *> mKeyWidgetMap;
    static QMap<QQFileInfo, MdiDocument *> smFileInfoDocumentMap;
};

