#include "ExcelsiorMain.h"

#include <QApplication>
#include <QFileInfo>
#include <QTimer>

#include <../../../common/version.h>
#include "version.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("Excelsior Video Manageer");
    a.setApplicationName(OC_VER_APPNAME);
    a.setApplicationVersion(OC_VER_APPVER);
    ExcelsiorMain w;
    QTimer::singleShot(500, &w, &ExcelsiorMain::start);
    return a.exec();
}
