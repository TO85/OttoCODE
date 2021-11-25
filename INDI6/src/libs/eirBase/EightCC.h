#ifndef EIGHTCC_H
#define EIGHTCC_H
#include "eirType.h"

#include <QtCore/QByteArray>


class EIRTYPESHARED_EXPORT EightCC
{
public:
    EightCC(const quint64 u64=0);
    EightCC(const char * pc);

    bool isNull(void) const { return !u; }
    bool isPrintable(void) const;
    QByteArray toByteArray(void) const;
    QString toString(void) const;
    const char * operator () (void) const
    { return toByteArray().constData(); }
    operator quint64 (void) const { return u; }

public:
    union
    {
        char    c[8];
        quint64 u;
    };
};

#endif // EIGHTCC_H
