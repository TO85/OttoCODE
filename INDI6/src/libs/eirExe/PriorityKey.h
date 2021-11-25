#pragma once
#include "eirExe.h"

#include <eirType/Milliseconds.h>

class EIREXE_EXPORT PriorityKey
{
public:
    enum LevelValues
    {
        Highest = 0x7FFF,
        Higher = 0x07FF,
        High = 0x007F,
        Neutral = 0,
        Low = 0xFF80,
        Lower = 0xF800,
        Lowest = 0x8000
    };
    typedef qint16 Level;
    typedef qint64 Key;

public:
    explicit PriorityKey() = default;
    PriorityKey(const Level aLevel);
    PriorityKey(const Level aLevel, const Milliseconds aMsec);
    PriorityKey(const PriorityKey& other) = default;
    ~PriorityKey() = default;
    PriorityKey& operator = (const PriorityKey& other) = default;

    Key toSigned64() const { return mUnion.i64; }
    operator Key () const { return toSigned64(); }

    void set(const Level aLevel, const qint64 aMsec);
    void setValue(const Level aLevel) { mUnion.iValue = - aLevel; }
    void setMsec(const Milliseconds aMsec) { mUnion.iTime = aMsec; }

private:
    union
    {
        qint64 i64;
        qint64 iTime : 48,
            iValue : 16;
    } mUnion;
}; // sub-class Priority

Q_DECLARE_METATYPE(PriorityKey);
