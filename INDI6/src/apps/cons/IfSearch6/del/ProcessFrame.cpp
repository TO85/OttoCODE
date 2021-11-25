#include "ProcessFrame.h"

#include <eirXfr/Debug.h>

ProcessFrame::ProcessFrame(const VariableMap &initMap, const VariableMap &configMap)
    : mInitMap(initMap)
    , mConfigMap(configMap)
    , mFaceClassifier(PatternType::FaceFrontal)
    , mEyeClassifier(PatternType::EyeEither)
{
    TRACEFN;
    initMap.dump();
    configMap.dump();
}

void ProcessFrame::initialize(const VariableMap &initMap)
{
    TRACEFN;
    mInitMap.set(initMap);
    initMap.dump();
    mInitMap.dump();
    NEEDDO(initialize);
}

bool ProcessFrame::load(const QString &filePathName)
{
    TRACEQFI << filePathName; MUSTDO(it); MUSTUSE(filePathName);
    MUSTDO(return); return false;
}

bool ProcessFrame::load(const QDir &dir, const QString &fileName)
{
    TRACEQFI << fileName; MUSTDO(it); MUSTUSE(dir); MUSTUSE(fileName);
    MUSTDO(return); return false;
}

bool ProcessFrame::load()
{
    mCascadeDir = QDir("/lang/OpenCV4/opencv/build/etc/haarcascades");
    BEXPECT(mCascadeDir.isReadable());
    mFaceCascadeFileInfo = QFileInfo(mCascadeDir, "haarcascade_frontalface_alt2.xml");
    BEXPECT(mFaceCascadeFileInfo.isReadable());
    DUMPVAL(mFaceCascadeFileInfo);
    EXPECT(mFaceClassifier.load(mFaceCascadeFileInfo));
    EXPECT(mFaceClassifier.isLoaded());
    return mFaceClassifier.isLoaded();
}

void ProcessFrame::process(const QImage &frameImage, const VariableMap &imageConfigMap)
{
    TRACEQFI << frameImage;
    VariableMap processConfig = mConfigMap;
    processConfig.set(imageConfigMap);
    imageConfigMap.dump();
    processConfig.dump();

}
