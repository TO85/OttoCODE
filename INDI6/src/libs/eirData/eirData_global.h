#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRDATA_LIBRARY)
#  define EIRDATA_EXPORT Q_DECL_EXPORT
#else
#  define EIRDATA_EXPORT Q_DECL_IMPORT
#endif
