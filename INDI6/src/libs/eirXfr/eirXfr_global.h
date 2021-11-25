#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRXFR_LIBRARY)
#  define EIRXFR_EXPORT Q_DECL_EXPORT
#else
#  define EIRXFR_EXPORT Q_DECL_IMPORT
#endif
