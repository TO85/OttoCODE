#pragma once

#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMdiSubWindow>

class BaseMdiWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    QString title() const { return mTitle; }

protected:
    BaseMdiWindow(const QString &title, QMdiArea *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    QMdiArea *mdiArea() { return mpMdiArea; }

private:
    QMdiArea *mpMdiArea=nullptr;
    QString mTitle;
};

