#pragma once

#include <QtCore/qglobal.h>

#if defined(EIROPENCV_LIBRARY)
#  define EIROPENCV_EXPORT Q_DECL_EXPORT
#else
#  define EIROPENCV_EXPORT Q_DECL_IMPORT
#endif
