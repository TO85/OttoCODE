#pragma once
#include "ocType.h"

#include <QSharedDataPointer>
class MimeTypeData;


class OCTYPE_EXPORT MimeType
{
public:
    MimeType();
    MimeType(const MimeType &);
    MimeType &operator=(const MimeType &);
    ~MimeType();

private:
    QSharedDataPointer<MimeTypeData> data;
};

