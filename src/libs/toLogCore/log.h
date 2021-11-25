//! @file log.h Log Namespace Wrapper (in {torc repo}./src/lib/toLogCore
#pragma once
#include "toLogCore.h"

#include <QObject>

#include <QMetaEnum>

class TOLOGCORE_EXPORT log : public QObject
{
    Q_GADGET
public:
    enum Severity
    {
        $nullSev            = 0,
        LogInternal         = 0x10,
        Info                = 0x20,
        FunctionPointer     = 0x50,
        Dump                = 0x60,
        Trace               = 0x70,
        Caution             = 0xA0,
        Warning             = 0xB0,
        Error               = 0xC0,
        Severe              = 0xD0,
        Fatal               = 0xE0,
        System              = 0xF0,
        Nuclear             = 0xF8,
        MeltDown            = 0xFC,
        ChinaSyndrome       = 0xFE,
        $maxSev             = 0xFF
    };
    Q_ENUM(Severity);

    enum SeverityDetail
    {
        $nullSevd           = 0,
        Lowissimo           = 0x01,
        Lowest              = 0x02,
        Lower               = 0x04,
        Low                 = 0x08,
        Neutral             = 0x10,
        High                = 0x20,
        Higher              = 0x40,
        Highest             = 0x80,
    };
    Q_ENUM(SeverityDetail);

    enum SubSystem
    {
        $nullSubs           = 0,
        LibrarySubs         = 0x01,
        ApplicationSubs     = 0x02,
        ServiceSubs         = 0x03,
        CloudSubs           = 0x04,
        ReservedSubs5       = 0x05,
        ReservedSubs6       = 0x06,
        ReservedSubs7       = 0x07,
        SpeedTestSubs       = 0x08,
        SysTestSubs         = 0x10,
        RegressionSubs      = 0x20,
        UnitTestSubs        = 0x40,
        TodoSubs            = 0x80,
    };
    Q_ENUM(SubSystem);

public:
    explicit log(QObject *parent = nullptr) : QObject(parent) {;}
    template<typename ENUM> QString name(const ENUM enumValue)
    { return QMetaEnum::fromType<ENUM>().valueToKey(enumValue); }

signals:
};
