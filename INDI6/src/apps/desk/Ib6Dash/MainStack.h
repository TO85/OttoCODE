#pragma once

#include <eirWgt/QQStackedLayout.h>

class QQGridLayout;

class ServerPage;
class StatusPage;

class MainStack : public QQStackedLayout
{
    Q_OBJECT
public:
    MainStack(QWidget * parent=nullptr);


public slots:
    void initialize();
    void setup();

private:
    QQGridLayout *mpLayout=nullptr;
    StatusPage *mpSplashPage=nullptr;
    ServerPage *mpServerPage=nullptr;
};

