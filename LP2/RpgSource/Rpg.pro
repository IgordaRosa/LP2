QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    bossf3.cpp \
    bossskill.cpp \
    game.cpp \
    gameover.cpp \
    hp.cpp \
    inimigo1.cpp \
    inimigo1d.cpp \
    inimigo2.cpp \
    inimigo2d.cpp \
    listadesave.cpp \
    main.cpp \
    mainwindow.cpp \
    mana.cpp \
    opt.cpp \
    perso.cpp \
    player.cpp \
    resetgame.cpp \
    score.cpp \
    skill1.cpp \
    skill1d.cpp \
    skill1r.cpp \
    skill2.cpp \
    skill2d.cpp \
    skill2r.cpp \
    teladeperso.cpp \
    timerfase.cpp

HEADERS += \
    about.h \
    bossf3.h \
    bossskill.h \
    char.hpp \
    classe.hpp \
    game.h \
    gameover.h \
    hp.h \
    inimigo1.h \
    inimigo1d.h \
    inimigo2.h \
    inimigo2d.h \
    listadesave.h \
    mainwindow.h \
    mana.h \
    opt.h \
    perso.h \
    personagem.hpp \
    player.h \
    resetgame.h \
    score.h \
    skill1.h \
    skill1d.h \
    skill1r.h \
    skill2.h \
    skill2d.h \
    skill2r.h \
    teladeperso.h \
    timerfase.h

FORMS += \
    about.ui \
    listadesave.ui \
    mainwindow.ui \
    opt.ui \
    perso.ui \
    resetgame.ui \
    teladeperso.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
