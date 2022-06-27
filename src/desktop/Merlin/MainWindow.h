#pragma once

#include <QMainWindow>

class BaseActions;

class QMdiArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {;}
    QMdiArea * mdi();
    BaseActions * actions();

private slots:
    void setup();
        void setupMenuBar();
        void setupConnections();

private:
    QMdiArea * mpMdiArea;
    BaseActions * mpActions;
};
