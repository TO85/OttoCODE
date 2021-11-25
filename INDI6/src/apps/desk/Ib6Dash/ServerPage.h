#pragma once

#include <eirWgt/QQGridLayout.h>
#include <QWidget>

#include <QtCore/QMap>

#include <eirType/BasicName.h>
#include <eirType/QQString.h>
#include <eirWgt/BaseStackedLayoutPage.h>


class ServerPage : public BaseStackedLayoutPage
{
    Q_OBJECT
public:
    ServerPage(QQStackedLayout * parent);

private:
    void setupDriverNames();
    void setupDriverLayout();

private:
    QMap<BasicName, QQString> mDriverNameDescriptionMap;
    QQGridLayout *mpDriverLayout=nullptr;

    // BaseStackedLayoutPage interface
public slots:
    virtual void initialize() override;
    virtual void setup() override;
    virtual void updateUI() override;
};

