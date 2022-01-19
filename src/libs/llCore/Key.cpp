#include "Key.h"


Key::Key(const char *pch) : mSegments(QString(pch).split(separator())) {;}

QString Key::last() const
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
