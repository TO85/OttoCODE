#pragma once

#include <QtCore/qglobal.h>

#if defined(OCTYPE_LIBRARY)
#  define OCTYPE_EXPORT Q_DECL_EXPORT
#else
#  define OCTYPE_EXPORT Q_DECL_IMPORT
#endif
