#include "CommandLineSettings.h"

#include <eirXfr/Debug.h>

CommandLineSettings::CommandLineSettings(QObject *parent)
    : BaseVolatileSettings(parent)
{
    setObjectName("CommandLineSettings");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
}

CommandLineSettings::CommandLineSettings(const QQStringList aList, QObject *parent)
    : BaseVolatileSettings(parent)
{
    setObjectName("CommandLineSettings");
    TRACEQFI << QOBJNAME(parent) << QOBJNAME(this);
    set(aList);
}

void CommandLineSettings::clear()
{
    TRACEQFI << count();
    BaseVolatileSettings::clear();
    mOtherStrings.clear();
}

void CommandLineSettings::set(const QQStringList aList, const bool clearFirst)
{
    TRACEQFI << aList.count();
    if (clearFirst) clear();
    for (QQString arg : aList)
    {
        if (arg.startsWith('/'))
            append(split(arg.mid(1)));
        else
            mOtherStrings << arg;
    }
}

/* ----------------------- private ------------------------- */

void CommandLineSettings::append(const QQVariant::KeyValue &keyValue)
{
    TRACEQFI << keyValue.first.toString() << keyValue.second.toString();
    setValue(keyValue.first.toString(), keyValue.second);
}

QQVariant::KeyValue CommandLineSettings::split(const QQString &aString)
{
    QQVariant::KeyValue result;
    QQVariant::Key key;
    QQVariant vari;
    int equalPos = aString.indexOf('=');
    if (equalPos < 0)
    {
        key = MultiName(aString);
        vari = QVariant( ! aString.endsWith('!'));
    }
    else if (equalPos > 2)
    {
        key = MultiName(aString.left(equalPos));
        vari = QVariant(aString.mid(equalPos+1));
    }
    result.first = key, result.second = vari;
    TRACEQFI << aString << equalPos << result.first.toString() << result.second.toString();
    return result;
}
