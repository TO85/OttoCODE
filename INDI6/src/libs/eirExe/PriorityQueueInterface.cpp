#include "PriorityQueueInterface.h"


PriorityQueueInterface::PriorityQueueInterface(const MultiName &aName, const QObject *parent)
{
    setObjectName("PriorityQueueInterface" + (aName.isEmpty() ? "" : (":" + mName())));
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
    EMIT(constructed());
}
