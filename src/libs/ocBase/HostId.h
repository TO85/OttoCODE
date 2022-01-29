#pragma once

#include <QSharedDataPointer>

class HostIdData;

class HostId
{
public:
    HostId();
    HostId(const HostId &);
    HostId &operator=(const HostId &);
    ~HostId();

private:
    QSharedDataPointer<HostIdData> data;
};

