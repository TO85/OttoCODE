#include "SqlManager.h"

#include <QtCore/QCoreApplication>

#include <QtSql/QSqlDatabase>

#include <eirXfr/Debug.h>

SqlManager::SqlManager()
    : QObject(qApp->parent())
{
    setObjectName("SqlManager");
    TRACEQFI << QOBJNAME(parent()) << QOBJNAME(this);
    EMIT(constructed());
}

void SqlManager::initialize()
{
    if (mInitialized.notSet())
    {
        initializeConnectors();
    }
}

void SqlManager::initializeConnectors()
{
    QStringList tDatabaseNames = QSqlDatabase::drivers();

}
