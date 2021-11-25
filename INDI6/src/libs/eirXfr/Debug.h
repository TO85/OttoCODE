// file: {INDI6 repo}./src/libs/eirType/Debug.h
#pragma once
#include "eirXfr.h"

#include <QtDebug>
#include <QCoreApplication>
#include <QDateTime>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QTimer>

#define PTRSTRING(ptr) QString("%1=0x%2").arg(#ptr).arg(quintptr(ptr), sizeof(quintptr) / 4, 16, QChar('0'))
#define QOBJNAME(pqobj) ((nullptr == pqobj) ? ("{null} " #pqobj) : ("QObject: (" #pqobj + (") " + pqobj->objectName())))
#define QOBJPTR(qpT) (qpT.isNull() ? Q_ASSERT(#qpT) : qpT)
#define TIME QDateTime::currentDateTime().toString("hh:mm:ss.zzz")

#define DEBUG(qmt, pfx) qmt() << pfx << TIME << __LINE__
#define DEBUGQFIN(qmt, pfx) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__ << Qt::endl
#define DEBUGQOB(qmt, pfx, mom) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__ << (mom ? mom->objectName() : "{orphan}");
#define DEBUGFN(qmt, pfx) { qmt() << pfx << TIME   << Q_FUNC_INFO << __LINE__; }
#define DEBUGPSZ(qmt, pfx, psz) { qmt(pfx << TIME  << __LINE__ psz); }
#define DEBUGQST(qmt, pfx, qst) { qmt(pfx << TIME << __LINE__  qPrintable(qst)); }
#define DEBUGDO(qmt, pfx, msg) { qmt() << pfx << TIME  << Q_FUNC_INFO << __LINE__ << "TODO:" << #msg; }
#define DEBUGUSE(qmt, pfx, var)  { (void)(var); qmt() << pfx << TIME   << Q_FUNC_INFO << __LINE__ << "TO USE:" << #var; }
#define DEBUGRTN(qmt, pfx, var)  {  return(var); qmt() << pfx << TIME   << Q_FUNC_INFO << __LINE__ << "TO RTN:" << #var; }
#define DEBUGEMIT(qmt, pfx, var)  {  (void)(var); qmt() << pfx << TIME   << Q_FUNC_INFO << __LINE__ << "TO EMIT:" << #var; }
#define DEBUGEXP(qmt, pfx, bexpr) { if ( ! (bexpr)) qmt() << pfx << TIME  << Q_FUNC_INFO << __LINE__ << Qt::endl << "Expectation FAILED:" << #bexpr; }
#define RDEBUGEXP(qmt, pfx, bexpr) { if ( ! (bexpr)) { qmt() << pfx << TIME  << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #bexpr; DEBUGQUIT; } }
#define DEBUGEXPI(qmt, pfx, bexpr, info) { if ( ! (bexpr)) qmt() << pfx << TIME  << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #bexpr << info; }
#define DEBUGXN(qmt, pfx, bexpr) { if (bexpr) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #bexpr; }
#define DEBUGXEQ(qmt, pfx, expt, var) { if (expt != var) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #expt << expt << "==" << #var << var; }
#define DEBUGXEZ(qmt, pfx, expt, var) { if ( ! qFuzzyCompare(expt, var)) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #expt << expt << "==" << #var << var; }
#define DEBUGXNE(qmt, pfx, expt, var) { if (expt == var) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #expt << expt << "!=" << #var << var; }
#define DEBUGXGT(qmt, pfx, expt, var) { if (expt <  var) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__  << Qt::endl << "Expectation FAILED:" << #expt << expt << ">" << #var << var; }
#define DEBUGXPTR(qmt, pfx, ptr) if (nullptr == ptr) qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__ << Qt::endl << "Pointer FAILED:" <<  #ptr;
#define DEBUGPTR(qmt, pfx, ptr, expr)     if (ptr) ptr->expr else DEBUG(qmt, pfx) "Pointer" << #ptr << "FAILED for" << #expr;
#define DEBUGFNR(qmt, pfx, expr) { qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__ << "Return:" << #expr << QString(expr); return expr; }
#define DEBUGRTV(qmt, pfx) { qmt() << pfx << TIME << Q_FUNC_INFO << __LINE__ << "Return(void)"; return; }
#define DEBUGQUIT Q_ASSERT(false);
#define DEBUGCON(qmt, pfx, src, sig, rec, slt) TSTALLOC(src); TSTALLOC(rec); if ( ! connect(src,sig,rec,slt)) DEBUG(qmt, pfx) << "Connect FAILED:" << #src << #sig << #rec << #slt;
#define DEBUGDCON(qmt, pfx, src, sig, rec, slt) TSTALLOC(src); TSTALLOC(rec); if ( ! disconnect(src,sig,rec,slt)) DEBUG(qmt, pfx) << "Disconnect FAILED:" << #src << #sig << #rec << #slt;

