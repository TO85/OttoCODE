#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRTYPE_LIBRARY)
#  define EIRTYPE_EXPORT Q_DECL_EXPORT
#else
#  define EIRTYPE_EXPORT Q_DECL_IMPORT
#endif
