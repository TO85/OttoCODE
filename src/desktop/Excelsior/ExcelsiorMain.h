#pragma once

#include <MdiMainWindow>

class ImageWindowWidget;
class ColorComponentWindowWidget;

class ExcelsiorMain : public MdiMainWindow
{
    Q_OBJECT
public:
    ExcelsiorMain(QApplication *pApp);

public slots:

private slots:
    virtual void setupActions() override;
    virtual void setupConnections() override;
    virtual void setupMenus() override;

    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupWindowMenu();
    void setupHelpMenu();

private:

};

