#include "QQStringList.h"

#include <tgmath.h>

#include <eirXfr/Debug.h>

#include "QQSize.h"

QQStringList::QQStringList(const QList<QQString> &other)
{
    for (QQString s : other) append(s());
}

QQStringList::QQStringList(const QQList<QQString> &other)
{
    for (QQString qqst : other) append(qqst);
}

QQStringList::QQStringList(const int aCount, const QQString &aFillString)
{
    fill(aCount, aFillString);
}

QQStringList::QQStringList(const QList<QString> &other)
{
    for (QString qst : other) append(QQString(qst));
}

QQStringList QQStringList::first(const int n) const
{
    QQStringList result, copy = it();
    while (copy.notEmpty() && result.count() < n)
        result << copy.takeFirst();
    return result;
}

QQStringList QQStringList::reversed() const
{
    QQList<QString> copy = it();
    copy.reverse();
    QQStringList result = copy;
    return result;
}

void QQStringList::append(const QQStringList &other, const int indexWidth)
{
    int index=0;
    if (indexWidth)
    {
        for ( QQString s : other )
            append(s);
    }
    else
    {
        for ( QQString s : other )
            append(QQString("%1: %2").arg(++index, indexWidth).arg(s));
    }
}

void QQStringList::prepend(const QQStringList &other)
{
    TRACEQFI << other;
    for ( QQString s : other.reversed())
        QStringList::prepend(s());
}

QQStringList QQStringList::remove(const int pos, const int num)
{
    TRACEQFI << pos << num << count();
    AEXPECT(pos >= 0 && pos < count());
    int n = num;
    while (n > 0 && pos < count())
        removeAt(pos);
    return it();
}

QQString QQStringList::join(const QQString &separator) const
{
    QQString result;
    if (isEmpty()) return result;                                     /* /========\ */
    QQStringList copy = it();
    result = copy.takeFirst();
    while (copy.notEmpty()) result += separator + copy.takeFirst();
    return result;
}

QQStringList QQStringList::subSample(const int nList, const int nString)
{
    QQStringList result, copy = it();
    if (nList <= 1 && nString <= 1) return copy;                        /* /====\ */
    copy.remove(0, nList / 2);
    while (copy.notEmpty())
    {
        QQString takenString = copy.takeFirst();
        QQString sampleString = (nString <= 1) ? takenString : takenString.subSample(nString);
        result << sampleString;
        copy.remove(0, nList - 1);
    }
    return it() = result;
}

void QQStringList::fill(const int aCount, const QQString &aFillString)
{
    clear();
    while (count() < aCount) append(aFillString);
}

/* ---------------------- static ------------------------- */

QQStringList QQStringList::intersected(const QQStringList &aList, const QQStringList &with)
{
    QQStringList result;
    for (QQString s : with)
        if (aList.contains(s))
            result << s;
    return result;
}
/* ---------------------- debug ------------------------- */

QQStringList QQStringList::toDebugStrings(const QQSize maxSize) const
{
    QQStringList result;
    if (isEmpty()) { result << "{QQStringList: empty}"; return result; }    /* /====\ */
    int mw = 0;
    const int n = count();
    const int xw = log10(n) + 1;
    for (int ix = 0; ix < qMin(n, maxSize.height()); ++ix)
        mw = qMax(mw, at(ix).count());
    const int sw = log10(mw) + 1;
    result << QString("{QQStringList: %1>").arg(n);
    for (int ix = 0; ix < qMin(n, maxSize.height()); ++ix)
        result << QQString("%1: %2 %3").arg(ix, xw).arg(at(ix).count(), sw)
                  .arg((maxSize.width() && at(ix).count() > maxSize.width())
                       ? ">" + at(ix).left(maxSize.count()) + "< ..."
                            : ">" + at(ix) + "<");
    result << QString("<QQStringList}");
    return result;
}

/* ---------------------- non-member ------------------------- */

QDebug operator << (QDebug dbg, const QQStringList &qsl)
{
#if 0
    const int n = qsl.count();
    for (int ix = 0; ix < n; ++ix)
        dbg << qsl.at(ix);
#else
    for (QQString s : qsl.toDebugStrings())
        dbg << s << Qt::endl;
#endif
    return dbg;
}
