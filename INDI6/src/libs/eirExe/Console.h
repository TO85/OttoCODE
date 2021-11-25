#pragma once
#include "eirExe.h"

#include <QObject>
#include "AppSupport.h"
#include <eirType/StdStreams.h>

#include <QPointer>

class QCoreApplication;

class EIREXE_EXPORT Console : public AppSupport, public StdStreams
{
    Q_OBJECT
public:
    explicit Console(QCoreApplication *coreApp);

signals:

private:
};

