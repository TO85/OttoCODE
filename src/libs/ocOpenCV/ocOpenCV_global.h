#pragma once

#include <QtCore/qglobal.h>

#if defined(OCOPENCV_LIBRARY)
#  define OCOPENCV_EXPORT Q_DECL_EXPORT
#else
#  define OCOPENCV_EXPORT Q_DECL_IMPORT
#endif
