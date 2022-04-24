#include "SysProcessEnv.h"

SysProcessEnv::SysProcessEnv()
{
    qDebug() << Q_FUNC_INFO << cmProcEnv.toStringList();
    KeySeg tPathKey;

    for (QString skey : cmProcEnv.keys())
    {
        qDebug() << skey << cmProcEnv.value(skey);
        if (0 == skey.compare("PATH", Qt::CaseInsensitive))
            tPathKey = KeySeg(skey);
        else
            mKeyList.append(KeySeg(skey));
    }

    QStringList tPathDirNames = cmProcEnv.value(tPathKey).split(':');
    for (QString pathName : tPathDirNames)
        mPathDirList.append(QQDir(pathName));
}

int SysProcessEnv::keyCount() const
{
    return mKeyList.count();
}

bool SysProcessEnv::isValidKeyIndex(const int ix) const
{
    return ix >= 0 && ix < keyCount();
}

KeySeg SysProcessEnv::key(const int ix) const
{
    return isValidKeyIndex(ix) ? keyList().at(ix) : KeySeg();
}

KeySegList SysProcessEnv::keyList() const
{
    return mKeyList;
}

QString SysProcessEnv::value(const int ix) const
{
    return  isValidKeyIndex(ix)
            ? cmProcEnv.value(key(ix))
            : QString();
}

int SysProcessEnv::pathCount() const
{
    return mPathDirList.count();
}

bool SysProcessEnv::isValidPathIndex(const int ix) const
{
    return ix >= 0 && ix < pathCount();
}

QQDir SysProcessEnv::pathDir(const int ix) const
{
    return isValidPathIndex(ix) ? pathDirList().at(ix) : QQDir();
}

QQDir::List SysProcessEnv::pathDirList() const
{
    return mPathDirList;
}
