#pragma once

#include <GridDialog>

#include <QDialog>
#include <QDialogButtonBox>


class ImageFileDialog : public GridDialog
{
    Q_OBJECT
public:
    enum Mode
    {
        $nullMode = 0,
        OpenFile,
        SaveAs,
        $maxMode
    };

public:
    ImageFileDialog(const Mode mode=$nullMode, QWidget * parent=nullptr, Qt::WindowFlags flags=Qt::WindowFlags());
    ImageFileDialog(const Mode mode, QDialogButtonBox::StandardButtons buttons, QWidget * parent=nullptr, Qt::WindowFlags flags=Qt::WindowFlags());

    /* ------- generated -------- */
private:
    Q_PROPERTY(ImageFileDialog::Mode mode READ mode WRITE mode NOTIFY modeChanged);
    Mode mMode;
public:
    Mode mode() const;
public slots:
    void mode(const ImageFileDialog::Mode newMode);
signals:
    void modeChanged(const ImageFileDialog::Mode newMode);
};

