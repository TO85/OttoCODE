#pragma once

#include <MdiGridWidget>

#include <QtCore/QDir>
class QLabel;

class EtcSubWinWidget : public MdiGridWidget
{
    Q_OBJECT
public:
    EtcSubWinWidget(const QDir &dir, QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());
    const QDir dir();

public slots:
    virtual void setup() override;

private:
    QDir mDir;
    QLabel *mpFileNameTitleLabel=nullptr;
};

