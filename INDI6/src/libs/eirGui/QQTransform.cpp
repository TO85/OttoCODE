#include "QQTransform.h"

#include <eirType/Angle.h>
#include <eirXfr/Debug.h>


void QQTransform::reset()
{
    TRACEQFI << toAttributeDebugString();
    comment("reset:");
    QTransform::reset();
}

QQTransform &QQTransform::rotateRadians(qreal aAngle, Qt::Axis aAxis)
{
    TRACEQFI << aAngle << aAxis << toAttributeDebugString();
    comment(QQString("rotateRadians: angle=%1 (%2), axis=%3")
                    .arg(aAngle).arg(Angle::degreesFromRadians(aAngle)).arg(aAxis));
    QTransform::rotateRadians(aAngle, aAxis);
    dump();
    return it();
}

QQTransform &QQTransform::translate(qreal dx, qreal dy)
{
    TRACEQFI << dx << dy << toAttributeDebugString();
    comment(QQString("translate: dx=%1, dy=%3").arg(dx).arg(dy));
    QTransform::translate(dx, dy);
    dump();
    return it();
}

/* ---------------------- private ------------------------- */

void QQTransform::initComments()
{
    if (isIdentity()) mCommentList << QString("identity: %1").arg(toDebugString());
}

void QQTransform::comment(const QQString aComment)
{
    initComments();
    mCommentList << aComment;
}

/* ---------------------- debug ------------------------- */

QQString QQTransform::toDebugString() const
{
    return QQString("m11=%1 m12=%2 m13=%3 m21=%4 m22=%5 m23=%6 m31=%7 m32=%8 m33=%9 dx=%10 dy=%11")
            .arg(m11()).arg(m12()).arg(m13()).arg(m21()).arg(m22()).arg(m23())
            .arg(m31()).arg(m32()).arg(m33()).arg(dx()).arg(dy());
}

QQString QQTransform::toAttributeDebugString() const
{
    return QQString("%1Affine %2Identity %3Invertible %4Rotating %5Scaling %6Translating ")
            .arg(isAffine() ? "is" : "not").arg(isIdentity() ? "is" : "not").arg(isInvertible() ? "is" : "not")
            .arg(isRotating() ? "is" : "not").arg(isScaling() ? "is" : "not").arg(isTranslating() ? "is" : "not");
}


QQStringList QQTransform::toDebugStrings() const

{
    QQStringList result;
    result << "{QQTransform:>";
    result << mCommentList;
    result << toAttributeDebugString();
    result << toDebugString();
    result << "<QQTransform}";
    return result;
}

void QQTransform::dump() const
{
    for ( QQString s : toDebugStrings() )
        DUMP << s;
}

/* ---------------------- non-member ------------------------- */


QDebug operator << (QDebug dbg, const QQTransform &xf)
{
    for (QQString s : xf.toDebugStrings())
        dbg << s <<Qt::endl;
    return dbg;
}
