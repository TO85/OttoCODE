#include "ServerPage.h"

#include <QtSql/QSqlDatabase>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

#include <eirWgt/BaseStackedLayoutPage.h>
#include <eirWgt/QQStackedLayout.h>
#include <eirXfr/Debug.h>

ServerPage::ServerPage(QQStackedLayout *parent)
    : BaseStackedLayoutPage("Server", parent)
    , mpDriverLayout(new QQGridLayout)
{
    setObjectName("ServerPage");
    AEXPECTPTR(mpDriverLayout);
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this) << QOBJNAME(mpDriverLayout);
}

void ServerPage::setupDriverNames()
{
    TRACEQFI << QOBJNAME(this);
    QStringList tDriverNames = QSqlDatabase::drivers();
    TRACE << tDriverNames;
    for ( QString tDriverName : tDriverNames )
    {
        QString tDescription;
        if (false) ;
        else if ("QDB2" == tDriverName)         tDescription = "IBM DB2";
        else if ("QIBASE" == tDriverName)       tDescription = "Borland InterBase";
        else if ("QMYSQL" == tDriverName)       tDescription = "MySQL";
        else if ("QMARIADB" == tDriverName)     tDescription = "MariaDB";
        else if ("QOCI" == tDriverName)         tDescription = "Oracle Call Interface";
        else if ("QODBC" == tDriverName)        tDescription = "Microsoft SQL Server and other ODBC";
        else if ("QPSQL" == tDriverName)        tDescription = "PostgreSQL";
        else if ("QSQLITE" == tDriverName)      tDescription = "SQLite version 3";
        else tDescription.clear();
        mDriverNameDescriptionMap.insert(tDriverName, tDescription);
    }
    TRACE << mDriverNameDescriptionMap;
}

void ServerPage::setupDriverLayout()
{
    TRACEQFI << QOBJNAME(this);
    QGroupBox *pDriverGroup = new QGroupBox("Server Classes:", widget());
    QButtonGroup *pButtonGroup = new QButtonGroup(this);
    int row = 0;
    for ( BasicName tName : mDriverNameDescriptionMap )
    {
        QQString tDescription = mDriverNameDescriptionMap.value(tName);
        QRadioButton *pButton = new QRadioButton(tName, widget());
        QLabel *pDescLabel = new QLabel(tDescription, widget());
        mpDriverLayout->addWidget(pButton, row, 0);
        mpDriverLayout->addWidget(pDescLabel, row, 1);
        pButtonGroup->addButton(pButton, row);
        ++row;
    }
    pButtonGroup->setExclusive(true);
    pDriverGroup->setLayout(mpDriverLayout);
    QLabel * pSelectLabel = new QLabel("Select Server Class:");
    layout()->addWidget(pSelectLabel, 0, 0);
    layout()->addWidget(pDriverGroup, 1, 0);
}


void ServerPage::initialize()
{
    TRACEQFI << QOBJNAME(this);
}

void ServerPage::setup()
{
    TRACEQFI << QOBJNAME(this);
    setupDriverNames();
    setupDriverLayout();
}

void ServerPage::updateUI()
{
    TRACEQFI << QOBJNAME(this);
}

