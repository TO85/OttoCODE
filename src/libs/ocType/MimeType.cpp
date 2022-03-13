#include "MimeType.h"

class MimeTypeData : public QSharedData
{
public:

};

MimeType::MimeType() : data(new MimeTypeData)
{

}

MimeType::MimeType(const MimeType &rhs)
    : data{rhs.data}
{

}

MimeType &MimeType::operator=(const MimeType &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

MimeType::~MimeType()
{

}
