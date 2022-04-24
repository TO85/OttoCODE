#include "ExcelsiorFrameGridMdiSub.h"

#include <QMdiArea>
#include <QMdiSubWindow>

ExcelsiorFrameGridMdiSub::ExcelsiorFrameGridMdiSub(QWidget *parentWidget)
    : QMdiSubWindow(parentWidget)
{
    setObjectName("ExcelsiorFrameGridMdiSub");
}

/* ---------------------- private slots -------------------- */

void ExcelsiorFrameGridMdiSub::growGridRows(const int rowCount)
{

}

void ExcelsiorFrameGridMdiSub::growGridCols(const int colCount)
{

}
