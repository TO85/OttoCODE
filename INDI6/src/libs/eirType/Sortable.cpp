#include "Sortable.h"

#include <eirType/BasicName.h>
#include <eirType/MultiName.h>
#include "QQRect.h"

Sortable::Sortable() {;}

Sortable::Sortable(const QString &qstr)
    : QString(qstr.toLower()) {;}

Sortable::Sortable(const BasicName & basic)
    : QString(basic().toLower()) {;}

Sortable::Sortable(const MultiName & multi)
    : QString(multi().toLower()) {;}

Sortable::Sortable(const QQRect & qqrc)
{
    clear();
    QString sortable = QString("@Area %1 @Size %2,%3 @Center %4,%5")
               .arg(qqrc.area(), 4, QChar('0'))
               .arg(qqrc.width(), 4, QChar('0'))
               .arg(qqrc.height(), 4, QChar('0'))
               .arg(qqrc.center().x(), 4, QChar('0'))
               .arg(qqrc.center().y(), 4, QChar('0'));
    append(sortable);
}


