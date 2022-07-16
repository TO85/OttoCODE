#pragma once

#include "BaseTaskMenu.h"

class FileTaskMenu : public BaseTaskMenu
{
    Q_OBJECT
public:
    FileTaskMenu(const QString &title, QWidget *parent = nullptr);


public slots:
    virtual void setup();

private slots:
    void FileNewTask() {;}
    void FileOpenTask() {;}

};

