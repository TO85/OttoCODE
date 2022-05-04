#pragma once

#include <MdiMainWindow>

class QMdiSubWindow;

#include <QQDir>
#include <QQFileInfo>
class ActionManager;
class Key;

class ExcelsiorFrameGridMdiSub;

class ExcelsiorMain : public hold-MdiMainWindow
{
    Q_OBJECT
public:
    ExcelsiorMain(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

public slots:
    void start();

private slots:
    void setupActions();
    void setupConnections();
    void setupMenus();

    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupWindowMenu();
    void setupHelpMenu();

    void openFileAction();

private:
    ExcelsiorFrameGridMdiSub * addSubWindow(const QQFileInfo & fi);

private:
    QQDir mCurrentImageDir;
    QQDir mDefaultImageDir = QQDir("/data/vdata/INDIface/INDIin");
    QMap<QQFileInfo, ExcelsiorFrameGridMdiSub *> mFileInfoSubWinMap;
};

