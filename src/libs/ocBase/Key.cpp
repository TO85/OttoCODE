#include "Key.h"


Key::Key(const QString &qs) : mSegments(qs.split(separator())) {;}
Key::Key(const QStringList &qsl) : mSegments(qsl) {;}
Key::Key(const char *pch) : mSegments(QString(pch).split(separator())) {;}

int Key::count() const
{
    return mSegments.count();
}

Key Key::first(const int k) const
{
    if (k > 0 && k < count())
        return mSegments.first(k);
    if (k < 0)
    {
        const int n = count() + k;
        if (n > 0)
            return mSegments.first(n);
    }
    return QString();
}

Key Key::last() const
{
    return mSegments.isEmpty() ? QString() : mSegments.last();
}

QString Key::toString() const
{
    return mSegments.join(separator());
}

/* ----------------------- static --------------------------- */

QChar Key::smSeparator('/');

QChar Key::separator()
{
    return smSeparator;
}

void Key::setSeparator(const QChar &c)
{
    smSeparator = c;
}
