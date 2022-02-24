#pragma once

#include <MdiMainWindow>

class MdiGridWidget;

class BossMainWindow : public MdiMainWindow
{
    Q_OBJECT
public:
    BossMainWindow(QApplication *pApp);
    ~BossMainWindow();

private slots:
    void viewEtc();
    void aboutOttoCODE();
    void aboutAppBoss();

private:
    virtual void setupMenus() override;
    virtual void setupConnections() override;

signals:

private:
};
