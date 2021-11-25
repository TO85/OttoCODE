#pragma once

#include <QtCore/qglobal.h>

#if defined(IFMARKER_LIBRARY)
#  define IFMARKER_EXPORT Q_DECL_EXPORT
#else
#  define IFMARKER_EXPORT Q_DECL_IMPORT
#endif