#define PINFO   "= INFO"
#define PDUMP   "~ DUMP"
#define PTRACE  "-TRACE"
#define PWARN   "* WARN"
#define PERROR  "#ERROR"
#define PASSERT  "@FATAL"
#define PITODO  "=ITODO"
#define PTODO   "- TODO"
#define PWTODO  "*WTODO"
#define PETODO  "#ETODO"
#define PBTODO  "@FTODO"

#define INFO                    DEBUG(qInfo, PINFO) // << stuff
#define INFOQFI                 DEBUGQFI(qInfo, PINFO) // << stuff
#define INFOFN()                DEBUGFN(qInfo, PINFO);
#define INFOPSZ(psz)            DEBUGPSZ(qInfo, PINFO, psz);
#define INFOQST(qst)            DEBUGQST(qInfo, PINFO, qPrintable(qst));
#define NEXPECT(bexpr)          DEBUGEXP(qInfo, PINFO, bexpr)
#define NEXPECTEQ(expt, var)    DEBUGXEQ(qInfo, PINFO, expt, var)
#define NEXPECTNE(expt, var)    DEBUGXNE(qInfo, PINFO, expt, var)
#define LIKEDO(msg)             DEBUGDO(qInfo, PITODO, msg)

#define DUMP                    DEBUG(qDebug, PDUMP) // << stuff
#define DUMPVAL(val)            DUMP << #val << val;
#define DUMPVALX(val)           DUMP << #val << Qt::endl; for (auto s : HexDump(&val, sizeof(val), 1, 1)) DUMP << s << Qt::endl;
#define DUMPHEX(ba)             DUMP << #ba << Qt::endl; for (auto s : HexDump(ba, 1, 1)) DUMP << s << Qt::endl;
#define TRACE                   DEBUG(qDebug, PTRACE) // << stuff
#define TRACEQFI                DEBUGQFIN(qDebug, PTRACE) // << stuff
#define TRACEQOB(mom)           DEBUGQOB(qDebug, PTRACE, mom);
#define TRACEFN                 DEBUGFN(qDebug, PTRACE);
#define TRACEPSZ(psz)           DEBUGPSZ(qDebug, PTRACE, psz);
#define TRACEQST(qst)           DEBUGQST(qDebug, PTRACE, qPrintable(qst));
#define TEXPECT(bexpr)          DEBUGEXP(qDebug, PTRACE, bexpr)
#define TEXPECTEQ(expt, var)    DEBUGXEQ(qDebug, PTRACE, expt, var)
#define TEXPECTNE(expt, var)    DEBUGXNE(qDebug, PTRACE, expt, var)
#define TRACERTV()              DEBUGRTV(qDebug, PTRACE)
#define TRACERTN(expr)          TRACE << "return" << #expr << expr; return expr;
#define TRACEFNR(expr)          DEBUGFNR(qDebug, PTRACE, expr)
#define TODO(msg)               DEBUGDO(qDebug, PTODO, msg)
#define LATERDO(msg)            DEBUGDO(qDebug, PTODO, msg)
#define TOUSE(msg)              DEBUGUSE(qDebug, PTODO, msg)
#define TORTN(msg)              DEBUGRTN(qDebug, PTODO, msg)
#define UNUSED(var)             Q_UNUSED(var)
#define EMIT(expr)              DEBUG(qDebug, PTRACE) << "EMIT" << #expr; Q_EMIT(expr);

