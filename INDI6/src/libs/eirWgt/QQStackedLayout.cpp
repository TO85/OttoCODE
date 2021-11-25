#include "QQStackedLayout.h"

#include <eirXfr/Debug.h>

#include "BaseStackedLayoutPage.h"

QQStackedLayout::QQStackedLayout(QWidget *parent)
    : QStackedLayout(parent)
{
    setObjectName("QQStackedLayout");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

QWidget *QQStackedLayout::at(const int aPosition)
{
    return QStackedLayout::widget(aPosition);
}

QWidget *QQStackedLayout::at(const MultiName &aKey)
{
    return at(position(aKey));
}

int QQStackedLayout::position(const MultiName &aKey) const
{
    return mKeyList.indexOf(aKey);
}

int QQStackedLayout::position(const QWidget *wgt) const
{
    const int nPosition = count();
    for (int kPosition = 0; kPosition < nPosition; ++kPosition)
        if (widget(kPosition) == wgt)
            return kPosition;
    return -1;
}

MultiName QQStackedLayout::name(const int aPosition) const
{
    return isValidPosition(aPosition) ? mKeyList.value(aPosition) : MultiName();
}

MultiName QQStackedLayout::name(const QWidget *wgt) const
{
    return name(position(wgt));
}

MultiNameList QQStackedLayout::keys() const
{
    MultiNameList result;
    foreach (MultiName key, mKeyList) result << key;
    return result;
}

void QQStackedLayout::clear()
{
    const int nPosition = count();
    for (int kPosition = 0; kPosition < nPosition; ++kPosition)
        remove(widget(kPosition));
    mKeyList.clear();
}

int QQStackedLayout::addPage(BaseStackedLayoutPage *pPage)
{
    TRACEQFI << &pPage << mKeyList.count();
    // If the QStackedLayout is empty before this function is called, the given widget becomes the current widget.
    const bool tFirst = mKeyList.isEmpty();
    const int result = addWidget(pPage);
    addWidget(pPage);
    mKeyList.append(pPage->name());
    if (tFirst) setCurrentIndex(result);
    EMIT(widgetAdded(pPage->name(), result));
    EMIT(selected(pPage->name(), result));
    TRACE << result << mKeyList();
    return result;
}

int QQStackedLayout::insert(const int aPosition, BaseStackedLayoutPage *pPage)
{
    TRACEQFI << aPosition << &pPage << mKeyList.count();
    if (notValidPosition(aPosition)) return addPage(pPage);            /* /====\ */
    const int result = insertWidget(aPosition, pPage);
    mKeyList.insert(result, pPage->name());
    EMIT(widgetAdded(pPage->name(), result));
    return result;
}

void QQStackedLayout::remove(const int aPosition)
{
    TRACEQFI << aPosition << mKeyList.count();
    if (notValidPosition(aPosition)) return;                            /* /====\ */
    const MultiName removedKey = name(aPosition);
    removeWidget(widget(aPosition));
    mKeyList.removeAt(aPosition);
    EMIT(widgetRemoved(removedKey, aPosition));
}

void QQStackedLayout::remove(const MultiName &aKey)
{
    remove(position(aKey));
}

void QQStackedLayout::remove(QWidget *pWgt)
{
    remove(position(pWgt));
}

QWidget *QQStackedLayout::selectedWidget() const
{
    return QStackedLayout::currentWidget();
}

int QQStackedLayout::selectedPosition() const
{
    return QStackedLayout::currentIndex();
}

MultiName QQStackedLayout::selectedKey() const
{
    return name(selectedPosition());
}

void QQStackedLayout::select(const int aPos)
{
    TRACEQFI << aPos << name(aPos)();
    if (notValidPosition(aPos)) return;                                  /* /====\ */
    if (isValidPosition(selectedPosition()))
        EMIT(unselected(name(selectedPosition()), selectedPosition()));
    QStackedLayout::setCurrentIndex(aPos);
    EMIT(selected(name(aPos), aPos));
}

void QQStackedLayout::select(const MultiName &aKey)
{
    select(position(aKey));
}

void QQStackedLayout::select(QWidget *pWgt)
{
    select(position(pWgt));
}

bool QQStackedLayout::isValidPosition(const int aPosition) const
{
    return aPosition >= 0 && aPosition < mKeyList.count();
}
