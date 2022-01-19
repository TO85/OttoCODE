#pragma once

#include <QtCore/qglobal.h>

#if defined(OCMATH_LIBRARY)
#  define OCMATH_EXPORT Q_DECL_EXPORT
#else
#  define OCMATH_EXPORT Q_DECL_IMPORT
#endif
