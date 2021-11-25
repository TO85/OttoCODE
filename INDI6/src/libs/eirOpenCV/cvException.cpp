#include "cvException.h"

#include <opencv2/core/core_c.h>

#include <eirXfr/Debug.h>

cvException::cvException(const cv::Exception other)
    : cv::Exception(other)
{
    TRACEQFI << toDebugStrings();
}

int cvException::errorCode() const
{
    return code;
}

QString cvException::codeString() const
{
    QString result(cvErrorStr(errorCode()));
    return result;
}

int cvException::fileLine() const
{
    return line;
}

QString cvException::errorString() const
{
    cvString cvErr(err);
    return cvErr.toString();
}

QString cvException::fileName() const
{
    cvString cvFile(file);
    return cvFile.toString();
}

QString cvException::function() const
{
    cvString cvFunc(func);
    return cvFunc.toString();
}

QString cvException::message() const
{
    cvString cvMsg(msg);
    return cvMsg.toString();
}

void cvException::clear()
{
    code = -1, err.clear(), func.clear(), file.clear(), line = -1, msg.clear();
}

void cvException::process()
{
    formatMessage();
}

QStringList cvException::toDebugStrings() const
{
    cvException copy(it());
    copy.process();
    QStringList result;
    result << QString("{cvException>%1[%2]")
              .arg(fileName()).arg(fileLine());
    result << QString("(#%1) %2")
              .arg(errorCode()).arg(errorString());
    result << function();
    result << copy.message();
    result << "<cvException}";
    return result;
}

QDebug operator << (QDebug dbg, const cvException &x)
{
    for (QString s : x.toDebugStrings())
        dbg << s;
    return dbg;
}
