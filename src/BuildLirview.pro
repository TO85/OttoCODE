# file: {OttoCODE}./src/BuildLirview.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocType \
#        ocLog \
#        ocIO \
        ocqCore \
#        ocqGui \
#        ocqWidgets \
#        ocColor \
#        ocPixel \
#        ocImage \
        ocExe \
        lirview \

ocBase.subdir           = libs/ocBase
ocType.subdir           = libs/ocType
#ocLog.subdir            = libs/ocLog
#ocIO.subdir             = libs/ocIO
ocqCore.subdir          = libs/ocqCore
#ocqGui.subdir           = libs/ocqGui
#ocqWidgets.subdir       = libs/ocqWidgets
#ocColor.subdir          = libs/ocColor
#ocPixel.subdir          = libs/ocPixel
#ocImage.subdir          = libs/ocImage
ocExe.subdir            = libs/ocExe
lirview.subdir          = desktop/lirview

ocBase.depends          =
ocType.depends          =                                                                       ocBase
#ocLog.depends           =                                                                      ocBase
#ocIO.depends            =                                                                       ocBase
ocqCore.depends         =                                                               ocType  ocBase
#ocqGui.depends          =                           ocExe                       ocqCore         ocType  ocBase
#ocqWidgets.depends      =                                               ocqGui  ocqCore         ocType  ocBase
#ocColor.depends         =                                               ocqGui                  ocType  ocBase
#ocPixel.depends         =                   ocColor                     ocqGui                  ocType  ocBase
#ocImage.depends         =           ocPixel ocColor                     ocqGui                  ocType  ocBase
ocExe.depends           =                                                               ocType  ocBase
#lirview.depends         =  ocImage  ocPixel ocColor ocExe   ocqWidgets  ocqGui  ocqCore         ocType  ocBase
lirview.depends         =                           ocExe                               ocType  ocBase


