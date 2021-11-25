# Mini Issues

## eirXml

[X] 210618aho
- [X] Add .dump() to DomFile
- [X] DomFileManager::dump()


[!] 210331aho
~ DUMP "12:20:50.629" 93 "{DomStatus:> Max=?$null nItems=5"
~ DUMP "12:20:50.629" 93 "-Info >FileInfo exists(true)<"

[ ] 210331aho
~ DUMP "12:20:50.629" 72 ""
~ DUMP "12:20:50.629" 72 "{QQDomElement: INDIFaceData>"
~ DUMP "12:20:50.629" 72 ""
~ DUMP "12:20:50.629" 72 "{attributeNameValueList:>"
~ DUMP "12:20:50.629" 72 ""

## ifGeometry

[ ] 210625aho
- Refactor EyeROI : private SCRect::Pair pair as members left and right

## IfData

[-] 210331aho
- [X] New Indi1MainData class
- [X] new QObject Indi1ResourceManager
- [X] Remove Indi1MainData data from INDI1ResourceData
- [X] Remove pseudo-slots from INDI1ResourceData
- [X] New Input & OutputINDI1BitMask classes
- [X] ?Eventually remove INDI1ResourceData class?

[ ] 210331aho
* WARN "12:20:50.629" void __cdecl BaseINDI1BitMask::set(const class QQDomElement &) 41
Expectation FAILED: maskSize.area() 16384 == bs.count() 0
-TRACE "12:20:50.629" 46 16512 QSize(16512, 0) 0 QSize(128, 128) 4749 11763 16512

[ ] 210618aho
- [ ] BaseDir not set

## eirType

[ ] 210331aho
Q:\Qt\5.15.2\msvc2019_64\include\QtCore/qmap.h(1189): warning C4661: 'const T QMultiMap<DetectRect::Score,T>::operator [](const Key &) const': no suitable definition provided for explicit template instantiation request
        with
        [
            T=DetectRect,
            Key=DetectRect::Score
        ]
Q:\Qt\5.15.2\msvc2019_64\include\QtCore/qmap.h(1188): note: see declaration of 'QMultiMap<DetectRect::Score,DetectRect>::operator []'

## eirXfr

[X] 210331aho
Debug ASSERT and other fixup

[ ] 210331aho
ElementAttributeMap

## If6Console

[ ] 210331aho
OpenCV(4.5.0) Error: Assertion failed (size.width>0 && size.height>0) in cv::imshow
