#pragma once
#include "ocBase.h"

#include <QMetaType>
#include <QString>
#include <QStringList>

class TOBASE_EXPORT Key
{
public:
    Key(const QString &qs);
    Key(const QStringList &qsl);
    Key(const char *pch);
    Key() = default;
    ~Key() = default;
    Key(const Key &other) = default;
    Key &operator = (const Key &other) = default;

public:
    int count() const;
    Key first(const int k=1) const;
    Key last() const;
    QString toString() const;
    operator QString () { return toString(); }

protected:
    static QChar separator();
    static void setSeparator(const QChar &c);

protected:
    static QChar smSeparator;

private:
    QStringList mSegments;
};

Q_DECLARE_METATYPE(Key);

