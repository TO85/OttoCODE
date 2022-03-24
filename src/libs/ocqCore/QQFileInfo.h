#pragma once
#include "ocqCore.h"

#include <QFileInfo>

#include <QMetaType>

#include "QQDir.h"
#include "QQString.h"

class OCQCORE_EXPORT QQFileInfo : public QFileInfo
{
public:
    QQFileInfo(const QQString &fileName);
    QQFileInfo(const QQDir &dir, const QQString &fileName);

public:
    bool notExists() const { return ! exists(); }

public: // QMetaType
    QQFileInfo() = default;
    ~QQFileInfo() = default;
    QQFileInfo(const QQFileInfo &other) = default;
    QQFileInfo &operator = (const QQFileInfo &other) = default;
};

extern OCQCORE_EXPORT bool operator == (const QQFileInfo &lfi, const QQFileInfo &rfi);
extern OCQCORE_EXPORT bool operator <  (const QQFileInfo &lfi, const QQFileInfo &rfi);

Q_DECLARE_METATYPE(QQFileInfo);

#if 0
class EIRTYPE_EXPORT QQFileInfo : public QFileInfo
{
public:
    typedef QVector<QQFileInfo> Vector;

public:
    QQFileInfo() = default;
    QQFileInfo(const QQFileInfo &other) = default;
    QQFileInfo(const QFileInfo &other) : QFileInfo(other) {;}
    QQFileInfo(const QString &pathFileName) : QFileInfo(pathFileName) {;}
    QQFileInfo(const QQDir &pathDir , const QQString &fileName);
    QQFileInfo(const QDir &dir , const QQString &fileName);
    ~QQFileInfo() = default;
    QQFileInfo &operator=(const QQFileInfo &other) = default;

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    QQDir dir() const;
    QQString attributes() const;
    QQString allAttributes() const;
    QQString suffix() const { return QQString(QFileInfo::suffix()); }
    bool isSuffix(const QQString &aOther) const;
    bool tryIsFile(const QIODevice::OpenMode mode=QIODevice::ReadOnly) const;
    bool tryIsDir() const { return tryHasDir() && ! tryIsFile(); }
    bool tryHasDir() const;

public:
    void setFile(const QQString &aFileName);
    void setFile(const QFile &file) { QFileInfo::setFile(file); }
    void setFile(const QDir &dir, const QQString &aFileName) { QFileInfo::setFile(dir, aFileName); }
    void setBaseFileName(const QQString &aBaseName);
    void setSuffix(const QQString &aSuffix);
    void setDir(const QQDir &aDir);
    void appendFileName(const QQString &s, const QQString &glue="+");
    void nullify();

private:
    QQFileInfo &it() { return *this; }
    QQFileInfo it() const { return *this; }

public: // static
    static bool tryIsFile(const QQString &filePathName,
            const QIODevice::OpenMode mode=QIODevice::ReadOnly);
    static bool tryIsDir(const QQString &pathName);

public: // debug
    QStringList toDebugStrings() const;
};

Q_DECLARE_METATYPE(QQFileInfo);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQFileInfo &fi);

#endif
