#pragma once

#include <QMdiSubWindow>
#include <QWidget>

#include <KeySeg>

class QQMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    QQMdiSubWindow(const KeySeg & key, QWidget *parent = nullptr,
                   Qt::WindowFlags flags = Qt::WindowFlags());
};

