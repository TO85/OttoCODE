#pragma once

#include <QtCore/qglobal.h>

#if defined(EIREXE_LIBRARY)
#  define EIREXE_EXPORT Q_DECL_EXPORT
#else
#  define EIREXE_EXPORT Q_DECL_IMPORT
#endif
