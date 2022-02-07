#include "QQDir.h"


String QQDir::lastPath() const
{
    String tPath = path();
    return tPath.lastSection();
}
