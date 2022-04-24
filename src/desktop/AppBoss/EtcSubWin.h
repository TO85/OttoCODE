#pragma once

#include <MdiGridSubWin>

#include <QQDir>

class EtcSubWin : public MdiGridSubWin
{
    Q_OBJECT
public:
    EtcSubWin(QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());

    virtual QString title() const { return "System Etc Directories"; }

public slots:
    virtual void setup();

private:
    QQDir::List mDirList;
};

