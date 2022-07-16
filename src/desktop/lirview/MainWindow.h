#pragma once

#include <QMainWindow>

class FileTaskMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setup();

private:
    FileTaskMenu * mpFileMenu;
};
