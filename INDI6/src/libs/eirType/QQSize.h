#pragma once
#include "eirType.h"

#include <QtCore/QSize>

#include <QtCore/QList>
#include <QtCore/QMetaType>
#include <QtCore/QPoint>

#include "QQPoint.h"
#include "QQString.h"
#include "Rational.h"

class EIRTYPE_EXPORT QQSize : public QSize
{
public:
    typedef QList<QQSize> List;

public:
    QQSize(const int dim) : QSize(dim, dim) {;}
    QQSize(const int width, const int height) : QSize(width, height) {;}
    QQSize(const QSize other) : QSize(other) {;}
    QQSize() = default;
    QQSize(const QQSize &other) = default;
    ~QQSize() = default;
    QQSize &operator=(const QQSize &other) = default;

    bool isSquare() const { return width() == height(); }
    bool notSquare() const { return ! isSquare(); }
    Rational aspect() const { return Rational(width(), height()); }
    QQPoint center() const { return QQPoint(width() / 2, height() / 2); }
    int rows() const { return height(); }
    int cols() const { return width(); }
    int area() const { return width() * height(); }
    int count() const { return area(); }
    int index(const QQPoint pt) const;
    bool less(const QQSize &other) const { return area() < other.area(); }
    QQString toString() const { return QQString("(%1x%2)").formatMessage(width(), height()); }
    operator QString () const { return toString(); }
    QQSize scaled(const Rational r) const;
    QQSize scaled(const int iScale) const { return it() * qreal(iScale); }
    bool operator < (const QQSize &other) const { return less(other); }

    void set(const int aWidth, const QQSize aAspect);
    void set(const QQSize newSize) { it() = newSize; }
    void invalidate() { setWidth(-1), setHeight(-1); }
    void empty() { set(emptySize()); }
    void nullify() { empty(); }

public: // static
    static const QQSize emptySize() { return QQSize(0, 0); }

private:
    QQSize &it() { return *this; }
    QQSize it() const { return *this; }

public: // debug
    QQString toDebugString() const;
};

Q_DECLARE_METATYPE(QQSize);

extern EIRTYPE_EXPORT bool operator < (const QQSize &lhs, const QQSize &rhs);

