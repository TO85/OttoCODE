#pragma once
#include "eirOpenCV.h"

#include <QtDebug>
#include <QtCore/QMetaType>

#include <opencv2/core/core.hpp>

#include "cvString.h"

class EIROPENCV_EXPORT cvException : public cv::Exception
{
public:
    cvException(const cv::Exception other);
    explicit cvException() = default;
    cvException(const cvException &other) = default;
    ~cvException() = default;
    cvException &operator = (const cvException &other) = default;

public:
    int errorCode() const;
    QString codeString() const;
    int fileLine() const;
    QString errorString() const;
    QString fileName() const;
    QString function() const;
    QString message() const;

    bool isNull() const { return -1 == errorCode(); }
    bool notNull() const { return ! isNull(); }

public:
    void clear();
    void process();

private:
    cvException it() const { return *this; }
    cvException &it() { return *this; }

public:
    QStringList toDebugStrings() const;
};

Q_DECLARE_METATYPE(cvException);

extern EIROPENCV_EXPORT QDebug operator << (QDebug dbg, const cvException &x);

