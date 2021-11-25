#pragma once
#include "eirType.h"

#include <QtCore/QVector>

template <typename T> class QQVector : public QVector<T>
{
public:
    QQVector(const int size) : QVector<T>(size) {;}
    T &at(const int index)
    { if (index >= QVector<T>::size()) QVector<T>::resize(index+1); return operator[](index); }
    T at(const int index) const { return QVector<T>::at(index); }
    T &operator [] (const int index) { return at(index); }
    T &operator [] (const int index) const { return at(index); }
};

