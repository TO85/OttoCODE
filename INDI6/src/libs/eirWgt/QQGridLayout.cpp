#include "QQGridLayout.h"

#include <eirXfr/Debug.h>


QQGridLayout::QQGridLayout(QWidget *parent)
    : QGridLayout(parent)
{
    setObjectName("QQGridLayout");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

void QQGridLayout::clear()
{
    TRACEQFI << QOBJNAME(this) << rowCount() << columnCount();
    const int nRows = rowCount();
    const int nCols = columnCount();
    for (int row = 0; row < nRows; ++row)
    {
        for (int col = 0; col < nCols; ++col)
        {
            QLayoutItem *pItem = itemAtPosition(row, col);
            if (pItem)
                removeItem(pItem);
        }
    }
}

void QQGridLayout::resize(const QQSize aSize, QWidget * pWidget)
{
    TRACEQFI << QOBJNAME(this) << aSize << QOBJNAME(pWidget) << rowCount() << columnCount();
    const int nRows = rowCount();
    const int nCols = columnCount();
    for (int row = 0; row < nRows; ++row)
    {
        if (nCols < aSize.width())
        {
            for(int col = nCols; col < aSize.width(); ++col)
                addWidget(pWidget, row, col);
        }
        else if (nCols > aSize.width())
            for(int col = aSize.width(); col < nCols; ++col)
            {
                QLayoutItem *pItem = itemAtPosition(row, col);
                if (pItem)
                    removeItem(pItem);
            }
        // else nCols == aSize.width(), do nothing
    }

}
