#include "Console.h"

#include <eirXfr/Debug.h>

Console::Console(QCoreApplication *coreApp)
    : AppSupport(coreApp)
{
    setObjectName("Console");
    TRACEQFI << QOBJNAME(coreApp);
    open(StdStreams::All);
}