#define WARN                    DEBUG(qWarning, PWARN) // << stuff
#define WARNQFI                 DEBUGQFIN(qWarning, PWARN) // << stuff
#define WARNFN()                DEBUGFN(qWarning, PWARN);
#define WARNPSZ(psz)            DEBUGPSZ(qWarning, PWARN, psz);
#define WARNQST(qst)            DEBUGQST(qWarning, PWARN, qPrintable(qst));
#define WEXPECT(bexpr)          DEBUGEXP(qWarning, PWARN, bexpr)
#define WEXPECTI(bexpr, info)   DEBUGEXPI(qWarning, PWARN, bexpr, info)
#define WCONNECT(src, sig, dst, slt)    DEBUGCON(qWarning,  PWARN, src, sig, dst, slt)
#define WEXPECTNOT(bexpr)       DEBUGXN(qWarning, PWARN, bexpr)
#define WEXPECTEQ(expt, var)    DEBUGXEQ(qWarning, PWARN, expt, var)
#define WEXPECTNE(expt, var)    DEBUGXNE(qWarning, PWARN, expt, var)
#define WANTDO(msg)             DEBUGDO(qWarning, PWTODO, msg)
#define WANTUSE(msg)            DEBUGUSE(qWarning, PWTODO, msg)
#define WANTRTN(msg)            DEBUGRTN(qWarning, PWTODO, msg)
#define WPTR(ptr, expr)         DEBUGPTR(qWarning, PWARN, ptr, expr)

#define ERROR                   DEBUG(qCritical, PERROR) // << stuff
#define ERRORQFI                DEBUGQFIN(qCritical, PERROR) // << stuff
#define ERRORFN()               DEBUGFN(qCritical, PERROR);
#define ERRORPSZ(psz)           DEBUGPSZ(qCritical, PERROR, psz);
#define ERRORQST(qst)           DEBUGQST(qCritical, PERROR, qPrintable(qst));
#define EXPECT(bexpr)           DEBUGEXP(qCritical, PERROR, bexpr)
#define EXPECTNOT(bexpr)        DEBUGXN(qCritical, PERROR, bexpr)
#define EXPECTEQ(expt, var)     DEBUGXEQ(qCritical, PERROR, expt, var)
#define EXPECTEZ(expt, var)     DEBUGXEZ(qCritical, PASSERT, expt, var)
#define EXPECTNE(expt, var)     DEBUGXNE(qCritical, PERROR, expt, var)
#define EXPECTGT(expt, var)     DEBUGXGT(qCritical, PERROR, expt, var)
#define CONNECT(src, sig, dst, slt)    DEBUGCON(qCritical,  PERROR, src, sig, dst, slt)
#define DISCONNECT(src, sig, dst, slt) DEBUGDCON(qCritical, PERROR, src, sig, dst, slt)
#define NEEDDO(msg)             DEBUGDO(qCritical, PETODO, msg)
#define NEEDUSE(msg)            DEBUGUSE(qCritical, PETODO, msg)
#define NEEDRTN(msg)            DEBUGRTN(qCritical, PETODO, msg)
#define NEEDFNR(expr)           DEBUGFNR(qCritical, PETODO, expr)
#define NEEDRTV()               DEBUGRTV(qCritical, PETODO)
#define PTR(ptr, expr)          DEBUGPTR(qCritical, PERROR, ptr, expr)

