#pragma once
#include "ocBase.h"

#include <QMetaType>
#include <QString>
#include <QStringList>

#include "KeySeg.h"

class OCBASE_EXPORT Key
{
public:
    Key(const KeySeg &seg);
    Key(const QList<KeySeg> &segs);
    Key(const QString &qs);
    Key(const QStringList &qsl);
    Key(const char *pch);

public: // const
    int count() const;
    bool isEmpty() const;
    bool notEmpty() const { return ! isEmpty(); }
    KeySeg first() const;
    Key first(const int k) const;
    KeySeg last() const;
    QList<KeySeg> list() const;
    Key appended(const KeySeg &seg) const;
    Key appended(const Key &key) const;
    bool equal(const Key &other) const;
    bool less(const Key &other) const;
    QString toQString() const;
    bool operator == (const Key &other) const { return equal(other); }
    bool operator < (const Key &other) const { return less(other); }
    operator QString () const { return toQString(); }

public: // non-const
    void clear();
    void set(const KeySeg &seg);
    void set(const QString &qs);
    void set(const QStringList &qsl);
    void set(const char *pch);
    Key append(const KeySeg &seg);
    Key append(const Key &key);

protected:
    static QChar separator();
    static void setSeparator(const QChar &c);

private:
    Key it() const { return *this; }
    Key & it() { return *this; }

protected:
    static QChar smSeparator;

private:
    QList<KeySeg> mSegments;

public:
    Key() = default;
    ~Key() = default;
    Key(const Key &other) = default;
    Key &operator = (const Key &other) = default;

};

Q_DECLARE_METATYPE(Key);

