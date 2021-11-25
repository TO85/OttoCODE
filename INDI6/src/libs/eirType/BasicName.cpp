#include "BasicName.h"

#include <eirXfr/Debug.h>

#include "QQString.h"
#include "QQStringList.h"

QRegularExpression BasicName::smListFromStringSeperatorRx = QRegularExpression("[,;]");
QRegularExpression BasicName::smValidFirstCharRx = QRegularExpression("[a-zA-Z$]");
QRegularExpression BasicName::smValidCharRx = QRegularExpression("[a-zA-Z0-9_$]");
QChar BasicName::smInvalidReplaceChar; // null default


/*! \class BasicName
 *  \brief The BasicName class provides a single-element name.
 *  \sa MultiName
 *  \sa Type Library
 *  \sa PersonName
 *  \note This and the MultiName class provide variable-type
 *      names, not intended for names of people.
 *      See (eventually) the PersonName class in the
 *      Type (TBD?) library for that use.
 *  \since v1.00
 */

/*!
 * \brief BasicName::BasicName constructs a name from a QString().
 * \param sName is the initial name.
 * \since v1.00
 */
BasicName::BasicName(const QQString &sname)
{
    set(sname);
}

/*!
 * \brief BasicName::BasicName constructs a name
 *      from a null-terminated character string.
 * \param cName is the initial name
 * \since v1.02
 */
BasicName::BasicName(const char *cName)
{
    set(QString::fromLocal8Bit(cName));
}

/*!
 * \brief BasicName::BasicName constructs a name from a QByteArray().
 * \param ba contains the initial name.
 * \since v1.01
 */
BasicName::BasicName(const QByteArray & ba)
{
    set(QString::fromLocal8Bit(ba.data()));
}


bool BasicName::isEmpty() const
{
    return mName.isEmpty();
}

bool BasicName::notEmpty() const
{
    return ! isEmpty();
}

/*!
 * \brief BasicName::toString returns the string.
 * \return the stored QString()
 * \since v1.00
 */
QQString BasicName::toString() const
{
    return mName;
}

QByteArray BasicName::toByteArray() const
{
    return mName.toLocal8Bit();
}

/*!
 * \brief BasicName::operator QString convenience
 *      cast access to toString().
 * \return the stored QString().
 * \since v1.01
 */
BasicName::operator QQString(void) const
{
    return toString();
}

/*!
 * \brief BasicName::operator () convenience
 *      operator access to toString().
 * \return the stored QString().
 * \since v1.01
 */
QString BasicName::operator () () const
{
    return QString(toString());
}

/*!
 * \brief BasicName::set sets a new name
 * \param name is a QString() containing the new name.
 * \since v1.00
 * \todo Parse the input string for valid name characters.
 */
void BasicName::set(QQString name)
{
    mName.clear();
    QString s = name.takeFirst();
    mName.append(smValidFirstCharRx.match(s).hasMatch() ? s : smInvalidReplaceChar);
    while (name.notEmpty())
    {
        s = name.takeFirst();
        mName.append(smValidCharRx.match(s).hasMatch() ? s : smInvalidReplaceChar);
    }
}

#if 0
/*!
 * \brief BasicName::toVariant creates a string-valued QVariant().
 * \return the QVariant().
 * \since v1.02
 */
QQVariant BasicName::toVariant() const
{
    return QQVariant(toString());
}

/*!
 * \brief BasicName::operator QVariant convenience cast
 *      access to toVariant().
 * \return the QVariant().
 * \since v1.02
 */
inline BasicName::operator QQVariant(void) const
{
    return toVariant();
}
#endif
/*!
 * \brief BasicName::sortable
 * \return a sortable QByteArray().
 * \since v1.01
 * \internal
 */
BasicName::Sortable BasicName::sortable() const
{
    return toByteArray().toLower();
}

/*!
 * \brief BasicName::operator== compares stored string
 *      to another instance.
 * \return true if the sortable strings are equal.
 * \since v1.01
 */
bool BasicName::operator == (const BasicName & other) const
{
    return sortable() == other.sortable();
}

bool BasicName::operator !=(const BasicName &other) const
{
    return sortable() != other.sortable();
}

/*!
 * \brief BasicName::operator< compares stored string
 *      to another instance.
 * \param the right hand side
 * \return true if this sortable string is less than the other.
 * \since v1.01
 */
bool BasicName::operator <  (const BasicName &other) const
{
    return sortable() < other.sortable();
}

// static
bool BasicName::isValidChar(const QChar &sChar)
{
    WANTDO(More than space)
    return (' ' == sChar);
}

/*!
 * \brief static BasicName::toStringList
 *      converts a list if BasicName entries to a list of QStrings.
 * \param basicList input list of BasicName items
 * \return QQStringList list converted to QStrings
 *
 */
QQStringList BasicName::toStringList(BasicName::List basicList)
{
    QQStringList result;
    foreach(BasicName basicName, basicList)
        result << basicName.toString();
    return result;

}

BasicName::List BasicName::listFrom(const QQStringList &names)
{
    BasicName::List result;
    for (QQString name : names)
        result << BasicName(name);
    return result;
}

// ------------------------------------- static  ---------------------------------------

BasicName::List BasicName::listFrom(QQString &names)
{
    TRACEQFI << names;
    names.replace(smListFromStringSeperatorRx, " ");
    QQStringList nameList = names.simplified().split(' ');
    return listFrom(nameList);
}

// ------------------------------------- non-member  ---------------------------------------

QDebug operator << (QDebug dbg,  const BasicName &bn)
{
    dbg << bn.toString(); return dbg;
}

