#pragma once
#include "eirXfr.h"
//! file {EIRC2 repo}./src/libs/eirXfr/StartupDebug.h

#include <QtGlobal>
#include <QtDebug>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

/*!
   \brief The StartupDebug class is used to capture QtDebug messages prior to starting XFR itself.

   Usage:
   \code
#include <eirXfr/StartupDebug.h>
Q_GLOBAL_STATIC(StartupDebug, sdo)

#include"FubarConsole.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    sdo->start(argv[0], "./log");
    // from here on, all QtDebug messages are sent to start log file
    // until sdo->finish() is called, typically in XFR::start().

    a.setApplicationName("FubarConsole");
    a.setApplicationVersion(EIRC2_VER_STRING " " EIRC2_VER_TRUNKNAME);
    a.setOrganizationName(EIRC2_VER_ORGNAME);

    FubarConsole c(a.parent());
    Q_UNUSED(c);

    return a.exec();
}
    \endcode
 */
class EIRXFR_EXPORT StartupDebug
{
public:
    StartupDebug();
    bool start(const QString &exeArg0,
               const QString &logDirName);
    void finish();

protected:

private:
    QFile * mpStartupFile;
    const QtMessageHandler cmMyHandler=&myStartupMessageHandler;

protected: // static
    static void myStartupMessageHandler(QtMsgType type,
             const QMessageLogContext &context,
             const QString &msg);

private: // static
    static QTextStream * smpTextStream;
    static QTextStream * smpStderrStream;
};



