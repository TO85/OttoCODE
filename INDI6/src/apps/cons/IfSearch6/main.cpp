#include <QCoreApplication>

#include <QTimer>

#include <cstdio>

#include "IfS6Console.h"

#include <../version.h>
#include "version.h"

#include <eirBase/VersionInfo.h>
#include <eirXfr/StartupDebug.h>
Q_GLOBAL_STATIC(StartupDebug, sdo)

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    VersionInfo vi(VER_STRING, VER_MAJOR, VER_MINOR, VER_MICRO, VER_MINI);
    printf("Hello from main %s!\n", qPrintable(vi.toString()));
    a.setApplicationName(VER_APPNAME);
    a.setApplicationVersion(VER_STRING " " VER_TRUNKNAME);
    a.setOrganizationName(VER_ORGNAME);

    sdo->start(argv[0], "./log");

    IfS6Console c(&a);
    return a.exec();
}

/* Rolling in OpenCV Steps
 *
 * 1. @210211 - Enable #include files
 * ---OK
 *
 * 2. @210211 -
    LIBS *= -LD:\lang\OpenCV4\opencv\build\x64\vc15\lib
    LIBS *= -lopencv_world450d
    void IfS6Console::hello()
    writeLine(QString("---OpenCV version %1").arg(QString::fromStdString(cv::getVersionString())));
    writeLines(cvStringList(cv::getBuildInformation()), "  >");
 * ---OK
 *
 * 3. @210212 - Load cvCascade for face and eye
    QDir mBaseCascadeDir;
    QString mFaceCascadeFilename;
    QString mEyeCascadeFilename;
    cvCascade mFaceCascade;
    cvCascade mEyeCascade;
    mBaseCascadeDir = QDir("../detectors");
    mFaceCascadeFilename = "v4/haarcascade_frontalface_alt.Xml";
    QFileInfo faceQFI(mBaseCascadeDir, mFaceCascadeFilename);
    mFaceCascade.load(faceQFI);
 * ---OK
 *
 * !BREAKS!    LIBS *= -leirVar6
 * Forget eirVar for now.
 *
 */
