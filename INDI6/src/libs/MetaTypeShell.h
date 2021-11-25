/* @file: MetaTypeShell.h */
#include "eirType.h"

#include <QtCore/QMetaType>

class Sand;

class EIRTYPE_EXPORT MetaTypeShell
{
    explicit MetaTypeShell() = default;
    MetaTypeShell(const Sand aSand);
    MetaTypeShell(const MetaTypeShell &other) = default;
    ~MetaTypeShell() = default;
    MetaTypeShell &operator = (const MetaTypeShell &other) = default;

};

Q_DECLARE_METATYPE(MetaTypeShell);
