#include "DirectoryTreeWidget.h"

#include <QGuiApplication>
#include <QStringList>

#include <CommaString>


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
    const QStringList tColumnList = tColumns.split();
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
    Q_UNUSED(tree); // NEEDDO use tree

}

DirectoryTreeWidget::Item::Item(const QQDir &dir)
    : mDir(dir)
{
    setText(0, dir.lastPath());
}
