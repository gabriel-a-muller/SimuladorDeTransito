#-------------------------------------------------
#
# Project created by QtCreator 2017-11-21T12:15:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projeto_Final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cruzamento.cpp \
    gerador.cpp \
    rua.cpp \
    trafego.cpp

HEADERS  += mainwindow.h \
    ExcecaoInvalida.h \
    Cruzamento.h \
    Rua.h \
    Trafego.h \
    Veiculo.h \
    gerador.h \
    imagemcarro.h

FORMS    += mainwindow.ui
