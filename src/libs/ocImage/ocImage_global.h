#pragma once

#include <QtCore/qglobal.h>

#if defined(OCIMAGE_LIBRARY)
#  define OCIMAGE_EXPORT Q_DECL_EXPORT
#else
#  define OCIMAGE_EXPORT Q_DECL_IMPORT
#endif
