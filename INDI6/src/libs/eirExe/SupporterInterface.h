#pragma once
#include "eirExe.h"

#include "AppSupport.h"
#include "StatusMessage.h"

class EIREXE_EXPORT SupporterInterface
{
public:
    SupporterInterface() {;}
    SupporterInterface(AppSupport *pSupport) : mpSupport(pSupport) {;}
    ~SupporterInterface() {;}

protected:
    virtual StatusMessage doInitialize() = 0;
    virtual StatusMessage doPrepare() = 0;
    virtual StatusMessage doOptions() = 0;
    virtual StatusMessage doSettings() = 0;
    virtual StatusMessage doFinalize() = 0;
    virtual StatusMessage doStart() = 0;
    virtual StatusMessage doShutdown() = 0;

public:
    StatusMessage status() const { return mStatus; }

private:
    AppSupport *support() { return mpSupport; }

private:
    AppSupport *mpSupport=nullptr;
    StatusMessage mStatus;
};

