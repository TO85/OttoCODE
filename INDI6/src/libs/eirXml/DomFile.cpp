#include "DomFile.h"

#include "ElementAttributeMap.h"

DomFile::DomFile(QObject *parent)
    : QObject(parent)
{
    setObjectName("DomFile:");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

DomFile::DomFile(const QQFileInfo &aFileInfo, QObject *parent)
    : QObject(parent)
    , mFileInfo(aFileInfo)
{
    setObjectName("DomFile:"+aFileInfo.baseName());
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

QQDomElement DomFile::childElement(const int ix)
{
    TRACEQFI << ix << childElementCount();
    return (ix >= 0 && ix < childElementCount())
            ? mChildElementList.value(ix)
            : QQDomElement();
}

void DomFile::clear()
{
    mKey.clear();
    mStatus.clear();
    mFileInfo.nullify();
    mBytes.clear();
    mDocument.clear();
    mChildElementNameList.clear();
    mChildElementList.clear();
}

DomStatus DomFile::loadDocument()
{
    TRACEQFI << mFileInfo;
    DomStatus status;
    status.set(mFileInfo);
    status.expect("FileInfo exists(%1)", mFileInfo.exists(), QtInfoMsg, QtWarningMsg);
    QFile *pFile = new QFile(mFileInfo.absoluteFilePath(), parent());
    pFile->open(QIODevice::ReadOnly | QIODevice::Text);
    status.expect("File isReadable(%1)", pFile->isReadable(), QtInfoMsg, QtCriticalMsg);
    if (status.type().isError()) return mStatus = status;                         /* /====\ */

    mBytes = pFile->readAll();
    pFile->close();
    pFile = nullptr;
    status.set(mBytes);
    status.expect("File Bytes notEmpty(%1)", mBytes.notEmpty(), QtInfoMsg, QtCriticalMsg);
    if (status.type().isError()) return mStatus = status;                         /* /====\ */

    status.setDocument(&mDocument, mFileInfo.completeBaseName(), mBytes);
    status.expect("Document notNull(%1)", mDocument.notNull(), QtInfoMsg, QtWarningMsg);
    QQDomElement tRootDE = mDocument.documentElement();
    status.expect("RootElement notNull(%1)", tRootDE.notNull(), QtInfoMsg, QtWarningMsg);

    return mStatus.append(status);
}

int DomFile::loadChildElements()
{
    TRACEFN;
    QQDomElement tChildElement = rootElement().firstChildElement();
    while (tChildElement.notNull())
    {
        mChildElementNameList.append(tChildElement.nodeName());
        mChildElementList.append(tChildElement);
        tChildElement = rootElement().nextSiblingElement();
    }
    return mChildElementList.count();
}

DomStatus DomFile::loadDocument(const QQFileInfo &aFileInfo)
{
    TRACEQFI << aFileInfo;
    mFileInfo = aFileInfo;
    return loadDocument();
}

QQString DomFile::toDebugString() const
{
    QQString result = "{DomFile " + mKey() + ": ";
    if (mDocument.notNull())
    {
        result += QQString("DomDocument: %1 RootElement %2: %3 attributes %4 children")
                .formatMessage(mDocument.doctypeName(),
                               rootElement().tagName(),
                               rootElement().attributeCount(),
                               rootElement().childNodeCount());
    }
    else if (mBytes.notEmpty())
    {
        result += mBytes.toDebugString();
    }
    else if (mFileInfo.notNull())
    {
        result += mFileInfo.toDebugStrings().join(";");
    }
    else
    {
        result += "{empty}";
    }

    return result;
}

QQStringList DomFile::toInfoStrings(const int level) const
{
    QQStringList result;
    result << QQString("Key: %1 Status: %2")
              .formatMessage(key()(), status().type().toInfoString());
    if (fileInfo().notNull())
        result << QQString("   File: %1").formatMessage(fileInfo().filePath());
    if (level > 0 && bytes().isEmpty())
        result << bytes().toInfoString();
    if (level > 1 && document().notNull())
    {
        result << QQString("   DDoc: %1").formatMessage(document().doctypeName());
        result << QQString("   Root: %1").formatMessage(rootElement().tagName());
    }
    if (level > 2 && document().notNull())
    {
        QQStringList tAttributeList = rootElement().attributeNameValueList();
        result << QQString("   Attributes: %1").formatMessage(tAttributeList.count());
        result.append(tAttributeList, 8);
    }
    if (level > 2 && document().notNull())
    {
        const int tMax = (level > 2) ? level : 4;
        result << QQString("   Elements: %1").formatMessage(childElementNames().count());
        result.append(childElementNames().first(tMax), 8);
    }
    return result;
}

QQStringList DomFile::toDebugStrings() const
{
    QQStringList result;
    result << "{DomFile:>";
    result << "Name = >" + objectName() + "<";
    result << "Key = >" + mKey() + "<";
    result << mStatus.toDebugStrings();
    result << mFileInfo.toDebugStrings();
    result << mBytes.toDebugString(64);
    result << mDocument.toDebugStrings();
    result << rootElement().attributeNameValueList();
    result << rootElement().childElementNameList();
    result << "<DomFile}";
    return result;
}

QDebug operator << (QDebug dbg, const DomFile &df)
{
    for (auto s : df.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}
