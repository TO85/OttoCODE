# file: {INDI6 repo}./src/apps/cons/BuildIfS6.pri

TEMPLATE = subdirs

SUBDIRS += \
        ../../../libs/eirXfr \
        ../../../libs/eirBase \
#        ./libs/eirType \
#        ./libs/eirWgt \
        ../../../libs/eirExe \
#        ./libs/eirQtCV \
		./libs/eirOpenCV
#        ./libs/eirObjDet \
#        ./libs/eirImage \
#        ./libs/eirStore \
#        ./libs/eirTask \
#        ./tests/testXfr \
#        ./tests/testType \
        ./IfSearch6 \


eirBase.depends     = eirXfr
# eirType.depends     = eirBase eirXfr
# eirWgt.depends      = eirType eirBase eirXfr
###eirExe.depends      = eirType eirBase ierXfr
eirExe.depends      = eirType eirXfr
# eirQtCV.depends     = eirExe eirType eirBase eirXfr
# eirObjDet.depends   = eirQtCV eirExe eirType eirBase eirXfr
# eirImage.depends    = eirObjDet eirQtCV eirExe eirType eirXfr
###IfSearch6.depends  = eirImage eirExe eirWgt eirType eirBase eirXfr
IfSearch6.depends  =  eirExe   eirBase eirXfr

