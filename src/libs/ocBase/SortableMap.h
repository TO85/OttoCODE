#pragma once

#include <QMap>
#include "Sortable.h"

#include "List.h"

template <typename T>
class SortableMap : public QMap<Sortable, T>
{
public:
    SortableMap() {;}
    void add(const T & t) { insert(Sortable(t), t); }
    const T value(const T & t) const { value(Sortable(t)); }
    T & value(const T & t) { value(Sortable(t)); }
    T & operator [] (const T & t) { return value(t); }
    T operator [] (const T & t) const  { return value(t); }
    List<T> values() const { return values(); }
};

