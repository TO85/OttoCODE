#pragma once

#include <QtCore/qglobal.h>

#if defined(TOMATH_LIBRARY)
#  define TOMATH_EXPORT Q_DECL_EXPORT
#else
#  define TOMATH_EXPORT Q_DECL_IMPORT
#endif
