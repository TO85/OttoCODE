#pragma once
#include "ocqWidgets.h"

#include <QMainWindow>

class QApplication;
class QCoreApplication;
class QMenu;

#include <KeyMap>
#include <QQString>
class Key;

class OCQWIDGETS_EXPORT QQMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QQMainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    const QApplication *gui() const;
    const QCoreApplication *core() const;
    const QObject *object();
    QMenu * menu(const Key key);

public:
    QMenu * addMenu(const Key key, const QQString &text=QQString());

public slots:
    virtual void setup();
    void exit();

signals:
    void setupComplete();

protected:

private:
    KeyMap<QMenu *> mKeyMenuMap;
};

