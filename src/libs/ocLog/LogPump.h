#pragma once
#include "ocLog.h"

#include <QObject>

#include <QQueue>

#include "LogItem.h"
class LogFilter;
class LogFormat;

class OCLOG_EXPORT LogPump : public QObject
{
    Q_OBJECT
public:
    explicit LogPump(QObject *parent = nullptr);
    LogPump(const int initialCapacity, QObject *parent = nullptr);

public:
    LogItem peek() const;
    LogItem::List peek(const int n) const;

public:
    LogItem take();
    LogItem::List take(const int n);

public slots:
    void enqueue(const LogItem item);
    void enqueue(const LogItem::List items);
    void dequeue();
    void dequeue(const int n);
    void setTroll(LogFilter * filter, LogFormat * format);
    void clearTroll();

signals:
    void empty(const bool isEmpty);
    void countUpdated(const int newCount);
    void capacityUpdated(const int newCapacity, const int oldCapacity);
    void enqueued(const LogItem item);
    void dequeued(const LogItem item);

private:
    QQueue<LogItem> mIntakeQueue;
    int mLastCapacity=0;
    LogFilter * mpTrollFilter=nullptr;
};

