#pragma once
#include "ocBase.h"

#include <QString>
#include <QMetaType>
#include <QVariant>
class QByteArray;

class Key;
class KeySeg;

class OCBASE_EXPORT Sortable : public QString
{
public:
    Sortable(const QString &string) { set(string); }
    Sortable(const QVariant &variant) { set(variant); }
    Sortable(const QByteArray &bytes) { set(bytes); }
    Sortable(const Key &key) { set(key); }
    Sortable(const KeySeg &item) { set(item); }
    Sortable() = default;
    ~Sortable() = default;
    Sortable(const Sortable &other) = default;
    Sortable &operator = (const Sortable &other) = default;

public: // access
    QString source();
    QVariant variant();

public:
    void clear();
    void set(const QString &string);
    void set(const QVariant &variant);
    void set(const QByteArray &bytes);
    void set(const Key &key);
    void set(const KeySeg &seg);

public: // static
    static QByteArray random();

private:
    QString mSource;
    QVariant mVariant;
};

Q_DECLARE_METATYPE(Sortable);

