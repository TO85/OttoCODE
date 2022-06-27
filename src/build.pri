# {OttoCODE}./src/build.pri

message(----------------In build.pri)
#windows:message(=windows:)
#win32:message(=win32:)
#win64:message(=win64:)
#linux:message(=linux:)
#msvc:message(=msvc:)
#gcc:message(=gcc:)
#message(QMAKESPEC = $${QMAKESPEC})
#message(QT_ARCH = $$QT_ARCH)
#message(QMAKE_TARGET.arch = $${QMAKE_TARGET.arch})

contains(QT_ARCH, i386) {
#    message("32-bit")
} else {
#    message("64-bit")
}

CTOOL = "???"
windows:CTOOL = "windows"
linux:CTOOL = "linux"

windows { #message(windows)
    msvc { #message(windows & msvc)
            contains($${QT_ARCH}, i386) { #message(windows & msvc & i386)
                CTOOL = "win32V"
            } # i386
            else { #message(windows & msvc & x86_64)
                CTOOL = "win64V"
            } # else
    } # msvc
    gcc { #message(windows & gcc)
            contains($${QT_ARCH}, "i386") { #message(windows & gcc & i386)
                CTOOL = "win32G"
            } ## i386
            else { #message(windows & gcc & x86_64)
                CTOOL = "win64G"
            } ## else
    } #gcc
} # windows

linux { #message(linux)
    gcc { #message(linux & gcc)
            contains($${QT_ARCH}, "i386") { #message(linux & gcc & i386)
                CTOOL = "nix32G"
            } ## i386
            else
            { #message(linux & gcc & x86_64)
                CTOOL = "nix64G"
            } ## else
    } #gcc
} #linux

#message(CTOOL = $$CTOOL)

DISTFILES += \
    $$PWD/hosts.pri \
    $$PWD/hosts/eagle.pri

