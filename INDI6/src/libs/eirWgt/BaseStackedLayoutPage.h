#pragma once

#include <QWidget>

#include <eirType/MultiName.h>

class QQGridLayout;
class QQStackedLayout;

class BaseStackedLayoutPage : public QWidget
{
    Q_OBJECT
public:
    explicit BaseStackedLayoutPage(const MultiName &aName, QQStackedLayout *parent);

    MultiName name() const;
    QWidget *widget();
    QQGridLayout *layout();

public slots:
    virtual void initialize() = 0;
    virtual void setup() = 0;
    virtual void updateUI() = 0;

signals:

private:
    BaseStackedLayoutPage *it() { return this; }

private:
    QQStackedLayout *mpStack=nullptr;
    MultiName mName;
    QQGridLayout *mpPageLayout;
};

