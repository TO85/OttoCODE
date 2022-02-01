#pragma once

#include <QtCore/qglobal.h>

#if defined(OCIO_LIBRARY)
#  define OCIO_EXPORT Q_DECL_EXPORT
#else
#  define OCIO_EXPORT Q_DECL_IMPORT
#endif
