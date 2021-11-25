#pragma once
#include "eirExe.h"

#include <QtCore/QSettings>

#include "SupporterInterface.h"

class EIREXE_EXPORT AppSettings : public QSettings, public SupporterInterface
{
    Q_OBJECT
public:
    explicit AppSettings();
    QVariantMap configuration(const QString groupKey);

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

#pragma warning ( push )
#pragma warning( disable : 4101 )
Q_GLOBAL_STATIC(AppSettings, STG);
#pragma warning ( pop )
