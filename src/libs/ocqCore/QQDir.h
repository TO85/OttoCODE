#pragma once
#include "ocqCore.h"

#include <QDir>

#include <QMetaType>

class OCQCORE_EXPORT QQDir : public QDir
{
public:
    QQDir(const QString &pathName) : QDir(pathName) {;}

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    QString lastPath() const;

private:
    QQDir it() const { return *this; }
    QQDir & it() { return *this; }

private: // debug
    QString attributes() const;

public: // QMetaType
    QQDir() = default;
    ~QQDir() = default;
    QQDir(const QQDir &other) = default;
    QQDir &operator = (const QQDir &other) = default;
};

extern OCQCORE_EXPORT bool operator <  (const QQDir &lhs, const QQDir &rhs);
extern OCQCORE_EXPORT bool operator == (const QQDir &lhs, const QQDir &rhs);

Q_DECLARE_METATYPE(QQDir);

