#pragma once

#include <QtCore/qglobal.h>

#if defined(TOEXE_LIBRARY)
#  define TOEXE_EXPORT Q_DECL_EXPORT
#else
#  define TOEXE_EXPORT Q_DECL_IMPORT
#endif
