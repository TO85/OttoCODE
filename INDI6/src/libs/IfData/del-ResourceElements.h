#pragma once

#include <QSharedDataPointer>

class ResourceElementsData;

class ResourceElements
{
public:
    ResourceElements();
    ResourceElements(const ResourceElements &);
    ResourceElements &operator=(const ResourceElements &);
    ~ResourceElements();

private:
    QSharedDataPointer<ResourceElementsData> data;
};

