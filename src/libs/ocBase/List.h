#pragma once
/*! @file ListT.h Declaration of List Template
 */

#include <QVector>

template <typename T> class List
{
public:
    List() {;}
    List(const T &t) { mList.append(t); }
    List(const List<T> &ts) { mList.append(ts); }
    List(const qsizetype size, const T &fill=T()) : mList(size, fill) {;}

public:
    int count() const { return mList.count(); }
    bool isEmpty() const { return mList.isEmpty(); }
    bool notEmpty() const { return ! isEmpty(); }
    List<T> values() const { return mList; }
    T first() const { return mList.first(); }
    List<T> first(const int n) const { return mList.first(n); }
    List<T> mid(const int k, const int n=-1) const { return mList.mid(k, n); }
    T last() const { return mList.last(); }

public:
    void clear() { mList.clear(); }
    void append(const T &t) { mList.append(t); }
    T takefirst() { return mList.takefirst(); }

private:
    QList<T> mList;
};
