#pragma once

#include <QtCore/QMap>
#include <QtWidgets/QMainWindow>
class QMdiArea;

class BaseMdiWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMdiArea *mdiArea() { return mpMdiArea; }

public:
    void addSubWindow(BaseMdiWindow *pSubWindow);

private:
    QMdiArea *mpMdiArea=nullptr;
    QMap<QString, BaseMdiWindow *> mTitleSubWindowMap;
};
