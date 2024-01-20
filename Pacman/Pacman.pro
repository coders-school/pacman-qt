QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audiomanager.cpp \
    configmanager.cpp \
    game.cpp \
    ghosts.cpp \
    main.cpp \
    mainwindow.cpp \
    maze.cpp \
    player.cpp \
    scoremanager.cpp \
    uimanager.cpp

HEADERS += \
    audiomanager.h \
    configmanager.h \
    game.h \
    ghosts.h \
    mainwindow.h \
    maze.h \
    player.h \
    scoremanager.h \
    uimanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
!isEmpty(target.path): INSTALLS += target

