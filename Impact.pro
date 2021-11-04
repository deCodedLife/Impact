QT += quick widgets svg sql

CONFIG += c++11
CONFIG += qtquickcompiler

SOURCES += \
        src/animations.cpp \
        src/characters.cpp \
        src/database.cpp \
        src/dragonstrike.cpp \
        src/impact.cpp \
        src/timer.cpp \
        src/winkeys.cpp \
        src\main.cpp

RESOURCES += res\qml.qrc \
    res/images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/animations.h \
    src/characters.h \
    src/database.h \
    src/dragonstrike.h \
    src/impact.h \
    src/timer.h \
    src/winkeys.h

DISTFILES +=
