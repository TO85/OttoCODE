#pragma once
#include "ocqCore.h"

#include <QDir>
#include <Null>

#include <QList>
#include <QMetaType>

#include "QQString.h"

class OCQCORE_EXPORT QQDir : public QDir
{
public:
    typedef QList<QQDir> List;

public:
    QQDir(const QDir &other) : QDir(other) {;}
    QQDir(const QString &pathName) : QDir(pathName) {;}

public:
    QQString lastPath() const;
    QDir toQDir() const;
    QVariant toVariant() const;
    bool isNull() const;

private:
    QQDir it() const { return *this; }
    QQDir & it() { return *this; }

public: // debug
    QQString attributes() const;
    QQString toDebugString() const;

public: // QMetaType
    QQDir() = default;
    ~QQDir() = default;
    QQDir(const QQDir &other) = default;
    QQDir &operator = (const QQDir &other) = default;
};

extern OCQCORE_EXPORT bool operator <  (const QQDir &lhs, const QQDir &rhs);
extern OCQCORE_EXPORT bool operator == (const QQDir &lhs, const QQDir &rhs);

Q_DECLARE_METATYPE(QQDir);

extern QDebug operator<<(QDebug dbg, const QQDir &dir);


