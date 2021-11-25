/*! \file QProperty.h Declarations for QProperty mechanism
*/

/*!
Usage:

In .h file:
@code
#include <QObject>
#include <QRect>
class QTransform;

#include <QProperty.h>

#define TRANSFORM_QPROPERTIES(TND) \
        TND(qreal, Scale,   0.0) \
        TND(qreal, Aspect,  0.0) \
        TND(qreal, Rotate,  0.0) \
        TND(QRect, Crop,   QRectF()) \

class TransformProperties : public QObject
{
    Q_OBJECT
    DECLARE_QPROPERTIES(TRANSFORM_QPROPERTIES);
public:
    explicit TransformProperties(QObject *parent = 0);
    bool isNull(void) const;
    QTransform transform(void) const;
    int dimension(const QSizeF sz) const;
};
@endcode

In .cpp file:
@code
#include "TransformProperties.h"
#include <QtGui/QTransform>

#include "InfoMacros.h"

TransformProperties::TransformProperties(QObject *parent) :
    QObject(parent)
{
    DEFINE_QPROPERTIES_CTORS(TRANSFORM_QPROPERTIES);
    setObjectName("TransformProperties");
}
bool TransformProperties::isNull(void) const
...
@endcode

*/

#include <QVariant>

#define QPROPERTY_DECLARE(TYPE, NAME, DFLT) \
    public: \
        void init##NAME()          { QVariant vari; vari.setValue(DFLT); setProperty(#NAME, vari); } \
        void set##NAME(TYPE v)     { QVariant vari; vari.setValue(v); setProperty(#NAME, vari); } \
        TYPE get##NAME(void) const { QVariant vari = property(#NAME); return qvariant_cast<TYPE>(vari); } \

#define QPROPERTY_DECLARE_RO(TYPE, NAME, DFLT) \
    private: \
        void init##NAME()          { QVariant vari; vari.setValue(DFLT); setProperty(#NAME, vari); } \
        void set##NAME(TYPE v)     { QVariant vari; vari.setValue(v); setProperty(#NAME, vari); } \
    public: \
        TYPE get##NAME(void) const { QVariant vari = property(#NAME); return qvariant_cast<TYPE>(vari); } \

#define QPROPERTY_CTOR(TYPE, NAME, DFLT) \
        setProperty(#NAME, QVariant(DFLT)); \

#define DECLARE_QPROPERTIES(DEF) \
        DEF(QPROPERTY_DECLARE) \

#define DECLARE_QPROPERTIES_RO(DEF) \
        DEF(QPROPERTY_DECLARE_RO) \

#define DEFINE_QPROPERTIES_CTORS(DEF) \
        DEF(QPROPERTY_CTOR) \
