#pragma once
#include "eirType.h"
/** \file BooleanString.h Declaration of BooleanString class
 *
 */

#include <QtCore/QMetaType>

#include "QQBitArray.h"
#include "QQString.h"

/*! \brief Parses a string into a QBitArray
 *
 */
class EIRTYPE_EXPORT BooleanString
{
public:
    /*!
     * \brief BooleanString Parse using default true/false values ('+'/'-')
     * \param aString The string to parse
     * \sa setValidTrueFalse()
     */
    BooleanString(const QQString aString) { set(aString); }
    BooleanString(const QQString aString, const QQString &validTrue, const QQString &validFalse);
    explicit BooleanString() = default; //! Constructs a null default item
    BooleanString(const BooleanString &other) = default; //! Default copy c'tor
    ~BooleanString() = default; //! Default d'tor
    BooleanString &operator = (const BooleanString &other) = default; //! Default copy assignment

public: // access
    //! The parsed true/false bits (const)
    QQBitArray bits() const { return mBits; }
    //! The parsed true/false bits (non-const)
    QQBitArray &bits() { return mBits; }
    //! The parsed string with unknown characters as spaces (const)
    QQString string() const { return mString; }
    //! The parsed string with unknown characters as spaces (non-const)
    QQString &string() { return mString; }
    //! The number of parsed characters
    int count() const { return mString.count(); }
    //! The number of (true/false) bits counted
    int count(const bool tBool) const { return mBits.count(tBool); }

public: // command
    /*!
     * \brief set Parses the input string into output string and bit array
     * \param aString The input string
     * \return The parsed string
     * \see bits()
     * \sa string()
     */
    QQString set(const QQString &aString);

public: // static
    /*!
     * \brief setValidTrueFalse Replaces the default characters to be considered true/false
     * \param aValidTrue New true characters
     * \param aValidFalse New false characters
     */
    void setValidTrueFalse(const QQString &aValidTrue, const QQString &aValidFalse);

private:
    QQString mString;
    QQBitArray mBits;

private:
    static QQString smValidTrue;
    static QQString smValidFalse;
};

Q_DECLARE_METATYPE(BooleanString);
