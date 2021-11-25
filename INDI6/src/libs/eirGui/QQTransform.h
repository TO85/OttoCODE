#pragma once
#include "eirGui.h"

#include <QtDebug>

#include <eirType/QQPoint.h>
#include <eirType/QQStringList.h>



class EIRGUI_EXPORT QQTransform : public QTransform
{
public:
    QQTransform() = default;
    QQTransform(const QTransform &other) : QTransform(other) {;}
    QQTransform(const QQTransform &other) = default;
    ~QQTransform() = default;
    QQTransform &operator = (const QQTransform &other) = default;

    QQTransform it() const { return *this; }
    QQTransform &it() { return *this; }

    void reset();
    QQTransform &rotateRadians(qreal angle, Qt::Axis axis = Qt::ZAxis);
    QQTransform &translate(qreal dx, qreal dy);
    QQTransform &translate(QQPoint pt) { return translate(pt.x(), pt.y()); }

private:
    void initComments();
    void comment(const QQString aComment);

public: // debug
    QQString toDebugString() const;
    QQString toAttributeDebugString() const;
    QQStringList toDebugStrings() const;
    void dump() const;

private:
    QQStringList mCommentList;
};

Q_DECLARE_METATYPE(QQTransform);

extern EIRGUI_EXPORT QDebug operator << (QDebug dbg, const QQTransform &xf);
