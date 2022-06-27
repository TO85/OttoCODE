# {OttoCODE}./src/version.pri

message(----------------In version.pri)

OC_VER_MAJOR = 1
OC_VER_MINOR = 23
OC_VER_RELEASE = 1
OC_VER_BRANCH = 0
OC_VER_STRING = "v1.23A"
OC_VER_TRUNKNAME = "develop"
OC_VER_QT = $${QT_VERSION}
OC_VER_BRANCHNAME = "origin"
OC_VER_QT = $${QT_VERSION}

windows:VERSION = 1.23.1.0
!windows:VERSION = 1.23.0
VER_MAJ = $${OC_VER_MAJOR}
VER_MIN = $${OC_VER_MINOR}
VER_PAT = $${OC_VER_BRANCH}

