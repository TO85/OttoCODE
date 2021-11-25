#include "StringTable.h"

StringTable::StringTable(const QQSize aSize)
{
    fill(aSize);
}

int StringTable::count() const
{
    return mSize.area();
}

QQSize StringTable::size() const
{
    return mSize;
}

QQSize StringTable::reserved() const
{
    return mReservedSize;
}

QQString StringTable::at(const QQPoint aRowCol) const
{
    return mStringListList.at(aRowCol.y()).at(aRowCol.x());
}

QQString StringTable::at(const int aRow, const int aCol) const
{
    return mStringListList.at(aRow).at(aCol);
}

QQString &StringTable::at(const QQPoint aRowCol)
{
    return mStringListList[aRowCol.y()][aRowCol.x()];
}

QQString &StringTable::at(const int aRow, const int aCol)
{
    return mStringListList[aRow][aCol];

}

QQStringList StringTable::headers() const
{
    return mHeaders;
}

QQStringList &StringTable::headers()
{
    return mHeaders;
}

QQString StringTable::header(const int aCol) const
{
    return mHeaders.at(aCol);
}

QQString StringTable::header(const int aCol)
{
    return mHeaders[aCol];
}

QQStringList StringTable::row(const int aRow) const
{
    return mStringListList.at(aRow);
}

QQStringList StringTable::col(const int aCol) const
{
    QQStringList result;
    result.reserve(mSize.height());
    for (int row = 0; row < mSize.height(); ++row)
        result.append(at(row, aCol));
    return result;
}

QQStringList StringTable::row(const int aRow)
{
    return mStringListList[aRow];
}

void StringTable::set(const QQPoint aRowCol, const QQString &aString)
{
    mStringListList[aRowCol.y()][aRowCol.x()] = aString;
}

void StringTable::set(const int aRow, const int aCol, const QQString &aString)
{
    mStringListList[aRow][aCol] = aString;
}

void StringTable::set(const int aRow, const QQList<QQString> &aRowStrings)
{
    mStringListList[aRow] = aRowStrings;
}

void StringTable::setHeaders(const QQStringList &aHeaders)
{
    mHeaders = aHeaders;
}

void StringTable::setHeader(const int aCol, const QQString &aColHeader)
{
    mHeaders[aCol] = aColHeader;
}

void StringTable::clear()
{
    mStringListList.clear(), mHeaders.clear();
}

void StringTable::resize(const QQSize aSize)
{
    mStringListList.resize(aSize.rows());
    for (int row = 0; row < aSize.rows(); ++row)
        mStringListList[row].resize(aSize.cols());
    mSize = mReservedSize = aSize;
}

void StringTable::reserve(const QQSize aReservedSize)
{
    QQSize tSize(powerOfTwoUp(qMax(mAllocatedSize.rows(), aReservedSize.rows())),
                 powerOfTwoUp(qMax(mAllocatedSize.cols(), aReservedSize.cols())));
    mStringListList.resize(tSize.rows());
    for (int row = 0; row < tSize.rows(); ++row)
        mStringListList[row].resize(tSize.cols());
    mReservedSize = tSize;
}

void StringTable::fill(const QQSize aReservedSize, const QQString &aFillString)
{
    clear();
    QQList<QQString> rowString;
    while (rowString.count() < aReservedSize.cols())
        rowString.append(aFillString);
    while (mStringListList.count() < aReservedSize.rows())
        mStringListList.append(rowString);
    mSize = mReservedSize = aReservedSize;
}

void StringTable::allocate(const QQSize aAllocatedSize)
{
    QQSize tSize(powerOfTwoUp(qMax(mAllocatedSize.rows(), aAllocatedSize.rows())),
                 powerOfTwoUp(qMax(mAllocatedSize.cols(), aAllocatedSize.cols())));
    mStringListList.resize(tSize.rows());
    for (int row = 0; row < tSize.rows(); ++row)
        mStringListList[row].resize(tSize.cols());
    mAllocatedSize = tSize;
}
