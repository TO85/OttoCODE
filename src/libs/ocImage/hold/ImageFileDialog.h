#pragma once
#include "ocImage.h"

#include <QWidget>

#include <QDialog>
#include <QDialogButtonBox>
class QTextEdit;

#include <QQDir>

class OCIMAGE_EXPORT ImageFileDialog : public QWidget
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

private:
    enum GridRows
    {
        $nullRow = 0,
        DirectoryRow,
    };
    enum GridCols
    {
        $nullCol = 0,
        LabelCol,
        DisplayCol,
        Button1Col,
        BrowseCol,
    };

private slots:
    void setup();
    void setupActions();
    void setupConnections();
    void setupDirectory();

    void browseDirectory();

    void doDirectoryChanged(const QQDir &newDirectory);
    void doDefaultDirectoryChanged(const QQDir &newDefaultDirectory);


private:
    QAction* mpBrowseDirectoryAct=nullptr;
    QAction* mpDefaultDirectoryAct=nullptr;
    QTextEdit * mpDirectoryText=nullptr;

    /* ------- generated -------- */
private:
    Q_PROPERTY(ImageFileDialog::Mode mMode READ mode WRITE mode NOTIFY modeChanged);
    Q_PROPERTY(QQDir mDirectory READ directory WRITE directory NOTIFY directoryChanged)
    Q_PROPERTY(QQDir mDefaultDirectory READ defaultDirectory WRITE defaultDirectory NOTIFY defaultDirectoryChanged)
    Mode mMode;
    QQDir mDirectory;
    QQDir mDefaultDirectory;

public:
    Mode mode() const;
    const QQDir &directory() const;
    const QQDir &defaultDirectory() const;

public slots:
    void mode(const ImageFileDialog::Mode newMode);
    void directory(const QQDir &newDirectory);
    void defaultDirectory(const QQDir &newDefaultDirectory);

signals:
    void modeChanged(const ImageFileDialog::Mode newMode);
    void directoryChanged(const QQDir &Directory);
    void defaultDirectoryChanged(const QQDir &DefaultDirectory);
};

