#pragma once

#include <QtCore/qglobal.h>

#if defined(IFMANAGER_LIBRARY)
#  define IFMANAGER_EXPORT Q_DECL_EXPORT
#else
#  define IFMANAGER_EXPORT Q_DECL_IMPORT
#endif
