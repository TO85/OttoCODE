#pragma once
#include "ocBase.h"

#include <QList>
#include <QString>

#include "String.h"

class OCBASE_EXPORT KeySeg
{
public:
    KeySeg();
    KeySeg(const QString & qs);

public:
    bool startsWith(const KeySeg & stub) const;
    QString toQString() const;
    operator QString () const { return toQString(); }

public:
    void clear();
    void set(const QString & string);

public: // static
    QList<KeySeg> split(const String segNames);

private:
    KeySeg it() const { return *this; }
    KeySeg & it() { return *this; }

private:
    QString mString;
};


