#pragma once

#include <QtCore/qglobal.h>

#if defined(INDIFACE_LIBRARY)
#  define INDIFACE_EXPORT Q_DECL_EXPORT
#else
#  define INDIFACE_EXPORT Q_DECL_IMPORT
#endif
