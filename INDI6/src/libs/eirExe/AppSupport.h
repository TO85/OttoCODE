#pragma once
#include "eirExe.h"

#include <QObject>

#include <QCoreApplication>
#include <QSettings>

#include <eirXfr/Debug.h>

#include "StatusMessage.h"
class AppOptions;
class AppSettings;

class EIREXE_EXPORT AppSupport : public QObject
{
    Q_OBJECT
public:
    explicit AppSupport(QCoreApplication *coreApp);
    AppOptions *options() const { return mpOptions; }
    AppSettings *settings() const { return mpSettings; }

public slots:
    void initialize();

private slots:
    void initStart() { MUSTDO(it); MUSTEMIT(false); }
    void initPrepare() { MUSTDO(it); MUSTEMIT(false); }
    void initOptions() { MUSTDO(it); MUSTEMIT(false); }
    void initSettings(const QSettings::SettingsMap &cmdlineSettings)
    { MUSTDO(it); MUSTUSE(cmdlineSettings); MUSTEMIT(false); }
    // more...
    void initFinish() { MUSTDO(it); MUSTEMIT(false); }

signals:
    void constructed();
    void initializeCalled();
    void initializePrepared();
    void initializeStarting();
    void optionsInitd(const QSettings::SettingsMap &cmdlineSettings);
    void settingsInitd();
    // more...
    void initializeFinished();


private:
    QCoreApplication *mpCoreApp=nullptr;
    AppOptions * mpOptions=nullptr;
    AppSettings * mpSettings=nullptr;
    StatusMessage mStatus;

};

