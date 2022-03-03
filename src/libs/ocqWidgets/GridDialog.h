#pragma once

#include <QDialog>

#include <QDialogButtonBox>
class QGridLayout;
class QVBoxLayout;

class GridDialog : public QDialog
{
    Q_OBJECT
public:
    GridDialog(QWidget * parent=nullptr, Qt::WindowFlags flags=Qt::WindowFlags());
    GridDialog(QDialogButtonBox::StandardButtons buttons, QWidget * parent=nullptr, Qt::WindowFlags flags=Qt::WindowFlags());

public:
    QDialogButtonBox *buttonBox();
    QGridLayout *grid();

private:
    void ctor();

private:
    QDialogButtonBox * mpButtonBox=nullptr;
    QVBoxLayout * mpMainVBox=nullptr;
    QWidget * mpGridWidget=nullptr;
    QGridLayout * mpGridLayout=nullptr;
};

