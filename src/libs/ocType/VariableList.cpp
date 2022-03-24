#include "VariableList.h"


bool VariableList::isValidIndex(const int index) const
{
    return index >= 0 && index < count();
}

const Variable VariableList::at(const int index) const
{
    return isValidIndex(index) ? QList<Variable>::at(index) : Variable();
}
