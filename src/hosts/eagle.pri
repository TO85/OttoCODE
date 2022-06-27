# {OttoCODE}./src/hosts/eagle.pri

message(----------------In ./src/hosts/eagle.pri)
#message(QMAKESPEC = $${QMAKESPEC})

# OC_QMAKE_HOST=eagle
#message(OC_HOST = $$(OC_HOST))
contains(OC_HOST, eagle) {
    message("Building on eagle!")
    OC_BASEDESTDIR = $$OTTOCODE_BASEBINDIR
}

#message(OC_BASEDESTDIR = $${OC_BASEDESTDIR})
