#-------------------------------------------------
#
# Project created by QtCreator 2017-03-04T13:37:54
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManagement
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addbookentry.cpp \
    editentryform.cpp

HEADERS  += mainwindow.h \
    addbookentry.h \
    editentryform.h \
    databaseconnection.h

FORMS    += mainwindow.ui \
    addbookentry.ui \
    editentryform.ui

RESOURCES += \
    libmanagementresources.qrc
