#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRSQL_LIBRARY)
#  define EIRSQL_EXPORT Q_DECL_EXPORT
#else
#  define EIRSQL_EXPORT Q_DECL_IMPORT
#endif
