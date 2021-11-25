#pragma once
//! @file: StringTable.h
#include "eirType.h"

#include <QtCore/QMetaType>

#include "QQList.h"
#include "QQSize.h"
#include "QQPoint.h"
#include "QQString.h"
#include "QQStringList.h"

class EIRTYPE_EXPORT StringTable
{
public:
    StringTable(const QQSize aSize);
    explicit StringTable() = default;
    StringTable(const StringTable &other) = default;
    ~StringTable() = default;
    StringTable &operator = (const StringTable &other) = default;

public: // access
    int count() const;
    QQSize size() const;
    QQSize reserved() const;
    QQString at(const QQPoint aRowCol) const;
    QQString at(const int aRow, const int aCol) const;
    QQString &at(const QQPoint aRowCol);
    QQString &at(const int aRow, const int aCol);
    QQStringList headers() const;
    QQStringList &headers();
    QQString header(const int aCol) const;
    QQString header(const int aCol);
    QQStringList row(const int aRow) const;
    QQStringList col(const int aCol) const;
    QQStringList row(const int aRow);
    QQString operator [] (const QQPoint aRowCol) const;
    QQString &operator [] (const QQPoint aRowCol);
    QQStringList operator [] (const int aRow) const;
    QQStringList &operator [] (const int aRow);

public: // commands
    void set(const QQPoint aRowCol, const QQString &aString);
    void set(const int aRow, const int aCol, const QQString &aString);
    void set(const int aRow, const QQList<QQString> &aRowStrings);
    void setHeaders(const QQStringList &aHeaders);
    void setHeader(const int aCol, const QQString &aColHeader);
    void clear();
    void resize(const QQSize aSize);
    void reserve(const QQSize aReservedSize);
    void fill(const QQSize aReservedSize, const QQString &aFillString=QQString());

private: // commands
    void allocate(const QQSize aAllocatedSize);

private:
    QQStringList mHeaders;
    QQList< QQList<QQString> > mStringListList;
    QQSize mSize;
    QQSize mReservedSize;
    QQSize mAllocatedSize;
};

Q_DECLARE_METATYPE(StringTable);
