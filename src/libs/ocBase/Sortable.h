#pragma once
#include "ocBase.h"

#include <QString>
#include <QVariant>
class QByteArray;

class Key;

class TOBASE_EXPORT Sortable : public QString
{
public:
    Sortable() { set(); }
    Sortable(const QString &string) { set(string); }
    Sortable(const QVariant &variant) { set(variant); }
    Sortable(const QByteArray &bytes) { set(bytes); }
    Sortable(const Key &key) { set(key); }

public: // access
    QString source();
    QVariant variant();

public:
    void set();
    void set(const QString &string);
    void set(const QVariant &variant);
    void set(const QByteArray &bytes);
    void set(const Key &key);

private:
    QString mSource;
    QVariant mVariant;
};

