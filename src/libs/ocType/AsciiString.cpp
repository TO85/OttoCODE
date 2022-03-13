#include "AsciiString.h"


QByteArray AsciiString::toQByteArray() const
{
    return QByteArray(it());
}
