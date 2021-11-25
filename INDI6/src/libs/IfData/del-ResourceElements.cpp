#include "del-ResourceElements.h"

class ResourceElementsData : public QSharedData
{
public:

};

ResourceElements::ResourceElements() : data(new ResourceElementsData)
{

}

ResourceElements::ResourceElements(const ResourceElements &rhs) : data(rhs.data)
{

}

ResourceElements &ResourceElements::operator=(const ResourceElements &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ResourceElements::~ResourceElements()
{

}
