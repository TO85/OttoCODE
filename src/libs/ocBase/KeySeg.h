#pragma once
#include "ocBase.h"

#include <QChar>
#include <QList>
#include <QRegularExpression>
#include <QString>

class OCBASE_EXPORT KeySeg
{
public:
    typedef QList<KeySeg> List;

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
    List split(const QString segNames);

private:
    KeySeg it() const { return *this; }
    KeySeg & it() { return *this; }

private:
    QString mString;

private:
    static QRegularExpression smValidCharRx;
    static QString smInvalidReplaceString;
};

extern OCBASE_EXPORT bool operator == (const KeySeg &lhs, const KeySeg &rhs);
extern OCBASE_EXPORT bool operator <  (const KeySeg &lhs, const KeySeg &rhs);

