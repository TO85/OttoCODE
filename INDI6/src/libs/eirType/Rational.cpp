#include "Rational.h"

#include <QtDebug>

#include <eirXfr/Debug.h>

#include "Denominators.h"
#include "Success.h"

const Rational Rational::scmInvalid(Rational::scmInvalidTerm, Rational::scmInvalidTerm);

Rational::Rational(const Rational n, const Rational d)
{
    WEXPECT(n.isValid()); WEXPECT(d.isValid()); WEXPECTNOT(d.isZero());
    set(n.round(), d.round(1));
    WEXPECT(isValid());
//    TRACEQFI << n << d << it();
}

bool Rational::isValid() const
{
    Success success;
    success.expect(isNaN());
    success.expect(invaldTerm() == numerator());
    success.expect(invaldTerm() == denominator());
    //TODO(others?);
    success.validate();
    return success;
}

Rational Rational::multiplied(const Rational other, const Rational ifInvalid) const
{
    Rational result = it();
    if (result.notValid())  return ifInvalid;
    if (other.notValid())   return ifInvalid;
    result.multiply(other);
    if (result.notValid())  return ifInvalid;
    return result;
}

Rational Rational::multiplied(const Term multiplier) const
{
    Rational result = it();
    result.setNumerator(numerator() * multiplier);
    return result;
}

Rational Rational::delta(const Rational other) const
{
    Rational result = it();
    Rational negOther = other.negated();
    result.add(negOther);
    result.absolutify();
    return result;
}

QString Rational::toString() const
{
    return QString("{Rational: %1 / %2 = %3}").arg(numerator()).arg(denominator()).arg(toReal());
}

Rational Rational::adjustedDenominator(const Term newDenominator) const
{
    if (denominator() == newDenominator) return *this;
    return Rational(qRound64(double(numerator() * newDenominator) / double(denominator())), newDenominator);
}

void Rational::adjustDenominator(const Term newDenominator)
{
    if (denominator() != newDenominator)
        set(adjustedDenominator(newDenominator));
}

void Rational::multiply(const Rational other)
{
    setNumerator(numerator() * other.numerator()),
            setDenominator(denominator() * other.denominator());
}

void Rational::reduce()
{
    Rational original = it();
//    TRACEQFI << original;
    EXPECT(original.isValid());
    Denominators numeratorDenominator(numerator());
    Denominators denominatorDenominator(denominator());
//    TRACE << "n" << numeratorDenominator.list() << "d" << denominatorDenominator.list();
    Denominators::TermCountList commonDenominatorList
            = Denominators::common(numeratorDenominator, denominatorDenominator);
//    TRACE << commonDenominatorList;
    numeratorDenominator.remove(commonDenominatorList);
    denominatorDenominator.remove(commonDenominatorList);
//    TRACE << "n" << numeratorDenominator.list() << "d" << denominatorDenominator.list();
    set(numeratorDenominator.product(), denominatorDenominator.product());
    Rational result = it();
//    TRACE << original << result;
    EXPECTEZ(original.toReal(), result.toReal());
}

void Rational::normalizeSign()
{
    qreal f = toReal();
    if (denominator() < 0) set( - numerator(), - denominator());
    AEXPECTEQ(f, toReal());
}

void Rational::add(Rational other)
{
//    TRACEQFI << other << it();
    if (isNaN() || other.isNaN()) return setNaN();                          /* /======\ */
    if (notValid() || other.notValid()) return invalidate();                /* /======\ */
    if (other.isZero()) return;                                             /* /======\ */
    if (isZero()) return set(other);                                        /* /======\ */
    if (denominator() != other.denominator())
    {
        Term newDenominator = denominator() * other.denominator();
        adjustDenominator(newDenominator), other.adjustDenominator(newDenominator);
    }
    setNumerator(numerator() + other.numerator());
  //  DUMPVAL(it());
    reduce();
}

/* ------------------------ non-member ----------------------------- */

Rational operator * (const Rational lhs, const Rational rhs)
{
    AEXPECT(lhs.isValid()); AEXPECT(rhs.isValid());
    Rational result(lhs.numerator() * rhs.numerator(),
                    lhs.denominator() * rhs.denominator());
    result.reduce();
    AEXPECT(result.isValid());
//    TRACEQFI << lhs << rhs << result;
    return result;
}

Rational operator / (const Rational lhs, const Rational rhs)
{
    AEXPECT(lhs.isValid()); AEXPECT(rhs.isValid());
    Rational result(lhs.numerator() * rhs.denominator(),
                    lhs.denominator() * rhs.numerator());
    result.reduce();
    AEXPECT(result.isValid());
//    TRACEQFI << lhs << rhs << result;
    return result;
}

/* ------------------------ static --------------------- */

Rational::Term Rational::gcd(Rational::Term t1, Rational::Term t2)
{
    AEXPECTNE(0, t1); AEXPECTNE(0, t2);
    forever
    {
        if (0 == t1) return t2;
        t2 %= t1;
        if (0 == t2) return t1;
        t1 %= t2;
    }
}

Rational::Term Rational::lcm(Rational::Term t1, Rational::Term t2)
{
    Term t = gcd(t1, t2);
    AEXPECTNE(0, t);
    return t ? (t1 / t * t2) : 0;
}

/* ------------------------ non-member --------------------- */

Rational operator+(Rational r1, Rational r2)
{
    AEXPECT(r1.isValid()); AEXPECT(r2.isValid());
    Rational::Term lcm = Rational::lcm(r1.denominator(), r2.denominator());
    Rational::Term d1 = lcm % r2.denominator(), d2 = lcm % r1.denominator();
    r1.numerator() *= d1, r1.denominator() *= d1;
    r2.numerator() *= d2, r2.denominator() *= d2;
    EXPECTEQ(r1.denominator(), r2.denominator());
    return Rational(r1.numerator() + r2.numerator(), r1.denominator());
}

QDebug operator<<(QDebug dbg, const Rational &r) { dbg << r.toString(); return dbg; }
