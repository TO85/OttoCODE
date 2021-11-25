#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRGUI_LIBRARY)
#  define EIRGUI_EXPORT Q_DECL_EXPORT
#else
#  define EIRGUI_EXPORT Q_DECL_IMPORT
#endif
