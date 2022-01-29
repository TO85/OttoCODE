#pragma once

#include <MdiGridWindow>

#include <QtCore/QDir>
class QLabel;

class EtcSubWindow : public MdiGridWindow
{
    Q_OBJECT
public:
    EtcSubWindow(const QDir &dir, QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());
    const QDir dir();

public slots:
    virtual void setup() override;

private:
    QDir mDir;
    QLabel *mpFileNameTitleLabel=nullptr;
};

