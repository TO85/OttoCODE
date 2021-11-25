#pragma once
#include "eirType.h"

#include <QPoint>

#include <limits.h>

#include <QtCore/QMetaType>

class QQPointF;

class EIRTYPE_EXPORT QQPoint : public QPoint
{
public:
    typedef QList<QQPoint> List;

public:
    QQPoint(const QPoint &other) : QPoint(other) {;}
    QQPoint(const int x, const int y) : QPoint(x, y) {;}
    QQPoint() = default;
    QQPoint(const QQPoint &other) = default;
    ~QQPoint() = default;
    QQPoint &operator=(const QQPoint &other) = default;

public: // access
    int row() const { return y(); }
    int col() const { return x(); }
    qreal xF() const { return qreal(x()); }
    qreal yF() const { return qreal(y()); }

public: // status
    bool notValid() const { return invalidPoint() == it(); }
    bool isValid() const { return ! notValid(); }
    bool isOrigin() const { return 0 == x() && 0 == y(); }
    QQPointF toPointF() const;
    int distance(const QQPoint other) const;
    qreal distanceF(const QQPoint other) const;
    QQPoint negated() const { return QQPoint( - x(), - y()); }

public: // commands
    void set(const int x, const int y) { setX(x), setY(y); }
    void nullify() { set(0, 0); }
    void invalidate() { set(INT_MIN, INT_MIN); }

public: // static
    static QQPoint invalidPoint() { return scmInvalid; }

private:
    QQPoint it() const { return *this; }
    QQPoint &it() { return *this; }

public: // debug
    QString toDebugString() const;

private: // static
    static const QQPoint scmInvalid;
};

Q_DECLARE_METATYPE(QQPoint);

extern EIRTYPE_EXPORT uint qHash(const QQPoint &dr, uint seed);
