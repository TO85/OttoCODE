#include "MdiDocument.h"

MdiDocument::MdiDocument(const QQFileInfo fileInfo, QObject *parent)
    : QObject{parent}
    , mFileInfo(fileInfo)
{
    setObjectName("MdiDocument:"+mFileInfo.baseName());
    mFileInfoDocumentMap.insert(mFileInfo, this);
}

MdiDocument::~MdiDocument()
{
    mFileInfoDocumentMap.remove(mFileInfo);
}

QMap<QQFileInfo, MdiDocument *>MdiDocument:: mFileInfoDocumentMap;
