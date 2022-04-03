QT       +=  gui
QT += network

CONFIG += c++11
CONFIG -= app_bundle
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += ../common

SOURCES += \
    application.cpp \
    main.cpp \
    polinom.cpp \
    rational.cpp \
    ..\common\communicator.cpp \
    ..\common\common.cpp

HEADERS += \
    application.h \
    number.h \
    polinom.h \
    rational.h \
    ..\common\communicator.h \
    ..\common\common.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
