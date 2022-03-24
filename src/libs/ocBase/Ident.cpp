#include "Ident.h"

#include <QString>
#include <QStringList>
#include <QVariant>

#include "Key.h"
#include "Uid.h"

class IdentData : public QSharedData
{
public:
    IdentData() : dmUid(true) {;}

private:
    friend class Ident;
    Uid dmUid;
    Key dmKey;
    QString dmName;
    QStringList dmDesc;
    QVariant dmInfo;
};

Ident::Ident() : data(new IdentData) { insert(*this); }
Ident::Ident(const Key &akey, const Uid &uid) : data(new IdentData) { key(akey), set(uid); insert(*this); ; }
Ident::Ident(const Ident &rhs) : data{rhs.data} {;}
Ident &Ident::operator=(const Ident &rhs) { if (this != &rhs) data.operator=(rhs.data); return *this; }
Ident::~Ident() { remove(*this); }

Uid Ident::uid() const
{
    Q_ASSERT(data);
    return data->dmUid;
}

Uid Ident::uid(const Uid uid)
{
    Q_ASSERT(data);
    return data->dmUid = uid;
}

Key Ident::key() const
{
    Q_ASSERT(data);
    return data->dmKey;
}

Key Ident::key(const Key key)
{
    Q_ASSERT(data);
    return data->dmKey = key;
}

QString Ident::name() const
{
    Q_ASSERT(data);
    return data->dmName;
}

void Ident::set(const Uid uid)
{
    Q_ASSERT(data);
    if (uid.isNull())
        data->dmUid = Uid::createVersion4();
    else
        data->dmUid = uid;
}

/* ------------------------- static --------------------------- */

QMap<Uid, Ident> Ident::smUidIdentMap;
QMap<Key, Ident> Ident::smKeyIdentMap;
QMap<QString, Ident> Ident::smNameIdentMap;

Ident Ident::ident(const Uid uid)
{
    return smUidIdentMap.value(uid);
}

Ident Ident::ident(const Key &key)
{
    return smKeyIdentMap.value(key);
}

Ident Ident::ident(const QString &name)
{
    return smNameIdentMap.value(name);
}

void Ident::insert(const Ident ident)
{
    smUidIdentMap.insert(ident.uid(), ident);
    smKeyIdentMap.insert(ident.key(), ident);
    smNameIdentMap.insert(ident.name(), ident);
}

void Ident::remove(const Ident ident)
{
    smUidIdentMap.remove(ident.uid());
    smKeyIdentMap.remove(ident.key());
    smNameIdentMap.remove(ident.name());
}
