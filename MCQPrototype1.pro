#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T00:56:23
#
#-------------------------------------------------

QT       += core gui
QT       += network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MCQPrototype1
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    validators/loginvalidator.cpp \
    model/team.cpp \
    model/otherinfo.cpp \
    model/quizdetail.cpp \
    instructiondialog.cpp \
    model/question.cpp \
    questionwindow.cpp \
    serveripaddressdialog.cpp

HEADERS  += loginwindow.h \
    validators/loginvalidator.h \
    model/team.h \
    model/otherinfo.h \
    model/quizdetail.h \
    instructiondialog.h \
    model/question.h \
    questionwindow.h \
    serveripaddressdialog.h

FORMS    += loginwindow.ui \
    instructiondialog.ui \
    questionwindow.ui \
    serveripaddressdialog.ui

RESOURCES += \
    imageresource.qrc

RC_FILE = myappicon.rc
