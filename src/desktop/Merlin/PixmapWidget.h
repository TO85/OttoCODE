#pragma once

#include <QWidget>

#include <QPixmap>
class QLabel;

class PixmapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PixmapWidget(QWidget *parent = nullptr);
    explicit PixmapWidget(const QPixmap & pxm, QWidget *parent = nullptr);

public:

public:
    void set(const QPixmap & pxm);
    void set();

signals:

private:

private:
    QPixmap mPixmap;
    QLabel * mpPixmapLabel;
};

