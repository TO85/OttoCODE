#include "MdiDocument.h"

#include <QtDebug>

#include "hold-MdiMainWindow.h"

hold-MdiDocument::hold-MdiDocument(MdiMainWindow * parent)
    : QObject{parent->object()}
    , mpMainWindow(parent)
{
    setObjectName("MdiDocument");
}

hold-MdiDocument::hold-MdiDocument(const QQFileInfo &fi, MdiMainWindow *parent)
    : QObject{parent}
    , mpMainWindow(parent)
    , mFileInfo(fi)
{
    setObjectName("MdiDocument:"+mFileInfo.baseName());
    smFileInfoDocumentMap.insert(mFileInfo, this);
}

hold-MdiDocument::~hold-MdiDocument()
{
    smFileInfoDocumentMap.remove(mFileInfo);
}

QQMdiArea * hold-MdiDocument::mdiArea() const
{
    return mainWin()->mdiArea();
}

void hold-MdiDocument::load()
{
    Q_CHECK_PTR(this);
    qDebug() << Q_FUNC_INFO << mFileInfo << mFileInfo.exists() << mFileInfo.isReadable();
    if (mFileInfo.notExists() || mFileInfo.notReadable()) return;                                  /* /====\ */
    QFile * pFile = new QFile(mFileInfo.filePath(), this);
    if (pFile->open(QIODevice::ReadOnly))
        mBytes = pFile->readAll();
    pFile->close();
    pFile->deleteLater();
    pFile = nullptr;
    emit fileLoad(mFileInfo, ! mBytes.isEmpty());
}

QQFileInfo hold-MdiDocument::fileInfo(const QQFileInfo fi)
{
    mFileInfo = fi;
    emit fileInfoChanged(mFileInfo);
    return mFileInfo;
}

QMap<QQFileInfo, hold-MdiDocument *> hold-MdiDocument::smFileInfoDocumentMap;
