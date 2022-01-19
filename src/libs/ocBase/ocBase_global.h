#pragma once

#include <QtCore/qglobal.h>

#if defined(TOBASE_LIBRARY)
#  define TOBASE_EXPORT Q_DECL_EXPORT
#else
#  define TOBASE_EXPORT Q_DECL_IMPORT
#endif
