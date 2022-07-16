# {OttoCODE}./src/hosts/titan.pri

message(----------------In ./src/hosts/titan.pri)
#message(QMAKESPEC = $${QMAKESPEC})

#message(OC_QMAKE_HOST = $$OC_QMAKE_HOST)
contains(OC_QMAKE_HOST, titan) {
    message("Building on titan!")
    OC_BASEDESTDIR = $$OTTOCODE_BASEBINDIR
}

#message(OC_BASEDESTDIR = $${OC_BASEBINDIR})
