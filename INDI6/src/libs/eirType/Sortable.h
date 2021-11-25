// file: {EIRC Repo}./src/libs/eirType/Sortable
#pragma once
#include "eirType.h"

#include <QString>

class BasicName;
class MultiName;
class QQRect;

class EIRTYPE_EXPORT Sortable : public QString
{
public:
    Sortable();
    Sortable(const QString & qstr);
    Sortable(const BasicName & basic);
    Sortable(const MultiName & multi);
    Sortable(const QQRect & multi);

};

