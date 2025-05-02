QT       += core gui sql network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Project paths
PROJECT_ROOT = $$PWD
BUILD_DIR = $$PROJECT_ROOT/build

# Output directories
DESTDIR = $$BUILD_DIR
OBJECTS_DIR = $$BUILD_DIR/obj
MOC_DIR = $$BUILD_DIR/moc
UI_DIR = $$BUILD_DIR/ui
RCC_DIR = $$BUILD_DIR/rcc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    login.cpp \
    dashboard.cpp \
    employeemanagement.cpp \
    documentmanagement.cpp \
    documents.cpp \
    taskmanagement.cpp \
    calendar.cpp \
    reports.cpp \
    database.cpp \
    cartablewidget.cpp \
    delegationwidget.cpp \
    emailwidget.cpp \
    archivewidget.cpp \
    searchwidget.cpp

HEADERS += \
    mainwindow.h \
    login.h \
    dashboard.h \
    employeemanagement.h \
    documentmanagement.h \
    documents.h \
    taskmanagement.h \
    calendar.h \
    reports.h \
    database.h \
    cartablewidget.h \
    delegationwidget.h \
    emailwidget.h \
    archivewidget.h \
    searchwidget.h

FORMS += \
    mainwindow.ui \
    login.ui \
    dashboard.ui \
    employeemanagement.ui \
    documentmanagement.ui \
    documents.ui \
    taskmanagement.ui \
    calendar.ui \
    reports.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Clean build directory before building
QMAKE_CLEAN += -r $$BUILD_DIR

# Additional configurations for Qt Creator
CONFIG += debug_and_release
CONFIG += ordered

# Ensure UI files are properly processed
CONFIG += uic
UIC_DIR = $$BUILD_DIR/ui

# Ensure MOC files are properly processed
CONFIG += moc
MOC_DIR = $$BUILD_DIR/moc

# Ensure RCC files are properly processed
CONFIG += rcc
RCC_DIR = $$BUILD_DIR/rcc
