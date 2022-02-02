#pragma once

#include <QObject>

#include <QtDebug>

class KeyItem;

class Log : public QObject
{
    Q_GADGET
public:
    enum Severity
    {
        $nullSeverity   = 0,
        Detail          = 0x00000004,
        Dump            = 0x00000010,
        Trace           = 0x00000040,
        Info            = 0x00000100,
        Progress        = 0x00000400,
        Warning         = 0x00001000,
        WExpect         = 0x00004000,
        Severe          = 0x00010000,
        Expect          = 0x00040000,
        Critical        = 0x00100000,
        Assert          = 0x01000000,
        AExpect         = 0x04000000,
        System          = 0x08000000,
        Nuclear         = 0x10000000,
        Maximum         = 0x80000000,
    };
    Q_ENUM(Severity);
    KeyItem severityKey(const Severity value) const;
    Severity severityValue(const KeyItem &key) const;
    QtMsgType severityMsgType(const Severity value) const;

public:
    explicit Log();

signals:

};


