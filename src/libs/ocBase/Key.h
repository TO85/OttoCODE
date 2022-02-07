#pragma once
#include "ocBase.h"

#include <QList>
#include <QMetaType>
#include <QString>
#include <QStringList>

#include "KeySeg.h"

class OCBASE_EXPORT Key
{
public:
    Key(const KeySeg &ki);
    Key(const QList<KeySeg> &kl);
    Key(const QString &qs);
    Key(const QStringList &qsl);
    Key(const char *pch);
    Key() = default;
    ~Key() = default;
    Key(const Key &other) = default;
    Key &operator = (const Key &other) = default;

public:

public:
    int count() const;
    KeySeg first() const;
    Key first(const int k) const;
    KeySeg last() const;
    bool less(const Key &other);
    QString toQString() const;
    operator QString () const { return toQString(); }

public:
    void clear();
    void set(const KeySeg &ki);
    void set(const QString &qs);
    void set(const QStringList &qsl);
    void set(const char *pch);

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
};

Q_DECLARE_METATYPE(Key);

