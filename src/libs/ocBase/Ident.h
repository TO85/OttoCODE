#pragma once
#include "ocBase.h"

#include <QSharedDataPointer>
class IdentData;

#include <QMap>
class QString;
class QVariant;

#include "Uid.h"
#include "Key.h"

class OCBASE_EXPORT Ident
{
public:
    Ident();
    Ident(const Key &key, const Uid &uid=Uid());
    Ident(const Ident &);
    Ident &operator=(const Ident &);
    ~Ident();

public:
    Uid uid() const;
    Uid uid(const Uid uid);
    Key key() const;
    Key key(const Key key);
    QString name() const;
    QString name(const QString name) ;
    QStringList description() const;
    QStringList description(const QStringList description);
    QVariant info() const;
    QVariant info(const QVariant data);

public:
    void set(const Uid uid);

public: // static
    static Ident ident(const Uid uid);
    static Ident ident(const Key & key);
    static Ident ident(const QString & name);
    static void insert(const Ident ident);
    static void remove(const Ident ident);

private:
    QSharedDataPointer<IdentData> data;
    static QMap<Uid, Ident> smUidIdentMap;
    static QMap<Key, Ident> smKeyIdentMap;
    static QMap<QString, Ident> smNameIdentMap;
};

