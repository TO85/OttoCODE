#pragma once

#include <QtCore/qglobal.h>

#if defined(OCLOG_LIBRARY)
#  define OCLOG_EXPORT Q_DECL_EXPORT
#else
#  define OCLOG_EXPORT Q_DECL_IMPORT
#endif
