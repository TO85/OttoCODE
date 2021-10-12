#pragma once

#include <QtCore/qglobal.h>

#if defined(TOGUI_LIBRARY)
#  define TOGUI_EXPORT Q_DECL_EXPORT
#else
#  define TOGUI_EXPORT Q_DECL_IMPORT
#endif
