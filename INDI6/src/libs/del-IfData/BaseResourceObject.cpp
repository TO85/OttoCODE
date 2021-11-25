#include "BaseResourceObject.h"

BaseResourceObject::BaseResourceObject(QObject *parent)
    : QObject(parent)
{
    setObjectName("BaseResourceObject");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);

}
