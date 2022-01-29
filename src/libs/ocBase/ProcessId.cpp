#include "ProcessId.h"

#include <Millisecond>
#include <Uid>

class ProcessIdData : public QSharedData
{
public:
    Uid uid;
    Millisecond msec;
    Millisecond baseMsec;
    Uid hostUid;
    Uid networkUid;

};

ProcessId::ProcessId() : data(new ProcessIdData)
{

}

ProcessId::ProcessId(const ProcessId &rhs)
    : data{rhs.data}
{

}

ProcessId &ProcessId::operator=(const ProcessId &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ProcessId::~ProcessId()
{

}
