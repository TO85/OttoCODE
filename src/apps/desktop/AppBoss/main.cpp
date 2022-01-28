#include "BossMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BossMainWindow w(&a);
    w.show();
    return a.exec();
}
