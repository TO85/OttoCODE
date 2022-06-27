#pragma once

#include <QtCore/qglobal.h>

#if defined(OCBASE_LIBRARY)
#  define OCBASE_EXPORT Q_DECL_EXPORT
#else
#  define OCBASE_EXPORT Q_DECL_IMPORT
#endif
