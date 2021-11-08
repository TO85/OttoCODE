#include <QCoreApplication>

#include <cstdio>

#include <QtSql/QSqlDatabase>

int main(int argc, char *argv[])
{
    fprintf(stdout, "Hello from SqlCon");
    QSqlDatabase myDB = QSqlDatabase::addDatabase("QPSQL", "manifest");
    fprintf(stdout, "QPSQL: myDB.isValid()=%i\n", myDB.isValid());
    QCoreApplication a(argc, argv);
    return a.exec();
}
