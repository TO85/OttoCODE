#pragma once

#include <QtCore/qglobal.h>

#if defined(LLCORE_LIBRARY)
#  define LLCORE_EXPORT Q_DECL_EXPORT
#else
#  define LLCORE_EXPORT Q_DECL_IMPORT
#endif
