#pragma once
#include "ocBase.h"

#include <QString>
#include <QStringList>

#include "KeySeg.h"
#include "KeySegList.h"

class OCBASE_EXPORT Key
{
public:
    explicit Key() {;}
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
    KeySeg::List list() const;
    Key appended(const KeySeg &seg) const;
    Key appended(const Key &key) const;
    QString toQString(const QChar &sep=QChar()) const;
    bool equal(const Key &other) const;
    bool less(const Key &other) const;
    QString operator ()() const { return toQString(); }
    bool operator == (const Key &other) const { return equal(other); }
    bool operator < (const Key &other) const { return less(other); }

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

#ifdef QT_DEBUG
private:
    QString mdString;
#endif
protected:
    static QChar smSeparator;

private:
    KeySegList mSegments;
};


