# file: {OttoCODE}./src/BioldXlc.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocExe \
        ocImage \
        Excelsior \

ocBase.subdir           = libs/ocBase
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocExe.subdir            = libs/ocExe
ocImage.subdir          = libs/ocImage
Excelsior.subdir        = desktop/Excelsior

ocBase.depends          =
ocqCore.depends         =                                        ocBase
ocqGui.depends          =                               ocqCore  ocBase
ocqWidgets.depends      =                               ocqCore  ocBase
ocExe.depends           =                               ocqCore  ocBase
ocImage.depends         =                        ocqGui ocqCore  ocBase
Excelsior.depends       =   ocExe   ocqWidgets   ocqGui ocqCore  ocBase

