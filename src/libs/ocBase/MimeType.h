#pragma once

#include <QSharedDataPointer>

class MimeTypeData;

class MimeType
{
public:
    MimeType();
    MimeType(const MimeType &);
    MimeType &operator=(const MimeType &);
    ~MimeType();

private:
    QSharedDataPointer<MimeTypeData> data;
};

