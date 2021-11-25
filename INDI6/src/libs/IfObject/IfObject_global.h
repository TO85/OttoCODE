#pragma once

#include <QtCore/qglobal.h>

#if defined(IFOBJECT_LIBRARY)
#  define IFOBJECT_EXPORT Q_DECL_EXPORT
#else
#  define IFOBJECT_EXPORT Q_DECL_IMPORT
#endif
