#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T15:42:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFinances
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Transaction.cpp \
    TransactionDialog.cpp \
    Category.cpp

HEADERS  += mainwindow.h \
    Transaction.h \
    TransactionDialog.h \
    Category.h

FORMS    += mainwindow.ui \
    TransactionDialog.ui
