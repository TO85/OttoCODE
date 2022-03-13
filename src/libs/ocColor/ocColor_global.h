#pragma once

#include <QtCore/qglobal.h>

#if defined(OCCOLOR_LIBRARY)
#  define OCCOLOR_EXPORT Q_DECL_EXPORT
#else
#  define OCCOLOR_EXPORT Q_DECL_IMPORT
#endif
