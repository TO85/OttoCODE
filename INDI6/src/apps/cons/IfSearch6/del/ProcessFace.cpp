#include "ProcessFace.h"

#include <eirXfr/Debug.h>

ProcessFace::ProcessFace(const VariableMap &initMap, const VariableMap &configMap)
{
    TRACEFN;
    MUSTDO(something);
    MUSTUSE(initMap);
    MUSTUSE(configMap);

}

bool ProcessFace::load()
{
    TRACEFN;
    MUSTDO(something);

    MUSTDO(return); return false;
}



/*

mEyeCascadeFileInfo = QFileInfo(mCascadeDir, "haarcascade_eye.xml");
BEXPECT(mEyeCascadeFileInfo.isReadable());
DUMPVAL(mEyeCascadeFileInfo);
EXPECT(mEyeClassifier.load(mEyeCascadeFileInfo));
EXPECT(mEyeClassifier.isLoaded());

 */
