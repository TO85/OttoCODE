#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRWGT_LIBRARY)
#  define EIRWGT_EXPORT Q_DECL_EXPORT
#else
#  define EIRWGT_EXPORT Q_DECL_IMPORT
#endif
