#include "BooleanString.h"

#include <eirXfr/Debug.h>

#include "QQStringList.h"

QQString BooleanString::smValidTrue("1t+");
QQString BooleanString::smValidFalse("0f-");


/*!
 * \brief BooleanString Parse using specified true/false values
 * \param aString The string to parse
 * \param validTrue Characters that are considered true
 * \param validFalse Characters that are considered false
 */
BooleanString::BooleanString(const QQString aString,
                             const QQString &validTrue,
                             const QQString &validFalse)
{
    setValidTrueFalse(validTrue, validFalse);
    set(aString);
}

QQString BooleanString::set(const QQString &aString)
{
    TRACEQFI << aString.split(64).toDebugStrings() << smValidTrue << smValidFalse;
    const int nInput = aString.size();
    QQString result;
    result.fill(' ', nInput);
    QQBitArray bta(nInput, false);
    int index = 0;

    for (QChar c : aString)
    {
        if (smValidTrue.contains(c))
        {
            result[index] = c;
            bta[index] = true;
        }
        if (smValidFalse.contains(c))
        {
            result[index] = c;
            bta[index] = false;
        }
    //  else (neither) so, ignore input
        index++;
    }
    const int nOutput = index;
    result.resize(nOutput);
    bta.resize(nOutput);

    DUMPVAL(bta);
    DUMPVAL(result);
    mBits = bta;
    mString = result;
    return result;
}

void BooleanString::setValidTrueFalse(const QQString &aValidTrue, const QQString &aValidFalse)
{
    smValidTrue = aValidTrue, smValidFalse = aValidFalse;
}
