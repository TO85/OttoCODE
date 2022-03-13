#pragma once

#include <QMap>
#include <QMetaType>
#include <QStringList>

#include <QQString>

class StringTree
{
public:
    StringTree(const QStringList &strings) { set(strings); }
    StringTree() = default;
    ~StringTree() = default;
    StringTree(const StringTree &other) = default;
    StringTree &operator = (const StringTree &other) = default;

public:

    void set(const QStringList &strings);

private:
    QMap<QQString, QQString> mSectionsNodeMap;
};


Q_DECLARE_METATYPE(StringTree);

