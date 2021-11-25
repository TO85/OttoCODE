#pragma once

#include <QGridLayout>
#include <QWidget>

#include <eirType/QQSize.h>

class QQGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    QQGridLayout(QWidget *parent=nullptr);

    void clear();
    void resize(const QQSize aSize, QWidget * pWidget=nullptr);

};

