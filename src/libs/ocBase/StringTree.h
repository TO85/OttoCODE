#pragma once

#include <QMap>
#include <QMetaType>

#include "String.h"
#include "StringList.h"

class StringTree
{
public:
    StringTree(const StringList &strings) { set(strings); }
    StringTree() = default;
    ~StringTree() = default;
    StringTree(const StringTree &other) = default;
    StringTree &operator = (const StringTree &other) = default;

public:

    void set(const StringList &strings);

private:
    QMap<String, String> mSectionsNodeMap;
};


Q_DECLARE_METATYPE(StringTree);

