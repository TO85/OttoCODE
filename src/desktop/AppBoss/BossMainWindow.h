#pragma once

#include <MdiMainWindow>

class MdiGridWidget;

class BossMainWindow : public MdiMainWindow
{
    Q_OBJECT
public:
    BossMainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~BossMainWindow();

private slots:
    void viewEnv();
    void viewEtc();
    void aboutOttoCODE();
    void aboutAppBoss();

private:
    virtual void setupActions() override;
    virtual void setupMenus() override;
    virtual void setupConnections() override;

private:
};
