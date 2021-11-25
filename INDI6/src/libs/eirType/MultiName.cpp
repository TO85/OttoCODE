// file: ./Library/Base/MultiName.cpp
#include "MultiName.h"

#include <eirXfr/Debug.h>

// static
const uint MultiName::scmHashSeed = *((uint *)("MultNameHashSeed"));
QChar MultiName::smDelimiter('/');

/*! \class MultiName
 *  \brief The MultiName class provides a multi-element name.
 *  \sa BasicName
 *  \sa Type Library
 *  \sa PersonName
 *  \note This and the BasicName class provide variable-type
 *      names, not intended for names of people.
 *      See (eventually) the PersonName class in the
 *      Type (TBD?) library for that use.
 *  \since v1.01
 */

MultiName::MultiName(const QString &stringNames)
{
    set(stringNames);
}

MultiName::MultiName(const QQString & qsNames)
{
    set(qsNames);
}

MultiName::MultiName(const char *cNames)
{
    set(QString::fromLocal8Bit(cNames));
}

MultiName::MultiName(const QByteArray &baNames)
{
    set(QString::fromLocal8Bit(baNames));
}
#if 0
MultiName::MultiName(const BasicName &segment)
{
    mBasicSegmentNames << segment;
}
#endif
MultiName::MultiName(const BasicName::List & other)
{
    mBasicSegmentNames = other;
}

MultiName::MultiName(const QQStringList &qslNames)
{
    set(qslNames);
}

MultiName::MultiName(const MultiName &base, const MultiName &name)
{
    mBasicSegmentNames = base.mBasicSegmentNames
            + name.mBasicSegmentNames;
}

MultiName::MultiName(const qint64 &aNumber)
{
    if (aNumber)
    {
        QQByteArray tBA(aNumber);
        QQByteArray tHex = tBA.toHex().rightJustified(2 *sizeof(aNumber), '0', false);
        QQStringList tQSL = tHex.segment(16);
        set(tQSL);
    }
}

bool MultiName::isValidIndex(const int ix) const
{
    return ix >= 0 && ix < segmentCount();
}

void MultiName::clear()
{
    mBasicSegmentNames.clear();
}

void MultiName::set(const QQString & qsNames)
{
    clear();
    QQString qs = qsNames.simplified();
    qs.replace(' ', smDelimiter);
    QQStringList qsl = qs.split(smDelimiter, Qt::SkipEmptyParts);
    set(qsl);
}

void MultiName::set(const QQStringList & names)
{
    clear();
    for (QQString s : names)
        mBasicSegmentNames << BasicName(s);
}

void MultiName::prepend(const MultiName &groupName)
{
    if (groupName.notEmpty())
    {
        BasicName::List resultNames;
        resultNames << groupName.mBasicSegmentNames;
        resultNames << mBasicSegmentNames;
        mBasicSegmentNames = resultNames;
    }
}

MultiName MultiName::prepended(const MultiName &groupName) const
{
    BasicName::List result;
    result << groupName.mBasicSegmentNames;
    result << mBasicSegmentNames;
    return result;
}

BasicName MultiName::firstSegment() const
{
    return mBasicSegmentNames.first();
}

MultiName MultiName::firstSegments(int count) const
{
    MultiName result;
    if (notEmpty())
        for (int x = 0; x < qMin(count, segmentCount()); ++x)
            result.mBasicSegmentNames.append(segmentAt(x));
    return result;
}

BasicName MultiName::segmentAt(const int index) const
{
    return isValidIndex(index) ? mBasicSegmentNames.at(index) : BasicName();
}

MultiName MultiName::appended(const BasicName &segment) const
{
    TRACEQFI << segment() << toString();
    MultiName result = *this;
    result.mBasicSegmentNames.append(segment);
    TRACEFNR(result.toString());
    return result;
}
/*
MultiName &MultiName::append(const BasicName &segment)
{
    TRACEQFI << segment() << "append() to" << toString();
    TRACE << BasicName::toStringList(mBasicSegmentNames);
    mBasicSegmentNames.append(segment);
    TRACE << BasicName::toStringList(mBasicSegmentNames);
    TRACE << toString();
    return *this;
}
*/
int MultiName::segmentCount() const
{
    return mBasicSegmentNames.size();
}

int MultiName::compare(const MultiName &other) const
{
    if (sortable() == other.sortable()) return 0;
    if (sortable() <  other.sortable()) return -1;
    else /* sortable() > other       */ return +1;
}

void MultiName::removeFirstSegments(int count)
{
    while (count--)
        if (mBasicSegmentNames.notEmpty())
            mBasicSegmentNames.removeFirst();
}

void MultiName::removeLastSegment()
{
    mBasicSegmentNames.removeLast();
}

BasicName MultiName::lastSegment() const
{
    return mBasicSegmentNames.last();
}

MultiName MultiName::segmentsMid(const int offset, const int count) const
{
    MultiName result(mBasicSegmentNames);
    result.removeFirstSegments(offset);
    if (count > 0) result = result.firstSegments(count);
    return result;
}

QQStringList MultiName::toStringList() const
{
    QQStringList qsl;
    foreach(BasicName bn, mBasicSegmentNames)
        qsl << bn.toString();
    return  qsl;
}

QQString MultiName::toString(const QQString &ifEmpty) const
{
    if (isEmpty()) return ifEmpty;
    return join(getDelimiter());
}

QQString MultiName::operator ()() const
{
    return toString();
}

QVariant MultiName::toVariant() const
{
    return QVariant(toStringList());
}

QQStringList MultiName::stringList(const MultiName::List mnames)
{
    QQStringList rtn;
    foreach (MultiName mname, mnames) rtn << mname.toString();
    return rtn;
}

QQString MultiName::sortable() const
{
    return toString().toLower();
}

uint MultiName::hash() const
{
    return (uint)qHash(sortable(), scmHashSeed);
}

bool MultiName::operator == (const MultiName & other) const
{
    return sortable() == other.sortable();
}

bool MultiName::operator < (const MultiName & other) const
{
    return sortable() < other.sortable();
}
/*
MultiName &MultiName::operator +=(const BasicName &segment)
{
    return append(segment);
}
*/
void MultiName::dump() const
{
    DUMP << toString();
}

// static
QQStringList MultiName::toStringList(const List &mnl)
{
    QQStringList qsl;
    foreach (MultiName mn, mnl) qsl << mn.toString();
    return qsl;
}

// static
MultiName::List MultiName::toList(const QQStringList &qsl)
{
    List mnl;
    for (QQString qs : qsl) mnl << MultiName(qs);
    return mnl;
}

// protected
QString MultiName::join(const QChar & delimiter) const
{
    QString qs;
    if ( ! isEmpty())
    {
        const QString sDelim(delimiter);
        BasicName::List copy = mBasicSegmentNames;
        qs = copy.takeFirst();
        while ( ! copy.isEmpty())
            qs += sDelim + copy.takeFirst().toString();
    }
    return qs;
}

bool MultiName::startsWith(const MultiName &groupName) const
{
    int n = groupName.segmentCount();
    for (int index = 0; index < n; ++index)
        if (segmentAt(index) != groupName.segmentAt(index))
            return false;
    return true;
}

QChar MultiName::getDelimiter() // static
{
    return smDelimiter;
}

void MultiName::setDelimiter(const QChar & value) // static
{
    smDelimiter = value;
}

MultiName::operator QVariant() const
{
    return toVariant();
}

MultiName::operator QString() const
{
    return toString();
}

