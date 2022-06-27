#pragma once
#include "ocBase.h"

#include <QString>
#include <QMetaType>
#include <QVariant>
class QByteArray;

class QQDir;
class Key;
class KeySeg;
class Uid;

class OCBASE_EXPORT Sortable
{
public:
    Sortable(const QString &string)         { set(string); }
    Sortable(const QVariant &variant)       { set(variant); }
    Sortable(const QByteArray &bytes)       { set(bytes); }
    Sortable(const Uid &uid)                { set(uid); }
    Sortable(const Key &key)                { set(key); }
    Sortable(const KeySeg &seg)             { set(seg); }
    Sortable(const QQDir &dir)              { set(dir); }

public: // access
//    operator QString () const { return mSortableString; }
  //  operator QString () { return mSortableString; }

    bool equal(const Sortable & other) const;
    bool less(const Sortable & other) const;
    bool operator == (const Sortable & other) const;
    bool operator <  (const Sortable & other) const;
    void clear();
    void set(const QString &string);
    void set(const QVariant &variant);
    void set(const QByteArray &bytes);
    void set(const Key &key);
    void set(const KeySeg &seg);
    void set(const QQDir &dir);
    void set(const Uid &uid);

public: // static
    static QByteArray random();

private:
    QString mSortableString=random();

public: // QMetaType
    Sortable() = default;
    ~Sortable() = default;
    Sortable(const Sortable &other) = default;
    Sortable &operator = (const Sortable &other) = default;
};

extern OCBASE_EXPORT bool operator == (const Sortable & lhs, const Sortable & rhs);
extern OCBASE_EXPORT bool operator <  (const Sortable & lhs, const Sortable & rhs);

Q_DECLARE_METATYPE(Sortable);

