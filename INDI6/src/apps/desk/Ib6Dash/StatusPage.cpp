#include "StatusPage.h"


#include <QtCore/QFileInfo>
#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtSvg/QSvgRenderer>

#include <eirWgt/BaseStackedLayoutPage.h>
#include <eirWgt/QQGridLayout.h>
#include <eirWgt/QQStackedLayout.h>
#include <eirXfr/Debug.h>

StatusPage::StatusPage(QQStackedLayout * parent)
    : BaseStackedLayoutPage("Splash", parent)
{
    setObjectName("SplashPage");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

void StatusPage::initialize()
{
    TRACEQFI << QOBJNAME(this);
    QFileInfo tSvgFileInfo(":/logos/svg/INDIbase6.svg");
    QSvgRenderer * pSvgRenderer = new QSvgRenderer(tSvgFileInfo.filePath());
    QPainter * pPainter = new QPainter(&mSplashPixmap);
    pSvgRenderer->render(pPainter);
    pPainter->end();
    TRACE << tSvgFileInfo << mSplashPixmap;
}

void StatusPage::setup()
{
    TRACEQFI << QOBJNAME(this);
    QLabel *pLabel = new QLabel(this);
    pLabel->setPixmap(mSplashPixmap);
    layout()->clear();
    layout()->setColumnStretch(0, 1);
    layout()->setColumnMinimumWidth(1, 600);
    layout()->addWidget(pLabel, 1, 0);
    layout()->setColumnStretch(2, 1);
    update();
}

void StatusPage::updateUI()
{
    TRACEQFI << QOBJNAME(this);
    update();
}
