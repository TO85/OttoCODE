#include "NetworkId.h"

#include <QHostAddress>

#include <Millisecond>
#include <Uid>

class NetworkIdData : public QSharedData
{
public:
    Uid uid;
    Millisecond msec;
    QHostAddress publicHostAddress;
    QString publicDomainName;
    QString localDomainName;

};

NetworkId::NetworkId() : data(new NetworkIdData)
{

}

NetworkId::NetworkId(const NetworkId &rhs)
    : data{rhs.data}
{

}

NetworkId &NetworkId::operator=(const NetworkId &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

NetworkId::~NetworkId()
{

}
