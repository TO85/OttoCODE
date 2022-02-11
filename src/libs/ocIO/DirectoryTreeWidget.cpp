#include "DirectoryTreeWidget.h"

#include <QGuiApplication>

#include <CommaString>
#include <String>
#include <StringList>


DirectoryTreeWidget::DirectoryTreeWidget(QWidget *parent)
    : QTreeWidget(parent)
{
    setObjectName("DirectoryTreeWidget");
}

void DirectoryTreeWidget::configure(const VariableMap &config)
{
    QFont tFont = QGuiApplication::font();
    CommaString tColumns("LastPath");

    clear();
    Q_UNUSED(config); // NEEDDO use config
    mColumnCharacterWidthMap.insert($nullColumn, 60);

    mFont = tFont;
    const StringList tColumnList = tColumns.split();
    for (auto columnName : tColumnList)
    {
        const Column tColumn = columnValue(columnName);
        mColumns |= tColumn;
        mColumnPositionList << tColumn;
        mColumnNamePositionList << columnName;
    }
}

void DirectoryTreeWidget::set(const FileSystemTree &tree)
{

}

DirectoryTreeWidget::Item::Item(const QQDir &dir)
    : mDir(dir)
{
    setText(0, dir.lastPath());
}
