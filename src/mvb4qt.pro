QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    qmvbport.cpp \
    qmvbcard.cpp \
    # qmvbmanager.cpp \
    # qavicmvbdriver.cpp \
    # qpixymvbdriver.cpp \
    qsimulatemvbdriver.cpp \
    qlittleendianprotocol.cpp \
    qbigendianprotocol.cpp \
    qabstractmvbprotocol.cpp \
    qoffsetbigendianprotocol.cpp \
    qoffsetlittleendianprotocol.cpp \
    qmvbregister.cpp \
    qmvbcardmanager.cpp

HEADERS += \
    mvb4qt.h \
    qmvbport.h \
    qabstractmvbdriver.h \
    qmvbcard.h \
    # qmvbmanager.h \
    # qavicmvbdriver.h \
    # qpixymvbdriver.h \
    qsimulatemvbdriver.h \
    qabstractmvbprotocol.h \
    qlittleendianprotocol.h \
    qbigendianprotocol.h \
    qoffsetbigendianprotocol.h \
    qoffsetlittleendianprotocol.h \
    qmvbregister.h \
    qmvbcardmanager.h \
    mvbglobal.h
