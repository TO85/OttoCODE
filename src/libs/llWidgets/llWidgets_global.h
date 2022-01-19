#pragma once

#include <QtCore/qglobal.h>

#if defined(LLWIDGETS_LIBRARY)
#  define LLWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define LLWIDGETS_EXPORT Q_DECL_IMPORT
#endif
