/* @file: MetaTypeShell.h */
#include "eirType.h"

#include "Boolean.h"

#include <QtCore/QMetaType>


class EIRTYPE_EXPORT Null
{
public:
    Null() = default;
    Null(const bool is) { mBoolean.set(is); }
    Null(const Null &other) = default;
    ~Null() = default;
    Null &operator = (const Null &other) = default;

    bool is() const { return mBoolean.is(); }
    bool notIs() const { return mBoolean.notIs(); }

    bool set(const bool b=true) { return mBoolean.set(b); }
    bool unset(const bool b=true) { return mBoolean.unset(b); }

    QString toString() const { return mBoolean.toString(); }

private:
    Boolean mBoolean=Boolean(true);
};

Q_DECLARE_METATYPE(Null);

extern EIRTYPE_EXPORT QDebug operator<<(QDebug dbg, const Null &n);

