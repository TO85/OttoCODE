#pragma once

#include <QWidget>

class QGraphicsView;
class QGraphicsScene;
class QScrollArea;
class QToolBar;

#include <ActionManager>
#include <Rational>

#include "BaseImage.h"

class ImageViewWidget : public QWidget
{
    Q_OBJECT
public:
    enum ToolName
    {
        $null       = 0,
        ZoomIn      = 0x00000001,
        ZoomOut     = 0x00000002,
        ZoomOne     = 0x00000004,
        ZoomFit     = 0x00000008,
        $end        = 0x0000000F
    };
    Q_DECLARE_FLAGS(ToolNames, ToolName);

public:
    explicit ImageViewWidget(QWidget *parent = nullptr);
    ImageViewWidget(const BaseImage image, QWidget *parent = nullptr);
    ActionManager * actions();

public:


public slots:
    void setup();
    void enable(const ToolNames tools, const bool is=true);

signals:

private:
    QGraphicsScene * mpScene;
    QGraphicsView * mpView;
    ActionManager * mpActionManager;
    QToolBar * mpToolBar;
    Rational mZoom;
};

