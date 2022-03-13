#pragma once
#include "ocqCore.h"

#include <QDir>

#include <QMetaType>

class OCQCORE_EXPORT QQDir : public QDir
{
public:
    QQDir(const QDir &other) : QDir(other) {;}
    QQDir(const QString &pathName) : QDir(pathName) {;}
    QQDir() = default;
    ~QQDir() = default;
    QQDir(const QQDir &other) = default;
    QQDir &operator = (const QQDir &other) = default;

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    QString lastPath() const;

public: // static
    static QDir nullDir() { return smNullDir; }

private:
    QQDir it() const { return *this; }
    QQDir & it() { return *this; }

private: // debug
    QString attributes() const;

private: // static
    static QDir smNullDir;
};

extern OCQCORE_EXPORT bool operator <  (const QQDir &lhs, const QQDir &rhs);
extern OCQCORE_EXPORT bool operator == (const QQDir &lhs, const QQDir &rhs);

Q_DECLARE_METATYPE(QQDir);

