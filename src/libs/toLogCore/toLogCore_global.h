#pragma once

#include <QtCore/qglobal.h>

#if defined(TOLOGCORE_LIBRARY)
#  define TOLOGCORE_EXPORT Q_DECL_EXPORT
#else
#  define TOLOGCORE_EXPORT Q_DECL_IMPORT
#endif
