#include "IconGrid.h"

#include <eirXfr/Debug.h>

IconGrid::IconGrid(QWidget *parent)
    : QWidget(parent)
{
    ctor();
}

IconGrid::IconGrid(const QQSize aGridSize, const QQSize aIconSize, QWidget *parent)
    : QWidget(parent)
    , mGridSize(aGridSize)
    , mIconSize(aIconSize)
{
    ctor();
    CONNECT(this, &IconGrid::GridSizeChanged, this, &IconGrid::updateGridSize);
}

void IconGrid::updateGridSize()
{
    TRACEQFI << getGridSize();
    mGridLayout.resize(getGridSize());
    mIconMatrix.resize(getGridSize());
}

void IconGrid::updateIconSize()
{
    TRACEQFI << getIconSize();
//    for (QQIcon &tIcon : mIconMatrix.vector()) tIcon.setPreferedSize(getIconSize());
}
