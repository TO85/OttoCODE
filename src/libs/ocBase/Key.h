#pragma once
#include "ocBase.h"

#include <QList>
#include <QMetaType>
#include <QString>
#include <QStringList>

#include "KeyItem.h"

class TOBASE_EXPORT Key
{
public:
    Key(const KeyItem &ki);
    Key(const QList<KeyItem> &kl);
    Key(const QString &qs);
    Key(const QStringList &qsl);
    Key(const char *pch);
    Key() = default;
    ~Key() = default;
    Key(const Key &other) = default;
    Key &operator = (const Key &other) = default;
    void set(const KeyItem &ki);
    void set(const QString &qs);
    void set(const QStringList &qsl);
    void set(const char *pch);

public:
    int count() const;
    KeyItem first() const;
    Key first(const int k) const;
    KeyItem last() const;
    bool less(const Key &other);
    QString toQString() const;
    operator QString () const { return toQString(); }

public:
    void clear();

protected:
    static QChar separator();
    static void setSeparator(const QChar &c);

private:
    Key it() const { return *this; }
    Key & it() { return *this; }

protected:
    static QChar smSeparator;

private:
    QList<KeyItem> mSegments;
};

Q_DECLARE_METATYPE(Key);

