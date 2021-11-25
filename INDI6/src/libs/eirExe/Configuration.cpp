#include "Configuration.h"

#include <eirXfr/Debug.h>


Configuration Configuration::extract(const Configuration::Key &groupKey, const Configuration &localConfig) const
{
    TRACEQFI << groupKey() << localConfig.map(); WANTDO(it); return Configuration();
}
