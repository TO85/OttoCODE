#pragma once



#include <QMetaType>

class cvMat
{
public:


public: // QMetaType
    cvMat() = default;
    ~cvMat() = default;
    cvMat(const cvMat &other) = default;
    cvMat &operator = (const cvMat &other) = default;
};


Q_DECLARE_METATYPE(cvMat);


