#pragma once
#include "eirOpenCV.h"

#include <QtCore/QString>

#include <QtCore/QMetaType>

#include <opencv2/core/cvstd.hpp>

#include "cvString.h"

class EIROPENCV_EXPORT cvQString : public QString
{
public:
    cvQString(const QString &other) : QString(other) {;}
    cvQString(const cvString &other);
    explicit cvQString() = default;
    cvQString(const cvQString &other) = default;
    ~cvQString() = default;
    cvQString &operator = (const cvQString &other) = default;
};

Q_DECLARE_METATYPE(cvQString);

