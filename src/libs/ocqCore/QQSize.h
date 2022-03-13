#pragma once
#include "ocqCore.h"


#include <QSize>

#include <QMetaType>


class OCQCORE_EXPORT QQSize : public QSize
{
public:
    QQSize(const QSize other) : QSize(other) {;}
    QQSize(const int width, const int height) : QSize(width, height) {;}

public:
    int area() const;

public:
    void nullify();

public: // static
    static QQSize null();

private:
    QQSize it() const { return *this; }
    QQSize & it() { return *this; }

private:
    static QQSize smNull;

public:
    QQSize() = default;
    ~QQSize() = default;
    QQSize(const QQSize &other) = default;
    QQSize &operator = (const QQSize &other) = default;
};


Q_DECLARE_METATYPE(QQSize);

