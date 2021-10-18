QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mymainwindow.cpp \
    personajesotrak.cpp

HEADERS += \
    mymainwindow.h \
    personajesotrak.h

FORMS += \
    mymainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
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
