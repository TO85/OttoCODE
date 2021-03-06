#pragma once
#include "ocIO.h"

#include <QTreeWidget>
#include <QWidget>
class QFont;

#include <QQDir>
#include <QQString>
#include <VariableMap>
class FileSystemTree;

class OCIO_EXPORT DirectoryTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    enum Column
    {
        $nullColumn         = 0,
        AbsolutePath        = 0x00000001,
        Path                = 0x00000002,
        LastPath            = 0x00000004,
        Owner               = 0x00000100,
        Group               = 0x00000200,
        PermissionOwner     = 0x00001000,
        PermissionGroup     = 0x00002000,
        PermissionOther     = 0x00004000,
        Permissions         = PermissionOwner | PermissionGroup | PermissionOther,
        Flags               = 0x00010000,
        TimeBorn            = 0x01000000,
        TimeRead            = 0x02000000,
        TimeModified        = 0x04000000,
    };
    Q_DECLARE_FLAGS(Columns, Column);
    Q_ENUM(Column);
    KeySeg columnKey(const Column value) const;
    Column columnValue(const KeySeg & key) const;

public:
    class Item : public QTreeWidgetItem
    {
        Item(const QQDir & dir);

    private:
        QQDir mDir;
    };

public:
    DirectoryTreeWidget(QWidget * parent=nullptr);

public slots:
    void clear() {Q_ASSERT(!"TODO");}
    void configure(const VariableMap & config);
    void setup() {Q_ASSERT(!"TODO");}
    void add(const DirectoryTreeWidget::Item & item) {Q_ASSERT(!"TODO");}
    void set(const QList<KeySeg> & columnNames) {Q_ASSERT(!"TODO");}
    void set(const FileSystemTree & tree);

private:
    QFont mFont;
    Columns mColumns;
    QList<Columns> mColumnPositionList;
    QList<QQString> mColumnNamePositionList;
    QMap<Column, QQString> mColumnStringMap;
    QMap<Column, int> mColumnCharacterWidthMap;
};

