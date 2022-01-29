/*! @file DualMap.h Declare DualMap template class
 *  @ingroup ocType
 */
#pragma once

#include <QtCore/QMap>

template <typename TL, typename TR> class DualMap
{
public:
    DualMap() {;}
    bool isEmpty(void) const { return mapTLtoTR.isEmpty() || mapTRtoTL.isEmpty(); }
    bool contains(const TL & tL) const { return mapTLtoTR.contains(tL); }
    bool contains(const TR & tR) const { return mapTRtoTL.contains(tR); }
    int count(void) const { return qMin(mapTLtoTR.count(), mapTRtoTL.count()); }
    int size(void) const { return count(); }
    TR at(const TL & key) const { return contains(key) ? mapTLtoTR.value(key) : TR(); }
    TL at(const TR & key) const { return contains(key) ? mapTRtoTL.value(key) : TL(); }

    void clear(void) { mapTLtoTR.clear(), mapTRtoTL.clear(); }
    bool remove(const TL & tL, const TR & tR)
    {
        bool result = contains(tL) && contains(tR);
        mapTLtoTR.remove(tL), mapTRtoTL.remove(tR);
        return result;
    }
    bool insert(const TL & tL, const TR & tR)
    {
        if (contains(tL) || contains(tR)) return false;
        mapTLtoTR.insert(tL, tR),
        mapTRtoTL.insert(tR, tL);
        return true;
    }
    bool replace(const TL & tL, const TR & tR)
    {
        bool result = remove(tL, tR);
        mapTLtoTR.insert(tL, tR),
        mapTRtoTL.insert(tR, tL);
        return result;
    }

private:
    QMap<TL,TR> mapTLtoTR;
    QMap<TR,TL> mapTRtoTL;
};

#if 0
QList<T1> keys(void) const { return mapT1toT2.keys(); }
QList<T2> values(void) const { return mapT1toT2.values(); }
bool remove(const T1 & key)
{
    if (contains(key))
    {
        T2 value = at(key);
        mapT1toT2.remove(key);
        if (contains(value))
        {
            mapT2toT1.remove(value);
            return true;
        }
    }
    return false;
} // remove(T1)
bool remove(const T2 & key)
{
    if (contains(key))
    {
        T1 value = at(key);
        mapT2toT1.remove(key);
        if (contains(value))
        {
            mapT1toT2.remove(value);
            return true;
        }
    }
    return false;
} // remove(T2)
bool insertUnique(const T1 & t1, const T2 & t2)
{
    if (contains(t1) || contains(t2))
        return false;
    mapT1toT2.insert(t1, t2);
    mapT2toT1.insert(t2, t1);
    return true;
}
#endif
