#pragma once

#include <QtCore/qglobal.h>

#if defined(LLGUI_LIBRARY)
#  define LLGUI_EXPORT Q_DECL_EXPORT
#else
#  define LLGUI_EXPORT Q_DECL_IMPORT
#endif
