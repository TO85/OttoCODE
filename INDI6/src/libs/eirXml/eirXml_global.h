#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRXML_LIBRARY)
#  define EIRXML_EXPORT Q_DECL_EXPORT
#else
#  define EIRXML_EXPORT Q_DECL_IMPORT
#endif
