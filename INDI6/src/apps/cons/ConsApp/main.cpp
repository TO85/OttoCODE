#include <QCoreApplication>

#include <QProcess>

#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("Hello\n");

    QStringList tEnvVars = QProcess::systemEnvironment();
    while ( ! tEnvVars.isEmpty())
        printf("%s\n", tEnvVars.takeFirst().toLocal8Bit().data());

    return a.exec();
}
