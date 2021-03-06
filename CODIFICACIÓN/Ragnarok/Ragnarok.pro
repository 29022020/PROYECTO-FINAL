QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    axe.cpp \
    floor.cpp \
    god.cpp \
    levelwindow.cpp \
    login.cpp \
    main.cpp \
    multiplayer.cpp \
    personajesotrak.cpp \
    plataformrandi.cpp \
    powerupitems.cpp \
    proyectilbase.cpp \
    register.cpp \
    runes.cpp \
    startmenu.cpp \
    userinterfaz.cpp \
    vikingsarena.cpp

HEADERS += \
    axe.h \
    floor.h \
    god.h \
    levelwindow.h \
    login.h \
    multiplayer.h \
    personajesotrak.h \
    plataformrandi.h \
    powerupitems.h \
    proyectilbase.h \
    register.h \
    runes.h \
    startmenu.h \
    userinterfaz.h \
    vikingsarena.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    D:/Music/AREA21 - HELP (Official Video)(M4A_128K).m4a \
    D:/Music/Invincible(MP3_160K)_1.mp3 \
    D:/Music/Subtact _ She Is Jules - Bite [Monstercat Release](MP3_160K)_1.mp3 \
    sprites/AXE/Axe.png \
    sprites/ITEMS/DPurple.png \
    sprites/ITEMS/Green.png \
    sprites/ITEMS/Purplee.png \
    sprites/ITEMS/White.png \
    sprites/ITEMS/Yellow.png \
    sprites/RUNAS/Runa1.png \
    sprites/RUNAS/Runa2.png \
    sprites/RUNAS/Runa3.png \
    sprites/VIKINGARENA/Viking-removebg-preview.png \
    sprites/personaje/ataquederecha1.png \
    sprites/personaje/ataquederecha2.png \
    sprites/personaje/ataquederecha3.png \
    sprites/personaje/ataquederecha4.png \
    sprites/personaje/ataqueizquierda1.png \
    sprites/personaje/ataqueizquierda2.png \
    sprites/personaje/ataqueizquierda3.png \
    sprites/personaje/ataqueizquierda4.png \
    sprites/personaje/derecha1.png \
    sprites/personaje/derecha3.png \
    sprites/personaje/izquierda1.png \
    sprites/personaje/izquierda2.png \
    sprites/personaje/izquierda3.png

RESOURCES += \
    Sprites.qrc

FORMS += \
    levelwindow.ui \
    login.ui \
    multiplayer.ui \
    register.ui \
    startmenu.ui \
    userinterfaz.ui
