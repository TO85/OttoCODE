#include "LogChannel.h"

LogChannel::LogChannel(const Key key)
    : cmKey(key)
    , cmUid(smUidDMap.insert(key))
{
    ++mSequence;
}

LogChannel LogChannel::null()
{
    return smNullChannel;
}
