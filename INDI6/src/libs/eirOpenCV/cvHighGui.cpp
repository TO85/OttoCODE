#include "cvHighGui.h"

#include <eirType/Success.h>
#include <eirXfr/Debug.h>

#include "cvMat.h"
#include "cvMatQImage.h"
#include "cvString.h"

bool cvHighGui::imshow(const QQImage &aImage, const cvMatType aMatType,
                       const int waitMsec, const QQString &aName) const
{
    const QQImage cvImage = aImage.rgbSwapped();
    const cvMat mat(aImage, aMatType);
    const cvString name(aName.string(aImage.baseName("imshow")));
    cv::imshow(name, mat());
    (void)cv::waitKey(waitMsec);
    return true;
}
