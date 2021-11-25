#pragma once

#include <QWidget>
#include <eirWgt/BaseStackedLayoutPage.h>

#include <QtGui/QPixmap>

class StatusPage : public BaseStackedLayoutPage
{
    Q_OBJECT
public:
    StatusPage(QQStackedLayout * parent);

private:
    QPixmap mSplashPixmap;
    QWidget mSplashWidget;


    // BaseStackedLayoutPage interface
public slots:
    virtual void initialize() override;
    virtual void setup() override;
    virtual void updateUI() override;

};

