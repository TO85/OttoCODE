#pragma once

#include <QtCore/qglobal.h>

#if defined(LLEXE_LIBRARY)
#  define OCEXE_EXPORT Q_DECL_EXPORT
#else
#  define OCEXE_EXPORT Q_DECL_IMPORT
#endif
