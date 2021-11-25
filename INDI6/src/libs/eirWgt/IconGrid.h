#pragma once
#include <eirWgt.h>

#include <QWidget>

#include <eirType/MatrixT.h>
#include <eirType/QQSize.h>
#include <eirGui/QQIcon.h>

#include "QQGridLayout.h"

class EIRWGT_EXPORT IconGrid : public QWidget
{
    Q_OBJECT
public:
    explicit IconGrid(QWidget *parent = nullptr);
    IconGrid(const QQSize aGridSize, const QQSize aIconSize, QWidget *parent = nullptr);


    const QQSize &getGridSize() const;
    const QQSize &getIconSize() const;

public slots:
    void setGridSize(const QQSize &newGridSize);
    void resetGridSize();
    void setIconSize(const QQSize &newIconSize);
    void resetIconSize();

signals:
    void GridSizeChanged(const QQSize &);
    void IconSizeChanged(const QQSize &);

private:
    void ctor();

private slots:
    void updateGridSize();
    void updateIconSize();

private:
    QQSize mGridSize;
    QQSize mIconSize;
    QQGridLayout mGridLayout;
    Matrix<QQIcon> mIconMatrix;
};

inline const QQSize &IconGrid::getGridSize() const
{
    return mGridSize;
}

inline void IconGrid::setGridSize(const QQSize &newGridSize)
{
    if (mGridSize == newGridSize)
        return;
    mGridSize = newGridSize;
    emit GridSizeChanged(mGridSize);
}

inline void IconGrid::resetGridSize()
{
    setGridSize(QQSize());
    emit GridSizeChanged(mGridSize);
}

inline const QQSize &IconGrid::getIconSize() const
{
    return mIconSize;
}

inline void IconGrid::setIconSize(const QQSize &newIconSize)
{
    if (mIconSize == newIconSize)
        return;
    mIconSize = newIconSize;
    emit IconSizeChanged(mIconSize);
}

inline void IconGrid::resetIconSize()
{
    setIconSize(QQSize());
    emit IconSizeChanged(mIconSize);
}

inline void IconGrid::ctor()
{
    setObjectName("IconGrid");
    TRACEQFI << QOBJNAME(parent()) << QOBJNAME(this);
}

