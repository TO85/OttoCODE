#include "AppSupport.h"

#include <eirXfr/Debug.h>

#include "AppOptions.h"
#include "AppSettings.h"

AppSupport::AppSupport(QCoreApplication *coreApp)
    : QObject(coreApp->parent())
    , mpCoreApp(coreApp)
    , mpOptions(nullptr)  // ctor in initOptions()
    , mpSettings(nullptr) // ctor in initSettings()
{
    setObjectName("AppSupport");
    TRACEQFI << QOBJNAME(this);
    EMIT(constructed());
}

void AppSupport::initialize()
{
    TRACEQFI << QOBJNAME(this); MUSTDO(it);
    CONNECT(this, &AppSupport::initializeCalled,
            this, &AppSupport::initStart);
    CONNECT(this, &AppSupport::initializeStarting,
            this, &AppSupport::initOptions);
    CONNECT(this, &AppSupport::optionsInitd,
            this, &AppSupport::initSettings);
    CONNECT(this, &AppSupport::settingsInitd,
            this, &AppSupport::initFinish);
//  CONNECT(this, &AppSupport::initializeFinished,
  //        this, &AppSupport::...???...);
    EMIT(initializeCalled());
}
