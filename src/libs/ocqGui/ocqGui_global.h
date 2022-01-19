#pragma once

#include <QtCore/qglobal.h>

#if defined(OCQGUI_LIBRARY)
#  define OCQGUI_EXPORT Q_DECL_EXPORT
#else
#  define OCQGUI_EXPORT Q_DECL_IMPORT
#endif
