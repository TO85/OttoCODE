#pragma once

#include <QSharedDataPointer>

class ProcessIdData;

class ProcessId
{
public:
    ProcessId();
    ProcessId(const ProcessId &);
    ProcessId &operator=(const ProcessId &);
    ~ProcessId();

private:
    QSharedDataPointer<ProcessIdData> data;
};

