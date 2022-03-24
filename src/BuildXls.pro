# file: {OttoCODE}./src/BioldXlc.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocType \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocOpenCV \
        ocColor \
        ocPixel \
        ocExe \
        ocImage \
        Excelsior \

ocBase.subdir           = libs/ocBase
ocType.subdir           = libs/ocType
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocOpenCV.subdir         = libs/ocOpenCV
ocColor.subdir          = libs/ocColor
ocPixel.subdir          = libs/ocPixel
ocExe.subdir            = libs/ocExe
ocImage.subdir          = libs/ocImage
Excelsior.subdir        = desktop/Excelsior

ocBase.depends          = #none
ocType.depends          =
ocqCore.depends         =
ocqGui.depends          =                                                           ocqCore ocType  ocBase
ocqWidgets.depends      =                                                   ocqGui  ocqCore         ocBase
ocOpenCV.depends        =                                       ocqWidgets  ocqGui  ocqCore         ocBase
ocExe.depends           = #tbd
ocColor.depends         =                                                   ocqGui  ocqCore         ocBase
ocPixel.depends         =                   ocColor                         ocqGui          ocType  ocBase
ocImage.depends         =           ocPixel ocColor ocOpenCV                ocqGui  ocqCore ocType  ocBase
Excelsior.depends       =   ocExe   ocPixel ocColor ocOpenCV    ocqWidgets  ocqGui  ocqCore ocType  ocBase

