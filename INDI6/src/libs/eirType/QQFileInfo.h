#pragma once
#include "eirType.h"

#include <QtCore/QFileInfo>

#include <QtCore/QDir>
#include <QtCore/QMetaType>
#include <QtCore/QVariant>
#include <QtCore/QVector>

#include "Boolean.h"
#include "QQDir.h"
#include "QQString.h"

class EIRTYPE_EXPORT QQFileInfo : public QFileInfo
{
public:
    typedef QVector<QQFileInfo> Vector;

public:
    QQFileInfo() = default;
    QQFileInfo(const QQFileInfo &other) = default;
    QQFileInfo(const QFileInfo &other) : QFileInfo(other) {;}
    QQFileInfo(const QString &pathFileName) : QFileInfo(pathFileName) {;}
    QQFileInfo(const QQDir &pathDir , const QQString &fileName)
        : QFileInfo(pathDir, fileName) {;}
    QQFileInfo(const QDir &dir , const QQString &fileName)
        : QFileInfo(dir, fileName) {;}
    ~QQFileInfo() = default;
    QQFileInfo &operator=(const QQFileInfo &other) = default;

    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    QQDir dir() const { return QQDir(QFileInfo::dir()); }
    QQString attributes() const;
    QQString allAttributes() const;
    QQString suffix() const { return QQString(QFileInfo::suffix()); }
    bool tryIsFile(const QIODevice::OpenMode mode=QIODevice::ReadOnly) const;
    bool tryIsDir() const { return tryHasDir() && ! tryIsFile(); }
    bool tryHasDir() const;


    void setFile(const QString &aFileName) { QFileInfo::setFile(aFileName); }
    void setFile(const QFile &file) { QFileInfo::setFile(file); }
    void setFile(const QDir &dir, const QString &aFileName) { QFileInfo::setFile(dir, aFileName); }
    void nullify();

private:
    QQFileInfo &it() { return *this; }
    QQFileInfo it() const { return *this; }

public: // static
    static bool tryIsFile(const QQString &filePathName,
            const QIODevice::OpenMode mode=QIODevice::ReadOnly);
    static bool tryIsDir(const QQString &pathName);

public:
//    static QQFileInfo nullFileInfo;

private:

public: // debug
    QStringList toDebugStrings() const;

private:
};

Q_DECLARE_METATYPE(QQFileInfo);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQFileInfo &fi);

