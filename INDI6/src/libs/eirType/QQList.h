#pragma once
#include "eirType.h"

#include <QtCore/QList>
#include <QtCore/QVector>

template<typename T> class QQList : public QList<T>
{
public:
    QQList<T>(const QList<T> &other) : QList<T>(other) {;}
    QQList<T>() = default;
    QQList<T>(const QQList<T> &other) = default;
    QQList<T> &operator=(const QQList<T> &) = default;
    ~QQList<T>() = default;

public:
    bool notEmpty() const { return ! QQList<T>::isEmpty(); }

public:
    void resize(const int aCount) { fill(aCount); }
    void fill(const int aCount) { it() = QVector<T>(aCount).toList(); }
    void reverse()
    {
        for(int ix = 0, sz = QList<T>::size(), max = (sz / 2); ix < max; ix++)
            QList<T>::swapItemsAt(ix, sz -(1 + ix));
    }
    QQList<T> remove(const int position, const int count)
    {
        int n = count;
        while (--n > 0)
            QQList<T>::removeAt(position);
        return it();
    }

private:
    QQList<T> &it() { return *this; }
    QQList<T> it() const { return *this; }
};
