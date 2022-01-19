#pragma once

#include <QtCore/qglobal.h>

#if defined(OCQWIDGETS_LIBRARY)
#  define OCQWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define OCQWIDGETS_EXPORT Q_DECL_IMPORT
#endif
