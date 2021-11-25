#pragma once
#include "IfData.h"

#include <eirGui/Document.h>

class MainResource
{
public:
    MainResource() {;}

public:
    BasicName name() const { return mName; }
    BasicName className() const { return mClassName; }
    Document description() const { return mDescription; }
    QQSize normalSize() const { return mNormalSize; }
    int activePixels() const { return mActivePixels; }
    EyeLine normalEyeLine() const { return mNormalEyeLine; }

public:
    void clear();
    void setName(const BasicName &newName) { mName = newName; }
    void setClassName(const BasicName &newClassName) { mClassName = newClassName; }
    void setDescription(const Document &newDescription) { mDescription = newDescription; }
    void setActivePixels(int newActivePixels) { mActivePixels = newActivePixels; }
    void setNormalSize(const QQSize &newNormalSize) { mNormalSize = newNormalSize; }
    void setNormalEyeLine(const EyeLine &newNormalEyeLine) { mNormalEyeLine = newNormalEyeLine; }

public:
    QQStringList toDebugStrings() const;
    void dump() const { for (auto s : toDebugStrings().list()) DUMP << s; }

private:
    BasicName mName;
    BasicName mClassName;
    Document mDescription;
    int mActivePixels=0;
    QQSize mNormalSize;
    EyeLine mNormalEyeLine;

};

