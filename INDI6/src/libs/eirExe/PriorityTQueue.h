#pragma once
#include "eirExe.h"

#include <eirType/MultiName.h>

#include "PriorityQueueInterface.h"
#include "PriorityKey.h"

template <typename T> class EIREXE_EXPORT PriorityTQueue : public PriorityQueueInterface
{
public:
    explicit PriorityTQueue(const MultiName &aName=MultiName(), const QObject* parent = nullptr)
        : PriorityQueueInterface(aName, parent) {;}

public:
    bool contains(const PriorityKey aKey) const;
    T at(const PriorityKey aKey) const;
    int count() const;
    bool isEmpty() const;
    bool notEmpty() const;
    PriorityKey firstKey() const;
    T first() const;

public:
    void clear();
    T &at(const PriorityKey aKey);
    T &takeAt(const PriorityKey aKey);
    PriorityKey enqueue(const T& t);
    PriorityKey enqueue(const PriorityKey::Level aLevel, const T& t);
    PriorityKey enqueue(const PriorityKey aKey, const T& t);
    T dequeue(); // AKA takeFirst()
    T dequeue(const PriorityKey aKey);
    int remove(const PriorityKey aKey);

protected:
    QMap<PriorityKey, T> mKeyTMap;
};
