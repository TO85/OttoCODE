#pragma once
#include "IfMarker.h"


#include "MarkedImageEntry.h"

class AbstractImageQueue : public QObject
{
public:
    AbstractImageQueue();

public:
    virtual bool enqueue() {MUSTDO(it);MUSTRTN(false);}
    virtual MarkedImageEntry dequeue() {MUSTDO(it);MUSTRTN(MarkedImageEntry());}
    virtual void process() = 0;

protected:
    virtual void pump() {MUSTDO(it);}


private:
    QQueue<MarkedImageEntry> mItemQueue;


};
