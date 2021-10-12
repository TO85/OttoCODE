#pragma once

#include <QtCore/qglobal.h>

#if defined(TOCORE_LIBRARY)
#  define TOCORE_EXPORT Q_DECL_EXPORT
#else
#  define TOCORE_EXPORT Q_DECL_IMPORT
#endif
