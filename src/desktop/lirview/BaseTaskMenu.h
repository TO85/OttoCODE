#pragma once

#include <QMenu>

#include <QIcon>

class QAction;

class BaseTaskMenu : public QMenu
{
    Q_OBJECT
public:
    BaseTaskMenu(QWidget *parent = nullptr);
    BaseTaskMenu(const QString &title, QWidget *parent = nullptr);
    BaseTaskMenu(const QString &title, const QIcon &ico, QWidget *parent = nullptr);

protected slots:
    virtual void setup() {;}

protected:
    void icon(const QIcon &i);
    QAction * addItem(const QString &title, const QIcon &icon=QIcon());


};

