#pragma once

#include <QtCore/qglobal.h>

#if defined(TOWIDGETS_LIBRARY)
#  define TOWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define TOWIDGETS_EXPORT Q_DECL_IMPORT
#endif
