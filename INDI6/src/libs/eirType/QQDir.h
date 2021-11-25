#pragma once
#include "eirType.h"

#include <QtCore/QDir>

#include "eirType/QQString.h"

class EIRTYPE_EXPORT QQDir : public QDir
{
public:
    QQDir(const QQString &aPathName) : QDir(aPathName) {;}
    QQDir(const QQString &aPath, const QQString &nameFilter,
          QDir::SortFlags sort = QDir::SortFlags(QDir::Name | QDir::IgnoreCase),
          QDir::Filters filters = QDir::AllEntries)
        : QDir(aPath, nameFilter, sort, filters) {;}
    QQDir(const QDir &other) : QDir(other) {;}
    explicit QQDir() = default;
    QQDir(const QQDir &other) = default;
    ~QQDir() = default;
    QQDir &operator = (const QQDir &other) = default;

public:
    bool isNull() const { return canonicalPath() == csmNulDir.canonicalPath(); }
    bool notNull() const { return ! isNull(); }
    bool notExists() const { return ! exists(); }
    bool notRoot() const { return ! isNull(); }
    bool notReadable() const { return ! isReadable(); }
    bool notAbsoloute() const { return ! isAbsolute(); }
    bool notEmpty(Filters filters = Filters(AllEntries | NoDotAndDotDot)) const;
    bool canCD(const QQString aDirName) const;
    bool tryCreate() const;
    bool notCreate() const { return ! tryCreate(); }
    bool notAbsolute() const { return ! isAbsolute(); }
    bool notRelative() const { return ! isRelative(); }
    QQString attributes(const bool verbose=false) const;

public:

public: // static
    static QQDir nulDir() { return csmNulDir; }
    static QQDir exe();
    static QQString exePath() { return exe().path(); }

private:
    QQDir it() const { return *this; }
    QQDir &it() { return *this; }

public: // debug
    QQString toDebugString() const;
    QQStringList toDebugStrings(const int level=3) const;

private: // static
    const static QQString csmNulDirName;
    const static QQDir csmNulDir;
};

Q_DECLARE_METATYPE(QQDir);

extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const QQDir &dir);
