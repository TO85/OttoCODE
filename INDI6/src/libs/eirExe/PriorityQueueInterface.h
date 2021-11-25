#pragma once
#include "eirExe.h"

#include <QtCore/QObject>

#include <eirType/Milliseconds.h>
#include <eirType/MultiName.h>

#include "PriorityKey.h"

class EIREXE_EXPORT PriorityQueueInterface : public QObject
{
	Q_OBJECT
/* ------------------------- properties ------------------------- */
    Q_PROPERTY(bool autoRemove READ isAutoRemove WRITE setAutoRemove NOTIFY autoRemoveChanged);
    Q_PROPERTY(Milliseconds mLongTimerMsec READ longTimerMsec WRITE setLongTimerMsec NOTIFY longTimerChanged);
    Q_PROPERTY(Milliseconds mShortTimerMsec READ shortTimerMsec WRITE setShortTimerMsec NOTIFY shortTimerChanged);
public:
    bool isAutoRemove() const { return mAutoRemove; }
    void setAutoRemove(const bool aAutoRemove) { mAutoRemove = aAutoRemove; }
    Milliseconds longTimerMsec() const { return mLongTimerMsec; }
    void setLongTimerMsec(const Milliseconds aMsec) { mLongTimerMsec = aMsec; }
    Milliseconds shortTimerMsec() const { return mLongTimerMsec; }
    void setShortTimerMsec(const Milliseconds aMsec) { mLongTimerMsec = aMsec; }
signals:
    void autoRemoveChanged(const bool aAuto);
    void longTimerChanged(const Milliseconds aMsec);
    void shortTimerChanged(const Milliseconds aMsec);
private:
    MultiName mName;
    bool mAutoRemove = false;
    Milliseconds mLongTimerMsec = 500;
    Milliseconds mShortTimerMsec = 50;


/* ------------------------- QObject PriorityQueueInterface ------------------------- */
protected:
    PriorityQueueInterface(const MultiName &aName, const QObject* parent);

public slots:
    void start() {MUSTDO(it);}
    void pause() {MUSTDO(it);}
    void resume() {MUSTDO(it);}
    void flushNext(const int max) {MUSTUSE(max);MUSTDO(it);}
    void flushAll() {MUSTDO(it);}
    void stop() {MUSTDO(it);}
    void terminate() {MUSTDO(it);}


signals:
    void constructed();
    void startChanged();
    void pauseChanged();
    void flushing(const int count);
    void terminating();
    void cleared();
    void empty();
    void countChanged(const int aCount);
    void dequeReady(const PriorityKey aPriority);
    void enqueued(const PriorityKey aKey);
    void dequeued(const PriorityKey aKey);
    void removed(const PriorityKey aKey);

private slots:
    void pump() {MUSTDO(it);}
    void shootShort() {MUSTDO(it);}
    void shootLong() {MUSTDO(it);}
    void signalCleared() {MUSTDO(it);}
    void signalEmpty() {MUSTDO(it);}
    void signalCountChanged(const int aCount) {MUSTUSE(aCount);MUSTDO(it);}
    void signalDequeReady(const PriorityKey aKey) {MUSTUSE(aKey);MUSTDO(it);}
    void signalEnqueued(const PriorityKey aKey) {MUSTUSE(aKey);MUSTDO(it);}
    void signalDequeued(const PriorityKey aKey) {MUSTUSE(aKey);MUSTDO(it);}
    void signalRemoved(const PriorityKey aKey) {MUSTUSE(aKey);MUSTDO(it);}

private:

};


