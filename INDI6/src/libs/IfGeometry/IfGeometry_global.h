#pragma once

#include <QtCore/qglobal.h>

#if defined(IFGEOMETRY_LIBRARY)
#  define IFGEOMETRY_EXPORT Q_DECL_EXPORT
#else
#  define IFGEOMETRY_EXPORT Q_DECL_IMPORT
#endif
