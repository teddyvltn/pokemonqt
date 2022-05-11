QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    damage.cpp \
    game.cpp \
    main.cpp \
    menu/battle.cpp \
    menu/mainmenu.cpp \
    move.cpp \
    player.cpp \
    pokemon.cpp \
    utils.cpp \
    widget.cpp

HEADERS += \
    damage.h \
    game.h \
    globals.h \
    menu/battle.h \
    menu/mainmenu.h \
    move.h \
    player.h \
    pokemon.h \
    utils.h \
    widget.h

FORMS += \
    battle.ui \
    mainmenu.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qressource.qrc
