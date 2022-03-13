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
    QVariant dmData;
};

Ident::Ident() : data(new IdentData)
{

}

Ident::Ident(const Ident &rhs)
    : data{rhs.data}
{

}

Ident &Ident::operator=(const Ident &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Ident::~Ident()
{

}

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
