#include "BaseColorTable.h"

BaseColorTable::BaseColorTable() {;}
BaseColorTable::BaseColorTable(const RgbList other)
    : QList<QRgb>(other.first(qMin(256, other.count()))) {;}

// --------------------- static ----------------------

BaseColorTable BaseColorTable::grey()
{
    static BaseColorTable result;
    if (result.isEmpty())
    {
        quint8 index = 0;
        while (result.count() < 256)
        {
            result.append(qRgb(index, index, index));
            index++;
        }
    }
    return result;
}
