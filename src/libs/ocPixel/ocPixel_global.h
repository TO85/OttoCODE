#pragma once

#include <QtCore/qglobal.h>

#if defined(OCPIXEL_LIBRARY)
#  define OCPIXEL_EXPORT Q_DECL_EXPORT
#else
#  define OCPIXEL_EXPORT Q_DECL_IMPORT
#endif
