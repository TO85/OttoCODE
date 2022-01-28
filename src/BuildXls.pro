# file: {OttoCODE}./src/BioldXlc.pro

TEMPLATE = subdirs

SUBDIRS += \
        ocBase \
        ocqCore \
        ocqGui \
        ocqWidgets \
        ocExe \
        Excelsior \

ocBase.subdir           = libs/ocBase
ocqCore.subdir          = libs/ocqCore
ocqGui.subdir           = libs/ocqGui
ocqWidgets.subdir       = libs/ocqWidgets
ocExe.subdir            = libs/ocExe
Excelsior.subdir         = apps/desktop/Excelsior

toBase.depends          =
toqCore.depends         =                                        ocBase
toqGui.depends          =                               ocqCore  ocBase
toqWidgets.depends      =                               ocqCore  ocBase
toExe.depends           =                               ocqCore  ocBase
Excelsior.depends        =   ocExe   ocqWidgets   ocqGui ocqCore  ocBase

