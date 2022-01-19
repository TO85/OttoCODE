#pragma once

#include <QtCore/qglobal.h>

#if defined(OCQCORE_LIBRARY)
#  define OCQCORE_EXPORT Q_DECL_EXPORT
#else
#  define OCQCORE_EXPORT Q_DECL_IMPORT
#endif
