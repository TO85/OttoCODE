#pragma once
/* @file: QQIcon.h */
#include "eirGui.h"

#include <eirType/MultiName.h>
#include <eirType/QQFileInfoList.h>
#include <eirType/QQSize.h>

class EIRGUI_EXPORT QQIcon : public QIcon
{
public:
    QQIcon(const QIcon aSand);
    explicit QQIcon() = default;
    QQIcon(const QQIcon &other) = default;
    ~QQIcon() = default;
    QQIcon &operator = (const QQIcon &other) = default;

public:
    MultiName iconName() const;

public: // access
    MultiName getIconName() const;
    void setIconName(const MultiName &newIconName);
    void resetIconName();
    const QQSize &getPreferedSize() const;
    void setPreferedSize(const QQSize &newPreferedSize);

private:
    MultiName mIconName;
    QQFileInfoList mFileInfoList;
    QQSize mPreferedSize;
};

Q_DECLARE_METATYPE(QQIcon);

