#pragma once
#include "IfObject.h"

#include <QtCore/QFileInfo>

#include <eirExe/Configuration.h>
#include <eirOpenCV/cvCascade.h>
#include <eirOpenCV/cvMat.h>
#include <eirOpenCV/cvString.h>
class ObjectDetector;

class IFOBJECT_EXPORT ObjectFinder
{
public:
    ObjectFinder(ObjectDetector *pDetector, const ObjectType otype);

    ObjectType type() const { return cmType; }
    ObjectDetector *detector() { return mpDetector; }
    cvCascade *cascade() { return &mCascade; }
    bool isLoaded() const { return mCascade.isLoaded(); }

    bool initialize();
    void clear() {;}
    bool load(const QFileInfo &xmlFileInfo);
    QStringList statusStrings() const { return mCascade.statusStrings(); }
    DetectRectMap detect(const cvMat &cvm, const Configuration config);
    DetectRectMap detect(const SCRect regionRect, const cvMat &cvm, const Configuration config);

private:
    ObjectDetector *mpDetector;
    const ObjectType cmType;
    cvCascade mCascade;
};

