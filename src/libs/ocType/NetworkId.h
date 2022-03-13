#pragma once

#include <QSharedDataPointer>

class NetworkIdData;

class NetworkId
{
public:
    NetworkId();
    NetworkId(const NetworkId &);
    NetworkId &operator=(const NetworkId &);
    ~NetworkId();

private:
    QSharedDataPointer<NetworkIdData> data;
};

