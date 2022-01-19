#pragma once
#include "llCore.h"

#include <QMetaType>
#include <QString>
#include <QStringList>

class LLCORE_EXPORT Key
{
public:
    Key(const char *pch);
    Key() = default;
    ~Key() = default;
    Key(const Key &other) = default;
    Key &operator = (const Key &other) = default;

public:
    QString last() const;
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

