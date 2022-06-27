#pragma once

#include <QQMainWindow>

class QMdiSubWindow;

#include <QQDir>
#include <QQFileInfo>
class ActionManager;
class Key;
class QQMdiArea;

class PixcelsiorImageDocument;

class ExcelsiorMain : public QQMainWindow
{
    Q_OBJECT
public:
    ExcelsiorMain(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

public slots:
    void start();

signals:
    void openFile(const QQFileInfo &fileInfo);
    void documentOpened(const QQFileInfo &fileInfo);

private slots:
    void setupActions();
    void setupConnections();
    void setupMenus();
    void setupUI();

    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupWindowMenu();
    void setupHelpMenu();

    void openFileAction();
    void openDocument(const QQFileInfo &fileInfo);

private:

private:
    QQDir mCurrentImageDir;
    QQDir mDefaultImageDir=QQDir("/data/vdata/INDIface/INDIin");
    QQMdiArea * mpMdiArea=nullptr;
    QMap<QQFileInfo, PixcelsiorImageDocument *> mFileInfoImageDocumentMap;
};

