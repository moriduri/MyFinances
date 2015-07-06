#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T15:42:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = MyFinances
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Transaction.cpp \
    TransactionDialog.cpp \
    Category.cpp \
    TransactionsView.cpp

HEADERS  += mainwindow.h \
    Transaction.h \
    TransactionDialog.h \
    Category.h \
    TransactionsView.h

FORMS    += mainwindow.ui \
    TransactionDialog.ui \
    TransactionsView.ui
