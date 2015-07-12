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
    Category.cpp \
    TransactionsView.cpp \
    CategoriesView.cpp \
    AddDialog.cpp \
    AddCategoryDialog.cpp \
    AddTransactionDialog.cpp

HEADERS  += mainwindow.h \
    Transaction.h \
    Category.h \
    TransactionsView.h \
    CategoriesView.h \
    AddDialog.h \
    AddCategoryDialog.h \
    AddTransactionDialog.h

FORMS    += mainwindow.ui \
    TransactionsView.ui \
    CategoriesView.ui \
    Dialog.ui
