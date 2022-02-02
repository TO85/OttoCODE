/*! @file Named.h Declarations for Named Type template
  *
  */
#pragma once

#include <QMap>

#include "KeyItem.h"
#include "Sortable.h"

/*! @class  Named
  * @brief  Specializes DualMap for case insensitive strings
  */
template <typename  T> class Named
{
public:
    Named(void) {}
    T invalid(void) const
    { return T(); }
    void clear(void)
    { mTKeyMap.clear(), mKeyTMap.clear(); }
    bool isEmpty(void) const
    { return mTKeyMap.isEmpty() || mKeyTMap.isEmpty(); }
    int size(void) const
    { return qMin(mTKeyMap.size(), mKeyTMap.size()); }
    bool contains(const T & t) const
    { return mTKeyMap.contains(t); }
    bool contains(const KeyItem & key) const
    { return mKeyTMap.contains(Sortable(key)); }
    KeyItem key(const T & t) const
    { return contains(t) ? mTKeyMap.value(t) : KeyItem(); }
    T value(const KeyItem & key) const
    { return contains(Sortable(key)) ? mKeyTMap.value(Sortable(key)) : T(); }
    void insert(const KeyItem & key, const T & t)
    { mTKeyMap.insert(t, key), mKeyTMap.insert(Sortable(key), t); }
    T first() const
    { return isEmpty() ? T() : mTKeyMap.constBegin().key(); }
    QList<T> keys(void) const
    { return mTKeyMap.keys(); }
    T last() const; // NEEDDO
    T next(const T & key) const; // NEEDDO
    T previous(const T & key) const; // NEEDDO
    bool remove(const T & t); // NEEDDO
    bool remove(const KeyItem & key); // NEEDDO

private:
    QMap<T,KeyItem> mTKeyMap;
    QMap<Sortable,T> mKeyTMap;
}; // template Named

