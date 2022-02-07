#pragma once
#include "ocIO.h"

#include <QTableWidget>

#include <QFont>
#include <QList>
#include <QMap>

#include <KeySeg>
#include <String>

#include "../ocqCore/ObjectHelper.h"

class OCIO_EXPORT FileInfoTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    enum Column
    {
        $nullColumn         = 0,
        FileName            = 0x00000001,
        BaseName            = 0x00000002,
        CompleteBaseName    = 0x00000004,
        Suffix              = 0x00000010,
        CompleteSuffix      = 0x00000020,
        Owner               = 0x00000100,
        Group               = 0x00000200,
        PermissionOwner     = 0x00001000,
        PermissionGroup     = 0x00002000,
        PermissionOther     = 0x00004000,
        Permissions         = PermissionOwner | PermissionGroup | PermissionOther,
        Flags               = 0x00010000,
        SizeBytes           = 0x00100000,
        SizeUnits           = 0x00200000,
        TimeBorn            = 0x01000000,
        TimeRead            = 0x02000000,
        TimeModified        = 0x04000000,
    };
    Q_DECLARE_FLAGS(Columns, Column);
    Q_ENUM(Column);
    KeySeg columnKey(const Column value) const
    {
        return enumName(value);
    }
    int columnValue(const KeySeg & key) const
    {
        return enumValue<Column>(key.toQString().toLocal8Bit().data());
    }


public:
    FileInfoTableWidget(QWidget * parent=nullptr);

private:
    QFont mFont;
    Columns mColumns;
    QList<Columns> mColumnPositionList;
    QMap<Column, String> mColumnStringMap;
    QMap<Column, int> mColumnCharacterWidthMap;
};

//template<class FileInfoTableWidget, "Column"> KeySeg enumKey(const int value);
