#-------------------------------------------------
#
# Project created by QtCreator 2012-11-18T19:51:47
#
#-------------------------------------------------

QT       += core

QT       += gui

TARGET = Ruby2JavaByteCode
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    test.cpp \
    parser_tab.cpp \
    lex.yy.cpp \
    semantic.cpp \
    semanticTables.cpp

HEADERS += \
    test.h \
    structures.h \
    parser_tab.h \
    semantic.h \
    semanticTables.h \
    CodeCommands.h

OTHER_FILES += \
    parser.y
