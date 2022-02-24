#pragma once
#include "ocLog.h"

#include <Key>
#include <KeyUidDMap>
#include <Uid>

class OCLOG_EXPORT LogChannel
{
public:
    LogChannel(const Key key);

public: // static
    static LogChannel null();
    static bool contains(const Uid uid);
    static bool contains(const Key key);
    static LogChannel channel(const Uid uid);
    static LogChannel channel(const Key key);

private:
    const Key cmKey;
    const Uid cmUid;
    int mSequence=0;
    static LogChannel smNullChannel;
    static KeyUidDMap smUidDMap;
};

