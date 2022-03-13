#include "HostId.h"

#include <QHostAddress>
#include <QSysInfo>

#include <Millisecond>
#include <Uid>

class HostIdData : public QSharedData
{
public:
    Uid uid;
    Millisecond msec;
    Uid networkUid;
    QHostAddress localHostAddress;
    QString localHostName;
    QString machineHostName;
    QString machineUniqueId;

};

HostId::HostId() : data(new HostIdData)
{

}

HostId::HostId(const HostId &rhs)
    : data{rhs.data}
{

}

HostId &HostId::operator=(const HostId &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

HostId::~HostId()
{

}
