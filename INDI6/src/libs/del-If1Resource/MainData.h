#pragma once
#include "If1Resource.h"

#include "Resource1BaseData.h"

class MainDataData;

class IF1RESOURCE_EXPORT MainData : public Resource1BaseData
{
public:
    explicit MainData() = default;
    MainData(const MainData &other) = default;
    ~MainData() = default;
    MainData &operator = (const MainData &other) = default;


public: // geters
    const BasicName className() const;
    const BasicName name() const;
    const QQString description() const;
    int pixelCount() const;
    const QQSize normalSize() const;
    const EyeLine normalEyes() const;

    void setClassName(const BasicName &newClassName);
    void resetClassName();
    void setName(const BasicName &newName);
    void resetName();
    void setDescription(const QQString &newDescription);
    void resetDescription();
    void setPixelCount(int newPixelCount);
    void resetPixelCount();
    void setNormalSize(const QQSize &newNormalSize);
    void resetNormalSize();
    void setNormalEyes(const EyeLine &newNormalEyes);
    void resetNormalEyes();

private:

private: // setters
    friend class MainDocument;


private:
    BasicName mClassName;
    BasicName mName;
    QQString mDescription;
    int mPixelCount=-1;
    QQSize mNormalSize;
    EyeLine mNormalEyes;
};

Q_DECLARE_METATYPE(MainData);
