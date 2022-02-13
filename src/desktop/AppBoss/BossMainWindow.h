#pragma once

#include <MdiMainWindow>


class MdiGridWindow;

class BossMainWindow : public MdiMainWindow
{
    Q_OBJECT
public:
    BossMainWindow(QApplication *pApp);
    ~BossMainWindow();

public slots:
    void viewEtc();

private:
    virtual void setupMenus() override;
    virtual void setupConnections() override;

signals:

private:
};
