# file: {OttoCODE}./src/BioldXlc.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocColor \
        ocPixel \
        ocExe \
        ocImage \
        Excelsior \

ocBase.subdir           = libs/ocBase
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocColor.subdir          = libs/ocColor
ocPixel.subdir          = libs/ocPixel
ocExe.subdir            = libs/ocExe
ocImage.subdir          = libs/ocImage
Excelsior.subdir        = desktop/Excelsior

ocBase.depends          =
ocqCore.depends         =                                                       ocBase
ocqGui.depends          =                                               ocqCore ocBase
ocqWidgets.depends      =                                               ocqCore ocBase
ocColor.depends      =                                                  ocqCore ocBase
ocPixel.depends      =                      ocColor                     ocqCore ocBase
ocExe.depends           =                                               ocqCore ocBase
ocImage.depends         =           ocPixel ocColor             ocqGui  ocqCore ocBase
Excelsior.depends       =   ocExe                   ocqWidgets  ocqGui  ocqCore ocBase

