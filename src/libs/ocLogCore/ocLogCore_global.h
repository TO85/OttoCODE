#pragma once

#include <QtCore/qglobal.h>

#if defined(OCLOGCORE_LIBRARY)
#  define OCLOGCORE_EXPORT Q_DECL_EXPORT
#else
#  define OCLOGCORE_EXPORT Q_DECL_IMPORT
#endif
