#pragma once

#include <QMdiSubWindow>

#include <QGridLayout>
#include <QList>
#include <QPoint>
#include <QSize>
#include <QWidget>

#include <Image>
#include <ImagePak>
#include <Key>

class ExcelsiorFrameGridMdiSub : public QMdiSubWindow
{
    Q_OBJECT
public:
    struct GridLocation
    {
        QPoint Offset;
        QSize Size;
        Qt::Alignment Alignment;
        Image::Type ImageType;
        Key ImageKey;
    };
    typedef QList<GridLocation> GridLocList;

public:
    ExcelsiorFrameGridMdiSub(QWidget * parentWidget);

public:
    void setBaseQImage(const QImage &qi);
    void clearGridLocList();
    bool isGridLocAvailable(const GridLocation & gll) const;
    GridLocation availableGridLoc(const GridLocation & gll, const int hint) const;
    GridLocation find(const GridLocation &gloc) const;
    GridLocation find(const int ix) const;
    GridLocation find(const Key key) const;
    GridLocList gridLocList() const;

public:
    void append(const QPoint pt, const QSize sz=QSize(),
                           const Qt::Alignment align=Qt::AlignCenter);
    void append(const GridLocation &gloc);
    bool useGridLoc(const GridLocation &gloc);
    bool releaseGridLoc(const GridLocation &gloc);

public:

private slots:
    void growGridRows(const int rowCount=-1);
    void growGridCols(const int colCount=-1);


private:
    QWidget * mpMdiSubWidget=nullptr;
    ImagePak mImagePak;
    GridLocList mGridLocList;
};

