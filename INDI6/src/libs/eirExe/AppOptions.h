#pragma once
#include "eirExe.h"

#include <QObject>

#include "SupporterInterface.h"

class EIREXE_EXPORT AppOptions : public QObject, public SupporterInterface
{
    Q_OBJECT
public:
    explicit AppOptions(QObject *parent = nullptr);

protected:
    virtual StatusMessage doInitialize()    { return StatusMessage(); }
    virtual StatusMessage doPrepare()       { return StatusMessage(); }
    virtual StatusMessage doOptions()       { return StatusMessage(); }
    virtual StatusMessage doSettings()      { return StatusMessage(); }
    virtual StatusMessage doFinalize()      { return StatusMessage(); }
    virtual StatusMessage doStart()         { return StatusMessage(); }
    virtual StatusMessage doShutdown()      { return StatusMessage(); }


signals:

private:

};

