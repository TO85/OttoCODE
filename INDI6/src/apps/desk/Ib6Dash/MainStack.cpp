#include "MainStack.h"

#include <QtCore/QObject>

#include <eirWgt/QQGridLayout.h>

#include "ServerPage.h"
#include "StatusPage.h"

MainStack::MainStack(QWidget *parent)
    : QQStackedLayout(parent)
{
    setObjectName("Ib6Dash:MainStack");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

void MainStack::initialize()
{
    TRACEQFI << QOBJNAME(this);
    mpLayout = new QQGridLayout;
    AEXPECTPTR(mpLayout);
    mpLayout->setObjectName("MainStack:QQGridLayout");
    mpSplashPage = new StatusPage(this);
    AEXPECTPTR(mpSplashPage);
    mpServerPage = new ServerPage(this);
    AEXPECTPTR(mpServerPage);
    addPage(mpSplashPage);
    addPage(mpServerPage);
    mpSplashPage->initialize();
    mpServerPage->initialize();
    TRACE << QOBJNAME(mpLayout) << QOBJNAME(mpSplashPage)  << QOBJNAME(mpServerPage);
}

void MainStack::setup()
{
    mpSplashPage->setup();
    mpServerPage->setup();
}
