#include "BaseStackedLayoutPage.h"

#include <eirXfr/Debug.h>

#include "QQGridLayout.h"
#include "QQStackedLayout.h"

BaseStackedLayoutPage::BaseStackedLayoutPage(const MultiName &aName, QQStackedLayout *parent)
    : QWidget(parent->widget())
    , mpStack(parent)
    , mName(aName)\
    , mpPageLayout(new QQGridLayout(this))
{
    setObjectName("StackedLayoutPage:"+mName);
    TRACEQFI << aName() << QOBJNAME(parent) << QOBJNAME(this);
}

MultiName BaseStackedLayoutPage::name() const
{
    return mName;
}

QWidget *BaseStackedLayoutPage::widget()
{
    return (QWidget *)(this);
}

QQGridLayout *BaseStackedLayoutPage::layout()
{
    return mpPageLayout;
}
