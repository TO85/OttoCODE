#include "QQIcon.h"

#include <eirXfr/Debug.h>

MultiName QQIcon::iconName() const
{
    TODO(Try FileInfo also)
    if (false)
        ;
    else if (mIconName.notEmpty())
        return mIconName;
    else
        return MultiName(cacheKey());
}

MultiName QQIcon::getIconName() const
{
    return mIconName;
}

void QQIcon::setIconName(const MultiName &newIconName)
{
    mIconName = newIconName;
}

void QQIcon::resetIconName()
{
    setIconName(MultiName());
}

const QQSize &QQIcon::getPreferedSize() const
{
    return mPreferedSize;
}

void QQIcon::setPreferedSize(const QQSize &newPreferedSize)
{
    mPreferedSize = newPreferedSize;
}
