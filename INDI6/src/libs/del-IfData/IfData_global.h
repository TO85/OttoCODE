#pragma once

#include <QtCore/qglobal.h>

#if defined(IFDATA_LIBRARY)
#  define IFDATA_EXPORT Q_DECL_EXPORT
#else
#  define IFDATA_EXPORT Q_DECL_IMPORT
#endif
