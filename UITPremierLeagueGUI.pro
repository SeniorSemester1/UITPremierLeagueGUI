#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T22:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UITPremierLeagueGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        BestFitPlayerManager.cpp \
        ClubChangeWrapper.cpp \
        ClubManager.cpp \
        ClubRecord.cpp \
        DataReader.cpp \
        DataWriter.cpp \
        FirstFitPlayerManager.cpp \
        League.cpp \
        LeagueManager.cpp \
        PlayerChangeWrapper.cpp \
        PlayerManager.cpp \
        PlayerRecord.cpp \
        Season.cpp \
        SeasonChangeWrapper.cpp \
    Logger.cpp

HEADERS += \
        BestFitPlayerManager.h \
        ClubChangeWrapper.h \
        ClubManager.h \
        ClubRecord.h \
        DataReader.h \
        DataWriter.h \
        FirstFitPlayerManager.h \
        League.h \
        LeagueManager.h \
        mainwindow.h \
        PlayerChangeWrapper.h \
        PlayerManager.h \
        PlayerRecord.h \
        Season.h \
        SeasonChangeWrapper.h \
        SeasonNode.cpp.autosave \
    Logger.h

FORMS += \
        mainwindow.ui \

SUBDIRS += \
    UITPremierLeagueGUI.pro

DISTFILES += \
    UITPremierLeagueGUI.pro.user
