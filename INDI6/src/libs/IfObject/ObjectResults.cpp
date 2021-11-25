#include "ObjectResults.h"

#include <QtCore/QByteArray>
#include <QtCore/QDataStream>

#include <eirXfr/Debug.h>

ObjectResults::Item::List ObjectResults::itemList(const bool reversed) const
{
    ObjectResults::Item::List result = itemMap().values();
    if (reversed) result.reverse();
    return result;
}

ObjectResults::Item ObjectResults::rankItem(const int rank) const
{
    for (ObjectResults::Item ori : itemList())
        if (ori.rank() == rank)
            return ori;
    return ObjectResults::Item();
}

DetectRectMap ObjectResults::itemResults() const
{
    DetectRectMap result;
    foreach (ObjectResults::Item item, itemList())
        result << item.resultRect();
    TRACEQFI << itemList() << result;
    return result;
}

ObjectResults::operator QVariant() const
{
    QVariant result;
    result.setValue(it());
    return result;
}

void ObjectResults::set(const ObjectResults &other)
{
    mItemMap = other.mItemMap;
    mOrphanRects = other.mOrphanRects;
}

void ObjectResults::setItems(const ObjectResults::Item::List aList)
{
    clearItems();
    for (ObjectResultItem ori : aList) append(ori);
}

// ------------------------------------- static ---------------------------------------



// ------------------------------------- debug ---------------------------------------

QQStringList ObjectResults::toDebugStrings() const
{
    QQStringList result;
    result << QString("{ObjectResults: maxScore=%1, %2 Items}").arg(maxScore()).arg(mItemMap.count());
    foreach (ObjectResults::Item ori, mItemMap) result << ori.toDebugStrings();
    result << QString("{ObjectResults: %1 Orphans}").arg(mOrphanRects.count());
    foreach (DetectRect dr, mOrphanRects) result << dr.toDebugString();
    return result;
}

// ------------------------------------- private  ---------------------------------------



// ------------------------------------- non-member  ---------------------------------------

QDebug operator << (QDebug dbg, const ObjectResults &objres)
{
    foreach (QString s, objres.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}


/* ================================== Item sub-class ================================ */

QRectList ObjectResults::Item::includedQRectList() const
{
    QRectList result;
    for (DetectRect dr : mIncludedResults) result << dr.rect().toQRect();
    return result;
}

QVariant ObjectResults::Item::toVariant() const
{
    QVariant result;
    result.setValue(it());
    return result;
}

void ObjectResults::Item::clear()
{
    mResult.nullify();
    mIncludedResults.clear();
    mRank = 0;
    mQuality.nullify();
}

DetectRect ObjectResults::Item::unifiedDetectRect() const
{
    TRACEQFI << toDebugStrings();
    DetectRect result = includedResults().united();
    SCRect scrc = result.rect().squaredByArea();
    result.setRect(scrc);
    DUMPVAL(result);
    return result;
}

// ------------------------------------- Item sub-class static  ---------------------------------------

ObjectResults::Item ObjectResults::Item::fromVariant(const QVariant &vari)
{
    ObjectResults::Item result;
    QByteArray ba = vari.toByteArray();
    QDataStream ds(ba);
    QVariant v;
    DetectRect dr;
    int i;
    qreal f;
    ds >> v; dr = qvariant_cast<DetectRect>(v); result.setResultRect(dr);
    ds >> i;
    while (--i) { ds >> v; dr = qvariant_cast<DetectRect>(v); result.append(dr); }
    ds >> i; result.setRank(i);
    ds >> f; result.setQualityDistance(f);
    return result;
}

QQStringList ObjectResults::Item::toDebugStrings() const
{
    QStringList qsl;
    qsl << QString("{OR::Item> Rank=%2 Distance=%3 Quality=Q%4 Type=%6 ResultRect=%1 - %5 Included:}")
           .arg(mResult.toDebugString())
           .arg(mRank, 3)
           .arg(mQuality.distance(), -5, 'f', 3)
           .arg(mQuality.quality(), 3, 10, QChar('0'))
           .arg(mIncludedResults.count())
           .arg(mType.name());
    if (mIncludedResults.count() > 1)
    {
        foreach (DetectRect dr, mIncludedResults)
            qsl << dr.toDebugString();
    }
    qsl << "<OR::Item}";
    return qsl;
}

// ------------------------------------- Item non-member  ---------------------------------------

QDataStream &operator >> (QDataStream &ds, ObjectResults::Item &item)
{
    QVariant vari;
    ds >> vari;
    item = ObjectResults::Item::fromVariant(vari);
    return ds;
}

QDebug operator << (QDebug dbg, const ObjectResults::Item item)
{
    foreach (QString s, item.toDebugStrings())
        dbg << s << Qt::endl;
    return dbg;
}

