#pragma once
#include "eirWgt.h"

#include <QtWidgets/QStackedLayout>

#include <QtCore/QPair>
#include <QtWidgets/QWidget>

#include <eirType/MultiName.h>
#include <eirType/MultiNameList.h>
#include <eirType/QQList.h>

class BaseStackedLayoutPage;

class QQStackedLayout : public QStackedLayout
{
    Q_OBJECT
public:
    QQStackedLayout(QWidget * parent=nullptr);

public:
    QWidget * at(const int aPosition);
    QWidget * at(const MultiName &aKey);
    int position(const MultiName &aKey) const;
    int position(const QWidget *wgt) const;
    MultiName name(const int aPosition) const;
    MultiName name(const QWidget *wgt) const;
    MultiNameList keys() const;

public:
    void clear();
    int addPage(BaseStackedLayoutPage *pPage);

    int insert(const int aPosition, BaseStackedLayoutPage *pPage);
    void remove(const int aPosition);
    void remove(const MultiName &aKey);
    void remove(QWidget *pWgt);
    QWidget * selectedWidget() const;
    int selectedPosition() const;
    MultiName selectedKey() const;

public slots:
    void select(const int aPos);
    void select(const MultiName &aKey);
    void select(QWidget *pWgt);

signals:
    void empty();
    void widgetAdded(const MultiName &aKey, const int aPosition);
    void widgetRemoved(const MultiName &aKey, const int aPosition);
    void selected(const MultiName &aKey, const int aPosition);
    void unselected(const MultiName &aKey, const int aPosition);

private:
    QQStackedLayout *it() { return this; }

private:
    bool isValidPosition(const int aPosition) const;
    bool notValidPosition(const int aPosition) const { return ! isValidPosition(aPosition); }

private:
    MultiNameList mKeyList;
};