#define ASSERT(strm)            DEBUG(qCritical, PASSERT) << strm; DEBUGQUIT
#define ASSERTQFI(strm)         DEBUGQFIN(qCritical, PASSERT) << strm; DEBUGQUIT
#define ASSERTFN()              DEBUGFN(qCritical, PASSERT); DEBUGQUIT
#define ASSERTPSZ(psz)          DEBUGPSZ(qCritical, PASSERT, psz); DEBUGQUIT
#define ASSERTQST(qst)          DEBUGQST(qCritical, PASSERT, qPrintable(qst)); DEBUGQUIT
#define MUSTDO(msg)             DEBUGDO(qCritical, PBTODO, msg); DEBUGQUIT
#define MUSTUSE(var)            DEBUGUSE(qCritical, PBTODO, var); DEBUGQUIT
#define AEXPECT(bexpr)          DEBUGEXP(qCritical, PASSERT, bexpr); if ( ! (bexpr)) DEBUGQUIT
#define AEXPECTNOT(bexpr)       DEBUGXN(qCritical, PASSERT, bexpr); if (bexpr) DEBUGQUIT
#define AEXPECTEQ(expt, var)    DEBUGXEQ(qCritical, PASSERT, expt, var); if (expt != var) DEBUGQUIT
#define AEXPECTEZ(expt, var)    DEBUGXEZ(qCritical, PASSERT, expt, var); if ( ! qFuzzyCompare(expt, var)) DEBUGQUIT
#define AEXPECTNE(expt, var)    DEBUGXNE(qCritical, PASSERT, expt, var); if (expt == var) DEBUGQUIT
#define AEXPECTPTR(ptr)         DEBUGXPTR(qCritical, PASSERT, ptr); if (nullptr == ptr) DEBUGQUIT
#define AEXPECTPQO(typ, ptr)    DEBUGXPTR(qCritical, PASSERT, q_object_cast<typ *>(ptr))); if (nullptr == q_object_cast<typ *>(ptr)) DEBUGQUIT
#ifdef QT_DEBUG
#define RMUSTDO(msg)            DEBUGDO(qCritical, PETODO, msg); DEBUGQUIT
#define RMUSTUSE(var)           DEBUGUSE(qCritical, PBTODO, var); DEBUGQUIT
#define REXPECT(bexpr)          RDEBUGEXP(qCritical, PASSERT, bexpr)
#define REXPECTNOT(bexpr)       DEBUGXN(qCritical, PASSERT, bexpr); if (bexpr) DEBUGQUIT
#define REXPECTEQ(expt, var)    DEBUGXEQ(qCritical, PASSERT, expt, var); if (expt != var) DEBUGQUIT
#define REXPECTNE(expt, var)    DEBUGXNE(qCritical, PASSERT, expt, var); if (expt == var) DEBUGQUIT
#define REXPECTPTR(ptr)         DEBUGXPTR(qCritical, PASSERT, ptr); if (nullptr == ptr) DEBUGQUIT
#else
#define RMUSTDO(msg)            DEBUGDO(qCritical, PBTODO, msg)
#define RMUSTUSE(var)           DEBUGUSE(qCritical, PBTODO, var);
#define REXPECT(bexpr)          DEBUGEXP(qCritical, PASSERT, bexpr)
#define REXPECTNOT(bexpr)       DEBUGXN(qCritical, PASSERT, bexpr)
#define REXPECTEQ(expt, var)    DEBUGXEQ(qCritical, PASSERT, expt, var)
#define REXPECTNE(expt, var)    DEBUGXNE(qCritical, PASSERT, expt, var)
#define REXPECTPTR(ptr)         DEBUGXPTR(qCritical, PASSERT, ptr)
#endif
#define MUSTRTN(var)            DEBUGRTN(qCritical, PBTODO, var); DEBUGQUIT
#define MUSTEMIT(var)           DEBUGEMIT(qCritical, PBTODO, var); DEBUGQUIT
#define BPTR(ptr, expr)         DEBUGPTR(qCritical, PERROR, ptr, expr); DEBUGQUIT

#ifdef QT_DEBUG
# define NOTIFY(strm)           DEBUG(qCritical, PASSERT) << strm; DEBUGQUIT
#else
# define NOTIFY(strm)           DEBUG(qWarning, PWARN) << strm;
#endif

#define TSTALLOC(ptr)           DEBUGXPTR(qCritical, PASSERT, ptr);
#define TRYALLOC(typ, var, nexpr) typ * var = new nexpr; TSTALLOC(var)
