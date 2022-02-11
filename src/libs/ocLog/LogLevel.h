#pragma once
#include "ocLog.h"

#include <Key>
#include <KeyMap>

#include "Log.h"

class OCLOG_EXPORT LogLevel
{
public:
    typedef QWORD Value;

public:
    class Set
    {
    public:
        Set();
        bool isNull() const;
        bool contains(const LogLevel level) const;
        bool contains(const Value value) const;
        bool contains(const Key & key) const;
        LogLevel level(const Value value) const;
        LogLevel level(const Key key) const;

    public:
        void initialize();
        void insert(const LogLevel level);

    private:
        void initializeBaseLevels();

    private:
        QMap<Value, LogLevel> mValueMap;
        KeyMap<LogLevel> mKeyMap;
    };

public:
    LogLevel() {;}
    LogLevel(const Value value, const Key & key, const Log::Severity severity);
    static Set & set() { return smSet; }

private:
    Value mValue=0;
    Key mKey;
    Log::Severity mSeverity=Log::$nullSeverity;

public: // static
    static Set smSet;
};

