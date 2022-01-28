#include "MainWindow.h"

#include <QApplication>

#include <../../../common/version.h>
#include "version.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("Excelsior Video Manageer");
    a.setApplicationName(OC_VER_APPNAME);
    a.setApplicationVersion(OC_VER_APPVER);
    MainWindow w(&a);
    w.show();
    return a.exec();
}
