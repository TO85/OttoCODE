/*! @file Named.h Declarations for Named Type template
  *
  */
#pragma once

#include <QMap>

/*! @class  Named
  * @brief  Specializes DualMap for case insensitive strings
  */
template <class T> class Named
{
public:
    Named(void) {}
    T invalid(void) const
    { return T(); }
    void clear(void)
    { T_name_map.clear(), name_T_map.clear(); }
    bool isEmpty(void) const
    { return T_name_map.isEmpty() || name_T_map.isEmpty(); }
    int size(void) const
    { return qMin(T_name_map.size(), name_T_map.size()); }
    bool contains(const T & key) const
    { return T_name_map.contains(key); }
    bool contains(const QString & key) const
    { return name_T_map.contains(key.toLower()); }
    QString value(const T & key) const
    { return contains(key) ? T_name_map.value(key) : QString(); }
    QString name(const T & key) const
    { return contains(key) ? T_name_map.value(key) : QString(); }
    T value(const QString & key) const
    { return contains(key.toLower()) ? name_T_map.value(key.toLower()) : T(); }
    void insert(const T & t1, const QString & t2)
    { T_name_map.insert(t1, t2), name_T_map.insert(t2.toLower(), t1); }
    T first(const T & t1) const
    { (void)t1; return isEmpty() ? T() : T_name_map.constBegin().key(); }
    QList<T> keys(void) const
    { return T_name_map.keys(); }
    T last(const T & t1) const
    {
        T result(invalid());
        (void)t1;
        if ( ! T_name_map.isEmpty())
        {
            typename QMap<T,QString>::const_iterator it = T_name_map.constEnd();
            --it;
            result = it.key();
        }
        return result;
    }
    T next(const T & key) const
    {
        T result(invalid());
        typename QMap<T,QString>::const_iterator it = T_name_map.find(key);
        if (T_name_map.end() != it)
            ++it;
        if (T_name_map.end() != it)
            result = it.key();
        return result;
    }
    T previous(const T & key) const
    {
        T result(invalid());
        typename QMap<T,QString>::const_iterator it = T_name_map.find(key);
        if (T_name_map.begin() != it)
            --it;
        if (T_name_map.begin() != it)
            result = it.key();
        return result;
    }
    bool remove(const T & key)
    {
        if (contains(key))
        {
            QString value = value(key);
            T_name_map.remove(key);
            if (contains(value))
            {
                name_T_map.remove(value);
                return true;
            }
            else
                return false;
        }
        else
            return false;
    } // remove(T)

    bool remove(const QString & key)
    {
        if (contains(key.toLower()))
        {
            T value = value(key.toLower());
            name_T_map.remove(key.toLower());
            if (contains(value))
            {
                T_name_map.remove(value);
                return true;
            }
            else
                return false;
        }
        else
            return false;
    } // remove(T)

private:
    QMap<T,QString> T_name_map;
    QMap<QString,T> name_T_map;
}; // template Named

