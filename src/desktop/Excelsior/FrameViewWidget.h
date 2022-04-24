#pragma once

#include <MdiGridWidget>


class FrameViewWidget : public MdiGridWidget
{
public:
    FrameViewWidget(const Key &key, QQMdiArea *parent, Qt::WindowFlags flags = Qt::WindowFlags());
};

