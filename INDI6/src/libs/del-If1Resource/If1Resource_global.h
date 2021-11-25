#pragma once

#include <QtCore/qglobal.h>

#if defined(IF1RESOURCE_LIBRARY)
#  define IF1RESOURCE_EXPORT Q_DECL_EXPORT
#else
#  define IF1RESOURCE_EXPORT Q_DECL_IMPORT
#endif
