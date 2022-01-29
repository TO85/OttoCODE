#include "QQString.h"

#if 0
#include <QtCore/QRegularExpression>

#include <eirXfr/Debug.h>

#include "QQStringList.h"

QChar QQString::smDelimiter=QChar('/');

QQString::QQString(const Flags flags) : mFlags(flags) {;}
QQString::QQString(const QString &other, const Flags flags)
    : QString(other), mFlags(flags) { ctor(); }
QQString::QQString(const char *pch, const char *disambigulation)
    : QString(QObject::tr(pch, disambigulation)) {;}
QQString::QQString(const QString &other, const QRegularExpression validRX)
    { set(other, validRX); ctor(); }
QQString::QQString(const char *pch, const Flags flags)
    : QString(pch), mFlags(flags) { ctor(); }
QQString::QQString(const char aChar, const Flags flags)
    : mFlags(flags) { clear(); append(aChar); ctor(); }
QQString::QQString(const QQChar aChar, const Flags flags)
    : mFlags(flags) { clear(); append(aChar); ctor(); }
QQString::QQString(const QByteArray ba, const Flags flags)
    : QString(ba), mFlags(flags) { ctor(); }
QQString::QQString(const int count, const QChar c, const Flags flags)
    : QString(count, c),  mFlags(flags) { ctor(); }

QQString::QQString(const char *pchFormat, const QVariant &v1, const QVariant &v2, const QVariant &v3, const QVariant &v4)
{
    set(pchFormat, v1, v2, v3, v4);
}

QQString &QQString::operator =(const QQChar aChar)
{
    clear(); append(aChar); return it();
}

QQString QQString::print() const
{
    QQString result;
    for ( QChar ch : it() )
        result << (ch.isPrint() ? ch : '.');
    return result;
}

QQString QQString::takeFirst()
{
    return QQString(takeFirstChar());
}

QQString QQString::takeFirst(const int n)
{
    QQString result = left(n);
    remove(0, n);
    return result;
}

QQChar QQString::takeFirstChar()
{
    QQChar result(' ');
    if (notEmpty())
    {
        result = at(0);
        remove(0, 1);
    }
    return result;
}

void QQString::makeUpper()
{
    QQString result = it().toUpper();
    swap(result);
}

QQString QQString::subSample(const int skip)
{
    QQString result, copy = it();
    AEXPECT(skip >= 1);
    copy.remove(0, skip / 2);
    while (copy.notEmpty())
    {
        result << copy.takeFirstChar();
        copy.remove(0, skip);
    }
    return result;
}

void QQString::append(const QChar qch)
{
    QString::append(qch);
}

QQString QQString::operator <<(const QChar qch)
{
    append(qch); return it();
}

QQString QQString::squeezed() const
{
#if 1
    QQString result = it();
    return result.remove(QRegularExpression("\\s"));
#else
    return mid(0).simplified().replace(QQChar(' '), "");
#endif
}

QQString QQString::appended(const QQString s, const bool delimited) const
{
    QQString result = it();
    if (delimited && smDelimiter != s[0]) result.append(smDelimiter);
    return result + s;
}

QQString QQString::formatMessage(const QVariantList &vv) const
{
    return formatMessageVars(it(), vv);
}

QQString QQString::formatMessage(const QVariant &v1, const QVariant &v2, const QVariant &v3, const QVariant &v4) const
{
    return formatMessage4Var(it(), v1, v2, v3, v4);
}

void QQString::set(const QQString &other, const QRegularExpression validRX)
{
    TRACEQFI << other << validRX;
    while (other.notEmpty())
    {
        QString s1 = takeFirst();
        if (validRX.match(s1).isValid())
            append(s1);
    }
    TRACE << it();
}

void QQString::set(const QQString &format,
                   const QVariant &v1, const QVariant &v2,
                   const QVariant &v3, const QVariant &v4)
{
    it() = format.formatMessage(v1, v2, v3, v4);
}

QQString QQString::string(const QQString &ifEmpty) const
{
    return isEmpty() ? ifEmpty : it();
}

QQStringList QQString::split(const QQString &sep, Qt::SplitBehavior behavior,
                             Qt::CaseSensitivity cs, const Flags flags) const
{
    QQStringList result;
    QQStringList splits = QQStringList(QString::split(sep, behavior, cs));
    for (QQString string : splits)
        result.append(QQString(string, flags));
    return result;
}
#if 0
QQStringList QQString::split(const QQChar sep, Qt::SplitBehavior behavior, Qt::CaseSensitivity cs) const
{
    return QQStringList(QString::split(sep, behavior, cs));
}
#endif
QQStringList QQString::split(const int width) const
{
    QQStringList result;
    const int aw = (qAbs(width) < 16) ? 16 : qAbs(width);
    const bool onWhite = width < 0;
    QQString copy = simplified();
    while (copy.notEmpty())
    {
        QQString takeString;
        if (copy.count() < aw)
        {
            takeString = copy;
            copy.clear();
        }
        else
        {
            int take = aw;
            if (onWhite)
            {
                take = copy.lastIndexOf(' ', aw - copy.count());
                if (take < 16) take = aw;
            }
            takeString = copy.takeFirst(take);
        }
        result << takeString;
    }
    return result;
}

bool QQString::equals(const QQString &other)  const
{
    return 0 == QString::compare(other, Qt::CaseInsensitive);
}

bool QQString::lessthan(const QQString &other) const
{
    return QString::compare(other) < 0;
}

/* ------------------------ static ------------------------- */

QQString QQString::formatMessageVars(const QQString &aFormat, const QVariantList &vv)
{
    QQString result = aFormat;
    for (int i = 1; i <= 9 && result.contains("%"+QString::number(i)); ++i)
    {
        QString replaceString("%"+QString::number(i));
        if (result.contains(replaceString))
            result.replace(replaceString, vv.at(i).toString());
    }
    return result;
}

QQString QQString::formatMessage4Var(const QQString &aFormat, const QVariant &v1, const QVariant &v2,
                                 const QVariant &v3, const QVariant &v4)
{
    QVariantList qvl = QVariantList() << QVariant(aFormat) << v1 << v2 << v3 << v4;
    return formatMessageVars(aFormat, qvl);
}

/* ------------------------ private ------------------------- */

void QQString::ctor()
{
    if (mFlags & Simplify) set(string().simplified());
    if (mFlags & Squeeze)  set(string().squeezed());
}
#endif
