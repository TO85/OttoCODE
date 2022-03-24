#pragma once
#include "ocType.h"

#include <limits.h>

#include <QMetaType>

class OCTYPE_EXPORT Rational
{
public:
    typedef signed long long Term;
    typedef QPair<Term, Term> Pair;

public:
    Rational(const Term n, const Term d) : mNumerator(n), mDenominator(d) {;}
    Rational(const Term n) : mNumerator(n), mDenominator(1) {;}

public:
    Term numerator() const { return mNumerator; }
    qreal numeratorF() const { return qreal(mNumerator); }
    Term &numerator() { return mNumerator; }
    Term denominator() const { return mDenominator; }
    qreal denominatorF() const { return qreal(mDenominator); }
    Term &denominator() { return mDenominator; }
    bool isNaN() const { return 0 == denominator(); }
    qreal toReal(const qreal ifNaN=qQNaN()) const { return isNaN() ? ifNaN : qreal(mNumerator) / qreal(mDenominator); }
    float toFloat(const qreal ifNaN=qQNaN()) const { return isNaN() ? ifNaN : float(mNumerator) / float(mDenominator); }
    double toDouble(const qreal ifNaN=qQNaN()) const { return isNaN() ? ifNaN : double(mNumerator) / double(mDenominator); }
    operator qreal () const { return toReal(0.0); }
    Term invalidTerm() const { return LLONG_MIN; }
    Rational invalid() const { return Rational(invalidTerm(), 0); }

private:
    Rational &it() { return *this; }
    Rational it() const { return *this; }

private:
    Term mNumerator=0;
    Term mDenominator=0;

public: // QMetaType
    Rational() = default;
    ~Rational() = default;
    Rational(const Rational &other) = default;
    Rational &operator = (const Rational &other) = default;
};

Q_DECLARE_METATYPE(Rational);

#if 0
class EIRTYPE_EXPORT Rational
{
public:
    Rational(const Pair p)  : mNumerator(p.first), mDenominator(p.second) {;}
    Rational(const QSize sz)  : mNumerator(sz.width()), mDenominator(sz.height()) {;}
    Rational(const Rational n, const Rational d);
    ~Rational() = default;
    Rational &operator=(const Rational &other) = default;

    static Term invaldTerm() { return scmInvalid; }
    static Rational invalid() { return Rational(scmInvalid, scmInvalid); }

    bool isNull() const { return 0 == numerator() && 0 == denominator(); }
    bool isValid() const;
    bool notValid() const { return ! isValid(); }
    bool isZero() const { return  0 == numerator(); }
    bool notZero() const { return  ! isZero(); }
    bool isNegative() const { return (numerator() * denominator()) < 0; }
    bool isUnit(const bool formal=true) const;
    bool isGreater(const Rational &other) { return numerator() > other.adjustedDenominator(denominator()).numerator(); }
    Term round(const Term ifNaN=scmInvalid) const { return isNaN() ? ifNaN : qRound(qreal(numerator()) / qreal(denominator())); }
    Rational multiplied(const Rational other, const Rational ifInvalid=Rational(0,0)) const;
    Rational multiplied(const Term multiplier) const;
    Rational absolutified() const { return Rational(qAbs(numerator()), qAbs(denominator())); }
    Rational negated() const { Rational result( - numerator(), denominator()); result.normalizeSign(); return result; }
    Rational delta(const Rational other) const;
    Rational inverted() const { return Rational(mDenominator, mNumerator); }
    bool operator > (const Rational &other) { return isGreater(other); }

    void set(const Rational other) { set(other.numerator(), other.denominator()); }
    void set(const Term n, const Term d) { setNumerator(n), setDenominator(d); }
    void setF(const qreal f, const Term d=1000000000) { set(qRound(f * qreal(d)), d); }
    void setNumerator(const Term n) { mNumerator = n; }
    void setDenominator(const Term d) { mDenominator = d; }
    Rational adjustedDenominator(const Term d) const;
    void adjustDenominator(const Term newDenominator);
    void multiply(const Rational other);
    void reduce();
    void absolutify() { it() = absolutified(); }
    void negate() { it() = negated(); }
    void nullify() { set(0, 0); }
    void invalidate() { set(invalid()); }
    void setNaN() { setDenominator(0); }
    void normalizeSign();
    void unitify(const bool byModulo=false);
    void add(Rational other);
    Rational operator += (const Rational other) { add(other); return it(); }

public: // static
    static Term gcd(Rational::Term t1, Rational::Term t2);
    static Term lcm(Rational::Term t1, Rational::Term t2);

public: // debug
    QString toString() const;

};

Q_DECLARE_METATYPE(Rational);

extern EIRTYPE_EXPORT Rational operator * (const Rational lhs, const Rational rhs);
extern EIRTYPE_EXPORT Rational operator / (const Rational lhs, const Rational rhs);
extern EIRTYPE_EXPORT QDebug operator << (QDebug dbg, const Rational &item);
#endif
